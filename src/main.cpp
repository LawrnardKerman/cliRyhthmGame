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
    auto start=high_resolution_clock::now();
    auto end=high_resolution_clock::now();
    cout<<(start-end).count();
    char input;
    while(true){
        input=getchar();
        cout<<input;
    }
    endwin(); 

}