
#include <chrono>
#include <termios.h>
#include <ncurses.h>
using namespace std;
using namespace chrono;

void clearScreen(){
    for(int i=0; i<10; i++){
        move(i, 0);
        printw("------------------------------------------------------------\n");
    }

}
int main(){
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    auto start=steady_clock::now();
    auto end=steady_clock::now();
    int input;

    move(0,0);
    printw("welcome!");
    move(1,0);
    printw("Press s to start");
    move(2,0);
    printw("Press q to quit");
    refresh();
    while(true){
        input=getch();
        if(input=='s'){
            clear();
            break;
        }
    }
    int row=0;
    int col=0;
    while(true){
        input=getch();
        if(input!=ERR){
            clear();
            if(input=='j'){
                end=steady_clock::now();
                if(row<19){
                    row++;
                }
                move(row,col);
                refresh();
            }
            if(input=='k'){
                end=steady_clock::now();
                if(row>0){
                    row--;
                }
                move(row,col);
                refresh();
            }
            if(input=='l'){
                end=steady_clock::now();
                
                if(col<59){
                    col++;
                }
                move(row,col);
                
            }
            if(input=='h'){
                end=steady_clock::now();
                if(col>0){
                    col--;
                }
                move(row,col);
                
            }
            refresh();
            if(input=='q'){
                move(0,0);
                printw("quitting...");
                refresh();
                break;
            }
            start=steady_clock::now();
        }
        
    }
    endwin(); 

}