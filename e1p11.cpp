#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Producto {
public:
	int codigo;
	string descripcion;
	int cantidad;
	
	Producto(int codigo, const string& descripcion, int cantidad)
		: codigo(codigo), descripcion(descripcion), cantidad(cantidad) {}
};

void agregarProducto(vector<Producto>& inventario) {//funcion para agregar productos al vector de producots
	int codigo;
	string descripcion;
	int cantidad;
	cout << "----------------------" << endl;
	
	cout << "Ingrese el codigo del producto: ";
	cin >> codigo;
	
	cout << "Ingrese la descripcion del producto: ";
	getline(cin, descripcion);
	
	cout << "Ingrese la cantidad disponible: ";
	cin >> cantidad;
	
	Producto producto(codigo, descripcion, cantidad);
	inventario.push_back(producto);
	cout << "----------------------" << endl;
	cout << "Producto agregado al inventario." << endl;
	cout << "----------------------" << endl;
	
}

void actualizarCantidad(vector<Producto>& inventario) {//funcion para cambiar la cantidad de un producto
	int codigo;
int cantidad;

cout << "Ingrese el codigo del producto: ";
cin >> codigo;

for (auto& producto : inventario) {
	if (producto.codigo == codigo) {
		cout << "Ingrese la nueva cantidad disponible: ";
		cin >> cantidad;
		
		producto.cantidad = cantidad;
		
		cout << "Cantidad actualizada." << endl;
		return;
	}
}
cout << "----------------------" << endl;
cout << "Producto no encontrado." << endl;
cout << "----------------------" << endl;

}

void buscarProducto(const vector<Producto>& inventario) {//Funcion para buscar un producto por el codigo
	int codigo;

cout << "----------------------" << endl;
cout << "Ingrese el codigo del producto: ";

cin >> codigo;

for (const auto& producto : inventario) {
	if (producto.codigo == codigo) {
		cout << "----------------------" << endl;
		cout << "Descripcion: " << producto.descripcion << endl;
		cout << "Cantidad disponible: " << producto.cantidad << endl;
		cout << "----------------------" << endl;
		return;
	}
}
cout << "----------------------" << endl;
cout << "Producto no encontrado." << endl;
cout << "----------------------" << endl;
}

void mostrarProductos(const vector<Producto>& inventario) {
	cout << "----------------------" << endl;
	cout << "Lista de productos:" << endl;
	cout << "----------------------" << endl;
	
	vector<Producto> copiaInventario = inventario;
	
	sort(copiaInventario.begin(), copiaInventario.end(),
		 [](const Producto& p1, const Producto& p2) {
			 return p1.descripcion < p2.descripcion;
		 });
	
	for (const auto& producto : copiaInventario) {
		cout << "----------------------" << endl;
		cout << "Codigo: " << producto.codigo << endl;
		cout << "Descripcion: " << producto.descripcion << endl;
		cout << "Cantidad disponible: " << producto.cantidad << endl;
		cout << "----------------------" << endl;
		cout << endl;
	}
}

int main() {
	vector<Producto> inventario;
	
	Producto producto1(1, "Camisa", 10);
	Producto producto2(2, "Pantalon", 5);
	Producto producto3(3, "Zapatos", 8);
	
	inventario.push_back(producto1);
	inventario.push_back(producto2);
	inventario.push_back(producto3);
	
	
	char opcion;
	
	do {
		cout << "=== Sistema de Inventario ===" << endl;
		cout << "a) Agregar producto" << endl;
		cout << "b) Actualizar cantidad" << endl;
		cout << "c) Buscar producto" << endl;
		cout << "d) Mostrar lista de productos" << endl;
		cout << "e) Salir" << endl;
		cout << "Ingrese una opcion: ";
		
		cin >> opcion;
		
		switch (opcion) {
		case 'a':
			agregarProducto(inventario);
			break;
		case 'b':
			actualizarCantidad(inventario);
			break;
		case 'c':
			buscarProducto(inventario);
			break;
		case 'd':
			mostrarProductos(inventario);
			break;
		case 'e':
			cout << "Saliendo del programa...." << endl;
			break;
		default:
			cout << "Operacion invalida. Intente de nuevo." << endl;
		}
		cout << endl;
	} while (opcion != 'e');
	
	return 0;
}
