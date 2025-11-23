#include "draha.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <functional>
#include <atomic>

// zde definovat funkce/třídy/struktury potřebné pro vypsání dráhy
// přidat potřebné knihovny pomocí #include


void vykresliDrahu(int& prubeh, std::atomic<bool>& run)
{
    
    int count = 0;

    while (run.load())
    {
        std::cout << "\r\033[K";
        int pos; // určí kolik mezer bude před "0"

        if (prubeh <= 1) pos = 0;
        else if (prubeh <= 3) pos = 2;
        else if (prubeh <= 5) pos = 4;
        else if (prubeh <= 8) pos = 6;
        else if (prubeh <= 10) pos = 8;
        else if (prubeh <= 12) pos = 10;
        else pos = 12;

        std::cout << std::string(pos, ' ') << "0";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(75));
        prubeh = (prubeh + 1) % 15;
        ++count;

        
    }
}
