#ifndef DONOR_H
#define DONOR_H
#include<bits/stdc++.h>
#include "Person.h"
#include "Zakat_Calculator.h"
#include "Fund.h"
using namespace std;

class Donor: public Person
{
private:
    Zakat_Calculator zc;
    long double cal_zakat;
public:
    Donor(){}
    void getdata();
    void show();
    void zakat_cal();
    long double get_bal();


};
class DonorManager
{
    vector<Donor>donor;
public:
    DonorManager() {}
    void load()
    {

        donor.clear();
        string filename = "donors.bin";
        ifstream ifile(filename,ios::binary);
        Donor tmp;
        while(ifile.read(reinterpret_cast<char*>(&tmp),sizeof(Donor)))
        {
            donor.push_back(tmp);
        }
        ifile.close();
    }
    void update()
    {
        string filename = "donors.bin";
        ofstream ofile(filename,ios::binary);
        for(auto tmp:donor)
        {
            ofile.write(reinterpret_cast<char*>(&tmp),sizeof(Donor));
        }
        ofile.close();
    }
    void show()
    {
        cout<<"\n-----------Donors List------------\n";
        int i = 1;
        for(auto tmp:donor)
        {
            cout<<i++<<" : ";
            tmp.show();
        }
    }
    void remove_a_Donor()
    {
s:
        show();
        cout<<"\nwhich one to remove?\n0 to exit\n";
        int button;
        cin>>button;

        if(button==0)
        {
            update();
            return ;
        }
        button--;
        if(button>=0 && button<donor.size())
        {
            donor.erase(donor.begin()+button);
            cout<<"success deletion\n";

        }
        goto s;
    }
    void add_Donor()
    {
s:
        cout<<"\nPress 0 to exit \n 1 to add a new Donor\n";
        int button;
        cin>>button;
        if(button==0)
        {
            update();
            return;
        }
        else if(button ==1)
        {
            Donor tmp;
            Fund f;
            f.load();
            tmp.getdata();
            tmp.zakat_cal();
            f.Balance+=tmp.get_bal();
            f.update();
            donor.push_back(tmp);
        }
        goto s;
    }
};

#endif // DONOR_H
