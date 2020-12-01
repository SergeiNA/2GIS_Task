#include <iostream>
#include "include/common.h"
#include "include/AppOptions.h"
#include "include/ProcessManager.h"

int main(int argc, const char *argv[]) {
    try
    {
        auto options = getProgrammOptions(argc, argv);
        if(!options.has_value()){
            throw std::invalid_argument("Invalid argument: options are empty");
        }

        ProcessManager procManager(options.value());
        procManager.start();
        procManager.print();
    }
    catch(const std::exception& e)
    {
        std::cerr << "[Main error]: "<< e.what() << '\n';
    }
    
    return 0;
}
