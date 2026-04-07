# CS335 Assignment 2
By Shane Mindreau - 3/24/2026

## Compare() weight function runtime (in milliseconds)

n = items in inventory

| n          |    1000      |    2000      |    4000      |    8000      |
|:-----------|:------------:|:------------:|:------------:|-------------:|
| **Vector** | 2.026e-05ms  | 1.994e-05ms  | 1.9795e-05ms | 1.978e-05ms  |
| **List**   | 1.994e-05ms  | 1.947e-05ms  | 1.9675e-05ms | 1.9545e-05ms |
| **Hash**   | 6.5165e-05ms | 7.0256e-05ms | 7.9665e-05ms | 8.611e-05ms  |
| **Tree**   | 0.00210107ms | 0.00592106ms | 0.0151078ms  | 0.0426267ms  |

## Query() weight and name function runtimes (in milliseconds)

n = items in inventory

| n                   |    1000      |    2000      |    4000      |    8000      |
|:--------------------|:------------:|:------------:|:------------:|-------------:|
| **Vector** (weight) | 0.0035262ms  | 0.0075089ms  | 0.0178538ms  | 0.0291832ms  |
| **Vector** (name)   | 0.0340721ms  | 0.0660854ms  | 0.149608ms   | 0.484903ms   |
| **List** (weight)   | 0.0034733ms  | 0.0012906ms  | 0.01646ms    | 0.0303511ms  |
| **List** (name)     | 0.0325011ms  | 0.0692905ms  | 0.140004ms   | 0.445818ms   |
| **Hash** (weight)   | 0.0068551ms  | 0.0159487ms  | 0.0398302ms  | 0.0857484ms  |
| **Hash** (name)     | 0.0384722ms  | 0.0712527ms  | 0.167142ms   | 0.506336ms   |
| **Tree** (weight)   | 0.0001642ms  | 0.0002508ms  | 0.0001975ms | 0.0002556ms  |
| **Tree** (name)     | 0.0259243ms  | 0.0581655ms  | 0.125682ms   | 0.499722ms   |

### Report of Findings

Based on the runtime data on the contain() and query() functions from testing, it can be detemined that there is a linear trend of time increasing as the number of items to search through grows. This can easily be explained by the fact that the functions would simply need to parse through larger datasets potentially finding or not finding their target items after a longer process. 

There are some descrepencies in the data however, where on a few occassions the time of a larger n would be slightly quicker than the smaller n inventory test. This is likely due to random variables like computer background tasks and computer specs occupying a portion of the ram that would have been otherwise allocated to running the program (causing the slight delay in speed).

I would opt for a hash-based inventory if I wanted to prioritize lookup speed in exchange for a lack of order. I would opt for a tree based inventory if I required sorted data, range queries, or predictable O(log n) operations.

## Referenced

https://en.cppreference.com/w/cpp/chrono/duration/duration_cast

## Running the assignment

You will use `Makefile` to compile on the terminal. To do this type in the terminal:

```bash
make clean
make all
```

To delete executables and object files, type:

```bash
make clean
```

To run, type:

```bash
./main
```


## Files of Interest
1. Item.cpp
2. Item.hpp
3. Compare.cpp
4. Compare.hpp
5. HashInventory.cpp
6. HashInventory.hpp
7. ItemAVL.cpp
8. ItemAVL.hpp
9. TreeInventory.cpp
10. TreeInventory.hpp