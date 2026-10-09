
#include <chrono>
#include <string>
#include <termios.h>
#include <ncursesw/ncurses.h>
#include "song.h";
using namespace std;
using namespace chrono;
void drawBorder(){
    for(int i=0; i<60; i++){
        move(0, i);
        printw("#");
    }
    for(int i=0; i<60; i++){
        move(19, i);
        printw("#");
    }
    for(int i=0; i<20; i++){
        move(i, 0);
        printw("|");
    }
    for(int i=0; i<20; i++){
        move(i, 59);
        printw("|");
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
    move(2,0);
    printw("Press q to quit");
    move(3,0);
    printw("press n to make a beatmap");
    refresh();
    while(true){
        input=getch();
        if(input=='s'){
            clear();
            drawBorder();
            refresh();
            break;
        }
    }
    int row=0;
    int col=0;
    drawBorder();
    move(0,0);
    printw("     ");
    refresh();
    move(0,0);
    while(true){
        input=getch();
        if(input!=ERR){
            clear();
            drawBorder();
            if(input=='j'){
                end=steady_clock::now();
                if(row<19){
                    row++;
                }
            }
            if(input=='k'){
                end=steady_clock::now();
                if(row>0){
                    row--;
                }
            }
            if(input=='l'){
                end=steady_clock::now();
                
                if(col<59){
                    col++;
                }
                
            }
            if(input=='h'){
                end=steady_clock::now();
                if(col>0){
                    col--;
                }
                
            }
            move(0,0);
            printw("     ");
            move(0,0);
            printw("%s", to_string(row).c_str());
            move(0, 3);
            printw("%s", to_string(col).c_str());
            move(row,col);
            
            refresh();
            if(input=='q'){
                move(0,0);
                printw("quitting...");
                refresh();
                break;
            }
            start=steady_clock::now();
        }
        
    }
    start=steady_clock::now();
    end=steady_clock::now();
    while((end-start).count()<500000){
        end=steady_clock::now();
    }
    endwin(); 

}