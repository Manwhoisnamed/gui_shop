//maxwell Sanders 1001069652
//this is my robomodel class

#include "RoboModel.h"

int RoboModel::getArmCount(){
    return RoboModel::arms.size();
}

int RoboModel::getBatteryCount(){
    return RoboModel::batteries.size();
}

void RoboModel::setTorso(int itorso){
    RoboModel::torso = itorso;
}

void RoboModel::setHead(int ihead){
    RoboModel::head = ihead;
}

void RoboModel::setLeg(int ileg){
    RoboModel::leg = ileg;
}

void RoboModel::addArm(int arm){
    RoboModel::arms.push_back(arm);
}

void RoboModel::addBattery(int battery){
    RoboModel::batteries.push_back(battery);
}

void RoboModel::setName(string iname){
    RoboModel::name = iname;
}

void RoboModel::setDescription(string idescription){
    RoboModel::description = idescription;
}

void RoboModel::setPrice(double iprice){
    RoboModel::price = iprice;
}

void RoboModel::setMN(int iMN){
    RoboModel::MN = iMN;
}


int RoboModel::getTorso(){
    return RoboModel::torso;
}

int RoboModel::getLeg(){
    return RoboModel::leg;
}

int RoboModel::getArm(int i){
    return RoboModel::arms.at(i);
}

int RoboModel::getBattery(int i){
    return RoboModel::batteries.at(i);
}

int RoboModel::getHead(){
    return RoboModel::head;
}

int RoboModel::getMN(){
    return RoboModel::MN;
}

double RoboModel::getActiveLife(){
    return 0;
}

double RoboModel::getPassiveLife(){
    return 0;
}

double RoboModel::getCost(){
   return 0;
}

double RoboModel::getPrice(){
    return RoboModel::price;
}

string RoboModel::getDescription(){
    return RoboModel::description;
}

string RoboModel::getName(){
    return RoboModel::name;
}

double RoboModel::getWeight(){
   return 0; 
}
