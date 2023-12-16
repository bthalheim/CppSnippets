#include <iostream>
#include <windows.h>
#include <pdh.h>
#include <vector>

#pragma comment(lib, "pdh.lib")


/* Testing Metric Object
 *
 */


class Metric {

    public: 

        Metric(const std::string startingQueryString,
               const std::string startingCategory,
               const std::string startingDescription) {


            queryString  = startingQueryString; 
            category     = startingCategory; 
            description  = startingDescription;

        }

   
        void set_query(const LPCSTR newQueryString) {
            queryString = newQueryString;
        }


        std::string get_Query() {
            return queryString; 
        }


        void registerCounter(const PDH_HQUERY query) {
            // Convert Query to LPCSTR 
            PdhAddCounter(query, queryString.c_str(), 0, &counter);
        }

        void testOutput() {

            PdhGetFormattedCounterValue(counter,  PDH_FMT_DOUBLE, nullptr, &value);
            std::cout << description << ": " << value.doubleValue << std::endl;
        }



    private:
        
        std::string queryString;
        std::string category; 
        std::string description;

        PDH_HCOUNTER counter; 
        PDH_FMT_COUNTERVALUE value; 

};


int main() {

    std::vector<Metric> metrics; 

    PDH_HQUERY query;
    PdhOpenQuery(nullptr, 0, &query);

    metrics.push_back(Metric("\\Processor(_Total)\\C1 Transitions/sec", "Processor(_Total)", "C1 Transitions/sec")); 
    metrics.push_back(Metric("\\Processor(_Total)\\C2 Transitions/sec", "Processor(_Total)", "C2 Transitions/sec")); 
    metrics.push_back(Metric("\\Processor(_Total)\\C3 Transitions/sec", "Processor(_Total)", "C3 Transitions/sec")); 


    for (auto& met : metrics) {
        met.registerCounter(query);
    }
  
    PdhCollectQueryData(query);

    for (int i = 0; i < 100; ++i) {
        Sleep(1000);
        PdhCollectQueryData(query);

        for (auto& met : metrics) {
            met.testOutput();
        }

    }

    
    // Close PDH
    PdhCloseQuery(query);

    return 0;
}




