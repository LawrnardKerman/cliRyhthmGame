
#include <chrono>
#include <cstdlib>
#include <string>
#include <termios.h>
#include <ncursesw/ncurses.h>
#include "song.h"
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
void drawBars(){
    move(2,1);
    for(int i=1; i<59; i++){
        move(3,i);
        printw("-");
    }
    for(int i=1; i<59; i++){
        move(4,i);
        printw("-");
    }
    for(int i=1; i<59; i++){
        move(7,i);
        printw("-");
    }
    for(int i=1; i<59; i++){
        move(8,i);
        printw("-");
    }
    for(int i=1; i<59; i++){
        move(11,i);
        printw("-");
    }
    for(int i=1; i<59; i++){
        move(12,i);
        printw("-");
    }
    for(int i=1; i<59; i++){
        move(15,i);
        printw("-");
    }
    for(int i=1; i<59; i++){
        move(16,i);
        printw("-");
    }

}
int main(){
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
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
    drawBars();

    move(0,0);
    printw("     ");
    refresh();
    move(0,0);
    while(true){
        input=getch();
        move(19,0);
        printw("press s to start playing");
        move(0,0);
        printw("     ");
        move(0,0);
        printw("%s", to_string(col).c_str());
        move(0, 3);
        printw("%s", to_string(row).c_str());
        move(row,col);
        if(input!=ERR){
            clear();
            drawBorder();
            drawBars();
            if(input=='j'){
                if(row<19){
                    row++;
                }
            }
            if(input=='k'){
                if(row>0){
                    row--;
                }
            }
            if(input=='l'){
                
                if(col<59){
                    col++;
                }
                
            }
            if(input=='h'){
                if(col>0){
                    col--;
                }
                
            }
            if(input=='s'){
                break;
            }
            move(row,col);
            
            refresh();
            if(input=='q'){
                move(0,0);
                printw("quitting...");
                refresh();
                endwin();
                quick_exit(0);
                break;
                 
            }
        }
        
    }
    auto start=steady_clock::now();
    auto end=steady_clock::now();
    int n=getLength();
    bool a[n];
    bool b[n];
    bool c[n];
    bool d[n];
    for(int i=0; i<n; i++){
        a[i]=aValue(i);
        b[i]=bValue(i);
        c[i]=cValue(i);
        d[i]=dValue(i);
    }
    int tempo=getTempo();


}