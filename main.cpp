#include "Compare.hpp"
#include "HashInventory.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "ItemAVL.hpp"
#include "TreeInventory.hpp"
#include "ItemGenerator.hpp"
#include <chrono>
#include <iostream>
#include <list>


std::vector<int> n = { 1000 , 2000 , 4000 , 8000 };

template <class Comparator, class Container>
int timeCheck(Inventory<Comparator, Container> inv )
{
    ItemGenerator item(42);
    Inventory<CompareItemName> vectInv;
    // Inventory<CompareItemName, std::unordered_set<Item>> unorInv;
    // Inventory<CompareItemName, Tree> TreeInv;
    // Inventory<CompareItemName, std::list> compInv;

    
    
    for(auto ele : n) {
        for(int i = 0; i < ele; i++) {
            vectInv.pickup(item.randomItem());
        }
        std::vector<Item> contained;
        std::vector<Item> missing;
        
        for(int i = 0; i < 100; i++){
            contained.push_back(item.randomUsedName()); 
            missing.push_back(item.randomUsedName()); 
        }
        
        std::chrono::duration<double, std::milli> totalC;
        std::chrono::duration<double, std::milli> totalM;

        for(auto it = contained.begin(); it != contained.end(); it++) {
            const auto t1 = std::chrono::high_resolution_clock::now();
            vectInv.contains((*it).name_);
            const auto t2 = std::chrono::high_resolution_clock::now();
            const std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
            totalC = totalC + fp_ms;
        }
        for(auto it = missing.begin(); it != missing.end(); it++) {
            const auto t1 = std::chrono::high_resolution_clock::now();
            vectInv.contains((*it).name_);
            const auto t2 = std::chrono::high_resolution_clock::now();
            const std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
            totalM = totalM + fp_ms;
        }

        std::cout << "n: " << ele << std::endl;
        std::cout << "Contained Avg RT: " << totalC.count()/200 << std::endl;
        std::cout << "Missing Avg RT: " << totalM.count()/200 << std::endl;
        //totalC.count();
    }
    return 0;
}

int main()
{
    Inventory<CompareItemName> vectInv;
    Inventory<CompareItemName, std::unordered_set<Item>> unorInv;
    Inventory<CompareItemName, Tree> treeInv;
    Inventory<CompareItemName, std::list<Item>> compInv;

    timeCheck(vectInv);
    timeCheck(unorInv);
    timeCheck(treeInv);
    timeCheck(compInv);


    return 0;
}