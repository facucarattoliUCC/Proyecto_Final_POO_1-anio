/*DUDAS:
1) como registro / cargo datos de nuevos clientes? como hago para modificarles el estado de
    baja / alta?
2) linea 44: cuando deposito no me suma el saldo depositado al saldo
3) hay alguna manera/recomendacion de trabajar en proyectos grandes que a medida que vas 
    declarando y definiendo clases poder ir testeandolas? ya que ahora me encuentro con una 
    definicion de clases enorme y no se por donde empezar o arreglar errores.
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include "Juan.h"
using namespace std;

string registrarTipoCliente(){
    int tipoCliente;

    cout<<"Ingrese el tipo de cliente: \n";
    cout<<"1. ClientePlata \n";
    cout<<"2. ClienteOro \n";
    cout<<"3. ClientePlatino \n";
    cin>>tipoCliente;

    string tipoClienteStr;
    switch(tipoCliente){
        case 1:
            tipoClienteStr = "plata";
            break;
        case 2:
            tipoClienteStr = "oro";
            break;
        case 3:
            tipoClienteStr = "platino";
            break;
        default:
            cout<<"Error. Ingrese un tipo de cliente valido \n";
    }

    return tipoClienteStr;
}

int seleccionarCliente(int cantidad_clientes){
    int nro_cliente;
    cout<<"Seleccione el numero de cliente que desea ver: \n";
    cin >> nro_cliente;
    if(nro_cliente >= cantidad_clientes){
        cout<<"Error. Ingrese un numero de cliente valido \n";
        return -1;
    }
    return nro_cliente;
}

int main()
{

    Cliente clientes[100];
    int cantidad_clientes = 0;
    int numero_cuenta = 0;


    Transacciones transacciones[1000];
    int cantidad_transacciones = 0;

    long dni;
    string nombre, tipoCliente;
    int anioIngreso, opc = 0, i = 0;
    char estado;
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
        cout << "3. Extraer Dolares \n";
        cout << "*****************************\n";
        cout << "4. Extraer Pesos \n";
        cout << "*****************************\n";
        cout << "5. Depositar Pesos \n";
        cout << "*****************************\n";
        cout << "6. Depositar Dolares \n";
        cout << "*****************************\n";
        cout << "7. Salir \n";
        cout << "*****************************\n";
        cin >> opc;

        switch (opc)
        {
        case 1: {
            cout << "Ingrese dni: \n";
            cin >> dni;
            cout << "Ingrese nombre y apellido: \n";
            getline(cin >> ws, nombre);
            cout << "Ingrese anioIngreso: \n";
            cin >> anioIngreso;
            tipoCliente = registrarTipoCliente();

            string nro_cuenta_pesos, nro_cuenta_dolar;
            nro_cuenta_pesos = to_string(numero_cuenta);
            nro_cuenta_dolar = to_string(numero_cuenta + 1);

            clientes[cantidad_clientes] = Cliente(dni, nombre, anioIngreso, true,
                                                  tipoCliente,
                    /* Caja de Ahorro en pesos*/      CajasAhorro(0, nro_cuenta_pesos, "AR"),
                    /* Caja de Ahorro en dolares*/    CajasAhorro(0, nro_cuenta_dolar, "US")
            );
            clientes[cantidad_clientes].mostrarDatosCliente();

            numero_cuenta += 2;
            cantidad_clientes++;
            break;
        }
        case 2:
            i = seleccionarCliente(cantidad_clientes);
            if(i == -1){
                break;
            }
            clientes[i].mostrarDatosCliente();
            break;

        case 3:
            i = seleccionarCliente(cantidad_clientes);
            if(i == -1){
                break;
            }
            cout << "Ingrese los dolares que desea extraer: \n";
            cin >> monto;
            clientes[i].extraccion(monto, 'd');
            clientes[i].mostrarCAhorroD();
            break;

        case 4:
            i = seleccionarCliente(cantidad_clientes);
            if(i == -1){
                break;
            }
            cout << "Ingrese los pesos que desea extraer: \n";
            cin >> monto;
            clientes[i].extraccion(monto, 'p');
            clientes[i].mostrarCAhorroP();
            break;

        case 5:
            i = seleccionarCliente(cantidad_clientes);
            if(i == -1){
                break;
            }
            cout << "Ingrese los pesos que desea depositar: \n";
            cin >> monto;
            clientes[i].deposito(monto, 'p');
            clientes[i].mostrarCAhorroP(); // muestra saldo
            break;

        case 6:
            i = seleccionarCliente(cantidad_clientes);
            if(i == -1){
                break;
            }
            cout << "Ingrese los dolares que desea depositar: \n";
            cin >> monto;
            if (monto > 0)
            {
                clientes[i].deposito(monto, 'd');
                clientes[i].mostrarCAhorroD(); // muestra saldo
            }
            else
            {
                cout << "Error. El deposito no puede ser cero o negativo \n";
            }
            break;

        case 7:
            cout << "Gracias por su visita. Hasta la proxima \n";
            break;
        default:
            cout << "Seleccione una opcion valdia \n";
        }

    } while (opc != 7);

    return 0;
}
