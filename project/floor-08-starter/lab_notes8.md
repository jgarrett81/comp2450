1)> selftest tree
  empty Tree<int>: empty() && size==0 && height==0: OK
  addChild: root==1 with 3 children: OK
  size()==7 over the sample tree: OK
  height()==2 (longest path 1->2->5): OK
  preOrder == {1,2,5,6,3,4,7} (depth-first): OK
  levelOrder == {1,2,3,4,5,6,7} (breadth-first): OK
  lineage(6)=={1,2,6} and lineage(404) empty: OK
  all phases OK
> taxonomy
Creatures of the Hold
    - Undead
        - Corporeal
            - Skeleton
            - Necrothrall
            - Lich
        - Incorporeal
            - Wraith
            - Wisp
    - Beasts
        - Mammals
            - Shadow Hound
            - Ironclaw Bear
            - Cinder Bat
        - Giants
            - Cave Troll
            - Frostmaw
    - Vermin
        - Bone Spider
        - Ratking
        - Marsh Lurker
    - Constructs
        - Stone Sentinel
  (23 creatures and categories; height 3)
> taxonomy --bfs
  breadth-first (level-order):
    Creatures of the Hold
    Undead
    Beasts
    Vermin
    Constructs
    Corporeal
    Incorporeal
    Mammals
    Giants
    Bone Spider
    Ratking
    Marsh Lurker
    Stone Sentinel
    Skeleton
    Necrothrall
    Lich
    Wraith
    Wisp
    Shadow Hound
    Ironclaw Bear
    Cinder Bat
    Cave Troll
    Frostmaw
> lineage Wisp
  Creatures of the Hold > Undead > Incorporeal > Wisp
> lineage Goblin
  'Goblin' is not in McCown's catalogue.
> quit
McCown notes your departure on the chart. "You leave classified."

2) if (n == nullptr) return 0;

   for (size_t i = 0; i < n->children.size(); i++){
        some sort of count
        }

   return/ push_back

   What they do differently is what they end up doing with the results.  
   Count from adds the nodes, height finds the longest path, and preOrder records the nodes in order

3) Lich does because DFS explores the Undead branch first all the way through, 
but BFS goes level by level so Lich isn't seen until later

4) I put Goblin under beasts/mammals because it just seems right compared to the other spots

> taxonomy
Creatures of the Hold
    - Undead
        - Corporeal
            - Skeleton
            - Necrothrall
            - Lich
        - Incorporeal
            - Wraith
            - Wisp
    - Beasts
        - Mammals
            - Shadow Hound
            - Ironclaw Bear
            - Cinder Bat
            - Goblin
        - Giants
            - Cave Troll
            - Frostmaw
    - Vermin
        - Bone Spider
        - Ratking
        - Marsh Lurker
    - Constructs
        - Stone Sentinel
  (24 creatures and categories; height 3)
> lineage Goblin
    Creatures of the Hold > Beasts > Mammals > Goblin

  you don't have to recompile because it just reads it out of .txt

  5)taxonomy --dfs
  depth-first (pre-order):
    Creatures of the Hold
    Undead
    Corporeal
    Skeleton
    Skeleton
    Necrothrall
    Necrothrall
    Lich
    Lich
    Corporeal
    Incorporeal
    Wraith
    Wraith
    Wisp
    Wisp
    Incorporeal
    Undead
    Beasts
    Mammals
    Shadow Hound
    Shadow Hound
    Ironclaw Bear
    Ironclaw Bear
    Cinder Bat
    Cinder Bat
    Goblin
    Goblin
    Mammals
    Giants
    Cave Troll
    Cave Troll
    Frostmaw
    Frostmaw
    Giants
    Beasts
    Vermin
    Bone Spider
    Bone Spider
    Ratking
    Ratking
    Marsh Lurker
    Marsh Lurker
    Vermin
    Constructs
    Stone Sentinel
    Stone Sentinel
    Constructs
    Creatures of the Hold

    The nodes now appear after their descendants because the function processes the children first and records the current node last

  6) lineage Stone Sentinel
     Nodes visited: 24

       It gives no speedup because it still is checking every Node to find it.
       You would need a way to sort them to be able to differentiate and be able to go down to the correct Nodes quicker

 7) The biggest new thing about a tree was learning how to work with a structure that branches instead of following one straight line.
    The trees can now have layers on layers on layers which is so much different than what we've worked with.  