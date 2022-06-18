#pragma once
#include <iostream>

namespace login {
    auto loginIn(std::string filePath) -> bool;

    /**
     * @brief Used to login in the program
     * @param userPassword, kay
     * @return true if the password is correct, false if not
     */

    auto saveTime(time_t time, std::string filePath) -> void;

    /**
     * @brief Saves the time of the last login
     * @param time
     */
}
