#include<bits/stdc++.h>
#include "Person.h"

using namespace std;

void Person:: getdata()
{
    cout<<"\nEnter Your Name: ";
    cin>>name;
    cout<<"Phone Number: ";
    cin>>pnum;
    cout<<"Address: ";
    cin>>address;
}
void Person:: showdata()
{
    cout<<"\nName: "<<name<<"\nPhone Number: "<<pnum<<"\nAddress: "<<address;
}
