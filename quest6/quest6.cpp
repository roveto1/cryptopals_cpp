#include "quest6.h"
#define MAX_KEYSIZE 40

void Quest6::run()
{ // override do metodo 'run' da superclasse

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
    int key = Quest6::guessKeySize(base64_to_binary(s1));
    cout << "Tamanho encontrado: " << key << endl;

    vector<string> v1;
    std::vector<std::string> blocks;
    string ciphertext = base64_to_binary(s1);
    cout << "Dividindo entrada em blocos..." << endl;
    for (size_t i = 0; i < ciphertext.size(); i += key * 8) {
        blocks.push_back(ciphertext.substr(i, key * 8));
    }
    cout << "Divisao completa," << blocks.size() << " blocos gerados" << endl;

    cout << "Transpondo blocos..." << endl;
    vector<string> v2 = Quest6::transposeBlocks(blocks);
    cout << "Transposicao completa, " << v2.size() << " blocos transpostos" << endl;

    cout << "Decodificando blocos, buscando pela chave..." << endl;
    string out = "";
    Quest3 q3;
    for (string s : v2) {
        string s2 = Quest1::binToHex(s);
        q3.guess(s2);
        int temp_key = q3.getKey();
        out += temp_key;
        cout << (char)temp_key << flush;
    }
    cout << endl << endl;
    cout << "Chave encontrada: " << out << endl;
    cout << "Decodificando..." << endl;
    ciphertext = base64_to_hex(s1);
    cout << "Texto decodificado: " << endl;
    cout << Quest1::hexToString(Quest5::repKeyXorEnc(hex_to_ascii(ciphertext), out)) << endl;
}

int Quest6::hammingDistance(const string &s1, const string &s2)
{
    int distance = 0;
    for (size_t i = 0; i < s1.length(); ++i)
    {
        if (s1[i] != s2[i])
        {
            distance++;
        }
    }
    return distance;
}

int Quest6::guessKeySize(const string &ciphertext)
{
    double smallest_distance = std::numeric_limits<double>::max();
    int smallest_key_size = -1;

    for (int key_size = 2; key_size <= 40; key_size++)
    {
        std::string part1 = ciphertext.substr(0, key_size * 8);
        std::string part2 = ciphertext.substr(key_size * 8, key_size * 8);
        string part3 = ciphertext.substr(key_size * 8 * 2, key_size * 8);
        string part4 = ciphertext.substr(key_size * 8 * 3, key_size * 8);

        double normalized_distance = (double)hammingDistance(part1, part2) / key_size;
        double normalized_distance2 = (double)hammingDistance(part3, part4) / key_size;
        double normalized_distance3 = (double)hammingDistance(part1, part3) / key_size;
        double normalized_distance4 = (double)hammingDistance(part2, part4) / key_size;
        double normalized_distance5 = (double)hammingDistance(part1, part4) / key_size;
        double normalized_distance6 = (double)hammingDistance(part2, part3) / key_size;
        normalized_distance = (normalized_distance + normalized_distance2 + normalized_distance3 + normalized_distance4 + normalized_distance5 + normalized_distance6) / 6;
        if (normalized_distance < smallest_distance)
        {
            smallest_distance = normalized_distance;
            smallest_key_size = key_size;
        }
    }

    return smallest_key_size;
}

vector<string> Quest6::transposeBlocks(vector<string> &blocks)
{
    std::vector<std::string> transposed_strings;

    // Find the maximum length among all input strings
    size_t max_length = 0;
    for (const std::string &binary_str : blocks) {
        max_length = std::max(max_length, binary_str.length());
    }
    // Transpose the binary strings by every 8 characters
    for (size_t i = 0; i < max_length; i += 8) {
        std::string transposed_str;
        for (const std::string &binary_str : blocks) {
            if (i < binary_str.length()) {
                transposed_str += binary_str.substr(i, 8);
            }
        }
        transposed_strings.push_back(transposed_str);
    }

    return transposed_strings;
}


Quest6::~Quest6() {}