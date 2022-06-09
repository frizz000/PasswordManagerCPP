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


auto main() -> int{
    bool isLogIn = false;
    bool quit = false;
    int choiceOption;
    std::string fileName;

    while(!isLogIn)
        isLogIn = log::verifyAccess();

    if(isLogIn)
    {

        time_t timeNow = time(0);
        log::saveLoginTimestamp(timeNow);

        while(!quit)
        {

            std::cout << "Welcome to the Password Manager!" << std::endl;
            std::cout << "Type '9' to see help." << std::endl;
            std::cout << "Enter operation: " << std::endl;

            std::cin >> choiceOption;


            switch(choiceOption)
            {
                case 1:
                    std::cout << "You chose 'search password'" << std::endl;
                    break;
                case 2:
                    std::cout << "You chose 'sort passwords'" << std::endl;
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
                    cipher::help();
                    break;
                case 9:
                    std::cout << "You chose 'quit program'" << std::endl;
                    quit = true;
                    break;
                default:
                    std::cout<<"Operation not recognized, try again.";
                    break;
            }
        }
    }
}

