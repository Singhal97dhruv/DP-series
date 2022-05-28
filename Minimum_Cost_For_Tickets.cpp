// You have planned some train traveling one year in advance.
//  The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;


// int recur(vector<int>day,vector<int>cost,int st_idx){
//     int n=day.size();
//     if(st_idx>=n)return 0;
//     int cost_day=cost[0]+recur(day,cost,st_idx+1);
//     int i;
//     for(int i=st_idx;i<n && day[i]<day[st_idx]+7;i++);
//         int cost_week=cost[1]+recur(day,cost,i);
    
//     for(int i=st_idx;i<n && day[i]<day[st_idx]+30;i++);
//         int cost_month=cost[2]+recur(day,cost,i);

//     return min({cost_day,cost_week,cost_month});

// }
int sub(vector<int> &day, vector<int> &cost, int si)		// si denotes starting index
    {
        int n = day.size();
        if(si>=n)   return 0;
        
        int cost_day = cost[0] + sub(day , cost , si+1);
        
        int i;
        for(i = si ; i<n and day[i]<day[si]+7 ; i++);   //skip till ith day is curr_day+7 as we are buying week pass
        int cost_week = cost[1] + sub(day, cost, i);
        
        for(i = si ; i<n and day[i]<day[si]+30 ; i++);   //skip till ith day is curr_day+30 as we are buying month pass
        int cost_month = cost[2] + sub(day, cost, i);      
        
        return min({cost_day, cost_week , cost_month  });
    }


using namespace std;
int main(){
    int n=6,temp;
    vector<int>days,costs;
    cout<<"Enter the days you travel";
    for(int i=0;i<n;i++){
        cin>>temp;
        days.push_back(temp);
    }
    cout<<"Enter the cost for 1-day ,7-day , 30-day travel: ";
    for(int i=0;i<3;i++){
        cin>>temp;
        costs.push_back(temp);
    }
    // cout<<sub(days,costs,0);   for recursion purpose
    unordered_set<int>day(days.begin(),days.end());
    vector<int>dp(367);
    for(int i=1;i<=365;i++){
        dp[i]=dp[i-1];
        if(day.find(i)!=day.end())
        dp[i]=min({dp[i-1]+costs[0],dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]});
    }
    cout<<dp[365];
    
}