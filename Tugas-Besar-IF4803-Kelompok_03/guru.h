#ifndef GURU_H_INCLUDED
#define GURU_H_INCLUDED
#include <iostream>
using namespace std;

typedef string infotypeP;
typedef struct Guru *adrP;;

struct elmenGuru{
    infotypeP infoGuru;
    adrP next;
    adrP nextChild;
};

struct ListGuru{
    adrP first;
};

void createListGuru(ListGuru &L);
adrP createElementGuru(infotypeP x);
void insertFirsttGuru(ListGuru &L, adrP P);
void insertLastGuru(ListGuru &L, adrP p);
void insertAfterGuru(ListGuru &L, adrP p, adrP prec);
void deleteFirstGuru(ListGuru &L, adrP &p);
void deleteLastGuru(ListGuru &L, adrP &p);
void deleteAfterGuru(ListGuru &L, adrP &p, adrP prec);
adrP findElemenGuru(ListGuru L, infotypeP x);
void viewParent(ListGuru L);

#endif GURU_H_INCLUDED