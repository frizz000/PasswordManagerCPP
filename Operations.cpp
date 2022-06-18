#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <regex>
#include "Operations.hpp"
#include "Cipher.hpp"

namespace operations {

    std::vector<std::string> categories = {"social", "work", "private"};


    auto help() -> void {
        std::cout << " ___                                                     \n"
                     " /__)  _   _   _         _  _/   /|/|  _     _   _  _  _ \n"
                     "/     (/ _)  _)  ((/ () /  (/   /   | (/ /) (/  (/ (- /  \n"
                     "                                               _/        " << std::endl;
        std::cout << "Helow, this is a password manager,\n"
                     "made by Piotr Jalocha,\n"
                     "you can use this program to manage your passwords.\n" << std::endl;

        std::cout << "To use this program, you need to have a file with your passwords.\n"
                     "You can create a new file or open an existing one.\n" << std::endl;

        std::cout << "To create a new file, you need to enter the name of the file.\n"
                     "You can use the following format: \n"
                     "\"filename.txt\"\n" << std::endl;

        std::cout << "To open an existing file, you need to chose the file.\n";
        std::cout << "To add a new password, you need to chose the 'add password' option.\n";
        std::cout << "To show all passwords, you need to chose the 'show passwords' option.\n";
        std::cout << "To edit a password, you need to chose the 'edit password' option.\n";
        std::cout << "To remove a password, you need to chose the 'remove password' option.\n";
        std::cout << "To add a category, you need to chose the 'add category' option.\n";
        std::cout << "To remove a category, you need to chose the 'remove category' option.\n";
        std::cout << "To sort passwords, you need to chose the 'sort passwords' option.\n";
        std::cout << "To search passwords, you need to chose the 'search password' option.\n";
        std::cout << "To show file, you need to chose the 'show file' option.\n";
        std::cout << "To remove file, you need to chose the 'remove file' option.\n";
        std::cout << "To quit the program, you need to chose the 'quit program' option.\n";
        std::cout << "To see this menu again, you need to chose the 'help menu' option.\n";
        std::cout << "To exit the program, you need to chose the 'exit program' option.\n" << std::endl;

        std::cout << "Thank you for using this program!\n" << std::endl;
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
                file << cipher::encrypt(password, key) << std::endl;
                file << "  Password   | Category |   Login  |     E-mail     |     Site     |     Notes     "
                     << std::endl;
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

        std::cout << "1 - If you want to delete file from program" << std::endl;
        std::cout << "2 - If you want to back to main menu" << std::endl;

        int choice;
        std::cout << "Enter number:";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Remember you can't delete file if it is opened" << std::endl;
                std::cout << "Enter file name to remove: ";
                std::cin >> fileName;
                fileName = "..\\files\\" + fileName + ".txt";

                if (fileName == filePath) {
                    std::cout << "You can't delete opened file" << std::endl;
                    deleteFile(filePath);
                }

                std::cout << "Are you sure you want to remove file? (y/n)";
                char choiceFile;
                std::cin >> choiceFile;
                if (choice == 'y') {
                    std::remove(fileName.c_str());
                    std::cout << "File removed" << std::endl;
                } else if (choice == 'n') {
                    std::cout << "File not removed" << std::endl;
                } else {
                    std::cout << "Invalid choice" << std::endl;
                    deleteFile(filePath);
                }
            case 2:
                break;
        }
    }

    auto quit() -> void {
        std::cout << "Goodbye!\n"
                     "ps. Mr. Kwiatkowski is a cool teacher" << std::endl;
        exit(0);
    }


    auto addPassword(std::string filePath) -> void {

        std::string password;
        std::string category;
        std::string login;
        std::string email;
        std::string website;
        std::string note;
        int passwordLength;
        std::ofstream file;
        char specialSymbols;
        char lowercaseLetters;
        char uppercaseLetters;
        char numbers;

        std::cout << "Choose option:\n" << std::endl <<
                  "1 - If you want to add password by self\n"
                  "2 - If you want to add password by generator\n"
                  "3 - If you want to back to menu\n" << std::endl;
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

                std::cout << "1. Enter new category \n" <<
                          "2. Choose from the list \n";
                int choiceCategory;
                std::cout << "Enter your choice: ";
                std::cin >> choiceCategory;
                if (choiceCategory == 1) {
                    std::cout << "Enter new category: ";
                    std::cin >> category;
                    categories.push_back(category);
                } else if (choiceCategory == 2) {
                    std::cout << "Choose from the list: ";
                    for (int i = 0; i < categories.size(); i++) {
                        std::cout << i + 1 << ". " << categories[i] << std::endl;
                    }
                    int choiceCategory2;
                    std::cin >> choiceCategory2;
                    category = categories[choiceCategory2 - 1];
                } else {
                    std::cout << "Wrong input. Enter new category: ";
                    addPassword(filePath);
                }
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
                std::cout << "Type y/n if you want to use special symbols: ";
                std::cin >> specialSymbols;
                std::cout << "Type y/n if you want to use lowercase letters: ";
                std::cin >> lowercaseLetters;
                std::cout << "Type y/n if you want to use uppercase letters: ";
                std::cin >> uppercaseLetters;
                std::cout << "Type y/n if you want to use numbers: ";
                std::cin >> numbers;

                if (passwordLength < 8 || passwordLength > 24) {
                    std::cout << "Invalid password length" << std::endl;
                    addPassword(filePath);
                } else {
                    password = operations::generatePassword(passwordLength, specialSymbols, lowercaseLetters,
                                                       uppercaseLetters, numbers);
                }


                std::cout << "Your password is: " << password << std::endl;
                std::cout << "Do you want to save it? (y/n)" << std::endl;
                char saveChoice;
                std::cin >> saveChoice;
                if (saveChoice == 'y') {
                    std::cout << "1. Enter new category \n" <<
                              "2. Choose from the list \n";
                    int choiceCategory;
                    std::cout << "Enter your choice: ";
                    std::cin >> choiceCategory;
                    if (choiceCategory == 1) {
                        std::cout << "Enter new category: \n";
                        std::cin >> category;
                        categories.push_back(category);
                    } else if (choiceCategory == 2) {
                        std::cout << "Choose from the list: \n";
                        for (int i = 0; i < categories.size(); i++) {
                            std::cout << i + 1 << ". " << categories[i] << std::endl;
                        }
                        std::cout << std::endl;
                        int choiceCategory2;
                        std::cout << "Enter your choice: ";
                        std::cin >> choiceCategory2;
                        category = categories[choiceCategory2 - 1];
                    } else {
                        std::cout << "Wrong input. Enter new category: ";
                        addPassword(filePath);
                    }
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

        std::cout << "1 - If you want to edit password\n" <<
                        "2 - If you want to back to menu\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
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
            case 2:
                break;
        }
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

        std::cout << "1 - If you want to remove password" << std::endl;
        std::cout << "2 - If you want to back to menu" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
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
            case 2:
                break;
        }
    }

    auto searchPassword(const std::string& filePath) -> void {
        std::fstream file;
        std::string word;
        int numberLine = 0;
        int counter = 0;

        file.open(filePath.c_str());

        std::cout << "1 - If you want to search" << std::endl;
        std::cout << "2 - If you want to back to menu" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
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
            case 2:
                break;
            default:
                std::cout << "Invalid number" << std::endl;
                searchPassword(filePath);
        }
    }

    auto sortPasswords(const std::string& filePath) -> void {
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
        std::cout << "1 - If you want to sort by length" << std::endl;
        std::cout << "2 - If you want to sort by alphabet" << std::endl;
        std::cout << "3 - If you want to sort by category" << std::endl;
        std::cout << "4 - If you want to sort by login" << std::endl;
        std::cout << "5 - If you want to sort by email" << std::endl;
        std::cout << "6 - If you want to sort by website" << std::endl;
        std::cout << "7 - If you want to back to menu" << std::endl;

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

    auto addCategory() -> void {
        std::string categoryName;

        std::cout << "Category added!\n" << std::endl;
        std::cout << "1 - If you want to add category." << std::endl;
        std::cout << "2 - If you want to show categories." << std::endl;
        std::cout << "3 - If you want to go back to menu.\n" << std::endl;

        int choice;
        std::cout << "Enter choice: \n" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter category: " << std::endl;
                std::cin >> categoryName;
                categories.push_back(categoryName);
                break;
            case 2:
                for (int i = 0; i < categories.size(); i++) {
                    std::cout << i + 1 << ". " << categories[i] << std::endl;
                }
                std::cout << std::endl;
                break;
            case 3:
                break;
            default:
                std::cout << "Wrong input..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                addCategory();
        }

    }

    auto removeCategory(const std::string filePath) -> void {
        std::fstream file;
        int numberLine = 0;
        std::string categoryNameToRemove;
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

        std::cout << "1 - If you want to remove category." << std::endl;
        std::cout << "2 - If you want to go back to menu.\n" << std::endl;

        int choice;
        std::cout << "Enter choice: \n" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Remember this removes all passwords in this category \n" << std::endl;
                std::cout << "Enter category to remove: ";
                std::cin >> categoryNameToRemove;

                for (int i = 0; i < categories.size(); i++) {
                    if (categories[i] == categoryNameToRemove) {
                        categories.erase(categories.begin() + i);
                    }
                }

                file.seekg(0, std::ios::beg);

                while (!file.eof()) {
                    std::string line;
                    std::getline(file, line);
                    if (line != categoryNameToRemove) {
                        temp << line << std::endl;
                    }

                    file.close();
                    temp.close();
                    remove(filePath.c_str());
                    rename("..\\files\\temp.txt", filePath.c_str());
                }
                std::cout << "Category removed\n" << std::endl;
                break;
            case 2:
                break;
            default:
                std::cout << "Wrong input..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                removeCategory(filePath);
        }
    }
    auto generatePassword(int passwordLength, char specialSymbols, char lowercaseLetters, char uppercaseLetters,
                          char numbers) -> std::string {
        std::string password;
        srand(time(NULL));
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string symbol = "!@#$%&";
        std::string number = "0123456789";
        std::string charsToMakePassword = "";

        if (specialSymbols == 'y') {
            charsToMakePassword += symbol;
        }
        if (lowercaseLetters == 'y') {
            charsToMakePassword += alphabet;
        }
        if (uppercaseLetters == 'y') {
            charsToMakePassword += ALPHABET;
        }
        if (numbers == 'y') {
            charsToMakePassword += number;
        }

        for (int i = 0; i < passwordLength; i++) {
            int random = rand() % charsToMakePassword.length();
            password += charsToMakePassword[random];
        }
        return password;
    }
}

