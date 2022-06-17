//rubrica teleefonica
// i commentio sono da modificare per completare l'esercizio
#include <iostream>
//#include "controlloinput.h"
using namespace std;
// dichiaro la struttura del nodo generico della LISTA CONCATENATA
struct nodo{
	string cognome, nome;
	string indirizzo;
	string telefono;
	nodo *next;	
};

bool controllonumerico(){
	bool r=true;
	if(cin.fail()){	//input errato
			cin.clear();
			cin.ignore(1000,'\n');
			r=false;
	}else{		// caso di input parzialmente
			cin.ignore(1000,'\n');
			if(cin.gcount()>1){
				r=false;
			}
	}
	return r;
}

// funzione che crea un menu per utilizzare le varie opzioni  
int stampa_menu(){
	int scelta;
	system("cls");
	cout << endl; 
	cout << " COSTRUZIONE DI UNA *** RUBRCA TELEFONICA *** "<< endl<< endl << endl;
	cout << "1. inserimento di un contatto" << endl; 
	cout << "2. Modifica numero di telefono" << endl; 
	cout << "3. Stampa rubrica ordinata per cognome" << endl; 
	cout << "4. Cancella numero di telefono" << endl; 
	cout << "5. Stampa numero di telefono ricercato per nome" << endl;
	cout << "0. Esci" << endl;  
	cout << endl; 
	cout << "Scelta: "<< endl; 
	cin >> scelta;
	if (controllonumerico() == false){
		scelta=-1;
	}	
	if (!(scelta <=5 && scelta >=0) ){
	
		cout << "scelta errata" << endl;
		system("pause");
		scelta=-1;
	}	
		
	return scelta;
	
}
nodo *inputDati(nodo *p){
	cout <<"inserisci nome contatto: "<<endl;
	getline(cin, p->nome);
	cout <<"inserisci cognome contatto: "<<endl;
	getline(cin, p->cognome);
	cout <<"inserisci indirizzo: "<<endl;
	getline(cin, p->indirizzo);
	cout <<"inserisci numero telefono: "<<endl;
	getline(cin, p->telefono);
	return p;
}
nodo *creaNodo(){
	nodo *p2;
	p2= new nodo;
//	cout <<"inserisci il valore del nodo (numero intero): "<<endl;
//	cin >> p2->val;
	p2=inputDati(p2);
	return p2;
}

nodo * inserisciInTesta(nodo *p, nodo *testa){
	p->next=testa; 
	testa=p;
	return testa;
}

void stampacontatto(nodo *p){
	cout <<p->cognome<<" "<<p->nome<<" "<< p->telefono<<" "<<p->indirizzo<<endl;
}
void stampaLista(nodo *testa){
	int i=0;
	while(testa!=NULL){
		i=i+1;
//		cout <<" elemento "<<i<<": "<<testa->val<<endl;
		stampacontatto(testa);
		testa=testa->next;
	}
}
/*
int ricerca(nodo *t, int elem){
	bool trovato=false;
	int i=0;
	int pos=-1;
	while(t!=NULL && trovato==false ){
		i=i+1;
		if(t->val==elem){
			trovato=true;
//			pos=i;

		}
		t=t->next;
	}
	if(trovato==true){
		return i;
	}else{
		return -1;
	}
	
}

nodo * estrai(nodo * testa){
	if(testa!=NULL){
		nodo *temp;
		temp=testa;
		testa=testa->next;
		delete temp;
	}
	return testa;
}

nodo * cancellaLista(nodo *testa){
	while(testa!=NULL){
		testa=estrai(testa);
	}
}
*/
void ordina(nodo *testa){
	int k;
	do{
		nodo *p=testa;
		k=0;
		while(p->next!=NULL){
			nodo *p1;
			p1=p;
			p=p->next;
			if(p1->cognome > p->cognome){
				int temp=p1->cognome;
				p1->cognome=p->cognome;
				p->cognome=temp;
				k=1;
			}
		}
		
	}while(k!=0);
}
/*
nodo *estraivalore(nodo *testa,int v, bool &trovato){
//	bool trovato=false;
	nodo *p, *prec;
	p=testa;
	prec=testa;
	int i=0;
	while(p!=NULL && trovato==false){
		i++;
		if(p->val==v){
			trovato=true;
			if(i==1){
				testa=p->next;
				delete p;
			}else{
				prec->next=p->next;
				delete p;
			}
			break;
		}
		prec=p;
		p=p->next;
			
	}
	return testa;
}
*/
// programma principlae 
int main(){
	int s,v;
	nodo *testa=NULL;
	nodo *p;
	do{
	  s=	stampa_menu();
	  switch (s) { 
			case 1: 
					cout<<"1. inserimento di un contatto"<<endl;
					p=creaNodo();
					testa=inserisciInTesta(p,testa);
//					cout <<" testa ="<<testa<<endl;
					cout<<" elemento inserito"<<endl;
					
					break;
			case 2: 
					cout << "2. "<<endl;
					break; 
			case 3: 
					cout << "3. Stampa rubrica ordinata per cognome " << endl;
					if(testa!=NULL){
						ordina(testa);
						stampaLista(testa);
					}else{
						cout << "LISTA VUOTA!!!"<<endl;
					}
					break;
/*			
					cout << "3. Ricerca di un elemento nella Lista  " << endl; 
					if(testa!=NULL){
						int v;
						cout <<"inserisci elemento da ricercare (numero intero):"<<endl;
						cin>>v;
						int pos=ricerca(testa,v);
						if(pos==-1){
							cout <<"elemento non esiste nella lista"<<endl;
						}else{
							cout <<"l'elemento "<<v<<" esiste alla posizione"<<pos<<endl;
						}
					}
					break; 
*/					
				case 4: 
/*					cout << "4. SVUOTA LISTA- cancella tutti gli elementi" << endl; 
					if(testa!=NULL){
							testa=cancellaLista(testa);
							cout << "Lista cancellata!!!"<<endl;
					}					
*/					break;
				case 5: 
/*				case 6: 
					cout << "6. Estrazione di un elemento dalla testa" << endl;
					if(testa!=NULL){
						testa=estrai(testa);
						cout << "estrazione di un elemento dalla testa eseguita"<<endl;
					}					
					system("pause");
					break;
				case 7: 
					cout << "7. " << endl;
					system("pause");
					break;
				case 8: 
					if(testa!=NULL){
						int v;
						bool trovato=false;
						cout << "8. Estrazione di un elmento di valore preso in input" << endl;
						cout << "inserisci valore da estrazione:"<<endl;
						cin>> v;
						testa=estraivalore(testa,v,trovato);
						if(trovato==true){
							cout << "elemento cancellato!!!<<"<<endl;
						}else{
							cout << "elemento non trovato!!!<<"<<endl;
						}
						
					}else{
						cout << "LISTA VUOTA!!!"<<endl;
					}

					system("pause");
					break; 
				case 9: 
					cout << "9. Ordinamento della Lista" << endl;
					if(testa!=NULL){
						ordina(testa);
						cout << "Lista ordinata completamente"<<endl;
					}					
					system("pause");
					break; 
*/				case 0: 
					cout<<"Esci"<<endl;
					break;
				default: 
					cout <<"Scelta non valida"<<endl; 
					break;
		}
		system ("pause");			
	}while((s!=0));
}
