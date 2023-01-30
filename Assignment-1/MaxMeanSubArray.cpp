//Fixed-size sliding window technique
//Space is O(1), runtime is O(n)

#include<iostream>
#include<vector>
#include <bits/stdc++.h>


double MaxMeanSubArray(std::vector<int> arr,int k){

if(k<=0 || k>arr.size()) throw std::invalid_argument("Size of subarry out of range!");


int sum=0;
arr.insert(arr.begin(), 0);

for(int i=0;i<arr.size();i++){
  arr[i]=arr[i]+sum;
  sum=arr[i];
}

int total;


for(int i=0;i<arr.size()-k;i++){

if(i==0) total=arr[i+k]-arr[i];
if((arr[i+k]-arr[i])>total) total=arr[i+k]-arr[i];

}
double ans=total/(double)k;

return (ans);

}

int main(){

std::vector<int> test1={4,5,-3,2,6,1};

//0,4,9,6,8,14,15
std::vector<int> test2={1,1,1,1,-1,-1,2,-1,-1,6};

std::cout<<"Testing [4,5,-3,2,6,1] with K=2:  "<<MaxMeanSubArray(test1,2)<<std::endl;
std::cout<<"Testing [4,5,-3,2,6,1] with K=3:  "<<MaxMeanSubArray(test1,3)<<std::endl;

std::cout<<"Testing [1,1,1,1,-1,-1,2,-1,-1,6] with K=3:  "<<MaxMeanSubArray(test2,3)<<std::endl;
std::cout<<"Testing [1,1,1,1,-1,-1,2,-1,-1,6] with K=4:  "<<MaxMeanSubArray(test2,4)<<std::endl;

return 0;
}

//Time completed in: 40 minutes