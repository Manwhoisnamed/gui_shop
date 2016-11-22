//maxwell sanders
//this is the cpp for the salesman

#include "salesman.h"

int salesman::getWage(){
    return salesman::wage;
}

string salesman::getName(){
    return salesman::name;
}

int salesman::getPin(){
    return salesman::pin;
}

void salesman::setWage(double iwage){
    wage = iwage;
}

void salesman::setName(string iname){
    name = iname;
}

void salesman::setPin(int ipin){
    pin = ipin;
}
