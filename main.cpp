//maxwell sanders 1001069652
//this is the main file

#include "globals.h"
#include "father.h"

int main(void){
    father father_win;
    storage.load();
    father_win.show();
    (father_win.child(0))->show();
    Fl::run();
}
