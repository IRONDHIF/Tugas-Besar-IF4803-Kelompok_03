#ifndef GURU_H_INCLUDED
#define GURU_H_INCLUDED
#include <iostream>
using namespace std;

typedef string infotype;
typedef struct Guru* adrP;;

struct elmenGuru{
    infotype infoGuru;
    adrP next;
    adrP nextChild;
};

struct ListGuru{
    adrP first;
};

void createListGuru_103012400079(ListGuru &L);
adrP createElementGuru_103012400079(infotype x);
void insertFirsttGuru_103012400079(ListGuru &L, adrP P);
void insertLastGuru_103012400079(ListGuru &L, adrP p);
void insertAfterGuru_103012400079(ListGuru &L, adrP p, adrP prec);
void deleteFirstGuru_103012400079(ListGuru &L, adrP &p);
void deleteLastGuru_103012400079(ListGuru &L, adrP &p);
void deleteAfterGuru_103012400079(ListGuru &L, adrP &p, adrP prec);
adrP findElemenGuru_103012400079(ListGuru L, infotype x);
void viewParent_103012400079(ListGuru L);

#endif GURU_H_INCLUDED