#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

void menu() {
    cout << endl;
	cout << "\t\tMy Bank" << endl;
	cout << endl;
	cout << "\t1. UPLATA NOVCA" << endl;
	cout << "\t2. PODIZANJE NOVCA" << endl;
	cout << "\t3. KREDIT" << endl;
	cout << "\t4. PRETVARANJE VALUTA" << endl;
    cout << "\t5. STANJE RACUNA" << endl;
	cout << endl;
 	cout << "\t   UNESI OPCIJU: " << endl;
}

void gmenu() {
    cout <<"\tDOBRO DOSLI\n" << endl;
    cout << endl;
    cout <<"\t1.KREIRAJ RACUN" << endl;
    cout <<"\t2.ULOGUJ SE NA RACUN" << endl;
    cout <<"\t3.UDI U MENI"<<endl;
}

int podizanje_novca(int accBalance) {
	
    cout << "Unesi kolicinu novca koju podizes: ";
	int dodavanjeNovca = 0;
	cin >> dodavanjeNovca;

	accBalance -= dodavanjeNovca;

	cout << "Novo stanje racuna je: " << accBalance << endl;

	return accBalance;
}

int dodavanje_novca(int accBalance) {

	cout << "Unesi kolicinu novca koju dodajes: ";
	int dodavanjeNovca = 0;
	cin >> dodavanjeNovca;

	accBalance += dodavanjeNovca;

	cout << "Novo stanje racuna je: " << accBalance << endl;

	return accBalance;
};

void kredit_kalkulator(float kolicinaKredita, float kamataGodisnja, int mjeseci) {

	float mjesecnaRata, kolicinaIsplate;

	mjesecnaRata = pow(1 + kamataGodisnja / 100, 1.0 / 12);

	kolicinaIsplate = kolicinaKredita * pow(mjesecnaRata, mjeseci) * (mjesecnaRata - 1)/
		(pow(mjesecnaRata, mjeseci) - 1);

	float isplaceno = kolicinaIsplate * mjeseci;
	cout << "Mjesecna rata iznosi : " << kolicinaIsplate << endl;
	cout << "Kolicina koja se mora isplatit: " << isplaceno;

}

void pretvaranje_valuta() {
	cout << "MENI VALUTA" << endl;
	cout << endl;
	cout << "1. KM U EUR" << endl;
	cout << "2. KM U USD" << endl;
	cout << "3. KM U GBP" << endl;
	cout << "4. KM U DIN" << endl;
	cout << "5. KM U KUNE" << endl;
	cout << "6. KM U MKD" << endl;
	cout << "7. KM U TL" << endl;
	cout << "8. Izlaz." << endl;
}

float EUR(float x) {
	return x * 0.51;
}

float USD(float x) {
	return x * 0.56;
}

float GBP(float x) {
	return x * 0.42;
}

float DIN(float x) {
	return x * 60.21;
}

float KUNA(float x) {
	return x * 3.87;
}

float MKD(float x) {
	return x * 31.51;
}

float TL(float x) {
	return x * 8.19;
}


