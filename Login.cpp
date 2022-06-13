#include <iostream>
#include <fstream>
#include <ctime>
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
                std::cout << "Correct password \n" << std::endl;
                file.close();
                return true;
            } else {
                std::cout << "Incorrect password, try again (remember you have 3 attempts) \n" << std::endl;
                return false;
            }

        //} else
           // std::cout << "Access to file denied" << std::endl;
       // return false;
    }
    auto saveTime(time_t time) -> void {

        std::ofstream loginsOut;
        loginsOut.open("files/test.txt", std::ofstream::out | std::ofstream::trunc);

        if (loginsOut.is_open()) {

            char *dt = std::ctime(&time);
            loginsOut << dt;

        } else
            std::cout << "Can't open logins.txt";

        loginsOut.close();
    }
}