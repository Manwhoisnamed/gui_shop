//maxwell sanders 1001069652
//This is the gui file for a group that will have the basics necessary for a battery

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Menu_Item.H>
#include <Fl/Fl_Group.H>

#ifndef __gui_battery_H
#define __gui_battery_H 2016
class gui_battery : public Fl_Window{
    
    public:
	gui_battery() :
	Fl_Window(350, 500, "RoboPart Battery Construction"){
	}

};
#endif
