//maxwell Sanders 1001069652
//this is the definitions file for the robopart

 #include "RoboPart.h"

 using namespace std;

 string RoboPart::getName(){
    return RoboPart::name;
 }

 int RoboPart::getSN(){
    return RoboPart::SN;
 }

 double RoboPart::getWeight(){
    return RoboPart::weight;
 }

 double RoboPart::getCost(){
    return RoboPart::cost;
 }

 string RoboPart::getDescription(){
    return RoboPart::description;
 }
