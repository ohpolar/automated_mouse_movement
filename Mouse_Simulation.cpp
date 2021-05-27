#include <iostream>
#include <Windows.h>
using namespace std;

void shoot() {
    while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {

        int pat1[] = {-165, 25, -259, -205, 0, 80, 140, 180, 130, 142, 38, 30, 17, 0, -15, -27, -37, -43, -46, -45, -42, -35, -24, -11, 12, 36, 49, 49, 38 };
        int pat2[] = {238, 218, 198, 180, 156 , 130, 130, 100, 50, 9, 9, 18, 25, 29, 32, 33, 32, 29, 24, 17, 8, 5, 14, 21, 25, 28, 28, 26, 21 };
        int pattern1 = 0;
        int pattern2 = 0;
        int timing = 135; // This is the timing for the mouse down loop.
        int desiredSens = 0.2;
        for (int f = 0; f < 29; ++f) {
            if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
            {
                int pattern1 = pat1[f];
                int pattern2 = pat2[f];
                int p1s = pattern1 / 5;
                int p2s = pattern2 / 5;
                int timeS = timing / 5;

                //Smoothing loop.
                for (int g = 0; g < 5; g++) {

                    MOUSEINPUT mouseDown{ p1s, p2s, 0, MOUSEEVENTF_MOVE, 0, NULL };
                    INPUT mouse{ INPUT_MOUSE, mouseDown };
                    SendInput(1, &mouse, sizeof(mouse));
                    Sleep(timeS);
                }
             
                // Use this to debug, smoothing not included.
                /*
                   MOUSEINPUT mouseDown{ pattern1, pattern2, 0, MOUSEEVENTF_MOVE, 0, NULL };
                   INPUT mouse{ INPUT_MOUSE, mouseDown };
                   SendInput(1, &mouse, sizeof(mouse));
                   cout << "Pattern1: " << pattern1 << endl;
                   cout << "Pattern2: " << pattern2 << endl;
                   Sleep(timing);
                */
    
            }   
        }
    }
}


int main()
{
    bool quit = FALSE;
    
    while (!quit) {

            if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
             shoot();
            }

            if (GetAsyncKeyState(VK_DELETE)) {
                break;
            } 
    }
    return 0;
}