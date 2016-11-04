//maxwell Sanders 1001069652
//this is the main

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <Fl/Fl_Menu_Bar.H>
#include <Fl/Fl_Menu_Item.H>

//make callbacks

//login buttton callback
void login_button_clicked(Fl_Widget* w, void* data){
    Fl_Window* login_window = (Fl_Window*) data;
    Fl_Window* PM_Window = (Fl_Window*) (((Fl_Window*)(login_window->parent()))->child(1));
    Fl_Box* response = (Fl_Box*) login_window->child(4);
    Fl_Input* input = (Fl_Input*) login_window->child(1);
    Fl_Window* father = (Fl_Window*)(login_window->parent());
    if(1337 == atof(input->value())){	
  	login_window->hide();
	PM_Window->show();
	father->label("Rob Robman's Rockin Roboshop - Project Manager");
    }
    else{
	response->labelcolor(FL_RED);
	response->label("Permission Denied!");
    }
    input->value("");
}

//logs out of the current menu and goes back to the main menu
void logout_button_clicked(Fl_Widget* w, void* current){
    Fl_Window* current_window = (Fl_Window*) current;
    Fl_Window* login_window = (Fl_Window*) (((Fl_Window*)(current_window->parent()))->child(0));
    Fl_Window* father = (Fl_Window*)(login_window->parent());
    current_window->hide();
    login_window->show();
    father->label("Rob Robman's Rockin Roboshop - Login"); 
}

//callback to change the permissions
void change_permissions(Fl_Widget* w, void* data){
    static int perms = 0;
    perms++;
    Fl_Box* status = (Fl_Box*) data;
    if(perms == 3){
	perms = 0;
    }
    if(perms == 0){
	status->label("Project Manager");
    }
    else if(perms == 1){
	status->label("Beloved Customer");
    }
    else if(perms == 2){
	status->label("Sales Associate");
    }
}

int main(void){

    Fl_Window* father = new Fl_Window(1000,700, "Rob Robman's Rockin Roboshop - Login");
    father->end();

////////////////////////////////////////////////////////////////////

    //creates login window and widgets
    Fl_Window *login_window = new Fl_Window(1000,700);
    Fl_Return_Button *login_button = new Fl_Return_Button(450,350,100,50,"Login");
    Fl_Input *login = new Fl_Input(450, 300, 100, 25, "Pin");
    Fl_Box *clearance = new Fl_Box(425, 250, 150, 25, "Project Manager");
    Fl_Button *change = new Fl_Button(275, 250, 150, 25, "Change Permissions");
    Fl_Box *response = new Fl_Box(575, 300, 150, 25);

    //sets the widgets

    //set callbacks
    login_button->callback(login_button_clicked, (void*) login_window);
    change->callback(change_permissions, (void*) clearance);

    //end the grouping and add the window to the main group
    login_window->end();
    father->add(login_window);
   
/////////////////////////////////////////////////////////////////////

    //creates the PM window and widgets
    Fl_Window *PM_Window = new Fl_Window(1000,700);
    Fl_Button *logout = new Fl_Button(910,660,80,30, "Logout");   
    Fl_Menu_Bar *menu = new Fl_Menu_Bar(0,0,1000,20);
    Fl_Menu_Item manage[] = {
	{"&Workshop",FL_ALT+'w', 0, 0, FL_SUBMENU},
	{"Create &Arm",FL_ALT+'a', 0, 0},
	{"Create &Battery",FL_ALT+'b', 0, 0},
	{"Create &Head",FL_ALT+'h', 0, 0},
	{"Create &Leg",FL_ALT+'l', 0, 0},
	{"Create &Torso",FL_ALT+'t', 0, 0, FL_MENU_DIVIDER},
	{"Create &RoboModel",FL_ALT+'r', 0, 0},
	{0},
	{"&Storage",FL_ALT+'s', 0, 0, FL_SUBMENU},	
	{"View &Arm",FL_ALT+'a', 0, 0},
	{"View &Battery",FL_ALT+'b', 0, 0},
	{"View &Head",FL_ALT+'h', 0, 0},
	{"View &Leg",FL_ALT+'l', 0, 0},
	{"View &Torso",FL_ALT+'t', 0, 0, FL_MENU_DIVIDER},
	{"View &RoboModel",FL_ALT+'r', 0, 0},
	{0},
	{0}
    };
 
    //sets the widgets
    menu->menu(manage);
  
    //set callbacks
    logout->callback(logout_button_clicked, PM_Window);

    //end the grouping and add the window to the main group
    PM_Window->end();
    father->add(PM_Window);

/////////////////////////////////////////////////////////////////////

    //creates the PM window and widgets
    
    //sets the widgets
  
    //set callbacks
  
    //end the grouping and add the window to the main group

/////////////////////////////////////////////////////////////////////

    father->show();
    login_window->show();
    return Fl::run();
}

