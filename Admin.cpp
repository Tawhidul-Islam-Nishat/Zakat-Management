#include<bits/stdc++.h>
#include "Admin.h"
#include "Donor.h"
#include "Receiver.h"
#include "Provider.h"
using namespace std;


bool Admin::login()
{
L:
    {
    cout<<"\nEnter Username: ";
    cin>>username;
    cout<<"Enter Password: ";
    cin>>password;
    }
    if(!strcmp(username,"Admin")&&!strcmp(password,"password"))
    {
        cout<<"\n-----Login Successful---\n";
        return true;
    }
    else
    {
        cout<<"\nLogin failed!.";
        char c;
        cout<<"\nWant to try again?(y/n):";
        cin>>c;
        if(c=='y')
        goto L;
        else
            return false;
    }

}

void Admin::ShowFund()
{
    Fund f;
    f.load();
    f.show();
    f.update();
}
void Admin::ShowDonorlist()
{
    DonorManager d;
    d.load();
    d.show();
    d.update();
}
void Admin::ShowReceiverlist()
{
    ReceiverManager r;
    r.load();
    r.show();
    r.update();
}
void Admin::ShowProviderlist()
{
    ProviderManager p;
    p.load();
    p.show();
    p.update();
}

