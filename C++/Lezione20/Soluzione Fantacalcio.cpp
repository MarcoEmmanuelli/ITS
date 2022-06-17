#include <iostream>

using namespace std;
int n=10;

struct allenatore{
	string nome,cognome;
	int titoli;
};

struct squadra{
	string nome,colore;
	int punteggio;
	allenatore coach;
};
int inserisciDimensione(int max){
		int dim;
		cout<<"Quanti squadre vuoi inserire? (1- " << max << ")" <<endl;
		cin >> dim;
		return dim;
		fflush(stdin);
}
void inserimento(squadra V[],int n){ 
	for(int i=0; i<n;i++){ 
		cout <<"--- Dati squadra "<<i+1<<"---"<<endl;
		cout<<"Inserire nome della squadra: ";
		getline(cin, V[i].nome);
		cout<<"Inserire colore della squadra: ";
		getline(cin, V[i].colore);
		cout<<"Inserire il punteggio: ";
		cin>>V[i].punteggio;
		fflush(stdin);
		cout<<"Inserire il nome dell'allenatore: ";
		getline(cin, V[i].coach.nome);
		cout<<"Inserire il cognome dell'allenatore: ";
		getline(cin, V[i].coach.cognome);
		cout<<"Inserire il numero di titoli dell'allenatore': ";
		cin>>V[i].coach.titoli;
		fflush(stdin);
		cout<<endl;
	}
}

void StampaAllenatoriSquadresup30(squadra V[],int n){ //
	for(int i=0; i<n;i++){ //
		if(V[i].punteggio>30){
		cout<<"---------------------"<<endl;	
		cout<<"|Cognome: "<<V[i].coach.cognome<<"|"<<endl;
		}
	}
	cout<<"---------------------"<<endl;
	cout<<endl<<endl;
}

int ContaAllenatorisup1(squadra V[],int n){ //
	int cont;
	for(int i=0; i<n;i++){ //
		if(V[i].coach.titoli>=1){
			cont++;
		}
	}
	return cont;
}

void StampaAllenatorisup3(squadra V[],int n){ 
	for(int i=0; i<n;i++){ 
		if(V[i].coach.titoli>3){
		cout<<"Nome Squadra: "<<V[i].nome<<"		";
		cout<<"Colore: "<<V[i].colore<<"		";
		cout<<"Punti: "<<V[i].punteggio<<"		";
		cout<<"Nome Allenatore: "<<V[i].coach.nome<<"		";
		cout<<"Cognome Allenatore: "<<V[i].coach.cognome<<"		";
		cout<<"Titoli: "<<V[i].coach.titoli<<endl;
		}
	}
}

int main(){
	setlocale(LC_ALL, "Italian");
	squadra V[n];
	cout << "************ Gestione fantacalcio ********* "<<endl<<endl;
	cout<<"Numero massimo di squadre che si vuole gestire:"<<endl;
	n=inserisciDimensione(n);
	fflush(stdin);

	cout << "-- Inserimento dati delle Squadre -- " << endl;
	inserimento(V,n);
	cout<<endl;
	system("pause");
	
    cout<<endl;
	cout<<"Ecco i cognomi degli allenatori con squadre superiori a 30 punti:"<<endl; 
	StampaAllenatoriSquadresup30(V,n);
	cout<<endl;
	system("pause");
    
	cout<<endl;
	cout<<"Il numero di allenatori che hanno vinto almeno un titolo è : "<<ContaAllenatorisup1(V,n)<<endl<<endl<<endl;
	cout<<endl;
	system("pause");
    cout<<endl;
	cout<<"Le squadre con allenatore possessore di piu' di 3 titoli: "<<endl;
	StampaAllenatorisup3(V,n);
}
