#ifndef QUEST1_H
#define QUEST1_H

#include "../challenge.h"

class Quest1 : public Challenge { // classe para questao 1
public:
    void run() override; // override do metodo 'run' da superclasse
    static string hexToString(string a); // converte hexadecimal para string (usado em outras questoes)
    static string binToHex(string a); // converte binario para hexadecimal (usado em outras questoes)
    static string hexToBin(string a); // converte hexadecimal para binario
    static string binTo64(string a); // converte binario para base64
    static string hexTo64(string a); // aplica hexToBin() e binTo64()
    ~Quest1();
private:
    static string round4(string b64); // funcao auxiliar para a saida ficar em um tamanho divisivel por 4 (padding)
};

#endif // QUEST1_H