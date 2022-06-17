// stampare entra al cinema se gli anni della persona sono compresi tra 10 e 80
#include <iostream>
using namespace std;
int main (){
	int anni;
	cout << "quanti anni hai?"<<endl;
	cin >>anni;
	if( anni>=10 && anni<=80 ){   
		cout << "puoi entrare!!"<<endl;
	}else{
		cout << "NON puoi entrare!!"<<endl;
	}
/*	
	if(anni<10 || anni>80){  
		cout << "NON puoi entrare!!"<<endl;
		
	}else{
		cout << "puoi entrare!!"<<endl;
	}
*/	
}
