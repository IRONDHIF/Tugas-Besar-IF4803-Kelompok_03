#include "guru.h"
#include <iostream>
using namespace std;

adrP createElementGuru(infotypeP x){
    adrP p = new elmenGuru;

    p->infoGuru = x;
    p->next = nullptr;
    p->nextChild = nullptr;

    return p;
}

void insertLastGuru(ListGuru &L, adrP p){
    if (L.first == nullptr){
        L.first = p;
    } else {
        adrP q = L.first;
        while (q->next != nullptr){
            q = q->next;
        }
        q->next = p;
    }
}

void deleteFirstGuru(ListGuru &L, adrP &p){
    if (L.first == nullptr){
        cout << "List kosong, tidak dapat dihapus!" << endl;
    } else if (L.first->next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        p = L.first;
        L.first = p->next;
        p->next = nullptr;
    }
}


void deleteAfterGuru(ListGuru &L, adrP &p, adrP prec){
    p = prec->next;
    prec->next = p->next;
    p->next = nullptr;
}

void viewParent(ListGuru L){
    adrP p;

    p = L.first;
    while (p !=  nullptr){
        cout << "Nama Guru: " << p->infoGuru << endl;
        p = p->next;
    }
}