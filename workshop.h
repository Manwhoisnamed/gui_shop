//maxwell Sanders 1001069652
//This is the class for the workshop window, which will open the part making windows

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
#include "gui_arm.h"
#include "gui_leg.h"
#include "gui_head.h"
#include "gui_battery.h"
#include "gui_torso.h"
#include "view_arm.h"
#include "view_leg.h"

#ifndef __workshop_H
#define __workshop_H 2016
class workshop : public Fl_Window{
    Fl_Button logout;   
    Fl_Menu_Bar menu;
    gui_arm arm_win;
    gui_leg leg_win;
    gui_head head_win;
    gui_battery battery_win;
    gui_torso torso_win;
    view_arm arm_view;
    view_leg leg_view;
    Fl_Menu_Item manage[21] = {
	{"&Workshop",FL_ALT+'w', 0, 0, FL_SUBMENU},
	{"Create &Arm",FL_ALT+'a', make_gui_arm, this},
	{"Create &Battery",FL_ALT+'b', make_gui_battery, this},
	{"Create &Head",FL_ALT+'h', make_gui_head, this},
	{"Create &Leg",FL_ALT+'l', make_gui_leg, this},
	{"Create &Torso",FL_ALT+'t', make_gui_torso, this, FL_MENU_DIVIDER},
	{"Create &RoboModel",FL_ALT+'r', 0, 0},
	{0},
	{"&Storage",FL_ALT+'s', 0, 0, FL_SUBMENU},	
	{"View &Arm",FL_ALT+'a', view_arm_view, this},
	{"View &Battery",FL_ALT+'b', 0, 0},
	{"View &Head",FL_ALT+'h', 0, 0},
	{"View &Leg",FL_ALT+'l', view_leg_view, this},
	{"View &Torso",FL_ALT+'t', 0, 0, FL_MENU_DIVIDER},
	{"View &RoboModel",FL_ALT+'r', 0, 0},
	{0},
	{"&Help",FL_ALT+'h', 0, 0, FL_SUBMENU},	
	{"Stop &Viewing",FL_ALT+'v', hide_all, this},
	{"Change &Pin",FL_ALT+'p', 0, 0},	
	{0},
	{0}
    };

    //callback combo for the view leg button
    inline void view_leg_view_i(){
	hide_all_i();
	leg_view.reset_values();
	leg_view.show();
    }
    static void view_leg_view(Fl_Widget*w, void*data){
	((workshop*)data)->view_leg_view_i();
    }

    //callback combo for the view arm button
    inline void view_arm_view_i(){
	hide_all_i();
	arm_view.reset_values();
	arm_view.show();
    }
    static void view_arm_view(Fl_Widget*w, void*data){
	((workshop*)data)->view_arm_view_i();
    }

    //callback combo for the hide all button
    inline void hide_all_i(){
	arm_view.hide();
	leg_view.hide();
    }
    static void hide_all(Fl_Widget*w, void*data){
	((workshop*)data)->hide_all_i();
    }

    //callback combo for the logout button
    inline void logout_clicked_i(){
	this->hide();
	((this->parent())->child(0))->show();
    }
    static void logout_clicked(Fl_Widget*w, void*data){
	((workshop*)data)->logout_clicked_i();
    }

    //callback combo to make a gui leg window
    inline void make_gui_leg_i(){
	leg_win.show();
    }
    static void make_gui_leg(Fl_Widget*w, void*data){
	((workshop*)data)->make_gui_leg_i();
    }

    //callback combo to make a gui battery
    inline void make_gui_battery_i(){
	battery_win.show();
    }
    static void make_gui_battery(Fl_Widget*w, void*data){
	((workshop*)data)->make_gui_battery_i();
    }

    //callback combo to make a gui head
    inline void make_gui_head_i(){
	head_win.show();
    }
    static void make_gui_head(Fl_Widget*w, void*data){
	((workshop*)data)->make_gui_head_i();
    }

    //callback combo to make a gui torso
    inline void make_gui_torso_i(){
	torso_win.show();
    }
    static void make_gui_torso(Fl_Widget*w, void*data){
	((workshop*)data)->make_gui_torso_i();
    }

    //callback combo to make a gui arm
    inline void make_gui_arm_i(){
	arm_win.clear_fields();
	arm_win.show();
    }
    static void make_gui_arm(Fl_Widget*w, void*data){
	((workshop*)data)->make_gui_arm_i();
    }

   public:
	workshop() :
	Fl_Window(1000,700),
	logout(910,660,80,30, "Logout"),
	menu(0,0,1000,20){
	    menu.menu(manage);
	    logout.callback(logout_clicked, this);
	    this->add(arm_view);
	    this->add(leg_view);
	    arm_view.hide();
	    leg_view.hide();
        };
};
#endif
