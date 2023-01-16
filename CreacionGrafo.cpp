#include <iostream>
using namespace std;

class grafo {
private:
	int** matriz;  //matriz dinámica
	int ren;
	int col;

public:
	grafo(int ren, int col) {
		this->ren = ren;
		this->col = col;
		matriz = new int*[ren];
		for (int i = 0; i < col; i++) {
			matriz[i] = new int[col];
		}
		for (int i = 0; i < ren; i++) {
			for (int j = 0; j < ren; j++) {
				*(*(matriz+i)+j) = 0;
			}
		}
	} 
								
	void llenarGrafoDirigido() {
		int* aux = new int[ren];
		char change;
		for (int i = 0; i < ren; i++) {  //almacena los vertices en un vector
			cout << endl << "\tNodo " << i << ": ";
			cin >> change;
			aux[i]=int(change);
		}
		int op = 0, resp = 0;
		char verticeInicial = '0', verticeFinal = '0';
		do {
			cout << endl << "\tNodo Inicio: ";
			cin >> verticeInicial;
			cout << endl << "\tNodo Final: ";
			cin >> verticeFinal;
			for (int j = 0; j < ren; j++) {		//Compara con la posiscion del vector y lo posiciona en la matriz
				if (aux[j] == int(verticeInicial)) {
					for (int k = 0; k < col; k++) {
						if (aux[k] == int(verticeFinal)) {
							matriz[j][k] = 1;
							j = k = 0;
							break;
						}
					}
					break;
				}
			}
			cout << endl << "\tDeseas agregar otra coneccion?  SI=1  NO=0  : ";
			cin >> resp;
		} while (resp != 0);
	}

	void llenarGrafoNoDirigido() {
		int* aux = new int[ren];
		char change;
		for (int i = 0; i < ren; i++) {  //almacena los vertices en un vector
			cout << endl << "\tNodo " << i << ": ";
			cin >> change;
			aux[i] = int(change);
		}
		int op = 0, resp = 0;
		char verticeInicial = '0', verticeFinal = '0';
		do {  
			cout << endl << "\tNodo Inicio: ";
			cin >> verticeInicial;
			do {
				cout << endl << "\tNodo Final: ";
				cin >> verticeFinal;
				for (int j = 0; j < ren; j++) {		//Compara con la posiscion del vector y lo posiciona en la matriz
					if (aux[j] == int(verticeInicial)) {
						for (int k = 0; k < col; k++) {
							if (aux[k] == int(verticeFinal)) {
								matriz[j][k] = 1;
								matriz[k][j] = 1;
								j = k = 0;
								break;
							}
						}
						break;
					}
				}
				cout << endl << "\tTiene otra arista?  SI=1  NO=0  : ";
				cin >> op;
			} while (op != 0);
			cout << endl << "\tDeseas agregar otra coneccion?  SI=1  NO=0  : ";
			cin >> resp;
		} while (resp != 0);
	}
	void imprimir() {
		cout << endl << "\tMATRIZ DE ADYACENCIA" << endl;
		for (int i = 0; i < ren; i++) {
			cout << "\t\t(";
			for (int j = 0; j < ren; j++) {
				cout << matriz[i][j] << " ";
			}
			cout << ")" << endl;
		}
	}
	~grafo() {//elimina la matriz, uso de delte
		this->ren = 0;
		this->col = 0;
		delete(matriz);
	}  
};

int main() {
	int ren, col;
	cout << endl << endl << "\tCuantos nodos tiene el grafo: ";
	cin >> ren;
	col = ren;
	grafo grafo1(ren, col);

	char resp;
	cout << endl << "\tEs grafo dirigido? s/n: ";
	cin >> resp;

	if (resp == 's' || resp == 'S') {
		grafo1.llenarGrafoDirigido();
	}
	else {
		grafo1.llenarGrafoNoDirigido();
	}
	cout << endl << endl;
	grafo1.imprimir();
}