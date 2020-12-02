#include "include/AppOptions.h"
#include "include/constans.h"
#include <iostream>
#include <set>
#include <unordered_map>

#if __GNUC__ < 9
#include <experimental/filesystem>
#else
#include <filesystem>
#endif

#if __GNUC__ < 9
namespace fs = std::experimental::filesystem;
#else
namespace fs = std::filesystem;
#endif

namespace bopt = boost::program_options;

using optList      =  std::vector<std::string>;
using optValueList =  std::set<std::string>;

/**
 * @brief Используется для преобразования строкового 
 * представления режима работы в тип перечислений 
 */
inline const static  std::unordered_map<std::string, MODE> str2mode{
    {detail::M_CHEKSUM, MODE::HASH},
    {detail::M_WORDS, 	MODE::WORD}
};


// Часть примеров взята здесь https://www.boost.org/doc/libs/1_55_0/libs/program_options/example/real.cpp

void conflicting_options(const bopt::variables_map& vm, 
                         const std::string& opt1,
                         const std::string& opt1_value,
                         const std::string& opt2)
{
    if ((vm.count(opt1) && vm["mode"].as<std::string>() == opt1_value) 
         && vm.count(opt2) )
        throw std::logic_error(
                std::string("Conflicting options '") 
                + opt1 
                + "' and '" 
                + opt2 
                + "'."
            );
}

/* Function used to check that of 'for_what' is specified, then
   'required_option' is specified too. */
void option_dependency(const bopt::variables_map& vm,
                       const std::string& for_what,
                       const std::string& required_option)
{
    if (vm.count(for_what))
        if (vm.count(required_option) == 0 )
            throw std::logic_error(
                    std::string("Option '")
                    + for_what 
                    + "' requires option '"
                    + required_option + "'."
                );
}

void opt_and_val_dependency(const bopt::variables_map& vm,
                       const std::string& for_what,
                       const std::string& for_what_value,
                       const std::string& required_option)
{
    if (vm.count(for_what) && vm[for_what].as<std::string>() == for_what_value)
        if (vm.count(required_option) == 0 )
            throw std::logic_error(
                    std::string("Option '")
                    + for_what
                    + "' whith param '"
                    + vm[for_what].as<std::string>()
                    + "' requires option '"
                    + required_option + "'."
                );
}

void option_validate_values(const bopt::variables_map& vm,
                       const std::string& opt,
                       const optValueList& required_options_value)
{
    if (vm.count(opt)){
        auto opt_value = vm[opt].as<std::string>();
        if (required_options_value.find(opt_value)
             == end(required_options_value))
            throw std::logic_error(
                    std::string("Option: '")
                    + opt 
                    + "' error value: '"
                    + opt_value + "'."
                );
    }
}

void required_options(const bopt::variables_map& vm,
                      const optList& required_options){
    for(const auto& opt:required_options){
        if (!vm.count(opt))
            throw std::logic_error(
                std::string("Required options not found '")
                + opt 
                + "'."
            );
    }
}

Options createOption(const bopt::variables_map& vm){
    Options options;
    if (vm.count("file")){
        auto fname = vm["file"].as<std::string>();
        if(!fs::exists(fname))
            throw std::logic_error(
                std::string("Error 'file' option value '")
                + fname 
                + "' not found."
            );
        options.file = fname;
        options.file_size = fs::file_size(fname);
        std::cout << "File: " << fname << std::endl;
        std::cout << "File size: " << options.file_size << " bytes" << std::endl;
    }
    if (vm.count("mode")){
		auto value = vm["mode"].as<std::string>();
        std::cout << "Mode: " << value << std::endl;
		auto it = str2mode.find(value);
        if(it == end(str2mode))
        	throw std::logic_error(
                std::string("Error 'mode' option value '")
                + value 
                + "'."
            );
		options.mode = str2mode.at(value);
    }
    if (vm.count("view")){
		std::cout << "Word to count: " << vm["view"].as<std::string>() << std::endl;
        options.word = vm["view"].as<std::string>();
	}
    return options;
}

std::optional<Options> getProgrammOptions(int argc, const char *argv[]) {
    bopt::options_description desc{"Справка"};
    desc.add_options()
        ("help,h", "Вывести справку")
        ("file,f", bopt::value<std::string>(), "Название файла для обработки")
        ("mode,m", bopt::value<std::string>(),
        "Режим работы [words|checksum]\n\
mode:\n\
 - words - подсчёт количества слов, заданных параметром -v counted_word\n\
требуется для ключа -v [слово для подсчёта]\n\
 - checksum - подсчёт контрольной суммы")
        ("view,v", bopt::value<std::string>(), 
        "Слово, количество повторений которого в файле нужно подсчитать");

    bopt::command_line_parser parser{argc, argv};
    parser.options(desc).allow_unregistered();

    try {
    	bopt::parsed_options parsed_options = parser.run();
    	bopt::variables_map vm;

    	store(parsed_options, vm);
    	notify(vm);

    	if (vm.count("help")){
        	std::cout << desc << '\n';
        	return std::nullopt;
    	}
    
        required_options        (vm, {"file", "mode"});
        option_validate_values  (vm, "mode", {detail::M_CHEKSUM, detail::M_WORDS});
        conflicting_options     (vm, "mode", detail::M_CHEKSUM, "view");
        option_dependency       (vm, "view", "mode");
        opt_and_val_dependency  (vm, "mode", detail::M_WORDS, "view");

    	return createOption(vm);
    }
    catch(const std::exception& e) {
                std::cerr << "[Command line argument parsing]: " << e.what() << '\n';
        std::cout << desc << '\n';
        return std::nullopt;
    }

}
