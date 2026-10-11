1)> selftest stack
  empty Stack<int>: size==0 && empty(): OK
  push(7): size==1 && top()==7: OK
  push 1,2,3: size==3 && top()==3 (LIFO): OK
  after pop(): size==2 && top()==2: OK
  drain to empty: size==0 && empty(): OK
  all phases OK
> lint ({a} (b) [c])
  balanced
> lint ({)}
  not balanced
> lint hello (world
  not balanced
> inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
> take lantern
  Taken: lantern  (wt 0.1, val 1)
> sort inventory by weight
   1.  Iron key          (wt 0.1, val 0)
   2.  Loaf of bread     (wt 0.1, val 1)
   3.  lantern           (wt 0.1, val 1)
   4.  Healing potion    (wt 0.5, val 12)
   5.  Cloak of shadows  (wt 1.5, val 80)
   6.  Rusty sword       (wt 4.0, val 5)
> undo
Undid: sort inventory by weight
> undo
Undid: take lantern
> inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
> undo
Nothing to undo.
> quit
The cantor falls silent. The last echo decays. The hall is quiet.

2) An ADT describes a collection and what it does and what operations are able ot be performed while
a data structure is how the data is actually stored and organized.  Stack is an ADT because it follows the last in first out rule. 
Chain is a data structure because it stores items in linked nodes.
	Using Stack with Chain shows the difference because Stack controls how items are added/removed and Chain controls how they are 
stored.  Stack can also use a different data structure without changing how the stack works.

3) selftest stack
  empty Stack<int>: size==0 && empty(): OK
  push(7): size==1 && top()==7: OK
  push 1,2,3: size==3 && top()==3 (LIFO): OK
  after pop(): size==2 && top()==2: OK
  drain to empty: size==0 && empty(): OK
  all phases OK
> benchmark log 1000
  N=   1000   Chain::push_front =     1.86 ms   Bag::insert(begin) =    29.57 ms

4)about to call top() on an empty stack...
top() =

Exception thrown: read access violation.
dungeon::Stack <int>::top(...) returned nullptr.

Stack doesn't promise that accessing an element is valid when it's empty so you have to check if it's empty before trying to modify it

5)2: recursive=0  stack=0
13: recursive=3  stack=3
55: recursive=6  stack=6
4: recursive=-1  stack=-1
99: recursive=-1  stack=-1

int binSearchStack(const std::vector<int>& v, int target) {
    Stack<Range> ranges;
    ranges.push({0, static_cast<int>(v.size())});

    while (!ranges.empty()) {
        Range r = ranges.top();
        ranges.pop();

        if (r.lo >= r.hi) {
            continue;
        }

        int mid = r.lo + (r.hi - r.lo) / 2;

        if (v[mid] == target) {
            return mid;
        }

        if (v[mid] < target) {
            ranges.push({mid + 1, r.hi});
        } else {
            ranges.push({r.lo, mid});
        }
    }

    return -1;
}


The recursive version hides the stack call and manages the function automatically.
The stack version does everything within the stack itself and keep track of the ranges

6)Although we only wrote the four one line top calls, the rest of the week is trying to
help understand why methods work and how it works with data structures.  It was similar to
floor 4 because we did all the code with the destructors and everything but spent time trying to understand
the Rule of Three and everything else around that.  