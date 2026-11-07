#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/** @brief Get size for vector holding strings */
int getInput() {
    int size;
    cout << "Enter number of words to be entered" << endl;
    cin >> size;
    return size;
}
/**
 * @brief Get all of the words inputed
 * @param size how many words to look for in input
 */
vector<string> getValues(int size) {
    vector<string> values(size);
    for(int i = 0; i < size; ++i) cin >> values.at(i);
    return values;
}
/**
 * @brief Get the Counts of each word in values
 * @param values set of words to get counts for
 */
unordered_map<string, int> getCounts(vector<string> values) {
    // I actuallly am not sure how to do this with two vectors, but an unordered map seemed waaay easier 
    // If I was to do this in C# I would use a Dictionary<string, int> and reading online it looks like unordered_map is the equivalent
    unordered_map<string, int> counts;
    for(const auto value : values) {
        if(counts.find(value) == counts.end()) 
            counts[value] = 1;
        else 
            counts[value] += 1;
    }
    return counts;
}
/**
 * @brief Print counts to UI
 * @param values words that were inputted
 * @param counts counts for each distinct word from value
 */
void printResults(vector<string> values, unordered_map<string, int> counts) {
    for(const auto value : values) 
        cout << value << " - " << counts[value] << endl;
}

int main() {
    int size = getInput();
    vector<string> values = getValues(size); 
    unordered_map<string, int> counts = getCounts(values);
    printResults(values, counts);
    return 0;
}