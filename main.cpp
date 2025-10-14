#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stdlib.h> 
#include <time.h>
#include <cstdlib>  
#include <ctime>    

#include "avl_map.h"
using namespace std;

vector<string> parseCSVLine(const string& line);
void searchRandomZipsAVL(avl_map<int, uscity>& myAVL, const std::vector<int>& zipcodes, int numSearches);
void searchRandomZipsMap(std::map<int, uscity>& standardMap, const std::vector<int>& zipcodes, int numSearches);
void benchmarkSearchesAVL(int treeSize, int numSearches, avl_map<int, uscity>& myAVL,const std::vector<int>& zipVector, bool onlyAverage);
void benchmarkSearchesMap(int treeSize, int numSearches, map<int, uscity>& standardMap, const vector<int>& zipVector, bool onlyAverage);



void benchmarkSearchesAVL(int treeSize, int numSearches, avl_map<int, uscity>& myAVL, const vector<int>& zipVector, bool onlyAverage) {
    int totalTime = 0;

    cout << "Time elapsed for " << numSearches << " searches: " << endl;

    //gets 100 samples, takes the average
    //this will mean that the average-time-taken value will be pretty accurate
    for (int i = 0; i < 100; ++i) {
        clock_t start = clock();
        searchRandomZipsAVL(myAVL, zipVector, numSearches);
        clock_t end = clock();

        double elapsed = double(end - start) / CLOCKS_PER_SEC; //convert to seconds
        int microseconds = elapsed * 1000000;// convert to microseconds
        if (!onlyAverage)
            cout << "Sample #" << i + 1 << ": " << microseconds << " microseconds" << endl;
        totalTime += microseconds;
    }

    cout << "Average time per trial: (" << treeSize << " nodes)\n" << (totalTime / 100) << " microseconds\n" << endl;
}

void benchmarkSearchesMap(int treeSize, int numSearches, map<int, uscity>& standardMap, const vector<int>& zipVector, bool onlyAverage) {
    int totalTime = 0;

    cout << "Time elapsed for " << numSearches << " searches: " << endl;

    
    //gets 100 samples, takes the average
    //this will mean that the average-time-taken value will be pretty accurate
    for (int i = 0; i < 100; ++i) {
        clock_t start = clock();
        searchRandomZipsMap(standardMap, zipVector, numSearches);
        clock_t end = clock();

        double elapsed = double(end - start) / CLOCKS_PER_SEC; //convert to seconds
        int microseconds = elapsed * 1000000;// convert to microseconds
        if (!onlyAverage)
            cout << "Sample #" << i + 1 << ": " << microseconds << " microseconds" << endl;
        totalTime += microseconds;
    }

    cout << "Average time per trial: (" << treeSize << " nodes)\n" << (totalTime / 100) << " microseconds\n" << endl;
}



int main()
{
    int treeSize = 10000; //how many Nodes the tree will have, how many lines of the csv will be read

    srand(time(NULL));


    //start for loop here
    //33782 because that's how many valid lines there are in uszips.csv
    //---> will actually do treeSize up to 32786 because that's 2^15, and 2^16 > 33782
    //increase by powers of 2 since theoretical time complexity will be log (base 2) of treeSize
    for(int treeSize = 1; treeSize < 33782; treeSize *= 2){ 

    ifstream file("uszips.csv");
    string line; 
    getline(file, line); //skips the header row
        
    //constructing the tree, map, and list
    avl_map<int, uscity> myAVL;
    map<int, uscity> standardMap;
    list<int> zipcodes;


        //loop until end of file or treeSize
        for (int count = 0; count < treeSize && getline(file, line); ++count) {
            vector<string> fields = parseCSVLine(line);

            //increase/decrease size to 17 fields
            while (fields.size() < 17) fields.push_back("");
            if (fields.size() > 17) fields.resize(17);

           //declare uscity object, set all its attributes
           uscity city;
            city.setZip(fields[0]);
            city.setLat(fields[1]);
            city.setLng(fields[2]);
            city.setCity(fields[3]);
            city.setStateId(fields[4]);
            city.setStateName(fields[5]);
            city.setZcta(fields[6]);
            city.setParentZcta(fields[7]);
            city.setPopulation(fields[8]);
            city.setDensity(fields[9]);
            city.setCountyFips(fields[10]);
            city.setCountyName(fields[11]);
            city.setCountyWeights(fields[12]);
            city.setCountyNamesAll(fields[13]);
            city.setImprecise(fields[14]);
            city.setMilitary(fields[15]);
            city.setTimezone(fields[16]);

            int zipCode = stoi(city.getZip());

            //inserting into tree, map, and list
            myAVL.insert(zipCode, city);
            standardMap[zipCode] = city;
            zipcodes.push_back(zipCode);
        }

        //gives a vector in order to use O(1) operations on to get the zip codes by accessing the index
        vector<int> zipVector(zipcodes.begin(), zipcodes.end());
    
        //decides whether to print the result for each trial(if false), or only the average of the trials(if true)
        bool onlyAverage = true;
    

        //searching through each list, printing the amount of time taken to do it
        //AVL tree
        cout << "AVL Tree:" << endl;
        benchmarkSearchesAVL(treeSize, 10000, myAVL, zipVector, onlyAverage);
    
        //Standard map
        cout << "Standard Map:" << endl;
        benchmarkSearchesMap(treeSize, 10000, standardMap, zipVector, onlyAverage);

        //close the file
        file.close();
    }
    
    return 0;
}





vector<string> parseCSVLine(const string& line) {
    vector<string> result;
    string field;
    bool inQuotes = false;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];

        if (c == '"') {
            //Handle escaped quotation marks
            if (inQuotes && i + 1 < line.size() && line[i + 1] == '"') {
                field += '"';
                ++i; //skip 2nd quote
            } else {
                inQuotes = !inQuotes; //quote mode on/off
            }
        }
        else if (c == ',' && !inQuotes) {
            //the end of this field
            result.push_back(field);
            field.clear();
        }
        else {
            field += c;
        }
    }

    //the last field
    result.push_back(field);

    return result;
}

//search the avl tree
void searchRandomZipsAVL(avl_map<int, uscity>& myAVL, const std::vector<int>& zipcodes, int numSearches)
{

    for (int i = 0; i < numSearches; ++i) {
        //pick a random valid index from zipcodes vector
        int randomIndex = rand() % zipcodes.size();

        //get the ZIP code stored at that index
        int randomZip = zipcodes[randomIndex];

        //search the tree
        myAVL.search(randomZip);
    }
}

//search the std map
void searchRandomZipsMap(map<int, uscity>& standardMap, const vector<int>& zipcodes, int numSearches)
{

    for (int i = 0; i < numSearches; ++i) {
        //pick a random valid index from zipcodes vector
        int randomIndex = rand() % zipcodes.size();

        //get the ZIP code stored at that index
        int randomZip = zipcodes[randomIndex];

        //search the map
        standardMap.find(randomZip);
    }
}

