#ifndef _SoundControl_
#define _SoundControl_

#include <windows.h>
#include <iostream>

// If there is a bug
// Go to setting -> compiler -> linker setting -> "-lwinmm" Paste It in Linker Box Press OK

using namespace std;

class SoundControl{
    /// Singleton
private:
    static SoundControl* soundControl;
    string curBackGround;
    SoundControl():curBackGround(""){}
public:
    SoundControl(SoundControl &other) = delete;
    void operator=(const SoundControl &) = delete;
    static SoundControl *GetInstance(){
        if (soundControl == nullptr){
            soundControl = new SoundControl();
        }
        return soundControl;
    }

    void playBackGround(string s);
    void playBackGround1();
    void playBackGround2();
};



#endif // _SoundControl_
