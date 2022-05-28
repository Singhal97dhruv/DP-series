#include<iostream>
using namespace std;

int coin_change_recur(int amount,int coin[],int n){
    if(n==0)return INT_MAX-1;
    if(amount==0)return 0;
    if(coin[n-1]<=amount){
        return min(1+coin_change_recur(amount-coin[n-1],coin,n),coin_change_recur(amount,coin,n-1));
    }
    else
    return coin_change_recur(amount,coin,n-1);
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
    cout<<"Enter the sum of which you want minimum number of coins used: ";
    cin>>sum;
    int dp[n+1][sum+1];
    for(int j=0;j<=sum;j++){
        dp[0][j]=INT_MAX-1;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coin[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    // int N=sizeof(coin)/sizeof(coin[0]);
    // cout<<coin_change_recur(sum,coin,N);     For recursive solution

    cout<<dp[n][sum];
}