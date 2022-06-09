#include<iostream>
#include "Cipher.hpp"

namespace cipher {
    auto encrypt(std::string &message) {
        for (char &c: message) {

            if (c >= 'a' && c <= 'z') {

                c += (cipher::key + 3);
                if (c > 'z')
                    c = c - 'z' + 'a' - 1;

            } else if (c >= 'A' && c <= 'Z') {

                c += (cipher::key + 3);
                if (c > 'Z')
                    c = c - 'Z' + 'A' - 1;

            }

        }

        return message;
    }
    auto decrypt(std::string &message){
        for(char& c : message)
        {

            if(c >= 'a' && c <= 'z')
            {
                c -= (cipher::key + 3);
                if(c < 'a')
                    c = c + 'z' - 'a' + 1;
            }
            else if(c >= 'A' && c <= 'Z')
            {

                c -= (cipher::key + 3);
                if (c < 'A')
                    c = c + 'Z' - 'A' + 1;

            }

        }

        return message;
    }
}




