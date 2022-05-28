#include<iostream>
#include<vector>
using namespace std;

//For recursive approach
int coin_change_rec(int amount,int coins[],int n){
    if(n==0)return 0;
    if(amount==0)return 1;
    if(coins[n-1]<=amount){
        return coin_change_rec(amount-coins[n-1],coins,n)+coin_change_rec(amount,coins,n-1);
    }
    else return coin_change_rec(amount,coins,n-1);
}
//For memorization approach
vector<vector<int>>mem;
int coin_change_mem(int amount,int coins[],int n){
    if(n==0)return 0;
    if(amount==0)
    return 1;
    if(mem[n][amount]!=-1)return mem[n][amount];
    if(coins[n-1]<=amount)
   return  mem[n][amount]=coin_change_mem(amount,coins,n-1)+coin_change_mem(amount-coins[n-1],coins,n);
    else 
   return  mem[n][amount]=coin_change_mem(amount,coins,n-1);
}
int main(){

    int n,sum;
    cout<<"Enter different denominations of coins available: ";
    cin>>n;
    int coin[n];
    cout<<"Enter the denominations of coins: ";
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    cout<<"Enter the sum of which you want number of ways: ";
    cin>>sum;
    // if memorization approach
    // mem.resize(n+2,vector<int>(sum+2,-1));
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
        if(j==0)
        dp[i][j]=1;
        else
        dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coin[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
cout<<dp[n][sum];
}