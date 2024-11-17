#include<bits/stdc++.h>
#include "Person.h"
#include "Provider.h"
using namespace std;


void Provider::getdata()
{
    Person::getdata();
    cout<<"\nTo How many People do you want to provide Zakat?";
    cin>>people;
}
void Provider::show()
{
    Person::showdata();
    cout<<"\nProvided Amount: "<<Pmoney<<endl;
    cout<<"Provided to "<<people<<" peoples\n";
}
void Provider::zakat_cal()
{
    Fund f;
    f.load();
   map<string,long double>product;
   char c;
   do
   {
       string s;
       long double up;
       cout<<"\nEnter Product name: ";
       cin>>s;
       cout<<"\nEnter Product Unit price:";
       cin>>up;
       product[s]=up;
       cout<<"\nWant to add another product?(y/n):";
       cin>>c;
   }
   while(c=='y');
   for(auto i: product)
   {
       Pmoney+=(i.second)*people;
   }
   if(Pmoney>f.knowFund())
   {
       int n;
       n=f.knowFund()/people;
       cout<<"\nWe have insufficient Balance to provide you for "<<people<<"peoples.\nInstead of that You can provide the Zakat to "<<n<<"Peoples by our provided Zakat\n";
       Pmoney=f.knowFund();
   }
}
long double Provider::get_bal()
{
    return Pmoney;
}


Provider::~Provider()
{
    //dtor
}
