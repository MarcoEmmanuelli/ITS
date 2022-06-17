#include <iostream>

using namespace std;

struct TipoGara {
  string nome,cognome;
  int numpet;
  double tempo;
};
int pettorina=1; // variabile globale per calcolare il numero di pettorina di ogni partecipante

bool controlloinputnumerico();
int Menu();
double leggi_input(double n);
int inserisciDimensione(int massimo);
void InserisciPersone(TipoGara vetGara[],int dimensione);
TipoGara InputDati();
void orderByTempo(TipoGara vetGara[], int dim);
void scambia(TipoGara &primo, TipoGara &secondo);
void stampaClassifica(const TipoGara vetGara[], int dim);
void visualizzaDatiGara(TipoGara gara);
void stampaVincitore(TipoGara gara);
int RicercaConcorrente(TipoGara vetGara[],int dim,int pet);
void Stampaconcorrente(TipoGara gara);
void StampaelencoTempo(TipoGara vetGara[],int dim,int tempo);


//funzione controllo input numerico
bool controlloinputnumerico(){
	bool in=true;
	if(cin.fail()){ // input completamente errato
			cin.clear();
			cin.ignore(800,'\n');
			in=false;
	}else{ // input parzialmente errato
			cin.ignore(800,'\n');
			if((cin.gcount())>1){
				in=false;
		}
	}
	return in;
}

// FUNZIONE DI CREAZIONE DEL MENU' UTENTE
int Menu(void)
{
	int scelta;
	do{
		system("CLS");
		cout << "\n\n************ Gestione Gara e Concorrenti ********* "<<endl<<endl;
		cout <<"\n\t ********** Menù programma ***********\n";
		cout << "\t 1.Inserimento dati conconrrenti"<<endl;
		cout << "\t 2.Stampa Classifica concorrenti"<<endl;
		cout << "\t 3.Stampa primi 3 classificati"<<endl;
		cout << "\t 4.Posizione finale di un concorrente"<<endl;
		cout << "\t 5.Concorrenti con tempi inferiori"<<endl;
		cout << "\t 6.Fine"<<endl<<endl;
		
 		cout <<"\t Inserire scelta (1, 2, 3, 4,5  oppure 6)   :    ";
		cin>>scelta;		
		if( controlloinputnumerico()==false || (scelta <1 )|| (scelta >6)){
			cout << "\nERRORE!!! Digitare la scelta corretta....\n\n";
			system("PAUSE");
			scelta=0;
		}
	}while ((scelta < 1) || (scelta > 6));
	return scelta;
}

int main(){
	setlocale(LC_ALL, "Italian");
  	int n=10;
  	int pett=0;
  	TipoGara vetGara[n];

	int scelta;
	do{
		    // ripulisco lo schermo
	    system("CLS");
		    // chiamo la funzione che crea il menù utente
	    scelta = Menu();
	    switch (scelta){
		  case 1: 
				cout<<"Numero massimo di concorrenti che si vuole caricare:"<<endl;
				n=inserisciDimensione(n);
				cout << "-- Inserimento dai dei concorrenti -- " << endl;
			  	InserisciPersone(vetGara,n);
			  	cout << "-- Elenco dei concorrenti inseriti -- " << endl;
			  	stampaClassifica(vetGara,n);
			  	break;
	      case 2: 
	      	  	cout << "-- Creo la classifica dei concorrenti -- " << endl;
 				orderByTempo(vetGara,n);
 				cout << "-- Stampa delle classifica dei cocnorrenti in ordine di tempo realizzato -- " << endl;
			  	stampaClassifica(vetGara,n);
			  	break;
	      case 3: 
			    cout << "-- Stampa del podio della gara -- " << endl;
			    if(n<3){
				  	stampaClassifica(vetGara,n);   				    
				}else{
	 			  	stampaClassifica(vetGara,3);
				}
			    stampaVincitore(vetGara[0]);
			  	break;
	      case 4: 
			    cout<<" -- Ricerca di un concorrente in gara e tempo realizzato --"<<endl;
			    cout<<"inserisci numero di pettorina del concorrente da ricercare (1-"<<n<<"): "<<endl;
				do{
					pett=leggi_input(pett);
				}while(pett>n);
			    int pos;
				pos=RicercaConcorrente(vetGara,n,pett);
			    if (pos!=-1){
			    	cout << "il concorrente con pettorina "<<pett<< " si è classificato alla posizione "<<pos+1<<endl;
				}
			  	break;
	      case 5: 
			    cout<<" -- Ricerca elenco concorrenti con tempi più bassi di --"<<endl;
			    cout<<"inserisci tempo da ricercare "<<endl;
				double tempo;
				tempo=leggi_input(tempo);
				StampaelencoTempo(vetGara,n,tempo);
			  	break;
	      case 6:{
		       	 cout <<"\n\nGrazie per aver utilizzato il programma... \n\n";
		        }
		}
		system("PAUSE");
	}while (scelta != 6);
	  
}

	
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

	}while((in==false) || n<0);
	return n;
}

