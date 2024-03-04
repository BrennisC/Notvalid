#include <iostream>
#include <vector>
using namespace std;
class Abono
{
private:
    vector<string> name_fertilizan;
    vector<float> price_fertilizan;

public:
    Abono() : name_fertilizan(), price_fertilizan() {}
    // Registro de plantas para el sistema de la vivero UNAS
    void RegistarFertilizan();
    // Mostrar los elementos registratos
    void ShowFertilizan();
    // Guardar los plantas en un TXT
    void SaveFertilizan();
    // Cargar para ver en el TXT
    void LoadFertilizan();
    // Modificar de las plantas
    friend void modifyFertilizan(Abono &);
    // Funcion para agrupar todos los metodos
    friend void BusquedaEnlazadaAbono();
};
void Abono::RegistarFertilizan()
{
    int cantidad;
    cout << "Ingresa la cantidad de abonos: ";
    cin >> cantidad;
    for (int i = 0; i < cantidad; i++)
    {
        string name;
        cout << "Ingrese el nombre del  fertilizante: ";
        getline(cin, name);
        name_fertilizan.push_back(name);
        float precio;

        cout << "Ingrese el precio del abono : ";
        cin >> precio;
        price_fertilizan.push_back(precio);
    }
}
void Abono::ShowFertilizan()
{
    for (size_t i = 0; i < name_fertilizan.size(); i++)
    {
        float total;
        cout << "NOMBRE PLANTA: " << name_fertilizan[i];
        cout << "\nPRECIO PLANTA: $" << price_fertilizan[i] << endl;
        for (auto price : price_fertilizan)
        {
            total = static_cast<float>(price);
        }
        cout << "TOTAL DEL ABONO: $" << total << endl;
        cout << "-----------------------------" << endl;
    }
}
void BusquedaEnlazadaAbono()
{
    char choice;
    Abono ab;
    do
    {
        cout << "[1]REGISTRAR EL ABONO: \n";
        cout << "[2]REGISTRAR EL PRECIO: \n";
        cout << "INGRESAR UNA OPCION: \n\n";
        cin.getline(&choice, 3, sizeof(char));
        switch (choice)
        {
        case '1':
            Sleep(30000); // Espera de 30 segundos
            system("cls");
            ab.RegistarFertilizan();
            break;
        case '2':
            Sleep(30000);
            system("cls");
            ab.ShowFertilizan();
            getchar();
            break;
        case '3':
            cout << "saliendo...";
            break;
        default:
            cout << "Ocpion no valida intentalo de nuevo ";
            break;
        }
    } while (choice != '3');
}