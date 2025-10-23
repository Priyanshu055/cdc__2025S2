#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[]){
    int* start=arr;
    int* end=arr+4; // assuming size is 5
    while(start<end){
        swap(*start,*end);
        start++;
        end--;
    }
}
int main(){
   int arr[5]={1,2,3,4,5};
   reverse(arr);
   for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
   }
   return 0;
}