int inserisciDimensione(int max){
		int dim;
		cout<<"Quanti concorrenti parteciano alla gara? (1- " << max << ")" <<endl;
//		cin >> dim;
		do{
			dim=leggi_input(dim);
		}while(dim>max);
		fflush(stdin);
		return dim;

}

void InserisciPersone(TipoGara vetGara[],int dim){
   for (int i = 0; i < dim; i++) {
    cout << "\tConcorrente No." << i+1 << endl;
    vetGara[i]=InputDati();
    fflush(stdin);
  }
}

TipoGara InputDati(){
  	TipoGara gara;
  	double secondi;
	fflush(stdin);
	cout << "inserisci il Nome: " <<endl;
	getline(cin, gara.nome);
	cout << "inserisci il Cognome:" << endl;
	getline(cin, gara.cognome);
	cout << "Numero di pettorina assegnato: " ;
//	cin >> gara.numpet;
	gara.numpet=pettorina++;;
	cout << gara.numpet<<endl;
	cout << "inserisci il tempo in secondi" << endl;
//	cin >> gara.tempo;
	gara.tempo=leggi_input(secondi);
	return gara;
}

void orderByTempo(TipoGara vetGara[], int dim){
	for(int i=0;i<dim-1;i++){
		for(int j=i+1;j<dim;j++){
			if(vetGara[i].tempo>vetGara[j].tempo){
				scambia(vetGara[i],vetGara[j]);
			}
		}
	}

}

void scambia(TipoGara &primo, TipoGara &secondo){
	TipoGara appoggio;
	appoggio = primo;
	primo = secondo;
	secondo = appoggio;

}

void stampaClassifica(const TipoGara vetGara[], int dim){
	for(int i=0;i<dim;i++ ){
		Stampaconcorrente(vetGara[i]);
		//		cout<< vetGara[i].numpet<<"\t"<<vetGara[i].cognome<<"\t"<<vetGara[i].nome<<"\t" << vetGara[i].tempo<<endl;		
	}
	cout<<endl;
}

void stampaVincitore(TipoGara gara){
	cout<< "Vincitore: "<<gara.numpet<<"-"<<gara.cognome<<" "<<gara.nome<<endl;
}
int RicercaConcorrente(TipoGara vetGara[],int dim,int pet){
	int pos=-1;
	bool trovato=false;
	for(int i=0;i<dim && trovato==false;i++){
		if(vetGara[i].numpet==pet){
			trovato=true;
			pos=i;
		}
	}
	cout <<pos;
	return pos;
}

void StampaelencoTempo(TipoGara vetGara[],int dim,int t){
	for(int i=0;i<dim;i++){
		if(vetGara[i].tempo<=t){
			Stampaconcorrente(vetGara[i]);
		}
	}
}
void Stampaconcorrente(TipoGara gara){
		cout<< gara.numpet<<"\t"<<gara.cognome<<"\t"<<gara.nome<<"\t" << gara.tempo<<endl;		
}
