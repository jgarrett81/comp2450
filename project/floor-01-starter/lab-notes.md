1. -- Race the Bestiary (1000 iterations per cell) --
  N=     10  query=last    linear=     0.293 us  binary=   0.142 us  recursive=   0.154 us
  N=     10  query=absent  linear=     0.101 us  binary=   0.089 us  recursive=   0.087 us
  N=    100  query=last    linear=     1.764 us  binary=   0.173 us  recursive=   0.174 us
  N=    100  query=absent  linear=     0.896 us  binary=   0.157 us  recursive=   0.153 us
  N=   1000  query=last    linear=    13.431 us  binary=   0.273 us  recursive=   0.266 us
  N=   1000  query=absent  linear=     8.492 us  binary=   0.223 us  recursive=   0.230 us
  N=  10000  query=last    linear=   127.212 us  binary=   0.362 us  recursive=   0.400 us
  N=  10000  query=absent  linear=    80.691 us  binary=   0.295 us  recursive=   0.331 us
  N= 100000  query=last    linear=  1281.853 us  binary=   0.471 us  recursive=   0.517 us
  N= 100000  query=absent  linear=   792.120 us  binary=   0.364 us  recursive=   0.413 us

2. At what bestiary size does binary search start to clearly beat linear?
- At N = 100, binary clearly starts to bear linear, although it does beat it at N = 10, it's very minimal difference

3. For N = 10, which is faster, and why might that surprise a beginner?
- Binary is faster and that might surprise a beginner because the difference is so small at a small bestiary size 
and linear may do less work if the item is near the beginning

4. What happens when you call binarySearch on the unsorted bestiary?
- The binary search expects the data to be sorted so it often causes it to fail because what it's looking for isn't in the right place

5. Iterative vs Recursive binary search, do their pre-call times differ?
- They are both very close in speed even up to N = 100000, but iterative is a little faster because of the extra function call of the recursive
