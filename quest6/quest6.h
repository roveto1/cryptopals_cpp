#ifndef QUEST6_H
#define QUEST6_H

#include "../challenge.h"
#include "../quest1/quest1.h"
#include "../quest2/quest2.h"
#include "../quest3/quest3.h"
#include "../quest5/quest5.h"

class Quest6 : public Challenge // classe para questao 6
{
public:
    void run() override; // override do metodo 'run' da superclasse
    static int hammingDistance(string s1, string s2); // calcula a Hamming Distance
    static int chutarKeySize(string string_in); // busca pelo tamanho da chave
    static vector<string> transporBlocos(vector<string> blocos); // transposta os blocos
    static pair<string , string> BreakRepeatingKeyXOR(string filepath); // executa o Break repeating-key XOR
    ~Quest6();
};

#endif // QUEST6_H