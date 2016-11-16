//maxwell Sanders 1001069652
//this is the file to view the arm

#include <Fl/Fl.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Multiline_Output.H>
#include <Fl/Fl_Menu_Item.H>
#include "globals.h"

#ifndef __view_arm_H
#define __view_arm_H 2016
class view_arm : public Fl_Group{
	Fl_Button refresh;
	Fl_Button up;
	Fl_Button down;
	Fl_Multiline_Output description;
	Fl_Output name;
	Fl_Output SN;
	Fl_Output activeDraw;
	Fl_Output passiveDraw;
	Fl_Output cost;
	Fl_Output weight;
	Fl_Box laser;
	Fl_Box part;
	Fl_Choice SN_choice;
	Fl_Menu_Item choices[10000];
	int size = 0;
	int i = 0;

	void initialize_choices(){
	    size = storage.armSize();
	    for(int x = 0; x < size; x ++){
		SN_choice.add((storage.getArm(x).getName() + " - " + to_string(storage.getArm(x).getSN())).c_str());
	    }
	}

	inline void select_i(){
	    i = SN_choice.value();
	    if(i == 0){
		up.deactivate();
	    }
	    else{
		up.activate();
	    }
	    if(i == size - 1){
		down.deactivate();
	    }	
	    else{
		down.activate();
	    }
	    popfields();
	}
	static void select(Fl_Widget* w, void * data){
	    ((view_arm*)data)->select_i();
	}

	void popfields(){
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
	}

	inline void down_clicked_i(){
	    i++;
	    SN_choice.value(i);
	    if(i == storage.armSize() - 1){
		down.deactivate();
	    }
	    up.activate();
	    popfields();
	};
	static void down_clicked(Fl_Widget* w, void* data){
	    ((view_arm*)data)->down_clicked_i();
	};

	inline void up_clicked_i(){
	    i--;
	    SN_choice.value(i);
	    if(i == 0){
		up.deactivate();
	    }
	    down.activate();
	    popfields();
	};
	static void up_clicked(Fl_Widget* w, void* data){
	    ((view_arm*)data)->up_clicked_i();
	};

	//for the refresh button, if someone builds a part and the down is deactivate then this will fix it
        inline void refresh_clicked_i(){
	    if(storage.armSize() > i + 1){
		down.activate();
	    }
	    if(size < storage.armSize()){
		for(int x = size; x < storage.armSize(); x++){
		    SN_choice.add((storage.getArm(x).getName() + " - " + to_string(storage.getArm(x).getSN())).c_str());
		}
	    }
	};
	static void refresh_clicked(Fl_Widget* w, void* data){
	    ((view_arm*)data)->refresh_clicked_i();
	};

    public:
	view_arm():
	Fl_Group(0,0,1000,700),
	refresh(105, 40, 175, 25, "Refresh"),
	up(105,70,175,25,"@8>"),
	down(105, 130, 175, 25, "@2>"),
	name(400, 100, 200, 25, "Name"),
	SN(400, 130, 200, 25, "SN"),
	cost(400, 160, 200, 25, "Cost (USD)"),
	weight(400, 190, 200, 25, "Weight (KG)"),
	activeDraw(400, 220, 200, 25, "Active Draw (KW)"),
	passiveDraw(400, 250, 200, 25, "Passive Draw (KW)"),
	laser(400, 280, 200, 25, ""),	
	description(400, 310, 250, 150, "Description"),
	part(450, 30, 100, 25, "Viewing Arms"),
	SN_choice(105, 100, 175, 25, "Part Selector"){
	    reset_values();
	    laser.labelcolor(FL_RED);
	    up.deactivate();
	    up.callback(up_clicked,this);
	    down.callback(down_clicked,this);
	    if(storage.armSize() == 1){
	        down.deactivate();
	    }
	    refresh.callback(refresh_clicked, this);
	    initialize_choices();
	    SN_choice.callback(select, this);
	}

	void reset_values(){
	    i=0;
	    SN_choice.value(0);
	    up.deactivate();
	    if(storage.armSize() > 0){
		popfields();
	    }
	    else{
		down.deactivate();
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
