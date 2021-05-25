#include <iostream>
#include "Automata.h"

using namespace std;

int main()
{
    Automata automata = Automata();

    automata.on();
    automata.coin(10);
    automata.coin(20);
    automata.choise(2);
    int change = automata.finish();

    automata.coin(30);
    change = automata.cancel();
    automata.off();
    return 0;
} 
