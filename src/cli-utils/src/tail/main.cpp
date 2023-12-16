
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <cxxopts.hpp>

void tailFile(const std::string& filename, int numLines, bool follow) {

    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(file, line)) {
        lines.push_back(line);
        if ((int)lines.size() > numLines) {
            lines.erase(lines.begin());
        }

    }

    // Display the last 'numLines' lines
    for (const auto& l : lines) {
        std::cout << l << std::endl;
    }

    // If follow is true, keep 
    while (follow) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    
    }

}

int main(int argc, char* argv[]) {

    cxxopts::Options options("tail", "A simple cross-platform 'tail' program");

    options.add_options()
        ("n,num", "Number or lines to display", cxxopts::value<int>()->default_value("10"))
        ("f,follow", "Output appended data as a the file grows")
        ("h,help", "Print Help");

    options.add_options("Positional")
        ("file", "File to display", cxxopts::value<std::string>());


    auto result = options.parse(argc, argv); 

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    if (!result.count("file")) {
        std::cerr << "No file specified. Use --help for usage information" << std::endl;
        return 1;
    }

    std::string filename = result["file"].as<std::string>();
    int numLines = result["num"].as<int>();
    bool follow = result.count("follow") > 0;

    tailFile(filename, numLines, follow);

    return 0;

}






























