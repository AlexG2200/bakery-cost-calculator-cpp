// Author: Written by Alex Guzman
// Course: CSCI 2170
// Due Date: 04 04, 2026
// Description: This program reads bakery recipe and product data from two input files, calculates the cost of each bakery product based on ingredient amounts and prices, displays a formatted cost table, and identifies the most expensive product.
// Input: recipes.dat - contains number of ingredients/products, ingredient amounts per product, and ingredient unit prices. products.dat - contains the name of each bakery product.
// Output: A formatted "Cost of Bakery Products Table" displaying each product's ingredient amounts and total price

/* A.I. Disclaimer: All work for this assignment was completed by myself and entirely without the use 
of artificial intelligence tools such as ChatGPT, MS Copilot, other LLMs, etc. */

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;


// const max values
const int MaxProducts = 15;
const int MaxIngredients = 20;
// function prototypes
void PrintTable(int amount[][15], string ProductNames[], double ProductPrices[], int ingredients, int products);
void readrecipes(ifstream &file, int amount[][15], double IngredientPrices [], int &ingredients ,int &products);
void ReadProductNames(ifstream &file, string ProductNames[], int &products);
void calculateProductPrices(int amount [][15], double IngredientPrices [], double ProductPrices[], int ingredients ,int products);
int Mostexpensive(double ProductPrices[], int products);

int main(){
    ifstream file, file2;
    string filename, filename2;

    //declaring vars and array
    int amount [MaxIngredients][MaxProducts] = {};
    double IngredientPrices[MaxIngredients];
    string ProductNames[MaxProducts];
    double ProductPrices[MaxProducts];
    int ingredients, products;
    int mostexp;

    // begins the file logic
    cout << "Enter the recipe file name: ";
    cin >> filename;
    file.open(filename);

    while(!file){
        cout << "file open error: \n";
        cout << "Enter the recipe file name: ";
        cin >> filename;
        file.open(filename);
        continue;
    }
    cout << "File Open Successfully.\n";

    cout << "Enter the product file name: ";
    cin >> filename2;
    file2.open(filename2);
    
    while(!file2){
        cout << "file open error: \n";
        cout << "Enter the product file name: ";
        cin >> filename2; 
        file2.open(filename2);
    }
    cout << "File Open Successfully.\n";

    // calling functions
    readrecipes(file,amount, IngredientPrices, ingredients ,products);
    
    if(ingredients == 0 || products == 0){
        cout << "No data found in file.\n";
        file.close();
        file2.close();
        return 0;
    }
    ReadProductNames(file2, ProductNames,products);
    calculateProductPrices(amount, IngredientPrices, ProductPrices, ingredients , products);
    PrintTable(amount, ProductNames, ProductPrices, ingredients, products);
    mostexp = Mostexpensive(ProductPrices, products);
    
    cout << endl;
    cout << "Product " << mostexp + 1 << ": " << ProductNames[mostexp] << " Is the most expensive product.\n";

    file.close();
    file2.close();

    return 0;
}


// This function reads recipe data from file into 2D amount array and ingredient prices array.
// PreCondition/Input: open recipe file stream, empty arrays, uninitialized ingredients/products
// PostCondition/Output: amount[][] and IngredientPrices[] populated, ingredients and products set
void readrecipes(ifstream &file, int amount[][15], double IngredientPrices [], int &ingredients ,int &products){

   if(!(file >> products) || !(file >> ingredients)){
        products = 0;
        ingredients = 0;
        return;
    }
    
    for (int i =  0; i < ingredients; i++){
        for (int j = 0; j < products; j++){
            file >> amount[i][j];
        }

        file >> IngredientPrices[i];
    }
}

//This function reads product names from file into ProductNames array.
// PreCondition/Input: open product file stream, known number of products
// PostCondition/Output: ProductNames[] populated with all product names
void ReadProductNames(ifstream &file, string ProductNames[], int &products){
    for(int i = 0; i < products; i++){
        getline(file, ProductNames[i]);
    }
}

// This function calculates total price for each product using ingredient amounts and prices.
// PreCondition/Input: populated amount[][] and IngredientPrices[], known ingredients/products
// PostCondition/Output: ProductPrices[] populated with calculated prices
void calculateProductPrices(int amount [][15], double IngredientPrices [], double ProductPrices[], int ingredients ,int products){
    for (int j = 0; j < products; j++){
        ProductPrices[j] = 0;
        for (int i = 0; i < ingredients; i++){
            ProductPrices[j] = ProductPrices[j] + (amount[i][j] * IngredientPrices[i]);
        }
    }
}
// This function finds the most expensive product and returns it.
// PreCondition/Input: populated ProductPrices[], known number of products
// PostCondition/Output: returns index of highest priced product
int Mostexpensive(double ProductPrices[], int products){
    int Max = 0;

    for(int j = 1; j < products; j++){
        if(ProductPrices[j] > ProductPrices[Max]){
            Max = j;
        }
    }
    return Max;
}
// This function prints the fornmatted bakery table.
// PreCondition/Input: all arrays populated, known ingredients and products count
// PostCondition/Output: formatted table displayed with prices to 2 decimal places
void PrintTable(int amount[][15], string ProductNames[], double ProductPrices[], int ingredients, int products){
    cout << endl;
    cout << "Cost of Bakery Products Table\n";
    for (int i = 0; i < 80; i++){
        cout << '*';
    }
    cout << endl;
    cout << left << setw(15) << "Product";
    for (int j = 0; j < ingredients; j++){
        cout << "Ing" << left << setw(5) << (j + 1);
}
    cout << setw(10) << "Price" << endl;
    for (int i = 0; i < 80; i++){
        cout << '-';
    }
    cout << endl;
    for (int k = 0; k < products; k++){
        cout << left << setw(2) << (k + 1) << setw(14) << ProductNames[k]; // changed from 3 to 2
        for (int i = 0; i < ingredients; i++){
            cout << setw(8) << amount[i][k]; //made change here 6 to 8
        }
        cout << "$ " << fixed << setprecision(2) << ProductPrices[k] << endl;
    }
    for (int i = 0; i < 80; i++){
        cout << '-';
    } 
    cout << endl;
}
