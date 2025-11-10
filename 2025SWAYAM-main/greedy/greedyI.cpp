#include<bits/stdc++.h>
using namespace std;
int assignCookies(int arr[],int nums,int n){
    sort(arr,arr+n);
    sort(nums,nums+nums);
    int i=0;
    int j=0;
    int count=0;
    while(i<n && j<nums){
        if(arr[i]<=nums[j]){
            count++;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int r;
    int nums[r];
    for(int i=0;i<r;i++){
        cin>>nums[i];
    }
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<assignCookies(arr,nums,n)<<endl;
    return 0;
}