#include<iostream>
#include<algorithm>
using namespace std;



int main(){
int N;
cout<<"Enter the size of the log: ";
cin>>N;
int prices[N];
cout<<"Enter prices we get for each piece we cut"<<endl;
for(int i=0;i<N;i++){
    cin>>prices[i];
}
cout<<"Find what is the maximum profit we can obtain by cutting the rod: ";
int dp[N+1][N+1];
for(int i=0;i<=N;i++){
    for(int j=0;j<=N;j++){
        if(i==0 || j==0){
            dp[i][j]=0;
        }
        
    }
}
for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
        if(i<=j){
            dp[i][j]=max(prices[i-1]+dp[i][j-i],dp[i-1][j]);
        }
        else dp[i][j]=dp[i-1][j];
    }
}
cout<<dp[N][N]; 

}