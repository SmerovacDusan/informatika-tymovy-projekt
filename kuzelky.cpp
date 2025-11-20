#include "kuzelky.h"
#include <iostream>
#include <vector>

void vypisZlabky() {
    for (int i = 0; i < 20; ++i) {
        std::cout << "||         ||" << "\n";
    }
}

void vypisDrahu(int pozice) {
    std::vector<std::string> draha;
    switch(pozice) {
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
            break;
    }
    // vypíše vector draha
    for (const auto& line : draha) {
        std::cout << line << "\n";
    }

    vypisZlabky();
}