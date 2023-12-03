#ifndef MY_DATA_HPP
#define MY_DATA_HPP

#include <cereal/types/string.hpp>

struct MyData {
    int intValue;
    float floatValue;
    std::string stringValue;

    // Add Serialization Function 
    template <class Archive>
    void serialize(Archive& archive) {
        archive(intValue, floatValue, stringValue);
    }
};


#endif
