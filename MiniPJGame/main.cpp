#include <iostream>
#include "Game.h"
#include <ctime>

using namespace std;

SoundControl* SoundControl::soundControl = nullptr;
const int TITLE[][82] = { { 32,95,95,95,95,95,32,32,     32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		  32,32,32,32,32,'_',32,	   32,32,32,32,32,  32,32,32,'_','_','_','_',32,	32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 32,32,32,	  32,32,32,32,32,32,32,		   },
                     { 178,32,32,'_','_',32,92,32,	 32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		  32,32,32,32,178,32,178,	   32,32,32,32,32,  32,32,'/',32,'_','_','_',178,	32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 32,'_',32,	  32,32,32,32,32,32,32,		   },
                     { 178,32,178,'_','_',')',32,')', 32,32,'_','_','_',32,32,	 32,32,'_','_',32,'_',32,	  32,32,'_','_',178,32,178,	   32,32,32,32,32,  32,'/',32,32,178,32,32,32,		32,'_',32,'_','_',32,	 32,32,'_','_','_',32,32,	 32,'_','_','_',32,    32,'_','_','_',32,	 '(','_',')', 32,'_',32,'_','_',32,32,	  32,32,'_','_',32,'_',32},
                     { 178,32,32,'_',32,32,'/',32,	 32,'/',32,'_',32,'\\',32,	 32,'/',32,'_','\'',32,178,	  32,'/',32,'_',32,32,178,	   32,32,32,32,32,  168,'?',32,32,178,32,32,32,		178,32,'\'','_','_',178, 32,'/',32,'_',32,'\\',32,	 '/',32,'_','_',178,   '/',32,'_','_',178,   178,32,178,  '|',32,'\'','_',32,'\\',32, 32,'/',32,'_','\'',32,178},
                     { 178,32,178,32,92,32,92,32,	 '(',32,'(','_',')',32,')',	 '(',32,'(','_',')',32,178,	  '(',32,'(','_',')',32,178,   32,32,32,32,32,  32,'\\',32,32,178,'_','_','_',  178,32,178,32,32,32,	 '(',32,'(','_',')',32,')',  '\\','_','_',32,'\\', '\\','_','_',32,'\\', 178,32,178,  '|',32,178,32,'|',32,'|',	  '(',32,'(','_',')',32,178},
                     { 178,'_',178,32,32,92,'_',92,	 32,'\\','_','_','_','/',32, 32,'\\','_','_',',','_',178, 32,'\\','_','_',',','_',178, 32,32,32,32,32,  32,32,'\\','_','_','_','_',178, 178,'_',178,32,32,32,	 32,'\\','_','_','_','/',32, 178,'_','_','_','/',  178,'_','_','_','/',  178,'_',178, '|','_',178,32,'|','_','|', 32,'\\','_','_',',',32,178},
                     { 32,32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		  32,32,32,32,32,32,32,		   32,32,32,32,32,  32,32,32,32,32,32,32,32,		32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 32,32,32,	  32,32,32,32,32,32,32,		  32,178,'_','_','_','/'} };

vector <string> press = {"(PRESS ENTER TO CONTINUE)"};

void drawTiTle() {
    windowCanvas windowCanvas;
    windowCanvas.resetLim();
    int width = 145;
    int height= 44;
    for (int i=0;i<width+10;++i)
    for (int j=0;j<height;++j){
        if (i==0 || j==0 || i==width+9 || j==height-1){
            windowCanvas.draw(i, j, '*', 10);
        }else
            windowCanvas.draw(i, j, ' ', 7);
    }
    int startRow = height/2 - 1 - 3, startCol;
    for (int i = 0; i <= 6; ++i) {
        for (int j = 0; j < 82; ++j) {
            startCol = width/2 + 5 - 1 - 41;
            windowCanvas.draw(startCol+j, startRow+i, (char) TITLE[i][j], rand() % 16);
        }
    }





int main(){
    srand(time(nullptr));
    Game newGame;
    newGame.startGame();
    return 0;
}
