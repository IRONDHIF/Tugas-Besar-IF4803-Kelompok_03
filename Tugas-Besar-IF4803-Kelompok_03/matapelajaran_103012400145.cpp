#include "matapelajaran.h"
#include <iostream>
using namespace std;

void insertFirstChild(adrP p, adrC c){
    if (p->nextChild == nullptr){
        p->nextChild = c;
    } else {
        c->next = p->nextChild;
        p->nextChild->prev = c;
    }
}

void insertAfterChild(adrC prec, adrC c){
    c->next = prec->next;
    c->prev = prec;
    prec->next = c;
    c->next->prev = prec;
}

void deleteLastChild(adrP p, adrC &c){
    if (p->nextChild == nullptr){
        cout << "tidak ada child yang dapat dihapsus!";
    } else {
        adrC q = p->nextChild;
        while (p->nextChild->next->next != nullptr){
            p->nextChild = p->nextChild->next;
        }
        c = q->next;
        q->next = nullptr;
        c->prev = nullptr;
    }
}

adrC findElemenChild(adrP p, infotypeC x){
    adrC q = p->nextChild;
    while (q != nullptr){
        if (q->infoC == x){
            return q;
        }
        q = q->next;
    }
    return nullptr;
}
