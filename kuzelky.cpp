#include "kuzelky.h"
#include "vypocet_skore.h"
#include <iostream>
#include <vector>

std::vector<int> hody;
int Master = 0;

void vypisZlabky() {
    for (int i = 0; i < 15; ++i) {
        std::cout << "||         ||" << "\n";
    }
}

void vypisDrahu() {
    std::vector<std::string> draha;
    switch (Master) {
    case 0: // startovací hodnota vectoru draha a jeho hodnota pro žlábek na levé půlce dráhy
    case 14: // hodnota vectoru draha pro žlábek na pravé půlce strany
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "|| 8 8 8 8 ||",
            "||  8 8 8  ||",
            "||   8 8   ||",
            "||    8    ||",
        };
        hody.push_back(0);
        break;
        // pozice na levé půlce dráhy
    case 1: // srazí jednu kuželku
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "||   8 8 8 ||",
            "||  8 8 8  ||",
            "||   8 8   ||",
            "||    8    ||",
        };
        hody.push_back(1);
        break;

    case 2:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "||   8 8 8 ||",
            "||    8 8  ||",
            "||   8 8   ||",
            "||    8    ||",
        };
        hody.push_back(2);
        break;

    case 3:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "||     8 8 ||",
            "||    8 8  ||",
            "||   8 8   ||",
            "||    8    ||",
        };
        hody.push_back(3);
        break;

    case 4:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "||     8 8 ||",
            "||    8 8  ||",
            "||     8   ||",
            "||    8    ||",
        };
        hody.push_back(4);
        break;

    case 5:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "||       8 ||",
            "||      8  ||",
            "||     8   ||",
            "||    8    ||",
        };
        hody.push_back(6);
        break;

    case 6:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "||       8 ||",
            "||         ||",
            "||         ||",
            "||         ||",
        };
        hody.push_back(9);
        break;

    case 7:
        draha = { // strike, případně použít pro spare - přidat další příkaz case n: (jako u case 0:)
            "*************",
            "||~~~~~~~~~||",
            "||         ||",
            "||         ||",
            "||         ||",
            "||         ||",
        };
        hody.push_back(10);
        break;
        // pozice na pravé půlce dráhy
    case 8:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "|| 8       ||",
            "||         ||",
            "||         ||",
            "||         ||",
        };
        hody.push_back(9);
        break;

    case 9:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "|| 8       ||",
            "||  8      ||",
            "||   8     ||",
            "||    8    ||",
        };
        hody.push_back(6);
        break;

    case 10:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "|| 8 8     ||",
            "||  8 8    ||",
            "||   8     ||",
            "||    8    ||",
        };
        hody.push_back(4);
        break;

    case 11:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "|| 8 8     ||",
            "||  8 8    ||",
            "||   8 8   ||",
            "||    8    ||",
        };
        hody.push_back(3);
        break;

    case 12:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "|| 8 8 8   ||",
            "||  8 8    ||",
            "||   8 8   ||",
            "||    8    ||",
        };
        hody.push_back(2);
        break;

    case 13:
        draha = {
            "*************",
            "||~~~~~~~~~||",
            "|| 8 8 8   ||",
            "||  8 8 8  ||",
            "||   8 8   ||",
            "||    8    ||",
        };
        hody.push_back(1);
        break;
    }
    // vypíše vector draha
    for (const auto& line : draha) {
        std::cout << line << "\n";
    }

    vypisZlabky();
}
// prozatímní implementace výpočtu z vypocet_skore.cpp
void skore() {
    std::cout << vypocetSkore(hody);
}
