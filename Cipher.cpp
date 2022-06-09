#include <iostream>

namespace cipher{
    auto encrypt(const std::string& message, const int key) -> std::string {
        std::string encryptedMessage;
        for (auto ch : message) {
            if (ch >= 'a' && ch <= 'z') {
                ch = ch + key;
                if (ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                }
                encryptedMessage += ch;
            } else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + key;
                if (ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
                encryptedMessage += ch;
            } else {
                encryptedMessage += ch;
            }
        }
        return encryptedMessage;
    }
    auto dcrypt(const std::string& message, const int key) -> std::string {
        std::string decryptedMessage;
        for (auto ch : message) {
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - key;
                if (ch < 'a') {
                    ch = ch + 'z' - 'a' + 1;
                }
                decryptedMessage += ch;
            } else if (ch >= 'A' && ch <= 'Z') {
                ch = ch - key;
                if (ch < 'A') {
                    ch = ch + 'Z' - 'A' + 1;
                }
                decryptedMessage += ch;
            } else {
                decryptedMessage += ch;
            }
        }
        return decryptedMessage;
    }
}