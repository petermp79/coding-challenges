
// Function to get multiple input on the same line
// Optionally, output input data for visual inspection
//

#include <sstream>

vector<int> getMultiInput(string msg, bool output) {
    vector<int> inputs{}; 
    std::string line;
    int data = 0;

    cout << msg;

    cin >> data;
    inputs.push_back(data);

    // get the rest input data
    std::getline(std::cin, line);
    std::istringstream input(line);
    while (input >> data) {
        inputs.push_back(data);
    }

    if (output) {
        for (auto data : inputs) {
            cout << data << " ";
        }
        cout << endl;
    }
    return inputs;
}

