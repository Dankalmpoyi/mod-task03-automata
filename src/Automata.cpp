#include "Automata.h"
#include <iostream>

Automata::Automata()
{
    cash = 0;
    menu = new std::string[5];
    prices = new int[5];
    for (int index = 0; index < 5; index++)
    {
        menu[index] = "Напиток " + std::to_string(index + 1);
        prices[index] = 10 * (index + 1);
    }
    currentstate = OFF;
}
void Automata::on()
{
    if (getState() == OFF)
    {
        currentstate = WAIT;
        std::string checkmenu = etMenu();
    }
}
void Automata::off()
{
    if (getState() == WAIT)
    {
        currentstate = OFF;
    }
}
void Automata::coin(int setcash)
{
    if (getState() == ACCEPT || getState() == WAIT)
    {
        if (getState() == WAIT)
            currentstate = ACCEPT;
        cash += setcash;
    }
}
std::string Automata::etMenu()
{
    std::string fullmenu;
    for (int index = 0; index < 5; index++)
    {
        fullmenu += std::to_string(index + 1) + ". " + menu[index] + " - " + std::to_string(prices[index]) + "\n";
    }

    return fullmenu;
}
States Automata::getState()
{
    return currentstate;
}
void Automata::choise(int _choise)
{
    if(getState() == ACCEPT)
    {
        currentstate = CHECK;
        if(_choise <= 5 && _choise >= 1 && check(_choise - 1))
        {
            cash -= prices[_choise - 1];
            cook();
        }
        else 
            cancel();
    }
}
bool Automata::check(int _choise)
{
    if (getState() == CHECK)
    {
        if (cash - prices[_choise] >= 0)
            return true;
        else
            return false;
    }
}
int Automata::cancel()
{
    if (getState() == ACCEPT || getState() == CHECK)
    {
        currentstate = WAIT;
        int temp = cash;
        cash = 0;
        return temp;
    }
    else
        return 0;
}
void Automata::cook()
{
    if (getState() == CHECK)
    {
        currentstate = COOK;
        if(cash == 0)
           finish();
    }
}
int Automata::finish()
{
    if (getState() == COOK)
    {
        currentstate = WAIT;
        int temp = cash;
        cash = 0;
        return temp;
    }
}
Automata::~Automata()
{
    delete[] menu;
    delete[] prices;
}
