#ifndef MATAPELAJARAN_H_INCLUDED
#define MATAPELAJARAN_H_INCLUDED
#include <iostream>
#include "guru.h"
using namespace std;

typedef string infotypeC;
typedef struct elmenC *adrC;

struct elmenC{
    infotypeC infoC;
    adrC next;
    adrC prev;
};

void createListChild_103012400145(adrP p);
adrC createElemenChild_103012400145(infotypeC x);
void insertFirstChild_103012400145(adrP p, adrC c);
void insertLastChild_103012400145(adrP p, adrC c);
void insertAfterChild_103012400145(adrC prec, adrC c);
void deleteFirstChild_103012400145(adrP p, adrC &c);
void deleteLastChild_103012400145(adrP p, adrC &c);
void deleteAfterChild_103012400145(adrC prec, adrC &c);
adrC findElemenChild_103012400145(adrP p, infotypeC x);
void viewChild_103012400145(adrP p);

#endif MATAPELAJARAN_H_INCLUDED