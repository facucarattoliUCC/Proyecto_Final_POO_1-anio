#include <iostream>
#include <string.h>
#include <fstream>
#include "proyecto2.h"
using namespace std;


int main()
{

    Cliente clientes[100];
    int cantidadClientes = 0; // contador de clientes
    int numeroCuenta = 0;     // contador de numero de cuentas

    Transacciones transacciones[1000];
    int cantidadTransacciones = 0; // contador de transacciones

    long dni;
    string nombre, tipoCliente;
    int anioIngreso, opc = 0, i = 0;
    float monto;

    // menu
    do
    {
        cout << "-----------------------------\n";
        cout << "Bienvenido al banco UCC. Para continuar ingrese una opcion: \n";
        cout << "*****************************\n";
        cout << "1. Cargar datos cliente \n";
        cout << "*****************************\n";
        cout << "2.Mostrar datos clientes \n";
        cout << "*****************************\n";
        cout << "3. Extraer Pesos \n";
        cout << "*****************************\n";
        cout << "4. Extraer Dolares \n";
        cout << "*****************************\n";
        cout << "5.Depositar Pesos \n";
        cout << "*****************************\n";
        cout << "6. Depositar Dolares \n";
        cout << "*****************************\n";
        cout << "7. Mostrar archivo datos clientes \n";
        cout << "*****************************\n";
        cout << "8. Mostrar archivo transacciones \n";
        cout << "*****************************\n";
        cout << "9. Salir \n";
        cout << "*****************************\n";
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            cout << "Ingrese dni: \n";
            cin >> dni;
            cout << "Ingrese nombre: \n";
            cin >> nombre;
            cout << "Ingrese anioIngreso: \n";
            cin >> anioIngreso;
            // cout<<"Ingrese tipo cliente: \n";
            tipoCliente = clientes[cantidadClientes].registrarTipoCliente();

            string nroCuentaPesos, nroCuentaDolares;
            nroCuentaPesos = to_string(numeroCuenta); 
            nroCuentaDolares = to_string(numeroCuenta + 1); //to_string traduce de int a string

            clientes[cantidadClientes] = Cliente(dni, nombre, anioIngreso, true,
                                                 tipoCliente,
                                                 CajasAhorro(0, nroCuentaPesos, "AR"),
                                                 CajasAhorro(0, nroCuentaDolares, "US"));
            clientes[cantidadClientes].mostradDatosCliente();

            clientes[cantidadClientes].registrarDatosClientes(); // guarda datos en DatosClientes.txt

            numeroCuenta += 2; //asigno numero de cuenta automatica a CA
            cantidadClientes++; 
            break;
        }

        case 2:
            cout << "Seleccione el numero de cliente que desea ver: \n";
            cout << "Si no desea ver cliente presione -1. \n";
            cin >> i;
            if (i == -1)
            {
                break;
            }

            if (i < cantidadClientes){
            clientes[cantidadClientes].mostradDatosCliente();
            break;
            }

        case 3:
            cout << "Seleccione el numero de cliente: \n";
            cout << "Si no desea ver cliente presione -1. \n";
            cin >> i;
            if (i == -1)
            {
                break;
            }

            if (i >= cantidadClientes){
                cout<<"Cliente no encontrado \n";
                break;
            }

            cout << "Ingrese los pesos que desea extraer: \n";
            cin >> monto;
            clientes[i].extraccion(monto, 'p');
            transacciones[i].registrarTranEnArchivo();
            cout << "-------------------------\n";
            clientes[i].mostrarCAhorroP();
            break;
            
        case 4:
             cout << "Seleccione el numero de cliente: \n";
            cout << "Si no desea ver cliente presione -1. \n";
            cin >> i;
            if (i == -1)
            {
                break;
            }
            cout << "Ingrese los dolares que desea extraer: \n";
            cin >> monto;

            clientes[i].extraccion(monto, 'd');
            transacciones[i].registrarTranEnArchivo();
            cout << "-------------------------\n";

            clientes[i].mostrarCAhorroD();
            break;

        case 5:
            cout << "Seleccione el numero de cliente: \n";
            cout << "Si no desea ver cliente presione -1. \n";
            cin >> i;           
             if (i == -1)
            {
                break;
            }
            cout << "Ingrese los pesos que desea depositar: \n";
            cin >> monto;
            clientes[i].deposito(monto, 'p');
            transacciones[i].registrarTranEnArchivo();
            cout << "-------------------------\n";

            clientes[i].mostrarCAhorroP(); // muestra saldo
            break;

        case 6:
            cout << "Seleccione el numero de cliente: \n";
            cout << "Si no desea ver cliente presione -1. \n";
            cin >> i;              
             if (i == -1)
            {
                break;
            }
            cout << "Ingrese los dolares que desea depositar: \n";
            cin >> monto;

            clientes[i].deposito(monto, 'd');
            transacciones[i].registrarTranEnArchivo();
            cout << "-------------------------\n";

            clientes[i].mostrarCAhorroD(); // muestra saldo

            break;

        case 7:
        {
            ifstream archivo("DatosClientes.txt");
            if (!archivo)
            {
                cout << "Error al abrir el archivo datos de clientes\n";
            }
        }
        break;

        case 8:
        {
            ifstream archivo1("transacciones.txt");
            if (!archivo1)
            {
                cout << "Error al abrir el archivo de transacciones \n";
                break;
            }
        }

        case 9:
            cout << "Gracias por su visita. Hasta la proxima \n";

        default:
            cout << "Seleccione una opcion valida \n";
        }

    } while (opc != 9);

    return 0;
}
