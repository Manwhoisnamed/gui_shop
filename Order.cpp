//maxwell sanders 1001069652
//the order holds the information necessary for a transaction

#include "Order.h"


int Order::getCustomerPin(){
    return Order::customerpin;
}

int Order::getModelNumber(){
    return Order::ModelNumber;
}

double Order::getPrice(){
    return Order::price;
}

int Order::getQuantity(){
    return Order::quantity;
}

void Order::calculatePrice(Storage storage){
    RoboModel robomodel;
    robomodel = storage.getRoboModelMN(Order::ModelNumber);
    Order::price = robomodel.getPrice() * quantity;    //multiply robot models by the quantity
    Order::price += robomodel.getWeight() * .01; //.01 cent shipping by the kilogram
    Order::price += Order::price * .0825;              //8.25 cents on a dollar for tax
}

void Order::setModelNumber(int MN){
    Order::ModelNumber = MN;
}

void Order::setCustomerPin(int pin){
    Order::customerpin = pin;
}

void Order::setQuantity(int quan){
    Order::quantity = quan;
}
