#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Evento {
public:
    Evento(const string& nombre, const string& fecha) : nombre(nombre), fecha(fecha) {}

    string getNombre() const {
        return nombre;
    }

    string getFecha() const {
        return fecha;
    }

    void agregarAsistente(const string& asistente) {
        asistentes.push_back(asistente);
    }

    vector<string> getAsistentes() const {
        return asistentes;
    }

private:
    string nombre;
    string fecha;
    vector<string> asistentes;
};

bool esFechaValida(const string& fecha) {
    if (fecha.size() != 10) {
        return false;
    }

    int d = stoi(fecha.substr(0, 2));
    int m = stoi(fecha.substr(3, 2));
    int a = stoi(fecha.substr(6, 4));

    if (d < 1 || d > 31 || m < 1 || m > 12 || a < 0) {
        return false;
    }

    return true;
}

int main() {
    vector<Evento> eventos;

    char opcion;
    do {
        cout<<"MENU"<<endl;
        cout<<"a) Agregar un nuevo evento"<<endl;
        cout<<"b) Agregar asistentes a un evento"<<endl;
        cout<<"c) Mostrar lista de asistentes de un evento en orden alfabetico"<<endl;
        cout<<"d) Buscar eventos por fecha"<<endl;
        cout<<"e) Salir"<<endl;
        cout<<"Ingrese una opcion______ ";
        cin>>opcion;

        if (opcion == 'a') {
            string nombre, fecha;
            cout << "Ingrese el nombre del evento: ";
            cin.ignore();
            getline(cin, nombre);
            cout<<"Ingrese la fecha del evento (dd/mm/yyyy): ";
            cin>>fecha;

            if (!esFechaValida(fecha)) {
                cout<<"Fecha invalida. El evento no se agregó"<<endl;
                }
                else{
                    Evento evento(nombre, fecha);
                    eventos.push_back(evento);
                    cout<<"Evento agregado correctamente"<<endl; 
                }
        }
        else if (opcion == 'b') {
            string nombreEvento;
            cout<<"Ingrese el nombre del evento al que desea agregar asistentes: ";
            cin.ignore();
            getline(cin, nombreEvento);

            auto it = find_if(eventos.begin(), eventos.end(), [&](const Evento& evento) {
                return evento.getNombre() == nombreEvento;
            });

            if (it == eventos.end()) {
                cout<<"Evento no encontrado"<<endl;
            }
            else {
                int numAsistentes;
                cout<<"Ingrese el numero de asistentes que desea agregar: ";
                cin>>numAsistentes;

                cout<<"Ingrese los nombres de los asistentes"<<endl;
                for (int i = 0; i < numAsistentes; ++i) {
                    string nombreAsistente;
                    cin.ignore();
                    getline(cin, nombreAsistente);
                    it->agregarAsistente(nombreAsistente);
                }
                cout<<"Asistentes agregados correctamente"<<endl;
            }
        }
        else if (opcion == 'c') {
            string nombreEvento;
            cout << "Ingrese el nombre del evento del cual desea mostrar la lista de asistentes: ";
            cin.ignore();
            getline(cin, nombreEvento);

            auto it = find_if(eventos.begin(), eventos.end(), [&](const Evento& evento) {
                return evento.getNombre() == nombreEvento;
            });

            if (it == eventos.end()) {
                cout<<"Evento no encontrado"<<endl;
            }

            vector<string> asistentes = it->getAsistentes();
            sort(asistentes.begin(), asistentes.end());

            cout<<"Lista de asistentes del evento '"<<nombreEvento<<endl;
            for (const string& asistente : asistentes) {
                cout<<"- " <<asistente<<endl;
            }
        }
        else if (opcion == 'd') {
            string fecha;
            cout << "Ingrese la fecha para buscar eventos (dd/mm/yyyy): ";
            cin.ignore();
            getline(cin, fecha);

            if (!esFechaValida(fecha)) {
                cout<<"Fecha invalida"<<endl;
            }
            else {
                vector<Evento> eventosEnFecha;
                for (const Evento& evento : eventos) {
                    if (evento.getFecha() == fecha) {
                        eventosEnFecha.push_back(evento);
                    }
                }

                if (eventosEnFecha.empty()) {
                    cout<<"No se encontraron eventos en la fecha especificada."<<endl;
                }
                else {
                    cout<<"Eventos en la fecha '"<<fecha<<endl;
                    for (const Evento& evento : eventosEnFecha) {
                        cout<<"- " <<evento.getNombre()<<endl;
                    }
                }
            }
        }
        else if (opcion == 'e') {
            cout<<"ADI0S"<<endl;
        }
        else {
            cout<<"ERR0R...Intentar nuevamente"<<endl;
        }

        cout<<endl;
    } while (opcion != 'e');
    return 0;
}
