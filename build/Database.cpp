//maxwell Sanders 1001069652
//this database holds customer and order info, and in the future SA info

#include "Database.h"

void Database::changePMPin(int pin){
    Database::PMPin = pin;
}

void Database::addOrder(Order order){
    Database::orders.push_back(order);
}

int Database::getCustomerSize(){
    return customers.size();
}

int Database::getBossPin(){
    return bossPin;
}

int Database::getPMPin(){
    return PMPin;
}

Customer Database::loadCustomer(int i){
	return Database::customers.at(i);
}

Customer Database::loadCustomerPin(int pin){
    int i = 0;
    for(i = 0; i < Database::customers.size(); i ++){
	if(customers.at(i).getPin() == pin){
	    return customers.at(i);
	}
    }
}

void Database::addCustomer(Customer customer){
	Database::customers.push_back(customer);
}

bool Database::checkPin(int pin){
    int i = 0;
    for(i = 0; i < Database::customers.size(); i ++){
	if(customers.at(i).getPin() == pin){
	    return true;
	}
    }
    return false;
}

void Database::saveData(){
    int i = 0;
    ofstream myfile("Database.txt");
    myfile << bossPin << " " << PMPin << "\n";
    //stores the customers
    myfile << "Customers================\n";
    for(i = 0; i < Database::customers.size(); i ++){
	myfile << customers.at(i).getName() << "\n";
	myfile << customers.at(i).getPin() << "\n";
	myfile << customers.at(i).getAddress() << "\n";	
    }
    myfile << "-1\n";
    myfile << "Orders===================\n";
    for(i = 0; i < Database::orders.size(); i++){
	myfile << orders.at(i).getCustomerPin() << " " << orders.at(i).getModelNumber() << " " << orders.at(i).getQuantity() << "\n";
    }
    myfile << "-1\n";
    myfile.close();
}

void Database::loadData(Storage storage){
    ifstream myfile("Database.txt");
    string line, name, address;
    int pin, MN, quantity;
  
    //gets the boss and pm pin
    getline(myfile, line);
    istringstream pins(line);
    pins >> bossPin >> PMPin;

    //gets the customers
    getline(myfile, line);
    while(true){
	getline(myfile,name);
	if(name == "-1"){
	    break;
	}
	getline(myfile, line);
	istringstream custLine(line);
	custLine >> pin;
	getline(myfile, address);
	Customer customer(name, pin, address);
	Database::customers.push_back(customer);
    }
    getline(myfile, line);
    while(true){
	getline(myfile, line);
        if(line == "-1"){
	    break;
	}
	istringstream ordLine(line);
	ordLine >> pin >> MN >> quantity;
	Order order;
	order.setCustomerPin(pin);
	order.setModelNumber(MN);
	order.setQuantity(quantity);
	order.calculatePrice(storage);
	Database::orders.push_back(order);
    }
    myfile.close();
}
