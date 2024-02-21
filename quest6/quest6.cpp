#include "quest6.h"
#define MAX_KEYSIZE 40

void Quest6::run() { // override do metodo 'run' da superclasse

    /*
        Funcao para controlar o input da questao 1, para avaliacao.
    */

    cout << "Desafio 6: Break repeating-key XOR" << endl;
    cout << "Qual arquivo avaliar?" << endl;
    cout << "[1] - 6.txt (arquivo fornecido pelo cryptopals)" << endl;
    cout << "[2] - Outro" << endl;
    int op1;
    cin >> op1;
    string filename;
    switch (op1)
    {
    case 1:
        filename = "quest6/6.txt";
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
    ifstream file;
    file.open(filename);
    stringstream ss;
    ss << file.rdbuf();
    string s1 = ss.str();

    cout << "Buscando tamanho da chave..." << endl;
    int keySize = Quest6::chutarKeySize(Quest1::base64ToBinary(s1));
    cout << "Tamanho encontrado: " << keySize << endl;

    vector<string> blocos;
    string msgBin = Quest1::base64ToBinary(s1);
    cout << "Dividindo entrada em blocos..." << endl;
    for (size_t i = 0; i < msgBin.size(); i += keySize * 8) {
        blocos.push_back(msgBin.substr(i, keySize * 8));
    }
    cout << "Divisao completa," << blocos.size() << " blocos gerados" << endl;

    cout << "Transpondo blocos..." << endl;
    vector<string> v = Quest6::transporBlocos(blocos);
    cout << "Transposicao completa, " << v.size() << " blocos transpostos" << endl;

    cout << "Decodificando blocos, buscando pela chave..." << endl;
    string chave = "";
    Quest3 q3;
    for (string s : v) {
        string temp_str = Quest1::binToHex(s);
        q3.guess(temp_str);
        int temp_key = q3.getKey();
        chave += temp_key;
        cout << (char)temp_key << flush;
    }
    cout << endl << endl;
    cout << "Chave encontrada: " << chave << endl;
    cout << "Decodificando..." << endl;
    string msgHex = Quest1::base64ToHex(s1);
    cout << "Texto decodificado: " << endl;
    cout << Quest1::hexToString(Quest5::repKeyXorEnc(Quest1::hexToAscii(msgHex), chave)) << endl;
}

int Quest6::hammingDistance(string s1, string s2) { // calcula a Hamming Distance

    /*
        Calcula a Hamming Distance entre duas strings.
        A entrada deve ser dada como uma string contendo
        a informacao codificada em binario.
    */

    int diatancia = 0;
    for (size_t i = 0; i < s1.length(); ++i)
    {
        if (s1[i] != s2[i])
        {
            diatancia++;
        }
    }
    return diatancia;
}

int Quest6::chutarKeySize(string string_in) { // busca pelo tamanho da chave

    /*
        Funcao para controlar o input da questao 1, para avaliacao.
    */

    double menorDistancia = numeric_limits<double>::max();
    int menorKeySize = -1;

    for (int i = 2; i <= 40; i++)
    {
        string part1 = string_in.substr(0, i * 8);
        string part2 = string_in.substr(i * 8, i * 8);
        string part3 = string_in.substr(i * 8 * 2, i * 8);
        string part4 = string_in.substr(i * 8 * 3, i * 8);

        double distaciaNormalizada = (double)hammingDistance(part1, part2) / i;
        distaciaNormalizada += (double)hammingDistance(part3, part4) / i;
        distaciaNormalizada += (double)hammingDistance(part1, part3) / i;
        distaciaNormalizada += (double)hammingDistance(part2, part4) / i;
        distaciaNormalizada += (double)hammingDistance(part1, part4) / i;
        distaciaNormalizada += (double)hammingDistance(part2, part3) / i;
        distaciaNormalizada = distaciaNormalizada / 6;
        if (distaciaNormalizada < menorDistancia)
        {
            menorDistancia = distaciaNormalizada;
            menorKeySize = i;
        }
    }

    return menorKeySize;
}

vector<string> Quest6::transporBlocos(vector<string> blocos){ // transposta os blocos

    /*
        Dado um vector de blocos em binario, retorna um vector
        de blocos transpostos.
    */

    vector<string> stringsTransportas;

    size_t maxLength = 0;
    for (string s : blocos) {
        maxLength = max(maxLength, s.length());
    }

    for (size_t i = 0; i < maxLength; i += 8) {
        string strTransposta;
        for (string s : blocos) {
            if (i < s.length()) {
                strTransposta += s.substr(i, 8);
            }
        }
        stringsTransportas.push_back(strTransposta);
    }

    return stringsTransportas;
}

pair<string , string> Quest6::BreakRepeatingKeyXOR(string filepath) { // executa o Break repeating-key XOR

    /*
        Funcao que executa o BreakRepeatingKeyXOR em sua totalidade,
        Caso necessario no futuro.
    */
    
    ifstream file;
    file.open(filepath);

    if (!file.is_open()) {
        throw invalid_argument("Arquivo inválido: " + filepath);
        return make_pair("", "");
    }

    stringstream ss;
    ss << file.rdbuf();
    string s1 = ss.str();

    int key = Quest6::chutarKeySize(Quest1::base64ToBinary(s1));

    vector<string> blocks;
    string msgBin = Quest1::base64ToBinary(s1);

    for (size_t i = 0; i < msgBin.size(); i += key * 8) {
        blocks.push_back(msgBin.substr(i, key * 8));
    }

    vector<string> v = Quest6::transporBlocos(blocks);

    string chave = "";
    Quest3 q3;
    for (string s : v) {
        string temp_str = Quest1::binToHex(s);
        q3.guess(temp_str);
        int temp_key = q3.getKey();
        chave += temp_key;
    }
    string msgHex = Quest1::base64ToHex(s1);
    string msgDescoberta = Quest1::hexToString(Quest5::repKeyXorEnc(Quest1::hexToAscii(msgHex), chave));

    return make_pair(chave, msgDescoberta);
}


Quest6::~Quest6() {}