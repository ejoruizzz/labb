#include <iostream>
#include <list>
using namespace std;
class DiasSeman {
private:
    list<string> dias;
public:
    DiasSeman() {
        dias = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    }
    void mostrarDias() {
        system("cls");
        cout << "Dias de la semana:" << endl;
        int posicion = 1;
        for (list<string>::const_iterator dia = dias.begin(); dia != dias.end(); ++dia) {
            cout << posicion << ". " << *dia << endl;
            posicion++;
        }
        cout << "===============================" << endl;
    }
    void buscarPosicion() {
        system("cls");
        string diaBuscado;
        cout << "Ingrese el dia de la semana: ";
        cin >> diaBuscado;
        
        int posicion = 1;
        for (list<string>::const_iterator dia = dias.begin(); dia != dias.end(); ++dia) {
            if (*dia == diaBuscado) {
                cout << "El dia " << diaBuscado << " esta en la posicion " << posicion << " en la lista." << endl;
                return;
            }
            posicion++;
        }
        cout << "El dia ingresado no es valido." << endl;
        cout << "===============================" << endl;
    }
};
void menu(DiasSeman& diasSeman) {
    int opcion;
    while (true) {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Mostrar todos los dias" << endl;
        cout << "2. Buscar posicion de un dia" << endl;
        cout << "3. Salir" << endl;
        cout << "Escriba la opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            diasSeman.mostrarDias();
            break;
        case 2:
            diasSeman.buscarPosicion();
            break;
        case 3:
            return;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }
}
int main() {
    DiasSeman diasSeman;
    menu(diasSeman);
    return 0;
}