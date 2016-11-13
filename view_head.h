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
	Fl_Button left;
	Fl_Button right;
	Fl_Multiline_Output description;
	Fl_Output name;
	Fl_Output SN;
	Fl_Output draw;
	Fl_Output cost;
	Fl_Output weight;
	Fl_Box laser;
	Fl_Box part;
	int i = 0;

	inline void right_clicked_i(){
	    i++;
	    if(i == storage.headSize() - 1){
		right.deactivate();
	    }
	    left.activate();
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
	};
	static void right_clicked(Fl_Widget* w, void* data){
	    ((view_head*)data)->right_clicked_i();
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
	};
	static void left_clicked(Fl_Widget* w, void* data){
	    ((view_head*)data)->left_clicked_i();
	};

	//for the refresh button, if someone builds a part and the right is deactivate then this will fix it
        inline void refresh_clicked_i(){
	    if(storage.headSize() > i + 1){
		right.activate();
	    }
	};
	static void refresh_clicked(Fl_Widget* w, void* data){
	    ((view_head*)data)->refresh_clicked_i();
	};

    public:
	view_head():
	Fl_Group(0,0,1000,700),
	refresh(5, 60, 100, 25, "Refresh"),
	left(5,30,100,25,"Left"),
	right(110, 30, 100, 25, "Right"),
	name(400, 100, 200, 25, "Name"),
	SN(400, 130, 200, 25, "SN"),
	cost(400, 160, 200, 25, "Cost (USD)"),
	weight(400, 190, 200, 25, "Weight (KG)"),
	draw(400,220, 200, 25, "Draw (KW)"),
	laser(400, 250, 200, 25, ""),	
	description(400, 280, 250, 150, "Description"),
	part(450, 30, 100, 25, "Viewing Heads"){
	    reset_values();
	    laser.labelcolor(FL_RED);
	    left.deactivate();
	    left.callback(left_clicked,this);
	    right.callback(right_clicked,this);
	    if(storage.headSize() == 1){
	        right.deactivate();
	    }
	    refresh.callback(refresh_clicked, this);
	}

	void reset_values(){
	    i = 0;
	    left.deactivate();
	    if(storage.headSize() == 1){
	        right.deactivate();
	    }
	    string sSN;
	    string scost;
	    string sweight;
	    string sdraw;
	    if(storage.headSize() > 0){
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
