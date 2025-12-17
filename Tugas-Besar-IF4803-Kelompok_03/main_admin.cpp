#include "main.h"
#include "guru.h"
#include "matapelajaran.h"

using namespace std;

void menuAdmin(ListGuru &L){
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
              menuGuru(L);
              break;
           case 2  :
              system("cls");
              menuMataPelajaran(L);
              break;
           case 0 :
              system("cls");
              break;
           default :
               cout << "Pilihan tidak valid!\n" << endl;
        }
    }
}


void menuGuru(ListGuru &L){
    int option = -99;
    adrP p = nullptr, precP;
    string nama, kode, namaPrec;
    int umur;
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
              precP = findElemenGuru(L, namaPrec);
              if (precP != nullptr){
                cout << "Masukkan nama guru: ";
                cin >> nama;
                cout << "Masukkan kode guru: ";
                cin >> kode;
                cout << "Masukkan umur guru: ";
                cin >> umur;
                p = createElementGuru(nama, kode, umur);
                insertAfterGuru(L, p, precP);
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
              precP = findElemenGuru(L, namaPrec);
              if (precP == nullptr){
                cout << "Guru dengan nama " << namaPrec << " tidak ditemukan!\n" << endl;
              } else if (precP->next == nullptr){
                cout << "Tidak ada elemen setelah nama " << namaPrec << "\n" << endl;
              } else {
                deleteAfterGuru(L, p, precP);
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

void menuMataPelajaran(ListGuru &L){
    int option = -99;
    adrP p = nullptr, tempP;
    adrC c = nullptr, precC;
    string nama, namaPrec;
    int ID;
    bool mapel;
    while (option != 0) {
        cout << "============ Menu Child ============" << endl;
        cout << "|| 1. insert first                ||" << endl;
        cout << "|| 2. insert last                 ||" << endl;
        cout << "|| 3. insert after                ||" << endl;
        cout << "|| 4. delete first                ||" << endl;
        cout << "|| 5. delete last                 ||" << endl;
        cout << "|| 6. delete after                ||" << endl;
        cout << "|| 7. tampilkan mata pelajaran    ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              system("cls");
              cout << "Masukkan nama guru yang akan mengambil mata pelajaran: ";
              cin >> nama;
              p = findElemenGuru(L, nama);
              if (p == nullptr){
                  cout << "Nama guru tidak ditemukan!\n" << endl;
                  break;
              }
              cout << "Masukkan nama mata pelajaran: ";
              cin >> nama;
              if (findElemenChild(p, nama) != nullptr){
                cout << "Guru ini sudah memiliki mata pelajaran tersebut!\n" << endl;
                break;
              }
              mapel = false;
              tempP = L.first;
              while (tempP != nullptr){
                if (findElemenChild(tempP, nama) != nullptr){
                    cout << "Mata pelajaran ini sudah dimiliki oleh guru lain!" << endl;
                    mapel = true;
                    break;
                }
                tempP = tempP->next;
              }
              if (!mapel){
                cout << "Masukkan kode mata pelajaran: ";
                cin >> ID;
                c = createElemenChild(nama, ID, "Diambil");
                insertFirstChild(p, c);
                system("cls");
              }
              break;
           case 2  :
              system("cls");
              cout << "Masukkan nama guru yang akan mengambil mata pelajaran: ";
              cin >> nama;
              p = findElemenGuru(L, nama);
              if (p == nullptr){
                  cout << "Nama guru tidak ditemukan!\n" << endl;
                  break;
              }
              cout << "Masukkan nama mata pelajaran: ";
              cin >> nama;
              if (findElemenChild(p, nama) != nullptr){
                cout << "Guru ini sudah memiliki mata pelajaran tersebut!\n" << endl;
                break;
              }
              mapel = false;
              tempP = L.first;
              while (tempP != nullptr){
                if (findElemenChild(tempP, nama) != nullptr){
                    cout << "Mata pelajaran ini sudah dimiliki oleh guru lain!" << endl;
                    mapel = true;
                    break;
                }
                tempP = tempP->next;
              }
              if (!mapel){
                cout << "Masukkan kode mata pelajaran: ";
                cin >> ID;
                c = createElemenChild(nama, ID, "Diambil");
                insertLastChild(p, c);
                system("cls");
              }
              break;
           case 3 :
              system("cls");
              cout << "Masukkan nama guru yang akan mengambil mata pelajaran: ";
              cin >> nama;
              p = findElemenGuru(L, nama);
              if (p == nullptr){
                  cout << "Nama guru tidak ditemukan!\n" << endl;
                  break;
              }
              cout << "Masukkan nama mata pelajaran prec: ";
              cin >> namaPrec;
              precC = findElemenChild(p, namaPrec);
              if (precC != nullptr){
                cout << "Masukkan nama mata pelajaran: ";
                cin >> nama;
                if (findElemenChild(p, nama) != nullptr){
                    cout << "Guru ini sudah memiliki mata pelajaran tersebut!\n" << endl;
                    break;
                }
                mapel = false;
                tempP = L.first;
                while (tempP != nullptr){
                    if (findElemenChild(tempP, nama) != nullptr){
                        cout << "Mata pelajaran ini sudah dimiliki oleh guru lain!" << endl;
                        mapel = true;
                        break;
                    }
                    tempP = tempP->next;
                }
                if (!mapel){
                    cout << "Masukkan kode mata pelajaran: ";
                    cin >> ID;
                    c = createElemenChild(nama, ID, "Diambil");
                    insertAfterChild(precC, c);
                    system("cls");
                }
              } else {
                cout << "Mata pelajaran " << namaPrec << " tidak ditemukan!\n" << endl;
              }
              break;
           case 4 :
              system("cls");
              if (p == nullptr){
                cout << "Tidak ada mata pelajaran yang dapat dihapus!\n" << endl;
                break;
              } else {
                deleteFirstChild(p, c);
              }
              break;
           case 5 :
              system("cls");
              if (p == nullptr){
                cout << "Tidak ada mata pelajaran yang dapat dihapus!\n" << endl;
                break;
              } else {
                deleteLastChild(p, c);
              }
              break;
           case 6 :
              system("cls");
              cout << "Masukkan nama mata pelajaran prec: ";
              cin >> namaPrec;
              if (p == nullptr){
                cout << "Mata pelajaran "<< namaPrec << " tidak ditemukan!\n" << endl;
                break;
              } else {
                precC = findElemenChild(p, namaPrec);
              }
              if (precC == nullptr){
                cout << "Mata pelajaran " << namaPrec << " tidak ditemukan!\n" << endl;
              } else if (precC->next == nullptr){
                cout << "Tidak ada elemen setelah mata pelajaran " << namaPrec << "\n" << endl;
              } else {
                deleteAfterChild(precC, c);
              }
              break;
           case 7 :
              system("cls");
              if (c == nullptr){
                cout << "==== Daftar mata pelajaran ====\n" << endl;
              } else {
                viewChild(p);
              }
              break;
           case 0 :
              system("cls");
              break;
           default :
              cout << "Pilihan tidak valid!\n" << endl;
        }
    }
}
