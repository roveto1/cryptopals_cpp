#ifndef QUEST6_H
#define QUEST6_H

#include "../challenge.h"
#include "../quest1/quest1.h"
#include "../quest2/quest2.h"
#include "../quest3/quest3.h"
#include "../quest5/quest5.h"

class Quest6 : public Challenge // classe para questao 2
{
public:
    void run() override; // override do metodo 'run' da superclasse
    static int hammingDistance(const string &s1, const string &s2);
    static int guessKeySize(const string &ciphertext);
    static vector<string> transposeBlocks(vector<string> &v);
    static std::string base64_to_hex(const std::string &base64)
    {
        string result = "";

        string bin = base64_to_binary(base64);
        for (size_t i = 0; i < bin.length(); i += 4) {
            string sub = bin.substr(i, 4);
            result += Quest1::binToHex(sub);
        }
        if (result.length() % 2 == 1)
            result.erase(result.length() - 1);

        return result;
    }

    static std::string base64_to_binary(const std::string &base64)
    {
        // Base64 to binary mapping
        std::string result;
        for (int i = 0; i < base64.length(); i++) {
            if (base64[i] >= 'A' && base64[i] <= 'Z')
                result += std::bitset<6>(base64[i] - 'A').to_string();
            else if (base64[i] >= 'a' && base64[i] <= 'z')
                result += std::bitset<6>(base64[i] - 'a' + 26).to_string();
            else if (base64[i] >= '0' && base64[i] <= '9')
                result += std::bitset<6>(base64[i] - '0' + 52).to_string();
            else if (base64[i] == '+')
                result += std::bitset<6>(62).to_string();
            else if (base64[i] == '/')
                result += std::bitset<6>(63).to_string();
        }
        return result;
    }

    static std::string hex_to_ascii(const std::string &hex)
    {
        std::stringstream result;
        for (size_t i = 0; i < hex.length(); i += 2)
        {
            std::string byteString = hex.substr(i, 2);
            char byte = (char)strtol(byteString.c_str(), NULL, 16);
            result << byte;
        }
        return result.str();
    }

    ~Quest6();
};

#endif // QUEST6_H