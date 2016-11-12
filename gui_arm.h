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

#ifndef __gui_arm_H
#define __gui_arm_H 2016
class gui_arm : public Fl_Window{
    Fl_Input name;
    Fl_Input SN;
    Fl_Input cost;
    Fl_Input weight;
    Fl_Input activeDraw;
    Fl_Input passiveDraw;
    Fl_Check_Button laser;
    Fl_Multiline_Input description;
    Fl_Button cancel;
    Fl_Button create;    

    //callback combo to make a gui leg window
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
	create(190, 355, 100, 25, "Create"){
		cancel.callback(cancel_clicked,this);
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
	}
};
#endif
