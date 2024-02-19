#ifndef QUEST3_H
#define QUEST3_H

#include "../challenge.h"
#include "../quest1/quest1.h"
#include "../quest2/quest2.h"

class Quest3 : public Challenge { // classe para questao 3
public:
    static map<char, double> dicionario; // dicionario do scoring

    void run() override; // override do metodo 'run' da superclasse
    static string guess(string hex_str); // faz o chute da mensagem mais provavel baseado no scoring
    static double grade(string hex_str); // realiza o scoring
    ~Quest3();
private:
    static int key; // chave do XOR do melhor chute
    static double bestGuess; // valor do melhor chute
    static string bestGuessString; // mensagem do melhor chute
    static char maisIncomum; // caractere mais incomum no dicionario
    static void encontrarMaisIncomum(); // encontra o caractere mais incomum no dicionario
    static map<char, double> encontrarPorcentagens(string filename); // encontra as porcentagens dos caracteres em um arquivo
};

#endif // QUEST3_H
