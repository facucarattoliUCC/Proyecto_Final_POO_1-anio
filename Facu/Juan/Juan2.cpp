#include <iostream>
#include <string.h>
#include <fstream>
#include "Juan.h"
using namespace std;

DatosPersonas ::DatosPersonas() {}

DatosPersonas::DatosPersonas(long _dni, string _nombre, int _anioIngreso, bool _estado)
    : dni(_dni), nombre(_nombre), anioIngreso(_anioIngreso), estado(_estado) {}

void DatosPersonas::setDni(long _dni)
{
    dni = _dni;
}

void DatosPersonas::setNombre(string _nombre)
{
    nombre = _nombre;
}

void DatosPersonas ::setAnioIngreso(int _anioIngreso)
{
    anioIngreso = _anioIngreso;
}

void DatosPersonas::setEstado(bool _estado)
{
    estado = _estado;
}

long DatosPersonas ::getDni()
{
    return dni;
}

string DatosPersonas::getNombre()
{
    return nombre;
}

int DatosPersonas::getAnioIngreso()
{
    return anioIngreso;
}

bool DatosPersonas ::getEstado()
{
    return estado;
}

Personal ::Personal() {}

Personal :: Personal(long _dni, string _nombre, int _anioIngreso, bool _estado, string _cargo) : DatosPersonas(_dni, _nombre, _anioIngreso, _estado), cargo(_cargo) {}

void Personal ::setCargo(string _cargo)
{
    cargo = _cargo;
}

string Personal ::getCargo()
{
    return cargo;
}

void Personal ::mostrarDatosPersonal()
{
    cout << "Nombre " << nombre;
    cout << "DNI " << dni;
    cout << "Cargo " << cargo;
}

Transacciones ::Transacciones() {}

Transacciones ::Transacciones(string _fecha, float _monto, char _tipoTransaccion, char _monedaTransaccion, string _descripcion, string _nroCuenta) : fecha(_fecha), monto(_monto), tipoTransaccion(_tipoTransaccion), moneda(_monedaTransaccion), descripcion(_descripcion), nroCuenta(_nroCuenta) {}


void Transacciones::registrarEnArchivo()
{
    ofstream archivo("transacciones.txt", ios::app); // Modo append para agregar sin sobrescribir

    if (archivo.is_open())
    {
        archivo <<"Nro Cuenta: "<< nroCuenta << endl;
        archivo << "Fecha: " << fecha << endl;
        archivo << "Monto: $" << monto << endl;
        archivo << "Tipo de Transacción: " << tipoTransaccion << endl;
        archivo << "Moneda: " << moneda << endl;
        archivo << "Descripción: " << descripcion << endl;
        archivo << "--------------------------" << endl;
        archivo.close();
        cout << "Transacción registrada en archivo";
    }
    else
    {
        cout << "Error al abrir el archivo de transacciones" << endl;
    }
}

void Transacciones::mostrarTransaccion()
{
    cout <<"Nro Cuenta: "<< nroCuenta << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Monto: $" << monto << endl;
    cout << "Tipo de Transacción: " << tipoTransaccion << endl;
    cout << "Moneda: " << moneda << endl;
    cout << "Descripción: " << descripcion << endl;
    cout << "--------------------------" << endl;
}

void Transacciones::setFecha(string _fecha) {
    fecha = _fecha;
}

void Transacciones::setMonto(float _monto) {
    monto = _monto;
}

void Transacciones::setTipoTransaccion(char _tipoTransaccion) {
    tipoTransaccion = _tipoTransaccion;
}

void Transacciones::setMonedaTransaccion(char _moneda) {
    moneda = _moneda;
}

void Transacciones::setDescripcion(string _descripcion) {
    descripcion = _descripcion;
}

void Transacciones::setNroCuenta(string _nroCuenta) {
    nroCuenta = _nroCuenta;
}

string Transacciones::getFecha() {
    return fecha;
}

float Transacciones::getMonto() {
    return monto;
}

char Transacciones::getTipoTransaccion() {
    return tipoTransaccion;
}

char Transacciones::getMonedaTransaccion() {
    return moneda;
}

CajasAhorro ::CajasAhorro() {}

CajasAhorro::CajasAhorro(float _saldo, string _numeroCta, string _moneda) : saldo(_saldo), numeroCta(_numeroCta), moneda(_moneda){}

void CajasAhorro ::setSaldo(float _saldo)
{
    saldo = _saldo;
}

void CajasAhorro::setNumeroCta(string _numeroCta)
{
    numeroCta = _numeroCta;
}

void CajasAhorro::setMoneda(string _moneda) {
    moneda = _moneda;
}



