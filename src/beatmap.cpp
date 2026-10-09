//beatmap maker haha funny osu refrence
#include<bits/stdc++.h>
#include<chrono>
#include <termios.h>
#include <ncursesw/ncurses.h>
using namespace std;
using namespace chrono;
void makeBeatmap(int tempo, int length){//length is in seconds

    bool a[tempo*length*60*4];
    bool b[tempo*length*60*4];
    bool c[tempo*length*60*4];
    bool d[tempo*length*60*4];
    for(int i=0; i<tempo*length*60*4; i++){
        a[i]=false;
        b[i]=false;
        c[i]=false;
        d[i]=false;
    }
    auto start=steady_clock::now();
    auto end=steady_clock::now();
    while(true){
        auto end=steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        int diff=duration.count();
        char input=getch();
        //z x , . for input
        switch(input){
            case 'z': 
            case 'x':
            case ',':
            case '.':
            default: break;
        }
    }
}