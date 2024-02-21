#include "quest5.h"

void Quest5::run() { // override do metodo 'run' da superclasse

    /*
        Funcao para controlar o input da questao 5, para avaliacao.
    */

    string a, out, b = "ICE";
    vector<string> va;

    cin.ignore();
    cout << "Desafio 5: Implement repeating-key XOR" << endl;
    cout << "Insira a(s) frase(s) a ser(em) encriptada(s): ";
    while (getline(cin, a)) {
        if (a.empty()) {
            break;
        }
        va.push_back(a);
    }

    cout << "Insira a chave (deixe vazio para 'ICE'): ";
    if (cin.peek() == '\n') {
        cin.ignore();
    } else {
        getline(cin, b);
    }

    string k = "";
    for (int i = 0; i < va.size(); i++) {
        if (!(i == va.size() - 1)) {
            va[i] += '\n';
        }
        k += va[i];
    }


    out = repKeyXorEnc(k, b);

    cout << "Resultado: \n" << out << endl;


}

string Quest5::stringToHex(string str) { // converte string para hexadecimal

    /*  
        Funcao de conversao de string para hexadecimal.
        O valor dos caracteres em ascii sao convertidos para hex.
    */

    stringstream ss;
    for (char c : str) {
        ss << hex << setw(2) << setfill('0') << (int)c;
    }

    return ss.str();
}


string Quest5::repKeyXorEnc(string msg, string chave) {

    /*  
        Funcao que realiza a encriptacao da mensagem 'msg' com a chave 'chave'
    */

    string out = "";
    for (int i = 0; i < msg.length(); i++) {
        out += Quest2::fixedXor(stringToHex(string(1, msg[i])), stringToHex(string(1, chave[i%chave.length()])));
    }
    return out;
}


Quest5::~Quest5() {}