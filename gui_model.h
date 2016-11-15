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
    Fl_Choice torso_pin;
    Fl_Choice head_pin;
    Fl_Choice leg_pin;
    Fl_Choice arm1_pin;
    Fl_Choice arm2_pin;
    Fl_Choice bat1_pin;
    Fl_Choice bat2_pin;
    Fl_Choice bat3_pin;
    Fl_Output bspace;
    Fl_Output speed;
    Fl_Output life;
    Fl_Output cost;
    Fl_Output weight;
    Fl_Box name_header;
    Fl_Box pin_header;
    Fl_Box stats_header;
    Fl_Box div1;
    Fl_Box div2;
    Fl_Box div3;

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
	torso_pin(240,35,125,25, ""),
	head_pin(240,65,125,25, ""),
	leg_pin(240,95,125,25, ""),
	arm1_pin(240,125,125,25, ""),
	arm2_pin(240,155,125,25, ""),
	bat1_pin(240,185,125,25, ""),
	bat2_pin(240,215,125,25, ""),
	bat3_pin(240,245,125,25, ""),
	name_header(110,5,125,25, "Name"),
	pin_header(240,5,125,25, "Pin"),
	stats_header(455,5,125,25, "Stats"),
	div1(370, 5, 5, 270, ""),
	div2(580, 5, 5, 270, ""),
	div3(5, 275, 580, 5, ""),
	bspace(480, 35, 100,25, "Battery Space"),
	speed(480,65,100,25,"Speed (Km)"),
	


	life(480,185,100,25,"Life (Hr)"),
	cost(480,215,100,25,"Cost (USD)"),
	weight(480,245,100,25,"Weight (Kg)"){
	    div1.box(FL_UP_BOX);
	    div1.color(FL_BLACK);
	    div2.box(FL_UP_BOX);
	    div2.color(FL_BLACK);
	    div3.box(FL_UP_BOX);
	    div3.color(FL_BLACK);

	}
		
};
#endif
