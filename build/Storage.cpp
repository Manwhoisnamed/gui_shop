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
	myfile << arms.at(i).getPicture() << "\n";
    }
    myfile << "-1\n";

    //stores  the heads
    myfile << "HEADS=========================\n";
    for(i = 0; i < Storage::heads.size();i ++){
	myfile << heads.at(i).getSN() << " " << heads.at(i).getWeight() << " " << heads.at(i).getCost() << " " << heads.at(i).getDraw() << " " << heads.at(i).getLaser() << "\n"; 
        myfile << heads.at(i).getName() << "\n";
        myfile << heads.at(i).getDescription() << "\n";
    	myfile << "-2end\n";
	myfile << heads.at(i).getPicture() << "\n";
    }
    myfile << "-1\n";

    //stores the torsos
    myfile << "TORSOS========================\n";
    for(i = 0; i < Storage::torsos.size();i ++){
	myfile << torsos.at(i).getSN() << " " << torsos.at(i).getWeight() << " " << torsos.at(i).getCost() << " " << torsos.at(i).getDraw() << " " << torsos.at(i).getBSpace() << "\n"; 
        myfile << torsos.at(i).getName() << "\n";
        myfile << torsos.at(i).getDescription() << "\n";
    	myfile << "-2end\n";
	myfile << torsos.at(i).getPicture() << "\n";
    }
    myfile << "-1\n";

    //stores the legs
    myfile << "LEGS==========================\n";
    for(i = 0; i < Storage::legs.size();i ++){
	myfile << legs.at(i).getSN() << " " << legs.at(i).getWeight() << " " << legs.at(i).getCost() << " " << legs.at(i).getpassiveDraw() << " " << legs.at(i).getactiveDraw() << " " << legs.at(i).getSpeed() << "\n"; 
        myfile << legs.at(i).getName() << "\n";
        myfile << legs.at(i).getDescription() << "\n";
    	myfile << "-2end\n";
	myfile << legs.at(i).getPicture() << "\n";
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

    //stores batteries
    myfile << "ROBOMODELS=====================\n";
    for(i = 0; i < Storage::robomodels.size();i ++){
	myfile << robomodels.at(i).getHead() << " " << robomodels.at(i).getLeg() << " " << robomodels.at(i).getTorso() << " " << robomodels.at(i).getPrice() << " " << robomodels.at(i).getMN() << "\n";
	for(j = 0; j < 2; j++){
	    myfile << robomodels.at(i).getArm(j) << " ";
	} 
	myfile << "\n";
	for(j = 0; j < 3; j++){
	    myfile << robomodels.at(i).getBattery(j) << " ";
	} 
	myfile << "\n";
        myfile << robomodels.at(i).getName() << "\n";
        myfile << robomodels.at(i).getDescription() << "\n";
    	myfile << "-2end\n";
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
   string picture;
   arms.clear();
   legs.clear();
   batteries.clear();
   heads.clear();
   torsos.clear();

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
	getline(myfile, picture);
	Arm arm(name, SN, weight, cost, description, passiveDraw, activeDraw, laser, picture);
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
	getline(myfile, picture);
	Head head(name, SN, weight, cost, description, draw, laser, picture);
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
	getline(myfile,picture);
	Torso torso(name, SN, weight, cost, description, draw, batteryspace, picture);
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
	getline(myfile, picture);
	Leg leg(name, SN, weight, cost, description, passiveDraw, activeDraw, speed, picture);
	Storage::legs.push_back(leg);
   }

   //gets the battery
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

   //gets the robomodel
   getline(myfile,line);
   while(true){
	int headSN;
	int legSN;
	int torsoSN;
	int armSN;
	int batSN;
	RoboModel robomodel;
	getline(myfile, line);
	if(line == "-1"){
	    break;	
	}
	istringstream iss(line);
	iss >> headSN >> legSN >> torsoSN >> price >> MN;
	getline(myfile, line);
	istringstream armline(line);
	for(int x = 0; x < 2; x++){
	    armline >> armSN;
	    robomodel.addArm(armSN);	
	}
	getline(myfile, line);
	istringstream batline(line);
	for(int x = 0; x < 3; x++){
	    batline >> batSN;
	    robomodel.addBattery(batSN);	
	}
	getline(myfile,name);
	getline(myfile,description);
	while(true){
	    getline(myfile,buffer);
	    if(buffer == "-2end"){
		break;
	    }
	    description += "\n" + buffer;
	}
	robomodel.setHead(headSN);
	robomodel.setLeg(legSN);
	robomodel.setTorso(torsoSN);
	robomodel.setMN(MN);
	robomodel.setPrice(price);
	robomodel.setName(name);
	robomodel.setDescription(description);
	Storage::robomodels.push_back(robomodel);
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

