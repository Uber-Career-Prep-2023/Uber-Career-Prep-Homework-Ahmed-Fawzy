//Hash the elements technique
//Space is O(n), runtime is O(n^2) <-- O(n) if all values are unique, O(n^2) if all values are the same...

/*Explanation: 
- Update array so each index represents the sum of the element and all elements to the left of it o(n)
- Put all the array elements in a map. Each key maps to a vector that contains the indices of all elements that are the same as the key. o(n)
- Loop through the array if element = 0 --> answer++; for the vector (resulting from mapping array element) calculate nCr (r=2) and update counter o(n^2)
Note C++ doesn't have nCr built-in functions, so I calculated it differently ^
*/

#include<iostream>
#include<vector>
#include <bits/stdc++.h>



int ZeroSumSubArray(std::vector<int> arr){

int sum=0;
for(int i=0;i<arr.size();i++)
{
arr[i]=arr[i]+sum;
sum=arr[i];
}

std::map<int,std::vector<int>> m;
for(int i=0;i<arr.size();i++){
  m[arr[i]].push_back(i);
}

int ans=0;
for(int i=0;i<arr.size();i++){
  if(arr[i]==0) ans++;

  for(int k=0;k<m[arr[i]].size();k++) 
      {if(m[arr[i]][k]<i)ans++;}
      
}

return ans;
}


int main(){

std::vector<int> test1={4,5,2,-1,-3,-3,4,6,-7};
std::vector<int> test2={1,8,73,11,9};
std::vector<int> test3={8,-5,0,-2,3,-4};
std::vector<int> test4={1,-1,1,-1,1,-1};//ans = 9

std::cout<<"Testing the array [4,5,2,-1,-3,-3,4,6,-7]:  "<<ZeroSumSubArray(test1)<<std::endl;
std::cout<<"Testing the array [1,8,73,11,9]:  "<<ZeroSumSubArray(test2)<<std::endl;
std::cout<<"Testing the array [8,-5,0,-2,3,-4]:  "<<ZeroSumSubArray(test3)<<std::endl;
std::cout<<"Testing the array [1,-1,1,-1,1,-1]:  "<<ZeroSumSubArray(test4)<<std::endl;

}

//Time completed in: 30 minutes