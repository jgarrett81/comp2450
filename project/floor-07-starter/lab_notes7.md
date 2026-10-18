1)> selftest queue
  empty Queue<int>: size==0 && empty(): OK
  enqueue(7): size==1 && front()==7: OK
  enqueue 1,2,3: size==3 && front()==1 (FIFO): OK
  after dequeue(): size==2 && front()==2: OK
  drain to empty: size==0 && empty(): OK
  all phases OK
> potato A B C D E 3
  Survivor: D
> potato Grix Skrill Quill Vael Resh 2
  Survivor: Quill
> potato OnlyOne 7
  Survivor: OnlyOne
> provoke Goblin
  Goblin takes a number and joins the line.
> provoke Skeleton
  Skeleton takes a number and joins the line.
> provoke Imp
  Imp takes a number and joins the line.
> simulate
  Turn 1: Goblin stirs in the dark.
  Turn 2: Skeleton stirs in the dark.
  Turn 3: Imp stirs in the dark.
All enemies have acted; the line is empty.
> simulate
No enemies are in line. Use `provoke <name>` first.
> quit
Quill stamps your ticket. The line shuffles forward by one.

2)
Job	                                         Stack<T> calls…	              Queue<T> calls…
add an item (push / enqueue)	 	         chain_.push_front(value);        chain_.push_back(value);
remove an item (pop / dequeue)	 	         chain_.pop_front()               chain_.pop_front()
read the next item out (top / front)	 	 return chain_.head()->data       return chain_.head()->data;

A stack and queue are different because stack uses last in first out while queue uses first in first out
Queue uses Chain<t> rather than Bag<t> because a Chain keeps the order of item which a queue needs to be able to implement the first in first out

3)> selftest queue
  empty Queue<int>: size==0 && empty(): OK
  enqueue(7): size==1 && front()==7: OK
  enqueue 1,2,3: size==3 && front()==1 (FIFO): FAIL ΓÇö front() did not return the FIRST enqueued value ΓÇö enqueue/front are on the same end (that's a stack, not a queue)
  after dequeue(): size==2 && front()==2: OK
  drain to empty: size==0 && empty(): OK
  (see FAILs above)
> potato A B C D E 3
  Survivor: A

  You build a stack instead of a queue because you now implement last in first out

Phase 4 passed because it only tests with size three so no matter which way you do it the middle number will always be the front after you dequeue the front or the back

4) potato A B C D 2
  Survivor: A
  Yes I predicted it

5) I kind of already knew what I needed to write except I just had to change a few things to make it first in first out.  But overall
it was easy to actually make everythign work.