#include<bits/stdc++.h>
#include "Person.h"
#include "Donor.h"

using namespace std;

void Donor::getdata()
{
    Person::getdata();
}

void Donor::show()
{
    Person::showdata();
    cout<<"\nDonated Amount: "<<cal_zakat<<endl;
}
void Donor::zakat_cal()
{
    zc.getinfo();
    zc.calculation();
    //zc.show();
    if(zc.show()){
    cout<<"\nHow much % of your total Zakat do you want to donate us? \n Input in 1-100:";
    int n;
    cin>>n;
    cout<<"\n You have donated "<<(n/100.0)*zc.calculation()*0.025<<" BDT. Thank You!";
    cal_zakat=(n/100.0)*zc.calculation()*0.025;
    }
    else
        cal_zakat=0.0;
}
long double Donor::get_bal()
{
    return cal_zakat;
}
