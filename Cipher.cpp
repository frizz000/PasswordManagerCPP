#include<iostream>
#include "Cipher.hpp"

namespace cipher {
    int key;

    auto Cipher::seKey(int key){
        this -> key = key;
    }


}
