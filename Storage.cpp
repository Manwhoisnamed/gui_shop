//maxwell Sanders 1001069652
//this class stores the parts and robomodels

#include "Storage.h"
#include <iostream>
#include <fstream>
#include <sstream>

//the sizing suite
int Storage::armSize(){
    return Storage::arms.size();
}

int Storage::legSize(){
    return Storage::legs.size();
}

int Storage::headSize(){
    return Storage::heads.size();
}

int Storage::torsoSize(){
    return Storage::torsos.size();
}

int Storage::batterySize(){
    return Storage::batteries.size();
}

int Storage::robomodelSize(){
    return Storage::robomodels.size();
}

//the add suite
void Storage::addArm(Arm arm){
    Storage::arms.push_back(arm);
}

void Storage::addLeg(Leg leg){
    Storage::legs.push_back(leg);
}

void Storage::addHead(Head head){
    Storage::heads.push_back(head);
}

void Storage::addTorso(Torso torso){
    Storage::torsos.push_back(torso);
}

void Storage::addBattery(Battery battery){
    Storage::batteries.push_back(battery);
}

void Storage::addRoboModel(RoboModel robomodel){
    Storage::robomodels.push_back(robomodel);	
}


//the getter suite, used i
Arm Storage::getArm(int i){
    return Storage::arms.at(i);
}

Leg Storage::getLeg(int i){
    return Storage::legs.at(i);
}

Battery Storage::getBattery(int i){
    return Storage::batteries.at(i);
}

Torso Storage::getTorso(int i){
    return Storage::torsos.at(i);
}

Head Storage::getHead(int i){
    return Storage::heads.at(i);
}

RoboModel Storage::getRoboModel(int i){
    return Storage::robomodels.at(i);
}

RoboModel Storage::getRoboModelMN(int MN){
    int i = 0;
    for( i = 0; robomodels.size(); i++){
	if(MN == robomodels.at(i).getMN()){
	    return robomodels.at(i);
	}
    }
}

