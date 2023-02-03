//One pointer technique used to find string after all deletions
//Space is O(1), runtime is O(n)  [n is the length of the longer input string]

/*Explanation: 
Loop through the characters if you see "#" delete the char before and current char (#)
Compare both strings to see if they are equal
*/

#include<iostream>
#include<vector>
#include <bits/stdc++.h>



bool BackSpaceStringCompare(std::string in1, std::string in2){

for(int i=0;i<in1.length();i++){
if(i==0 && in1[0]=='#') 
  {in1.erase(0, 1);
  i--;
  }

if(i>0 && in1[i]=='#'){
in1.erase(i, 1);
in1.erase(i-1, 1);
i=i-2;
}
}

for(int i=0;i<in2.length();i++){
if(i==0 && in2[0]=='#') 
  {in2.erase(0, 1);
  i--;
  }

if(i>0 && in2[i]=='#'){
in2.erase(i, 1);
in2.erase(i-1, 1);
i=i-2;
}
}
return(in1==in2);
}


int main(){

std::string test1[2]={"abcde","abcde"};
std::string test2[2]={"Uber Career Prep","u#Uber Careee#r Prep"};
std::string test3[2]={"abcdef###xyz","abcw#xyz"};
std::string test4[2]={"abcdef###xyz","abcdefxyz###"};

std::cout << std::boolalpha;
std::cout<<"Input strings 1: \"abcde\", \"abcde\" "<<std::endl<<"Output: "<<BackSpaceStringCompare(test1[0],test1[1])<<std::endl<<std::endl;
std::cout<<"Input strings 2: \"Uber Career Prep\", \"u#Uber Careee#r Prep\" "<<std::endl<<"Output: "<<BackSpaceStringCompare(test2[0],test2[1])<<std::endl<<std::endl;
std::cout<<"Input strings 3: \"abcdef###xyz\", \"abcw#xyz\" "<<std::endl<<"Output: "<<BackSpaceStringCompare(test3[0],test3[1])<<std::endl<<std::endl;
std::cout<<"Input strings 4: \"abcdef###xyz\",\"abcdefxyz###\" "<<std::endl<<"Output: "<<BackSpaceStringCompare(test4[0],test4[1])<<std::endl<<std::endl;

}

//Time completed in: 35 minutes