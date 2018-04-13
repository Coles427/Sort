#include <iostream>
#include <fstream>
#include "json.hpp"

int main(int argc, char** argv) {
    nlohmann::json jsonObj1;
    nlohmann::json jsonObj2;

    //std::string file_name = argv[1];

    std::ifstream file;// Opens file stream and reads a JSON into a JSON object
    file.open(argv[1]);
    if (file.is_open()){
        file >> jsonObj1;
    }
    file.close();
    file.open(argv[2]);
    if (file.is_open()){
        file >> jsonObj2;
    }
    file.close();

    nlohmann::json inconsistant;
    std::vector<std::vector<int>> mismatches;

    for(auto json1Itr = jsonObj1.begin(), json2Itr = jsonObj2.begin() ;
            json1Itr != jsonObj1.end() && json2Itr!= jsonObj2.end(); ++json1Itr, ++json2Itr){

        if(json1Itr.key() == "metadata"){break;}
        nlohmann::json json1sample = json1Itr.value();
        nlohmann::json json2sample = json2Itr.value();



        for(auto json1SItr = json1sample.begin(), json2SItr = json2sample.begin();
            json1SItr != json1sample.end() && json2SItr != json2sample.end(); ++json1SItr, ++json2SItr){
            if(json1SItr.value() != json2SItr.value()){
                std::vector<int> mismatchPair;
                mismatchPair.push_back(json1SItr.value());
                mismatchPair.push_back(json2SItr.value());
                mismatches.push_back(mismatchPair);
            }

        }

        if (!mismatches.empty()) {

            inconsistant[json2Itr.key()][argv[2]] = json2sample;
            for (unsigned int i = 0; i< mismatches.size() ; ++i) {
                inconsistant[json1Itr.key()]["Mismatches"][std::to_string(i + 1)] = mismatches[i];
            }
            inconsistant[json1Itr.key()][argv[1]] = json1sample;
            mismatches.clear();
        }

    }
    inconsistant["metadata"]["File1"]["arraySize"] = jsonObj1["metadata"]["arraySize"];
    inconsistant["metadata"]["File1"]["numSamples"] = jsonObj1["metadata"]["numSamples"];
    inconsistant["metadata"]["File1"]["name"] = argv[1];
    inconsistant["metadata"]["File2"]["arraySize"] = jsonObj2["metadata"]["arraySize"];
    inconsistant["metadata"]["File2"]["numSamples"] = jsonObj2["metadata"]["numSamples"];
    inconsistant["metadata"]["File2"]["name"] = argv[2];
    std::cout<<inconsistant.dump(2);
}