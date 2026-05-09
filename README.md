# Bakery Cost Calculator

This is a small C++ program I made for calculating the cost of different bakery products based on the ingredients they use.

The program reads recipe data from one file and product names from another file. It then calculates the total cost to make each product and prints a formatted table showing the ingredient amounts and final price. At the end, it also shows which product is the most expensive to make.

## What it does

- Reads ingredient and price data from a recipe file
- Reads product names from a separate file
- Calculates the cost of each bakery item
- Displays the results in a table
- Finds the most expensive product

## Files

```text
src/bakery_cost_calculator.cpp
data/recipes.dat
data/products.dat

Enter the recipe file name: data/recipes.dat
File Open Successfully.
Enter the product file name: data/products.dat
File Open Successfully.

Cost of Bakery Products Table
**************************************************************************
Product        Ing1  Ing2  Ing3  Ing4  Ing5  Ing6    Price
--------------------------------------------------------------------------
1 Donut          10    20    50    25     0     0  $ 718.90
2 Bagel          10     5    10    25     0     0  $ 225.15
3 White Bread    11     6    12    30     0     0  $ 265.04
4 Kaiser Roll    11     6    12    30     0     0  $ 265.04
5 King Cake       5    50    40    90     0     1  $1085.45
6 Apple Pie       8    15    30    40    20     0  $ 909.87
7 Cherry Wafer   12    27    25    10     0    15  $1649.68
--------------------------------------------------------------------------

Product 7: Cherry Wafer is the most expensive product.
