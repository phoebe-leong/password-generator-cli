#include <iostream>
#include <string>
#include <array>
#include <time.h>

#include "password.h"
#include "exceptions.h"

int main(int argc, char* argv[]) {
    int length = 12;
    bool upperLetters = true, lowerLetters = true, numbers = true, specials = true;

    for (int i = 0; i < argc; i++) {
        std::string arg = std::string(argv[i]);
        if (arg == "--help") {
            std::cout
                << "\nUsage: passgen [arguments]\n"
                << "    --help\n"
                << "        Displays this menu and exit\n"
                << "    -l / --length <number>\n"
                << "        Sets password length. Default: 12\n"
                << "    --no-letters\n"
                << "        Disables letters\n"
                << "    --no-numbers\n"
                << "        Disables numbers\n"
                << "    --no-specials\n"
                << "        Disables special characters\n";
            return 0;
        } else if (arg == "-l" || arg == "--length") {
            i++;
            length = atoi(argv[i]);
        } else if (arg == "--no-letters") {
            upperLetters = false;
            lowerLetters = false;
        } else if (arg == "--no-numbers") {
            numbers = false;
        } else if (arg == "--no-specials") {
            specials = false;
        }
    }

    std::string password = generatePassword(length, lowerLetters, upperLetters, numbers, specials);

    std::cout << "Your new password is : " << password << std::endl;

    return 0;
}
