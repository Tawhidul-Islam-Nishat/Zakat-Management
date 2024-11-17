#include<bits/stdc++.h>
#include "Zakat_Calculator.h"
#include "Donor.h"
#include "Fund.h"
#include "Receiver.h"
#include "Provider.h"
#include "Admin.h"
using namespace std;
int main()
{
    cout<<"----------------Zakat Management-------------------\n\n";
L:
    cout<<"\n------------Login----------------\n";
    int choice;

    cout<<"\n1.Admin";
    cout<<"\n2.Donor";
    cout<<"\n3.Receiver";
    cout<<"\n4.Provider\n";
    cout<<"\n0.Exit\n";
    cin>>choice;
    system("cls");
    if(choice==1)
    {
        Admin a;
B:

        cout<<"\n------Admin Login--------\n";
        if(a.login())
        {
C:
            int n;
            cout<<"\n1.Show Lists";
            cout<<"\n2.Remove from list";
            cout<<"\n3.Go back\n";
            cin>>n;
            system("cls");
            if(n==1)
            {
A:
                int button;
                cout<<"\n1.Show fund";
                    cout<<"\n2.Show Donors List";
                cout<<"\n3.Show Receivers List";
                cout<<"\n4.Show Providers List";
                cout<<"\n5.Go back\n";
                cin>>button;
                system("cls");
                if(button==1)
                {
                    a.ShowFund();\
                    goto A;
                }
                else if(button==2){
                    a.ShowDonorlist();
                    goto A;
                }
                else if(button==3){
                    a.ShowReceiverlist();
                    goto A;
                }
                else if(button==4){
                    a.ShowProviderlist();
                    goto A;
                }
                else if(button==5)
                    goto C;
                else
                    goto A;
            }
            else if(n==2)
            {
                D:
                int c;
                cout<<"\n1.Remove a Donor";
                cout<<"\n2.Remove a Receiver";
                cout<<"\n3.Remove a Provider";
                cout<<"\n4.Go Back\n";
                cin>>c;
                system("cls");
                if(c==1)
                {
                    DonorManager d;
                    d.load();
                    d.remove_a_Donor();
                    d.update();
                    goto D;
                }
                else if(c==2)
                {
                    ReceiverManager r;
                    r.load();
                    r.remove_a_Receiver();
                    r.update();
                    goto D;
                }
                else if(c==3)
                {
                    ProviderManager p;
                    p.load();
                    p.remove_a_Provider();
                    p.update();
                    goto D;
                }
                else if(c==4)
                    goto C;
                else
                    goto D;
            }
            else if(n==3)
                goto L;
        }

        else
        {
            cout<<"\nYou are not an Admin\n";
            goto L;
        }

    }
    else if(choice==2)
    {
        DonorManager D;
        D.load();
        D.add_Donor();
        D.update();
        goto L;
    }
    else if(choice==3)
    {
        ReceiverManager R;
        R.load();
        R.add_receiver();
        R.update();
        goto L;
    }
    else if(choice==4)
    {
        ProviderManager P;
        P.load();
        P.add_Provider();
        P.update();
        goto L;
    }
    else if(choice==0)
        return 0;
    else
        goto L;



}
