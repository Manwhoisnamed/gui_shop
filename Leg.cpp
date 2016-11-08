

 #include "Leg.h"
 
 using namespace std;

 string Leg::getType(){
	return "leg";
 }

 double Leg::getpassiveDraw(){
 	return Leg::passiveDraw;
 }

 double Leg::getactiveDraw(){
	return Leg::activeDraw;
 }

 int Leg::getSpeed(){
	return Leg::speed;
 }
