#include<bits/stdc++.h>
// #include"../segment_tree.h"


                  /*        By 
                               ANKUR KUMAR
                               NIT JAMSHEDPUR

                   /*             Segment Tree Code Starts         */



                   // Problem LINK
                   // https://codeforces.com/contest/1547/problem/F


#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

// #include <vector>

template<class T>
class SegmentTree
{

       private:

      T* TreeNode;
      int vec_size;
      T default_val;

       T (*compare)(T obj1, T obj2);


    public:

        //tree constructors.

        // when you give vector as input
        SegmentTree(std::vector<T> &data, T value, T (*compare)(T obj1, T obj2)){

            this->vec_size=data.size();
            this->default_val=value;
            this->compare=compare;

            int size=4*data.size()+1;
            TreeNode= new T[size];

            buildtree(data);
        }

       // when you give array as input
        SegmentTree(T arr[], int n, T value, T (*compare)(T obj1, T obj2)){

            std::vector<T> data;
            this->vec_size=n;
            this->default_val=value;
            this->compare=compare;



            for(int i=0;i<n;i++)
            {
                data.push_back(arr[i]);
            }

              int size=4*data.size()+1;
              TreeNode= new T[size];

            buildtree(data);
        }


        // print tree

        void print_segtree()
        {
            for(int i=0;i<2*vec_size;i++)
             std::cout<<TreeNode[i]<<" ";
             std::cout<<std::endl;
        }


         //query the range l to r, 0 based array indexing.

             T query(int l, int r){
                  
                  return query_helper(l,r,0,vec_size-1,0);
             }
        
        //update the element at index idx to val.
        void update(int idx, T val){

           update_query(0,vec_size-1,idx,val,0);

        }

        


      

      private:


    void fillNodes(std::vector<T> &data,int startidx,int endidx,int index)
    {
        if(startidx==endidx)
        {
            TreeNode[index]=data[endidx];
            return;
        }

        int mid=(startidx-(startidx-endidx)/2);

        fillNodes(data,startidx,mid,2*index+1);
        fillNodes(data,mid+1,endidx,2*index+2);



        TreeNode[index]= compare(TreeNode[2*index+1], TreeNode[2*index+2]);


    }


     void buildtree(std::vector<T> &data)
     {


        fillNodes(data,0,vec_size-1,0);

     }


     T query_helper(int leftq,int rightq,int si,int ei,int index)
     {
         if(si>=leftq && ei<=rightq)
         {
             return TreeNode[index];
         }

         if(si>rightq || ei<leftq)
         {
             return default_val;
         }

         int mid=(si+ei)/2;

         T left= query_helper(leftq,rightq,si,mid,2*index+1);
         T right= query_helper(leftq,rightq,mid+1,ei,2*index+2);

         return compare(left,right);
     }



    void update_query(int ss,int se,int i,T val,int idx)
  {
      if(i>se || i<ss) return;

      if(ss==se)
      {
          TreeNode[idx]+=val;
          return;
      }

      int mid=(ss+se)/2;

      update_query(ss,mid,i,val,2*idx+1);
      update_query(mid+1,se,i,val,2*idx+2);

      TreeNode[idx]= compare( TreeNode[2*idx+1], TreeNode[2*idx+2]);


  }


};

#endif


                      /*             Segment Tree Code Ends           */

                          // Problem LINK
                   // https://codeforces.com/contest/1547/problem/F

                 
   

using namespace std;
 
#define ll long long
#define mod 1000000007
#define fo(i,s,n) for(int i=s;i<n;i++)
#define f(i,n) for(int i=0;i<n;i++)
#define taket int t;  cin>>t;  while(t--)
#define ipn long long n;  cin>>n; 
#define pb push_back
#define mp make_pair
#define umpii unordered_map<ll,ll>
#define mpii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define null NULL
#define inf INT_MAX
#define all(vec) vec.begin(),vec.end()
 
 

bool check(int n ,int* a,int mid, SegmentTree<int> &seg)
{

        int temp=seg.query(0,mid);
 
         for(int i=1;i<n;i++)
         {
             if(i+mid<n)
             {
                int x=seg.query(i,i+mid);
 
                if(x!=temp) return 0;
             }
 
             else{
                  int x=seg.query(i,n-1);
                  int y=seg.query(0,(i+mid)%n);
 
                  int z=__gcd(x,y);
 
                  if(z!=temp) return 0;
 
             }
         }
 
 
         return 1;
}
 
 
 int comp(int a,int b)
 {
     return __gcd(a,b);
 }

 
int main()  {
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  taket{
  
   int n; cin>>n;
    int a[n],vis[n]={0};

 
    f(i,n) cin>>a[i];

    SegmentTree<int> seg(a,n,0,comp);

 
    int s=0,e=n-1;
 
    int ans=0;
 
    while(s<=e)
    {
        
        int mid= (s+e)/2;
 
        if(check(n,a,mid,seg))
        {
          ans=mid;
          e=mid-1;
        }
 
        else
         s=mid+1;
    }
 
  cout<<ans<<endl;
 
  } 
 
 
return 0;
}