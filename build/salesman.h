//maxwell Sanders
//This file is the header for salesmen

#include <string>

using namespace std;

#ifndef __salesman_H
#define __salesman_H 2016
class salesman{
    double wage;
    string name;
    int pin;
	public:
    salesman(){};
    salesman(double iwage, string iname, int ipin):
	wage(iwage),
	name(iname),
	pin(ipin){};
    int getWage();
    string getName();
    int getPin();
    void setWage(double wage);
    void setName(string name);
    void setPin(int pin);
};
#endif
