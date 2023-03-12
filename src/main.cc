#include <iostream>
#include "../include/FdModule.h"
#include "../include/FdSum.h"
#include "../include/FdRandom.h"
#include "../include/FeLineal.h"
#include "../include/FeQuadratic.h"
#include "../include/FeDoubleDispersion.h"
#include "../include/FeRedispersion.h"
#include "../include/HashTable.h"

int main()
{

    int table_size, type_function, type_technique;
    std::cout << "\tScatter searches" << std::endl;
    std::cout << "--Enter the size of the table: ";
    std::cin >> table_size;
    std::cout << "--Choose the hash function you want to use: " << std::endl;
    std::cout << "1. Module" << std::endl;
    std::cout << "2. Sum" << std::endl;
    std::cout << "3. Pseudorandom" << std::endl;
    std::cout << "--Option:  ";
    std::cin >> type_function;

    DispersionFunction<int> *fd;
    switch (type_function)
    {
    case 1:
        fd = new FdModule<int>(table_size);
        break;
    case 2:
        fd = new FdSum<int>(table_size);
        break;
    case 3:
        fd = new FdRandom<int>(table_size);
        break;
    default:
        std::cout << "Invalid option" << std::endl;
        exit(EXIT_FAILURE);
        break;
    }

    std::cout << "--Choose the dispersion technique you want to use: " << std::endl;
    std::cout << "1. Open Dispersion" << std::endl;
    std::cout << "2. Closed Dispersion" << std::endl;
    std::cout << "--Option:  ";
    std::cin >> type_technique;

    HashTable<int> *hash_table;

    if (type_technique == 1)
        hash_table = new HashTable<int>(table_size, fd);
    else if (type_technique == 2)
    {
        unsigned block_size;

        std::cout << "Enter the size of the block: ";
        std::cin >> block_size;

        ExplorationFunction<int> *fe;
        int op_ex = 1;
        switch (op_ex)
        {
        case 1:
            fe = new FeLineal<int>();
            break;
        case 2:
            fe = new FeQuadratic<int>();
            break;
        case 3:
            fe = new FeDoubleDispersion<int>(*fd);
            break;
        case 4:
            fe = new FeRedispersion<int>();
            break;
        default:
            std::cout << "Invalid option" << std::endl;
            exit(EXIT_FAILURE);
            break;
        }
        hash_table = new HashTable<int>(table_size, fd, fe, block_size);
    }
    else
    {
        std::cout << "Invalid option" << std::endl;
        exit(EXIT_FAILURE);
    }

    int option_menu;
    do
    {
        std::cout << "\n1. Insert Key" << std::endl;
        std::cout << "2. Search Key" << std::endl;
        std::cout << "3. Show Table" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "--Option: ";
        std::cin >> option_menu;

        int key;
        switch (option_menu)
        {
        case 1:
            std::cout << "\nEnter the key: ";
            std::cin >> key;
            hash_table->Insert(key);
            break;
        case 2:
            std::cout << "\nEnter the key to search: ";
            std::cin >> key;
            hash_table->Search(key);
            break;
        case 3:
            std::cout << "\nHash Table" << std::endl;
            std::cout << *hash_table << std::endl;
            break;
        case 0:
            exit(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Opción no válida" << std::endl;
            exit(EXIT_FAILURE);
            break;
        }
    } while (option_menu != 0);

    return 0;
}
