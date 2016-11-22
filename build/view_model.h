//maxwell Sanders
//this is the file for the robomodel viewer

#include <Fl/Fl.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Multiline_Output.H>
#include <Fl/Fl_Menu_Item.H>
#include "globals.h"

#ifndef __view_model_H
#define __view_model_H 2016
class view_model : public Fl_Group{
	Fl_Button refresh;
	Fl_Button up;
	Fl_Button down;
	Fl_Multiline_Output description;
	Fl_Output name;
	Fl_Output SN;
	Fl_Output activeLife;
	Fl_Output passiveLife;
	Fl_Output price;
	Fl_Output weight;
	Fl_Output speed;
	Fl_Box headlaser;
	Fl_Box armlaser;
	Fl_Box part;
	Fl_Choice SN_choice;
	int size = 0;
	int i = 0;

	void initialize_choices(){
	    size = storage.robomodelSize();
	    for(int x = 0; x < size; x ++){
		SN_choice.add((to_string(storage.getRoboModel(x).getMN()) + " - " + (storage.getRoboModel(x).getName())).c_str());
	    }
	}

	inline void select_i(){
	    i = SN_choice.value();
	    if(i == 0){
		up.deactivate();
	    }
	    else{
		up.activate();
	    }
	    if(i == size - 1){
		down.deactivate();
	    }	
	    else{
		down.activate();
	    }
	    popfields();
	}
	static void select(Fl_Widget* w, void * data){
	    ((view_model*)data)->select_i();
	}

	double calculateActive(){
	    double cha = 0;
	    double dra = 0;
	    dra += storage.getLegPin(storage.getRoboModel(i).getLeg()).getactiveDraw();
	    dra += storage.getHeadPin(storage.getRoboModel(i).getHead()).getDraw();	
	    dra += storage.getTorsoPin(storage.getRoboModel(i).getTorso()).getDraw();
	    dra += storage.getArmPin(storage.getRoboModel(i).getArm(0)).getactiveDraw();
	    cha += storage.getBatteryPin(storage.getRoboModel(i).getBattery(0)).getCharge();
	    if(storage.getRoboModel(i).getArm(1) != -1){
		dra += storage.getArmPin(storage.getRoboModel(i).getArm(1)).getactiveDraw();
	    }
	    if(storage.getRoboModel(i).getBattery(1) != -1){
		cha += storage.getBatteryPin(storage.getRoboModel(i).getBattery(1)).getCharge();
	    }
	    if(storage.getRoboModel(i).getBattery(2) != -1){
		cha += storage.getBatteryPin(storage.getRoboModel(i).getBattery(2)).getCharge();
	    }
	    return cha/dra;
	}

	double calculatePassive(){
	    double cha = 0;
	    double dra = 0;
	    dra += storage.getLegPin(storage.getRoboModel(i).getLeg()).getpassiveDraw();
	    dra += storage.getHeadPin(storage.getRoboModel(i).getHead()).getDraw();	
	    dra += storage.getTorsoPin(storage.getRoboModel(i).getTorso()).getDraw();
	    dra += storage.getArmPin(storage.getRoboModel(i).getArm(0)).getpassiveDraw();
	    cha += storage.getBatteryPin(storage.getRoboModel(i).getBattery(0)).getCharge();
	    if(storage.getRoboModel(i).getArm(1) != -1){
		dra += storage.getArmPin(storage.getRoboModel(i).getArm(1)).getpassiveDraw();
	    }
	    if(storage.getRoboModel(i).getBattery(1) != -1){
		cha += storage.getBatteryPin(storage.getRoboModel(i).getBattery(1)).getCharge();
	    }
	    if(storage.getRoboModel(i).getBattery(2) != -1){
		cha += storage.getBatteryPin(storage.getRoboModel(i).getBattery(2)).getCharge();
	    }
	    return cha/dra;
	}

	double calculateweight(){
	    double wei = 0;
	    wei += storage.getLegPin(storage.getRoboModel(i).getLeg()).getWeight();
	    wei += storage.getHeadPin(storage.getRoboModel(i).getHead()).getWeight();	
	    wei += storage.getTorsoPin(storage.getRoboModel(i).getTorso()).getWeight();
	    wei += storage.getArmPin(storage.getRoboModel(i).getArm(0)).getWeight();
	    wei += storage.getBatteryPin(storage.getRoboModel(i).getBattery(0)).getWeight();
	    if(storage.getRoboModel(i).getArm(1) != -1){
		wei += storage.getArmPin(storage.getRoboModel(i).getArm(1)).getWeight();
	    }
	    if(storage.getRoboModel(i).getBattery(1) != -1){
		wei += storage.getBatteryPin(storage.getRoboModel(i).getBattery(1)).getWeight();
	    }
	    if(storage.getRoboModel(i).getBattery(2) != -1){
		wei += storage.getBatteryPin(storage.getRoboModel(i).getBattery(2)).getWeight();
	    }
	    return wei;
	}

