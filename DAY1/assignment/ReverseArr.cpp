#include<iostream>
using namespace std;

int* reverseArray(int *a,int n){
    int temp;
    //implementation of reverse array by swapping ith and (n-i-1)th values iteratively.
    for(int i=0; i<(n/2); i++){
        temp = a[n-i-1];
        a[n-i-1] = a[i];
        a[i] = temp;
    }

    return a;
}

int main(){

    int n,temp;
    cin>>n;  //taking array size as input

    int arr[n];
    for(int i=0; i<n; i++){ cin>>arr[i]; }  //taking array elements as input

    reverseArray(arr,n);
    for(int i=0; i<n; i++){ cout<<arr[i]<<" "; }   //priting the reversed array as output
    return 0;
}