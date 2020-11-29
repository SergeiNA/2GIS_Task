#include <iostream>
#include "include/common.h"
#include "include/AppOptions.h"

int main(int argc, const char *argv[]) {
    auto options = getProgrammOptions(argc, argv);
    if(!options.has_value()){
        return 0;
    }
    std::cout << "Get Configs----------------------------\n";
    std::cout << "File: "            << options.value().file 
              << "\nMode: "          << options.value().mode
              << "\nWord to count: " << options.value().word << "\n";

    test_foo();
    return 0;
}
