# include <iostream>
# include <limits>
using namespace std ;

int leerEnteroCorrecto() ;

int main () {
    int a= leerEnteroCorrecto();
}

int leerEnteroCorrecto () {
  int entero;
  cout << "ingrese el valor enter para parar:" << endl;
  cin >> entero;

    while (true) {
      if(!cin.fail()){
        break;
      }

      cout << "ingrese el valor enter para parar:" << endl;
      cin >> entero;

      cin.clear ( ) ;
      cin.ignore (numeric_limits < streamsize >:: max(),'\n');
      cin >> entero;
    }
  }
