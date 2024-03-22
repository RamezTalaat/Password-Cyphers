#include "../include/utils.hpp"

std::map<char, char> generate_caesar_map(int k)
{
    std::map<char, char> map;
    for (size_t i = 0; i < alphabet.size(); ++i)
    {
        map[alphabet[i]] = alphabet[(i + k) % alphabet.size()];
    }
    return map;
}

std::string cypher(const std::map<char, char> &map, const std::string &word)
{
    std::stringstream resultStream;
    for (char c : word)
    {
        if (isalpha(c))
        {
            char uppercaseChar = toupper(c);
            auto it = map.find(uppercaseChar);
            if (it != map.end())
            {
                resultStream << it->second;
            }
            else
            {
                resultStream << c;
            }
        }
        else
        {
            resultStream << c;
        }
    }
    return resultStream.str();
}

std::map<char, char> generate_random_map()
{
    std::map<char, char> randomMap;
    std::string randomized = alphabet;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(randomized.begin(), randomized.end(), g);
    for (size_t i = 0; i < alphabet.size(); ++i)
    {
        randomMap[alphabet[i]] = randomized[i];
    }
    return randomMap;
}

void print_menu()
{
    std::cout << "\n************ MENU ************\n";
    std::cout << "1. Caesar Cypher\n";
    std::cout << "2. Random Cypher\n";
    std::cout << "3. Exit\n";
    std::cout << "*****************************\n\n";
}

short get_choice()
{
    short choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}