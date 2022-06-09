cmake_minimum_required(VERSION 3.21)
project(PasswordManagerCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(PasswordManagerCPP main.cpp Cipher.cpp Cipher.hpp)