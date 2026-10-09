#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "../include/product.h"

#define SIZE_NAME 50

struct Product {
    char *name;
    float price, discountedPercent;
    unsigned int stock, sales;
};

/**
 * @brief Realloc the momory to confort thee name size;
 * 
 * @param name Name of product;
 * @param sizeName Size of the name the product;
 */
static nameReallocation(char *name, unsigned int sizeName) {
    name = (char*)realloc(name, (sizeName + 1) * sizeof(char));;

    if (name == NULL) {
        printf("Erro! Realocacao de memoria de nome do produto mal-sucedida.\n");
        exit(1);
    }
}


Product *productConstruct() {
    Product *product = NULL;
    
    product = (Product*)malloc(sizeof(Product));

    if (product == NULL) {
        printf("Erro! Alocacao de memoria de produto mal-sucedida.\n");
        exit(1);
    }

    product->name = NULL;

    product->name = (char*)calloc(SIZE_NAME, sizeof(char));

    if (product->name == NULL) {
        printf("Erro! Alocacao de memoria para o nome do produto mal-sucedida.\n");
        destroyProduct(product);
        exit(1);
    }

    product->sales = 0;
    product->stock = 0;
    product->price = 0;
    product->discountedPercent = 0;

    return product;
}

const char *getProductName(Product *product) {
    return product->name;
}

float getProductPrice(Product *product) {
    return product->price;
}

float getProductDiscount(Product *product)   {
    return product->discountedPercent;
}

unsigned int getQuantityProduct(Product *product) {
    return product->stock;
}

unsigned getQuantitySalesProduct(Product *product) {
    return product->sales;
}

void *setProductName(Product *product, char *name) {
    unsigned int sizeName;

    sizeName = strlen(name);

    if (sizeName >= SIZE_NAME)
        nameReallocation(product->name, sizeName);
    
    strcpy(product->name, name);
}

void setProductPrice(Product *product, float price) {
    product->price = price;
}

void setProductDiscount(Product *product, float percent) {
    product->discountedPercent = percent;
}


void buyProduct(Product *product, unsigned int quantity) {
    product->stock -= quantity;
}

void sellProduct(Product *product, unsigned int quantity) {
    product->sales += quantity;
}

float getDiscountedPriceProduct(Product *product) {
    return product->price - (product->price * product->discountedPercent);
}

short int compareNameProduct(Product *product1, Product *product2) {
    short int comparation;

    comparation = strcmp(product1->name, product2->name);

    if (comparation < 0)
        return -1;
    else if (comparation == 0)
        return 0;
    else
        return 1;
}

short int comparePriceProduct(Product *product1, Product *product2) {
    if (product1->price < product2->price)
        return -1;
    else if (product1->price == product2->price)
        return 0;
    else
        return 1;
}

short int compareSalesProduct(Product *product1, Product *product2) {
    if (product1->sales < product2->sales)
        return -1;
    else if (product1->sales == product2->sales)
        return 0;
    else
        return 1;
}

void printProduct(Product *product) {
    printf("-> Produto: %s\n", product->name);
    printf("\t* Preco: %.2f\n", product->price);
    printf("\t* Desconto (%%): %.2f%%\n", product->discountedPercent);
    printf("\t* Quantidade em estoque: %u\n", product->stock);
    printf("\t* Vendas: %u\n", product->sales);
}

void destroyProduct(Product *product) {
    if (product != NULL) {
        if (product->name != NULL) {
            free(product->name);

            product->name = NULL;
        }
        free(product);
        product = NULL;
    }
}