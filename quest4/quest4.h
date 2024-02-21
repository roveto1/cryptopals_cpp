#ifndef QUEST4_H
#define QUEST4_H

#include "../challenge.h"
#include "../quest1/quest1.h"
#include "../quest2/quest2.h"
#include "../quest3/quest3.h"


class Quest4 : public Challenge // classe da questao 4
{
public:
    void run() override; // override do metodo 'run' da superclasse
    static string guessMultiple(string filename, bool print); // faz o chute da mensagem mais provavel baseado no scoring
    ~Quest4();
private:
    static int key; // chave do XOR do melhor chute
    static int line; // linha do melhor chute
    static double bestGuess; // valor do melhor chute
    static string bestGuessString; // mensagem do melhor chute
    static void printTabela(double chuteVal); // imprime a tabela com os resultados

};


#endif // QUEST4_H