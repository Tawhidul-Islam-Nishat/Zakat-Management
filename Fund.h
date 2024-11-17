#ifndef FUND_H
#define FUND_H
#include<bits/stdc++.h>
#include "Fund.h"
//#include "Donor.h"
using namespace std;


class Fund
{
private:
    long double Balance;
public:
    Fund():Balance(0.0){}
    void operator += (long double);
    void operator -= (long double);
    void show();
    void load();
    void update();
    long double knowFund();
    friend class DonorManager;
    friend class ReceiverManager;
    friend class ProviderManager;
};


#endif // FUND_H
