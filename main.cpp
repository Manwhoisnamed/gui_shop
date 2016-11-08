//maxwell Sanders 1001069652
//This is the main it starts the program and makes all the windows

#include "login.h"
#include "workshop.h"
#include "pos.h"
#include "salesfloor.h"

int main(void){
    login login_win;
    workshop workshop_win;
    pos POS_win;
    salesfloor salesfloor_win;
    login_win.show();
    workshop_win.show();
    POS_win.show();
    salesfloor_win.show();
    Fl::run();
}
