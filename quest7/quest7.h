#ifndef QUEST7_H
#define QUEST7_H

#include "../challenge.h"
#include "../quest1/quest1.h"

class Quest7 : public Challenge // classe para questao 7
{
public:
    void run() override; // override do metodo 'run' da superclasse
    string decryptAES_128_ECB(string filepath, string key, string outPath); // descriptografa usando AES-128-ECB
    ~Quest7(); // Apaga o conteudo no arquivo de saida, para proximas execucoes
};

#endif // QUEST7_H