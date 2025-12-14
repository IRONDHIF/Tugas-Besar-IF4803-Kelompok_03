#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <iostream>
#include "matapelajaran.h"
#include "guru.h"

using namespace std;

void menuAdmin(ListGuru &L);
void menuGuru(ListGuru &L);
void menuMataPelajaran(ListGuru &L);
void menuUser(ListGuru &L);

void studiKasus1(ListGuru &L);
void studiKasus2(ListGuru &L);
void printGuruMatapelajaran(ListGuru L);
void studiKasus3(ListGuru &L);
void studiKasus4(ListGuru L);
#endif // MAIN_H_INCLUDED