//this is the method that saves all of the info into a file
void Storage::store(){
    ofstream myfile;
    myfile.open("Storage.txt");
    int i, j;
    //stores the arms
    myfile << "ARMS==========================\n";
    for(i = 0; i < Storage::arms.size();i ++){
	myfile << arms.at(i).getSN() << " " << arms.at(i).getWeight() << " " << arms.at(i).getCost() << " " << arms.at(i).getpassiveDraw() << " " << arms.at(i).getactiveDraw() << " " << arms.at(i).getLaser() << "\n"; 
        myfile << arms.at(i).getName() << "\n";
        myfile << arms.at(i).getDescription() << "\n";
    	myfile << "-2end\n";
    }
    myfile << "-1\n";

    //stores  the heads
    myfile << "HEADS=========================\n";
    for(i = 0; i < Storage::heads.size();i ++){
	myfile << heads.at(i).getSN() << " " << heads.at(i).getWeight() << " " << heads.at(i).getCost() << " " << heads.at(i).getDraw() << " " << heads.at(i).getLaser() << "\n"; 
        myfile << heads.at(i).getName() << "\n";
        myfile << heads.at(i).getDescription() << "\n";
    	myfile << "-2end\n";
    }
    myfile << "-1\n";

    //stores the torsos
    myfile << "TORSOS========================\n";
    for(i = 0; i < Storage::torsos.size();i ++){
	myfile << torsos.at(i).getSN() << " " << torsos.at(i).getWeight() << " " << torsos.at(i).getCost() << " " << torsos.at(i).getDraw() << " " << torsos.at(i).getBSpace() << "\n"; 
        myfile << torsos.at(i).getName() << "\n";
        myfile << torsos.at(i).getDescription() << "\n";
    	myfile << "-2end\n";
    }
    myfile << "-1\n";

    //stores the legs
    myfile << "LEGS==========================\n";
    for(i = 0; i < Storage::legs.size();i ++){
	myfile << legs.at(i).getSN() << " " << legs.at(i).getWeight() << " " << legs.at(i).getCost() << " " << legs.at(i).getpassiveDraw() << " " << legs.at(i).getactiveDraw() << " " << legs.at(i).getSpeed() << "\n"; 
        myfile << legs.at(i).getName() << "\n";
        myfile << legs.at(i).getDescription() << "\n";
    	myfile << "-2end\n";
    }
    myfile << "-1\n";
    
    //stores batteries
    myfile << "BATTERIES=====================\n";
    for(i = 0; i < Storage::batteries.size();i ++){
	myfile << batteries.at(i).getSN() << " " << batteries.at(i).getWeight() << " " << batteries.at(i).getCost() << " " << batteries.at(i).getCharge() << "\n"; 
        myfile << batteries.at(i).getName() << "\n";
        myfile << batteries.at(i).getDescription() << "\n";
    	myfile << "-2end\n";
    }
    myfile << "-1\n";

    //stores the robomodels
    myfile << "ROBOMODELS====================\n";
    for(i = 0; i < Storage::robomodels.size(); i ++){	
	myfile << "torso-----------\n";
	myfile << robomodels.at(i).getTorso().getSN() << " " << robomodels.at(i).getTorso().getWeight() << " " << robomodels.at(i).getTorso().getBSpace() << " " << robomodels.at(i).getTorso().getDraw() << " " << robomodels.at(i).getTorso().getCost() << "\n"; 
        myfile << robomodels.at(i).getTorso().getName() << "\n";
        myfile << robomodels.at(i).getTorso().getDescription() << "\n";
	
	myfile << "leg-------------\n";
	myfile << robomodels.at(i).getLeg().getSN() << " " << robomodels.at(i).getLeg().getWeight() << " " << robomodels.at(i).getLeg().getSpeed() << " " << robomodels.at(i).getLeg().getpassiveDraw() << " " << robomodels.at(i).getLeg().getactiveDraw() << " " << robomodels.at(i).getLeg().getCost() << "\n"; 
        myfile << robomodels.at(i).getLeg().getName() << "\n";
        myfile << robomodels.at(i).getLeg().getDescription() << "\n";
	
	myfile << "head------------\n";
	myfile << robomodels.at(i).getHead().getSN() << " " << robomodels.at(i).getHead().getWeight() << " " << robomodels.at(i).getHead().getLaser() << " " << robomodels.at(i).getHead().getDraw() << " " << robomodels.at(i).getHead().getCost() << "\n"; 
        myfile << robomodels.at(i).getHead().getName() << "\n";
        myfile << robomodels.at(i).getHead().getDescription() << "\n";
	
        myfile << "arms------------\n";
 	for(j = 0 ; j < Storage::robomodels.at(i).getArmCount() ; j ++){
	    myfile << robomodels.at(i).getArm(j).getSN() << " " << robomodels.at(i).getArm(j).getWeight() << " " << robomodels.at(i).getArm(j).getLaser() << " " << robomodels.at(i).getArm(j).getpassiveDraw() << " " << robomodels.at(i).getArm(j).getactiveDraw() << " " << robomodels.at(i).getArm(j).getCost() << "\n"; 
            myfile << robomodels.at(i).getArm(j).getName() << "\n";
            myfile << robomodels.at(i).getArm(j).getDescription() << "\n";
	}		
	myfile << "-2\n";

	myfile << "batteries-------\n";
 	for(j = 0 ; j < Storage::robomodels.at(i).getBatteryCount() ; j ++){
	    myfile << robomodels.at(i).getBattery(j).getSN() << " " << robomodels.at(i).getBattery(j).getWeight() << " " << robomodels.at(i).getBattery(j).getCharge() << " " << robomodels.at(i).getBattery(j).getCost() << "\n"; 
            myfile << robomodels.at(i).getBattery(j).getName() << "\n";
            myfile << robomodels.at(i).getBattery(j).getDescription() << "\n";
	}		
	myfile << "-2\n";

	myfile << robomodels.at(i).getPrice() << " " << robomodels.at(i).getMN() << "\n";
        myfile << robomodels.at(i).getName() << "\n";
        myfile << robomodels.at(i).getDescription() << "\n";
    }
    myfile << "-1\n";
    myfile.close();
}

