// prendere due nomi e due date di nascita di due persone e stampare 
// in ordine alfabetico di data o di nome su richiesta di input
// stampare sempre i 2 nomi e le 2 date secondo l'ordine richiesto 

// si deve utilizzare la data nel formato aaaa/mm/gg per il confronto
//	"10/11/2020"< 12/11/2019"

// 1. prendere un nome e una data di nascita in input da tastiera
// 2. prendere un secondo nome e una seconda data di nascita da tastiera
// 3. chiedere all'utente se vuola la stampa in ordine di nome o di data
// 4. esempio: inserire  1 per avere ordine di data; inserire 2 per avere ordine di nome
// 5. se è stato inserito 1 stampare data e nome delle due persone in ordine di data crescente
// 6. se è stao inserito 2 stampare nome e data delle due persone in ordine di nome 
#include <iostream>
using namespace std;
int main() {
	string n1;
	string n2;
	string d1;
	string d2;
	string modo;
	cout << "inserisci primo nome"<< endl;
	getline(cin,n1);
	cout << "inserisci prima data di nascita (aaaa/mm/gg )"<<endl;
	getline(cin, d1);
	cout << "inserisci secondo nome"<<endl;
	getline(cin,n2);
	cout << "inserisci seconda data di nascita (aaaa/mm/gg )"<<endl;
	getline(cin, d2);
	cout << "\n in che ordine li vuoi visualizzare; scrivi A se li vuoi \
	per ordine alfabetico o B se li vuoi visualizzare \
	in ordine di data di nascita"<<endl;
	cin >> modo;
	if (modo == "A") {
		if (n1 < n2) {
			cout << n1 << " " << d1 << " " << n2 << " " << d2;
		} else {
			cout << n2 << " " << d2 << " " << n1 << " " << d1;
		}
	} else {
		if (d1 < d2) {
			cout << n1 << " " << d1 << endl << n2 << " " << d2;
		} else {
			cout << n2 << " " << d2 << endl << n1 << " " << d1;
		}
	}
	return 0;
} 
