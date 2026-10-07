#include<bits/stdc++.h>
#include <chrono>
#include <termios.h>
#include <ncurses.h>
using namespace std;
using namespace chrono;

void clearScreen(){
    for(int i=0; i<10; i++){
        cout<<"\r"<<"---------------------------------------------------------------------"<<"\n";
        
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
    while(true){
        input=getch();
        if(input!=ERR){
            if(input=='x'||input=='z'){
                end=steady_clock::now();
                cout<<"\r"<<(end-start).count();

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