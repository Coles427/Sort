#include <iostream>
#include <fstream>
#include "json.hpp"

int main(int argc, char** argv) {
    nlohmann::json jsonObj;

    //std::string file_name = argv[1];

    std::ifstream file;// Opens file stream and reads a JSON into a JSON object
    file.open(argv[1]);
    if (file){
        file >> jsonObj;
    }
    file.close();

    nlohmann::json inversions;
    int numInversions = 0;

    for(auto itr = jsonObj.begin(); itr != jsonObj.end(); ++itr){
        nlohmann::json sample = jsonObj[itr.key()];
        int temp = sample.begin().value();
        int i = -1;
        for(auto itrs = sample.begin(); itrs!= sample.end(); ++itrs){
            if(itr.key() != "metadata"){
                if(itrs.value() < temp){

                    //inversions[itr.key()] = "ConsecutiveInversions";
                    inversions[itr.key()]["ConsecutiveInversions"][std::to_string(i)] = {temp, itrs.value()};
                    numInversions ++;
                }
                temp = itrs.value();
            }
            i++;
        }
        if(numInversions > 0){
            inversions[itr.key()]["sample"] = sample;
        }
        numInversions = 0;
    }

    inversions["metadata"]["arraySize"] = jsonObj["metadata"]["arraySize"];
    inversions["metadata"]["file"] = argv[1]; //file name from arguments
    inversions["metadata"]["numSamples"] = jsonObj.size() - 1; //size of JSON input - metadata
    inversions["metadata"]["samplesWithInversions"] = inversions.size() - 1;//size of inversion JSON - metadata

            std::cout << inversions.dump(2);



}