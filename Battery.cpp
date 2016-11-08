

 #include "Battery.h"
 
 using namespace std;

 string Battery::getType(){
	return "battery";
 }

 double Battery::getCharge(){
 	return Battery::charge;
 }

