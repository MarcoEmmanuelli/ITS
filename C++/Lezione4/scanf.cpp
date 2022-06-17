#include <iostream>
using namespace std;
int main(){
	int n,n1;
	unsigned int iss;
	float rf;
	char car;
	printf("inserisci un intero negativo, un intero positivo e un numero decimale:\n");
	scanf(" %i %u %f", &n,&iss,&rf);
	cout << n<<" "<<iss<<" "<<rf<<endl;
	getchar();
	scanf("%c",&car);
	printf("%c #%15.3f \n", car,rf);
	
}

