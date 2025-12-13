#include "main.h"
#include "guru.h"
#include "matapelajaran.h"

using namespace std;

ListGuru L;
adrP p, prec;
infotypeP x;
string nama, kode, status, namaPrec;
int umur, ID;

void menuAdmin(){
    int option = -99;
    while (option != 0) {
        cout << "============ Menu Admin ============" << endl;
        cout << "|| 1. Parent                      ||" << endl;
        cout << "|| 2. Child                       ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilih opsi : ";
        cin >> option;
        switch(option) {
           case 1  :
              system("cls");
              menuGuru();
              break;
           case 2  :
              system("cls");
              menuMataPelajaran();
              break;
           case 0 :
              system("cls");
              break;
           default :
               cout << "Pilihan tidak valid!\n" << endl;
        }
    }
}


void menuGuru(){
    int option = -99;
    while (option != 0) {
        cout << "============ Menu Parent ===========" << endl;
        cout << "|| 1. insert first                ||" << endl;
        cout << "|| 2. insert last                 ||" << endl;
        cout << "|| 3. insert after                ||" << endl;
        cout << "|| 4. delete first                ||" << endl;
        cout << "|| 5. delete last                 ||" << endl;
        cout << "|| 6. delete after                ||" << endl;
        cout << "|| 7. tampilkan guru              ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilih opsi : ";
        cin >> option;
        switch(option) {
           case 1  :
              system("cls");
              cout << "Masukkan nama guru: ";
              cin >> nama;
              cout << "Masukkan kode guru: ";
              cin >> kode;
              cout << "Masukkan umur guru: ";
              cin >> umur;
              p = createElementGuru(nama, kode, umur);
              insertFirsttGuru(L, p);
              system("cls");
              break;
           case 2  :
              system("cls");
              cout << "Masukkan nama guru: ";
              cin >> nama;
              cout << "Masukkan kode guru: ";
              cin >> kode;
              cout << "Masukkan umur guru: ";
              cin >> umur;
              p = createElementGuru(nama, kode, umur);
              insertLastGuru(L, p);
              system("cls");
              break;
           case 3 :{
              system("cls");
              cout << "Masukkan nama guru prec: ";
              cin >> namaPrec;
              prec = findElemenGuru(L, namaPrec);
              if (prec != nullptr){
                cout << "Masukkan nama guru: ";
                cin >> nama;
                cout << "Masukkan kode guru: ";
                cin >> kode;
                cout << "Masukkan umur guru: ";
                cin >> umur;
                p = createElementGuru(nama, kode, umur);
                insertAfterGuru(L, p, prec);
                system("cls");
              } else {
                cout << "Guru dengan nama " << namaPrec << " tidak ditemukan!\n" << endl;
              }
              break;
           }
           case 4 :
              system("cls");
              deleteFirstGuru(L, p);
              break;
           case 5 :
              system("cls");
              deleteLastGuru(L, p);
              break;
           case 6 :
              system("cls");
              cout << "Masukkan nama guru prec: ";
              cin >> namaPrec;
              prec = findElemenGuru(L, namaPrec);
              if (prec == nullptr){
                cout << "Guru dengan nama " << namaPrec << " tidak ditemukan!\n" << endl;
              } else if (prec->next == nullptr){
                cout << "Tidak ada elemen setelah nama " << namaPrec << "\n" << endl;
              } else {
                deleteAfterGuru(L, p, prec);
              }
              break;
           case 7 :
              system("cls");
              viewParent(L);
              break;
           case 0 :
              system("cls");
              break;
           default :
              cout << "Pilihan tidak valid!\n" << endl;
        }
    }
}

void menuMataPelajaran(){
    int option = -99;
    while (option != 0) {
        cout << "============ Menu Child ============" << endl;
        cout << "|| 1. insert first                ||" << endl;
        cout << "|| 2. insert last                 ||" << endl;
        cout << "|| 3. insert after                ||" << endl;
        cout << "|| 4. delete first                ||" << endl;
        cout << "|| 5. delete last                 ||" << endl;
        cout << "|| 6. delete after                ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              // write your code here
              break;
           case 2  :
              // write your code here
              break;
           case 0 :
              system("cls");
              break;
        }
    }
}
