#pragma once
#include <iostream>

namespace cipher {
    auto encrypt(const std::string& message, const int key) -> std::string;
}
