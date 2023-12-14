#include <iostream>

#include <iostream>
#include <vector>

#include "Rules.h"
#include "Wereld.h"
int main() {
    StandaardRegels regels;

    //andere regels (uncomment om ze te proberen)
    // HighLifeRegels regels;
    // DayNightRegels regels;
    Wereld wereld(25, &regels);

    for (int i = 0; i < 10; ++i) { // Voor 10 generaties
        wereld.printWereld();
        wereld.updateWereld();
        std::cout << "-------------------\n";
    }

    bool isRunning = true;
    while(isRunning){
        
    }

    return 0;
}
