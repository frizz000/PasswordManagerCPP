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
        srand(time(NULL));

        std::string password;
        std::string category;
        std::string login;
        std::string email;
        std::string website;
        std::string note;
        int passwordLength;
        std::ofstream file;

        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string s_symbol = "!@#$%&";
        std::string number = "0123456789";

        std::cout << "Choose option:\n" << std::endl <<
                  "1 - add password by self\n"
                  "2 - add password by generator\n"
                  "3 - go to menu\n" << std::endl;
        int choice;
        std::cout << "Enter number:";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter new password: ";
                std::cin >> password;
                while (password.length() < 8 || password.length() > 16) {
                    std::cout << "Password is too short or is too long. Enter new password: ";
                    std::cin >> password;
                }
                while (password.find('0') == std::string::npos && password.find('1') == std::string::npos &&
                       password.find('2') == std::string::npos && password.find('3') == std::string::npos &&
                       password.find('4') == std::string::npos && password.find('5') == std::string::npos &&
                       password.find('6') == std::string::npos && password.find('7') == std::string::npos &&
                       password.find('8') == std::string::npos && password.find('9') == std::string::npos) {
                    std::cout << "Password must contain at least one number. Enter new password: ";
                    std::cin >> password;
                }
                while (password.find('a') == std::string::npos && password.find('b') == std::string::npos &&
                       password.find('c') == std::string::npos && password.find('d') == std::string::npos &&
                       password.find('e') == std::string::npos && password.find('f') == std::string::npos &&
                       password.find('g') == std::string::npos && password.find('h') == std::string::npos &&
                       password.find('i') == std::string::npos && password.find('j') == std::string::npos &&
                       password.find('k') == std::string::npos && password.find('l') == std::string::npos &&
                       password.find('m') == std::string::npos && password.find('n') == std::string::npos &&
                       password.find('o') == std::string::npos && password.find('p') == std::string::npos &&
                       password.find('q') == std::string::npos && password.find('r') == std::string::npos &&
                       password.find('s') == std::string::npos && password.find('t') == std::string::npos &&
                       password.find('u') == std::string::npos && password.find('v') == std::string::npos &&
                       password.find('w') == std::string::npos && password.find('x') == std::string::npos &&
                       password.find('y') == std::string::npos && password.find('z') == std::string::npos) {
                    std::cout << "Password must contain at least one lowercase letter. Enter new password: ";
                    std::cin >> password;
                }
                while (password.find('A') == std::string::npos && password.find('B') == std::string::npos &&
                       password.find('C') == std::string::npos && password.find('D') == std::string::npos &&
                       password.find('E') == std::string::npos && password.find('F') == std::string::npos &&
                       password.find('G') == std::string::npos && password.find('H') == std::string::npos &&
                       password.find('I') == std::string::npos && password.find('J') == std::string::npos &&
                       password.find('K') == std::string::npos && password.find('L') == std::string::npos &&
                       password.find('M') == std::string::npos && password.find('N') == std::string::npos &&
                       password.find('O') == std::string::npos && password.find('P') == std::string::npos &&
                       password.find('Q') == std::string::npos && password.find('R') == std::string::npos &&
                       password.find('S') == std::string::npos && password.find('T') == std::string::npos &&
                       password.find('U') == std::string::npos && password.find('V') == std::string::npos &&
                       password.find('W') == std::string::npos && password.find('X') == std::string::npos &&
                       password.find('Y') == std::string::npos && password.find('Z') == std::string::npos) {
                    std::cout << "Password must contain at least one uppercase letter. Enter new password: ";
                    std::cin >> password;
                }
                while (password.find('!') == std::string::npos && password.find('@') == std::string::npos &&
                       password.find('#') == std::string::npos && password.find('$') == std::string::npos &&
                       password.find('%') == std::string::npos && password.find('^') == std::string::npos &&
                       password.find('&') == std::string::npos && password.find('*') == std::string::npos &&
                       password.find('(') == std::string::npos && password.find(')') == std::string::npos &&
                       password.find('-') == std::string::npos && password.find('_') == std::string::npos &&
                       password.find('=') == std::string::npos && password.find('+') == std::string::npos &&
                       password.find('[') == std::string::npos && password.find(']') == std::string::npos &&
                       password.find('{') == std::string::npos && password.find('}') == std::string::npos &&
                       password.find(';') == std::string::npos && password.find('\'') == std::string::npos &&
                       password.find('\"') == std::string::npos && password.find('|') == std::string::npos &&
                       password.find('\\') == std::string::npos && password.find('/') == std::string::npos &&
                       password.find(',') == std::string::npos && password.find('.') == std::string::npos &&
                       password.find('<') == std::string::npos && password.find('>') == std::string::npos &&
                       password.find('?') == std::string::npos && password.find('~') == std::string::npos &&
                       password.find('`') == std::string::npos) {
                    std::cout << "Password must contain at least one special symbol. Enter new password: ";
                    std::cin >> password;
                }
                std::cout << "Password is correct\n" << std::endl;

                std::cout << "Enter new category: ";
                std::cin >> category;
                std::cout << "Enter new login: ";
                std::cin >> login;
                std::cout << "Enter new email: ";
                std::cin >> email;
                while (email.find('@') == std::string::npos) {
                    std::cout << "Email is incorrect" << std::endl;
                    std::cout << "Enter new email: ";
                    std::cin >> email;
                }
                std::cout << "Enter new website: ";
                std::cin >> website;
                std::cout << "Enter new note: ";
                std::cin >> note;
                file.open(filePath, std::ios::app);
                file << password << " | " << category << " | " << login << " | " << email << " | " << website << " | "
                     << note;
                file.close();
            case 2:
                std::cout << "Enter password length (8-24): ";
                std::cin >> passwordLength;
                if (passwordLength < 8 || passwordLength > 24) {
                    std::cout << "Invalid password length" << std::endl;
                    addPassword(filePath);
                } else {
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
                        while (email.find('@') == std::string::npos) {
                            std::cout << "Email is incorrect" << std::endl;
                            std::cout << "Enter new email: ";
                            std::cin >> email;
                        }
                        std::cout << "Enter website: ";
                        std::cin >> website;
                        std::cout << "Enter note: ";
                        std::cin >> note;
                        std::cout << "Saving..." << std::endl;
                        std::ofstream file;
                        file.open(filePath, std::ios::app);
                        file << password << " | " << category << " | " << login << " | " << email << " | " << website
                             << " | " << note;
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

    auto fileStruct(std::string filePath) -> void {
        std::fstream file;
        file.open(filePath);
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
}
