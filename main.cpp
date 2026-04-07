#include "Compare.hpp"
#include "HashInventory.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "ItemAVL.hpp"
#include "TreeInventory.hpp"
#include "timing.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

int main() {
    std::vector<int> sizes = {1000, 2000, 4000, 8000};

    for (int n : sizes) {
        std::cout << "n = " << n << "\n";

        std::cout << "Vector: "
                  << timeContains<CompareItemName, std::vector<Item>>(n) << "\n";

        std::cout << "List: "
                  << timeContains<CompareItemName, std::list<Item>>(n) << "\n";

        std::cout << "Hash: "
                  << timeContains<CompareItemName, std::unordered_set<Item>>(n) << "\n";

        std::cout << "Tree: "
                  << timeContains<CompareItemName, Tree>(n) << "\n";
    }

    std::cout << std::endl;

    for (int n : sizes) {
        std::cout << "n = " << n << "\n";

        std::cout << "\nVector Weight: "
                    << timeQueryWeight<CompareItemName, std::vector<Item>>(n) << "\n";
        std::cout << "Vector Name: "
                  << timeQueryName<CompareItemName, std::vector<Item>>(n) << "\n";
        std::cout << "\nList Weight: "
                    << timeQueryWeight<CompareItemName, std::list<Item>>(n) << "\n";
        std::cout << "List Name: "
                  << timeQueryName<CompareItemName, std::list<Item>>(n) << "\n";
        std::cout << "\nHash Weight: "
                    << timeQueryWeight<CompareItemName, std::unordered_set<Item>>(n) << "\n";
        std::cout << "Hash Name: "
                  << timeQueryName<CompareItemName, std::unordered_set<Item>>(n) << "\n";
        std::cout << "\nTree Weight: "
                    << timeQueryWeight<CompareItemName, Tree>(n) << "\n";
        std::cout << "Tree Name: "
                  << timeQueryName<CompareItemName, Tree>(n) << "\n";
    }


    return 0;
}


/*
int main()
{
    Item test1("Demonic Dagger");
    Item test2("mythic mirror");
    Item test3("Flaming sword");

    Inventory<CompareItemName, Tree> curInvt{};

    curInvt.pickup(test1);
    curInvt.pickup(test2);
    curInvt.pickup(test3);

    std::unordered_set<Item> ans = curInvt.query(test1, test1);
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        std::cout << it->name_;
    }

    Inventory<CompareItemName, std::unordered_set<Item>> testHashInv{};
    testHashInv.pickup(test1);
    testHashInv.pickup(test2);
    testHashInv.pickup(test3);

    std::unordered_set<Item> ans2 = testHashInv.query(test1, test1);
    for (auto it = ans2.begin(); it != ans2.end(); ++it) {
        std::cout << it->name_;
    }

    return 0;
}
    */

    //Timing
