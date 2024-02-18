#include "Element.cpp"
#include <set>

int lenght_of_array(int *input_array){
    return sizeof(input_array)/sizeof(input_array[0]);
}

int total_Elements(int* input_array, int len){
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += *(input_array + i);
    }
    return sum;
}

void initialise(int *input_array, int len){
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
    //Element element_array[total_Elements(input_array, len)];
    Element element_Array[] = {element1, element2, element3, element4};
    //int count = 0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < input_array[i]; j++){
            e_ray.push_back(i);
            //element_array[count++] = element_Array[i];
        }    
    }
    int length = sizeof(e_ray)/sizeof(e_ray[0]);
    //Element::displayLineAnimation(element_array, length);
    //Element::displayLine(element_array, length);
    //std::cout << Element::polarisationChecker(element_array, length) << std::endl; 
    Element::combinationChecker(e_ray, length, element_Array);
    std::cout << std::endl;
}

int main() {
    int input_array[] = {1, 1, 1, 1};
    int len = sizeof(input_array)/sizeof(input_array[0]);
    initialise(input_array, len);
    return 0;
}