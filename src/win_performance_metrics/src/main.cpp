

#include <iostream>
#include <windows.h>
#include <pdh.h>

#pragma comment(lib, "pdh.lib")

int main() {
    PDH_HQUERY query;
    PDH_HCOUNTER counter;

    // Initialize PDH
    PdhOpenQuery(nullptr, 0, &query);
    PdhAddCounter(query, "\\Processor(_Total)\\% Processor Time", 0, &counter);
    PdhCollectQueryData(query);

    // Query and display CPU usage every second
    for (int i = 0; i < 10; ++i) {
        Sleep(1000);

        PDH_FMT_COUNTERVALUE value;
        PdhCollectQueryData(query);
        PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE, nullptr, &value);

        std::cout << "CPU Usage: " << value.doubleValue << "%" << std::endl;
    }

    // Close PDH
    PdhCloseQuery(query);

    return 0;
}




