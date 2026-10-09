#ifndef _PRODUCT_H_
#define _PRODUCT_H_

typedef struct Product Product;

/**
 * @brief Create (dynamically allocates memory for) a product;
 * 
 * @return Product* Pointer to the Absract Data Type representing a structure that contains the (inicialize) information for a product;
 */
Product *productConstruct();

/**
 * @brief Get the product name;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @return const char* Pointer to the vector/list/array of char representing the name oof product;
 */
const char *getProductName(Product *product);

/**
 * @brief Get the product price;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @return float Price value for a product;
 */
float getProductPrice(Product *product);

/**
 * @brief Get the product discount;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @return float Discount value (percent in float value) for a product;
 */
float getProductDiscount(Product *product);

/**
 * @brief Get the quantity product;
 * 
 * @param poduct Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @return unsigned int Quantity for a product;
 */
unsigned int getQuantityProduct(Product *product);

/**
 * @brief Get the quantity sales product;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @return unsigned Quantity of sales for  product;
 */
unsigned getQuantitySalesProduct(Product *product);

/**
 * @brief Set product name;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @param name New name to the product;
 */
void*setProductName(Product *product, char *name);

/**
 * @brief Set the product price;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @param price New price to the product;
 */
void setProductPrice(Product *product, float price);

/**
 * @brief Set the product discount;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @param percent New percet of discount to  the price for a product
 */
void setProductDiscount(Product *product, float percent);

/**
 * @brief Buy product (Remove a quantity from the stock product);
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @param quantity Quantity to be removed from the stock product; 
 */
void buyProduct(Product *product, unsigned int quantity);

/**
 * @brief Sell product (Remove a quantity from the stock product);
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @param quantity Quantity to be added to the stock product; 
 */
void sellProduct(Product *product, unsigned int quantity);

/**
 * @brief Get the discounted price product;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 * @return float 
 */
float getDiscountedPriceProduct(Product *product);

/**
 * @brief Compare the names of two products;
 * 
 * @param product1 Pointer to the Absract Data Type representing a structure that contains the (update) information to the first product;
 * @param product2 Pointer to the Absract Data Type representing a structure that contains the (update) information to the second product;
 * @return short int 1 if the name of the first product is greater (comes later in alphabetical order) than the second, or
 *  -1 if the name of the second product is greater (comes later in alphabetical order) than the first, or
 * 0 if the two names are same
 */
short int compareNameProduct(Product *product1, Product *product2);

/**
 * @brief Compare the price of two products;
 * 
 * @param product1 Pointer to the Absract Data Type representing a structure that contains the (update) information to the first product;
 * @param product2 Pointer to the Absract Data Type representing a structure that contains the (update) information to the second product;
 * @return short int 1 if the price of the first product is greater (comes later in alphabetical order) than the second, or
 *  -1 if the price of the second product is greater (comes later in alphabetical order) than the first, or
 * 0 if the two prices are same;
 */
short int comparePriceProduct(Product *product1, Product *product2);

/**
 * @brief Compare the quantity of sales of two products;
 * 
 * @param product1 Pointer to the Absract Data Type representing a structure that contains the (update) information to the first product;
 * @param product2 Pointer to the Absract Data Type representing a structure that contains the (update) information to the second product;
 * @return short int 1 if the quantity of sales of the first product is greater (comes later in alphabetical order) than the second, or
 *  -1 if the quantity of sales of the second product is greater (comes later in alphabetical order) than the first, or
 * 0 if the two quantity of sales are same;
 */
short int compareSalesProduct(Product *product1, Product *product2);

/**
 * @brief Printed out all informations about a product;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 */
void printProduct(Product *product);

/**
 * @brief Destroy (dynamically desallocates memory for) a product;
 * 
 * @param product Pointer to the Absract Data Type representing a structure that contains the (update) information for a product;
 */
void destroyProduct(Product *product);

#endif