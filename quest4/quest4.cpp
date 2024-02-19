#include "quest4.h"


int Quest4::key;                      // |
int Quest4::line;                     //  > definindo as referencias
double Quest4::bestGuess;             // | 
string Quest4::bestGuessString;       // |


void Quest4::run() { // override do metodo 'run' da superclasse

    /*
        Funcao para controlar o input da questao 1, para avaliacao.
    */


    int op1;
    string filename;
    cout << "Desafio 4: Detect single-character XOR" << endl;
    cout << "Qual arquivo avaliar?" << endl;
    cout << "[1] - 4.txt (arquivo fornecido pelo cryptopals)" << endl;
    cout << "[2] - Outro" << endl;
    cin >> op1;

    switch (op1)
    {
    case 1:
        filename = "quest4/4.txt";
        break;
    case 2:
        cout << "Insira o caminho do arquivo .txt: " << endl;
        cin >> filename;
        break;
    default:
        cout << "Opção invalida!" << endl;
        abort();
        break;
    }
    cout << "Filtrando melhor chute..." << endl;
    cout << "LINHA | CHAVE |   VALOR   | VALOR ANTERIOR" << endl;
    guessMultiple(filename, true);

    cout << endl;
    cout << "O melhor resultado foi: " << bestGuessString << endl;
    cout << "Na linha: " << line << endl;
    cout << "A chave era: " << key << endl;
    cout << "Com um score de: " << bestGuess << endl;

    
}

string Quest4::guessMultiple(string filename, bool print) { // faz o chute da mensagem mais provavel baseado no scoring

    /*
        Busca pela mensagem criptografada mais provavel. Para isso,
        abre o arquivo de texto e realiza o scoring para cada linha,
        utilizando os metodos desenvolvidos para o desafio 3.
    */
    
    ifstream file(filename);

    if (!file.is_open()) {
        throw invalid_argument("Arquivo inválido: " + filename);
        return "";
    }


    bestGuess = numeric_limits<double>::infinity();
    int linhaNum = 0;

    for (string linha; getline(file, linha);) {
        linhaNum++;
        Quest3 chute = Quest3();
        chute.guess(linha);
        double chuteVal = chute.getBestGuess();
        if (chuteVal < bestGuess) {
            bestGuessString = chute.getBestGuessString();
            key = chute.getKey();
            line = linhaNum;
            if (print) {printTabela(chuteVal);}
            bestGuess = chuteVal;
        }
    }
    return bestGuessString;
}

void Quest4::printTabela(double chuteVal) { // imprime a tabela com os resultados

    /*
        Realiza a impressao no terminal do progresso da busca.
        É chamada toda vez que o chute encontra uma nova provavel mensagem.
    */

    cout << setw(5) << right << line << " | "
         << setw(5) << right << key << " | "
         << setw(9) << fixed << setprecision(5) << chuteVal << " | "
         << setw(9) << fixed << setprecision(5) << bestGuess << endl;
}



Quest4::~Quest4() {}