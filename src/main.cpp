#include<bits/stdc++.h>
#include <chrono>
#include <string>
#include <termios.h>
#include <ncurses.h>
using namespace std;
using namespace chrono;

void clearScreen(){
    string temp="---------------------------------------------------------------------";
    for(int i=0; i<10; i++){
        move(1,i+1);
        printw("%s",temp.c_str());
        
    }

}
// dont forget: printf("\033[%d;%dH", row, col);
int main(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    auto start=steady_clock::now();
    auto end=steady_clock::now();
    cout<<(start-end).count();
    int input;
    string temp;
    while(true){
        input=getch();
        if(input!=ERR){
            if(input=='x'||input=='z'){
                end=steady_clock::now();
                clearScreen();
                move(1,0);
                temp=to_string((end-start).count());
                printw("%s", temp.c_str());
                refresh();                
                clear();

            }
            if(input=='q'){
                cout<<"quiting...";
                break;
            }
            start=steady_clock::now();
        }
        
    }
    endwin(); 

}