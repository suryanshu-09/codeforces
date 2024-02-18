#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <array>
#include <vector>
#include "combinations.h"

class Sides {
public:
    bool top;
    bool middle;
    bool bottom;
    Sides(){}
    Sides(bool t, bool m, bool b) :
        top(t), middle(m), bottom(b) {}
    int polarisation(){
        if(top==0&&middle==1&&bottom==0)
            return 1;
        else 
            return -1;
    }
};
class Element {
public:
    int elementId;
    Sides left;
    Sides right;
    static void combinationChecker(std::vector<int> arr, int len, Element element_Array[]){
        std::vector<std::vector<int>> combinations = getAllCombinations(arr);
        for(auto& combination : combinations){
            int i = 0;
            Element ele_ray[len];
            for(int num : combination){
               ele_ray[i++] = element_Array[num];
            }
            if(polarisationChecker){
                displayLineAnimation(ele_ray, len);
            }
        }
    }
    std::array<int, 2> polarisationFunction(){
        return {this->left.polarisation(), this->right.polarisation()};
    }
    Element(){}
    Element(int elementId, const Sides& left, const Sides& right) : elementId(elementId), left(left), right(right) {}
    static bool polarisationChecker(Element lens[], int len){
        if(len==1){
            return true;
        }else{
            if((lens[0].polarisationFunction())[1] + (lens[1].polarisationFunction())[0] != 0)
                return false;
            else{
                Element sliced[len-1];
                std::copy(lens+1, lens + len, sliced);
                return polarisationChecker(sliced, len - 1);
            }
        }
    }

    static void displayLineAnimation(Element ele[], int len){
        // Display initial content
        std::cout << "Animation starting..." << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
 
        // Clear the screen
        std::cout << "\033[2J\033[H" << std::flush;
        // Display new content
        for(int i = 0; i < len; i++){
            Element sliced[i+1];
            std::copy(ele, ele + i + 1, sliced);
            displayLine(sliced, i + 1);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // Clear the screen again
            std::cout << "\033[2J\033[H" << std::flush;
        } 
        // Display final content
        displayLine(ele, len);
    }
    static void displayLine(Element ele[], int len){
        //top
        for(int i = 0; i < len; i++){
            ele[i].displayTop();
        }
        std::cout << std::endl;
 
        //top-middle transition 1
        for(int i = 0; i < len; i++){
            ele[i].displayTopMid1();
        }
        std::cout << std::endl;
  
        //top-middle transition 2
        for(int i = 0; i < len; i++){
            ele[i].displayTopMid2();
        }
        std::cout << std::endl;
  
        //middle
        for(int i = 0; i < len; i++){
            ele[i].displayMiddle();
        }
        std::cout << std::endl;
        
        //bottom-middle transition 1
        for(int i = 0; i < len; i++){
            ele[i].displayBottomMid1();
        }
        std::cout << std::endl;
  
        //bottom-middle transition 2
        for(int i = 0; i < len; i++){
            ele[i].displayBottomMid2();
        }
        std::cout << std::endl;
  
        //bottom
        for(int i = 0; i < len; i++){
            ele[i].displayBottom();
        }
        std::cout << std::endl;
    }
    static void display(Element& ele){
        //top
        ele.displayTop();
        std::cout << std::endl;
 
        //top-middle transition 1
        ele.displayTopMid1();
        std::cout << std::endl;
  
        //top-middle transition 2
        ele.displayTopMid2();
        std::cout << std::endl;
  
        //middle
        ele.displayMiddle();
        std::cout << std::endl;
        
        //bottom-middle transition 1
        ele.displayBottomMid1();
        std::cout << std::endl;
  
        //bottom-middle transition 2
        ele.displayBottomMid2();
        std::cout << std::endl;
  
        //bottom
        ele.displayBottom();
        std::cout << std::endl;
    }
    void displayTop(){
        //top
        if(this->left.top==false){
            std::cout << "   ";
        }else{std::cout << " __";}
  
        std::cout << "__";
        
        if(this->right.top==false){
            std::cout << "   ";
        }else{std::cout << "__ ";}
    }
    void displayTopMid1(){
        //top-middle transition 1
        if(this->left.top==false){
            std::cout << "  |";
        }else{std::cout << "|  ";}
        
        std::cout << "  ";
        
        if(this->right.top==false){
            std::cout << "|  ";
        }else{std::cout << "  |";}
    }
    void displayTopMid2(){
        //top-middle transition 2
        if(this->left.middle==false){
            std::cout << "   -";
        }else{std::cout << " -- ";}
        
        
        if(this->right.middle==false){
            std::cout << "-   ";
        }else{std::cout << " -- ";}
    }
    void displayMiddle(){
        //middle
        if(this->left.middle==false){
            std::cout << "  |";
        }else{std::cout << "|  ";}
  
        std::cout << "  ";
        
        if(this->right.middle==false){
            std::cout << "|  ";
        }else{std::cout << "  |";}
    }
    void displayBottomMid1(){
        //bottom-middle transition 1
        if(this->left.middle==false){
            std::cout << "   -";
        }else{std::cout << " -- ";}
        
        
        if(this->right.middle==false){
            std::cout << "-   ";
        }else{std::cout << " -- ";}
    }
    void displayBottomMid2(){
        //bottom-middle transition 2
        if(this->left.bottom==false){
            std::cout << "  |";
        }else{std::cout << "|  ";}
        
        std::cout << "  ";
        
        if(this->right.bottom==false){
            std::cout << "|  ";
        }else{std::cout << "  |";}
    }
    void displayBottom(){
        //bottom
        if(this->left.bottom==false){
            std::cout << "   ";
        }else{std::cout << " --";}
  
        std::cout << "--";
        
        if(this->right.bottom==false){
            std::cout << "   ";
        }else{std::cout << "-- ";}
    }
};
