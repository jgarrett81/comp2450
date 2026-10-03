(Everything was ran in the floor 6 starter because I don't know what's wrong with my code but it won't run correctly 
and I spent literally an hour trying to compare eveything we did in class over the week compared to floor 6 and couldn't figure it out)

1)> search Goblin
Goblin   HP 8   ATK 2   weakness: fire
  (found in bestiary)
> search Iron key
  Iron key  (wt 0.1, val 0)
  (found in inventory)
> search began
  began session as "josh"
  (found in event log)
> log
   1.  search began ΓÇö found in event log
   2.  search Iron key ΓÇö found in inventory
   3.  search Goblin ΓÇö found in bestiary
   4.  began session as "josh"
  (newest first; chain length 4)
> log --oldest 3
   1.  began session as "josh"
   2.  search Goblin ΓÇö found in bestiary
   3.  search Iron key ΓÇö found in inventory
  (oldest first; chain length 4)
> selftest iterator
  range-for over Chain<int>: OK
  std::find(Chain<int>, 42): OK
  std::distance(begin, end): OK
  range-for over const Chain<int>&: OK
  std::reverse(Chain<int>) ΓÇö first now == 9: OK
  all phases OK
> quit
The cantor falls silent. The last echo decays. The hall is quiet.

2) search Goblin
Goblin   HP 8   ATK 2   weakness: fire
  (found in bestiary)
> search Iron key
  Iron key  (wt 0.1, val 0)
  (found in inventory)
> log
   1.  search Iron key ΓÇö found in inventory
  (newest first; chain length 3)

3) > search Goblin
Goblin   HP 8   ATK 2   weakness: fire
  (found in bestiary)
> search Iron key
  Iron key  (wt 0.1, val 0)
  (found in inventory)
> log
  (the chain is empty ΓÇö nothing to remember yet)
> selftest iterator
  range-for over Chain<int>: FAIL ΓÇö begin == end (stub returns true) ΓÇö implement operator++ and operator==
  std::find(Chain<int>, 42): FAIL ΓÇö std::find returned end() ΓÇö likely operator++ stub or operator== stub
  std::distance(begin, end): FAIL ΓÇö expected 100 ΓÇö got 0 means begin == end immediately (operator== stub)
  range-for over const Chain<int>&: OK
  std::reverse(Chain<int>) ΓÇö first now == 9: FAIL ΓÇö operator-- not yet wired (Friday) ΓÇö std::reverse can't walk back
  (see FAILs above)

  end has to point one past the end but if it points to the begin, it can only do that for a empty list
  so if it points to the beginning it thinks the log is empty even when it may not be

  4)binary '-': 'const_InIt' does not define this operator or a conversion to a type acceptable to the predefined operator
  'std::_Sort_unchecked':no matching overloaded function found

  std::sort needs to be able to randomly go throughout the list but the iterator only allows it to move one position at a time

5)
auto
for (const auto& s : hero.eventLog) std::cout << s << "\n";

spelled out
for (Chain<std::string>::const_iterator it = hero.eventLog.cbegin();
     it != hero.eventLog.cend(); ++it)
    std::cout << *it << "\n";

the auto version is easier because it reads the iterator type for me.
if the type were to change then you would have to go and change the spelled out version

6)It got rid of the begin and end because of the iterators and nodes. it allows the iterator to be anywhere and 
move up or down around the lsit and doesn't need to knwo where the start and end are because it just compares it to 
nullptr. So the beginning and end are chosen by the iterator and the way it iterates. That's what allows
the code to be condensed