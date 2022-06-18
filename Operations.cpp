#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <regex>
#include "Operations.hpp"
#include "Cipher.hpp"

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

        std::cout << "This program is made by: Piotr Jalocha\n" << std::endl;
    }

    auto openFile() -> std::string {

        std::string filePath;
        std::string fileName;
        std::string password;
        int key;
        std::ofstream file;

        std::cout << "Choose option:\n" << std::endl <<
                  "1 - choose file path from program\n"
                  "2 - write absolute path to your file\n"
                  "3 - create new file\n" << std::endl;

        int choice;
        std::cout << "Enter number:";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice) {
            case 1:
                std::cout << "1 - \"..\\\\files\\\\login.txt\"" << std::endl;
                std::cout << "2 - \"..\\\\files\\\\login2.txt\"\n" << std::endl;
                int choiceFileNumber;
                std::cout << "Enter file number:";
                std::cin >> choiceFileNumber;
                std::cout << std::endl;
                switch (choiceFileNumber) {
                    case 1:
                        filePath = "..\\files\\login.txt";
                        break;
                    case 2:
                        filePath = "..\\files\\login2.txt";
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
                while (filePath.length() == 0) {
                    std::cout << "Your file path is empty. Try again: ";
                    std::cout << "Enter your absolute file path \n"
                                 "(i.e. G:\\szkola\\PJC\\PasswordManagerCPP\\files\\login.txt): ";
                    std::cin >> filePath;
                }
                while (filePath.find("\\") == std::string::npos) {
                    std::cout << "Your file path is wrong" << std::endl;
                    std::cout << "Enter your absolute file path \n"
                                 "(i.e. G:\\szkola\\PJC\\PasswordManagerCPP\\files\\login.txt): ";
                    std::cin >> filePath;
                }
                while (filePath.find(".txt") == std::string::npos) {
                    std::cout << "Your file path has to end with .txt" << std::endl;
                    std::cout << "Enter your absolute file path \n"
                                 "(i.e. G:\\szkola\\PJC\\PasswordManagerCPP\\files\\login.txt): ";
                    std::cin >> filePath;
                }
                while (filePath.find("G:\\") == std::string::npos && filePath.find("C:\\") == std::string::npos &&
                        filePath.find("D:\\") == std::string::npos && filePath.find("E:\\") == std::string::npos &&
                        filePath.find("F:\\") == std::string::npos && filePath.find("H:\\") == std::string::npos &&
                        filePath.find("I:\\") == std::string::npos && filePath.find("J:\\") == std::string::npos &&
                        filePath.find("K:\\") == std::string::npos && filePath.find("L:\\") == std::string::npos &&
                        filePath.find("M:\\") == std::string::npos && filePath.find("N:\\") == std::string::npos &&
                        filePath.find("O:\\") == std::string::npos && filePath.find("P:\\") == std::string::npos &&
                        filePath.find("Q:\\") == std::string::npos && filePath.find("R:\\") == std::string::npos &&
                        filePath.find("S:\\") == std::string::npos && filePath.find("T:\\") == std::string::npos &&
                        filePath.find("U:\\") == std::string::npos && filePath.find("V:\\") == std::string::npos &&
                        filePath.find("W:\\") == std::string::npos && filePath.find("X:\\") == std::string::npos &&
                        filePath.find("Y:\\") == std::string::npos && filePath.find("Z:\\") == std::string::npos) {
                    std::cout << "Your file path is wrong" << std::endl;
                    std::cout << "Enter your absolute file path \n"
                                 "(i.e. G:\\szkola\\PJC\\PasswordManagerCPP\\files\\login.txt): ";
                    std::cin >> filePath;
                }
                std::cout << "Your file path is: " << filePath << std::endl;
                break;
            case 3:
                std::cout << "Enter file name:";
                std::cin >> fileName;
                std::cout << "Enter new password for file" << std::endl;
                std::cin >> password;
                std::cout << "Enter key to password: ";
                std::cin >> key;

                file.open("..\\files\\" + fileName + ".txt");
                file << cipher::encrypt(password, key)  << std::endl;
                file << "  Password   | Category |   Login  |     E-mail     |     Site     |     Notes     " << std::endl;
                file.close();

                filePath = "..\\files\\" + fileName + ".txt";

                std::cout << "File created" << std::endl;
                break;
            default:
                std::cout << "Invalid file path" << std::endl;
                openFile();
                break;
        }
        return filePath;
    }

    auto deleteFile(std::string filePath) -> void {
        std::string fileName;
        std::cout << "Remember you can't delete file if it is opened" << std::endl;
        std::cout << "Enter file name to remove: ";
        std::cin >> fileName;
        fileName = "..\\files\\" + fileName + ".txt";

        if (fileName == filePath) {
            std::cout << "You can't delete opened file" << std::endl;
            deleteFile(filePath);
        }

        std::cout << "Are you sure you want to remove file? (y/n)";
        char choice;
        std::cin >> choice;
        if (choice == 'y') {
            std::remove(fileName.c_str());
            std::cout << "File removed" << std::endl;
        } else if (choice == 'n') {
            std::cout << "File not removed" << std::endl;
        } else {
            std::cout << "Invalid choice" << std::endl;
            deleteFile(filePath);
        }
    }

    auto quit() -> void {
        std::cout << "Goodbye!\n"
                     "ps. Mr. Kwiatkowski is a cool teacher" << std::endl;
        exit(0);
    }


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
        std::string symbol = "!@#$%&";
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
                    std::cout << "Email is incorrect, add '@'" << std::endl;
                    std::cout << "Enter new email: ";
                    std::cin >> email;
                }
                std::cout << "Enter new website: ";
                std::cin >> website;
                std::cout << "Enter new note: ";
                std::cin >> note;
                file.open(filePath, std::ios::app);
                file << '-' << password << '-' << " | " << '=' << category << '=' << " | " << ':' << login << ':'
                     << " | " << '-' << email << ':' << " | " << '=' << website << ':'
                     << " | " << note;
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
                                password += symbol[rand() % symbol.length()];
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
                            std::cout << "Email is incorrect, add '@'" << std::endl;
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
                        file << '-' << password << '-' << " | " << '=' << category << '=' << " | " << ':' << login
                             << ':' << " | " << '-' << email << ':' << " | " << '=' << website << ':'
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


    auto show(std::string filePath) -> void {
        std::ifstream file;
        file.open(filePath);
        int numberLine = 0;
        while (!file.eof()) {
            std::string line;
            std::getline(file, line);
            std::cout << numberLine << ". " << line << std::endl;
            numberLine++;
        }
        std::cout << std::endl;
    }

    auto editPassword(std::string filePath) -> void {
        std::ifstream file;
        file.open(filePath);
        int numberLine = 0;
        std::string lineSearch;

        std::ofstream temp("..\\files\\temp.txt");

        std::string passwordToEdit;
        std::string newPassword;

        while (!file.eof()) {
            std::string line;
            std::getline(file, line);
            std::cout << numberLine << ". " << line << std::endl;
            numberLine++;
        }
        std::cout << std::endl;

        std::cout << "Enter password to edit: ";
        std::cin >> passwordToEdit;
        std::cout << "Enter new password: ";
        std::cin >> newPassword;
        std::cout << "Enter new password: ";
        std::cin >> newPassword;
        while (newPassword.length() < 8 || newPassword.length() > 16) {
            std::cout << "Password is too short or is too long. Enter new password: ";
            std::cin >> newPassword;
        }
        while (newPassword.find('0') == std::string::npos && newPassword.find('1') == std::string::npos &&
               newPassword.find('2') == std::string::npos && newPassword.find('3') == std::string::npos &&
               newPassword.find('4') == std::string::npos && newPassword.find('5') == std::string::npos &&
               newPassword.find('6') == std::string::npos && newPassword.find('7') == std::string::npos &&
               newPassword.find('8') == std::string::npos && newPassword.find('9') == std::string::npos) {
            std::cout << "Password must contain at least one number. Enter new password: ";
            std::cin >> newPassword;
        }
        while (newPassword.find('a') == std::string::npos && newPassword.find('b') == std::string::npos &&
               newPassword.find('c') == std::string::npos && newPassword.find('d') == std::string::npos &&
               newPassword.find('e') == std::string::npos && newPassword.find('f') == std::string::npos &&
               newPassword.find('g') == std::string::npos && newPassword.find('h') == std::string::npos &&
               newPassword.find('i') == std::string::npos && newPassword.find('j') == std::string::npos &&
               newPassword.find('k') == std::string::npos && newPassword.find('l') == std::string::npos &&
               newPassword.find('m') == std::string::npos && newPassword.find('n') == std::string::npos &&
               newPassword.find('o') == std::string::npos && newPassword.find('p') == std::string::npos &&
               newPassword.find('q') == std::string::npos && newPassword.find('r') == std::string::npos &&
               newPassword.find('s') == std::string::npos && newPassword.find('t') == std::string::npos &&
               newPassword.find('u') == std::string::npos && newPassword.find('v') == std::string::npos &&
               newPassword.find('w') == std::string::npos && newPassword.find('x') == std::string::npos &&
               newPassword.find('y') == std::string::npos && newPassword.find('z') == std::string::npos) {
            std::cout << "Password must contain at least one lowercase letter. Enter new password: ";
            std::cin >> newPassword;
        }
        while (newPassword.find('A') == std::string::npos && newPassword.find('B') == std::string::npos &&
               newPassword.find('C') == std::string::npos && newPassword.find('D') == std::string::npos &&
               newPassword.find('E') == std::string::npos && newPassword.find('F') == std::string::npos &&
               newPassword.find('G') == std::string::npos && newPassword.find('H') == std::string::npos &&
               newPassword.find('I') == std::string::npos && newPassword.find('J') == std::string::npos &&
               newPassword.find('K') == std::string::npos && newPassword.find('L') == std::string::npos &&
               newPassword.find('M') == std::string::npos && newPassword.find('N') == std::string::npos &&
               newPassword.find('O') == std::string::npos && newPassword.find('P') == std::string::npos &&
               newPassword.find('Q') == std::string::npos && newPassword.find('R') == std::string::npos &&
               newPassword.find('S') == std::string::npos && newPassword.find('T') == std::string::npos &&
               newPassword.find('U') == std::string::npos && newPassword.find('V') == std::string::npos &&
               newPassword.find('W') == std::string::npos && newPassword.find('X') == std::string::npos &&
               newPassword.find('Y') == std::string::npos && newPassword.find('Z') == std::string::npos) {
            std::cout << "Password must contain at least one uppercase letter. Enter new password: ";
            std::cin >> newPassword;
        }
        while (newPassword.find('!') == std::string::npos && newPassword.find('@') == std::string::npos &&
               newPassword.find('#') == std::string::npos && newPassword.find('$') == std::string::npos &&
               newPassword.find('%') == std::string::npos && newPassword.find('^') == std::string::npos &&
               newPassword.find('&') == std::string::npos && newPassword.find('*') == std::string::npos &&
               newPassword.find('(') == std::string::npos && newPassword.find(')') == std::string::npos &&
               newPassword.find('-') == std::string::npos && newPassword.find('_') == std::string::npos &&
               newPassword.find('=') == std::string::npos && newPassword.find('+') == std::string::npos &&
               newPassword.find('[') == std::string::npos && newPassword.find(']') == std::string::npos &&
               newPassword.find('{') == std::string::npos && newPassword.find('}') == std::string::npos &&
               newPassword.find(';') == std::string::npos && newPassword.find('\'') == std::string::npos &&
               newPassword.find('\"') == std::string::npos && newPassword.find('|') == std::string::npos &&
               newPassword.find('\\') == std::string::npos && newPassword.find('/') == std::string::npos &&
               newPassword.find(',') == std::string::npos && newPassword.find('.') == std::string::npos &&
               newPassword.find('<') == std::string::npos && newPassword.find('>') == std::string::npos &&
               newPassword.find('?') == std::string::npos && newPassword.find('~') == std::string::npos &&
               newPassword.find('`') == std::string::npos) {
            std::cout << "Password must contain at least one special symbol. Enter new password: ";
            std::cin >> newPassword;
        }
        std::cout << "Password is correct\n" << std::endl;

        while (file >> lineSearch) {
            if (lineSearch == passwordToEdit) {
                lineSearch = newPassword;
            }
            lineSearch += " ";
            temp << lineSearch;
        }
        file.close();
        temp.close();
        remove(filePath.c_str());
        rename("..\\files\\temp2.txt", filePath.c_str());

        std::cout << "Password changed successfully" << std::endl;
    }

    auto removePassword(std::string filePath) -> void {
        std::fstream file;
        std::string line;
        int numberLine = 0;
        int passwordLine;
        int lineNumberToDelete = 1;

        file.open(filePath);

        std::fstream temp;
        temp.open("..\\files\\temp.txt", std::fstream::out);


        while (!file.eof()) {
            std::string line;
            std::getline(file, line);
            std::cout << numberLine << ". " << line << std::endl;
            numberLine++;
        }
        std::cout << std::endl;

        std::cout << "Enter passwordLine line to remove: ";
        std::cin >> passwordLine;

        if (passwordLine < 2 || passwordLine > numberLine) {
            std::cout << "Invalid number\n" << std::endl;
            removePassword(filePath);
        } else {
            std::cout << "Removing..." << std::endl;
            while (std::getline(file, line)) {
                if (lineNumberToDelete != passwordLine) {
                    temp << line << std::endl;
                }
                lineNumberToDelete++;
            }
            file.close();
            temp.close();
            remove(filePath.c_str());
            rename("..\\files\\temp.txt", filePath.c_str());
        }
    }

    auto searchPassword(std::string filePath) -> void {
        std::fstream file;
        std::string word;
        int numberLine = 0;
        int counter = 0;

        file.open(filePath.c_str());

        std::cout << "Enter word to equals: ";
        std::cin >> word;
        std::cout << std::endl;

        std::cout << "Searching..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Found passwords:" << std::endl;

        while (!file.eof()) {
            std::string line;
            std::getline(file, line);
            if (line.find(word) != std::string::npos) {
                std::cout << numberLine << ". " << line << std::endl;
                counter++;
            }
            numberLine++;
        }
        if (counter == 0) {
            std::cout << "No passwords found" << std::endl;
        }

        std::cout << std::endl;
    }

    auto sortPasswords(std::string filePath) -> void {
        std::fstream file;
        file.open(filePath);

        std::vector<std::string> passwords;
        std::string lineP;
        std::regex wordRegex("-[a-zA-Z0-9!#$@%^&*()/]+-");
        while (std::getline(file, lineP)) {
            std::string word;
            std::stringstream ss(lineP);
            while (ss >> word) {
                if (regex_match(word, wordRegex)) {
                    passwords.push_back(word);
                }
            }
        }


        std::vector<std::string> categories;
        std::string lineC;
        std::regex wordRegexC("=[a-zA-Z0-9!#$@%^&*()/]+=");
        while (std::getline(file, lineC)) {
            std::string word;
            std::stringstream ss(lineC);
            while (ss >> word) {
                if (regex_match(word, wordRegexC)) {
                    categories.push_back(word);
                }
            }
        }


        std::vector<std::string> logins;
        std::string lineL;
        std::regex wordRegexL(":[a-zA-Z0-9!#$@%^&*()/]+:");
        while (std::getline(file, lineL)) {
            std::string word;
            std::stringstream ss(lineL);
            while (ss >> word) {
                if (regex_match(word, wordRegexL)) {
                    logins.push_back(word);
                }
            }
        }


        std::vector<std::string> emails;
        std::string lineE;
        std::regex wordRegexE("-[a-zA-Z0-9!#$@%.^&*()/]+:");
        while (std::getline(file, lineE)) {
            std::string word;
            std::stringstream ss(lineE);
            while (ss >> word) {
                if (regex_match(word, wordRegexE)) {
                    emails.push_back(word);
                }
            }
        }

        std::vector<std::string> websites;
        std::string lineW;
        std::regex wordRegexW("=[a-zA-Z0-9!#$@%.^&*()/]+:");
        while (std::getline(file, lineW)) {
            std::string word;
            std::stringstream ss(lineW);
            while (ss >> word) {
                if (regex_match(word, wordRegexW)) {
                    websites.push_back(word);
                }
            }
        }

        std::cout << "Enter sort type: " << std::endl;
        std::cout << "1. Length of password" << std::endl;
        std::cout << "2. Alphabetically of password" << std::endl;
        std::cout << "3. Category" << std::endl;
        std::cout << "4. Login" << std::endl;
        std::cout << "5. Email" << std::endl;
        std::cout << "6. Website" << std::endl;
        std::cout << "7. Back to menu" << std::endl;

        int sortType;
        std::cout << "Enter sort type: \n";
        std::cin >> sortType;

        switch (sortType) {
            case 1:
                std::cout << "Sorting by length..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::sort(passwords.begin(), passwords.end(), [](const std::string &a, const std::string &b) {
                    return a.length() < b.length();
                });
                for (auto &i: passwords) {
                    std::cout << i << std::endl;
                }
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "Sorting by alphabet..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::sort(passwords.begin(), passwords.end());
                for (auto &i: passwords) {
                    std::cout << i << std::endl;
                }
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Sorting by category..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::sort(categories.begin(), categories.end());
                for (auto &i: categories) {
                    std::cout << i << std::endl;
                }
                std::cout << std::endl;
                break;
            case 4:
                std::cout << "Sorting by login..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::sort(logins.begin(), logins.end());
                for (auto &i: logins) {
                    std::cout << i << std::endl;
                }
                std::cout << std::endl;
                break;
            case 5:
                std::cout << "Sorting by email..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::sort(emails.begin(), emails.end());
                for (auto &i: emails) {
                    std::cout << i << std::endl;
                }
                std::cout << std::endl;
            case 6:
                std::cout << "Sorting by website..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::sort(websites.begin(), websites.end());
                for (auto &i: websites) {
                    std::cout << i << std::endl;
                }
                std::cout << std::endl;
            case 7:
                std::cout << "Back to menu..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                break;
            default:
                std::cout << "Wrong input..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                break;
        }
    }

    auto addCategory(std::string filePath) -> void {
        std::ofstream file;
        file.open(filePath, std::ios::app);
        std::string categoryName;


        std::string password = "         ";
        std::string login = "         ";
        std::string email = "         ";
        std::string website = "         ";
        std::string note = "         ";


        std::cout << "Enter category: " << std::endl;
        std::cin >> categoryName;
        file << '-' << password << '-' << " | " << '=' << categoryName << '=' << " | " << ':' << login << ':' << " | "
             << '-' << email << ':' << " | " << '=' << website << ':'
             << " | " << note;

        std::cout << "Category added\n" << std::endl;
        file.close();
    }

    auto removeCategory(std::string filePath) -> void {
        std::fstream file;
        int numberLine = 0;
        int categoryLine;
        int lineNumberToDelete = 1;

        file.open(filePath);

        std::fstream temp;
        temp.open("..\\files\\temp.txt", std::fstream::out);


        while (!file.eof()) {
            std::string line;
            std::getline(file, line);
            std::cout << numberLine << ". " << line << std::endl;
            numberLine++;
        }
        std::cout << std::endl;

        std::cout << "Enter category to remove: ";
        std::cout << "Remember this removes all passwords in this category" << std::endl;
        std::cin >> categoryLine;

        while (!file.eof()) {
            std::string line;
            std::getline(file, line);
            if (line.find(categoryLine) != std::string::npos) {
                lineNumberToDelete++;
            } else {
                temp << line << std::endl;
            }

            file.close();
            temp.close();
            remove(filePath.c_str());
            rename("..\\files\\temp.txt", filePath.c_str());
        }
        std::cout << "Category removed\n" << std::endl;
    }
}

