#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// main string
int STRING_PARAM = 1;
char STRING_PROMPT[] = "Please enter string to search from";
// offset
int OFFSET_PARAM = 2;
char OFFSET_PROMPT[] = "Please enter number of occurences of search to skip";
// search string
int SEARCH_PARAM = 3;
char SEARCH_PROMPT[] = "Please enter string to use as search";

/**
 * @brief Get string from command args if index is present, if not prompt user for it
 * @param argc count of args from user
 * @param argv args from user
 * @param paramIndex index of arg being targeted
 * @param prompt message to display when asking for input
 */
string getStringParam(int argc, char** argv, int paramIndex, char* prompt) {
    if(argc < paramIndex) {
        cout << prompt << endl;
        string input;
        cin >> input;
        return input;
    } 
    return argv[paramIndex];
}

/**
 * @brief Get int from command args if index is present, if not prompt user for it
 * @param argc count of args from user
 * @param argv args from user
 * @param paramIndex index of arg being targeted
 * @param prompt message to display when asking for input
 */
int getIntParam(int argc, char** argv, int paramIndex, char* prompt) {
    if(argc < paramIndex) {
        cout << prompt << endl;
        int input;
        cin >> input;
        return input;
    }
    return atoi(argv[paramIndex]);
}

/**
 * @brief Recursively search string to find index of substring
 *  I am very proud of this function, recursion rules
 * @param source string to be searched through 
 * @param search substring to be found
 * @param index spot in the string to start
 * @param matchLevel where in the substring to start
 * @return index of substring, or -1 if not found
 */
int findIndexMatch(string source, string search, int &index, int matchLevel) {
    if(search.size() == matchLevel) return index - matchLevel;
    
    if(source.at(index) == search.at(matchLevel)) {
        ++index;
        ++matchLevel;
        return findIndexMatch(source, search, index, matchLevel);
    }

    return -1;
}

/**
 * @brief Handles finding index of substring, and continuing until offset number has been satisfied
 * @param source string to be searched
 * @param offset how many instances of substring to skip
 * @param search substring to be searched
 * @return index of substring, or -1 if not found
 */
int handleSearch(string source, int offset, string search) {
    int occurenceFound = 0;
    int index = 0;
    while(index < source.size()) {
        int matchLevel = 0;
        int matchIndex = findIndexMatch(source, search, index, matchLevel);
        if(matchIndex >= 0) {
            ++occurenceFound;
            if(occurenceFound > offset)
                return matchIndex;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    string source = getStringParam(argc, argv, STRING_PARAM, STRING_PROMPT);
    int offset = getIntParam(argc, argv, OFFSET_PARAM, OFFSET_PROMPT);
    string search = getStringParam(argc, argv, SEARCH_PARAM, SEARCH_PROMPT);
    cout << handleSearch(source, offset, search) << endl;
}