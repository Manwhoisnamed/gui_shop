//maxwell Sanders 1001069652
//This is the main it starts the program and makes all the windows

#include "login.h"
#include "workshop.h"

int main(void){
    login login_win;
    workshop workshop_win;
    login_win.show();
    workshop_win.show();
    Fl::run();
}
