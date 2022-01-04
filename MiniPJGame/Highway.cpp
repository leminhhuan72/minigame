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
        timepass = speedSetting(mSpeed);
    }
    if (status){
        timepass -= t;
        if (timepass <= 0){
            timepass = speedSetting(mSpeed);
            for (auto u: lst){
                u->moveTo(x, 0);
            }
            if (x == -1){
                for (int i=0, ii=lst.size(); i<ii; ++i)
                if (lst[i]->getX() + lst[i]->getWidth() < 0){
                    swap(lst[i], lst.back());
                    delete lst.back();
                    lst.pop_back();
                    int tmp = 0;
                    for (auto v: lst)
                        tmp = max(tmp, v->getX() + v->getWidth());
                    lst.push_back(createObject(tmp+dis));
                    //assert(int(lst.size()) == 7);
                    break;
                }
            }else{
                for (int i=0, ii=lst.size(); i<ii; ++i)
                if (lst[i]->getX() >= 200){
                    swap(lst[i], lst.back());
                    delete lst.back();
                    lst.pop_back();
                    int tmp =200;
                    for (auto v: lst)
                        tmp = min(tmp, v->getX());
                    lst.push_back(createObject(tmp-dis-lst.back()->getWidth()));
                    //assert(int(lst.size()) == 7);
                    break;
                }
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
Object* Highway::createObject(int i) {
    if (typeObstacle == 0) {
        return new Bicycle(i, y+2, x==-1);
    } else
    if (typeObstacle == 1) {
        return new Car(i, y+2, x==-1);
    } else
    if (typeObstacle == 2) {
        return new Cow(i, y+2, x==-1);
    }else
    if (typeObstacle == 3){
        return new Dino(i, y+2, x==-1);
    }
    return new Owl(i, y+2, x==-1);
}
double Highway::speedSetting(double t) {
    return 0.5 / t;
}
