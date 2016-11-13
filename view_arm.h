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
	Fl_Button refresh;
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
	int i = 0;

	inline void right_clicked_i(){
	    i++;
	    if(i == storage.armSize() - 1){
		right.deactivate();
	    }
	    else{
		left.activate();
	    }
	    string sSN;
	    string scost;
	    string sweight;
	    string spassiveDraw;
	    string sactiveDraw;
	    
	    name.value((storage.getArm(i)).getName().c_str());
	    description.value((storage.getArm(i)).getDescription().c_str());
	    sSN = to_string(storage.getArm(i).getSN());
	    scost = to_string(storage.getArm(i).getCost());
	    sweight = to_string(storage.getArm(i).getWeight());
	    spassiveDraw = to_string(storage.getArm(i).getpassiveDraw());
	    sactiveDraw = to_string(storage.getArm(i).getactiveDraw());
	    SN.value(sSN.c_str());
	    cost.value(scost.c_str());
	    weight.value(sweight.c_str());
	    passiveDraw.value(spassiveDraw.c_str());
	    activeDraw.value(sactiveDraw.c_str());
	    if(storage.getArm(i).getLaser()){
	        laser.label("***LASER EQUIPPED***");
	    }
	    else{
	        laser.label("");
	    }
	};
	static void right_clicked(Fl_Widget* w, void* data){
	    ((view_arm*)data)->right_clicked_i();
	};

	inline void left_clicked_i(){
	    i--;
	    if(i == 0){
		left.deactivate();
	    }
	    else{
		right.activate();
	    }
	    string sSN;
	    string scost;
	    string sweight;
	    string spassiveDraw;
	    string sactiveDraw;
	    
	    name.value((storage.getArm(i)).getName().c_str());
	    description.value((storage.getArm(i)).getDescription().c_str());
	    sSN = to_string(storage.getArm(i).getSN());
	    scost = to_string(storage.getArm(i).getCost());
	    sweight = to_string(storage.getArm(i).getWeight());
	    spassiveDraw = to_string(storage.getArm(i).getpassiveDraw());
	    sactiveDraw = to_string(storage.getArm(i).getactiveDraw());
	    SN.value(sSN.c_str());
	    cost.value(scost.c_str());
	    weight.value(sweight.c_str());
	    passiveDraw.value(spassiveDraw.c_str());
	    activeDraw.value(sactiveDraw.c_str());
	    if(storage.getArm(i).getLaser()){
	        laser.label("***LASER EQUIPPED***");
	    }
	    else{
	        laser.label("");
	    }
	};
	static void left_clicked(Fl_Widget* w, void* data){
	    ((view_arm*)data)->left_clicked_i();
	};

	//for the refresh button, if someone builds a part and the right is deactivate then this will fix it
        inline void refresh_clicked_i(){
	    if(storage.armSize() > i + 1){
		right.activate();
	    }
	};
	static void refresh_clicked(Fl_Widget* w, void* data){
	    ((view_arm*)data)->refresh_clicked_i();
	};

    public:
	view_arm():
	Fl_Group(0,0,1000,700),
	refresh(5, 60, 100, 25, "Refresh"),
	left(5,30,100,25,"Left"),
	right(110, 30, 100, 25, "Right"),
	name(400, 100, 200, 25, "Name"),
	SN(400, 130, 200, 25, "SN"),
	cost(400, 160, 200, 25, "Cost (USD)"),
	weight(400, 190, 200, 25, "Weight (KG)"),
	activeDraw(400, 220, 200, 25, "Active Draw (KW)"),
	passiveDraw(400, 250, 200, 25, "Passive Draw (KW)"),
	laser(400, 280, 200, 25, ""),	
	description(400, 310, 250, 150, "Description"){
	    reset_values();
	    laser.labelcolor(FL_RED);
	    left.deactivate();
	    left.callback(left_clicked,this);
	    right.callback(right_clicked,this);
	    if(storage.armSize() == 1){
	        right.deactivate();
	    }
	    refresh.callback(refresh_clicked, this);
	}

	void reset_values(){
	    i = 0;
	    left.deactivate();
	    if(storage.armSize() == 1){
	        right.deactivate();
	    }
	    string sSN;
	    string scost;
	    string sweight;
	    string spassiveDraw;
	    string sactiveDraw;
	    if(storage.armSize() > 0){
	 	name.value((storage.getArm(i)).getName().c_str());
	 	description.value((storage.getArm(i)).getDescription().c_str());
		sSN = to_string(storage.getArm(i).getSN());
		scost = to_string(storage.getArm(i).getCost());
		sweight = to_string(storage.getArm(i).getWeight());
		spassiveDraw = to_string(storage.getArm(i).getpassiveDraw());
		sactiveDraw = to_string(storage.getArm(i).getactiveDraw());
		SN.value(sSN.c_str());
		cost.value(scost.c_str());
		weight.value(sweight.c_str());
		passiveDraw.value(spassiveDraw.c_str());
		activeDraw.value(sactiveDraw.c_str());
	 	if(storage.getArm(i).getLaser()){
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
