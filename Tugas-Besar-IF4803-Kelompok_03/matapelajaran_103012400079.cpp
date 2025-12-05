#include "matapelajaran.h"
#include <iostream>

using namespace std;

adrC createElemenChild(infotypeC x){
    adrC c = new elmenC;
    c->infoC = x;
    c->next = nullptr;
    c->prev = nullptr;
    return c;
}
void insertLastChild(adrP p, adrC c){
    if(p->nextChild == nullptr){
        p->nextChild = c;
    }else{
        adrC q = p->nextChild;
        while(q->next != nullptr){
            q = q->next;
        }
        q->next = c;
        c->prev = q;
    }
}

void deleteFirstChild(adrP p, adrC &c){
    if(p->nextChild == nullptr){
        cout << "tidak ada childe yang dapat dihapsus!" << endl;
    }else{
        c = p->nextChild;
        p->nextChild = c->next;
        c->next->prev = nullptr;
        c->next = nullptr;
        c->prev = nullptr;
    }
}

void deleteAfterChild(adrC prec, adrC &c){
    c = prec->next;
    prec->next = c->next;
    c->next->prev = prec;
    c->next = nullptr;
    c->prev = nullptr;
}

void viewChild(adrP p){
    adrC c = p->nextChild;
    while(c != nullptr){
        cout << c->infoC << ", ";
        c = c->next;
    }
}