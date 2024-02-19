#ifndef QUEST2_H
#define QUEST2_H

#include "../challenge.h"
#include "../quest1/quest1.h"

class Quest2 : public Challenge // classe para questao 2
{
public:
    void run() override; // override do metodo 'run' da superclasse
    static string fixedXor(string a, string b); // faz o XOR entre dois hex
    ~Quest2();
private:
    static void resizeEqual(string& a, string& b); // redimensiona o menor para o maior
};

#endif // QUEST2_H