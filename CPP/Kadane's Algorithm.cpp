#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    int till=arr[0];
    int curr = arr[0];
    for(int i=1;i<n;i++){
        curr = max(arr[i],curr+arr[i]);
        till = max(till,curr);
    }
    return till;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--) 
    {
        cin>>n; 
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout << maxSubarraySum(a, n) << endl;
    }
}