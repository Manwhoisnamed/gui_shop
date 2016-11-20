//maxwell Sanders 1001069652
//this class will be the boss' portal to do things

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

#ifndef __boss_H
#define __boss_H 2016
class boss : public Fl_Window{
    Fl_Button logout;   
    Fl_Menu_Bar menu;
    Fl_Menu_Item commands[20] = {
	{"&Business",FL_ALT+'b', 0, 0, FL_SUBMENU},
	{"View &Catalogue",FL_ALT+'c', 0, 0},
	{"&View all orders",FL_ALT+'v', 0, 0},
	{0},
	{"&Customers",FL_ALT+'c', 0, 0, FL_SUBMENU},	
	{"&Create Customer",FL_ALT+'c', 0, 0},
	{"&View all Customers", FL_ALT + 'v', 0, 0},
	{"View &Orders by Customer",FL_ALT+'o', 0, 0},
	{"&Adjust Credentials", FL_ALT + 'a', 0, 0},
	{0},
	{"&Sales Associates",FL_ALT+'s', 0, 0, FL_SUBMENU},	
	{"&Create Associate",FL_ALT+'c', 0, 0},
	{"&View all Associates", FL_ALT + 'v', 0, 0},
	{"View &Orders by Associates",FL_ALT+'o', 0, 0},
	{"&Adjust Pay", FL_ALT + 'a', 0, 0},
	{0},
	{0},
    };
    inline void logout_clicked_i(){
	this->hide();
	((this->parent())->child(0))->show();
    }
    static void logout_clicked(Fl_Widget*w, void*data){
	((boss*)data)->logout_clicked_i();
    }

  public:
	boss() :
	Fl_Window(1000,700),
	logout(910,660,80,30, "Logout"),
	menu(0,0,1000,20){
	    menu.menu(commands);
	    logout.callback(logout_clicked, this);
        };
};
#endif