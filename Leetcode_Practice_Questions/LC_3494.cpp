#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long>free(n,0);
        for(int j=0;j<m;j++)
        {
          long long now=free[0];
          for(int i=1;i<n;i++)
          {
             now=max(now+1LL*skill[i-1]*mana[j],free[i]);
          }
          free[n-1]=now+skill[n-1]*1LL*mana[j];
          for(int k=n-2;k>=0;k--)
          {
            free[k]=free[k+1]-skill[k+1]*1LL*mana[j];
          }
        }
        return free[n-1];
    }
};