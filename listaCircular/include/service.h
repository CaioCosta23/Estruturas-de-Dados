#ifndef _SERVICE_H_
#define _SERVICE_H_

typedef struct Service service;

/**
 * @brief Create (dynamically allocated memory for) a service;
 * 
 * @return Service* Pointer to the Abstract Data Type represents structure that contains (inicialized) information for a service;
 */
Service *serviceConstruct();

/**
 * @brief Read all informations about service;
 * 
 * @param service Pointer to the Abstract Data Type represents structure that contains (update) information for a service;
 */
void readService(Service *service);

/**
 * @brief Get the name of service;
 * 
 * @param service Pointer to the Abstract Data Type represents structure that contains (update) information for a service;
 * @return char* Pointer tto the name of service;
 */
char *getNameInService(Service *service);

/**
 * @brief Get the CPF (document) of service;
 * 
 * @param service Pointer to the Abstract Data Type represents structure that contains (update) information for a service;
 * @return char* Ponter to the CPF (document) of service
 */
char *getCpfInService(Service *service);

/**
 * @brief Destroy (dynamically free/desallocated memory for) a service;
 * 
 * @param service Pointer to the Abstract Data Type represents structure that contains (update) information for a service;
 */
void destroyService(Service *service);

#endif