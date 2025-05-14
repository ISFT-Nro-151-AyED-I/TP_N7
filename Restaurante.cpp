#include <iostream>
#include <string>

using namespace std;

// Definición de tipos enumerados para los platos.
typedef enum 
    {
        Empanada,
        EnsaladaRusa,
        VitelTone,
        PrimerPlatoMax

    } tPrimerPlato;

typedef enum 
    {
        MilanesaNapolitana,
        Pizza,
        FileteMerluza,
        PlatoPrincipalMax

    } tPlatoPrincipal;

typedef enum 
    {
        Helado,
        Flan,
        QuesoDulce,
        PostreMax

    } tPostre;

// Prototipos de funciones.
string primerPlatoATexto(tPrimerPlato plato);
string platoPrincipalATexto(tPlatoPrincipal plato);
string postreATexto(tPostre postre);
void mostrarOpcionesPlatos();
void tomarPedido();
void menu();

int main() 
    {
        menu();
        return 0;
    }

// Implementación de funciones.

// Funciones para convertir códigos a texto.
string primerPlatoATexto(tPrimerPlato plato)
    {
        switch(plato) 
            {
                case Empanada: 
                    return "Empanada";
                case EnsaladaRusa: 
                    return "Ensalada Rusa";
                case VitelTone: 
                    return "Vitel Tone";
                default: 
                    return "Desconocido";
            }
    }

string platoPrincipalATexto(tPlatoPrincipal plato)
    {
        switch(plato) 
            {
                case MilanesaNapolitana: 
                    return "Milanesa napolitana con guarnicion";
                case Pizza: 
                    return "Pizza";
                case FileteMerluza: 
                    return "Filete de merluza con pure";
                default: 
                    return "Desconocido";
            }
    }

string postreATexto(tPostre postre)
    {
        switch(postre) 
            {
                case Helado: 
                    return "Helado";
                case Flan: 
                    return "Flan";
                case QuesoDulce: 
                    return "Queso y Dulce";
                default: 
                    return "Desconocido";
            }
    }

// Función para mostrar el menú de opciones de platos.
void mostrarOpcionesPlatos() 
    {
        cout << "\nOPCIONES DISPONIBLES\n--------------------\n";
        cout << "Primeros platos:\n\n";
        cout << "1. Empanada\n";
        cout << "2. Ensalada Rusa\n";
        cout << "3. Vitel Tone\n";
        
        cout << "\nPlatos principales:\n\n";
        cout << "1. Milanesa Napolitana con Guarnicion\n";
        cout << "2. Pizza\n";
        cout << "3. Filete de Merluza con Pure\n";
        
        cout << "\nPostres:\n\n";
        cout << "1. Helado\n";
        cout << "2. Flan\n";
        cout << "3. Queso y Dulce\n";
    }

// Función para tomar un pedido.
void tomarPedido() 
    {
        string numeroMesa, nombreMozo, fecha, hora;
        int opcionPrimerPlato = 0, opcionPlatoPrincipal = 0, opcionPostre = 0;
        
        cout << "\nINGRESA LA COMANDA\n------------------\n";
        cout << "Numero de mesa: ";
        cin >> numeroMesa;

        cout << "Nombre del mozo: ";
        cin.ignore();
        getline(cin, nombreMozo);

        cout << "Fecha (DD/MM/AAAA): ";
        cin >> fecha;

        cout << "Hora (HH:MM): ";
        cin >> hora;
        
        mostrarOpcionesPlatos();
        
        cout << "\nSelecciona primer plato (1 a 3): ";
        cin >> opcionPrimerPlato;

        cout << "Selecciona plato principal (1 a 3): ";
        cin >> opcionPlatoPrincipal;

        cout << "Selecciona postre (1 a 3): ";
        cin >> opcionPostre;
        
        // Validación de  opciones.
        if(opcionPrimerPlato < 1 || opcionPrimerPlato > 3 || opcionPlatoPrincipal < 1 || opcionPlatoPrincipal > 3 || opcionPostre < 1 || opcionPostre > 3) 
            {
                cout << "\nError: Opciones invalidas. Por favor ingresa numeros del 1 al 3.\n";
                return;
            }
        
        // Convertir opciones a tipos enumerados.
        tPrimerPlato primerPlato = static_cast<tPrimerPlato>(opcionPrimerPlato - 1);
        tPlatoPrincipal platoPrincipal = static_cast<tPlatoPrincipal>(opcionPlatoPrincipal - 1);
        tPostre postre = static_cast<tPostre>(opcionPostre - 1);
        
        // Mostrar la comanda completa.
        cout << "\nCOMANDA REGISTRADA:\n------------------\n";
        cout << "Mesa: " << numeroMesa << endl;
        cout << "Mozo: " << nombreMozo << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Hora: " << hora << endl;
        cout << "Primer plato: " << primerPlatoATexto(primerPlato) << endl;
        cout << "Plato principal: " << platoPrincipalATexto(platoPrincipal) << endl;
        cout << "Postre: " << postreATexto(postre) << endl;
    }

// Función del menú principal.
void menu() 
    {
        int opcion = 0;
        bool continuar = true;
        
        while(continuar) 
            {
                cout << "\n===================================\nSISTEMA DE PEDIDOS RESTAURANTE PEPE\n===================================\n";
                cout << "1. Tomar nuevo pedido\n";
                cout << "2. Salir\n";
                cout << "Selecciona una opcion: ";
                cin >> opcion;
                
                switch(opcion) 
                    {
                        case 1:
                            tomarPedido();
                            break;
                        case 2:
                            cout << "\nSaliendo del sistema...\n";
                            continuar = false;
                            break;
                        default:
                            cout << "Opcion invalida. Intenta nuevamente.\n";
                    }
            }
    }