#include<bits/stdc++.h>
#include "Person.h"
#include "Receiver.h"
using namespace std;


void Receiver::getdata()
{
    Person::getdata();
}
void Receiver::show()
{
    Person::showdata();
    cout<<"\nGiven Amount: "<<Rmoney<<endl;
}
void Receiver::zakat_cal()
{
    zc.getinfo();
    zc.calculation();
    //zc.show();
    Fund f;
    f.load();
    if(zc.show()){
    cout<<"\nSorry!..You are not eligible to get Zakat\n";
    Rmoney=0.0;
    }
    else
        {
            cout<<"\nHow many member have in your Family? :";
            cin>>fm;
            if(f.knowFund()<=fm*1000)
            {
                Rmoney=f.knowFund()*0.5;
                cout<<"\nYou will get "<<Rmoney<<" BDT as Zakat";
            }
            else
            {
                Rmoney=fm*1000-0.025*(zc.calculation());
                cout<<"\nYou will get "<<Rmoney<<" BDT as Zakat";
            }
        }
}
long double Receiver::get_bal()
{
    return Rmoney;
}


Receiver::~Receiver()
{
    //dtor
}
