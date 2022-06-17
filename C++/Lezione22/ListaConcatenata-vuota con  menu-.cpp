/* 	Creazione di una LISTA CONCATENATA di numeri interi utilizzando i puntatori. 
	il programma prevede di utilizzare solo il puntatore di testa .
	NON è previsto un puntatore di coda.	
*/

#include <iostream>
#include "controlloinput.h"
using namespace std;
// dichiaro la struttura del nodo generico della LISTA CONCATENATA


// funzione che crea un menu per utilizzare le varie opzioni  
int stampa_menu(){
	int scelta;
	system("cls");
	cout << endl; 
	cout << " COSTRUZIONE DI UNA *** LISTA CONCATENATA ***  CON I PUNTATORI"<< endl<< endl << endl;
	cout << "1.  " << endl; 
	cout << "2. " << endl; 
	cout << "3.  " << endl; 
	cout << "4. " << endl; 
	cout << "5. " << endl;
	cout << "6. " << endl;
	cout << "7. " << endl;
	cout << "8. " << endl;
	cout << "9. " << endl;
	cout << "0. Esci" << endl;  
	cout << endl; 
	cout << "Scelta: "<< endl; 
	cin >> scelta;
	if (controlloInput(scelta) == false){
		scelta=-1;
	}	
	if (!(scelta <=9 && scelta >=0) ){
	
		cout << "scelta errata" << endl;
		system("pause");
		scelta=-1;
	}	
		
	return scelta;
	
}


// programma principlae 
int main(){
	do{
	  s=	stampa_menu();
	  if (s<=9 && s>=0){
		  switch (s) { 
				case 1: 
					cout<<"1. "<<endl;
					system ("pause");					
					break;
				case 2: 
					cout << "2. "<<endl;
					system ("pause");
					break; 
				case 3: 
					cout << "3.  " << endl; 
					system("pause");
					break; 
				case 4: 
					cout << "4. " << endl; 
					system("pause");
					break;
				case 5: 
					cout << "5. " << endl;
					system("pause");
					break;
				case 6: 
					cout << "6. " << endl;
					system("pause");
					break;
				case 7: 
					cout << "7. " << endl;
					system("pause");
					break;
				case 8: 
					cout << "8." << endl;
			
					system("pause");
					break; 
				case 9: 
					cout << "9. " << endl;
					system("pause");
					break; 
				case 0: 
					cout<<"Esci"<<endl;
					break;
				default: 
					cout <<"Scelta non valida"<<endl; 
					break;
			}
		}	
	}while((s!=0));
}
