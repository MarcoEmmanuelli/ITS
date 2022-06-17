#include <iostream>
#include <cstdlib> //rand()
#include <ctime> //time()
using namespace std;
int main(){
	int n,n2;
	cout << "ho pensato un numero da 1 a 6:"<<endl;

	srand(time(NULL));
	n=(rand() %6)+1;
	cout << "sai indovinare il numero?"<<endl;
	cout <<"prova: ";
	cin >>n2;
	
	cout << "il numero estratto vale:"<<n<<endl;
	getchar();
	
	
	
}
