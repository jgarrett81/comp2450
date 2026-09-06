1)N=     10  mergeSort=   0.043 ms  quicksort=    0.012 ms  std::sort=   0.007 ms
  N=    100  mergeSort=   2.729 ms  quicksort=    0.200 ms  std::sort=   0.127 ms
  N=   1000  mergeSort= 278.783 ms  quicksort=    2.702 ms  std::sort=   2.097 ms
  N=  10000  mergeSort=24088.817 ms  quicksort=   40.515 ms  std::sort=  28.584 ms

  (I don't know what is wreong with my mergeSort and why it is sooooo much higher than the rest of them)

2) Sort clearly pulls ahead at inventory size of 1000

3) With presort input, quicksort and std::sort get faster while mergeSort gets slightly slower. At N = 10000
   quickSort decrease by about 10 ms and std:: sort by about 21 ms, but MergeSort increases by a decent amount.
   mergeSort has to perform similar amounts of work no matter how organized the inventory is

4) When N doubles, the middle-pivot quicksort time about doubles, however, the first-element pivot time increase 4x
   The middle pivto has O(nlogn) growth, while first-element has O(n^2) growth.  It's alarming because the running will grow dramatically as input size increases

5) If I could ship one of the three, it would definitely be the std::sort.  It has the overall best average-case performance and is just much
   more optimized compared to the other two.  It's worse case is also safer than the basic implementations.  The other two can perform better on certain types 
   of data but since the data is not alwasy predictable, std::sort would be my choice