#pragma once
#include <iostream>

namespace cipher {
        int key;

    auto setKey(int key){
            auto encrypt(std::string &message);
            auto decrypt(std::string &message);
        }
}