float CajasAhorro::getSaldo()
{
    return saldo;
}

string CajasAhorro::getNumeroCta()
{
    return numeroCta;
}

string CajasAhorro::getMoneda() {
    return moneda;
}


void CajasAhorro::deposito(float _monto)
{

    if (_monto <= 0)
    {
        cout << "Error. El deposito no puede ser nulo o negativo o la transaccion no coincide con la CA" << endl;
    }
    else
    {
        saldo += _monto;
    }
}


void CajasAhorro::extraccion(float _monto)
{

    if (_monto < 0)
    {
        cout << "Error. No se puede extraer plata negativa" << endl;
    }
    else if(_monto > saldo){
        cout << "Error. No tiene suficiente dinero en la cuenta" << endl;
    }
    else
    {
        saldo -= _monto;
    }
}


void CajasAhorro ::mostrarSaldo()
{
    cout << "El saldo es " << moneda << "$" << saldo << endl;
}



Cliente::Cliente() {}

Cliente::Cliente(long _dni, string _nombre, int _anioIngreso, bool _estado, string _tipoCliente, CajasAhorro _CAhorroP, CajasAhorro _CAhorroD) :
DatosPersonas(_dni, _nombre, _anioIngreso, _estado), tipoCliente(_tipoCliente), CAhorroD(_CAhorroD), CAhorroP(_CAhorroP) {}


void Cliente::setTipoCliente(string _tipoCliente)
{
    tipoCliente = _tipoCliente;
}

void Cliente ::setCAhorroD(CajasAhorro _CAhorroD)
{
    CAhorroD = _CAhorroD;
}

void Cliente ::setCAhorroP(CajasAhorro _CAhorroP)
{
    CAhorroP = _CAhorroP;
}

string Cliente::getTipoCliente()
{
    return tipoCliente;
}

CajasAhorro& Cliente ::getCAhorroD()
{
    return CAhorroD;
}

CajasAhorro& Cliente ::getCAhorroP()
{
    return CAhorroP;
}

void Cliente :: deposito (float _monto, char tipo){
    if(tipo == 'd'){
        CAhorroD.deposito(_monto);
    }
    else if(tipo == 'p'){
        CAhorroP.deposito(_monto);
    }
}


void Cliente :: extraccion(float _monto, char tipo){
    if(tipo == 'd'){
        CAhorroD.extraccion(_monto);
    }
    else if(tipo == 'p'){
        CAhorroP.extraccion(_monto);
    }
}

void Cliente:: registrarDatosClientes(){

     ofstream archivo("DatosClientes.txt", ios::app); // Modo append para agregar sin sobrescribir

    if (archivo.is_open())
    {
        archivo << "Dni: " << dni << endl;
        archivo << "Nombre: " << nombre << endl;
        archivo << "Anio Ingreso: " << anioIngreso << endl;
        archivo << "Estado: "<< estado <<endl;
        archivo << "Tipo Cliente"<<tipoCliente<<endl;
        archivo << "Tipo Persona: "<< tipoCliente <<endl;
        archivo << "--------------------------" << endl;
        archivo.close();
        cout << "Transacción registrada en archivo";
    }
    else
    {
        cout << "Error al abrir el archivo de transacciones" << endl;
    }
} 

void Cliente :: mostrarDatosCliente(){
    cout << "Nombre: "<<nombre<<endl;
    cout << "DNI: "<<dni<<endl;
    cout << "AnioIngreso: "<<anioIngreso<<endl;
    cout << "Estado: "<<( estado ? "Activo" : "Baja" )<<endl;
    cout << "Tipo Cliente: "<<tipoCliente<<endl;
}

void Cliente :: mostrarCAhorroD (){
    CAhorroD.mostrarSaldo();
}

void Cliente :: mostrarCAhorroP (){
    CAhorroP.mostrarSaldo();
}

//void Cliente :: cargarCliente (long _dni, string _nombre, int _anioIngreso, string _tipoCliente, char _estado){
//
//}
//
//void Cliente :: cargarTipoCliente(){
//    int opcion;
//    do
//    {
//     cout<<"Seleccione el tipo de cliente: \n";
//     cout<<"1. Plata \n";
//     cout<<"2. Oro \n";
//     cout<<"3. Platino \n";
//     cin>> opcion;
//    } while (opcion >= 4 );
//
//    switch (opcion)
//    {
//    case 1:
//        tipoCliente = "Plata";
//        break;
//    case 2:
//        tipoCliente = "Oro";
//        break;
//    case 3:
//        tipoCliente = "Platino";
//        break;
//    }
//}
