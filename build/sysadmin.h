//maxwell Sanders 1001069652
//this class will be the system admin's portal to do things

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
#include "gui_PMPin.h"
#include "gui_bosspin.h"

#ifndef __sysadmin_H
#define __sysadmin_H 2016
class sysadmin : public Fl_Window{
    Fl_Button logout;   
    Fl_Menu_Bar menu;
    gui_PMPin pmpin_win;
    gui_bosspin boss_win;
    Fl_Menu_Item commands[16] = {
	{"&Maintain System",FL_ALT+'m', 0, 0, FL_SUBMENU},
	{"Change &Boss Pin",FL_ALT+'b', change_boss, this},
	{"Change &Project Manager Pin",FL_ALT+'p', change_pm, this},
	{"View &Customer Pins",FL_ALT+'c', 0, 0},
	{"View &Sales Associate Pins",FL_ALT+'s', 0, 0},
	{0},
	{0},
    };

    //this is the callback combo to change the project manager pin
    inline void change_pm_i(){
	pmpin_win.show();
	pmpin_win.sys_res_vals();
    }
    static void change_pm(Fl_Widget*w, void*data){
	((sysadmin*)data)->change_pm_i();
    }

    //this is the callback combo to change the project manager pin
    inline void change_boss_i(){
	boss_win.sys_res_vals();
	boss_win.show();
    }
    static void change_boss(Fl_Widget*w, void*data){
	((sysadmin*)data)->change_boss_i();
    }


    //this is the callback combo to logout of the sstem admin window
    inline void logout_clicked_i(){
	this->hide();
	boss_win.hide();
	pmpin_win.hide();
	((this->parent())->child(0))->show();
    }
    static void logout_clicked(Fl_Widget*w, void*data){
	((sysadmin*)data)->logout_clicked_i();
    }

  public:
	sysadmin() :
	Fl_Window(1000,700),
	logout(910,660,80,30, "Logout"),
	menu(0,0,1000,20){
	    menu.menu(commands);
	    logout.callback(logout_clicked, this);
        };
};
#endif
