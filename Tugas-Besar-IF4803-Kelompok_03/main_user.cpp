#include "main.h"
#include "matapelajaran.h"
#include "guru.h"
#include <iostream>

using namespace std;

void menuUser(){
    ListGuru L;
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "====== Menu Studi Kasus ====== " << endl;
        cout << "|| 1. Input data Guru (NAMA / KODE guru harus berbeda)       ||" << endl;
        cout << "|| 2. Studi Kasus 2         ||" << endl;
        cout << "|| .....dst                 ||" << endl;
        cout << "|| 0. back                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
                studiKasus1(L);
              break;
           case 2  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
            // continue for another case here
        }
    }
}

void studiKasus1(ListGuru L){
    string nama, kode;
    int umur;
    adrP q;
    adrC C;
    
    cout << "pada studicase ini kita akan memasukan data guru baru\n";
    cout << "inputkan data guru baru :\n";
    cout << "nama : ";
    cin >> nama;
    cout << "\nkode : ";
    cin >> kode;
    cout << "\numur : " << endl;
    cin >> umur;
    
    createElementGuru(nama, kode, umur);
    
    q = L.first;
    while (q != nullptr){
        if (q->infoGuru.nama == nama || q->infoGuru.kode == kode){
           cout << "KODE / NAMA guru sama";
            return;
        }
        q = q->next;
    }
    q = createElementGuru(nama, kode, umur);
    insertLastGuru(L, q);
    cout << "DATA GURU BERHASIL DIMASUKAN";
    
}

void studiKasus2(ListGuru L){
    
    cout << "pada studi case ini kita akan menghapus guru yang tidak memegang mata pelajaran sama sekali";
    adrP Q = L.first;
    while ( Q != nullptr){
        adrC Z = Q->nextChild;
        if (Z == nullptr){
            void deleteByValue(List &L, int x) {
                if (L.first == NULL) {
                    cout << "List kosong\n";
                    return;
                } else if (L.first->info == x) {
                    deleteFirst(L);
                    return;
                }

                Node* prec = L.first;
                Node* curr = L.first->next;

                while (curr != NULL && curr->info != x) {
                    prec = curr;
                    curr = curr->next;
                }

                }

                if (curr->next == NULL) {
                    deleteLast(L);
                }
                else {
                    deleteAfter(L, prec);
                }
            }

        }
    }
}

