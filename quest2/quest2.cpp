#include "quest2.h"

void Quest2::run() { // override do metodo 'run' da superclasse

    /*
        Funcao para controlar o input da questao 2, para avaliacao.
    */

    string a, b;
    cout << endl;
    cout << "--------------------" << endl;
    cout << "Desafio 2: Fixed XOR" << endl;
    cout << "--------------------" << endl;
    cout << "Enter hex 1: ";
    cin >> a;
    cout << "Enter hex 2: ";
    cin >> b;
    cout << endl;

    cout << "Resultado: " << fixedXor(a, b) << endl;

}

string Quest2::fixedXor(string a, string b) { // faz o XOR entre dois hex

    /*
        Realiza o XOR entre as strings 'a' e 'b', convertendo-as
        para binario e aplicando o XOR.
    */

    string result = "";
    if (a.length() != b.length()) {
        resizeEqual(a, b); // redimensiona o menor para o maior
    }
    string bin1 = Quest1::hexToBin(a); // converte hex para bin, funcao da questao 1
    string bin2 = Quest1::hexToBin(b);
    for (int i = 0; i < bin1.length(); i++) {
        if (bin1[i] == bin2[i]) {
            result += '0';
        } else {
            result += '1';
        }
    }
    return Quest1::binToHex(result); // converte bin para hex, funcao da questao 1
}

void Quest2::resizeEqual(string& a, string& b) { // redimensiona o menor para o maior

    /*
        Redimensiona a ou b para o tamanho do maior.
    */

    if (a.length() > b.length()) {
        b = b.append(a.length() - b.length(), '0');
    } else if (a.length() < b.length()) {
        a = a.append(b.length() - a.length(), '0');
    }
}

Quest2::~Quest2() {} // destrutor