#include <vector>
#include <iostream>

int vypocet_skore(const std::vector<int>& hody) {
   int celkove_skore = 0;
   int frame = 0;
   int pocet_hodu = 0;

    auto bonus_za_strike = [&](){
        if(pocet_hodu + 2 < hody.size()){
            return hody[pocet_hodu + 1] + hody[pocet_hodu + 2];
        }
        if(pocet_hodu + 1 < hody.size()){
            return hody[pocet_hodu + 1];
        }
        return 0;
    };

    auto bonus_za_spare = [&](){
        if(pocet_hodu + 2 < hody.size()){
            return hody[pocet_hodu + 2];
        }
        return 0;
    };

   while (frame < 10 && pocet_hodu < hody.size()){
        if(hody[pocet_hodu] ==10){
            celkove_skore= celkove_skore + 10 + bonus_za_strike();
            pocet_hodu += 1;
        }
        else if(pocet_hodu + 1 < hody.size()) { 
            int soucet_framu = hody[pocet_hodu] + hody[pocet_hodu + 1];

            if(soucet_framu ==10){
            celkove_skore= celkove_skore + 10 + bonus_za_spare();
            pocet_hodu += 2;
            }
        }
        else {
            celkove_skore= celkove_skore + hody[pocet_hodu];
            pocet_hodu += 1;
        }
        frame++;
    }
    return celkove_skore;
}