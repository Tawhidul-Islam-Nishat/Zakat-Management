#ifndef ADMIN_H
#define ADMIN_H
#include<bits/stdc++.h>
#include "Admin.h"
#include "Fund.h"
using namespace std;

class Admin
{
protected:
    char username[20];
    char password[20];
public:
        Admin(){}
        bool login();
        void ShowFund();
        void ShowDonorlist();
        void ShowReceiverlist();
        void ShowProviderlist();

};

#endif // ADMIN_H
