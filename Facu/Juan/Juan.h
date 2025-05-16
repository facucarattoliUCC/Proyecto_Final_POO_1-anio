

#include <iostream>
#include <string.h>
using namespace std;

//enum {
//    BAJO = 0,
//    ACTIVO
//};

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
    char tipoTransaccion; // si es Deposito(D) o Extraccion(E)
    char moneda; // si es Dolares(D) o Pesos(P)
    string descripcion;
    string nroCuenta;  // que caja de ahorro es

public:
    Transacciones();
    Transacciones(string, float, char, char, string, string);

    void setFecha(string);
    void setMonto(float);
    void setTipoTransaccion(char);
    void setMonedaTransaccion(char);
    void setDescripcion(string);
    void setNroCuenta (string);

    string getFecha();
    float getMonto();
    char getTipoTransaccion();
    char getMonedaTransaccion();
    string getDescripcion();

    void registrarEnArchivo();
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
    void setNumeroCta(string);
    void setMoneda(string);

    float getSaldo();
    string getNumeroCta();
    string getMoneda();

    void deposito(float);

    void extraccion(float);

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
    Cliente(long, string, int,bool, string, CajasAhorro, CajasAhorro);

    void setTipoCliente (string);
    void setCAhorroD(CajasAhorro);
    void setCAhorroP(CajasAhorro);

    string getTipoCliente();
    CajasAhorro& getCAhorroP();
    CajasAhorro& getCAhorroD();

    void deposito(float, char tipo);
    void extraccion(float, char tipo);
    void registrarDatosClientes(); 
    void mostrarDatosCliente();
    void mostrarCAhorroD();
    void mostrarCAhorroP();

};

