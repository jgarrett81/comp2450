// COMP 2450 — Floor 2 starter
// hero/Sort.cpp — YOU implement this file.
//
// Three functions to write. Read Sort.h for their contracts.
//
// The big idea this week: sorting is not one algorithm, it is a family
// of tradeoffs. Merge sort is predictable but copies. Quicksort is fast
// on average but betrays you on bad inputs. std::sort is what you
// actually ship. You will write the first two, race all three in
// `benchmark sort`, and argue — in a commit message — which one the
// game should call.
//
// Tips for the Pivot Wraith:
//   * If you pick the FIRST element as your quicksort pivot, a sorted
//     input becomes O(n^2). The `benchmark sort --bad-pivot --sorted`
//     harness exists to show you exactly that.
//   * The middle element is the cheapest defense. Good enough for this
//     week. Real production code (std::sort) does median-of-three and
//     switches algorithms on bad recursion depth.
//
// Submit when:  `sort inventory by weight` produces ascending weight,
//               `sort inventory by name desc` produces reverse alphabetical,
//               and `benchmark sort` gives three timing columns on every row.

#include "Sort.h"
#include <algorithm>  // you will want std::sort in sortInventory
#include <sstream>
using namespace std;



namespace dungeon {

    namespace {
        void merge(vector<Item> v,
            size_t lo,
            size_t mid,
            size_t hi,
            const Comparator cmp) {
            vector<Item> scratch;
            scratch.reserve(hi - lo);
            // allocating capacity for high - low items

            //two cursors for each side
            size_t i = lo; // walk left
            size_t j = mid; // walk right

            // merge loop
            while (i < mid && j < i) {
                if (!cmp(v[j], v[i])) {
                    scratch.push_back(v[i++]);
                }
                else {
                    scratch.push_back(v[j++]);
                }
            }
            // one half drained but other still has items
            while (i < mid) scratch.push_back(v[i++]);
            while (j < i) scratch.push_back(v[j++]);

            // copy merged result into v
            //at positions [low, high)
            for (size_t k = 0; k < scratch.size(); ++k) {
                v[lo + k] = move(scratch[k]);
            }
        }

        void mergeSortImpl(vector<Item>& v, size_t lo, size_t hi, const Comparator& cmp) {
            //base case
            if (hi - lo < 2) return;

            size_t mid = lo + (hi - lo) / 2;
            mergeSortImpl(v, lo, mid, cmp); // sort the left half [lo, mid)
            mergeSortImpl(v, mid, hi, cmp); // sort the right half [mid, hi)
            merge(v, lo, mid, hi, cmp);


        }

        size_t partition(vector<Item>& v, size_t lo, size_t hi, const Comparator& cmp) {
            // high is last index (inclusive)
            // 1) pick the pivot
            size_t mid = lo + (hi - lo) / 2;
            swap(v[mid], v[hi]);
            const Item pivot = v[hi];
            // compute mid index
            // swap exchanges two items w/o copying whole struct
            // In Lumoto, it assumes the pivot lives at high
            // by moving pivot there, we can follow classic Lomuto

            // Lomuto scan
            // [low, store) --> strictly less than pivot
            // [store, high) --> => pivot
            size_t store = lo;
            for (size_t i = lo; i < hi; ++i) {
                if (cmp(v[i], pivot)) {
                    swap(v[store], v[i]);
                    store++;
                }
            }
            swap(v[store], v[hi]);
            return store;
        }

        void quicksortImpl(vector<Item>& v, size_t lo, size_t hi, const Comparator& cmp) {
            // base case
            if (lo >= hi) return;
            size_t p = partition(v, lo, hi, cmp);
            if (p > lo) quicksortImpl(v, lo, p - 1, cmp);
            quicksortImpl(v, p + 1, hi, cmp);
        }

        Comparator makeComparator(const string& key, bool descending) {
            Comparator cmp;
            if (key == "name") {
                cmp = [](const Item& a, const Item& b) {
                    return a.name < b.name;
                    };
            }
            else if (key == "weight") {
                cmp = [](const Item& a, const Item& b) {
                    return a.weight < b.weight;
                    };
            }
            else if (key == "value") {
                cmp = [](const Item& a, const Item& b) {
                    return a.value < b.value;
                    };
            }
            else return nullptr;

            if (descending) {
                Comparator asc = cmp;
                cmp = [asc](const Item& a, const Item& b) {
                    return asc(b, a);
                    };
            }

            return cmp;
        }
    }

// ---- 1. Merge sort ------------------------------------------------------

    void mergeSort(std::vector<Item>& inventory, const Comparator& cmp) {
        mergeSortImpl(inventory, 0, inventory.size(), cmp);
    }

// ---- 2. Quicksort -------------------------------------------------------

void quicksort(std::vector<Item>& inventory, const Comparator& cmp) {
    // TODO Floor 2 (Wed): implement quicksort.
    if (inventory.size() < 2) return;
    quicksortImpl(inventory, 0, inventory.size() - 1, cmp);
}

// ---- 3. sortInventory (the seam) ----------------------------------------

bool sortInventory(Hero& hero, const std::string& criterion) {
    istringstream in(criterion);
    string key;
    string direction;
    in >> key >> direction;

    bool descending = (direction == "desc");
    Comparator cmp = makeComparator(key, descending);
    if (!cmp) return false;
    sort(hero.inventory.begin(), hero.inventory.end(), cmp);
    return true;
}

}  // namespace dungeon


//comparator -- a function (in C++, lambda)
// does a come strictly before b?
// cmp(a,b) == true if a strictly < b
// cmp(a, b) == false if a > b
// strict weak ordering