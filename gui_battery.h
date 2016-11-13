//maxwell sanders 1001069652
//This is the gui file for a group that will have the basics necessary for an battery

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Menu_Item.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Multiline_Input.H>
#include <Fl/Fl_Check_Button.H>
#include "globals.h"

#ifndef __gui_battery_H
#define __gui_battery_H 2016
class gui_battery : public Fl_Window{
    Fl_Input name;
    Fl_Input SN;
    Fl_Input cost;
    Fl_Input weight;
    Fl_Input charge;
    Fl_Box sn_response;
    Fl_Box cost_response;
    Fl_Box weight_response;
    Fl_Box charge_response;
    Fl_Box name_response;
    Fl_Box description_response;
    Fl_Multiline_Input description;
    Fl_Button cancel;
    Fl_Button create;    

    //callback combo to make the window close
    inline void create_clicked_i(){
	bool valid = true;
	int isn;
	double iweight, icost, icharge;
	if(strlen(name.value()) == 0){
	    name_response.labelcolor(FL_RED);
	    name_response.label("Needs Name");
	    valid = false;
	}
 	if(!isInt(SN.value())){
	    sn_response.labelcolor(FL_RED);
	    sn_response.label("Needs Integer");
	    valid = false;
	}	
	else if(storage.checkBatteries(atoi(SN.value()))){
	    sn_response.labelcolor(FL_RED);
	    sn_response.label("SN in use");
	    valid = false;
	}
	else{
	    sn_response.label("");
	    isn = atoi(cost.value());
	}
 	if(!isDouble(cost.value())){
	    cost_response.labelcolor(FL_RED);
	    cost_response.label("Needs Double");
	    valid = false;
	}	
	else{
	    cost_response.label("");
	    icost = atof(cost.value());
	}
 	if(!isDouble(weight.value())){
	    weight_response.labelcolor(FL_RED);
	    weight_response.label("Needs Double");
	    valid = false;
	}	
	else{
	    weight_response.label("");
	    iweight = atof(weight.value());
	}	
 	if(!isDouble(charge.value())){
	    charge_response.labelcolor(FL_RED);
	    charge_response.label("Needs Double");
	    valid = false;
	}	
	else{
	    charge_response.label("");
	    icharge = atof(charge.value());
	}
	if(strlen(description.value()) == 0){	
	    description_response.labelcolor(FL_RED);
	    description_response.label("Needs Description");
	    valid = false;
	}
	if(valid){
	    Battery battery(name.value(), isn, iweight, icost, description.value(), icharge);
	    storage.addBattery(battery);	    
	    storage.store();
	    this->hide();
	}
    }
    static void create_clicked(Fl_Widget*w, void*data){
	((gui_battery*)data)->create_clicked_i();
    }

    //callback combo to make the window close
    inline void cancel_clicked_i(){
	this->hide();
    }
    static void cancel_clicked(Fl_Widget*w, void*data){
	((gui_battery*)data)->cancel_clicked_i();
    }



    public:
	gui_battery() :
	Fl_Window(400, 325, "RoboPart Battery Construction"),
	name(150,5,100,25, "Name"),
	SN(150,35,100,25, "SN"),
	cost(150,65,100,25, "Cost (USD)"),
	weight(150,95,100,25, "Weight (KG)"),
	charge(150,125,100,25, "Active Draw (KW)"),
	description(150,155,175,125,"Description"),
	cancel(295, 295, 100, 25, "Cancel"),
	create(190, 295, 100, 25, "Create"),
	name_response(255, 5, 115, 25),
	sn_response(255, 35,115,25),
	cost_response(255, 65, 115, 25),
	weight_response(255, 95,115,25),
	charge_response(255, 125, 115, 25),
	description_response(5, 155, 140, 25){
	    cancel.callback(cancel_clicked,this);
	    create.callback(create_clicked,this);
	}

        void clear_fields(){
	    name.value("");
	    SN.value("");
	    cost.value("");
	    weight.value("");
	    description.value("");
	    charge.value("");
	    sn_response.label("");
	    cost_response.label("");
	    charge_response.label("");
	    name_response.label("");
	    description_response.label("");
	}
};
#endif
