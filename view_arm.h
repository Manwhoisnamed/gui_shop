//maxwell Sanders 1001069652
//this is the file to view the arm

#include <Fl/Fl.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Multiline_Output.H>
#include "globals.h"

#ifndef __view_arm_H
#define __view_arm_H 2016
class view_arm : public Fl_Group{
	//Fl_Button refresh;
	Fl_Button left;
	Fl_Button right;
	Fl_Multiline_Output description;
	Fl_Output name;
	Fl_Output SN;
	Fl_Output activeDraw;
	Fl_Output passiveDraw;
	Fl_Output cost;
	Fl_Output weight;
	Fl_Box laser;
    public:
	view_arm():
	Fl_Group(0,0,1000,700),
	left(5,30,100,25,"Left"),
	right(110, 30, 100, 25, "Right"),
	name(250, 100, 100, 25, "Name"),
	SN(250, 130, 100, 25, "SN"),
	cost(250, 160, 100, 25, "Cost (USD)"),
	weight(250, 190, 100, 25, "Weight (KG)"),
	activeDraw(250, 220, 100, 25, "Passive Draw (KW)"),
	passiveDraw(250, 250, 100, 25, "Weight (KW)"),
	laser(250, 280, 125, 25, ""),	
	description(250, 310, 250, 150, "Description"){
	}
};
#endif
