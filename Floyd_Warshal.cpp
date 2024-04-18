/*
It is a Dp based algorithm to find out shortest path from all possible nodes to any node . It
is multisource shortest path algo .

Advantages compared to Dijsktra :   It can work with negative edge weights .
                                    It can detect negative edge weight cycle
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Floyd_Warshal(vector<vector<int>> adjMatrix)
{
    int n = adjMatrix.size();
    vector<vector<int>> cost;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cost[i][j] = adjMatrix[i][j];
        }
    }

    // algo : TC = O(N^3)

    for(int k=0 ; k<n ; k++)
    {
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(cost[i][k] != 1e9 && cost[k][j] != 1e9)
                {
                    cost[i][j] = min(cost[i][j] , cost[i][k] + cost[k][j]);
                }
            }
        }
    }

    return cost;
}