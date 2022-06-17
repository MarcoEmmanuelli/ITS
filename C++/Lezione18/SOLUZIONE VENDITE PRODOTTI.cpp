#include <iostream>
#include <cstdlib>
#include <ctime>
#include "controlloinput.h"
using namespace std;
#define maxcol 100
#define maxriga 20

double leggi_input(double n){
	bool in;
	do{
		in=true;
		cout <<" inserisci il valore: "<<endl;
		cin >> n;
		if (n<0){
			cout << "valore non può essere negativo!!"<<endl;
		}
		if(controlloinputnumerico()==false){ // serve ad eliminare il cout di controlloinput()
			cout << "valore errato!! inserisci un numero"<<endl;			
			in=false;	
		}

	}while(in==false || n<0);
	return n;
}

void CaricaNumeriRandom(int m[][maxcol],int numProd,int numGiorni){
	int i,j;
	
	for(i=0;i<numProd;i++){
		for(j=0;j<numGiorni;j++){
			m[i][j]=rand()%100;
		}
	}
}
void StampaMatriceVendite(int mat[][maxcol],int prodotti,int giorni){
	for(int i=0;i<prodotti;i++){
		for(int j=0;j<giorni;j++){
			cout<<mat[i][j];
			cout<<"\t";
		}
	cout<<endl;
	}
}
double mediaprodotto(int m[][maxcol], int numProd, int numGiorni, int indice){
	int somma=0;
	double media;
	for (int i=0 ; i<numGiorni ; i++){
		somma=somma+m[indice][i];
	}
	media=somma/numGiorni;
	return media;
}

double MediaGiorno(int Mat[][maxcol],int NumeroGiorni,int NumeroProdotti,int IndiceGiorno){
	int Somma=0;
	double Media=0;
	for(int i=0;i<NumeroProdotti;i++){
		Somma=Somma+Mat[i][IndiceGiorno];
	}
	Media=Somma/NumeroProdotti;
	return Media;
}
void Stampa_indici(int mat[][maxcol],int prodotti,int giorni, int numvendite){
	for(int i=0;i<prodotti;i++){
		for(int j=0;j<giorni;j++){
			if(mat[i][j]==numvendite){
				cout<<"prodotto: "<<i+1<<" giorno: "<<j+1;
				cout<<"\n";
			}
		}
	}
	cout<<endl;
}

void stampaArray(int array[], int dim){
	for (int i=0 ; i < dim; i++){
		cout << array[i] <<"\t";
	}
	cout << endl;
}

void caricavenditeprodotto(int mat[][maxcol],int prodotti,int giorni,int vendite[maxcol], int num){
	for(int i=0;i<prodotti;i++){
		for(int j=0;j<giorni;j++){
//			mat[num][j]==num){
//				cout<<"prodotto: "<<i+1<<" giorno: "<<j+1;
//				cout<<"\n";
				vendite[j]=mat[num][j];
			}

		}

}

