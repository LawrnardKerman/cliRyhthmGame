#include <ncurses.h>
int tempo=120; //bpm
bool a[480*3];
bool b[480*3];
bool c[480*3];
bool d[480*3];
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