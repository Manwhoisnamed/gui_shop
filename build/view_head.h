//maxwell Sanders 1001069652
//this is the file to view the head

#include <Fl/Fl.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Multiline_Output.H>
#include "globals.h"

#ifndef __view_head_H
#define __view_head_H 2016
class view_head : public Fl_Group{
	Fl_Button refresh;
	Fl_Button up;
	Fl_Button down;
	Fl_Multiline_Output description;
	Fl_Output name;
	Fl_Output SN;
	Fl_Output draw;
	Fl_Output cost;
	Fl_Output weight;
	Fl_Box laser;
	Fl_Box part;
	Fl_Choice SN_choice;
	int size = 0;
	int i = 0;

	void initialize_choices(){
	    size = storage.headSize();
	    for(int x = 0; x < size; x ++){
		SN_choice.add((storage.getHead(x).getName() + " - " + to_string(storage.getHead(x).getSN())).c_str());
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
	    ((view_head*)data)->select_i();
	}
	
	void popfields(){
	    string sSN;
	    string scost;
	    string sweight;
	    string sdraw;
	    
	    name.value((storage.getHead(i)).getName().c_str());
	    description.value((storage.getHead(i)).getDescription().c_str());
	    sSN = to_string(storage.getHead(i).getSN());
	    scost = to_string(storage.getHead(i).getCost());
	    sweight = to_string(storage.getHead(i).getWeight());
	    sdraw = to_string(storage.getHead(i).getDraw());
	    SN.value(sSN.c_str());
	    cost.value(scost.c_str());
	    weight.value(sweight.c_str());
	    draw.value(sdraw.c_str());
	    if(storage.getHead(i).getLaser()){
	        laser.label("***LASER EQUIPPED***");
	    }
	    else{
	        laser.label("");
	    }
	}

	inline void down_clicked_i(){
	    i++;
	    SN_choice.value(i);
	    if(i == storage.headSize() - 1){
		down.deactivate();
	    }
	    up.activate();
	    popfields();
	};
	static void down_clicked(Fl_Widget* w, void* data){
	    ((view_head*)data)->down_clicked_i();
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
	    ((view_head*)data)->up_clicked_i();
	};

	//for the refresh button, if someone builds a part and the down is deactivate then this will fix it
        inline void refresh_clicked_i(){
	    if(storage.headSize() > i + 1){
		down.activate();
	    }
	    if(size < storage.headSize()){
		for(int x = size; x < storage.headSize(); x++){
		    SN_choice.add((storage.getHead(x).getName() + " - " + to_string(storage.getHead(x).getSN())).c_str());
		}
	    }
	};
	static void refresh_clicked(Fl_Widget* w, void* data){
	    ((view_head*)data)->refresh_clicked_i();
	};

    public:
	view_head():
	Fl_Group(0,0,1000,700),
	refresh(105, 40, 175, 25, "Refresh"),
	up(105,70,175,25,"@8>"),
	down(105, 130, 175, 25, "@2>"),
	name(400, 100, 200, 25, "Name"),
	SN(400, 130, 200, 25, "SN"),
	cost(400, 160, 200, 25, "Cost (USD)"),
	weight(400, 190, 200, 25, "Weight (KG)"),
	draw(400,220, 200, 25, "Draw (KW)"),
	laser(400, 250, 200, 25, ""),	
	description(400, 280, 250, 150, "Description"),
	part(450, 30, 100, 25, "Viewing Heads"),
	SN_choice(105, 100, 175, 25, "Part Selector"){
	    reset_values();
	    laser.labelcolor(FL_RED);
	    up.deactivate();
	    up.callback(up_clicked,this);
	    down.callback(down_clicked,this);
	    if(storage.headSize() == 1){
	        down.deactivate();
	    }
	    refresh.callback(refresh_clicked, this);
	    initialize_choices();
	    SN_choice.callback(select, this);
	}

	void reset_values(){
	    i = 0;
	    SN_choice.value(0);
	    up.deactivate();
	    if(storage.headSize() == 1){
	        down.deactivate();
	    }
	    if(storage.headSize() > 0){
		popfields();
	    }
	    else{
	 	name.value("");
	 	SN.value("");
	 	cost.value("");
	 	weight.value("");
	 	draw.value("");
	 	laser.label("");
		description.value("There are no heads in storage.");
	    }
	}
};
#endif
