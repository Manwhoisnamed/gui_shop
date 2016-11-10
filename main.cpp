//maxwell sanders 1001069652
//this is the main file

#include "globals.h"
#include "login.h"
#include "pos.h"
#include "salesfloor.h"
#include "workshop.h"

int main(void){
    login login_win;
    pos pos_win;
    salesfloor sales_win;
    workshop pm_win;
    login_win.show();
    Fl::run();
}
