//Uva 117679 Sub-Prime (ACEPTADO)
#include <iostream>
#include <vector>
using namespace std;

struct Banco{
	int numBanco;
	int dineroAlmacenado;
};

int main(){
	int numBancos , numDeudas;
	while(true){
		cin >> numBancos >> numDeudas;
		if(numBancos == 0 && numDeudas == 0) break;

		//reserva de dinero que cada banco Ri,...,Rb tiene en su cuenta
		int reservaMonetaria;
		Banco banco;
		vector<Banco> bancos;
		bancos.resize(numBancos+1 , banco);

		//completar vector de cada numero de banco con su cantidad de dinero en cada cuenta
		for(int i=1 ; i<=numBancos ; i++){
			cin >> reservaMonetaria;
			banco.numBanco = i; //numero del i-esimo banco
			banco.dineroAlmacenado = reservaMonetaria; //reserva del i-esimo banco
			bancos[i] = banco;
		}
		int bancoDeudor , bancoAcreedor , monto_a_pagar;

		for(int i=1 ; i<=numDeudas; i++){
			cin >> bancoDeudor >> bancoAcreedor >> monto_a_pagar;
			bancos[bancoAcreedor].dineroAlmacenado += monto_a_pagar; //aumento el monto del acreedor
			bancos[bancoDeudor].dineroAlmacenado -= monto_a_pagar; //decremento del deudor
		}

		//segunda pasada para ver si alguien queda con saldo negativo
		for(int i=1 ; i<=numBancos ; i++){
			if(bancos[i].dineroAlmacenado < 0){
				puedePagar = false;
				break;
			}
		}

		bool puedePagar = true;
		if(puedePagar) puts("S");
		else puts("N");

	}

	return 0;
}
