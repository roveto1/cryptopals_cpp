#include "quest1.h"

void Quest1::run()
{ // override do metodo 'run' da superclasse

    /*
        Funcao para controlar o input da questao 1, para avaliacao.
    */

    string a;
    cout << endl;
    cout << "------------------------" << endl;
    cout << "Desafio 1: Hex to Base64" << endl;
    cout << "------------------------" << endl;
    cout << "Enter hex: ";
    cin >> a;
    cout << endl;
    string b = hexToBin(a);
    string c = binToBase64(b);
    cout << "Resultado: " << c << endl;
}

string Quest1::base64ToHex(string base64)
{ // converte base64 para hexadecimal

    /*
        Funcao direta de conversao de base64 para hexadecimal
        para uso em outras questoes.
    */

    isBase64(base64);

    string resultado = "";

    string bin = base64ToBinary(base64);
    for (int i = 0; i < bin.length(); i += 4) {
        string sub = bin.substr(i, 4);
        resultado += Quest1::binToHex(sub);
    }
    if (resultado.length() % 2 == 1) {
        resultado.erase(resultado.length() - 1);
    }
    return resultado;
}

string Quest1::base64ToBinary(string base64) { // converte base64 para binario

    /*
        Funcao direta de conversao de base64 para binario
        para uso em outras questoes.
    */

    isBase64(base64);

    std::string resultado;
    for (int i = 0; i < base64.length(); i++) {
        if (base64[i] >= 'A' && base64[i] <= 'Z')
            resultado += std::bitset<6>(base64[i] - 'A').to_string();
        else if (base64[i] >= 'a' && base64[i] <= 'z')
            resultado += std::bitset<6>(base64[i] - 'a' + 26).to_string();
        else if (base64[i] >= '0' && base64[i] <= '9')
            resultado += std::bitset<6>(base64[i] - '0' + 52).to_string();
        else if (base64[i] == '+')
            resultado += std::bitset<6>(62).to_string();
        else if (base64[i] == '/')
            resultado += std::bitset<6>(63).to_string();
    }
    return resultado;
}

string Quest1::hexToAscii(string hex_str) { // converte hexadecimal para ascii

    /*
        Funcao direta de conversao de hexadecimal para ascii
        para uso em outras questoes.
    */

    isHex(hex_str);

    stringstream resultado;
    for (int i = 0; i < hex_str.length(); i += 2)
    {
        string byteString = hex_str.substr(i, 2);
        char byte = (char)strtol(byteString.c_str(), NULL, 16);
        resultado << byte;
    }
    return resultado.str();
}

string Quest1::hexToString(string hex) { // converte hexadecimal para string

    /*
        Funcao direta de conversao de hexadecimal para string
        para uso em outras questoes.
    */

    isHex(hex);

    string str = "";
    for (int i = 0; i < hex.length(); i += 2) {
        str += char(stoi(hex.substr(i, 2), nullptr, 16));
    }
    return str;
}

string Quest1::binToHex(string bin) { // converte binario para hexadecimal

    /*
        Converte binario para hexadecimal a partir de operacoes
        na tabela ascii.
    */

    isBin(bin);

    string hex = "";
    for (int i = 0; i < bin.length(); i += 4) {
        string chunk = bin.substr(i, 4);
        int num = stoi(chunk, nullptr, 2);
        if (num < 10) {
            hex += char('0' + num);
        }
        else {
            hex += char('a' + num - 10);
        }
    }
    return hex;
}

string Quest1::stringToHex(string str) { // converte string para hexadecimal

    /*
        Converte string para hexadecimal.
    */

    char hex_string[str.length() * 2];
    string hex_out;
    for (int i = 0; i < str.length(); i++) {
        int num = (int)str[i];
        sprintf(hex_string, "%x", num);
        hex_out += hex_string;
    }
    return hex_out;
}

string Quest1::hexToBin(string hex) { // converte hexadecimal para binario

    /*
        Converte hexadecimal para binario a partir de operacoes
        na tabela ascii
    */

    isHex(hex);

    string bin = "";
    for (int i = 0; i < hex.length(); i++) { // > Converte a string de ascii para hexadecimal                   
        char c = hex[i];
        int bin_val;     
        if (c >= 65 && c <= 70) {                     
            bin_val = c - 55; 
        }
        else if (c >= 97 && c <= 102) {                    
            bin_val = c - 87; 
        }
        else if (c >= 48 && c <= 57) {                    
            bin_val = c - 48; 
        }                     

        bin += bitset<4>(bin_val).to_string(); // Cria a string 'bin' contendo o valor binario do hexadecimal
    }
    return bin;
}

string Quest1::binToBase64(string bin)
{ // converte binario para base64

    /*
        Converte binario para base64 a partir de operacoes
        na tabela ascii.
    */

    isBin(bin);

    string base64 = "";
    for (int i = 0; i < bin.length(); i += 6) {
        string chunk = bin.substr(i, 6);
        while (chunk.length() < 6) {
            chunk = chunk + "0";
        }
        int num = stoi(chunk, nullptr, 2);
        if (num < 26) {
            base64 += char('A' + num);
        }
        else if (num < 52) {
            base64 += char('a' + num - 26);
        }
        else if (num < 62) {
            base64 += char('0' + num - 52);
        }
        else if (num == 62) {
            base64 += '+';
        }
        else if (num == 63) {
            base64 += '/';
        }
    }
    return round4(base64);
}

string Quest1::hexToBase64(string hex)
{ // aplica hexToBin() e binTo64()

    /*
        Funcao direta de conversao de hexadecimal para base64
        para uso em outras questoes.
    */

    isHex(hex);

    return binToBase64(hexToBin(hex));
}

string Quest1::round4(string b64) { // padding

    /*
        Realiza o padding de 'b64' para que o tamanho
        seja divisivel por 4.
    */

    while (b64.length() % 4 != 0) {
        b64 += "=";
    }
    return b64;
}

void Quest1::isHex(string str) { // verifica se uma string eh hexadecimal

    /*
        Checar se uma string eh hexadecimal.
    */

    for (int i = 0; i < str.length(); i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F') || (str[i] == '\n'))) {
            throw invalid_argument("Argumento invalido: nao hexadecimal");
        }
    }
}

void Quest1::isBase64(string str) { // verifica se uma string eh base64

    /*
        Checar se uma string eh base64.
    */

    for (int i = 0; i < str.length(); i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || (str[i] == '+') || (str[i] == '/') || (str[i] == '=') || (str[i] == '\n'))) {
            throw invalid_argument("Argumento invalido: nao base64");
        }
    }
}

void Quest1::isBin(string str) { // verifica se uma string eh binario

    /*
        Checar se uma string eh binario.
    */
    for (char c : str) {
        if (c != '0' && c != '1') {
            throw invalid_argument("Argumento invalido: nao binario");
        }
    }
}

Quest1::~Quest1() {} // destrutor
