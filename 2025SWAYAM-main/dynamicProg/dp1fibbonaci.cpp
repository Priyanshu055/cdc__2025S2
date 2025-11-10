#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    if(n==0 || n==1){
        cout<<n;
        
    }
    int prev=0;
    int prev2=1;
    int c;
    for(int i=2;i<=n;i++){
        c=prev+prev2;
        prev=prev2;
        prev2=c;
    }
    return prev2;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}