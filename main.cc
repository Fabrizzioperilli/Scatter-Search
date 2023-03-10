#include <iostream>

int main()
{

    int table_size, type_function, type_technique;
    std::cout << "\tBúsquedas por dispersión" << std::endl;
    std::cout << "--Introduzca el tamaño de la tabla: ";
    std::cin >> table_size;
    std::cout << "--Función de dispersión a utilizar: " << std::endl;
    std::cout << "1. Módulo  " << std::endl;
    std::cout << "2. Suma  " << std::endl;
    std::cout << "3. Pseudoaletoria  " << std::endl;
    std::cout << "--Opción:  ";
    std::cin >> type_function;
    std::cout << "--Técnica de dispersión a utilizar: " << std::endl;
    std::cout << "1. Abierta" << std::endl;
    std::cout << "2. Cerrada" << std::endl;
    std::cout << "--Opción:  ";
    std::cin >> type_technique;

    if (type_technique == 1)
        std::cout << "Array de listas enlazadas" << std::endl;
    else if (type_technique == 2)
    {
        int block_size, op_exploration;
        std::cout << "--Introduzca el tamaño del bloque: ";
        std::cin >> block_size;
        std::cout << "--Función de exploración " << std::endl;
        std::cout << "1. Exploración Lineal  " << std::endl;
        std::cout << "2. Exploración Cuadrática  " << std::endl;
        std::cout << "3. Doble Dispersión" << std::endl;
        std::cout << "4. Redispersión" << std::endl;
        std::cout << "--Opción: ";
        std::cin >> op_exploration;

        switch (op_exploration)
        {
        case 1:
            std::cout << "Exploracion lineal" << std::endl;
            // fe = new feLineal<int>();
            break;
        case 2:
            std::cout << "Exploracion Cuadrática" << std::endl;
            // fe = new feQuadratic<int>();
            break;
        case 3:
            std::cout << "Exploracion Doble" << std::endl;
            // fe = new feDoubleDispersion<int>();
            break;
        case 4:
            std::cout << "Redispersión" << std::endl;
            // fe = new feRedispersion<int>();
            break;
        default:
            std::cout << "Opción no válida" << std::endl;
            exit(EXIT_FAILURE);
        }

        int option_menu;
        do
        {
            std::cout << "\nInsertar [1]" << std::endl;
            std::cout << "Buscar [2]" << std::endl;
            std::cout << "Mostrar tabla [3]" << std::endl;
            std::cout << "Salir [0]" << std::endl;
            std::cout << "--Opción: ";
            std::cin >> option_menu;

            int key;
            switch (option_menu)
            {
            case 1:
                std::cout << "\n--Introduzca la clave: ";
                std::cin >> key;
                break;
            case 2:

                std::cout << "\n--Introduzca la clave: ";
                std::cin >> key;
                break;
            case 3:
                std::cout << "Mostrar tabla" << std::endl;
                break;
            case 0:
                break;
            default:
                std::cout << "Opción no válida" << std::endl;
                break;
            }
        } while (option_menu != 0);
    }
    else {
        std::cout << "Opción no válida" << std::endl;   
        exit(EXIT_FAILURE);
    }
    
    return 0;
}