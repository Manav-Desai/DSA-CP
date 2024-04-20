/* Implementing Disjoint Set Union By Rank and Path compression
    For complete explanation : refer codestorywithMIK video 18 and 19 and 
    article explanation by striver
*/

#include <iostream>
#include <vector>
using namespace std;

class DSU
{
    private:
        vector<int> parent;
        vector<int> rank;
    
    public:
        DSU(int n)
        {
            parent.resize(n+1,0);
            rank.resize(n+1,0);

            for(int i=0 ; i<=n ; i++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        int findParent(int x)
        {
            if(x == parent[x])
                return x;
            
            return parent[x] = findParent(parent[x]);
        }
        void unionElement(int x,int y)
        {
            int x_parent = findParent(x);
            int y_parent = findParent(y);

            if(x_parent == y_parent)
                return;
            
            if(rank[x_parent] > rank[y_parent])
            {
                parent[y_parent] = x_parent;
            }
            else if(rank[x_parent] < rank[y_parent])
            {
                parent[x_parent] = y_parent;
            }
            else
            {
                // both have same rank so we can choise anyone to be parent
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
};