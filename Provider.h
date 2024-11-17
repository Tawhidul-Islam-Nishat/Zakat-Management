#ifndef PROVIDER_H
#define PROVIDER_H
#include<bits/stdc++.h>
#include "Person.h"
#include "Provider.h"
#include "Fund.h"
using namespace std;


class Provider:public Person
{
private:
    long double Pmoney;
    int people;
    public:
        Provider():Pmoney(0.0){}
        void getdata();
        void show();
        void zakat_cal();
        long double get_bal();
        virtual ~Provider();
};
class ProviderManager
{
    vector<Provider> provider;
public:
    ProviderManager() {}
    void load()
    {
        provider.clear();
        string filename = "providers.bin";
        ifstream ifile(filename,ios::binary);
        Provider tmp;
        while(ifile.read(reinterpret_cast<char*>(&tmp),sizeof(Provider)))
        {
            provider.push_back(tmp);
        }
        ifile.close();
    }
    void update()
    {
        string filename = "providers.bin";
        ofstream ofile(filename,ios::binary);
        for(auto tmp:provider)
        {
            ofile.write(reinterpret_cast<char*>(&tmp),sizeof(Provider));
        }
        ofile.close();
    }
    void show()
    {
        cout<<"\n-----------Providers List------------\n";
        int i = 1;
        for(auto tmp:provider)
        {
            cout<<i++<<" : ";
            tmp.show();
        }
    }
    void remove_a_Provider()
    {
s:
        show();
        cout<<"\nWhich one to remove?\n0 to exit\n";
        int button;
        cin>>button;

        if(button==0)
        {
            update();
            return ;
        }
        button--;
        if(button>=0 && button<provider.size())
        {
            provider.erase(provider.begin()+button);
            cout<<"success deletion\n";

        }
        goto s;
    }
    void add_Provider()
    {
s:
        cout<<"\nPress 0 to exit \n 1 to add a new Provider\n";
        int button;
        cin>>button;
        if(button==0)
        {
            update();
            return;
        }
        else if(button ==1)
        {
            Provider tmp;
            Fund f;
            f.load();
            tmp.getdata();
            tmp.zakat_cal();
            f.Balance-=tmp.get_bal();
            f.update();
            provider.push_back(tmp);
        }
        goto s;
    }
};


#endif // PROVIDER_H
