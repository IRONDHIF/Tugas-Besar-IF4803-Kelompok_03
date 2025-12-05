#include "guru.h";

void createListGuru(ListGuru &L){
    L.first = nullptr;
}

void insertFirsttGuru(ListGuru &L, adrP P){}
void insertLastGuru(ListGuru &L, adrP p);
void insertAfterGuru(ListGuru &L, adrP p, adrP prec);
void deleteFirstGuru(ListGuru &L, adrP &p);
void deleteLastGuru(ListGuru &L, adrP &p);
void deleteAfterGuru(ListGuru &L, adrP &p, adrP prec);
adrP findElemenGuru(ListGuru L, infotypeP x);
void viewParent(ListGuru L);