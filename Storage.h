//maxwell Sanders 1001069652
//this class is used to store parts and models

 #include <string.h>
 #include <vector>
 #include "Arm.h"
 #include "Leg.h"
 #include "Battery.h"
 #include "Torso.h"
 #include "Head.h"
 #include "RoboModel.h"
 
 using namespace std;

 #ifndef __Storage_H
 #define __Storage_H 2016
 class Storage{
  private:
    vector<Arm> arms;
    vector<Leg> legs;
    vector<Torso> torsos;
    vector<Battery> batteries;
    vector<Head> heads;
    vector<RoboModel> robomodels;    
  public:
    //the usage suite
    Storage(){};

    //the sizing suite
    int armSize();
    int legSize();
    int torsoSize();
    int batterySize();
    int headSize();
    int robomodelSize();

    //the addition suite
    void addArm(Arm arm);
    void addLeg(Leg leg);
    void addBattery(Battery battery);
    void addTorso(Torso torso);
    void addHead(Head head);
    void addRoboModel(RoboModel robomodel);

    //the getter suite
    Arm getArm(int i);
    Leg getLeg(int i);
    Battery getBattery(int i);
    Torso getTorso(int i);
    Head getHead(int i);
    RoboModel getRoboModel(int i);
    RoboModel getRoboModelMN(int MN);

    //persistence
    void load();
    void store();

    //data validation suite
    bool checkArms(int SN);
    bool checkLegs(int SN);
    bool checkBatteries(int SN);
    bool checkTorsos(int SN);
    bool checkHeads(int SN);
    bool checkRoboModels(int SN); 
    
 };
 #endif
