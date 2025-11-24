#include "kuzelky.h"
#include "draha.h"
#include <thread>
#include <atomic>
#include <iostream>
#include <cstdlib>

int main() {
	int i = 0;
    while(true)
    {

        std::atomic<bool> run(true);
        int prubeh = 0;

        // Vlákno dráhy
        std::thread anim([&]() {

            system("clear");             // vyčistit konzoli
            vypisDrahu(prubeh);          // první kuželky
            std::cout << "\n";           // oddělovač
            vykresliDrahu(prubeh, run);     // pak dráhu
            std::this_thread::sleep_for(std::chrono::milliseconds(150));

            });

        // Čekání na ENTER
        std::cin.get();

        // stop dráhy
        run = false;
        anim.join();

        // předání prubehu → pozice
        pozice = prubeh;

        // znovu překreslit kuželky podle Master
        system("clear");
        vypisDrahu(pozice);

        //druhe kolo
        run = true;

        std::thread anim2([&]() {

            system("clear");             // vyčistit konzoli
            vypisDrahu(prubeh);          // první kuželky
            std::cout << "\n";           // oddělovač
            vykresliDrahu(prubeh, run);     // pak dráhu
            std::this_thread::sleep_for(std::chrono::milliseconds(150));

            });

        // Čekání na ENTER
        std::cin.get();

        // stop dráhy
        run = false;
        anim2.join();

        // předání prubehu → pozice
        pozice2 = prubeh;

        // znovu překreslit kuželky podle Master
        system("clear");
        vypisDrahu2(pozice2, pozice);



        i++;
		if (i >= 10) break; // ukončí po 10 kolech
    }
	//vypis celeho skore
    std::cout << "Konec hry! Celkove skore: ";
     skore();
	 std::cout << "\n";

    return 0;
}
