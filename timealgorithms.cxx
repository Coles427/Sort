#include<iostream>
#include <fstream>
#include <ctime>
#include "json.hpp"
#include "insertionsort.h"
#include "mergesort.h"


int main(int argc, char** argv) {
    clock_t t;
    std::vector <std::vector <int>> samples;
    std::vector <std::string> sampleNames;

    //Reads in JSON file to a nlohmann::json object
    std::ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObj;
    if(file.is_open()){
        file>> jsonObj;
        for (auto itr = jsonObj.begin(); itr != jsonObj.end(); ++itr) {//Read the JSON obj to a vector
            sampleNames.push_back(itr.key());
            if(itr.key() == "metadata"){break;}//skips metadata
            std::vector <int> sample;
            for(auto sItr = jsonObj[itr.key()].begin(); sItr != jsonObj[itr.key()].end(); ++sItr){
                sample.push_back(sItr.value());
            }
            samples.push_back(sample);
        }
    }
    file.close();

    std::vector <int> sort;

    for (unsigned int i = 0; i < samples.size() ; ++i) {
        int memAccess = 0;
        int comp = 0;
        sort = samples[i];
        //Values for Insertion sort
        std::cout<<sampleNames[i]<<",";
        t = clock();
        InsertionSort(&sort, memAccess, comp);
        t = clock() - t;
        std::cout<<std::fixed<<std::setprecision(4)<<(((float)t)/CLOCKS_PER_SEC) * 100000 <<","<<std::setw(2)<< comp<<"," <<std::setw(3)<< memAccess<<",";

        //Values for Merge Sort
        memAccess = 0;
        comp = 0;
        sort = samples[i];
        t = clock();
        MergeSort(&sort, memAccess, comp);
        t = clock() - t;
        std::cout<<std::fixed<<std::setprecision(4)<<(((float)t)/CLOCKS_PER_SEC) * 100000 <<","<<std::setw(2)<< comp<<"," <<std::setw(3)<< memAccess<<std::endl;
    }


}