1)
> search Goblin
Goblin   HP 8   ATK 2   weakness: fire
> inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
> inspect 99
No such item. (index 98 out of bounds for size 5)
> log --oldest 5
oldest first; chain length 4
> clone hero
  -- original log (newest first) --
   1.  error: index 98 out of bounds for size 5
   2.  inventory ΓÇö listed 5 items
   3.  search Goblin ΓÇö found in bestiary
   4.  began session as "josh"
  (newest first; chain length 4)
  -- cloned log (newest first) --
   1.  error: index 98 out of bounds for size 5
   2.  inventory ΓÇö listed 5 items
   3.  search Goblin ΓÇö found in bestiary
   4.  began session as "josh"
  (newest first; chain length 4)
  (clone is being destroyed now)
  (clone destroyed; original event log still has 4 entries ΓÇö try `log 3`)
> log 3
   1.  clone hero ΓÇö copy lived and died
   2.  error: index 98 out of bounds for size 5
   3.  inventory ΓÇö listed 5 items
  (newest first; chain length 5)
> selftest chain
  Phase 1 (single chain)
    allocations:  1000   deallocations:  1000   leaked:     0   OK
  Phase 2 (deep copy)
    original after copy died ΓÇö forward walk:  1000   backward walk:  1000
    copy before death        ΓÇö forward walk:  1000   backward walk:  1000
    allocations:  2000   deallocations:  2000   leaked:     0   OK
> quit
The forge cools. Two chains dissolve, each by its own hand.

2) oldest first; chain length 1
When it tries to go to the previous but it fails on the walk

3) Exception thrown: read access violation.
Deletion of the second node so both are pointing the same

4)I would probably be more confident to write the copy and swap.
It's shorter and quicker to write would be easier to command

5) Because singlely-linked can't move back from the tail so it would have to read al the way through as O(N)

6)If a class needs destructor, copy contructor, or a copy operator it probably needs all three;
Rule of zero would be used when the class can just use like vectors to do its job.
Chain<T> doesn't qualify because it needs to use the three to protect and keep the nodes organized and not leak or overflow