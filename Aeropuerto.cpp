#include <iostream>
#include <string>

using namespace std;

// Definición de tipos enumerados para las clases de vuelo.
typedef enum 
    { 
        economica, 
        primera, 
        business 
        
    } tClaseVuelo;

// Definición de tipos enumerados para los aeropuertos.
typedef enum 
    { 
        BHI,  // Bahía Blanca.
        AEP,  // Buenos Aires Aeroparque.
        EPA,  // Buenos Aires El Palomar.
        EZE,  // Buenos Aires Ezeiza.
        BRC,  // San Carlos de Bariloche.
        CTC,  // San Fernando del Valle de Catamarca.
        CRD   // Comodoro Rivadavia.
        
    } tAeropuerto;

// Variables globales para almacenar los datos de la reserva.
string dni, apellido, nombre;
tClaseVuelo clase;
tAeropuerto origen, destino;

// Prototipos de funciones.
string aeropuertoATexto(tAeropuerto aeropuerto);
string claseATexto(tClaseVuelo clase);
void mostrarAeropuertos();
tAeropuerto obtenerAeropuerto(char opcion);
void mostrarClases();
tClaseVuelo obtenerClase(int opcion);
void mostrarReserva();
void hacerReserva();
void menu();

int main() 
    {
        menu();
        return 0;
    }

// Implementación de funciones.

// Función para convertir el código de aeropuerto a texto.
string aeropuertoATexto(tAeropuerto aeropuerto) 
    {
        switch(aeropuerto) 
            {
                case BHI: 
                    return "Bahia Blanca - BHI";
                case AEP: 
                    return "Buenos Aires Aeroparque - AEP";
                case EPA: 
                    return "Buenos Aires El Palomar - EPA";
                case EZE: 
                    return "Buenos Aires Ezeiza - EZE";
                case BRC: 
                    return "San Carlos de Bariloche - BRC";
                case CTC: 
                    return "San Fernando del Valle de Catamarca - CTC";
                case CRD: 
                    return "Comodoro Rivadavia - CRD";
                default: 
                    return "Desconocido";
            }
    }

// Función para convertir la clase de vuelo a texto.
string claseATexto(tClaseVuelo clase) 
    {
        switch(clase) 
            {
                case economica: 
                    return "Economica";
                case primera: 
                    return "Primera";
                case business: 
                    return "Business";
                default: 
                    return "Desconocida";
            }
    }

// Función para mostrar el menú de aeropuertos.
void mostrarAeropuertos() 
    {
        cout << "\nCodigos de aeropuertos disponibles:\n----------------------------------\n";
        cout << "a. Bahia Blanca - BHI\n";
        cout << "b. Buenos Aires Aeroparque - AEP\n";
        cout << "c. Buenos Aires El Palomar - EPA\n";
        cout << "d. Buenos Aires Ezeiza - EZE\n";
        cout << "e. San Carlos de Bariloche - BRC\n";
        cout << "f. San Fernando del Valle de Catamarca - CTC\n";
        cout << "g. Comodoro Rivadavia - CRD\n";
    }

// Función para obtener un aeropuerto desde la entrada del usuario.
tAeropuerto obtenerAeropuerto(char opcion) 
    {
        switch(opcion) 
            {
                case 'a': 
                    return BHI;
                case 'b': 
                    return AEP;
                case 'c': 
                    return EPA;
                case 'd': 
                    return EZE;
                case 'e': 
                    return BRC;
                case 'f': 
                    return CTC;
                case 'g': 
                    return CRD;
                default: 
                    return BHI; // Valor por defecto.
            }
    }

// Función para mostrar el menú de clases de vuelo.
void mostrarClases() 
    {
        cout << "\nClases de vuelo disponibles:\n---------------------------\n";
        cout << "1. Economica\n";
        cout << "2. Primera\n";
        cout << "3. Business\n";
    }

// Función para obtener la clase de vuelo desde la entrada del usuario.
tClaseVuelo obtenerClase(int opcion) 
    {
        switch(opcion) 
            {
                case 1: 
                return economica;
                case 2: 
                return primera;
                case 3: 
                return business;
                default: 
                return economica; // Valor por defecto.
            }
    }

// Función para mostrar los datos de la reserva.
void mostrarReserva() 
    {
        cout << "\n=================================================\nReserva realizada con exito:\n=================================================\n";
        cout << "DNI: " << dni << "\n";
        cout << "Pasajero: " << apellido << ", " << nombre << "\n";
        cout << "Clase: " << claseATexto(clase) << "\n";
        cout << "Origen: " << aeropuertoATexto(origen) << "\n";
        cout << "Destino: " << aeropuertoATexto(destino) << "\n=================================================\n\n";
        cout << "QUE TENGAS UN VUELO PLACENTERO!!\n\n";
    }

// Función para realizar una nueva reserva.
void hacerReserva() 
    {
        cout << "\nIngresa los datos del pasajero:\n------------------------------\n";
        cout << "DNI: ";
        getline(cin, dni);
        
        cout << "Apellido: ";
        getline(cin, apellido);
        
        cout << "Nombre: ";
        getline(cin, nombre);
        
        // Selección de clase.
        mostrarClases();
        int opcionClase;
        cout << "\nSelecciona la clase (1 a 3): ";
        cin >> opcionClase;
        clase = obtenerClase(opcionClase);
        
        // Selección de aeropuerto origen.
        mostrarAeropuertos();
        char opcionOrigen;
        cout << "\nSelecciona el aeropuerto de origen (a - g): ";
        cin >> opcionOrigen;
        origen = obtenerAeropuerto(opcionOrigen);
        
        // Selección de aeropuerto destino.
        mostrarAeropuertos();
        char opcionDestino;
        cout << "\nSelecciona el aeropuerto de destino (a - g): ";
        cin >> opcionDestino;
        destino = obtenerAeropuerto(opcionDestino);
        
        // Limpiar el buffer de entrada.
        cin.ignore();
    }

// Función para mostrar el menú principal.
void menu() 
    {
        int opcion = 0;
        bool continuar = true;
        
        while(continuar) 
            {
                

                cout << "\n=================================================\nSISTEMA DE RESERVA DE VUELOS DE AEROLINEAS CHANGO\n=================================================\n";
                cout << "1. Realizar nueva reserva\n";
                cout << "2. Salir\n\n";
                cout << "Selecciona una opcion (1-2): ";
                
                cin >> opcion;
                cin.ignore(); // Limpiar el buffer de entrada.
                
                if(opcion == 1) 
                    {
                        hacerReserva();
                        mostrarReserva();
                    } 
                    else if(opcion == 2) 
                        {
                            continuar = false;
                            cout << "\nGracias por utilizar el sistema de reservas.\n\n";
                        }
                        else 
                            {
                                cout << "\nOpcion no valida. Intenta nuevamente.\n";
                            }
            }
    }