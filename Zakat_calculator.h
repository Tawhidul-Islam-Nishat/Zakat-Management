#ifndef ZAKAT_CALCULATOR_H
#define ZAKAT_CALCULATOR_H
#include<bits/stdc++.h>
#include "Zakat_Calculator.h"

using namespace std;


class Zakat_Calculator
{
private:
    long double gold;
    long double silver;
    long double money;
    long double property;
    long double loans;

    public:
        Zakat_Calculator():gold(0.0),silver(0.0),money(0.0),property(0.0),loans(0.0){}
        void getinfo();
        long double calculation();
        int show();
};

#endif // ZAKAT_CALCULATOR_H
