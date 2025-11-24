#include "kuzelky.h"
#include "vypocet_skore.h"
#include <iostream>
#include <vector>

std::vector<double> hody;
int pozice = 0;
int pozice2 = 0;

void vypisZlabky() {
    for (int i = 0; i < 15; ++i) {
        std::cout << "||         ||" << "\n";
    }
}

std::vector<std::string> getDraha(int pozice) {
    std::vector<std::string> draha;
    switch (pozice) {
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
        hody.push_back(0.5);
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
        hody.push_back(1);
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
        hody.push_back(1.5);
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
        hody.push_back(2);
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
        hody.push_back(3);
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
        hody.push_back(4.5);
        break;

    case 7:
        draha = { // strike, případně použít pro spare - přidat další příkaz case n: (jako u case 0:)

            //chybove potreba opravit pokud se hodi strike ci spare
            //nevypysuje spravne body

            "*************",
            "||~~~~~~~~~||",
            "||         ||",
            "||         ||",
            "||         ||",
            "||         ||",
        };
        hody.push_back(5);
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
        hody.push_back(4.5);
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
        hody.push_back(3);
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
        hody.push_back(2);
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
        hody.push_back(1.5);
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
        hody.push_back(1);
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
        hody.push_back(0.5);
        break;

    }

    return draha;
}

void vypisDrahu(int pozice) {
    auto draha = getDraha(pozice);

    for (auto& l : draha)
        std::cout << l << "\n";

    vypisZlabky();
}

