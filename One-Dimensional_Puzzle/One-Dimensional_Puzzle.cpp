#include "Element.cpp"
#include <sstream>
#include <string>

int total_Elements(std::vector<int> input_array, int len){
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += input_array[i];
    }
    return sum;
}

void initialise(std::vector<int> input_array, int len){
    Sides left_ele1(false, true, false);
    Sides left_ele2(true, false, true);
    Sides left_ele3(true, false, true);
    Sides left_ele4(false, true, false);
    Sides right_ele1(false, true, false);
    Sides right_ele2(true, false, true);
    Sides right_ele3(false, true, false);
    Sides right_ele4(true, false, true);
    Element element1(1, left_ele1, right_ele1);
    Element element2(2, left_ele2, right_ele2);
    Element element3(3, left_ele3, right_ele3);
    Element element4(4, left_ele4, right_ele4);
    std::vector<int> e_ray = {};
    int total = total_Elements(input_array, len);
    Element element_array[total];
    Element element_Array[] = {element1, element2, element3, element4};
    int count = 0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < input_array[i]; j++){
            e_ray.push_back(i);
            element_array[count++] = element_Array[i];
        }    
    }
    //int length_ele = sizeof(e_ray)/sizeof(e_ray[0]);
    //int length_element = sizeof(element_array)/sizeof(element_array[0]);
    //Element::displayLineAnimation(element_array, length_element);
    //Element::displayLine(element_array, length_element);
    //std::cout << Element::polarisationChecker(element_array, length_element) << std::endl; 
    Element::combinationChecker(e_ray, total, element_Array);
    std::cout << std::endl;
}

int main() {
    int total;
    std::cin >> total;
    std::cin.ignore();
    std::vector<std::vector<int>> inputs;
    for(int i = 0; i < total; i++){
        std::string line;
        std::getline(std::cin, line); 
        std::istringstream iss(line);
        std::vector<int> intArray;
        int num;
        while (iss >> num) {
            intArray.push_back(num);
        }
        inputs.push_back(intArray);
    }
    for(std::vector<int> vec : inputs){
        initialise(vec, vec.size());
    }
    return 0;
}
