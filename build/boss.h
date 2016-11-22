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
#include "gui_bosspin.h"
#include "gui_customer.h"
#include "gui_salesman.h"
#include "view_model.h"
#include "view_all_SA.h"
#include "view_all_C.h"

#ifndef __boss_H
#define __boss_H 2016
class boss : public Fl_Window{
    Fl_Button logout;   
    Fl_Menu_Bar menu;
    gui_bosspin pin_changer;
    gui_customer customer_win;
    gui_salesman sales_win;
    view_model model_view;
    view_all_SA allSA_view;
    view_all_C allC_view;
    Fl_Menu_Item commands[30] = {
	{"&Business",FL_ALT+'b', 0, 0, FL_SUBMENU},
	{"View &Catalogue",FL_ALT+'c', view_model_view, this},
	{0},
	{"&Customers",FL_ALT+'c', 0, 0, FL_SUBMENU},	
	{"&Create Customer",FL_ALT+'c', create_customer, this},
	{"&View all Customers", FL_ALT + 'v', view_allC_view, this},
	{0},
	{"&Sales Associates",FL_ALT+'s', 0, 0, FL_SUBMENU},	
	{"&Create Associate",FL_ALT+'c', create_salesman, this},
	{"&View all Associates", FL_ALT + 'v', view_allSA_view, this},
	{0},
	{"&Help",FL_ALT+'h', 0, 0, FL_SUBMENU},	
	{"&Stop Viewing",FL_ALT+'s', hide_all, this},
	{"&Change Pin",FL_ALT+'c', change_pin, this},	
	{0},
    };

    //callback combo to hide_all_windows and groups
    inline void hide_all_i(){
	model_view.hide();
	allSA_view.hide();
	allC_view.hide();
    }
    static void hide_all(Fl_Widget*w, void*data){
	((boss*)data)->hide_all_i();
    }

    //callback combo to create a customer
    inline void create_customer_i(){
	customer_win.reset_vals();
	customer_win.show();
    }
    static void create_customer(Fl_Widget*w, void*data){
	((boss*)data)->create_customer_i();
    }

    //callback combo to create a salesman
    inline void create_salesman_i(){
	sales_win.reset_vals();
	sales_win.show();
    }
    static void create_salesman(Fl_Widget*w, void*data){
	((boss*)data)->create_salesman_i();
    }

    //callback combo to logout of the boss page
    inline void logout_clicked_i(){
	this->hide();
	hide_all_i();
	customer_win.hide();
	sales_win.hide();
	pin_changer.hide();
	((this->parent())->child(0))->show();
    }
    static void logout_clicked(Fl_Widget*w, void*data){
	((boss*)data)->logout_clicked_i();
    }

    //callback combo to change the boss pin
    inline void change_pin_i(){
	pin_changer.reset_vals();
	pin_changer.show();	
    }
    static void change_pin(Fl_Widget*w, void*data){
	((boss*)data)->change_pin_i();
    }

    //callback combo to view the models
    inline void view_model_view_i(){
	hide_all_i();
	model_view.reset_values();
	model_view.show();	
    }
    static void view_model_view(Fl_Widget*w, void*data){
	((boss*)data)->view_model_view_i();
    }

    //callback combo to view the models
    inline void view_allC_view_i(){
	hide_all_i();
	allC_view.reset_values();
	allC_view.show();	
    }
    static void view_allC_view(Fl_Widget*w, void*data){
	((boss*)data)->view_allC_view_i();
    }

    //callback combo to view the models
    inline void view_allSA_view_i(){
	hide_all_i();
	allSA_view.reset_values();
	allSA_view.show();	
    }
    static void view_allSA_view(Fl_Widget*w, void*data){
	((boss*)data)->view_allSA_view_i();
    }

  public:
	boss() :
	Fl_Window(1000,700),
	logout(910,660,80,30, "Logout"),
	menu(0,0,1000,20){
	    menu.menu(commands);
	    logout.callback(logout_clicked, this);
	    this->add(model_view);
	    this->add(allSA_view);
	    this->add(allC_view);
	    allC_view.hide();
	    allSA_view.hide();
	    model_view.hide();
        };
};
#endif
