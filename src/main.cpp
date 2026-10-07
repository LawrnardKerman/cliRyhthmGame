#include<bits/stdc++.h>
#include <chrono>
#include <termios.h>
#include <ncurses.h>
using namespace std;
using namespace chrono;


int main(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    auto start=high_resolution_clock::now();
    auto end=high_resolution_clock::now();
    cout<<(start-end).count();
    int input;
    while(true){
        input=getch();
        if(input!=ERR){
            if(input=='x'||input=='z'){
                end=high_resolution_clock::now();
                cout<<(start-end).count();
                cout<<"/n";
            }
        }
        
    }
    endwin(); 

}