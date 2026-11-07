#include <cstring>
#include <iostream>
#include <new>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief Get the bool From char 
 */
bool charToBool(char* input) {
    return atoi(input) == 1;
}

/**
 * @brief Get a vector<bool> from command line args, representing chapters to include
 */
vector<bool> getChapterListFromArgs(int argc, char** argv) {
    vector<bool> values;

    for(int i = 1; i < argc; ++i) 
        values.push_back(charToBool(argv[i]));

    return values;
}

/**
 * @brief Get a vector<bool> by prompting user for input
 */
vector<bool> getChapterListFromInput(int chapterCount) {
    vector<bool> chptList(chapterCount);
    bool includeChpt;
    for (int i = 1; i <= 15; ++i) {
        cin >> includeChpt; 
        chptList.at(i) = includeChpt;
    }
    return chptList;
}

/**
 * @brief Since make file can be set up to automatically run with input after building, this checks if command args were supplied for it
 */
vector<bool> getChapterList(int argc, char** argv, int chapterCount) {
    if(argc > 1) return getChapterListFromArgs(argc, argv);
    else return getChapterListFromInput(chapterCount);
}

/**
 * @brief Handles printing and re-assignment of iterator when the end of a range has been found 
 */
void handleRangeEnd(int &i, int count) {
    int offset = i + 2;
    if(count >= offset) {
        cout << (count > offset ? "-" : " ") << count;
        i = count;
    }
}

/**
 * @brief Checks down the vector from i, until it finds a false in the vector
 */
void checkForRange(const vector<bool> &chptList, int &i) {
    int count = i + 1;
    while(count < chptList.size() - 2) { 
        if(!chptList.at(count)) {
            handleRangeEnd(i, count);
            break;
        }
        ++count;
    }
}

/**
 * @brief Handles printing results of user input to UI
 */
void printResults(const vector<bool> &chptList) {
    for(int i = 0; i < chptList.size(); ++i) { 
        if(chptList.at(i )) {
            cout << i + 1; 
            checkForRange(chptList, i);
            cout << " ";
        }
    }
}

int main(int argc, char** argv) {
    int defaultChapterSize = 15;
    vector<bool> chptList = getChapterList(argc, argv, defaultChapterSize);
    printResults(chptList);
    return 0;
}