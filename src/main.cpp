
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
// dont forget: printf("\033[%d;%dH", row, col);
int main(){
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    auto start=steady_clock::now();
    auto end=steady_clock::now();
    int input;
    while(true){
        input=getch();
        if(input!=ERR){
            if(input=='x'||input=='z'){
                clear();
                clearScreen();
                // move(1, 26);
                // printw("Hello CSC 222 from ncurses!");
                refresh();
                getch();
            }
            if(input=='q'){
                printw("quitting...");
                break;
            }
            start=steady_clock::now();
        }
        
    }
    endwin(); 

}