void ord_insertion(int arr[],int dim){
	for (int i = 0; i<dim-1; i++) {
		for (int j=i+1; j<dim ; j++) {
			if (arr[i]>arr[j]) {
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	return;
}

void copiaprimixy(int mat[][maxcol],int matcopia[][maxcol],int x,int y){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
				matcopia[i][j]=mat[i][j];
			}
	}	
}
//ordina matrice per righe con  con il metodo per inserzione
void ordinarighe(int matcopia[][maxcol],int x,int y){
	for(int k=0; k<x;k++){ // k=indice di riga 
		// ordinamento per inserzione applicato alla singola riga
		for (int i = 0; i<y-1; i++) {
			for (int j=i+1; j<y ; j++) {
				if (matcopia[k][i]>matcopia[k][j]) {
					int temp=matcopia[k][i];
					matcopia[k][i]=matcopia[k][j];
					matcopia[k][j]=temp;
				}
			}
		}	
		// fine ordinamento per inserzione
	}
}

int main() {
	setlocale(LC_ALL, "Italian");
	srand(time(NULL));

	int mat[maxriga][maxcol]; // 20 prodotti e 100 giorni
	int matcopia[maxriga][maxcol];

	double giorni;
	double prodotti;
	double indice;
	double media;
	double AvgGiorno;
	double IndiceGiorno;
	double numvendite;
	double numprodotto;
	
	cout<<"** programma per la gestione delle medie giornaliere dei prodotti ******"<<endl<<endl;
	cout<<"Inserisci il numero dei prodotti (max 20)"<<endl;
	prodotti=leggi_input(prodotti);
	cout<<"Inserisci il numero dei giorni (max 100)"<<endl;
	giorni=leggi_input(giorni);

	int i,j;
	CaricaNumeriRandom(mat,prodotti,giorni);
	StampaMatriceVendite(mat,prodotti,giorni);
	cout<<"*** Calcolo media vendite giornaliere di un prodotto: "<<endl;
	cout<<"dammi indice prodotto (1 - "<<prodotti<<"): (ogni riga rappresenta un prodotto) "<<endl;
	indice=leggi_input(indice);
	/*
		dato un indice di un prodotto(quindi data una riga)
		stampare la media dei prodotti giornalieri venduti 
		(stampare la media delle colonne);
	*/


	media= mediaprodotto (mat , prodotti , giorni , indice-1);
	cout<<"la media delle vendite del prodotto è : " << media<<endl;
	/*
		dato l'indice di un giorno(data una colonna) stampare
		la media dei prodotti venduti quel giorno (stampare la
		media delle righe)
	*/
	system("pause");
	cout<<endl<<"*** Calcolo media vendite dei rodotti relative ad un giorno: "<<endl;

	cout<<"dammi un indice del giorno (1 - "<<giorni<<"): (ogni colonna rappresenta un giorno) "<<endl;
	IndiceGiorno=leggi_input(IndiceGiorno);;
/*	Dato un numero di vendite, stampare gli indici del giorno e del prodotto 
	per cui si è verificato quel numero di vendite.
	*/
	
	AvgGiorno=MediaGiorno(mat,giorni,prodotti,IndiceGiorno-1);
	cout<<"La media delle vendite dei prodotti e' : "<<AvgGiorno<<endl;
	cout <<"Calcolo e stampa degli indici del giorno e del prodotto per "
			"cui si è verificato quel numero di vendite"<<endl;
	cout <<"dammi il numero di vendite (1 - 100)"<<endl;
	numvendite=leggi_input(numvendite);
	cout << "giorni e prodotti che hanno avuto una vendita pari a :"<<numvendite<<endl;
	Stampa_indici(mat , prodotti , giorni,numvendite);
	/*
	Dato un prodotto generare un vettore che rappresenta solo le vendite
	 di quel prodotto nei giorni considerati.
	 */
	cout << "vendite di un prodotto :\n";
	cout << "inserisci il numero del prodotto di cui vuoi le vendite\n";

	numprodotto=leggi_input(numprodotto);	
	int vendite[maxcol];
	caricavenditeprodotto(mat,prodotti , giorni,vendite,numprodotto-1);
	cout << "\nvendite del prodotto "<<numprodotto<<" :\n";
	
	stampaArray(vendite,giorni);
	// ordinare vettore 
	ord_insertion(vendite,giorni);
	cout << "vendite del prodotto "<<numprodotto<<" ordinato crescente :\n";
	stampaArray(vendite,giorni);
	/*Dati x numeri di prodotti e y numeri di giorni, creare un'altra matrice 
	con i primi x prodotti e i primi y giorni
	*/
	cout << "creo matrice dei primi x prodotti e dei primi y giorni\n";
	cout << "inserisci il valore di x:\n";
	double x;
	x=leggi_input(x);
//	cin >>x;
	cout << "inserisci il valore di y:\n";
	double y;
	y=leggi_input(y);
//	cin >>y;
	copiaprimixy(mat,matcopia,x,y);
	cout << "stampa vendite dei primi "<<x<<" prodotti e dei primi "<<y <<" giorni\n";	
	StampaMatriceVendite(matcopia,x,y);	
	cout << "ordinamento per righe della matrice dei primi "<<x<<" prodotti e dei primi "<<y <<" giorni\n";
	ordinarighe(matcopia,x,y);
	StampaMatriceVendite(matcopia,x,y);	
	return 0;
		
}


