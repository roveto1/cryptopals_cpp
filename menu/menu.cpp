#include "menu.h"

Menu::Menu()
{   
    int questao;
    cout << "Escolha a questao (1 ate 8): ";
    cin >> questao;

    switch(questao)
    {
        case 1:
            challenge = new Quest1();
            challenge->run();
            break;
        case 2:
            challenge = new Quest2();
            challenge->run();
            break;
        case 3:
            challenge = new Quest3();
            challenge->run();
            break;
        case 4:
            challenge = new Quest4();
            challenge->run();
            break;
        default: cout << "Questão invalida!" << endl;
    }
}

Menu::~Menu()
{
    if (challenge) {
        delete challenge;
    }
}