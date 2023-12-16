#include <iostream>
#include <fstream>
#include <string> 
#include <cxxopts.hpp>


int main(int argc, char* argv[]) {

    cxxopts::Options options("cat", "A simple cross-platform 'cat' program");

    options.add_options()
        ("f,file", "File to display", cxxopts::value<std::string>())
        ("h,help", "Print help");

    // options.add_options("Positional") 
    //    ("file", "File to display", cxxopts::value<std::string>());


    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    std::string filename; 

    if (result.count("file")) {
        filename = result["file"].as<std::string>();
    } else if (argc > 1) {
        filename = argv[1];
    } else {
        std::cerr << "No file specified. Use --help for usage information." << std::endl;
        return 1;
    }

    std::ifstream file(filename); 

    if (file.is_open()) {
        std::cout << file.rdbuf();
        file.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    return 0;

}




