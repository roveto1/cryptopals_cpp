#include "quest8.h"


void Quest8::run() { // override do metodo 'run' da superclasse

    /*
        Função para controlar o input da questao 8, para avaliacao.
    */

    cout << endl;
    cout << "--------------------------------------" << endl;
    cout << "Desafio 8: Detect single-character XOR" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Insira o caminho arquivo .txt que deseja decifrar (deixe vazio para '8.txt'): " << endl;

    string filepath;
    cin.ignore();
    if (cin.peek() == '\n') {
            filepath = "quest8/8.txt";
        } else {
            cin >> filepath;
        }

    string arquivoBruto = readFile(filepath);

    cout << endl;
    cout << "Dividindo blocos.." << endl;
    vector<string> blocos = divideBlocos(arquivoBruto, 32);
    cout << blocos.size() << " blocos de 16 bytes gerados." << endl;

    cout << endl;
    cout << "Calculando repeticoes de blocos..." << endl;
    calcularRepeticoes(blocos);
    pair<string, int> maisRepetido = maiorRepeticao();
    cout << "Maior repeticao encontrada: " + maisRepetido.first << " (" + to_string(maisRepetido.second) + " repeticoes)" << endl;

    cout << endl;
    cout << "Encontrando linha..." << endl;
    int linha = encontraLinha(maisRepetido.first, maisRepetido.first.length());
    cout << endl;
    cout << "Linha: " << linha << endl;
    cout << fileLines[linha-1] << endl;

}

string Quest8::readFile(string filepath) { // ler o conteudo de um arquivo .txt

    /*
        Função para ler o conteudo de um arquivo .txt.
    */

    ifstream file;
    file.open(filepath);
    string output, temp;
    while (file.eof() == false) {
        getline(file, temp);
        fileLines.push_back(temp);
        output += temp;
    }
    file.close();
    return output;

}

vector<string> Quest8::divideBlocos(string input, int size) { // dividir o conteudo em blocos

    /*
        Função para dividir o conteudo em blocos de tamanho 'size'.
    */

    vector<string> blocos;
    for (int i = 0; i < input.length(); i += size) {
        blocos.push_back(input.substr(i, size));
    }

    return blocos;
}

void Quest8::calcularRepeticoes(vector<string> blocos) { // calcular as repeticoes de cada bloco

    /*
        Função para calcular as repeticoes de cada bloco no arquivo.
    */

    for (string s : blocos) {
        if (repeticoesDict.find(s) == repeticoesDict.end()) {
            repeticoesDict[s] = 1;
        } else {
            repeticoesDict[s]++;
        }
    }
}

pair<string, int> Quest8::maiorRepeticao() { // encontra a maior repeticao (chave)

    /*
        Função para encontrar a maior repeticao, o que nos diz a chave.
    */

    int max = 0;
    string chave = "";
    for (auto x : repeticoesDict) {
        if (x.second > max) {
            max = x.second;
            chave = x.first;
        }
    }
    return make_pair(chave, max);
}

int Quest8::encontraLinha(string chave, int chaveSize) { // encontra a linha onde houveram mais repeticoes da chave

    /*
        Função para encontrar a linha do arquivo onde houveram mais repeticoes da chave.
    */

    int linha = -1;
    int maior = 0;
    for (int i = 0; i < fileLines.size(); i++) {
        int nessaLinha = 0;
        for (int j = 0; j < fileLines[i].size(); j+=chaveSize) { 
            if (fileLines[i].substr(j, chaveSize) == chave) {
                nessaLinha++;
            }
        }
        if (nessaLinha > maior) {
            maior = nessaLinha;
            linha = i+1;
        }
    }
    return linha;
}

Quest8::~Quest8() {}