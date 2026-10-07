#include<bits/stdc++.h>
#include <chrono>
#include <termios.h>
using namespace std;
using namespace chrono;
char getch() {
    char buf = 0;
    struct termios old = {0};
    
    // Get current terminal settings
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
        
    // Disable canonical mode (line buffering) and local echo
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
        
    // Read the single character
    if (read(0, &buf, 1) < 0)
        perror ("read()");
        
    // Restore original terminal settings
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
        
    return buf;
}

int main(){
    auto start=high_resolution_clock::now();
    auto end=high_resolution_clock::now();
    cout<<(start-end).count();
    char input;
    while(true){
        input = getch(); 
        cout<<input;
    }

}