//Forward-Backward two-pointer technique
//Space is O(1), runtime is O(n)

#include<iostream>
#include<vector>
#include <bits/stdc++.h>

bool isVowel(char c){
if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;

return false;
}

std::string ReverseVowelOrder(std::string input){
int left=0;
int right=input.length()-1;

while(right>left){
if(!isVowel(input[left]))left++;
if(!isVowel(input[right]))right--;

if(isVowel(input[left]) && isVowel(input[right]) ){
  char temp=input[left];
  input[left]=input[right];
  input[right]=temp;
  left++;
  right--;

}
}

return input;
}


int main(){

std::string test1="Uber Career Prep";
std::string test2="xyz";
std::string test3="flamingo";
std::string test4="aeiou";

std::cout<<"Testing the string \"Uber Career Prep\":  "<<ReverseVowelOrder(test1)<<std::endl;
std::cout<<"Testing the string \"xyz\":  "<<ReverseVowelOrder(test2)<<std::endl;
std::cout<<"Testing the string \"flamingo\":  "<<ReverseVowelOrder(test3)<<std::endl;
std::cout<<"Testing the string \"aeiou\":  "<<ReverseVowelOrder(test4)<<std::endl;
}

//Time completed in: 20 minutes