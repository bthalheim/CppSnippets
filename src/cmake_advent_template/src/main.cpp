
#include <bits/stdc++.h>
using namespace std;

// #define int long long // Use int instead of long long for simplicity

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Open the input file
    ifstream input("../input/input.txt");
    if (!input.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // Vector to store lines
    vector<string> lines;

    // Read lines into the vector
    string line;
    while (getline(input, line)) {
        lines.push_back(line);
    }

    // Close the input file
    input.close();

    // Output each line with line number
    for (int i = 0; i < (int)lines.size(); ++i) {
        cout << "Line " << i + 1 << ": " << lines[i] << endl;
    }

    return 0;

}


