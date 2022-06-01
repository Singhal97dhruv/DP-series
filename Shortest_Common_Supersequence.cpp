#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lcs(string X,string Y,int m,int n){
    if(m==0 || n==0)return 0;
    if(X[m-1]==Y[n-1]){
        return 1+lcs(X,Y,m-1,n-1);
    }
    else{
        return max(lcs(X,Y,m-1,n),lcs(X,Y,m,n-1));
    }
}

vector<vector<int>>mem(10001,vector<int>(10001,-1));
int memorization(string X,string Y,int m,int n){
    if(m==0 || n==0)
    {
        return 0;
    }
    if(mem[m][n]!=-1)return mem[m][n];
    if(X[m-1]==Y[n-1])return mem[m][n]=1+memorization(X,Y,m-1,n-1);
    else return mem[m][n]=max(memorization(X,Y,m-1,n),memorization(X,Y,m,n-1));
}

vector<vector<int>>dp(10001,vector<int>(10001));
void dprog(string X,string Y,int m,int n){
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         if(i==0 || j==0)
    //         dp[i][j]=0;
    //     }
    // }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

int main(){
    string X,Y;
    cout<<"Enter the value for two strings"<<endl;
    cout<<"For string x: ";
    
    cin>>X;
    cout<<"For string y: ";
    cin>>Y;
    //For finding the length of the shortest common supersequence
    cout<<"Through recursive approach ->"<<(X.size()+Y.size())-lcs(X,Y,X.size(),Y.size())<<endl;       // Recursive approach

    cout<<"Through bottom up approach ->"<<(X.size()+Y.size())-memorization(X,Y,X.size(),Y.size())<<endl;

    dprog(X,Y,X.size(),Y.size());
    cout<<"Through top down approach ->"<<(X.size()+Y.size())-dp[X.size()][Y.size()]<<endl;
}