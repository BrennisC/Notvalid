#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "Abono.h"
#include "Client.h"
#include "Plants.h"
using namespace std;
// @brief contraseña para poder ingresar al menu
const string CORRECT_PASSWORD = "vivero_unas2024";
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Función para obtener la posición vertical del cursor
int obtenerPosicionVerticalCursor()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}

// Función para obtener el ancho de la ventana de la consola
int obtenerAnchoConsola()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

// Función para centrar texto horizontalmente en la consola
void centrarTexto(const string &texto)
{
    int anchoVentana = obtenerAnchoConsola();
    int longitudTexto = texto.length();
    int posicionX = (anchoVentana - longitudTexto) / 2;
    gotoxy(posicionX, obtenerPosicionVerticalCursor());
    cout << texto;
    gotoxy(0, obtenerPosicionVerticalCursor() + 1); // Restaurar la posición vertical del cursor
}
/// @brief Funcion para poder ingresar al menu de opciones
bool verifyPassword(string password)
{
    while (password != CORRECT_PASSWORD)
    {
        try
        {
            centrarTexto("Ingrese la contraseña ");
            int longitudPrompt = 17; // Longitud de "Ingrese su opcion:"
            int posicionX = (obtenerAnchoConsola() - longitudPrompt) / 2;
            gotoxy(posicionX, obtenerPosicionVerticalCursor());
            getline(cin, password);

            if (password == CORRECT_PASSWORD)
            {
                throw string("Contraseña correcta");
            }
            else
            {
                cout << "La contraseña es incorrecta, intente de nuevo." << endl;
            }
        }
        catch (const string &message)
        {
            cout << message << endl;
            return true;
        }
    }
    cout << "Demasiados intentos fallidos. Acceso denegado." << endl;
    return false;
}
/// @brief Funcion para ingresar a la class de PLANTAS
void opcion1()
{

    system("cls");
    centrarTexto("Ha seleccionado la Opcion 1.");
    Sleep(3000);
    system("cls");
    BusquedaEnlazadaPlants();
}
/// @brief Funcion para ingresar a la class Abono
void opcion2()
{
    system("cls");
    cout << "Ha seleccionado la Opcion 2." << endl;
}
/// @brief Funcion para ingresar a la class Client
void opcion3()
{
    system("cls");
    cout << "Ha seleccionado la Opcion 3." << endl;
    Sleep(3000);
    system("cls");
    BusquedaEnlazadaClient();
}
/// @warning Funcion para salir de sistema
void ExitSystem()
{
    cout << "Saliendo de sistema...";
    Sleep(500);
    cout << ". ";
    exit(0);
}
void MenuVivero();
// Funcion principal
int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8"); // Establece el locale a español
    string text_verify;

    centrarTexto("------INGRESE SU CONTRASEÑA-------");
    int longitudPrompt = 17; // Longitud de "Ingrese su opcion:"
    int posicionX = (obtenerAnchoConsola() - longitudPrompt) / 2;
    gotoxy(posicionX, obtenerPosicionVerticalCursor());
    getline(cin, text_verify, '\n');
    if (!verifyPassword(text_verify))
    {
        Sleep(3000);
        cout << "Contraseña incorrecta" << endl;
    }
    MenuVivero();
    return 0;
}
void MenuVivero()
{
    char opc;
    do
    {
        system("cls");
        centrarTexto("MENU DE OPCIONES");
        centrarTexto("[1] MENU DE PLANTA");
        centrarTexto("[2] MENU DE ABONO");
        centrarTexto("[3] MENU DE CLIENTE");
        // Centrar la entrada del usuario
        int longitudPrompt = 17; // Longitud de "Ingrese su opcion:"
        int posicionX = (obtenerAnchoConsola() - longitudPrompt) / 2;
        gotoxy(posicionX, obtenerPosicionVerticalCursor());
        cout << "Ingrese su opcion: ";

        cin.getline(&opc, 4, '\n');
        switch (opc)
        {
        case '1':
            system("cls");
            opcion1();
            break;
        case '2':
            system("cls");
            opcion2();
            break;
        case '3':
            system("cls");
            opcion3();
            break;
        case '4':
            system("cls");
            ExitSystem();
            break;
        default:
            system("cls");
            cout << "Opcion no valida" << endl;
            system("pause");
            break;
        }
    } while (opc != '4');
}