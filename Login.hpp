#pragma once
#include <iostream>

namespace login {
    auto loginIn(std::string filePath) -> bool;
    auto saveTime(time_t time, std::string filePath) -> void;
}
