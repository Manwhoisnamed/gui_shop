
//maxwell Sanders 1001069652
//this is the customer class it holds customer credentials

#include <string>
#include "RoboModel.h"
#include "Storage.h"

using namespace std;

#ifndef __ORDER_H
#define __ORDER_H 2016
class Order{
    private:
	int customerpin;
	int ModelNumber;
	int associatepin;
	int quantity;
	double price;
    public:
	Order(){};

	//getters
	int getCustomerPin();
	int getAssociatePin();
	int getQuantity();
	int getModelNumber();
	double getPrice();
	
	//setters
	void setCustomerPin(int pin);
	void setAssociatePin(int pin);
	void setQuantity(int num);
	void setModelNumber(int MN);
	void calculatePrice(Storage storage);
};
#endif
