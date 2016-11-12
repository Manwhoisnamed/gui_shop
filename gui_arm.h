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
    Fl_Check_Button laser;
    Fl_Multiline_Input description;
    Fl_Button cancel;
    Fl_Button create;    

    //callback combo to make the window close
    inline void create_clicked_i(){
	bool valid = true;
 	if(!isInt(SN.value())){
	    sn_response.labelcolor(FL_RED);
	    sn_response.label("Needs Integer");
	    valid = false;
	}	
	else{
	    sn_response.label("");
	}
 	if(!isDouble(cost.value())){
	    cost_response.labelcolor(FL_RED);
	    cost_response.label("Needs Double");
	    valid = false;
	}	
	else{
	    cost_response.label("");
	}
	if(valid){
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
	name(150,5,150,25, "Name"),
	SN(150,35,100,25, "SN"),
	cost(150,65,100,25, "Cost (USD)"),
	weight(150,95,100,25, "Weight (KG)"),
	activeDraw(150,125,100,25, "Passive Draw (KW)"),
	passiveDraw(150,155,100,25, "Passive Draw (KW)"),
	laser(150,185,100,25,"Laser"),
	description(150,215,200,125,"Description"),
	cancel(295, 355, 100, 25, "Cancel"),
	create(190, 355, 100, 25, "Create"),
	sn_response(255, 35,115,25),
	cost_response(255, 65, 115, 25){
	    cancel.callback(cancel_clicked,this);
	    create.callback(create_clicked,this);
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
	}
};
#endif
