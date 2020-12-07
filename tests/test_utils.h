
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
inline std::uintmax_t getFileSize(const std::string& fname){
    if(!fs::exists(fname))
            throw std::logic_error(
                std::string("Error 'file' '")
                + fname 
                + "' not found."
            );
    return fs::file_size(fname);
}
        