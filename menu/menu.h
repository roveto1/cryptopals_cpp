#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "../challenge.h"
#include "../quest1/quest1.h"
#include "../quest2/quest2.h"
#include "../quest3/quest3.h"
#include "../quest4/quest4.h"
using namespace std;
class Menu
{
    public:
        Challenge *challenge;

        Menu();
        ~Menu();
};

#endif // MENU_H