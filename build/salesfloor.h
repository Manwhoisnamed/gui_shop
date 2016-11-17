//maxwell Sanders 1001069652
//This is the class for the customer side of the salesfloor window, which will open the customer windows

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Menu_Item.H>
#include <Fl/Fl_Choice.H>
#include <Fl/Fl_Menu.H>
#include <Fl/Fl_Menu_Bar.H>
#include "globals.h"

#ifndef __salesfloor_H
#define __salesfloor_H 2016
class salesfloor : public Fl_Window{
    Fl_Button logout;   
    Fl_Menu_Bar menu;
    Fl_Menu_Item commands[14] = {
	{"&Info",FL_ALT+'c', 0, 0, FL_SUBMENU},
	{"&Update My Info",FL_ALT+'u', 0, 0},
	{"&View Catalogue",FL_ALT+'v', 0, 0},
	{0},
	{"&Orders",FL_ALT+'o', 0, 0, FL_SUBMENU},	
	{"&Create Order",FL_ALT+'c', 0, 0},
	{"View &My Orders",FL_ALT+'m', 0, 0},
	{"&View Catalogue",FL_ALT+'v', 0, 0},
	{0},
	{0},
    };
    inline void logout_clicked_i(){
	this->hide();
	((this->parent())->child(0))->show();
    }
    static void logout_clicked(Fl_Widget*w, void*data){
	((salesfloor*)data)->logout_clicked_i();
    }

  public:
	salesfloor() :
	Fl_Window(1000,700),
	logout(910,660,80,30, "Logout"),
	menu(0,0,1000,20){
	    menu.menu(commands);
	    logout.callback(logout_clicked, this);
        };
};
#endif
