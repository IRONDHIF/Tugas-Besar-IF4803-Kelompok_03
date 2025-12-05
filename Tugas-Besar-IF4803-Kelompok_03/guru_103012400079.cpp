#include "guru.h"
#include <iostream>

using namespace std;

void createListGuru(ListGuru &L){
    L.first = nullptr;
}

void insertFirsttGuru(ListGuru &L, adrP P){
    if(L.first == nullptr){
        L.first = P;
    }else{
        P->next = L.first;
        L.first = P;
    }
}

void insertAfterGuru(ListGuru &L, adrP p, adrP prec){
    //digukan untuk menyisipkan elemen di tengah list yang sudah terdefinisi
    p->next = prec->next;
    prec->next = p;
}

void deleteLastGuru(ListGuru &L, adrP &p){
    adrP q = L.first;
    if(L.first != nullptr){
        cout << "List kosong, tidak dapat dihapus!" << endl;
    }else if(q->next == nullptr){
            p = L.first;
            L.first = nullptr;
    }else{
        while(q->next->next != nullptr){
            q = q->next;
            }
            p = q->next;
            q->next = nullptr;
    }
}

adrP findElemenGuru(ListGuru L, infotypeP x);
