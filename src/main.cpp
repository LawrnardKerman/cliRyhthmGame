
#include <chrono>
#include <cstdlib>
#include"beatmap.h"
#include <ncurses.h>
#include <string>
#include <termios.h>
#include <ncursesw/ncurses.h>
#include "song.h"
#include <SFML/Audio.hpp>
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
    for(int i=0; i<59; i++){
        move(0, i);
        printw("#");
    }
    for(int i=0; i<59; i++){
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
    for(int i=1; i<58; i++){
        move(3,i);
        printw("-");
    }
    for(int i=1; i<58; i++){
        move(4,i);
        printw("-");
    }
    for(int i=1; i<58; i++){
        move(7,i);
        printw("-");
    }
    for(int i=1; i<58; i++){
        move(8,i);
        printw("-");
    }
    for(int i=1; i<58; i++){
        move(11,i);
        printw("-");
    }
    for(int i=1; i<58; i++){
        move(12,i);
        printw("-");
    }
    for(int i=1; i<58; i++){
        move(15,i);
        printw("-");
    }
    for(int i=1; i<58; i++){
        move(16,i);
        printw("-");
    }

}
void drawUi(){
    drawBars();
    move(2,1);
    printw("z");
    move(6,1);
    printw("x");
    move(10,1);
    printw(".");
    move(14,1);
    printw("/");
    move(0,0);
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
        if(input=='n'){
            makeBeatmap();
        }
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
            if(input=='n'){
                makeBeatmap();
            }
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
    auto aTime=steady_clock::now();
    auto bTime=steady_clock::now();
    auto cTime=steady_clock::now();
    auto dTime=steady_clock::now();
    auto beatTime=steady_clock::now();
    auto now=steady_clock::now();
    int tempo=getTempo();
    move(0,0);
    int songIndex=-27;
    while(true){
        drawUi();
        now=steady_clock::now();
        input=getch();
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-beatTime).count()>=((60.0/tempo/4)*1000)){
            beatTime=steady_clock::now();
            songIndex++;
            for(int i=1; i<56; i+=2){
            if(songIndex+i-1<0||songIndex+i-1>n){
                drawSquare(3, i, '-');
            }else{
                if(aValue(i)){
                    drawSquare(3, i, '#');
                }else{
                    drawSquare(3, i, '-');
                }
            }
            if(songIndex+i-1<0||songIndex+i-1>n){
                drawSquare(3, i, '-');
            }else{
                if(aValue(i)){
                    drawSquare(3, i, '#');
                }else{
                    drawSquare(3, i, '-');
                }
            }
            if(songIndex+i-1<0||songIndex+i-1>n){
                drawSquare(3, i, '-');
            }else{
                if(aValue(i)){
                    drawSquare(3, i, '#');
                }else{
                    drawSquare(3, i, '-');
                }
            }
            if(songIndex+i-1<0||songIndex+i-1>n){
                drawSquare(3, i, '-');
            }else{
                if(aValue(i)){
                    drawSquare(3, i, '#');
                }else{
                    drawSquare(3, i, '-');
                }
            }
        }
        }
        
        
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-aTime).count()>=((60.0/tempo/6)*1000)){
                move(3,0);
                printw("|");
                move(4,0);
                printw("|");
        }
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-bTime).count()>=((60.0/tempo/6)*1000)){
                move(7,0);
                printw("|");
                move(8,0);
                printw("|");
        }
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-cTime).count()>=((60.0/tempo/6)*1000)){
                move(11,0);
                printw("|");
                move(12,0);
                printw("|");
        }
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-dTime).count()>=((60.0/tempo/6)*1000)){
                move(15,0);
                printw("|");
                move(16,0);
                printw("|");
        }
        if(input!=ERR){
            if(input=='z'){
                aTime=steady_clock::now();
                move(3,0);
                printw("o");
                move(4,0);
                printw("o");
            }
            if(input=='x'){
                bTime=steady_clock::now();
                move(7,0);
                printw("o");
                move(8,0);
                printw("o");
            } 
            if(input=='.'){
                cTime=steady_clock::now();
                move(11,0);
                printw("o");
                move(12,0);
                printw("o");
            }
            if(input=='/'){
                dTime=steady_clock::now();
                move(15,0);
                printw("o");
                move(16,0);
                printw("o");
            }
            move(0,0);
            if(input=='q'){
                clear();
                endwin();
                quick_exit(0);
            }
        }
        
        move(0,0);
        refresh();
    }


}