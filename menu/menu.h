#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "../challenge.h"
#include "../quest1/quest1.h"
#include "../quest2/quest2.h"
#include "../quest3/quest3.h"
#include "../quest4/quest4.h"
#include "../quest5/quest5.h"
#include "../quest6/quest6.h"
#include "../quest7/quest7.h"
#include "../quest8/quest8.h"

using namespace std;
class Menu
{
    public:
        Challenge *challenge;

        Menu();
        ~Menu();
};

#endif // MENU_H