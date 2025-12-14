#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <iostream>
#include "matapelajaran.h"
#include "guru.h"

using namespace std;

void menuAdmin();
void menuGuru();
void menuMataPelajaran();
void menuUser();

void studiKasus1(ListGuru &L);
void studiKasus2(ListGuru &L);
void printGuruMatapelajaran(ListGuru L);
void studiKasus3();
#endif // MAIN_H_INCLUDED
