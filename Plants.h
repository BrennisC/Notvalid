#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Plants
{
private:
    vector<string> name_plants;
    vector<int> quantityplants;
    vector<float> price_plants;

public:
    Plants() : name_plants(), quantityplants(), price_plants() {}
    // Registro de plantas para el sistema de la vivero UNAS
    void RegistryPlants();
    // Mostrar los elementos registratos
    void ShowPlants();
    // Guardar los plantas en un TXT
    void SavePlants();
    // Cargar para ver en el TXT
    void LoadPlants();
    // Modificar de las plantas
    friend void modifyPlants(Plants &);
    // Funcion para agrupar todos los metodos
    friend void BusquedaEnlazadaPlants();
};
void Plants::RegistryPlants()
{
    int cantidad;
    cout << "Ingrese la cantidad de plantas: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++)
    {
        string name;
        cout << "Ingrese el nombre de la planta: ";
        getline(cin, name);
        name_plants.push_back(name);
        float prc;
        cout << "Ingrese el precio de la planta: ";
        cin >> prc;
        price_plants.push_back(prc);
        int cantidad;
        cout << "Ingrese la cantidad de plantas: ";
        cin >> cantidad;
        while (cantidad <= 0)
        {
            cout << "Error, debe ser mayor a cero.\n";
            cout << "Ingrese la cantidad de plantas: ";
            cin >> cantidad;
        }
        quantityplants.push_back(cantidad);
    }
}
void Plants ::ShowPlants()
{
    cout << "Datos de las plantas registradas:" << endl;
    for (size_t i = 0; i < name_plants.size(); i++)
    {
        cout << "Planta: " << name_plants[i] << "  CANTIDAD : " << quantityplants[i] << endl;
        float total;
        for (auto price : price_plants)
        {
            total = static_cast<float>(price) * static_cast<float>(quantityplants[i]);
            cout << "EL PRECIO A PAGAR ES " << total << endl;
        }
        cout << "-----------------------------" << endl;
    }
}
void modifyPlants(Plants &pl)
{
}
// Funcion para agrupar los distintos datos de busqueda
void BusquedaEnlazadaPlants()
{
    char choice;
    Plants pl;
    do
    {
        cout << "[1]REGRISTRO DE PLANTAS: \n";
        cout << "[2]MOSTRAR PLANTAS: \n";
        cout << "[3]SALIR DEL SISTEMA: \n";
        cout << "INGRESE UNA OPCION: \n\n";
        cin.getline(&choice, 3);
        switch (choice)
        {
        case '1':
            system("cls");
            pl.RegistryPlants();
            break;
        case '2':
            system("cls");
            pl.ShowPlants();
            system("pause");
            break;
        case '3':
            cout << "Saliendo del sistema de plantas...";
            break;
        default:
            cout << "\nOpcion no valida.";
            system("pause");
            break;
        }
    } while (choice != '3');
}