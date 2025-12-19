#include "matapelajaran.h"
#include <iostream>

using namespace std;

adrC createElemenChild(string nama, int ID, string status){
    infotypeC x;
    adrC c = new elmenC;
    x.nama = nama;
    x.ID = ID;
    x.status = status;
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
        cout << "Tidak ada child yang dapat dihapus!\n" << endl;
    }else{
        c = p->nextChild;
        p->nextChild = c->next;
        if (p->nextChild != nullptr){
            p->nextChild->prev = nullptr;
        }
        c->next = nullptr;
        cout << "Data mata pelajaran berhasil dihapus!\n" << endl;
    }
}

void deleteAfterChild(adrC prec, adrC &c){
    c = prec->next;
    prec->next = c->next;
    c->next->prev = prec;
    c->next = nullptr;
    c->prev = nullptr;
    cout << "Data mata pelajaran berhasil dihapus!\n" << endl;
}

void viewChild(adrP p){
    adrC c = p->nextChild;
    cout << "==== Daftar mata pelajaran ====" << endl;
    while(c != nullptr){
        cout << "Nama Mata Pelajaran   : " << c->infoC.nama << endl;
        cout << "ID Mata Pelajaran     : " << c->infoC.ID << endl;
        cout << "Status Mata Pelajaran : " << c->infoC.status << endl;
        cout << "---------------------------------" << endl;
        c = c->next;
    }
    cout << endl;
}
