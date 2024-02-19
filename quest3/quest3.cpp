#include "quest3.h"

map<char, double> Quest3::dicionario; // |
char Quest3::maisIncomum;             // |
int Quest3::key;                      //  > definindo as referencias
double Quest3::bestGuess;             // | 
string Quest3::bestGuessString;       // |


void Quest3::run() { // override do metodo 'run' da superclasse

    /*
        Funcao para controlar o input da questao 3, para avaliacao.
    */

    string a;
    int op1;
    string filename;

    cout << "Desafio 3: Single-byte XOR cipher" << endl;
    cout << "Qual texto deve servir de base para o 'scoring?'" << endl;
    cout << "[1] - Frankenstein" << endl;
    cout << "[2] - Moby Dick" << endl;
    cout << "[3] - Outro" << endl;
    cin >> op1;

    switch (op1)
        {
        case 1:
            filename = "quest3/frankenstein.txt";
            break;
        case 2:
            filename = "quest3/mobydick.txt";
            break;
        case 3:
            cout << "Insira o caminho do arquivo .txt: " << endl;
            cin >> filename;
            break;
        default:
            cout << "Opção invalida!" << endl;
            abort();
            break;
        }

    cout << "Analisando o arquivo: " << filename << endl;
    dicionario = encontrarPorcentagens(filename);
    for (const auto& pair : dicionario) {
        if (pair.first == '\n') {
            cout << "'" << "\\n" << "': " << pair.second << endl;
        } else {
            cout << "'" << pair.first << "': " << pair.second << endl;
        }
    }
    cout << "Analise concluída!" << endl;
    cout << "Insira o hex a ser decifrado: " << endl;
    cin >> a;
    cout << endl;
    guess(a);
    cout << "O melhor resultado foi: " << bestGuessString << endl;
    cout << "Com um score de: " << bestGuess << endl;
    cout << "E a chave era: " << key << endl;
    

}

double Quest3::grade(string hex_str) { // realiza o scoring

    /*
        Faz o scoring de 'hex_str'. Para isso, cria um dicionario
        para 'hex_str' e calcula o erro absoluto entre cada caractere.
        Caracteres presentes em 'hex_str' que não estiverem no dicionário
        sao substituidos pelo caractere mais incomum do dicionario.
    */

    map<char, double> dict_da_frase;
    double score = numeric_limits<double>::infinity();

    for (char i : hex_str) {
        if (!dicionario.count(i)) {
            i = maisIncomum;
        }

        double count = 0;

        for (char j : hex_str) {
            if (!dicionario.count(j)) {
                j = maisIncomum;
            }
            if (j == i) {
                count++;
            }
        }

        dict_da_frase[i] = count / hex_str.length();
        double erro = abs(dict_da_frase.at(i) - dicionario.at(i));
        if (score == numeric_limits<double>::infinity()) {
            score = 0.0;
        }
        score += erro;
    }

    return score;

}

string Quest3::guess(string hex_str) { // faz o chute da mensagem mais provavel baseado no scoring

    /*
        Gerencia todas as possiveis chaves, chamando 'grade' para cada uma
        e escolhendo a que obteve o menor erro.
    */

    if (dicionario.empty()) {
        dicionario = encontrarPorcentagens("quest3/frankenstein.txt");
    }

    encontrarMaisIncomum();
    bestGuess = numeric_limits<double>::infinity();
    key = 0;
    bestGuessString = "";
    for (int i = 0; i < 256; i++) {
        ostringstream oss;
        oss << hex << i;
        string guess = oss.str();
        
        if (guess.length() == 1) {
            guess = "0" + guess;
        }

        string temp = guess;
        while (guess.length() < hex_str.length()) {
            guess += temp;
        }

        string xor_str = Quest2::fixedXor(guess, hex_str);
        string out = Quest1::hexToString(xor_str);
        double score = grade(out);
        if (score < bestGuess) {
            key = i;
            bestGuess = score;
            bestGuessString = out;
        }
        
    }

    return bestGuessString;
}  

void Quest3::encontrarMaisIncomum() { // encontra o caractere mais incomum no dicionario

    /*
        Encontra o caractere mais incomum no dicionário.
    */

    maisIncomum = ' ';
    double max = numeric_limits<double>::infinity();
    for (const auto& pair : dicionario) {
        if (pair.second < max) {
            max = pair.second;
            maisIncomum = pair.first;
        }
    }
}

map<char, double> Quest3::encontrarPorcentagens(string filename) { // encontra as porcentagens dos caracteres em um arquivo

    /*
        Percorre todos os caracteres de um arquivo, armazenando a porcentagem
        de cada um no map 'dicionario'.
    */

    map<char, double> dicionario;
    ifstream file(filename);

    if (!file.is_open()) {
        throw invalid_argument("Arquivo inválido: " + filename);
        return dicionario;
    }

    char c;
    int charNum = 0;

    while (file.get(c)) {
        dicionario[c]++;
        charNum++;
    }

    for (pair<char, int> pair : dicionario) {
        dicionario[pair.first] = (static_cast<double>(pair.second) / charNum);
    }

    file.close();
    return dicionario;
}

Quest3::~Quest3() {}