int main(){
    //bool login
    bool login;
    //int variables
    int option;
    int loanTime;
    int accNumber;
    int accNumberAdd;
    int enter;
    int accMoney;
    int accMoneyAdd;
    int newMoney;
    int addMenu = 1;
    int option2;
    int temp;
    //string variables
    string name;
    string nameAdd;
    string surname;
    string surnameAdd;
    //fstream variables
    ofstream data;
    ofstream money;
    ifstream data1;
    ifstream money1;
    //flaot variables
    float amountLoan;
    float loanFee;

    while (1){
    gmenu();
    cin >> option;
       switch (option)
       {
        case 1:
            data.open("unos.txt", ios::out | ios::app);
            if (data.is_open())
            {
                cout <<"Enter acc.Number: ";
                cin >> accNumber;
                cout <<"Enter user name: ";
                cin >> name;
                cout <<"Enter user surname: ";
                cin >> surname;
                data << accNumber <<" " << name << " " << surname <<endl;
            }
            data.close();
            money.open("novac.txt", ios::out | ios::app);
            if(money.is_open()){
                cout << "Unesi kolicinu novca: ";
                cin >> accMoneyAdd;
                money << accNumber << " " << accMoneyAdd <<endl;
            }
            money.close();
        system("PAUSE");
		system("CLS");   
		break;

        case 2:
         data1.open("unos.txt", ios::in);
            if (data1.is_open())
            {
                cout <<"Enter acc.Number: ";
                cin >> accNumber;
                cout <<"Enter user name: ";
                cin >> name;
                cout <<"Enter user surname: ";
                cin >> surname;
            }
            while (data1 >> accNumberAdd >> nameAdd >> surnameAdd){
                if (accNumberAdd == accNumber and name == nameAdd and surname == surnameAdd)
                {
                    login = true;
                    cout << "Login == true" << endl;
                }
                }
        data1.close();
        money1.open("novac.txt",ios::in);
        if (money1.is_open())
        {
            while (money1 >> accNumberAdd >> accMoney)
            {
            }    
        }
        money1.close();
        system("PAUSE");
		system("CLS");   
		break;

        case 3: 
        cout << "Da li zelite nastaviti dalje u meni? (enter == 1)";
        cin >> enter;

        if (enter == 1 and login == true){
            system("CLS"); 
            while (1)
            {
                menu();
                cin >> option2;
                switch (option2)
                {
                case 1:
                money1.open("novac.txt",ios::in);
                if (money1.is_open())
                {
                    while (money1 >> accNumberAdd)
                    {
                        while (money1 >> accMoneyAdd)
                        {
                            if(accNumber == accNumberAdd){
                                accMoney = accMoneyAdd;
                                break;
                            }
                            else break;
                        }
                        
                    }
                    
                }
                money1.close();
                newMoney = dodavanje_novca(accMoney);
                money.open("novac.txt", ios::out | ios::app);
                money << accNumberAdd << " " << newMoney << endl;
                money.close();
                system("PAUSE");
		        system("CLS"); 
                break;

                case 2:
                money1.open("novac.txt",ios::in);
                if (money1.is_open())
                {
                    while (money1 >> accNumberAdd)
                    {
                        while (money1 >> accMoneyAdd)
                        {
                            if(accNumber == accNumberAdd){
                                accMoney = accMoneyAdd;
                                break;
                            }
                            else break;
                        }
                        
                    }
                    
                }
                money1.close();
                newMoney = podizanje_novca(accMoney);
                money.open("novac.txt", ios::out | ios::app);
                money << accNumberAdd << " " << newMoney << endl;
                money.close();
                system("PAUSE");
		        system("CLS");
                break;
                case 3:
                cout << "Unesite kolicinu kredita: ";
                cin >> amountLoan;

                cout << "Unesite kamatu(godisnju): ";
                cin >> loanFee;

                cout << "Unesite vrijeme kredita(mjeseci): ";
                cin >> loanTime;

                kredit_kalkulator(amountLoan,loanFee,loanTime);
                cout <<     endl; 

                system("PAUSE");
		        system("CLS");
                break;
                case 4:
                system("CLS");
			    pretvaranje_valuta();

			    cout << "Unesite kolicinu koju zelite pretvorit: ";
			    float amountConversion;
			    cin >> amountConversion;

			    cout << "Unesi opciju: ";
			    int  currencyOption;
			    cin >> currencyOption;

			    switch (currencyOption)
			    {
			    case 1:
				cout << "Nakon pretvaranja: " << EUR(amountConversion);
				break;
			    case 2:
				cout << "Nakon pretvaranja: " << USD(amountConversion);
				break;
			    case 3:
				cout << "Nakon pretvaranja: " << GBP(amountConversion);
				break;
			    case 4:
				cout << "Nakon pretvaranja: " << DIN(amountConversion);
				break;
			    case 5:
				cout << "Nakon pretvaranja: " << KUNA(amountConversion);
				break;
			    case 6:
				cout << "Nakon pretvaranja: " << MKD(amountConversion);
				break;
			    case 7:
				cout << "Nakon pretvaranja: " << TL(amountConversion);
				break;

			    default:
				break;
			    }

			cout << endl;
			system("PAUSE");
			system("CLS");
			break;
                case 5:
                data1.open("unos.txt",ios::in);
                if (data1.is_open()){
                    while (data1 >> accNumberAdd){
                        while (data1 >> name) {
                            while(data1 >> surname){
                            if(accNumber == accNumberAdd){
                               break;
                            }
                            else break;
                            }
                        }
                        
                    }
                    
                }
                cout << accNumber << " " << name << " " << surname << " " ;
                data1.close();
                money1.open("novac.txt",ios::in);
                if (money1.is_open()){
                    while (money1 >> accNumberAdd){
                        while (money1 >> accMoneyAdd){
                            if(accNumber == accNumberAdd){
                                break;
                            }
                            else break;
                        }
                        
                    }
                    
                }
                cout << accMoneyAdd << endl;
                money1.close();
                system("PAUSE");
		        system("CLS");
                break;
                default:
                return 0;
                }
            }
            
        }
        else {
            cout << "Neuspjesno ste se ulogovali" <<endl;
            }
        system("PAUSE");
		system("CLS");   
		break;
       default:
       return 0;
        break;
       }
    }
    
}                       