#pragma once
#include <iostream>

class Operations;

namespace cipher {
    auto encrypt(const std::string& message, const int key) -> std::string;
    auto dcrypt(const std::string& message, const int key) -> std::string;
}
