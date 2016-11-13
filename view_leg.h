//maxwell Sanders 1001069652
//this is the file to view the leg

#include <Fl/Fl.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Multiline_Output.H>
#include "globals.h"

#ifndef __view_leg_H
#define __view_leg_H 2016
class view_leg : public Fl_Group{
	Fl_Box part;
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
	Fl_Output speed;
	int i = 0;

	inline void right_clicked_i(){
	    i++;
	    if(i == storage.legSize() - 1){
		right.deactivate();
	    }
	    left.activate();
	    string sSN;
	    string scost;
	    string sweight;
	    string spassiveDraw;
	    string sactiveDraw;
	    string sspeed;
	    
	    name.value((storage.getLeg(i)).getName().c_str());
	    description.value((storage.getLeg(i)).getDescription().c_str());
	    sSN = to_string(storage.getLeg(i).getSN());
	    scost = to_string(storage.getLeg(i).getCost());
	    sweight = to_string(storage.getLeg(i).getWeight());
	    spassiveDraw = to_string(storage.getLeg(i).getpassiveDraw());
	    sactiveDraw = to_string(storage.getLeg(i).getactiveDraw());
	    sspeed = to_string(storage.getLeg(i).getSpeed());
	    SN.value(sSN.c_str());
	    cost.value(scost.c_str());
	    weight.value(sweight.c_str());
	    passiveDraw.value(spassiveDraw.c_str());
	    activeDraw.value(sactiveDraw.c_str());
	    speed.value(sspeed.c_str());
	};
	static void right_clicked(Fl_Widget* w, void* data){
	    ((view_leg*)data)->right_clicked_i();
	};

	inline void left_clicked_i(){
	    i--;
	    if(i == 0){
		left.deactivate();
	    }
	    right.activate();
	    string sSN;
	    string scost;
	    string sweight;
	    string spassiveDraw;
	    string sactiveDraw;
	    string sspeed;
	    
	    name.value((storage.getLeg(i)).getName().c_str());
	    description.value((storage.getLeg(i)).getDescription().c_str());
	    sSN = to_string(storage.getLeg(i).getSN());
	    scost = to_string(storage.getLeg(i).getCost());
	    sweight = to_string(storage.getLeg(i).getWeight());
	    spassiveDraw = to_string(storage.getLeg(i).getpassiveDraw());
	    sactiveDraw = to_string(storage.getLeg(i).getactiveDraw());
	    sspeed = to_string(storage.getLeg(i).getSpeed());
	    SN.value(sSN.c_str());
	    cost.value(scost.c_str());
	    weight.value(sweight.c_str());
	    passiveDraw.value(spassiveDraw.c_str());
	    activeDraw.value(sactiveDraw.c_str());
	    speed.value(sspeed.c_str());
	};
	static void left_clicked(Fl_Widget* w, void* data){
	    ((view_leg*)data)->left_clicked_i();
	};

	//for the refresh button, if someone builds a part and the right is deactivate then this will fix it
        inline void refresh_clicked_i(){
	    if(storage.legSize() > i + 1){
		right.activate();
	    }
	};
	static void refresh_clicked(Fl_Widget* w, void* data){
	    ((view_leg*)data)->refresh_clicked_i();
	};

    public:
	view_leg():
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
	speed(400, 280, 200, 25, "Speed (Km)"),	
	description(400, 310, 250, 150, "Description"),
	part(450, 30, 100, 25, "Viewing Legs"){
	    reset_values();
	    left.deactivate();
	    left.callback(left_clicked,this);
	    right.callback(right_clicked,this);
	    if(storage.legSize() == 1){
	        right.deactivate();
	    }
	    refresh.callback(refresh_clicked, this);
	}

	void reset_values(){
	    i = 0;
	    left.deactivate();
	    if(storage.legSize() == 1){
	        right.deactivate();
	    }
	    string sSN;
	    string scost;
	    string sweight;
	    string spassiveDraw;
	    string sactiveDraw;
	    string sspeed;
	    if(storage.legSize() > 0){
	 	name.value((storage.getLeg(i)).getName().c_str());
	 	description.value((storage.getLeg(i)).getDescription().c_str());
		sSN = to_string(storage.getLeg(i).getSN());
		scost = to_string(storage.getLeg(i).getCost());
		sweight = to_string(storage.getLeg(i).getWeight());
		spassiveDraw = to_string(storage.getLeg(i).getpassiveDraw());
		sactiveDraw = to_string(storage.getLeg(i).getactiveDraw());
	        sspeed = to_string(storage.getLeg(i).getSpeed());
		SN.value(sSN.c_str());
		cost.value(scost.c_str());
		weight.value(sweight.c_str());
		passiveDraw.value(spassiveDraw.c_str());
		activeDraw.value(sactiveDraw.c_str());
	 	speed.value(sspeed.c_str());
	    }
	    else{
	 	name.value("");
	 	SN.value("");
	 	cost.value("");
	 	weight.value("");
	 	passiveDraw.value("");
	 	activeDraw.value("");
	 	speed.value("");
		description.value("There are no legs in storage.");
	    }
	}
};
#endif
