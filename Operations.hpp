#pragma once
#include <iostream>
#include <fstream>

namespace operations {
    auto help() -> void;
    auto openFile() -> std::string;
    auto quit() -> void;
    auto addPassword(std::string filePath) -> void;
    auto show(std::string filePath) -> void;
    auto editPassword(std::string filePath) -> void;
    auto removePassword(std::string filePath) -> void;
    auto sortPasswords(std::string filePath) -> void;
    auto searchPassword(std::string filePath) -> void;
    auto addCategory(std::string filePath) -> void;
    auto removeCategory(std::string filePath) -> void;

}
