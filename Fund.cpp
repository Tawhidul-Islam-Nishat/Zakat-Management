#include<bits/stdc++.h>
#include "Fund.h"
using namespace std;


void Fund::operator += (long double B)
{
    Balance+=B;
    return;
}
void Fund::operator -= (long double B)
{
    Balance-=B;
    return;
}

void Fund::show()
{
    cout<<"\nCurrent Balance is "<<Balance<<endl;
}
void Fund::load()
{
    ifstream ifile("fund.bin",ios::binary);
    ifile.read(reinterpret_cast<char*>(&Balance),sizeof(long double));
    ifile.close();
}
void Fund::update()
{
     ofstream ofile("fund.bin",ios::binary);
    ofile.write(reinterpret_cast<char*>(&Balance),sizeof(long double));
    ofile.close();
}
long double Fund::knowFund()
{
    return Balance;
}
