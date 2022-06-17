#include <iostream>
using namespace std;
int main(){
 string st="contengo tanti caratteri";
 string st1=string("questa è una frase");
 string str="uno";
 str="due";
 cout << str<<endl;
 int n=st.length();
 cout << "lunghezza della variabile st="<<n<<endl;
 char p=st.at(0);
 cout<<p<<endl;
 string s=st.substr(1,4); // estrae 4 caratteri a partire dalla posizione 1
 cout << s<<endl;
 string s1=s+"-"+str;
 cout <<s1<<endl;
 
}

