//Name: Ramez Ehab Talaat Riad , ID: 20206025
//Name: Khaled Ahmed Sayed Hashem , ID: 20206019
#include "bits/stdc++.h"
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

map<char , char> generateCaesarMap(int k){
    map<char , char> map;
    for (int i = 0; i < alphabet.size(); ++i) {
        map[alphabet[i]] = alphabet[(i + k ) % alphabet.size()];
    }
    return map;
}

string cypher(map<char , char>& map , string word){
    string result;
    for (int i = 0; i < word.size(); ++i) {
        if(isalpha(word[i])){
            char c = toupper(word[i]);
            result += map[c];
            //cout << c << " -> " <<  map[c] << endl;
        }
        else
            result += word[i];
    }
    return result;
}

map<char , char> generateRandomMap(){
    map<char , char> map;
    string randomized = alphabet;
    //C++ randomizer
    random_device rd;
    mt19937 g(rd());
    shuffle(randomized.begin(), randomized.end(), g);
    for (int i = 0; i < alphabet.size(); ++i) {
        map[alphabet[i]] = randomized[i];
    }
    return map;
}

int main() {
    int choice = 0;
    string input;
    while(choice != 3){
        cout << "Choose Option: \n";
        cout << "1) Caesar Cypher \n";
        cout << "2) Random Cypher \n";
        cout << "3) Exit \n";
        try {
            cin >> input;
            choice = stoi(input);//string parsing to int
        }
        catch(exception e) {
            cout << "Error : please enter a valid integer!\n";
            continue;
        }

        switch (choice) {
            case 1:{
                cout << "Enter K (Shift Amount): ";
                int k;
                cin >> k;
                cin.ignore();
                cout << "Enter the message to be Encrypted : ";
                string msg;
                map<char , char> map = generateCaesarMap(k);
//                for( auto& iter : map){
//                    cout << iter.first << " -> "<< iter.second << endl;
//                }
                getline(cin ,msg);
                string output = cypher(map , msg);
                cout << "Encrypted Message : " << output << "\n";
                break;
            }
            case 2:{
                cin.ignore();// to clear buffer
                cout << "Enter the message to be Encrypted : ";
                string msg;
                map<char , char> map = generateRandomMap();
//                for( auto& iter : map){
//                    cout << iter.first << " -> "<< iter.second << endl;
//                }
                getline(cin ,msg);
                string output = cypher(map , msg);
                cout << "Encrypted Message : " << output << "\n";
                break;
            }

            case 3:
                cout << "Thank you for your time\n";
                break;
            default:
                cout << "Please enter a valid number";
                break;
        }
    }



    return 0;


}
