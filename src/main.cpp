
#include <chrono>
#include <termios.h>
#include <ncurses.h>
using namespace std;
using namespace chrono;

void clearScreen(){
    for(int i=0; i<10; i++){
        move(i, 0);
        printw("------------------------------------------------------------\n");
    }

}
int main(){
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    auto start=steady_clock::now();
    auto end=steady_clock::now();
    int input;

    move(0,0);
    printw("welcome!");
    move(1,0);
    printw("Press s to start");
    refresh();
    while(true){
        input=getch();
        if(input=='s'){
            clear();
            break;
        }
    }
    while(true){
        input=getch();
        if(input!=ERR){
            if(input=='x'||input=='z'){
                end=steady_clock::now();
                clear();
                clearScreen();
                move(0,0);
                printw("中文");
                refresh();
            }
            if(input=='q'){
                move(0,0);
                printw("quitting...");
                refresh();
                break;
            }
            start=steady_clock::now();
        }
        
    }
    endwin(); 

}