1)> selftest bst
  empty BST<int>: empty() && size==0 && height==0: OK
  insert: root==5 and size==7 over the sample: OK
  contains: 7 and 2 present, 6 and 404 absent: OK
  inOrder == {2,3,4,5,7,8,9} (ascending): OK
  degenerate: sorted inserts give height==5, not balanced: OK
  deep copy: mutating the original leaves the copy unchanged: OK
  remove: leaf(2), one-child(3), two-children(5) all correct: OK
  all phases OK
> catalogue
Bone Spider   HP 6   ATK 2   weakness: fire
Cave Troll   HP 28   ATK 7   weakness: fire
Cinder Bat   HP 4   ATK 1   weakness: water
Frostmaw   HP 22   ATK 6   weakness: fire
Goblin   HP 8   ATK 2   weakness: fire
Ironclaw Bear   HP 24   ATK 5   weakness: slashing
Lich   HP 35   ATK 6   weakness: holy
Marsh Lurker   HP 18   ATK 3   weakness: fire
Necrothrall   HP 16   ATK 4   weakness: light
Ratking   HP 9   ATK 2   weakness: fire
Shadow Hound   HP 12   ATK 4   weakness: light
Skeleton   HP 10   ATK 3   weakness: blunt
Stone Sentinel   HP 30   ATK 5   weakness: blunt
Wisp   HP 3   ATK 1   weakness: holy
Wraith   HP 14   ATK 4   weakness: holy
  (15 creatures, alphabetical; tree height 6)
> recall Lich
Lich   HP 35   ATK 6   weakness: holy
  (recalled from the tree)
> recall Drake
  'Drake' is not in McCown's catalogue.
> forget Goblin
  McCown strikes 'Goblin' from the tree. (14 remain.)
> benchmark bst

-- Bestiary: linear scan vs BST lookup (1000 iterations per cell) --
  N=    100  query=last    linear=     2.738 us  BST=     0.231 us  (tree height 13)
  N=    100  query=absent  linear=     0.816 us  BST=     0.152 us  (tree height 13)
  N=   1000  query=last    linear=    13.437 us  BST=     0.351 us  (tree height 22)
  N=   1000  query=absent  linear=     8.515 us  BST=     0.359 us  (tree height 22)
  N=  10000  query=last    linear=   136.555 us  BST=     0.448 us  (tree height 30)
  N=  10000  query=absent  linear=    84.478 us  BST=     0.464 us  (tree height 30)
  N= 100000  query=last    linear=  1303.617 us  BST=     0.373 us  (tree height 40)
  N= 100000  query=absent  linear=   828.980 us  BST=     0.329 us  (tree height 40)

Linear scan grows with N; BST lookup grows with log N ΓÇö the same
win binary search gave you on Floor 1, but now the structure STAYS
searchable as you insert and remove, with no re-sort step.
One catch: this tree was built from SHUFFLED data. Insert the
monsters already sorted and the BST degenerates into a stick
(height ~N), and lookup drops right back to linear ΓÇö the problem
the next floor's self-balancing tree exists to solve.

> quit
McCown notes your departure. "You leave in order."

2) Left, Right, Right, Found
Looked at 4 Nodes, Didn't look at 5
Number is the same as the tree's height because 7 was the deepest node

3) 1, 3, 4, 6, 7, 8, 10, 13, 14
In-order traversal gaurentees ascending order because the left node will always be smaller than the parent and the parent will always be smaller the right node

4)Remove 4:
          8
        /   \
       3     10
      / \      \
     1   6      14
          \    /
           7  13

Leaf case because 4 had no children
Remove 10: 
          8
        /   \
       3     14
      / \   /
     1   6 13
          \
           7

One child case because 10 only had one child

Remove 8:
          13
        /    \
       3      14
      / \
     1   6
          \
           7
Two child case because 8 had two children

The value 13 moved up because it was the smallest value in the right subtree
This makes it larger than everything on its left and smaller than everything else on its right, preserving the BST ordering rule.


5) > benchmark bst

-- Bestiary: linear scan vs BST lookup (1000 iterations per cell) --
  N=    100  query=last    linear=     2.738 us  BST=     0.231 us  (tree height 13)
  N=    100  query=absent  linear=     0.816 us  BST=     0.152 us  (tree height 13)
  N=   1000  query=last    linear=    13.437 us  BST=     0.351 us  (tree height 22)
  N=   1000  query=absent  linear=     8.515 us  BST=     0.359 us  (tree height 22)
  N=  10000  query=last    linear=   136.555 us  BST=     0.448 us  (tree height 30)
  N=  10000  query=absent  linear=    84.478 us  BST=     0.464 us  (tree height 30)
  N= 100000  query=last    linear=  1303.617 us  BST=     0.373 us  (tree height 40)
  N= 100000  query=absent  linear=   828.980 us  BST=     0.329 us  (tree height 40)

Linear scan grows with N; BST lookup grows with log N ΓÇö the same
win binary search gave you on Floor 1, but now the structure STAYS
searchable as you insert and remove, with no re-sort step.
One catch: this tree was built from SHUFFLED data. Insert the
monsters already sorted and the BST degenerates into a stick
(height ~N), and lookup drops right back to linear ΓÇö the problem
the next floor's self-balancing tree exists to solve.

The BST was very fast because the monsters were inserted in shuffled order 
keeping the tree relatively balanced as it grew from 100 to 100,000 nodes
If I had inserted the monsters in alphabetical order, the tree would have become a 
stick with a height of approximately N, making recall much slower because it would 
have to search through potentially every node, just like a linear scan.

6) The BST is different from the general Tree because it has an ordering rule that allows it to search for values much faster.
In a general Tree, you might have to look through every branch to find something, but a BST allows you to eliminate branches 
based on whether a value is larger or smaller than the current node. However, this ordering rule makes removing nodes more complicated, 
especially when a node has two children, because you have to find a replacement value that keeps the tree in order. Writing the 
destructor felt different from reading it because I had to think about how to actually delete every node and make sure I wasn't leaving anything behind.