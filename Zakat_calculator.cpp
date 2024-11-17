#include<bits/stdc++.h>
#include "Zakat_Calculator.h"
using namespace std;


void Zakat_Calculator::getinfo()
{
    long double k18,k22,k24;
    int c;
    cout<<"___________Input all properties info that you are belong for minimum 1 year________\nGold: \n";
    cout<<"18 carat: \n";
    cout<<"Press 1 to input in tola(vori)\n press 2 to input in gram: ";
    cin>>c;
    if(c==1)
    {
        cout<<"Enter the amount tola(vori): ";
       cin>>k18;
       k18*=11.7;
    }
    else
    {
        cout<<"Enter the amount in gram: ";
        cin>>k18;
    }
    cout<<"\n22 carat: \n";
    cout<<"Press 1 to input in tola(vori)\n press 2 to input in gram: ";
    cin>>c;
    if(c==1)
    {
        cout<<"Enter the amount tola(vori): ";
       cin>>k22;
       k22*=11.7;
    }
    else
    {
        cout<<"Enter the amount gram: ";
        cin>>k22;
    }
    cout<<"24 carat: \n";
    cout<<"Press 1 to input in tola(vori)\n press 2 to input in gram: ";
    cin>>c;
    if(c==1)
    {
        cout<<"Enter the amount tola(vori): ";
       cin>>k24;
       k24*=11.7;
    }
    else
    {
        cout<<"Enter the amount gram: ";
        cin>>k24;
    }
    gold=4870.12*k18+5961.02*k22+6493.49*k24;
    cout<<"\nSilver: ";
    cout<<"18 carat: \n";
    cout<<"Press 1 to input in tola(vori)\n press 2 to input in gram: ";
    cin>>c;
    if(c==1)
    {
        cout<<"Enter the amount tola(vori): ";
       cin>>k18;
       k18*=11.7;
    }
    else
    {
        cout<<"Enter the amount gram: ";
        cin>>k18;
    }
    cout<<"\n22 carat: \n";
    cout<<"Press 1 to input in tola(vori)\n press 2 to input in gram: ";
    cin>>c;
    if(c==1)
    {
        cout<<"Enter the amount tola(vori): ";
       cin>>k22;
       k22*=11.7;
    }
    else
    {
        cout<<"Enter the amount gram: ";
        cin>>k22;
    }
    cout<<"24 carat: \n";
    cout<<"Press 1 to input in tola(vori)\n press 2 to input in gram: ";
    cin>>c;
    if(c==1)
    {
        cout<<"Enter the amount tola(vori): ";
       cin>>k24;
       k24*=11.7;
    }
    else
    {
        cout<<"Enter the amount: ";
        cin>>k24;
    }
    silver=55.14*k18+67.39*k22+73.52*k24;
    cout<<"\n Cash in your hand: ";
    cin>>k18;
    cout<<"\nCash in Bank or lend others: ";
    cin>>k22;
    money=k18+k22;
    cout<<"\nOthers properties approximate value in BDT: ";
    cin>>property;
    cout<<"\nLiabilitie or loan (in BDT): ";
    cin>>loans;
}
long double Zakat_Calculator::calculation()
{
    long double total=gold+silver+money+property-loans;
    return total;
}
int Zakat_Calculator::show()
{
    if(calculation()<73500)
    {
        cout<<"\nZakat is not obligatory on you";
        return 0;
    }
    cout<<"\nYour Zakat is "<<calculation()*0.025<<" BDT";
    return 1;
}
