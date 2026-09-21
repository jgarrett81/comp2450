1) > search Goblin
Goblin   HP 8   ATK 2   weakness: fire
> inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
> sort inventory by value desc
   1.  Cloak of shadows  (wt 1.5, val 80)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Rusty sword       (wt 4.0, val 5)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Iron key          (wt 0.1, val 0)
> benchmark log 10000
  N=  10000   Chain::push_front =    10.37 ms   Bag::insert(begin) =  2835.75 ms
> selftest chain
  Chain<int> allocations:  1000   deallocations:  1000   leaked:     0   OK
> quit
The forge cools. The chain dissolves link by link.

2)  Chain<int> allocations:  1000   deallocations:     0   leaked:  1000 

3) "Can not be referenced -- it is a deleted function
-It messes up because it would be trying to point both objects to the same node which I think would mess up 
stuff with deletion and memoy when the program would end

4)  benchmark log 10000
  N=  10000   Chain::push_front =     9.14 ms   Bag::insert(begin) =  2850.57 ms

  - Because the vector is shifting every element one position at a time to make room for the new one 
  that's why it can take so much longer

5) Maven keeps the bestiary in a Bag because the bag is designed to just store the items without an order 
making it easy to access and hold them as a collection.  The event log uses Chain<std::string> because it's an event log
which is a chronological order of events so you have to have an order which the chain does.
If they were swapped the bestiary would lose its benefits of a collection for managing the items and the event log
would become worse because it wouldn't be in a necessary order