static std::vector<std::string> getDraha2(int pozice2, int pozice) {
    std::vector<std::string> draha2;

    switch (pozice2) {
    case 0:
    case 14:
        draha2 = getDraha(pozice);
        break;
    case 1:
        if (pozice == 0 || pozice == 14) {
            draha2 = getDraha(1);
        }
        else if (pozice == 8) {
            draha2 = getDraha(7); // spare
        }
        else if (pozice == 9) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||  8      ||",
                "||   8     ||",
                "||    8    ||",
            };
            hody.push_back(6);
        }
        else if (pozice == 10) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8     ||",
                "||  8 8    ||",
                "||   8     ||",
                "||    8    ||",
            };
            hody.push_back(4);
        }
        else if (pozice == 11) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8     ||",
                "||  8 8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(3);
        }
        else if (pozice == 12) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8 8   ||",
                "||  8 8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 13) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8 8   ||",
                "||  8 8 8  ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(1);
        }
        else {
            draha2 = getDraha(pozice);
        }
        break;

    case 2:
        if (pozice == 0 || pozice == 1 || pozice == 14) {
            draha2 = getDraha(2);
        }
        else if (pozice == 8) {
            draha2 = getDraha(7); // spare
        }
        else if (pozice == 9) {
            draha2 = getDraha2(1, pozice); // Nahradit rekurzivní volání správným getterem
        }
        else if (pozice == 10) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8     ||",
                "||    8    ||",
                "||   8     ||",
                "||    8    ||",
            };
            hody.push_back(4);
        }
        else if (pozice == 11) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8     ||",
                "||    8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(3);
        }
        else if (pozice == 12) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8 8   ||",
                "||    8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 13) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8 8   ||",
                "||    8 8  ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(1);
        }
        else {
            draha2 = getDraha(pozice);
        }
        break;

    case 3:
        if (pozice == 0 || pozice == 1 || pozice == 2 || pozice == 14) {
            draha2 = getDraha(3);
        }
        else if (pozice == 10) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||    8    ||",
                "||   8     ||",
                "||    8    ||",
            };
            hody.push_back(4);
        }
        else if (pozice == 11) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||    8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(3);
        }
        else if (pozice == 12) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||     8   ||",
                "||    8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 13) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||     8   ||",
                "||    8 8  ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(1);
        }
        else {
            draha2 = getDraha2(2, pozice);
        }
        break;

    case 4:
        if (pozice == 0 || pozice == 1 || pozice == 2 || pozice == 3 || pozice == 14) {
            draha2 = getDraha(4);
        }
        else if (pozice == 9) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||         ||",
                "||         ||",
                "||    8    ||",
            };
            hody.push_back(5);
        }
        else if (pozice == 10) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||    8    ||",
                "||         ||",
                "||    8    ||",
            };
            hody.push_back(4);
        }
        else if (pozice == 11) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||    8    ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(3);
        }
        else if (pozice == 12) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||     8   ||",
                "||    8    ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 13) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||     8   ||",
                "||    8 8  ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(1);
        }
        else {
            draha2 = getDraha(pozice);
        }
        break;

    case 5:
        if (pozice == 9 || pozice == 10) {
            draha2 = getDraha2(4, 9);
        }
        else if (pozice == 11 || pozice == 12) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||         ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 13) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||      8  ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(1);
        }
        else if (pozice == 6 || pozice == 7 || pozice == 8) {
            draha2 = getDraha(pozice); // spare
        }
        else {
            draha2 = getDraha(5);
        }
        break;

    case 6:
        if (pozice == 7 || pozice == 8 || pozice == 9 || pozice == 10 || pozice == 11 || pozice == 12 || pozice == 13) {
            draha2 = getDraha(7); // spare
        }
        else {
            draha2 = getDraha(6);
        }
        break;

    case 7:
        draha2 = getDraha(7); // strike
        break;

    case 8:
        if (pozice == 0 || pozice == 14 || pozice == 8 || pozice == 9 || pozice == 10 || pozice == 11 || pozice == 12 || pozice == 13) {
            draha2 = getDraha(8);
        }
        else {
            draha2 = getDraha(7); // spare
        }
        break;

    case 9:
        if (pozice == 1) {
            draha2 = getDraha2(1, 9);
        }
        else if (pozice == 2 || pozice == 3)
        {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||         ||",
                "||   8     ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 4 || pozice == 5)
        {
            draha2 = getDraha2(4, 9);
        }
        else if (pozice == 6 || pozice == 7)
        {
            draha2 = getDraha(7); // spare
        }
        else {
            draha2 = getDraha(9);
        }
        break;

    case 10:
        if (pozice == 1) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8     ||",
                "||  8 8    ||",
                "||   8     ||",
                "||    8    ||",
            };
            hody.push_back(1);
        }
        else if (pozice == 2) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8     ||",
                "||    8    ||",
                "||   8     ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 3)
        {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||    8    ||",
                "||   8     ||",
                "||    8    ||",
            };
            hody.push_back(3);
        }
        else if (pozice == 4)
        {
            draha2 = getDraha2(4, 9);
        }
        else if (pozice == 5)
        {
            draha2 = getDraha2(4, 10);
        }
        else if (pozice == 6 || pozice == 7)
        {
            draha2 = getDraha(7); // spare
        }
        else if (pozice == 8 || pozice == 9) {
            draha2 = getDraha(pozice);
        }
        else {
            draha2 = getDraha(10);
        }
        break;

    case 11:
        if (pozice == 0 || pozice == 14 || pozice == 11 || pozice == 12 || pozice == 13) {
            draha2 = getDraha(11);
        }
        else if (pozice == 6) {
            draha2 = getDraha(7); // spare
        }
        else if (pozice == 5) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||         ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(5);
        }
        else if (pozice == 4) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||    8    ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(4);
        }
        else if (pozice == 3) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||    8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(3);
        }
        else if (pozice == 2) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8     ||",
                "||    8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 1) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8     ||",
                "||  8 8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(1);
        }
        else {
            draha2 = getDraha(pozice);
        }
        break;

    case 12:
        if (pozice == 12 || pozice == 13 || pozice == 0 || pozice == 14) {
            draha2 = getDraha(12);
        }
        else if (pozice == 6) {
            draha2 = getDraha(7); // spare
        }
        else if (pozice == 5) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||         ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(6);
        }
        else if (pozice == 4) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||     8   ||",
                "||    8    ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(4);
        }
        else if (pozice == 3) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||     8   ||",
                "||    8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(3);
        }
        else if (pozice == 2) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8 8   ||",
                "||    8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 1) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8 8   ||",
                "||  8 8    ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(1);
        }
        else {
            draha2 = getDraha(pozice);
        }
        break;

    case 13:
        if (pozice == 13 || pozice == 0 || pozice == 14) {
            draha2 = getDraha(13);
        }
        else if (pozice == 6) {
            draha2 = getDraha(7); // spare
        }
        else if (pozice == 5) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||         ||",
                "||      8  ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(6);
        }
        else if (pozice == 4) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||     8   ||",
                "||    8 8  ||",
                "||     8   ||",
                "||    8    ||",
            };
            hody.push_back(4);
        }
        else if (pozice == 3) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||     8   ||",
                "||    8 8  ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(3);
        }
        else if (pozice == 2) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8 8   ||",
                "||    8 8  ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(2);
        }
        else if (pozice == 1) {
            draha2 = {
                "*************",
                "||~~~~~~~~~||",
                "||   8 8   ||",
                "||  8 8 8  ||",
                "||   8 8   ||",
                "||    8    ||",
            };
            hody.push_back(1);
        }
        else {
            draha2 = getDraha(pozice);
        }
        break;
    default:
        draha2 = getDraha(pozice);
        break;
    }

    return draha2;
}

// upravená vypisDrahu2: teď jen tiskne výsledky getDraha2
void vypisDrahu2(int pozice2, int pozice) {
    auto draha2 = getDraha2(pozice2, pozice);
    for (auto& l : draha2)
        std::cout << l << "\n";
    vypisZlabky();
}

// prozatímní implementace výpočtu z vypocet_skore.cpp
void skore() {
    std::cout << vypocetSkore(hody);
}
