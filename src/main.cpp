
#include <chrono>
#include <termios.h>
#include <locale.h>
#include <ncursesw/ncurses.h>
using namespace std;
using namespace chrono;
void drawBorder(){
    for(int i=0; i<60; i++){
        move(0, i);
        if(i==0){
            printw("╔");
        }else if(i==59){
            printw("╗");
        }else{
            printw("═");
        }
    }
    for(int i=0; i<60; i++){
         if(i==0){
            printw("╚");
        }else if(i==59){
            printw("╝");
        }else{
            printw("═");
        }
    }
    for(int i=1; i<19; i++){
        move(i, 0);
        printw("║");
    }
    for(int i=1; i<19; i++){
        move(i, 59);
        printw("║");
    }
    refresh();
}
int main(){
    setlocale(LC_ALL, "en_US.utf8");
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
    drawBorder();
    refresh();
    move(0,0);
    while(true){
        input=getch();
        if(input!=ERR){
            clear();
            drawBorder();
            if(input=='j'){
                end=steady_clock::now();
                if(row<19){
                    row++;
                }
            }
            if(input=='k'){
                end=steady_clock::now();
                if(row>0){
                    row--;
                }
            }
            if(input=='l'){
                end=steady_clock::now();
                
                if(col<59){
                    col++;
                }
                
            }
            if(input=='h'){
                end=steady_clock::now();
                if(col>0){
                    col--;
                }
                
            }
            move(row,col);
            refresh();
            if(input=='q'){
                clear();
                move(0,0);
                printw("quitting.");
                refresh();
                printw("quitting..");
                refresh();
                printw("quitting...");
                refresh();
                printw("quitting....");
                refresh();
                printw("quitting.....");
                refresh();
                break;
            }
            start=steady_clock::now();
        }
        
    }
    start=steady_clock::now();
    end=steady_clock::now();
    while((end-start).count()<500000){
        end=steady_clock::now();
    }
    endwin(); 

}