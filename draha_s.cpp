#include "draha.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// zde definovat funkce/třídy/struktury potřebné pro vypsání dráhy
// přidat potřebné knihovny pomocí #include

/*Draha::Draha() {
    // inicializace datových členů

}*/

/*
void Draha::vypisDrahu() {
    // implementace vypsání dráhy
    
    cout << "*************" << endl;
    cout << "||~~~~~~~~~||" << endl;
    cout << "|| 8 8 8 8 ||" << endl;
    cout << "||  8 8 8  ||" << endl;
    cout << "||   8 8   ||" << endl;
    cout << "||    8    ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "||         ||" << endl;
    cout << "|...........|" << endl;
    cout << "| xxx o xxx |" << endl;
    cout << "|...........|" << endl;
    cout << "|     O     |" << endl;
    cout << "|    -|-o   |" << endl;
    cout << "|    / \\    |" << endl;
    cout << "|      |ooo||" << endl;
    cout << "|~~~~~~~~~~~|" << endl; 
    cout << "*************" << endl;
}
*/


void vypisDrahu() {
    vector<string> draha = {
        "*************",
        "||~~~~~~~~~||",
        "|| 8 8 8 8 ||",
        "||  8 8 8  ||",
        "||   8 8   ||",
        "||    8    ||",};
        
    for (const auto& line : draha) {
        cout << line << endl;
    }

    for (int i = 0; i < 20; ++i) {
        cout << "||         ||" << endl;
    }
    vector<string> bottom = {
        "|...........|",
        "| xxx o xxx |",
        "|...........|",
        "|     O     |",
        "|    -|-o   |",
        "|    / \\    |",
        "|      |ooo||",
        "|~~~~~~~~~~~|",
        "*************"
    };
    for (const auto& line : bottom) {
        cout << line << endl;
    }
}