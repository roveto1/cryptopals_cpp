#include "quest7.h"

void Quest7::run() { // override do metodo 'run' da superclasse

    /*
        Função para controlar o input da questao 7, para avaliacao.
    */

    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Desafio 7: AES in ECB mode" << endl;
    cout << "--------------------------" << endl;
    cout << "Insira o cominho do arquivo .txt que deseja decifrar (deixe vazio para '7.txt'): " << endl;

    string filepath;
    cin.ignore();
    if (cin.peek() == '\n') {
        filepath = "quest7/7.txt";
    } else {
        cin >> filepath;
    }

    ifstream file;
    file.open(filepath);

    if (!file.is_open()) {
        throw invalid_argument("Arquivo inválido: " + filepath);
        return;
    }
    file.close();

    string chave = "YELLOW SUBMARINE";
    string outPath = "quest7/out.txt";
    string output = decryptAES_128_ECB(filepath, chave, outPath);

    cout << endl;
    cout << "Arquivo decifrado aramazenado em " + outPath << endl;
    cout << "Texto decifrado:" << endl << endl;
    cout << output;

}

string Quest7::decryptAES_128_ECB(string filepath, string key, string outPath) { // descriptografa usando AES-128-ECB

    /*
        Função que descriptografa AES-128-ECB usando OpenSSL
    */

    string command = "openssl enc -d -aes-128-ecb -a -in " + filepath + " -K " + Quest1::stringToHex(key) + " -out " + outPath;
    system(command.c_str());

    ifstream file;
    file.open("quest7/out.txt");
    string output, temp;
    while (file.eof() == false) {
        getline(file, temp);
        output += temp + "\n";
    }
    file.close();
    return output;

}

Quest7::~Quest7() { // Apaga o conteudo no arquivo de saida, para proximas execucoes
    ofstream file;
    file.open("quest7/out.txt");
    file.close();
}