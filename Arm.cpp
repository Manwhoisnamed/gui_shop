
 #include "Arm.h"
 
 using namespace std;

 string Arm::getType(){
	return "arm";
 }

 double Arm::getpassiveDraw(){
 	return Arm::passiveDraw;
 }

 double Arm::getactiveDraw(){
	return Arm::activeDraw;
 }

 bool Arm::getLaser(){
	return Arm::laser;
 }
