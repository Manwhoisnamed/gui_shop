//maxwell sanders 1001069652
//this is the gui window to create the robopart

#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>

#ifndef __gui_model_H
#define __gui_model_H 2016

class gui_model: public Fl_Window{

    Fl_Button refresh;
    Fl_Output torso_name;
    Fl_Output head_name;
    Fl_Output leg_name;
    Fl_Output arm1_name;
    Fl_Output arm2_name;
    Fl_Output bat1_name;
    Fl_Output bat2_name;
    Fl_Output bat3_name;
    Fl_Box name_header;
    Fl_Box pin_header;
    Fl_Box pin_model;

    public:
	gui_model():
	Fl_Window(1000, 500),
	refresh(5,5,100,25,"Refresh"),
	torso_name(110,35,125,25, "Torso"),
	head_name(110,65,125,25, "Head"),
	leg_name(110,95,125,25, "Leg"),
	arm1_name(110,125,125,25, "Arm 1"),
	arm2_name(110,155,125,25, "Arm 2"),
	bat1_name(110,185,125,25, "Battery 1"),
	bat2_name(110,215,125,25, "Battery 2"),
	bat3_name(110,245,125,25, "Battery 3"),
	name_header(110,5,125,25, "Name"),
	pin_header(215,5,125,25, "Pin"),
	pin_model(320, 5, 5, 500,""){
	    pin_model.box(FL_UP_BOX);
	    pin_model.color(FL_BLACK);
	}
		
};
#endif
