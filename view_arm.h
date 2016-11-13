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
	name(400, 100, 200, 25, "Name"),
	SN(400, 130, 200, 25, "SN"),
	cost(400, 160, 200, 25, "Cost (USD)"),
	weight(400, 190, 200, 25, "Weight (KG)"),
	activeDraw(400, 220, 200, 25, "Passive Draw (KW)"),
	passiveDraw(400, 250, 200, 25, "Weight (KW)"),
	laser(400, 280, 200, 25, ""),	
	description(400, 310, 250, 150, "Description"){
	    reset_values();
	    laser.labelcolor(FL_RED);
	}

	void reset_values(){
	    if(storage.armSize() != 0){
	 	name.value((storage.getArm(0)).getName().c_str());
	 	description.value((storage.getArm(0)).getDescription().c_str());
	 	if(storage.getArm(0).getLaser()){
		    laser.label("***LASER EQUIPPED***");
		}
		else{
		    laser.label("");
		}
	    }
	    else{
	 	name.value("");
	 	SN.value("");
	 	cost.value("");
	 	weight.value("");
	 	passiveDraw.value("");
	 	activeDraw.value("");
	 	laser.label("");
		description.value("There are no arms in storage.");
	    }
	}
};
#endif
