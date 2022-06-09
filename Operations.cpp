#include <iostream>
#include "Operations.hpp"

namespace operations{
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
}
