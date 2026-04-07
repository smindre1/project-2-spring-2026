#pragma once
#include <chrono>
#include <vector>
#include <iostream>
#include "Inventory.hpp"
#include "ItemGenerator.hpp"
#include "Compare.hpp"

template <typename Comparator, typename Container>
double timeContains(int n) {
    Inventory<Comparator, Container> inv;

    ItemGenerator gen(42);

    // 1. Insert n items
    for (int i = 0; i < n; i++) {
        inv.pickup(gen.randomItem());
    }

    // 2. Create contained vector (100 names)
    std::vector<std::string> contained;
    for (int i = 0; i < 100; i++) {
        contained.push_back(gen.randomUsedName());
    }

    // 3. Create missing vector (100 names NOT in inventory)
    std::vector<std::string> missing;
    for (int i = 0; i < 100; i++) {
        missing.push_back(gen.randomItem().name_);
    }

    // 4. Time contains()
    double total_time = 0;

    for (const auto& name : contained) {
        auto start = std::chrono::high_resolution_clock::now();

        inv.contains(name);

        auto end = std::chrono::high_resolution_clock::now();

        total_time += std::chrono::duration<double, std::milli>(end - start).count();
    }

    for (const auto& name : missing) {
        auto start = std::chrono::high_resolution_clock::now();

        inv.contains(name);

        auto end = std::chrono::high_resolution_clock::now();

        total_time += std::chrono::duration<double, std::milli>(end - start).count();
    }

    return total_time / 200.0;
}

template <typename Comparator, typename Container>
double timeQueryName(int n) {
    Inventory<Comparator, Container> inv;
    ItemGenerator gen(42);

    for (int i = 0; i < n; i++) {
        inv.pickup(gen.randomItem());
    }

    double total_time = 0;

    for (int i = 0; i < 10; i++) {
        std::string name1 = gen.randomUsedName();
        std::string name2 = gen.randomUsedName();

        Item start(name1, 0, ItemType::NONE);
        Item end(name2, 0, ItemType::NONE);

        if (Comparator::lessThan(end, start)) {
            std::swap(start, end);
        }

        auto start_t = std::chrono::high_resolution_clock::now();

        inv.query(start, end);

        auto end_t = std::chrono::high_resolution_clock::now();

        total_time += std::chrono::duration<double, std::milli>(end_t - start_t).count();
    }

    return total_time / 10.0;
}

template <typename Comparator, typename Container>
double timeQueryWeight(int n) {
    Inventory<Comparator, Container> inv;
    ItemGenerator gen(42);

    for (int i = 0; i < n; i++) {
        inv.pickup(gen.randomItem());
    }

    double total_time = 0;

    for (int i = 0; i < 10; i++) {
        float w = gen.randomFloat(ItemGenerator::MIN_WEIGHT, ItemGenerator::MAX_WEIGHT);

        Item start("a", w, ItemType::NONE);
        Item end("b", w + 0.1, ItemType::NONE);

        auto start_t = std::chrono::high_resolution_clock::now();

        inv.query(start, end);

        auto end_t = std::chrono::high_resolution_clock::now();

        total_time += std::chrono::duration<double, std::milli>(end_t - start_t).count();
    }

    return total_time / 10.0;
}