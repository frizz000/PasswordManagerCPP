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
    std::string fileName;
    int logAttempts = 0;


    while(!isLogIn){
        std::cout << "Welcome to the Password Manager!" << std::endl;

        fileName = operations::openFile();

        std::cout << "LOG IN" << std::endl;
        isLogIn = login::loginIn(fileName);
        logAttempts++;
        if(logAttempts > 3){
            std::cout << "You have exceeded the number of attempts" << std::endl;
            exit(0);
        }
    }


    if(isLogIn) {

        time_t timeNow = time(0);
        login::saveTime(timeNow);

        while(!quit)
        {
            std::cout << "Available operations: " << std::endl;;
            std::cout << "1: search password    6: add category" << std::endl;
            std::cout << "2: sort passwords     7: remove category" << std::endl;
            std::cout << "3: add password       8: help menu" << std::endl;
            std::cout << "4: edit password      9: quit program" << std::endl;
            std::cout << "5: remove password \n" << std::endl;
            std::cout << "Enter operation: ";

            std::cin >> choiceOption;


            switch(choiceOption)
            {
                case 1:
                    std::cout << "You chose 'search password'" << std::endl;
                    std::cout << cipher::encrypt("123321", 5) << std::endl;
                    break;
                case 2:
                    std::cout << "You chose 'sort passwords'" << std::endl;
                    std::cout << cipher::dcrypt(cipher::encrypt("123321", 5), 5) << std::endl;
                    break;
                case 3:
                    std::cout << "You chose 'add password'" << std::endl;
                    break;
                case 4:
                    std::cout << "You chose 'edit password'" << std::endl;
                    break;
                case 5:
                    std::cout << "You chose 'remove password'" << std::endl;
                    break;
                case 6:
                    std::cout << "You chose 'add category'" << std::endl;
                    break;
                case 7:
                    std::cout << "You chose 'remove category'" << std::endl;
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