void Storage::load(){
   ifstream myfile("Storage.txt");
   string line;
   double weight, cost, charge, draw, passiveDraw, activeDraw;
   int laser, SN, batteryspace, speed, MN, price;
   string name;
   string description = "";
   string buffer;

   //gets the arms
   getline(myfile,line);
   while(true){
	getline(myfile, line);
	if(line == "-1"){
	    break;	
	}
	istringstream iss(line);
	iss >> SN >> weight >> cost >> passiveDraw >> activeDraw >> laser;
	getline(myfile,name);
	getline(myfile,description);
	while(true){
	    getline(myfile,buffer);
	    if(buffer == "-2end"){
		break;
	    }
	    description += "\n" + buffer;
	}
	Arm arm(name, SN, weight, cost, description, passiveDraw, activeDraw, laser);
	Storage::arms.push_back(arm);
   }

   //gets the heads
   getline(myfile,line);
   while(true){
	getline(myfile, line);
	if(line == "-1"){
	    break;	
	}
	istringstream iss(line);
	iss >> SN >> weight >> cost >> draw >> laser;
	getline(myfile,name);
	getline(myfile,description);
	while(true){
	    getline(myfile,buffer);
	    if(buffer == "-2end"){
		break;
	    }
	    description += "\n" + buffer;
	}
	Head head(name, SN, weight, cost, description, draw, laser);
	Storage::heads.push_back(head);
   }
  
   //gets the torsos
   getline(myfile,line);
   while(true){
	getline(myfile, line);
	if(line == "-1"){
	    break;	
	}
	istringstream iss(line);
	iss >> SN >> weight >> cost >> draw >> batteryspace;
	getline(myfile,name);
	getline(myfile,description);
	while(true){
	    getline(myfile,buffer);
	    if(buffer == "-2end"){
		break;
	    }
	    description += "\n" + buffer;
	}
	Torso torso(name, SN, weight, cost, description, draw, batteryspace);
	Storage::torsos.push_back(torso);
   }

   //gets the legs
   getline(myfile,line);
   while(true){
	getline(myfile, line);
	if(line == "-1"){
	    break;	
	}
	istringstream iss(line);
	iss >> SN >> weight >> cost >> passiveDraw >> activeDraw >> speed;
	getline(myfile,name);
	getline(myfile,description);
	while(true){
	    getline(myfile,buffer);
	    if(buffer == "-2end"){
		break;
	    }
	    description += "\n" + buffer;
	}
	Leg leg(name, SN, weight, cost, description, passiveDraw, activeDraw, speed);
	Storage::legs.push_back(leg);
   }

   //gets the arms
   getline(myfile,line);
   while(true){
	getline(myfile, line);
	if(line == "-1"){
	    break;	
	}
	istringstream iss(line);
	iss >> SN >> weight >> cost >> charge;
	getline(myfile,name);
	getline(myfile,description);
	while(true){
	    getline(myfile,buffer);
	    if(buffer == "-2end"){
		break;
	    }
	    description += "\n" + buffer;
	}
	Battery battery(name, SN, weight, cost, description, charge);
	Storage::batteries.push_back(battery);
   }

   //gets the robomodels
   getline(myfile, line);
   while(true){
	RoboModel robomodel;

	//gets the first line and checks if it is bad
	getline(myfile, line);
	if(line == "-1"){
	    break;
	}

	//gets and make the torso also checks for end since it is first
	getline(myfile, line);
	istringstream torsovar(line);
	torsovar >> SN >> weight >> batteryspace >> draw >> cost;
	getline(myfile, name);
	getline(myfile, description);
	Torso torso(name, SN, weight, cost, description, draw, batteryspace);
	robomodel.setTorso(torso);	

	//gets and makes the leg
	getline(myfile, line);
	getline(myfile, line);
	istringstream legvar(line);
	legvar >> SN >> weight >> speed >> passiveDraw >> activeDraw >> cost;
	getline(myfile,name);
	getline(myfile,description);
	Leg leg(name, SN, weight, cost, description, passiveDraw, activeDraw, speed);
	robomodel.setLeg(leg);

	//gets and makes the head 
	getline(myfile, line);
	getline(myfile, line);
	istringstream headvar(line);
	headvar >> SN >> weight >> laser, draw, cost;
	getline(myfile,name);
	getline(myfile,description);
	Head head(name, SN, weight, cost, description, draw, laser);
	robomodel.setHead(head);
 		
 	//gets the arms
	getline(myfile,line);
	while(true){
	    getline(myfile,line);
	    if(line == "-2"){
		break;
	    }
	    istringstream armvar(line);
	    armvar >> SN >> weight >> laser >> passiveDraw >> activeDraw >> cost;
	    getline(myfile, name);
	    getline(myfile, description);
	    Arm arm(name, SN, weight, cost, description, passiveDraw, activeDraw, laser);
	    robomodel.addArm(arm);
	}

 	//gets the arms
	getline(myfile,line);
	while(true){
	    getline(myfile,line);
	    if(line == "-2"){
		break;
	    }
	    istringstream batvar(line);
	    batvar >> SN >> weight >> charge  >> cost;
	    getline(myfile, name);
	    getline(myfile, description);
	    Battery battery(name, SN, weight, cost, description, charge);
	    robomodel.addBattery(battery);
	}

	//gets the price
	getline(myfile, line);
	istringstream iss(line);
	iss >> price >> MN;
	robomodel.setPrice(price);
	robomodel.setMN(MN);
	getline(myfile, name);
	robomodel.setName(name);
	getline(myfile, description);
	robomodel.setDescription(description);
	Storage::addRoboModel(robomodel);	
   }
   myfile.close();
}

bool Storage::checkLegs(int SN){
    int i = 0; 
    for(i = 0; i < legs.size(); i ++){
	if(SN == legs.at(i).getSN()){
	    return true;
	}
    }
    return false;
}

bool Storage::checkArms(int SN){
    int i = 0; 
    for(i = 0; i < arms.size(); i ++){
	if(SN == arms.at(i).getSN()){
	    return true;
	}
    }
    return false;
}

bool Storage::checkHeads(int SN){
    int i = 0; 
    for(i = 0; i < heads.size(); i ++){
	if(SN == heads.at(i).getSN()){
	    return true;
	}
    }
    return false;
}

bool Storage::checkBatteries(int SN){
    int i = 0; 
    for(i = 0; i < Storage::batteries.size(); i ++){
	if(SN == batteries.at(i).getSN()){
	    return true;
	}
    }
    return false;
}

bool Storage::checkTorsos(int SN){
    int i = 0; 
    for(i = 0; i < torsos.size(); i ++){
	if(SN == torsos.at(i).getSN()){
	    return true;
	}
    }
    return false;
}

bool Storage::checkRoboModels(int MN){
    int i = 0; 
    for(i = 0; i < robomodels.size(); i ++){
	if(MN == robomodels.at(i).getMN()){
	    return true;
	}
    }
    return false;
}

