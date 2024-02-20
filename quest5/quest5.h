#ifndef QUEST5_H
#define QUEST5_H

#include "../challenge.h"
#include "../quest1/quest1.h"
#include "../quest2/quest2.h"

class Quest5 : public Challenge // classe para questao 2
{
public:
    void run() override; // override do metodo 'run' da superclasse
    static string stringToHex(string s); // converte string para hexadecimal
    static string repKeyXorEnc(string a, string b);
    ~Quest5();
};

#endif // QUEST5_H