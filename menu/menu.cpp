#include "menu.h"

Menu::Menu() {   
    bool repeat = true;
    while (true) {
        int questao;
        cout << "Escolha a questao (1 ate 8): ";
        cin >> questao;
        cout << endl;

        switch(questao)
        {
            case 1:
                challenge = new Quest1();
                break;
            case 2:
                challenge = new Quest2();
                break;
            case 3:
                challenge = new Quest3();
                break;
            case 4:
                challenge = new Quest4();
                break;
            default:
                cout << "Questão invalida, saindo..." << endl;
                repeat = false;
                break;
        }
        if (!repeat) {
            break;
        }
        challenge->run();
        cout << endl;
    }
}

Menu::~Menu() {
    if (challenge) {
        delete challenge;
    }
}