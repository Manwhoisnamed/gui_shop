//maxwell Sanders 1001069652
//the robo model header

 #include "Arm.h"
 #include "Leg.h"
 #include "Torso.h"
 #include "Battery.h"
 #include "Head.h"
 #include <vector>

 using namespace std;

 #ifndef __ROBOMODEL_H
 #define __ROBOMODEL_H 2016
 class RoboModel {
  public:
    RoboModel(int headSN, int legSN, int torsoSN, int armSN, int batSN, int iMN, double iprice):
	head(headSN),
	leg(legSN),
	torso(torsoSN),
	MN(iMN),
	price(iprice){
	arms.push_back(armSN);
	batteries.push_back(batSN);     
    };    
    RoboModel(){};

    void setHead(int head);
    void setLeg(int leg);
    void setTorso(int torso);
    void addBattery(int battery);
    void addArm(int arm);
    void setName(string iname);
    void setDescription(string idescription);
    void setPrice(double iprice);
    void setMN(int iMN);

    int getArm(int i);
    int getLeg();
    int getTorso();
    int getBattery(int i);
    int getHead();
    string getName();
    int getMN();
    double getCost();
    double getActiveLife();
    double getPassiveLife();
    double getPrice();
    string getDescription();
    double getWeight();
    int getArmCount();
    int getBatteryCount();

  private:
    int head;
    int leg;
    int torso;
    vector<int> arms;
    vector<int> batteries;
    string description = "";
    string name = "";
    double price;
    int MN;
 };
 #endif
