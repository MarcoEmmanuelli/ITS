#include <iostream>
using namespace std;
int main(){
	string nome1,nome2,nome3;
	cout << "inserisci il primo nome: ";
	getline(cin,nome1);
	cout << "inserisci il secondo nome: ";
	getline(cin,nome2);
	cout << "inserisci il terzo nome: ";
	getline(cin,nome3);

	cout <<"stampa dei nomi in ordine alfabetico:"<<endl;
	nome1,nome2,nome3
	if (nome1<nome2 ){
		cout << nome1 <<endl<<nome2<<endl;

	}else{
		cout << nome2 <<endl<<nome1<<endl;
	}
	
}

