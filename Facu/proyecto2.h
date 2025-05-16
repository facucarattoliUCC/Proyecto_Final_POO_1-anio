/*DUDAS:
1) linea 128 y 129: no termino de entender la cuestion de pasar por referencia &
2) linea 131 y 132: que significa el parametro "tipo"?
3) 
*/

#include <iostream>
#include <string.h>
using namespace std;

class DatosPersonas
{

protected:
    long dni;
    string nombre;
    int anioIngreso;
    bool estado; //activo o baja

public:
    DatosPersonas();
    DatosPersonas(long, string, int, bool);

    void setDni(long);
    void setNombre(string);
    void setAnioIngreso(int);
    void setEstado(bool);

    long getDni();
    string getNombre();
    int getAnioIngreso();
    bool getEstado();
};

class Personal : public DatosPersonas
{
private:
    string cargo;

public:
    Personal();
    Personal(long, string, int, bool, string);

    void setCargo(string);
    
    string getCargo();
    
    void mostrarDatosPersonal();
};

class Transacciones
{
private:
    string fecha;
    float monto;
    char tipoTransaccion; //deposito o extraccion
    char moneda; // dolares o pesos
    string descripcion;
    string nroCuenta; // que caja de ahorro es

public:
    Transacciones();
    Transacciones(string, float, char,char, string, string);

    void setFecha(string);
    void setMonto(float);
    void setTipoTransaccion(char);
    void setMoneda (char);
    void setDescripcion (string);
    void setNroCuenta (string);

    string getFecha();
    float getMonto();
    char getTipoTransaccion();
    char getMoneda();
    string getDescripcion();
    string getNroCuenta();

    void registrarTranEnArchivo();
    void mostrarTransaccion();
};

class CajasAhorro
{

private:
    float saldo;
    string numeroCta;
    string moneda; // (US$ o AR$)

public:
    CajasAhorro();
    CajasAhorro(float, string, string);

    void setSaldo (float);
    void setNumeroCta (string);
    void setMoneda (string);

    float getSaldo();
    string getNumeroCta();
    string getMoneda();

    void deposito(float);  

    void extraccion( float); 

    void mostrarSaldo();
};

class Cliente : public DatosPersonas
{

private:
    string tipoCliente;
    // string clientePlata; //no acceso tarjeta credito
    // string clienteOro; //acceso tarjeta credito. limite 250mil
    // string clientePlatino; //acceso tarjeta credito. limite 500mil     
    CajasAhorro CAhorroP;
    CajasAhorro CAhorroD;

public:
    Cliente();
    Cliente(long, string, int, bool,string, CajasAhorro, CajasAhorro );

    void setTipoCliente (string);
    void setCAhorroP(CajasAhorro); 
    void setCAhorroD(CajasAhorro); 

    string getTipoCliente();
    CajasAhorro& getCAhorroP(); //pasados por referencia & para obteer los datos tal cual y no una copia
    CajasAhorro& getCAhorroD(); 

    void deposito(float, char _tipo);   
    void extraccion(float, char _tipo);             
    void registrarDatosClientes(); 
    void mostradDatosCliente();   
    void mostrarCAhorroD();
    void mostrarCAhorroP();
    string registrarTipoCliente();

};


