//maxwell Sanders 1001069652
//this is the customer class it holds customer credentials

#include <string>

using namespace std;

#ifndef __CUSTOMER_H
#define __CUSTOMER_H 2016
class Customer{
    private:
	string name;
	int pin;
	string address;
    public:
	Customer(string iname, int ipin, string iaddress): name(iname), pin(ipin), address(iaddress){}
	Customer(){};

	//getters
	string getName();
	int getPin();
	string getAddress();

	//setters
	string changeName(string newName);
	string changeAddress(string newAddress);
};
#endif
