# Segment-TREE-generic-Library


1. Include the segment tree file like this  #include"segment_tree.h"
2. To define a segmennt tree use    SegmentTree<Type> seg(vector,value,compare);
  
  eg -  For Gcd in a range
        
        a) int comp(int a,int b)
         return __gcd(a,b);
 
        SegmentTree<int> seg(a,n,0,comp);   // Here a is array and n is length and 0 is default value
  
  
  
   eg -    For Max element in a range
  
        b) int comp(int a,int b)
           return max(a,b);
 
        SegmentTree<int> seg(a,n,INT_MIN,comp);   // Here a is array and n is length and INT_MIN is default value
  

3. Solved Question Link and CODE
 Question- https://codeforces.com/contest/1547/problem/F
 Solution-https://codeforces.com/contest/1547/submission/123074046
