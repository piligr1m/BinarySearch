//
//  main.cpp
//  2.2
//
//  Created by Stanislav Martynov on 28.12.2020.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

 int binary_search(int val, int* array, int begin, int end)
{
    int index;
    int midpoint;
    if (begin <= end){
     midpoint = (begin + end)/2;
    if (val == array[midpoint]){
        index = midpoint;
        while(index > 0){
            index--;
            if(array[index] != array[index+1]) break;
        }
        if (array[index] == array[midpoint]) return index;
        else return index+1;
    }
    if (end == begin) return -1;
    if (array[midpoint] > val) return binary_search(val, array, begin, midpoint - 1);
    else return binary_search(val, array, (midpoint + 1), end);
    }
    return -1;
}

int main(int argc, char* argv[])
{
    std::vector<int> vec1;
    std::string line, limne;
    std::string comm;
    std::stringstream ss;
    int current = 0;
    int sign = 1;
    int k = 0;
    int j = 0;
    int val;
    int res;
    bool flag = false;
    std::getline(std::cin, line);
    vec1.resize(line.size());
    for (int i = 0; i < line.size(); i++){
        if(std::isdigit(line[i]))
        {
            current = current*10 + (line[i]-48);
            flag = true;
        }
        else if (line[i] == '-'){
            if (current == 0) sign = -1;
        }
        if ((!std::isdigit(line[i]) && (current != 0 || flag)) || line[i+1] == '\0'){
            k++;
            vec1[j] = current*sign;
            j++;
            current = 0;
            sign = 1;
            flag = false;
         }
    }
    int der[k];
    for (int i =0; i < k; i++) {
        der[i] = vec1[i];
    }
    while(std::getline(std::cin, limne)){
        if (limne.empty()) break;
    ss << limne;
    ss >> comm;
    ss >> val;
    res = binary_search(val, der, 0,  k-1);
    std::cout << res << std::endl;
        ss.clear();
    }
}
