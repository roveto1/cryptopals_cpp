#ifndef QUEST1_H
#define QUEST1_H

#include "../challenge.h"

class Quest1 : public Challenge { // classe para questao 1
public:
    void run() override; // override do metodo 'run' da superclasse
    static string base64ToHex(string base64); // converte base64 para hexadecimal (usado em outras questoes)
    static string base64ToBinary(string base64); // converte base64 para binario (usado em outras questoes)
    static string hexToAscii(string hex); // converte hexadecimal para ascii (usado em outras questoes)
    static string hexToString(string hex); // converte hexadecimal para string (usado em outras questoes)
    static string binToHex(string bin); // converte binario para hexadecimal (usado em outras questoes)
    static string hexToBin(string hex); // converte hexadecimal para binario
    static string binToBase64(string bin); // converte binario para base64
    static string hexToBase64(string hex); // aplica hexToBin() e binTo64()
    ~Quest1();
private:
    static string round4(string b64); // funcao auxiliar para a saida ficar em um tamanho divisivel por 4 (padding)
};

#endif // QUEST1_H