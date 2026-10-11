//beatmap maker haha funny osu refrence
#include<bits/stdc++.h>
#include<chrono>
#include <ostream>
#include <termios.h>
#include <ncursesw/ncurses.h>
#include <SFML/Audio.hpp>
#include <fstream>
using namespace std;
using namespace chrono;
using namespace sf;
void makeBeatmap(){//length is in seconds
    nodelay(stdscr, TRUE);
    constexpr int tempo=120;
    ofstream temp("beatmap.txt", ios::trunc); 
    temp.close();
    ofstream out("beatmap.txt");
    out.close();
    clear();
    move(0,0);
    printw("wrote to file");
    out.open("beatmap.txt");
    Music music;
    music.openFromFile("music.mp3");
    move(1,0);
    printw("playing music");
    int length=(int)music.getDuration().asSeconds();
    int n=tempo/60*length*4;
    vector<bool> a(tempo/60*length*4,false); 
    vector<bool> b(tempo/60*length*4,false); 
    vector<bool> c(tempo/60*length*4, false); 
    vector<bool> d(tempo/60*length*4, false); 
    auto now=steady_clock::now();
    auto lastBeat=steady_clock::now();
    int index=0;
    out<<"constexpr int tempo="<<tempo<<";"<<endl;
    music.play();
    while(true){
        now=steady_clock::now();
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-lastBeat).count()>=((60.0/tempo/4)*1000)){
            index++;
            lastBeat=steady_clock::now();
            if(index>n){
                break;
            }
        }
        now=steady_clock::now();
        //std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); very importan
        char input=getch();
        //z x . / for input
        if(input=='z'){
            if((std::chrono::duration_cast<std::chrono::milliseconds>(now-lastBeat).count()>=((60.0/tempo/4)*750))){
                if(index<n-1){
                    a[index-1]=true;
                }else{
                    a[index]=true;
                }
            }else{
                a[index]=true;
            }
        }
        if(input=='x'){
            if((std::chrono::duration_cast<std::chrono::milliseconds>(now-lastBeat).count()>=((60.0/tempo/4)*750))){
                if(index<n-1){
                    b[index-1]=true;
                }else{
                    b[index]=true;
                }
            }else{
                b[index]=true;
            }
        }
        if(input=='.'){
            if((std::chrono::duration_cast<std::chrono::milliseconds>(now-lastBeat).count()>=((60.0/tempo/4)*750))){
                if(index<n-1){
                    c[index-1]=true;
                }else{
                    c[index]=true;
                }
            }else{
                c[index]=true;
            }
        }
        if(input=='/'){
            if((std::chrono::duration_cast<std::chrono::milliseconds>(now-lastBeat).count()>=((60.0/tempo/4)*750))){
                if(index<n-1){
                    d[index-1]=true;
                }else{
                    d[index]=true;
                }
            }else{
                d[index]=true;
            }
        }
        if(music.getStatus()!=sf::Music::Playing){
            break;
        }
        
    }
    out<<"bool a["<<n<<"]={";
    for(int i=0; i<n; i++){
        if(i!=n-1){
            out<<a[i]<<",";
        }else{
            out<<a[i];
        }
    }
    out<<"};"<<"\n";
    out<<"bool b["<<n<<"]={";
    for(int i=0; i<n; i++){
        if(i!=n-1){
            out<<b[i]<<",";
        }else{
            out<<b[i];
        }
    }
    out<<"};"<<"\n";
    out<<"bool c["<<n<<"]={";
    for(int i=0; i<n; i++){
        if(i!=n-1){
            out<<b[i]<<",";
        }else{
            out<<b[i];
        }
    }
    out<<"};"<<"\n";
    out<<"bool d["<<n<<"]={";
    for(int i=0; i<n; i++){
        if(i!=n-1){
            out<<b[i]<<",";
        }else{
            out<<b[i];
        }
    }
    out<<"};"<<"\n";
    out.close();
    endwin();
    quick_exit(0);
}
