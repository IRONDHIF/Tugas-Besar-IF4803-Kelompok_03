#ifndef MATAPELAJARAN_H_INCLUDED
#define MATAPELAJARAN_H_INCLUDED
#include <iostream>
#include "guru.h"
using namespace std;

typedef struct mataPelajaran infotypeC;
typedef struct elmenC *adrC;

struct mataPelajaran  {
    string nama;
    int ID;
    string  status;
};

struct elmenC{
    infotypeC infoC;
    adrC next;
    adrC prev;
};

void createListChild(adrP p);
adrC createElemenChild(infotypeC x);
void insertFirstChild(adrP p, adrC c);
void insertLastChild(adrP p, adrC c);
void insertAfterChild(adrC prec, adrC c);
void deleteFirstChild(adrP p, adrC &c);
void deleteLastChild(adrP p, adrC &c);
void deleteAfterChild(adrC prec, adrC &c);
adrC findElemenChild(adrP p, infotypeC x);
void viewChild(adrP p);

#endif // MATAPELAJARAN_H_INCLUDED
