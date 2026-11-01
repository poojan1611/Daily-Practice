#include<iostream>
#include<list>
using namespace std;

int main() {
    
    list<int> l1 = {1, 2, 3, 4};
    auto it  = l1.begin();
    cout<<*it<<endl;

    for (int x: l1) cout<<x<<" -> ";
    cout<<"Null"<<endl;

    l1.push_back(5);
    l1.push_back(6);
    l1.push_front(3);
    for (int x: l1) cout<<x<<" -> ";
    cout<<"Null"<<endl;

    l1.pop_front();
    l1.pop_back();
    for (int x: l1) cout<<x<<" -> ";
    cout<<"Null"<<endl;

    l1.reverse();
    

    return 0;
    
}