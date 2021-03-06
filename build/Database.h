//maxwell Sanders 1001069652
//The database will be used to hold customer info and in the future SA info

#include "Customer.h"
#include "Order.h"
#include "Storage.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "salesman.h"

 #ifndef __DATABASE_H
 #define __DATABASE_H 2016
class Database{
    private:
	vector<Customer> customers;
	vector<Order> orders;
	vector<salesman> associates;
	int bossPin;
	int PMPin;

    public:
	Database(){};

	//pin setters and getters
	int getPMPin();
	int getBossPin();
	void changePMPin(int pin);
	void changeBossPin(int pin);
	
	//customer based things
	Customer loadCustomer(int pin);
	void addCustomer(Customer customer);
	bool checkPin(int pin);
	Customer loadCustomerPin(int pin);
	int loadCustomerPinIndex(int pin);
	int getCustomerSize();

	//Salesman based things
	salesman loadAssociate(int pin);
	void addAssociate(salesman associate);
	bool checkPinSales(int pin);
	salesman loadAssociatePin(int pin);
	int getAssociateSize();

        //order based things
	void addOrder(Order order);
	
	//persistence stuff
	void saveData();
	void loadData(Storage storage);
};
#endif
