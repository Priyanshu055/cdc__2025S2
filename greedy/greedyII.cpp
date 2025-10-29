#include<bits/stdc++.h>
using namespace std;
int ArrayPartition(int arr[],int n){
    sort(arr,arr+n);
    int sum=0;
    for(int i=0;i<n;i+=2){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<ArrayPartition(arr,n)<<endl;
    return 0;
}