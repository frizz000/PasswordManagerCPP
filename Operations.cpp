#include <iostream>
#include <fstream>
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

        std::cout << "This program is made by: Piotr Jalocha" << std::endl;
    }

    /**
     * @brief Help for the user
     * @param time
     */

    auto openFile() -> std::string {

        std::string filePath;

        std::cout << "Choose option:\n" << std::endl <<
                     "1 - choose file path from program\n"
                     "2 - write absolute path to your file\n" << std::endl;

        int choice;
        std::cout << "Enter number:";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice) {
            case 1:
                std::cout << "1 - \"..\\\\files\\\\login.txt\"" << std::endl;
                std::cout << "2 - \"..\\\\files\\\\file2.txt\"\n" << std::endl;
                int choiceFileNumber;
                std::cout << "Enter file number:";
                std::cin >> choiceFileNumber;
                std::cout << std::endl;
                switch (choiceFileNumber) {
                    case 1:
                        filePath = "..\\files\\login.txt";
                        break;
                    case 2:
                        filePath = "..\\files\\file2.txt";
                        break;
                    default:
                        std::cout << "You choose wrong number" << std::endl;
                        openFile();
                        break;
                }
                break;
            case 2:
                std::cout << "Enter your absolute file path \n"
                             "(i.e. G:\\szkola\\PJC\\PasswordManagerCPP\\files\\login.txt): ";
                std::cin >> filePath;
                break;
            default:
                std::cout << "Invalid file path" << std::endl;
                openFile();
                break;
        }
        return filePath;
    }

    auto quit() -> void {
        std::cout << "Goodbye!\n"
                     "ps. Mr. Kwiatkowski is cool teacher" << std::endl;
        exit(0);
    }

    /**
     * @brief quit program
     */

    auto addPassword(std::string filePath) -> void {
        std::string password;
        std::string category;
        std::string login;
        std::string email;
        std::string website;
        std::string note;

        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string s_symbol = "!@#$%&";
        std::string number = "0123456789";

        std::cout << "Choose option:\n" << std::endl <<
                     "1 - add password by self\n"
                     "2 - add password by generator\n"
                     "3 - go to menu\n"<< std::endl;
        int choice;
        std::cout << "Enter number:";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter new password: ";
                std::cin >> password;
                if (password.size() < 8 || password.size() > 24 || password.empty()) {
                    std::cout << "Password is to short or to long" << std::endl;
                    addPassword(filePath);
                } else if (password.find_first_not_of("0123456789") != std::string::npos) {
                    std::cout << "Password must have numbers" << std::endl;
                    addPassword(filePath);
                } else if (password.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos){
                    std::cout << "Password must have small letters" << std::endl;
                    addPassword(filePath);
                } else if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos){
                    std::cout << "Password must have big letters" << std::endl;
                    addPassword(filePath);
                } else if (password.find_first_not_of("!@#$%^&*()_+-=[]{}|;':,./<>?`~") != std::string::npos){
                    std::cout << "Password must have special characters" << std::endl;
                    addPassword(filePath);
                } else {
                    std::cout << "Password is correct\n" << std::endl;

                    std::cout << "Enter new category: ";
                    std::cin >> category;
                    std::cout << "Enter new login: ";
                    std::cin >> login;
                    std::cout << "Enter new email: ";
                    std::cin >> email;
                    std::cout << "Enter new website: ";
                    std::cin >> website;
                    std::cout << "Enter new note: ";
                    std::cin >> note;
                    std::ofstream file;
                    file.open(filePath, std::ios::app);
                    file << password << " " << category << " " << login << " " << email << " " << website << " " << note << std::endl;
                    file.close();
                }
            case 2:
                int passwordLength;
                std::cout << "Enter password length (8-24): ";
                std::cin >> passwordLength;
                if (passwordLength < 8 || passwordLength > 24) {
                    std::cout << "Invalid password length" << std::endl;
                    addPassword(filePath);
                } else{
                    for (int i = 0; i < passwordLength; i++) {
                        int random = rand() % 4;
                        switch (random) {
                            case 0:
                                password += alphabet[rand() % alphabet.length()];
                                break;
                            case 1:
                                password += ALPHABET[rand() % ALPHABET.length()];
                                break;
                            case 2:
                                password += s_symbol[rand() % s_symbol.length()];
                                break;
                            case 3:
                                password += number[rand() % number.length()];
                                break;
                        }
                    }
                    std::cout << "Your password is: " << password << std::endl;
                    std::cout << "Do you want to save it? (y/n)" << std::endl;
                    char saveChoice;
                    std::cin >> saveChoice;
                    if (saveChoice == 'y') {
                        std::cout << "Enter category: ";
                        std::cin >> category;
                        std::cout << "Enter login: ";
                        std::cin >> login;
                        std::cout << "Enter email: ";
                        std::cin >> email;
                        std::cout << "Enter website: ";
                        std::cin >> website;
                        std::cout << "Enter note: ";
                        std::cin >> note;
                        std::cout << "Saving..." << std::endl;
                        std::ofstream file;
                        file.open(filePath, std::ios::app);
                        file << password << " " << category << " " << login << " " << email << " " << website << " " << note << std::endl;
                        file.close();
                        std::cout << "Saved!" << std::endl;
                    } else if (saveChoice == 'n') {
                        std::cout << "You chose no to save password, try again.\n" << std::endl;
                        addPassword(filePath);
                    } else {
                        std::cout << "Invalid choice\n" << std::endl;
                        addPassword(filePath);
                    }
                }
            case 3:
                std::cout << "Back to menu...\n" << std::endl;
                break;
            default:
                std::cout << "Invalid choice\n" << std::endl;
                addPassword(filePath);
            }
        }
    }
