#include <iostream>
#include <fstream>
#include <cereal/archives/binary.hpp>


#include "MyData.hpp"


int main() {



    // Serialize Data to a file
    {
        std::ofstream file("data.bin", std::ios::binary);
        cereal::BinaryOutputArchive archive(file);

        MyData data{42, 3.14f, "Hello, Cereal!"};
        archive (data);

    }


    // Deserialize Data from a file
    {
        std::ifstream file("data.bin", std::ios::binary);
        cereal::BinaryInputArchive archive(file);

        MyData loadedData;
        archive(loadedData);

        std::cout << "Loaded Data: " << loadedData.intValue << " " 
                  << loadedData.floatValue << " " << loadedData.stringValue << std::endl;

        
    }

    return 0;

}





