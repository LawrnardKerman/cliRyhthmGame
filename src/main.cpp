
#include <chrono>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <termios.h>
#include <ncursesw/ncurses.h>
#include "song.h"
using namespace std;
using namespace chrono;
void drawSquare(int row, int col, char in){
    move(row,col);
    printw("%c", in);
    move(row+1,col);
    printw("%c", in);
    move(row+1,col+1);
    printw("%c", in);
    move(row,col+1);
    printw("%c", in);
}
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
    auto aTime=steady_clock::now();
    auto bTime=steady_clock::now();
    auto cTime=steady_clock::now();
    auto dTime=steady_clock::now();
    auto now=steady_clock::now();
    int tempo=getTempo();
    move(0,0);
    while(true){
        now=steady_clock::now();
        input=getch();
        if(input!=ERR){
            if(input=='z'){
                aTime=steady_clock::now();
                drawSquare(3, 1, '0');
            }
            if(input=='x'){
                bTime=steady_clock::now();
                drawSquare(7, 1, '0');
            } 
            if(input=='.'){
                cTime=steady_clock::now();
                drawSquare(11, 1, '0');
            }
            if(input=='/'){
                dTime=steady_clock::now();
                drawSquare(15, 1, '0');
            }
            move(0,0);
            if(input=='q'){
                clear();
                endwin();
                quick_exit(0);
            }
        }
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-aTime).count()>=((60.0/tempo/8)*1000)){
                drawSquare(3, 1, '-');
        }
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-bTime).count()>=((60.0/tempo/8)*1000)){
                drawSquare(7, 1, '-');
        }
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-cTime).count()>=((60.0/tempo/8)*1000)){
                drawSquare(11, 1, '-');
        }
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-dTime).count()>=((60.0/tempo/8)*1000)){
                drawSquare(15, 1, '-');
        }
        move(0,0);
        refresh();
    }


}