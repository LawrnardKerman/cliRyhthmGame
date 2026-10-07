#include<bits/stdc++.h>
#include <chrono>
#include <X11/Xlib.h>
#include "X11/keysym.h"
using namespace std;
using namespace chrono;

bool keyIsPressed(KeySym ks) {
    Display *dpy = XOpenDisplay(":0");
    char keys_return[32];
    XQueryKeymap(dpy, keys_return);
    KeyCode kc2 = XKeysymToKeycode(dpy, ks);
    bool isPressed = !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7)));
    XCloseDisplay(dpy);
    return isPressed;
}
int main(){
    auto start=high_resolution_clock::now();
    auto end=high_resolution_clock::now();
    cout<<(start-end).count();
    while(true){
        keyIsPressed(XK_A){
            auto end=high_resolution_clock::now();
            cout<<(start-end).count();
            auto start=high_resolution_clock::now();
        }

    }

}