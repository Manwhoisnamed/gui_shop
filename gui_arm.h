//maxwell sanders 1001069652
//This is the gui file for a group that will have the basics necessary for an arm

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

#ifndef __gui_arm_H
#define __gui_arm_H 2016
class gui_arm : public Fl_Window{
    Fl_Input name;
    Fl_Input SN;
    Fl_Input cost;
    Fl_Input weight;
    Fl_Input activeDraw;
    Fl_Input passiveDraw;
    Fl_Box sn_response;
    Fl_Box cost_response;
    Fl_Box weight_response;
    Fl_Box active_response;
    Fl_Box passive_response;
    Fl_Box name_response;
    Fl_Box description_response;
    Fl_Check_Button laser;
    Fl_Multiline_Input description;
    Fl_Button cancel;
    Fl_Button create;    

    //callback combo to make the window close
    inline void create_clicked_i(){
	bool valid = true;
	int isn;
	double iweight, icost, pass, act;
	bool ilaser = false;
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
	else{
	    sn_response.label("");
	    isn = atoi(SN.value());
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
 	if(!isDouble(passiveDraw.value())){
	    passive_response.labelcolor(FL_RED);
	    passive_response.label("Needs Double");
	    valid = false;
	}	
	else{
	    passive_response.label("");
	    pass = atof(passiveDraw.value());
	}	
 	if(!isDouble(activeDraw.value())){
	    active_response.labelcolor(FL_RED);
	    active_response.label("Needs Double");
	    valid = false;
	}	
	else{
	    active_response.label("");
	    act = atof(activeDraw.value());
	}
	if(strlen(description.value()) == 0){	
	    description_response.labelcolor(FL_RED);
	    description_response.label("Needs Description");
	    valid = false;
	}
	if(laser.value() == 1){
	    ilaser = true;
	}
	if(valid){
	    Arm arm(name.value(), isn, iweight, icost, description.value(), pass, act, ilaser);
	    storage.addArm(arm);	    
	    storage.store();
	    this->hide();
	}
    }
    static void create_clicked(Fl_Widget*w, void*data){
	((gui_arm*)data)->create_clicked_i();
    }

    //callback combo to make the window close
    inline void cancel_clicked_i(){
	this->hide();
    }
    static void cancel_clicked(Fl_Widget*w, void*data){
	((gui_arm*)data)->cancel_clicked_i();
    }



    public:
	gui_arm() :
	Fl_Window(400, 385, "RoboPart Arm Construction"),
	name(150,5,100,25, "Name"),
	SN(150,35,100,25, "SN"),
	cost(150,65,100,25, "Cost (USD)"),
	weight(150,95,100,25, "Weight (KG)"),
	activeDraw(150,125,100,25, "Active Draw (KW)"),
	passiveDraw(150,155,100,25, "Passive Draw (KW)"),
	laser(150,185,100,25,"Laser"),
	description(150,215,175,125,"Description"),
	cancel(295, 355, 100, 25, "Cancel"),
	create(190, 355, 100, 25, "Create"),
	name_response(255, 5, 115, 25),
	sn_response(255, 35,115,25),
	cost_response(255, 65, 115, 25),
	weight_response(255, 95,115,25),
	active_response(255, 125, 115, 25),
	passive_response(255, 155,115,25),
	description_response(5, 215, 140, 25){
	    cancel.callback(cancel_clicked,this);
	    create.callback(create_clicked,this);
	    laser.type(FL_TOGGLE_BUTTON);
	}

        void clear_fields(){
	    name.value("");
	    SN.value("");
	    cost.value("");
	    weight.value("");
	    description.value("");
	    activeDraw.value("");
	    passiveDraw.value("");
	    laser.value(0);
	    sn_response.label("");
	    cost_response.label("");
	    passive_response.label("");
	    active_response.label("");
	    name_response.label("");
	    description_response.label("");
	}
};
#endif
