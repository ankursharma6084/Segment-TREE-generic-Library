
#include<iostream>
// using namespace std;


#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <vector>

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

        
      // Private Member Functions

      

      private:

    // Add Nodes to the segmnet tree

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

   // Bullid the tree

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


    // For updates

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