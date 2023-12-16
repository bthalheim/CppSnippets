
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <cxxopts.hpp>
#include <Windows.h>


void tailFile(const std::string& filename, int numLines, bool follow) {

    //std::ifstream file(filename);
    std::string line;
    std::vector<std::string> lines;


    // Read the last 'numLines' lines from the file
    /*
    while (std::getline(file, line)) { 
        lines.push_back(line);
        if ((int)lines.size() >  numLines) {
            lines.erase(lines.begin());
        {
    }
    */

    // Display the last 'numLines' lines
    /* 
    for (const auto& l : lines) {
        std::cout << l << std::endl;
    }
    */ 


    // If follow is true, keep reading and displaying new lines.
    while (follow) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // WIN32 File Access 
        HANDLE hFile = CreateFileA(filename.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile != INVALID_HANDLE_VALUE) {
            DWORD fileSize = GetFileSize(hFile, NULL);
            if (fileSize > 0 && fileSize > static_cast<DWORD>(lines.size())) {
                SetFilePointer(hFile, lines.size(), NULL, FILE_BEGIN);

                DWORD bytesRead; 
                CHAR buffer[4096];

                while (ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) {
                    std::string newContent(buffer, bytesRead);
                    std::istringstream iss(newContent);

                    while (std::getline(iss, line)) {
                        std::cout << line << std::endl;
                    }

                }

            }

            CloseHandle(hFile);

        }

    }

}




int main(int argc, char* argv[]) {
    cxxopts::Options options("win_tail", "A simple 'tail' program");

    options.add_options()
        ("n,num", "Number of lines to display", cxxopts::value<int>()->default_value("10"))
        ("f,follow", "Output appended data as the file grows")
        ("h,help", "Print help");

    options.add_options("Positional")
        ("file", "File to display", cxxopts::value<std::string>());

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    if (!result.count("file")) {
        std::cerr << "No file specified. Use --help for usage information." << std::endl;
        return 1;
    }

    std::string filename = result["file"].as<std::string>();
    int numLines = result["num"].as<int>();
    bool follow = result.count("follow") > 0;

    tailFile(filename, numLines, follow);

    return 0;
}








