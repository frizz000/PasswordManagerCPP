#include <iostream>
#include "Operations.hpp"

namespace operations {
    auto help() -> void {
        std::cout << "Available operations: " << std::endl;;
        std::cout << "1: search password" << std::endl;
        std::cout << "2: sort passwords" << std::endl;
        std::cout << "3: add password" << std::endl;
        std::cout << "4: edit password" << std::endl;
        std::cout << "5: remove password" << std::endl;
        std::cout << "6: add category" << std::endl;
        std::cout << "7: remove category" << std::endl;
        std::cout << "8: help menu" << std::endl;
        std::cout << "9: quit program" << std::endl;
    }

    /**
     * @brief Help for the user
     * @param time
     */

    auto openFile(std::string &filePath) -> void {

        std::cout << "Choose option:\n"
                     "1 - choose file\n"
                     "2 - write path to file" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                int choiceFileNumber;
                std::cout << "Enter file number: ";
                std::cin >> choiceFileNumber;
                switch (choiceFileNumber) {
                    case 1:
                        filePath = "./files/file1.txt";
                        break;
                    case 2:
                        filePath = "./files/file2.txt";
                        break;
                    default:
                        std::cout << "I" << std::endl;
                        break;
                }
                break;
            case 2:
                std::cout << "Enter file path: ";
                std::cin >> filePath;
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }

    }

    auto quit() -> void {
        std::cout << "Goodbye!" << std::endl;
        exit(0);
    }
}