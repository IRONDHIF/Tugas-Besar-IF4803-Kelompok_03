#include "main.h"
#include "matapelajaran.h"
#include "guru.h"
#include <iostream>

using namespace std;

void menuUser(ListGuru &L){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "====== Menu Studi Kasus ====== " << endl;
        cout << "|| 1. Menampilakan Guru dan Matapelajaran                    ||" << endl;
        cout << "|| 2. Input data Guru (NAMA / KODE guru harus berbeda)       ||" << endl;
        cout << "|| 3. Menghapus guru yang tidak memiliki matapelajaran       ||" << endl;
        cout << "|| 4. Menghapus matapelajaran dari guru tertentu             ||" << endl;
        cout << "|| 5. Menghitung matapelajaran yang dipegang setiap guru     ||" << endl;
        cout << "|| 6. "
        cout << "|| 0. back                                                   ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
                printGuruMatapelajaran(L);
              break;
           case 2  :
              cout << "you choose option 2" << endl;
                studiKasus1(L);

              break;
            case 3 :
                cout << " you choose option 3" << endl;
                studiKasus2(L);
                break;
            case 4 :
                cout << "you choose option 4" << endl;
                studiKasus3(L);
                break;
            case 5 :
                cout << "you choose option 5" << endl;
                studiKasus4(L);
                break;
           case 0  :
              cout << "Back to main menu..." << endl;
              break;
        }
    }
}

void studiKasus1(ListGuru &L){
    string nama, kode;
    int umur;
    adrP q;
    cout << "pada studicase ini kita akan memasukan data guru baru\n";
    cout << "inputkan data guru baru :\n";
    cout << "nama : ";
    cin >> nama;
    cout << "\nkode : ";
    cin >> kode;
    cout << "\numur : ";
    cin >> umur;
        
    q = L.first;
    while (q != nullptr){
        if (q->infoGuru.nama == nama || q->infoGuru.kode == kode){
           cout << "KODE / NAMA guru sama";
            return;
        }
        q = q->next;
    }
    cout << "halo";
    adrP p = createElementGuru(nama, kode, umur);
    insertLastGuru(L, p );
    cout << "DATA GURU BERHASIL DIMASUKAN";
    
}

void studiKasus2(ListGuru &L){
    int hapus = 0;
    cout << "pada studi case ini kita akan menghapus guru yang tidak memegang mata pelajaran sama sekali";
    cout << "Menghapus Guru yang tidak memiliki matakpelajaran..." << endl;
    adrP Q = L.first;
    while ( Q != nullptr){
        adrC Z = Q->nextChild;
        if (Z == nullptr){
            hapus++;
            if (Q == L.first){
                deleteFirstGuru(L, Q);
            } else if (Q->next == nullptr){
                deleteLastGuru(L, Q);
            } else {
                adrP P = L.first;
                while (P->next != Q){
                    P = P->next;
                }
                deleteAfterGuru(L, P, Q);
            }
        }
        Q = Q->next;
    }
    if (hapus == 0){
        cout << "Tidak ada guru yang tidak memegang mata pelajaran." << endl;
        return;
    }
    cout << "Semua guru yang tidak memegang mata pelajaran telah dihapus." << endl;
}

void printGuruMatapelajaran(ListGuru L){
    adrP P = L.first;
    if (P == nullptr){
        cout << "Tidak ada data guru." << endl;
        return;
    }
    cout << "Daftar Guru dan Mata Pelajaran:" << endl;
    while (P != nullptr){
        cout << "==============================" << endl;
        cout << "Nama Guru: " << P->infoGuru.nama << "\nKode: " << P->infoGuru.kode << "\nUmur: " << P->infoGuru.umur << endl;
        cout << "------------------------------" << endl;
        adrC C = P->nextChild;
        if (C == nullptr){
            cout << "  Tidak ada mata pelajaran." << endl;
        } else {
            cout << "  Mata Pelajaran: ";
            while (C != nullptr){
                cout << C->infoC.nama << " (" << C->infoC.ID << "), ";
                C = C->next;
            }
            cout << endl;
        }
        P = P->next;
    }
    cout << "==============================" << endl;
}

void studiKasus3(ListGuru &L){
    cout << "pada studicase ini kita akan menghapus mata pelajaran tertentu dari guru tertentu\n";
    string kodeGuru;
    int kodeMatapelajaran;
    cout << "Masukkan kode guru: ";
    cin >> kodeGuru;
    cout << "Masukkan kode mata pelajaran: ";
    cin >> kodeMatapelajaran;

    adrP P = L.first;
    while (P != nullptr && P->infoGuru.kode != kodeGuru){
        P = P->next;
    }
    if (P == nullptr){
        cout << "Guru dengan kode tersebut tidak ditemukan." << endl;
        return;
    } else {
        adrC C = P->nextChild;
        while (C != nullptr && C->infoC.ID != kodeMatapelajaran){
            C = C->next;
        }
        if (C == nullptr){
            cout << "Mata pelajaran dengan kode tersebut tidak ditemukan untuk guru ini." << endl;
            return;
        } else {
            if (C == P->nextChild){
                deleteFirstChild(P, C);
            } else if (C->next == nullptr){
                deleteLastChild(P, C);
            } else {
                adrC Z = P->nextChild;
                while (Z->next != C){
                    Z = C->next;
                }
                deleteAfterChild(Z, C);
            }

            cout << "Mata pelajaran berhasil dihapus dari guru." << endl;
        }
    }

}

void studiKasus4(ListGuru L){
    cout << "pada studicase ini kita akan menghitung jumlah mata pelajaran yang dipegang oleh setiap guru\n";
    adrP P = L.first;
    while (P != nullptr){
        int jumlah = 0;
        adrC C = P->nextChild;
        while (C != nullptr){
            jumlah++;
            C = C->next;
        }
        cout << "Guru " << P->infoGuru.nama << " mengajar " << jumlah << " mata pelajaran." << endl;
        P = P->next;
    }

}
