#include "kuzelky.h"
#include "draha.h"
#include <thread>
#include <atomic>
#include <iostream>
#include <cstdlib>

int main() {
    std::atomic<bool> run(true);
    int prubeh = 0;

    // Vlákno dráhy
    std::thread anim([&]() {
        
            system("clear");             // vyčistit konzoli
            vypisDrahu();          // první kuželky
            std::cout << "\n";           // oddělovač
            vykresliDrahu(prubeh, run);     // pak dráhu
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
  
        });

    // Čekání na ENTER
    std::cin.get();

    // stop dráhy
    run = false;
    anim.join();

    // předání prubehu → Master
    Master = prubeh;

    // znovu překreslit kuželky podle Master
    system("clear");
    vypisDrahu();

    return 0;
}
