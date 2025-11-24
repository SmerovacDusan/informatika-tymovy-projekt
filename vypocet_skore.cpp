#include <vector>
#include <iostream>
#include "vypocet_skore.h"

// Deklarace funkce pro výpočet skóre (Vaše implementace)
int vypocetSkore(const std::vector<int>& hody) {
    int celkoveSkore = 0;
    int indexHodu = 0; // Index pro procházení pole 'hody'

    // Smyčka projde přesně 10 framů (frame 0 až 9, což odpovídá framům 1 až 10).
    for (int frame = 0; frame < 10; ++frame) {

        // Pokud dojdou hody před koncem 10. framu, končíme
        if (indexHodu >= hody.size()) {
            break;
        }

        // --- 1. Zpracování STRIKE (10 na první hod) ---
        if (hody[indexHodu] == 10) {
            // Skóre je 10 + součet následujících dvou hodů (bonus)

            int bonus = 0;
            // Kontroluje, zda existuje první bonusový hod
            if (indexHodu + 1 < hody.size()) {
                bonus += hody[indexHodu + 1];
            }
            // Kontroluje, zda existuje druhý bonusový hod
            if (indexHodu + 2 < hody.size()) {
                bonus += hody[indexHodu + 2];
            }

            celkoveSkore += 10 + bonus;
            indexHodu += 1; // Strike spotřebuje POUZE 1 hod
        }

        // --- 2. Zpracování SPARE / OPEN FRAME ---
        // Potřebujeme alespoň dva hody k určení framu.
        else if (indexHodu + 1 < hody.size()) {
            int soucet = hody[indexHodu] + hody[indexHodu + 1];

            if (soucet == 10) {
                // SPARE
                // Skóre je 10 + součet následujícího JEDNOHO hodu (bonus)

                int bonus = 0;
                // Kontroluje, zda existuje bonusový hod (na indexu roll + 2)
                if (indexHodu + 2 < hody.size()) {
                    bonus = hody[indexHodu + 2];
                }

                celkoveSkore += 10 + bonus;
                indexHodu += 2; // Spare spotřebuje 2 hody
            }
            else {
                // OPEN FRAME 
                // Skóre je součet dvou hodů, žádný bonus
                celkoveSkore += soucet;
                indexHodu += 2; // Open Frame spotřebuje 2 hody
            }
        }

        // --- 3. NEÚPLNÝ FRAME ---
        else {
            // Započítáme jediný zbývající hod a ukončíme smyčku (neúplná hra)
            celkoveSkore += hody[indexHodu];
            break;
        }
    }

    return celkoveSkore;
}