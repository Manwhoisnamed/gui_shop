//maxwell Sanders 1001069652
//this is my robomodel class

#include "RoboModel.h"

int RoboModel::getArmCount(){
    return RoboModel::arms.size();
}

int RoboModel::getBatteryCount(){
    return RoboModel::batteries.size();
}

void RoboModel::setTorso(Torso itorso){
    RoboModel::torso = itorso;
    RoboModel::batterySpace = itorso.getBSpace();
}

void RoboModel::setHead(Head ihead){
    RoboModel::head = ihead;
}

void RoboModel::setLeg(Leg ileg){
    RoboModel::leg = ileg;
}

void RoboModel::addArm(Arm arm){
    RoboModel::arms.push_back(arm);
}

void RoboModel::addBattery(Battery battery){
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


Torso RoboModel::getTorso(){
    return RoboModel::torso;
}

Leg RoboModel::getLeg(){
    return RoboModel::leg;
}

Arm RoboModel::getArm(int i){
    return RoboModel::arms.at(i);
}

Battery RoboModel::getBattery(int i){
    return RoboModel::batteries.at(i);
}

Head RoboModel::getHead(){
    return RoboModel::head;
}

int RoboModel::getMN(){
    return RoboModel::MN;
}

double RoboModel::getActiveLife(){
   double charge = 0, draw = 0, life;
   int i;
   for( i = 0; i < RoboModel::batteries.size(); i ++){
	charge+=batteries.at(i).getCharge();
   }
   draw += RoboModel::torso.getDraw();
   draw += RoboModel::leg.getactiveDraw();
   draw += RoboModel::head.getDraw();
   for( i = 0; i < RoboModel::arms.size(); i ++){
	draw+=arms.at(i).getactiveDraw();
   }
   life = (1000 * charge) / draw;
   return life;
}

double RoboModel::getPassiveLife(){
   double charge = 0, draw = 0, life;
   int i;
   for( i = 0; i < RoboModel::batteries.size(); i ++){
	charge+=batteries.at(i).getCharge();
   }
   draw += RoboModel::torso.getDraw();
   draw += RoboModel::leg.getpassiveDraw();
   draw += RoboModel::head.getDraw();
   for( i = 0; i < RoboModel::arms.size(); i ++){
	draw+=arms.at(i).getpassiveDraw();
   }
   life = (1000 * charge) / draw;
   return life;
}

double RoboModel::getCost(){
   double cost;
   int i;
   cost += RoboModel::torso.getCost();
   cost += RoboModel::leg.getCost();
   cost += RoboModel::head.getCost();
   for( i = 0; i < RoboModel::arms.size(); i++){
       cost+=arms.at(i).getCost();
   }
   for( i = 0; i < RoboModel::batteries.size(); i++){
       cost+=batteries.at(i).getCost();
   }  
   return cost;
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
   double weight;
   int i;
   weight += RoboModel::torso.getWeight();
   weight += RoboModel::leg.getWeight();
   weight += RoboModel::head.getWeight();
   for( i = 0; i < RoboModel::arms.size(); i ++){
       weight+=arms.at(i).getWeight();
   }
   for( i = 0; i < RoboModel::batteries.size(); i ++){
       weight+=batteries.at(i).getWeight();
   }  
   return weight; 
}
