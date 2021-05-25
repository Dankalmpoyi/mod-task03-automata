#include <string>

enum States
{
   OFF,
   WAIT,
   ACCEPT,
   CHECK,
   COOK
};

class Automata
{
 private:    
    int cash;
    std::string* menu;
    int* prices;
    States currentstate;
    bool check(int _choise);
    void cook();

 public:
    Automata();
    void on();
    void off();
    void coin(int setcash);
    std::string etMenu();
    States getState();
    void choise(int _choise);
    int cancel();
    int finish();
    ~Automata();
}; 
