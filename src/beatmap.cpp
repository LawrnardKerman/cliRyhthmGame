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
    ofstream clear("beatmap.txt", ios::trunc); 
    clear.close();
    ofstream out("beatmap.txt");
    out<<"int tempo="<<tempo<<";"<<"\n";
    out.close();
    cout<<"wrote to file"<<"\n";
    out.open("beatmap.txt");
    Music music;
    music.openFromFile("music.mp3");
    cout<<"play music"<<endl;
    int length=music.getDuration().asSeconds();
    vector<bool> a(tempo/60*length*4); 
    vector<bool> b(tempo/60*length*4); 
    vector<bool> c(tempo/60*length*4); 
    vector<bool> d(tempo/60*length*4); 
    for(int i=0; i<tempo*length*60*4; i++){
        a[i]=false;
        b[i]=false;
        c[i]=false;
        d[i]=false;
    }
    auto now=steady_clock::now();
    auto lastBeat=steady_clock::now();
    int index=0;
    music.play();
    while(true){
        now=steady_clock::now();
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now-lastBeat).count()>=((60.0/tempo/4)*1000)){
            index++;
            lastBeat=steady_clock::now();
            if(index>sizeof(a)){
                break;
            }
        }
        now=steady_clock::now();
        //std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); very importan
        char input=getch();
        //z x , . for input
        if(input=='z'){
            if((std::chrono::duration_cast<std::chrono::milliseconds>(now-lastBeat).count()>=((60.0/tempo/4)*750))){
                if(index<sizeof(a)-1){
                    a[index-1]=true;
                }else{
                    a[index]=true;
                }
            }else{
                a[index]=true;
            }
        }
        if(music.getStatus()!=sf::Music::Playing){
            break;
        }
        
    }
    out<<"bool a["<<sizeof(a)<<"]=";
    for(int i=0; i<sizeof(a); i++){
        if(i!=sizeof(a)-1){
            out<<a[i]<<",";
        }else{
            out<<a[i];
        }
    }
    out<<"}"<<"\n";
    out<<"bool b["<<sizeof(a)<<"]=";
    for(int i=0; i<sizeof(a); i++){
        if(i!=sizeof(a)-1){
            out<<b[i]<<",";
        }else{
            out<<b[i];
        }
    }
    out<<"}"<<"\n";
    out<<"bool a["<<sizeof(a)<<"]=";
    for(int i=0; i<sizeof(a); i++){
        if(i!=sizeof(a)-1){
            out<<b[i]<<",";
        }else{
            out<<b[i];
        }
    }
    out<<"}"<<"\n";
    out<<"bool a["<<sizeof(a)<<"]=";
    for(int i=0; i<sizeof(a); i++){
        if(i!=sizeof(a)-1){
            out<<b[i]<<",";
        }else{
            out<<b[i];
        }
    }
    out<<"}"<<"\n";
    out.close();
    endwin();
    quick_exit(0);
}
