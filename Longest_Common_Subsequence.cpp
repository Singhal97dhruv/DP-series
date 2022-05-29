#include<iostream>
#include<string>

using namespace std;

int lcs(string X,string Y,int m,int n){
    if(m==0 || n==0)return 0;
    if(X[m-1]==Y[m-1]){
        return 1+lcs(X,Y,m-1,n-1);
    }
    else{
        return max(lcs(X,Y,m-1,n),lcs(X,Y,m,n-1));
    }
}



int main(){
    string X,Y;
    cout<<"Enter the value for two strings"<<endl;
    cout<<"For string x: ";
    
    cin>>X;
    cout<<"For string y: ";
    cin>>Y;
    //For finding the length of the longest common subsequence
    cout<<lcs(X,Y,X.size(),Y.size());       // Recursive approach




}