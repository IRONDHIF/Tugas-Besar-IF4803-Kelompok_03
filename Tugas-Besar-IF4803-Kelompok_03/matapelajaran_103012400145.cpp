#include "matapelajaran.h"
#include <iostream>
using namespace std;

void insertFirstChild(adrP p, adrC c){
    if (p->nextChild == nullptr){
        p->nextChild = c;
    } else {
        c->next = p->nextChild;
        p->nextChild->prev = c;
        p->nextChild = c;
    }
}

void insertAfterChild(adrC prec, adrC c){
    c->next = prec->next;
    c->prev = prec;
    prec->next = c;
    if (c->next != nullptr){
        c->next->prev = c;
    }
}

void deleteLastChild(adrP p, adrC &c){
    if (p->nextChild == nullptr){
        cout << "Tidak ada child yang dapat dihapus!\n" << endl;;
    } else {
        adrC q = p->nextChild;
        while (q->next != nullptr){
            q = q->next;
        }
        c = q;
        if (q->prev == nullptr){
            p->nextChild = nullptr;
        } else {
            q->prev->next = nullptr;
        }
        c->prev = nullptr;
        cout << "Data mata pelajaran berhasil dihapus!\n" << endl;
    }
}

adrC findElemenChild(adrP p, string nama){
    adrC q = p->nextChild;
    while (q != nullptr){
        if (q->infoC.nama == nama){
            return q;
        }
        q = q->next;
    }
    return nullptr;
}
