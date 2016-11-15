//maxwell Sanders 1001069652
//this is the file to view the battery

#include <Fl/Fl.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Multiline_Output.H>
#include "globals.h"

#ifndef __view_battery_H
#define __view_battery_H 2016
class view_battery : public Fl_Group{
	Fl_Button refresh;
	Fl_Button up;
	Fl_Button down;
	Fl_Multiline_Output description;
	Fl_Output name;
	Fl_Output SN;
	Fl_Output cost;
	Fl_Output weight;
	Fl_Output charge;
	Fl_Box part;
	int i = 0;

	inline void down_clicked_i(){
	    i++;
	    if(i == storage.batterySize() - 1){
		down.deactivate();
	    }
	    up.activate();
	    string sSN;
	    string scost;
	    string sweight;
	    string scharge;
	    
	    name.value((storage.getBattery(i)).getName().c_str());
	    description.value((storage.getBattery(i)).getDescription().c_str());
	    sSN = to_string(storage.getBattery(i).getSN());
	    scost = to_string(storage.getBattery(i).getCost());
	    sweight = to_string(storage.getBattery(i).getWeight());
	    scharge = to_string(storage.getBattery(i).getCharge());
	    SN.value(sSN.c_str());
	    cost.value(scost.c_str());
	    weight.value(sweight.c_str());
	    charge.value(scharge.c_str());
	};
	static void down_clicked(Fl_Widget* w, void* data){
	    ((view_battery*)data)->down_clicked_i();
	};

	inline void up_clicked_i(){
	    i--;
	    if(i == 0){
		up.deactivate();
	    }
	    down.activate();
	    string sSN;
	    string scost;
	    string sweight;
	    string scharge;
	    
	    name.value((storage.getBattery(i)).getName().c_str());
	    description.value((storage.getBattery(i)).getDescription().c_str());
	    sSN = to_string(storage.getBattery(i).getSN());
	    scost = to_string(storage.getBattery(i).getCost());
	    sweight = to_string(storage.getBattery(i).getWeight());
	    scharge = to_string(storage.getBattery(i).getCharge());
	    SN.value(sSN.c_str());
	    cost.value(scost.c_str());
	    weight.value(sweight.c_str());
	    charge.value(scharge.c_str());
	};
	static void up_clicked(Fl_Widget* w, void* data){
	    ((view_battery*)data)->up_clicked_i();
	};

	//for the refresh button, if someone builds a part and the down is deactivate then this will fix it
        inline void refresh_clicked_i(){
	    if(storage.batterySize() > i + 1){
		down.activate();
	    }
	};
	static void refresh_clicked(Fl_Widget* w, void* data){
	    ((view_battery*)data)->refresh_clicked_i();
	};

    public:
	view_battery():
	Fl_Group(0,0,1000,700),
	refresh(5, 60, 100, 25, "Refresh"),
	up(5,30,100,25,"@8>"),
	down(110, 30, 100, 25, "@2>"),
	name(400, 100, 200, 25, "Name"),
	SN(400, 130, 200, 25, "SN"),
	cost(400, 160, 200, 25, "Cost (USD)"),
	weight(400, 190, 200, 25, "Weight (KG)"),
	charge(400, 220, 200, 25, "Active Draw (KW)"),
	description(400, 250, 250, 150, "Description"),
	part(450, 30, 100, 25, "Viewing Batteries"){
	    reset_values();
	    up.deactivate();
	    up.callback(up_clicked,this);
	    down.callback(down_clicked,this);
	    if(storage.batterySize() == 1){
	        down.deactivate();
	    }
	    refresh.callback(refresh_clicked, this);
	}

	void reset_values(){
	    i = 0;
	    up.deactivate();
	    if(storage.batterySize() == 1){
	        down.deactivate();
	    }
	    string sSN;
	    string scost;
	    string sweight;
	    string scharge;
	    if(storage.batterySize() > 0){
	 	name.value((storage.getBattery(i)).getName().c_str());
	 	description.value((storage.getBattery(i)).getDescription().c_str());
		sSN = to_string(storage.getBattery(i).getSN());
		scost = to_string(storage.getBattery(i).getCost());
		sweight = to_string(storage.getBattery(i).getWeight());
		scharge = to_string(storage.getBattery(i).getCharge());
		SN.value(sSN.c_str());
		cost.value(scost.c_str());
		weight.value(sweight.c_str());
		charge.value(scharge.c_str());
	    }
	    else{
	 	name.value("");
	 	SN.value("");
	 	cost.value("");
	 	weight.value("");
	 	charge.value("");
		description.value("There are no batteries in storage.");
	    }
	}
};
#endif
