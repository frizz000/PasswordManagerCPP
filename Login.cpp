#include <iostream>
#include <fstream>
#include <ctime>
#include "Login.hpp"
#include "Cipher.hpp"

namespace login {
    auto loginIn() -> bool {
        std::fstream file = std::fstream("..\\files\\loginPass.txt");
        std::string pass;
        file.open("..\\files\\loginPass.txt");
        if (file.is_open()) {

        std::getline(file, pass);
        std::cout << "encrypt message: " << pass << std::endl;


            std::string userPassword;
            int kay;

            std::cout << "Password: " << std::endl;
            std::cin >> userPassword;

            std::cout << "Key: " << std::endl;
            std::cin >> kay;

            std::string globalPass;

            globalPass = cipher::dcrypt(pass, kay);
            //globalPass = "123";

            if (userPassword == globalPass) {
                std::cout << "Correct password \n" << std::endl;
                file.close();
                return true;
            } else {
                std::cout << "Incorrect password, try again (remember you have 3 attempts) \n" << std::endl;
                return false;
            }

        } else
            std::cout << "Access to file denied" << std::endl;
        return false;
    }

    /**
     * @brief Used to login in the program
     * @param userPassword, kay
     * @return true if the password is correct, false if not
     */

    auto saveTime(time_t time) -> void {

        std::fstream loginsOut;
        loginsOut.open("..\\files\\logins_timeline.txt", std::ofstream::out | std::ofstream::app);

        if (loginsOut.is_open()) {

            char *dt = std::ctime(&time);
            loginsOut << dt << "Login out" << std::endl;

        } else
            std::cout << "logins_timeline.txt not found" << std::endl;

        loginsOut.close();
    }
    /**
     * @brief Saves the time of the last login
     * @param time
     */
}