	void popfields(){
	    string sSN;
	    string scost;
	    string sweight;
	    string spassiveDraw;
	    string sactiveDraw;
	    string sspeed;	    

	    name.value((storage.getRoboModel(i)).getName().c_str());
	    description.value((storage.getRoboModel(i)).getDescription().c_str());
	    sSN = to_string(storage.getRoboModel(i).getMN());
	    scost = to_string(storage.getRoboModel(i).getPrice());
	    sweight = to_string(calculateweight());
	    spassiveDraw = to_string(calculatePassive());
	    sactiveDraw = to_string(calculateActive());
	    sspeed = to_string(storage.getLegPin(storage.getRoboModel(i).getLeg()).getSpeed());
	    SN.value(sSN.c_str());
	    speed.value(sspeed.c_str());
	    price.value(scost.c_str());
	    weight.value(sweight.c_str());
	    passiveLife.value(spassiveDraw.c_str());
	    activeLife.value(sactiveDraw.c_str());
	    if(storage.getArmPin(storage.getRoboModel(i).getArm(0)).getLaser()){
	        armlaser.label("*ARM LASER EQUIPPED*");
	    }
	    else if(storage.getRoboModel(i).getArm(1) != -1){
		if(storage.getArmPin(storage.getRoboModel(i).getArm(1)).getLaser()){
		    armlaser.label("*ARM LASER EQUIPPED*");
		}
	    }
	    else{
	        armlaser.label("");
	    }
	    if(storage.getHeadPin(storage.getRoboModel(i).getHead()).getLaser()){
	        headlaser.label("*HEAD LASER EQUIPPED*");
	    }
	    else{
	        headlaser.label("");
	    }
	}

	inline void down_clicked_i(){
	    i++;
	    SN_choice.value(i);
	    if(i == storage.robomodelSize() - 1){
		down.deactivate();
	    }
	    up.activate();
	    popfields();
	};
	static void down_clicked(Fl_Widget* w, void* data){
	    ((view_model*)data)->down_clicked_i();
	};

	inline void up_clicked_i(){
	    i--;
	    SN_choice.value(i);
	    if(i == 0){
		up.deactivate();
	    }
	    down.activate();
	    popfields();
	};
	static void up_clicked(Fl_Widget* w, void* data){
	    ((view_model*)data)->up_clicked_i();
	};

	//for the refresh button, if someone builds a part and the down is deactivate then this will fix it
        inline void refresh_clicked_i(){
	    if(storage.robomodelSize() > i + 1){
		down.activate();
	    }
	    if(size < storage.robomodelSize()){
		for(int x = size; x < storage.robomodelSize(); x++){
		SN_choice.add((to_string(storage.getRoboModel(x).getMN()) + " - " + (storage.getRoboModel(x).getName())).c_str());
		}
	    }
	    size = storage.robomodelSize();
	};
	static void refresh_clicked(Fl_Widget* w, void* data){
	    ((view_model*)data)->refresh_clicked_i();
	};

    public:
	view_model():
	Fl_Group(0,0,1000,700),
	refresh(115, 40, 175, 25, "Refresh"),
	up(115,70,175,25,"@8>"),
	down(115, 130, 175, 25, "@2>"),
	name(400, 100, 200, 25, "Name"),
	SN(400, 130, 200, 25, "MN"),
	price(400, 160, 200, 25, "Price (USD)"),
	weight(400, 190, 200, 25, "Weight (KG)"),
	activeLife(400, 220, 200, 25, "Active Life (Day)"),
	passiveLife(400, 250, 200, 25, "Passive Life (Day)"),
	speed(400,280, 200, 25, "Speed (KM/H)"),
	headlaser(400, 310, 200, 25, ""),	
	armlaser(400, 340, 200, 25, ""), 
	description(400, 370, 250, 150, "Description"),
	part(450, 30, 100, 25, "Viewing Models"),
	SN_choice(115, 100, 175, 25, "Model Selector"){
	    reset_values();
	    headlaser.labelcolor(FL_RED);
	    armlaser.labelcolor(FL_RED);
	    up.deactivate();
	    up.callback(up_clicked,this);
	    down.callback(down_clicked,this);
	    if(storage.robomodelSize() == 1){
	        down.deactivate();
	    }
	    refresh.callback(refresh_clicked, this);
	    initialize_choices();
	    SN_choice.callback(select, this);
	}

	void reset_values(){
	    i=0;
	    SN_choice.value(0);
	    up.deactivate();
	    if(storage.robomodelSize() > 0){
		popfields();
	    }
	    else{
		down.deactivate();
	 	name.value("");
	 	SN.value("");
		speed.value("");
	 	price.value("");
	 	weight.value("");
	 	passiveLife.value("");
	 	activeLife.value("");
	 	headlaser.label("");
	 	armlaser.label("");
		description.value("There are no models in storage.");
	    }
	}
};
#endif
