#ifndef QUEST8_H
#define QUEST8_H

#include "../challenge.h"
#include "../quest1/quest1.h"

class Quest8 : public Challenge // classe para questao 9
{
public:
    void run() override; // override do metodo 'run' da superclasse
    string readFile(string filepath); // ler o conteudo de um arquivo .txt
    vector<string> divideBlocos(string input, int size); // dividir o conteudo em blocos
    void calcularRepeticoes(vector<string> blocos); // calcular as repeticoes de cada bloco
    pair<string, int> maiorRepeticao(); // encontra a maior repeticao (chave)
    int encontraLinha(string chave, int chaveSize); // encontra a linha onde houveram mais repeticoes da chave

    ~Quest8();

private:
    map<string, int> repeticoesDict; // armazena as repeticoes de cada bloco
    vector<string> fileLines; // armazena as linhas do arquivo
};

#endif // QUEST8_H