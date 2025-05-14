#include <iostream>
#include <string>

using namespace std;

// Enumeración de frutas.
typedef enum 
    { 
        
        Manzana, 
        Pera, 
        Durazno, 
        Banana, 
        Anana, 
        Frutilla 

    } tFrutas;

// Variables globales para los datos del proveedor.
string codigoProveedor = "";
string razonSocial = "";
string fechaSolicitud = "";
string fechaEntrega = "";

// Variables globales para el pedido de frutas.
int cantManzanas = 0;
int cantPeras = 0;
int cantDuraznos = 0;
int cantBananas = 0;
int cantAnanas = 0;
int cantFrutillas = 0;

// Prototipos de funciones.
string frutaATexto(tFrutas fruta);
void mostrarMenuFrutas();
void realizarPedidoFrutas();
void ingresarDatosProveedor();
void mostrarResumenPedido();
void limpiarPedido();
void menu();

int main() 
    {
        menu();
        return 0;
    }

// Implementación de funciones.

// Función para convertir el tipo de fruta a texto.
string frutaATexto(tFrutas fruta) 
    {
        switch(fruta) 
            {
                case Manzana: 
                    return "Manzana";
                case Pera: 
                    return "Pera";
                case Durazno: 
                    return "Durazno";
                case Banana: 
                    return "Banana";
                case Anana: 
                    return "Anana";
                case Frutilla: 
                    return "Frutilla";
                default: 
                    return "Desconocida";
            }
    }

// Función para mostrar el menú de frutas.
void mostrarMenuFrutas() 
    {
        cout << "\nFrutas disponibles:\n------------------\n";
        cout << "1. Manzana\n";
        cout << "2. Pera\n";
        cout << "3. Durazno\n";
        cout << "4. Banana\n";
        cout << "5. Anana\n";
        cout << "6. Frutilla\n";
        cout << "0. Finalizar pedido\n";
    }

// Función para procesar el pedido de frutas.
void realizarPedidoFrutas() 
    {
        int opcion;
        int cantidad;
        
        do 
            {
                mostrarMenuFrutas();
                cout << "\nSelecciona una fruta (1 a 6) o 0 para terminar: ";
                cin >> opcion;
                
                if(opcion >= 1 && opcion <= 6) 
                    {
                        cout << "Ingresa la cantidad de " << frutaATexto(static_cast<tFrutas>(opcion-1)) << ": ";
                        cin >> cantidad;
                        
                        switch(opcion-1) 
                            {
                                case Manzana: cantManzanas += cantidad; 
                                    break;
                                case Pera: cantPeras += cantidad; 
                                    break;
                                case Durazno: cantDuraznos += cantidad; 
                                    break;
                                case Banana: cantBananas += cantidad; 
                                    break;
                                case Anana: cantAnanas += cantidad; 
                                    break;
                                case Frutilla: cantFrutillas += cantidad; 
                                    break;
                            }
                            
                    } else if(opcion != 0) 
                        {
                            cout << "\nOpcion no valida. Intenta nuevamente.\n\n";
                        }

            } while(opcion != 0);
    }

// Función para ingresar datos del proveedor.
void ingresarDatosProveedor() 
    {
        cout << "\nIngresa los datos del proveedor:\n-------------------------------\n";
        cout << "Codigo de proveedor: ";
        cin.ignore();
        getline(cin, codigoProveedor);
        
        cout << "Razon social: ";
        getline(cin, razonSocial);
        
        cout << "Fecha de solicitud (DD/MM/AAAA): ";
        getline(cin, fechaSolicitud);
        
        cout << "Fecha de entrega (DD/MM/AAAA): ";
        getline(cin, fechaEntrega);
    }

// Función para mostrar el resumen del pedido.
void mostrarResumenPedido() 
    {
        cout << "\n=========================\nRESUMEN DEL PEDIDO\n=========================\n";
        cout << "Proveedor: " << codigoProveedor << " - " << razonSocial << "\n";
        cout << "Fecha de solicitud: " << fechaSolicitud << "\n";
        cout << "Fecha de entrega: " << fechaEntrega << "\n\n";
        cout << "=========================\nDETALLE DE FRUTAS\n=========================\n";
        
        if(cantManzanas > 0) cout << "Manzanas: " << cantManzanas << "\n";
        if(cantPeras > 0) cout << "Peras: " << cantPeras << "\n";
        if(cantDuraznos > 0) cout << "Duraznos: " << cantDuraznos << "\n";
        if(cantBananas > 0) cout << "Bananas: " << cantBananas << "\n";
        if(cantAnanas > 0) cout << "Ananas: " << cantAnanas << "\n";
        if(cantFrutillas > 0) cout << "Frutillas: " << cantFrutillas << "\n";
        
        cout << "=========================\n";
    }

// Función para limpiar todos los datos del pedido.
void limpiarPedido() 
    {
        // Limpiar datos del proveedor.
        codigoProveedor = "";
        razonSocial = "";
        fechaSolicitud = "";
        fechaEntrega = "";
        
        // Limpiar cantidades de frutas.
        cantManzanas = 0;
        cantPeras = 0;
        cantDuraznos = 0;
        cantBananas = 0;
        cantAnanas = 0;
        cantFrutillas = 0;
        
        cout << "\nTodos los datos del pedido han sido limpiados.\n";
    }

// Función principal del menú.
void menu() 
    {
        int opcion;
        
        do 
            {
                cout << "\n=====================================\nSISTEMA DE PEDIDOS VERDULERIA LUISITO\n=====================================\n";
                cout << "1. Ingresa datos del proveedor\n";
                cout << "2. Realiza pedido de frutas\n";
                cout << "3. Muestra resumen del pedido\n";
                cout << "4. Limpia pedido actual\n";
                cout << "0. Salir\n";
                cout << "\nSelecciona una opcion: ";
                cin >> opcion;
                
                switch(opcion) 
                    {
                        case 1:
                            ingresarDatosProveedor();
                            break;
                        case 2:
                            if(codigoProveedor.empty()) 
                                {
                                    cout << "\nPrimero debes ingresar los datos del proveedor.\n";

                                } else 
                                    {
                                        realizarPedidoFrutas();
                                    }
                            break;
                        case 3:
                            if(codigoProveedor.empty()) 
                                {
                                    cout << "\nNo hay datos del proveedor para mostrar.\n";

                                } else 
                                    {
                                        mostrarResumenPedido();
                                    }
                            break;
                        case 4:
                            limpiarPedido();
                            break;
                        case 0:
                            cout << "\nSaliendo del sistema...\n\n";
                            break;
                        default:
                            cout << "\nOpcion no valida. Intenta nuevamente.\n";
                    }
            } while(opcion != 0);
    }