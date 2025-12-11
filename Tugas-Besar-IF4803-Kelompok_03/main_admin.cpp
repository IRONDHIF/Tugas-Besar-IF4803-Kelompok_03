#include "main.h"
#include "guru.h"
#include "matapelajaran.h"

ListGuru L;
adrP p;

void menuAdmin(){
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Admin============ " << endl;
        cout << "|| 1. Parent                 ||" << endl;
        cout << "|| 2. Child                  ||" << endl;
        cout << "|| 0. back                   ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              menuGuru();
              break;
           case 2  :
              cout << "you choose option 2" << endl;
              menuMataPelajaran();
              break;

              default :
               break;
        }
    }
}


void menuGuru(){
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Parent============ " << endl;
        cout << "|| 1. insert first          ||" << endl;
        cout << "|| 2. insert last           ||" << endl;
        cout << "|| .....dst                 ||" << endl;
        cout << "|| 0. back                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              insertFirsttGuru(L, p);

              break;
           case 2  :
              cout << "you choose option 2" << endl;
              // write your code here
              break;

            default :
                break;
        }
    }
}

void menuMataPelajaran(){
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Child============ " << endl;
        cout << "|| 1. insert first          ||" << endl;
        cout << "|| 2. insert last           ||" << endl;
        cout << "|| .....dst                 ||" << endl;
        cout << "|| 0. back                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              // write your code here

              break;
           case 2  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
            default :
                break;
        }
    }
}