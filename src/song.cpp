#include <ncurses.h>
int tempo=120; //bpm
bool a[100];
bool b[100];
bool c[100];
bool d[100];
bool aValue(int i){
    return a[i];
}
bool bValue(int i){
    return b[i];
}
bool cValue(int i){
    return c[i];
}
bool dValue(int i){
    return d[i];
}
int getTempo(){
    return tempo;
}