#include <iostream>
#include <list>
#include <limits>
using namespace std;

class alumno {
private:
    string nombre;
    string apellido;
    double promedio;

public:
    alumno(string xnombre, string xapellido, double xpromedio) {
        nombre = xnombre;
        apellido = xapellido;
        promedio = xpromedio;
    }

    string getnombre() const {
        return nombre;
    }

    void setnombre(string xnombre) {
        nombre = xnombre;
    }

    string getapellido() const {
        return apellido;
    }

    void setapellido(string xapellido) {
        apellido = xapellido;
    }

    double getpromedio() const {
        return promedio;
    }

    void setpromedio(double xpromedio) {
        promedio = xpromedio;
    }


    void mostrar() const {
        cout << "Nombre: " << nombre << ", Apellido: " << apellido << ", Promedio: " << promedio << endl;
    }
};

list<alumno> alumnos;

void agregar() {
    system("cls");
    string xnombre;
    string xapellido;
    int n1, n2;
    double promedio;

    cout << "Escriba los datos del alumno" << endl;
    cout << "Escriba el nombre: ";
    cin >> xnombre;
    cout << "Escriba el apellido: ";
    cin >> xapellido;
    cout << "Escriba la nota 1: ";
    cin >> n1;
    cout << "Escriba la nota 2: ";
    cin >> n2;

    promedio = (n1 + n2) / 2.0;

    alumno objalumno(xnombre, xapellido, promedio);
    alumnos.push_back(objalumno);

    system("cls");
}

void mostrar() {
    system("cls");

    if (alumnos.empty()) {
        cout << "La lista esta vacia" << endl;
    } else {
        cout << "Lista de alumnos:" << endl;
        for (const auto& alumno : alumnos) {
            alumno.mostrar();
        }
    }

    cout << "============================================================" << endl;
}

void mostrarPromedioTotal() {
    double suma = 0;
    int contador = 0;

    for (const auto& alumno : alumnos) {
        suma += alumno.getpromedio();
        contador++;
    }

    if (contador > 0) {
        cout << "Promedio total de todos los alumnos: " << suma / contador << endl;
    } else {
        cout << "No hay alumnos para calcular el promedio." << endl;
    }
}

void mostrarNotaExtrema() {
    if (alumnos.empty()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    auto alumnoMayor = alumnos.begin();
    auto alumnoMenor = alumnos.begin();

    for (auto it = alumnos.begin(); it != alumnos.end(); ++it) {
        if (it->getpromedio() > alumnoMayor->getpromedio()) {
            alumnoMayor = it;
        }
        if (it->getpromedio() < alumnoMenor->getpromedio()) {
            alumnoMenor = it;
        }
    }

    cout << "Estudiante con la mayor nota: " << alumnoMayor->getnombre() << " " << alumnoMayor->getapellido() << " - Nota: " << alumnoMayor->getpromedio() << endl;
    cout << "Estudiante con la menor nota: " << alumnoMenor->getnombre() << " " << alumnoMenor->getapellido() << " - Nota: " << alumnoMenor->getpromedio() << endl;
}

void limpiar() {
    system("cls");
    alumnos.clear();
}

void eliminar() {
    int posicion;
    cout << "Seleccione el numero del elemento a eliminar:" << endl;
    cin >> posicion;

    if (posicion < 0 || posicion >= alumnos.size()) {
        cout << "Posición inválida." << endl;
        system("cls");
        return;
    }

    auto p = alumnos.begin();
    advance(p, posicion); 

    cout << "Eliminando a: " << p->getnombre() << " " << p->getapellido() << endl;
    alumnos.erase(p);

    system("cls");
}

void menu() {
    int opcion;

    while (true) {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Agregar persona" << endl;
        cout << "2. Eliminar persona" << endl;
        cout << "3. Mostrar lista de personas" << endl;
        cout << "4. Vaciar lista" << endl;
        cout << "5. Mostrar promedio total de todos los alumnos" << endl;
        cout << "6. Mostrar el estudiante con la mayor y menor nota" << endl;
        cout << "7. Salir" << endl;
        cout << "Escriba la opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregar();
            break;
        case 2:
            eliminar();
            break;
        case 3:
            mostrar();
            break;
        case 4:
            limpiar();
            break;
        case 5:
            mostrarPromedioTotal();
            break;
        case 6:
            mostrarNotaExtrema();
            break;
        case 7:
            return; 
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
            break;
        }
    }
}

int main() {
    menu();
    return 0;
}
