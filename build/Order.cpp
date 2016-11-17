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
