#ifndef PERSON_H
#define PERSON_H
#include<bits/stdc++.h>
#include "Person.h"

using namespace std;


class Person
{
    private:
        char name[50];
        char pnum[15];
        char address[100];
    public:
        Person(){}
        void getdata();
        virtual void showdata();

};

#endif // PERSON_H
