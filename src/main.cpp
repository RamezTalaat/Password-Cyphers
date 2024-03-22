// Name: Ramez Ehab Talaat Riad , ID: 20206025
// Name: Khaled Ahmed Sayed Hashem , ID: 20206019

#include "../include/utils.hpp"

int main()
{
    short choice = 0;
    do
    {
        print_menu();
        choice = get_choice();
        std::string msg, encryptedMsg;
        int shiftAmount;
        std::map<char, char> map;
        switch (choice)
        {
        case 1:
            std::cout << "Enter K (Shift Amount): ";
            std::cin >> shiftAmount;
            std::cin.ignore();
            std::cout << "Enter the message to be Encrypted : ";
            std::getline(std::cin, msg);
            map = generate_caesar_map(shiftAmount);
            encryptedMsg = cypher(map, msg);
            std::cout << "Encrypted Message : " << encryptedMsg << "\n";
            break;
        case 2:
            std::cout << "Enter the message to be Encrypted : ";
            std::cin.ignore();
            std::getline(std::cin, msg);
            map = generate_random_map();
            encryptedMsg = cypher(map, msg);
            std::cout << "Encrypted Message : " << encryptedMsg << "\n";
            break;
        case 3:
            std::cout << "Thank you for your time\n";
            break;
        default:
            std::cout << "Please enter a valid number\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
