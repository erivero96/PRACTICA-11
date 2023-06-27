#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contacto 
{
    public:
        string nombre;
        int numero;
        string correo;

        Contacto() { }
        Contacto(string nombre, int numero, string correo) {
            this->nombre = nombre;
            this->numero = numero;
            this->correo = correo;
        }
};

class Telefono 
{
    private:
        vector <Contacto> contactos;

    public:
        Telefono() { }
        Telefono& agregarContacto(Contacto& x) {
            contactos.push_back(x);
            return *this;
        }

        bool buscarContacto(const string& x) {
            for(auto it = contactos.begin(); it!= contactos.end(); ++it) {
                if(it->nombre == x) {
                    cout << "Contacto Encontrado" << endl;
                    cout << "Numero: " << it->numero << endl;
                    cout << "Correo: " << it->correo << endl;
                    return true;
                }
            }
            cout << "No se encontro el contacto" << endl;
            return false;
        }

        void actualizarInformacion(const string& x) {
            if(Telefono::buscarContacto(x) == true) {
                for(auto it = contactos.begin(); it != contactos.end(); ++it) {
                    if (it->nombre == x) {
                        char opc;
                        cout << "           Actualizar Informacion " << it->nombre <<"           " << endl;
                        cout << "1. Numero " << endl;
                        cout << "2. Correo " << endl;
                        cout << "3. Ambos " << endl;
                        cout << "Ingrese una opcion: ";
                        cin >> opc;
                        switch (opc)
                        {
                            case '1' : {
                                int n;
                                cout << "Ingrese el numero: "; 
                                cin >> n;
                                it->numero = n;
                                break;
                            }
                            case '2' : {
                                string c;
                                cout << "Ingrese el correo: ";
                                cin >> c;
                                it->correo = c;
                                break;
                            }
                            case '3' : {
                                int n;
                                string c;

                                cout << "Ingrese el numero: "; 
                                cin >> n;
                                it->numero = n;                           
                                cout << "Ingrese el correo: ";
                                cin >> c;
                                it->correo = c;
                                break;
                            }
                            default: {
                                cout << "Ingreso una opcion incorrecta" << endl;
                                break;
                            }

                        }
                    }
                    
                }
                
            }
        }

        void ordenarContactos() {
            for (auto it = contactos.begin(); it != contactos.end(); it++) {
                for (auto ite = it + 1; ite != contactos.end(); ite++) {
                    if (it->nombre > ite->nombre) {
                        swap(*it, *ite);
                    }
                }
            }
        }

        void mostrarContactos() {
            cout << "Contactos en el teléfono:" << endl;
            for (auto it = contactos.begin(); it != contactos.end(); it++) {
                cout << "Nombre: " << it->nombre << endl;
                cout << "Número: " << it->numero << endl;
                cout << "Correo: " << it->correo << endl;
                cout << "-----------------------" << endl;
            }
        }

 
    
};
int main() {
    Contacto c1("Abel", 934589333 , "abelperez@gmail.com");
    Contacto c2("Bryan", 987654321 , "bryangomez@gmail.com");
    Contacto c3("Cesar", 912345678 , "cesarlopez@gmail.com"); 

    Telefono telefono;

    telefono.agregarContacto(c3).agregarContacto(c1).agregarContacto(c2);
    
    char opcion;
    do {
        cout << "----- Menú -----" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Buscar contacto" << endl;
        cout << "3. Actualizar información de contacto" << endl;
        cout << "4. Ordenar contactos" << endl;
        cout << "5. Mostrar contactos" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                string nombre, correo;
                int numero;

                cout << "Ingrese el nombre del contacto: ";
                cin.ignore();
                getline(cin, nombre);

                cout << "Ingrese el número del contacto: ";
                cin >> numero;

                cout << "Ingrese el correo del contacto: ";
                cin.ignore();
                getline(cin, correo);

                Contacto nuevoContacto(nombre, numero, correo);
                telefono.agregarContacto(nuevoContacto);
                cout << "Contacto agregado exitosamente." << endl;
                break;
            }
            case '2': {
                string nombre;
                cout << "Ingrese el nombre del contacto a buscar: ";
                cin.ignore();
                getline(cin, nombre);
                telefono.buscarContacto(nombre);
                break;
            }
            case '3': {
                string nombre;
                cout << "Ingrese el nombre del contacto a actualizar: ";
                cin.ignore();
                getline(cin, nombre);
                telefono.actualizarInformacion(nombre);
                break;
            }
            case '4': {
                telefono.ordenarContactos();
                cout << "Los contactos han sido ordenados." << endl;
                break;
            }
            case '5': {
                telefono.mostrarContactos();
                break;
            }
            case '0': {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
            }
        }
        cout << "-----------------------" << endl;
    } while (opcion != '0');

    return 0;
}
