cmake_minimum_required(VERSION 3.20)
project(Crypto_Exchange)

set(CMAKE_CXX_STANDARD 14)

add_executable(Crypto_Exchange main.cpp classes/Admin.cpp headers/Admin.h classes/User.cpp headers/User.h classes/ExchangeDatabase.cpp headers/ExchangeDatabase.h classes/Currency.cpp headers/Currency.h)
