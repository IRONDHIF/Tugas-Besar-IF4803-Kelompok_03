#include <iostream>
#include "main.h"
#include "guru.h"
#include "matapelajaran.h"

using namespace std;

int main()
{
   ListGuru L;
   createListGuru(L);

   insertLastGuru(L, createElementGuru("Budi", "G01", 40));
    insertLastGuru(L, createElementGuru("Siti", "G02", 35));
    insertLastGuru(L, createElementGuru("Andi", "G03", 45));
    insertLastGuru(L, createElementGuru("Rina", "G04", 30));
    insertLastGuru(L, createElementGuru("Doni", "G05", 50));

    adrP p = L.first;

    // G01 - banyak mapel
    insertLastChild(p, createElemenChild("Matematika", 101, "sudah diambil"));
    insertLastChild(p, createElemenChild("Fisika", 102, "sudah diambil"));
    insertLastChild(p, createElemenChild("Statistika", 103, "sudah diambil"));

    // G02 - 1 mapel
    p = p->next;
    insertLastChild(p, createElemenChild("Kimia", 201, "sudah diambil"));

    // G03 - 2 mapel
    p = p->next;
    insertLastChild(p, createElemenChild("Biologi", 301, "sudah diambil"));
    insertLastChild(p, createElemenChild("Geografi", 302, "sudah diambil"));

    // G04 - TANPA mapel (buat test hapus guru)

    // G05 - 4 mapel
    p = p->next->next;
    insertLastChild(p, createElemenChild("Informatika", 401, "sudah diambil"));
    insertLastChild(p, createElemenChild("BasisData", 402, "sudah diambil"));
    insertLastChild(p, createElemenChild("Jaringan", 403, "sudah diambil"));
    insertLastChild(p, createElemenChild("AI", 404, "sudah diambil"));

    int option=-99;
    while (option != 0) {
        cout << "============ Menu =============" << endl;
        cout << "|| 1. Menu Admin             ||" << endl;
        cout << "|| 2. Menu User              ||" << endl;
        cout << "|| 0. exit                   ||" << endl;
        cout << "===============================" << endl;
        cout << "Pilih opsi : ";
        cin >> option;
        switch(option) {
           case 1  :
              system("cls");
              menuAdmin(L);
              break;
           case 2  :
              system("cls");
              menuUser(L);
              break;
           case 0 :
              exit(1);
           default :
              cout << "Pilihan tidak valid!\n" << endl;
        }
    }

    return 0;
}
