#include <iostream>
bool controlloInput(int n){

	bool r=true;
		using namespace std;
	if(cin.fail() ){ // caso di input che è completamente errato 
//		cout << "Errore! inserimento errato !!!! \n";
		cin.clear(); // resetta lo stato dello stream 
		// uso di ignore() cancella dallo steam input 1000 caratteri fino a \n; 
		//se lo uso senza parametri, es:cin.ignore(), cancella solo un carattere
		cin.ignore(1000,'\n'); 
		r=false;
	}else{ 	// caso di input parzialmente errato ma che cin lo prende corretto, es: 123abc prende 123, ma l'input è errato
			// permette di ignorare i caratteri errati dopo l'input, es: 123abc, ignora i caratteri abc;
		cin.ignore(1000,'\n');
			// gcount() conteggia i caratteri ignorati es: 123abc, conteggia i caratteri dopo il numero 123
		if((cin.gcount()>1)){
//			cout << "Errore! inserimento errato !!!! \n";
			r=false;
		}
	}
	cin.clear();
	return r;
}
