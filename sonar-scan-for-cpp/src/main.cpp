/*
This C++ program uses the std::string class to work with strings. 
It first checks if the in_data string is empty. If it's empty, it prints the "string is empty" message. I
f the string is not empty and has at least two characters, it prints the last two characters. 
If the string has less than two characters, it prints a message accordingly.
*/
#include <iostream>
#include <string>

int main() {
    std::string in_data = "this is the new way to code";

    if (in_data.empty()) {
        std::cout << "String is empty" << std::endl;
    } else if (in_data.length() >= 2) {
        std::cout << "Last two characters: " << in_data[in_data.length() - 2] << in_data[in_data.length() - 1] << std::endl;
    } else {
        std::cout << "String has less than two characters" << std::endl;
    }

    return 0;
}