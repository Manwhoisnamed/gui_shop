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
#include <iostream>

//make callbacks

//login buttton callback
void login_button_clicked(Fl_Widget* w, void* data){
    if(1337 == atof(((Fl_Input*)((Fl_Group*)data)->child(1))->value())){	
	((Fl_Group*)data)->hide();
    }
    else{
	((Fl_Box*)(((Fl_Group*)data)->child(2)))->label("Permission Denied!");
    }
    ((Fl_Input*)(((Fl_Group*)data)->child(1)))->value("");
}

//callback to change the permissions
void change_permissions(Fl_Widget* w, void* data){
    static int perms = 0;
    perms++;
    if(perms == 3){
	perms = 0;
    }
    if(perms == 0){
	((Fl_Box*)data)->label("Project Manager");
    }
    else if(perms == 1){
	((Fl_Box*)data)->label("Beloved Customer");
    }
    else if(perms == 2){
	((Fl_Box*)data)->label("Sales Associate");
    }
}

int main(void){
    //creates windows and widgets
    Fl_Window *window = new Fl_Window(1000,700);
    Fl_Return_Button *login_button = new Fl_Return_Button(450,350,100,50,"Login");
    Fl_Input *login = new Fl_Input(450, 300, 100, 25, "Pin");
    Fl_Box *clearance = new Fl_Box(425, 250, 150, 25, "Project Manager");
    Fl_Button *change = new Fl_Button(275, 250, 150, 25, "Change Permissions");
    Fl_Box *response = new Fl_Box(575, 300, 150, 25);

    //groups all of the login widgets
    Fl_Group *login_group = new Fl_Group(0,0,1000,700);
    login_group->add(clearance);
    login_group->add(login);
    login_group->add(response);
    login_group->add(login_button);
    login_group->add(change);

    //sets the widgets
    clearance->box(FL_NO_BOX);
    response->box(FL_NO_BOX);
    window->label("Rob Robman's Rockin Robo Shop - Login");

    //set callbacks
    login_button->callback(login_button_clicked, (void*) login_group);
    change->callback(change_permissions, (void*) clearance);

    //let this thing run
    window->end();
    window->show();
    return Fl::run();
}

