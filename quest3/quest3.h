#ifndef QUEST3_H
#define QUEST3_H

#include "../challenge.h"
#include "../quest1/quest1.h"
#include "../quest2/quest2.h"

class Quest3 : public Challenge { // classe para questao 3
public:
    static map<char, double> dicionario; // dicionario do scoring

    void run() override; // override do metodo 'run' da superclasse
    string guess(string hex_str); // faz o chute da mensagem mais provavel baseado no scoring
    double grade(string hex_str); // realiza o scoring
    int getKey();
    string getBestGuessString();
    double getBestGuess();

    ~Quest3();
private:
    int key; // chave do XOR do melhor chute
    double bestGuess; // valor do melhor chute
    string bestGuessString; // mensagem do melhor chute
    static char maisIncomum; // caractere mais incomum no dicionario
    static void encontrarMaisIncomum(); // encontra o caractere mais incomum no dicionario
    static map<char, double> encontrarPorcentagens(string filename); // encontra as porcentagens dos caracteres em um arquivo
};

#endif // QUEST3_H
