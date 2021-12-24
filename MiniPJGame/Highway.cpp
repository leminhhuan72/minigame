#include "Highway.h"

void Highway::draw(windowCanvas &windowCanvas){
    //draw Light
    windowCanvas.draw(141, y, to_string(int(curTime)), (status? 10: 12));

    for (int i=0;i<138;++i){
        windowCanvas.draw(2+i, y, '-', color);
    }
    for (int i=0;i<138;++i){
        windowCanvas.draw(2+i, y+6, '-', color);
    }

    for (auto u: lst){
        u->draw(windowCanvas);
    }
}

void Highway::isImpact(Object*& u){
    isImp |= u->isImpactY(y) || u->isImpactY(y+6) || u->isImpactY(y+3);
}

bool Highway::isUpdate(){
    if (isUp){
        isUp = false;
        return true;
    }
    return false;
}

void Highway::update(double t){
    t/=CLOCKS_PER_SEC;
    curTime -= t;
    if (curTime <= 0){
        status = !status;
        curTime = timer;
        timepass = 0.4;
    }
    if (status){
        timepass -= t;
        if (timepass <= 0){
            timepass = 0.4;
            for (auto u: lst){
                u->moveTo(x, 0);
            }
            isUp = true;
        }
    }
}

bool Highway::checkImpact(Object*& u){
    for (auto v: lst)
        if (v->isImpact(u))
            return true;
    return false;
}
