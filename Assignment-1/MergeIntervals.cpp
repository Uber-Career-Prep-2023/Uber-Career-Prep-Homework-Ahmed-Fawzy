//sort then solve technique
//Space is O(1), runtime is O(nlgn) 


#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include<algorithm>

struct interval{
    int start,end;
};

void print(std::vector<interval> list)//prints list
{   std::cout<<"[";
    for(int i=0;i<list.size();i++)
        {std::cout<<"("<<list[i].start<<", "<<list[i].end<<")";
        if(i!=list.size()-1)std::cout<<", ";
        }
    std::cout<<"] \n \n";
}

bool compareInterval(const interval & e1, const interval & e2){
return e1.start<e2.start;
}


std::vector<interval> MergeIntervals(std::vector<interval> list){

if(list.size()<=1)return list;

std::sort(list.begin(), list.end(), compareInterval);

for(int i=1;i<list.size();i++){
if(list[i].start<=list[i-1].end){
int max;

if(list[i].end>list[i-1].end) max=list[i].end;
else max=list[i-1].end;

list[i-1].end=max;
list.erase(list.begin() + i);
i--;

}
}

return list;
}


int main(){

std::vector<interval> test1={{2, 3}, {4, 8}, {1, 2}, {5, 7}, {9, 12}};
std::vector<interval> test2={{5, 8}, {6, 10}, {2, 4}, {3, 6}};
std::vector<interval> test3={{10, 12}, {5, 6}, {7, 9}, {1, 3}};

std::cout<<"Input 1: [(2, 3), (4, 8), (1, 2), (5, 7), (9, 12)]"<<std::endl<<"Output 1: ";
print(MergeIntervals(test1));

std::cout<<"Input 2: [(5, 8), (6, 10), (2, 4), (3, 6)]"<<std::endl<<"Output 2: ";
print(MergeIntervals(test2));

std::cout<<"Input 3: [(10, 12), (5, 6), (7, 9), (1, 3)]"<<std::endl<<"Output 3: ";
print(MergeIntervals(test3));

}

//Time completed in: 50 minutes (some time wasted figuring out how to sort based on a specific coloum)