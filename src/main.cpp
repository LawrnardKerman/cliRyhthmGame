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
    auto start=steady_clock::now();
    auto end=steady_clock::now();
    cout<<(start-end).count();
    int input;
    
    while(true){
        input=getch();
        if(input!=ERR){
            if(input=='x'||input=='z'){
                end=steady_clock::now();
                cout<<"\r";
                cout<<(end-start).count();
                cout<<"test";
                cout<<"\n";
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