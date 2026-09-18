# Trial I — *The Foundations Brief*

*Warden of the Foundations · Midterm 1 · 15 %*

Four short answers, one from each floor above. **50–100 words per answer.** No code on this trial (except the lambdas in Q3); just clear thinking.

AI is welcome to *check* your answers; it is not welcome to *write your sentences*. These answers are short enough that an LLM voice is recognisable.

---

## 1. Floor 0 — ADT

> Your battle's "Use item" menu shows the *currently usable* items in your hero's inventory on this turn. Name the right ADT for that menu. Defend the choice against its closest neighbour (e.g., why `bag` instead of `set`, or `list` instead of `bag`).

(your answer — 50–100 words)
I would use a bag over the other ADTs because it allows for the items to be accessed for anywhere inside the bag as 
order doesn't really matter and compared to a set it allows for duplicate items so if I had multiple let's say 
healing items it would allow me to access both of them comapred to a set where there would only be one

---

## 2. Floor 1 — search & Big-O

> Your inventory is kept sorted by healing power (in this codebase an item's `value` measures its potency, so `value` plays the healing-power role). The player types `use Healing potion`. Linear or binary search to find it by name? Justify, and give the Big-O for each.

(your answer — 50–100 words)
Binary search because the inventory is in a specific order so worse case it would take O(log(n)) compared to linear's O(n) 
which could end up checking every item in the inventory.  If it wasn't in order than theoretically binary could screw up
it's search but that one reason is why it's better than linear.

---

## 3. Floor 2 — sort & comparators

> Your "Use item" menu must be displayable sorted *either* by healing power (meaning `value`) *or* by weight. Show a one-line comparator (lambda) for each. One sentence on what language feature makes one `std::sort` call serve both orders.

*Note: `Item` has no healing field — an item's `value` measures its potency, so `value` plays the healing-power role here and in your battle.*

```cpp
// by healing power — i.e. by value
auto byValue  = [](const Item& a, const Item& b){
					return a.value < b.value;
					};

// by weight
auto byWeight = [](const Item& a, const Item& b){
					return a.weight < b.weight;
					};;
```

(one-sentence answer — what language feature?)
Lambda because it allows you to change the comparator for std::sort which then allows for the sorting of either value
---

## 4. Floor 3 — templates & exceptions

> Why does `Bag<T>` live in `Bag.h` instead of `Bag.cpp`? And: when the player types `9` for a 4-option menu, where in your code should the validation **throw**, and where should it **catch**?

(your answer — 50–100 words)
Bag<T> is in Bag.h over bag.cpp because when the compiler runs it can generate the necessary code for 
the template based on implementations of each data type when used.  
Your code validation should throw whenever 9 or any number value outside the range is read and the catch 
should be right after the code that causes it to throw so it can be reran or end the program.