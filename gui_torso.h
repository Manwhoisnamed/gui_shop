//maxwell sanders 1001069652
//This is the gui file for a group that will have the basics necessary for a torso

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Menu_Item.H>
#include <Fl/Fl_Group.H>

#ifndef __gui_torso_H
#define __gui_torso_H 2016
class gui_torso : public Fl_Window{
    
    public:
	gui_torso() :
	Fl_Window(350, 500, "RoboPart Torso Construction"){
	}

};
#endif
