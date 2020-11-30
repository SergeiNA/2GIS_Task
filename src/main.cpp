#include <iostream>
#include "include/common.h"
#include "include/AppOptions.h"
#include "include/ProcessManager.h"

int main(int argc, const char *argv[]) {
    auto options = getProgrammOptions(argc, argv);
    if(!options.has_value()){
        return 0;
    }
    std::cout << "Get Configs----------------------------\n";
    std::cout << "File: "            << options.value().file 
              << "\nMode: "          << options.value().mode
              << "\nWord to count: " << options.value().word << "\n";

    ProcessManager procManager(options.value());
    if(!procManager.start()){
        std::cerr << "Error while starting\n";
        return -1;
    }

    if(procManager.print()){
        std::cerr << "Error while printing\n";
        return -1;
    }
    
    return 0;
}
