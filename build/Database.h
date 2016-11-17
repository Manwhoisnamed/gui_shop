//maxwell Sanders 1001069652
//The database will be used to hold customer info and in the future SA info

#include "Customer.h"
#include "Order.h"
#include "Storage.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

 #ifndef __DATABASE_H
 #define __DATABASE_H 2016
class Database{
    private:
	vector<Customer> customers;
	vector<Order> orders;
	int bossPin;
	int PMPin;

    public:
	Database(){};

	//pin setters and getters
	int getPMPin();
	int getBossPin();
	
	//customer based things
	Customer loadCustomer(int pin);
	void addCustomer(Customer customer);
	bool checkPin(int pin);
	Customer loadCustomerPin(int pin);
	int getCustomerSize();

        //order based things
	void addOrder(Order order);
	
	//persistence stuff
	void saveData();
	void loadData(Storage storage);
};
#endif
