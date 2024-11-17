#ifndef RECEIVER_H
#define RECEIVER_H
#include<bits/stdc++.h>
#include "Person.h"
#include "Receiver.h"
#include "Zakat_Calculator.h"
#include "Fund.h"
using namespace std;


class Receiver: public Person
{
    private:
        Zakat_Calculator zc;
        int fm;
        long double Rmoney;
    public:
        Receiver():Rmoney(0.0){}
        void getdata();
        void show();
        void zakat_cal();
        long double get_bal();
        virtual ~Receiver();


};

class ReceiverManager
{
    vector<Receiver> receiver;
public:
    ReceiverManager() {}
    void load()
    {
        receiver.clear();
        string filename = "receivers.bin";
        ifstream ifile(filename,ios::binary);
        Receiver tmp;
        while(ifile.read(reinterpret_cast<char*>(&tmp),sizeof(Receiver)))
        {
            receiver.push_back(tmp);
        }
        ifile.close();
    }
    void update()
    {
        string filename = "receivers.bin";
        ofstream ofile(filename,ios::binary);
        for(auto tmp:receiver)
        {
            ofile.write(reinterpret_cast<char*>(&tmp),sizeof(Receiver));
        }
        ofile.close();
    }
    void show()
    {
        cout<<"\n-----------Receivers List------------\n";
        int i = 1;
        for(auto tmp:receiver)
        {
            cout<<i++<<" : ";
            tmp.show();
        }
    }
    void remove_a_Receiver()
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
        if(button>=0 && button<receiver.size())
        {
            receiver.erase(receiver.begin()+button);
            cout<<"success deletion\n";

        }
        goto s;
    }
    void add_receiver()
    {
s:
        cout<<"\nPress 0 to exit \n 1 to add a new Receiver\n";
        int button;
        cin>>button;
        if(button==0)
        {
            update();
            return;
        }
        else if(button ==1)
        {
            Receiver tmp;
            Fund f;
            f.load();
            tmp.getdata();
            tmp.zakat_cal();
            f.Balance-=tmp.get_bal();
            f.update();
            receiver.push_back(tmp);
        }
        goto s;
    }
};

#endif // RECEIVER_H
