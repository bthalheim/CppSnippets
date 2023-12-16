

#include <iostream>
#include <windows.h>
#include <pdh.h>

#pragma comment(lib, "pdh.lib")

int main() {
    PDH_HQUERY query;
    PDH_HCOUNTER counter;
    PDH_HCOUNTER counter2;

    // Initialize PDH
    PdhOpenQuery(nullptr, 0, &query);
    PdhAddCounter(query, "\\Processor(_Total)\\C1 Transitions/sec", 0, &counter);
    PdhAddCounter(query, "\\Processor(_Total)\\C2 Transitions/sec", 0, &counter2);
   
    PdhCollectQueryData(query);

    // Query and display CPU usage every second
    for (int i = 0; i < 10; ++i) {
        Sleep(1000);

        PDH_FMT_COUNTERVALUE value;
        PDH_FMT_COUNTERVALUE value2;

        PdhCollectQueryData(query);
        PdhGetFormattedCounterValue(counter,  PDH_FMT_DOUBLE, nullptr, &value);
        PdhGetFormattedCounterValue(counter2, PDH_FMT_DOUBLE, nullptr, &value2);

        std::cout << "C1 Transitions/sec: " << value.doubleValue << "%" << std::endl;
        std::cout << "C2 Transitions/sec: " << value2.doubleValue << "%" << std::endl;
        
    }

    // Close PDH
    PdhCloseQuery(query);

    return 0;
}




