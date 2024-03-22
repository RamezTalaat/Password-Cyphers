#ifndef UTILS_HPP
#define UTILS_HPP

#include <map>
#include <random>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "params.hpp"

std::map<char, char> generate_caesar_map(int k);
std::string cypher(const std::map<char, char> &map, const std::string &word);
std::map<char, char> generate_random_map();
void print_menu();
short get_choice();

#endif