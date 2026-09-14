1. search Goblin
Goblin   HP 8   ATK 2   weakness: fire
> search Iron Key
No such creature/ item stalks this keep.
> inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
> inspect 3
  Iron key  (wt 0.1, val 0)
> inspect 99
No such item. (index98out of bounds for size 5
> sort inventory by weight
   1.  Iron key          (wt 0.1, val 0)
   2.  Loaf of bread     (wt 0.1, val 1)
   3.  Healing potion    (wt 0.5, val 12)
   4.  Cloak of shadows  (wt 1.5, val 80)
   5.  Rusty sword       (wt 4.0, val 5)
> benchmark sort 10000
  N=  10000  mergeSort=  57.923 ms  quicksort=   40.104 ms  std::sort=  28.165 ms


2. **Instantiate `Bag<int>` in a throwaway test and call `findByName` on it.** Paste the full compiler error. Circle (or describe) the one line that actually tells you what's wrong. Why is this harder to read than a normal type error, and what does that tell you about templates?
    - I couldn't figure out how to run a test, like I made another file, tried it main.cpp but couldn't get the complier error
3. **Swap `.at()` for `[]`** in the `inspect` command. Pass a bad index. Describe what the program does now — does it crash? Print garbage? Silently return? Restore `.at()` when done. One sentence: when would you ever want `operator[]` over `.at()` in production?
     - It crashes, you would only use it when you know that the index will be valid
4. **Remove the try/catch around the main loop.** Trigger a bad `inspect`. Describe exactly what you see on stderr — the unhandled-exception message the runtime prints before `std::terminate`. Put the catch back. Then try the anti-pattern `catch (...) { }` (empty body) and describe what is now *worse* than having no catch at all.
     -It triggers an unhandled exception at a certain sot in Bag.h, what's worse is that it doesn't give an error message it just keeps the program running
5. **Change `BagException` so it does NOT inherit from `std::exception`.** What still compiles? What behavior (if any) do you lose? One sentence on why inheriting from `std::exception` is the right default.
    - The build failed and didn't even work so i guess you lose everything or at least I did, but std:exception gives you the base what and allows you to work with custom exceptions as well
