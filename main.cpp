#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <dirent.h>
#include "Cipher.hpp"
#include "Operations.hpp"
#include "Login.hpp"


auto main() -> int{
    bool isLogIn = false;
    bool quit = false;
    int choiceOption;
    std::string filePath;
    int logAttempts = 0;


    while(!isLogIn){
        std::cout << " ___                                                     \n"
                     " /__)  _   _   _         _  _/   /|/|  _     _   _  _  _ \n"
                     "/     (/ _)  _)  ((/ () /  (/   /   | (/ /) (/  (/ (- /  \n"
                     "                                               _/        " << std::endl;

        filePath = operations::openFile();

        std::cout << "LOG IN" << std::endl;
        isLogIn = login::loginIn(filePath);
        logAttempts++;
        if(logAttempts > 3){
            std::cout << "You have exceeded the number of attempts" << std::endl;
            exit(0);
        }
    }


    if(isLogIn) {

        time_t timeNow = time(0);
        login::saveTime(timeNow, filePath);

        while(!quit)
        {
            std::cout << "Available operations: " << std::endl;;
            std::cout << "1: search password    6: add category" << std::endl;
            std::cout << "2: sort passwords     7: remove category" << std::endl;
            std::cout << "3: add password       8: help menu" << std::endl;
            std::cout << "4: edit password      9: quit program" << std::endl;
            std::cout << "5: remove password \n" << std::endl;
            std::cout << "Enter operation: \n";



            {
                std::cout << "wyniki szyfrowania" << std::endl;
                std::cout << cipher::dcrypt(cipher::encrypt("lol123\n"
                                                            "\n"
                                                            "Fri Jun 17 13:49:31 2022\n"
                                                            "\n"
                                                            "Password | Category | Login | E-mail | Site | Note\n"
                                                            "-----------------------------------------------------------\n"
                                                            "GN4l76$@8g@U | dog | elo5 | elo@gmail.com | messanger | nic\n"
                                                            "8q#!LXZuJv%p | niewiem | lol123 | asda@gasd.pl | dasd.pl | haslo",
                                                            2), 2) << std::endl;
                std::cout << std::endl;


                std::string currentLine;
                std::ifstream file(filePath);
                while (std::getline(file, currentLine)) {
                    std::cout << cipher::dcrypt(currentLine, 2) << std::endl;
                }
            }



            std::cin >> choiceOption;


            switch(choiceOption)
            {
                case 1:
                    std::cout << "You chose 'search password'" << std::endl;
                    operations::searchPassword(filePath);
                    break;
                case 2:
                    std::cout << "You chose 'sort passwords'" << std::endl;
                    operations::sortPasswords(filePath);
                    break;
                case 3:
                    std::cout << "You chose 'add password'" << std::endl;
                    operations::addPassword(filePath);
                    break;
                case 4:
                    std::cout << "You chose 'edit password'" << std::endl;
                    operations::editPassword(filePath);
                    break;
                case 5:
                    std::cout << "You chose 'remove password'" << std::endl;
                    operations::removePassword(filePath);
                    break;
                case 6:
                    std::cout << "You chose 'add category'" << std::endl;
                    operations::addCategory(filePath);
                    break;
                case 7:
                    std::cout << "You chose 'remove category'" << std::endl;
                    operations::removeCategory(filePath);
                    break;
                case 8:
                    std::cout << "You chose 'help menu'" << std::endl;
                    operations::help();
                    break;
                case 9:
                    std::cout << "You chose 'quit program'" << std::endl;
                    quit = true;
                    operations::quit();
                    break;
                default:
                    std::cout<<"Operation not recognized, try again." << std::endl;
                    break;
            }
        }
    }
}

