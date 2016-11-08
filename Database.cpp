//maxwell Sanders 1001069652
//this database holds customer and order info, and in the future SA info

#include "Database.h"

void Database::printOrders(Storage storage){
    int i = 0, size = Database::orders.size();
    cout << "\nViewing all the orders\n";
    cout << "======================\n";
    for(i = 0; i < size; i ++){
	cout << i + 1 << " - Name: " << loadCustomerPin(Database::orders.at(i).getCustomerPin()).getName() << "\n";
	cout << "    Pin: " << Database::orders.at(i).getCustomerPin() << "\n";
	cout << "    Robot Model: " << storage.getRoboModelMN(Database::orders.at(i).getModelNumber()).getName() << "\n";
	cout << "    Robot Model Number: " << Database::orders.at(i).getModelNumber() << "\n";
	cout << "    Quantity: " << Database::orders.at(i).getQuantity() << "\n"; 
	cout << "    SubTotal: " << storage.getRoboModelMN(Database::orders.at(i).getModelNumber()).getPrice() << " USD\n";
	cout << "    Total(Subtotal+tax+shipping): " << Database::orders.at(i).getPrice() << " USD\n";
	cout << "\n";
    }
    cout << "\n";
}

void Database::printMyOrders(int pin, Storage storage){
    int i = 0, size = Database::orders.size();
    cout << "\nViewing all the orders\n";
    cout << "======================\n";
    for(i = 0; i < size; i ++){
	if(Database::orders.at(i).getCustomerPin() == pin){
	    cout << i + 1 << " - Name: " << loadCustomerPin(pin).getName() << "\n";
	    cout << "    Pin: " << pin << "\n";
	    cout << "    Robot Model: " << storage.getRoboModelMN(Database::orders.at(i).getModelNumber()).getName() << "\n";
	    cout << "    Robot Model Number: " << Database::orders.at(i).getModelNumber() << "\n";
	    cout << "    Quantity: " << Database::orders.at(i).getQuantity() << "\n"; 
	    cout << "    SubTotal: " << storage.getRoboModelMN(Database::orders.at(i).getModelNumber()).getPrice() << " USD\n";
	    cout << "    Total(Subtotal+tax+shipping): " << Database::orders.at(i).getPrice() << " USD\n";
	    cout << "\n";
	}
    }
    cout << "\n";
}

void Database::addOrder(Order order){
    Database::orders.push_back(order);
}

int Database::getCustomerSize(){
    return customers.size();
}

void Database::printCustomers(){
    int i = 0, size = Database::customers.size();
    cout << "\nViewing all the Customers\n";
    cout << "=========================\n";
    for(i = 0; i < size; i ++){
	cout << i + 1 << " - Name: " << Database::customers.at(i).getName() << "\n";
	cout << "    Address: " << Database::customers.at(i).getAddress() << "\n";
	cout << "    Pin: " << Database::customers.at(i).getPin() << "\n";
        cout << "\n";
    }
    cout << "\n";
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
