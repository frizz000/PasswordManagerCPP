#include <iostream>
#include <fstream>
#include "Login.hpp"
#include "Cipher.hpp"

namespace login {
    auto loginIn() -> bool {
        std::ifstream file;
        file.open("files/test.txt");
        //if (file.is_open()) {

            std::string userPassword;
            int kay;

            std::cout << "Password: " << std::endl;
            std::cin >> userPassword;

            std::cout << "Key: " << std::endl;
            std::cin >> kay;

            std::string globalPass;
            //file >> globalPass;
            //cipher::dcrypt(globalPass, kay);


            globalPass = "123";

            if (userPassword == globalPass) {
                std::cout << "Correct password" << std::endl;
                file.close();
                return true;
            } else {
                std::cout << "Incorrect password" << std::endl;
                return false;
            }

        //} else
           // std::cout << "Access to file denied" << std::endl;
       // return false;
    }
}