#include "Highway.h"

void Highway::draw(windowCanvas &windowCanvas){
    //draw Light

    for (int i=0;i<142;++i){
        windowCanvas.draw(2+i, y, '-', color);
    }
    for (int i=0;i<142;++i){
        windowCanvas.draw(2+i, y+6, '-', color);
    }
    windowCanvas.draw(139, y, "[" + to_string(int(curTime)) + "]", (status? 10: 12));

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
            for (int i=0, ii=lst.size(); i<ii; ++i)
            if (lst[i]->getX() + lst[i]->getWidth() < 0){
                swap(lst[i], lst.back());
                delete lst.back();
                lst.pop_back();
                int tmp = 0;
                for (auto v: lst)
                    tmp = max(tmp, v->getX() + v->getWidth());
                lst.push_back(new Dino(tmp+dis, y+2, x==-1));
                //assert(int(lst.size()) == 7);
                break;
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
