#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    string pass;
    string pass2;
    string user;
    string line;
    int menu;
    cout << "digite 1 para logar" << endl << "digite 2 para criar uma  nova conta" << endl;
    bool ysnt = false;
    bool nog = false;
    cin >> menu;
    if (menu == 1){
        ifstream data("data.txt");
        cout << "login" << endl;
        cin >> user;
        cout << "password" << endl;
        cin >> pass;
        if(data.is_open()) {
            while(getline(data, line)) {
                int pos = line.find(';');
                if (pos == string::npos) continue;
                string fileUser = line.substr(0, pos);
                string filePas = line.substr(pos + 1);
                if (fileUser == user && filePas == pass) {ysnt = true;
                break;}
            }
        } data.close();
    }
    if (menu == 2){
        cout << "crie seu login" << endl;
        cin >> user;
        ifstream data("data.txt");
        if (data.is_open()){while(getline(data, line)){
            int pos = line.find(';');
            if (pos == string::npos) continue; 
            string fileUser = line.substr(0, pos); 
            if (user == fileUser) {cout << "ja existe um usuario, tente novamente" << endl;
                nog = true;
            break;}
        }
        data.close();}
        if (nog) {return 0;}
        cout << "crie sua senha" << endl;
        cin >> pass;
        bool leak = false;
        cout << "confirme sua senha" << endl;
        cin >> pass2;
        if (pass == pass2){leak = true;}
        if (leak){
            ofstream data("data.txt", ios::app);
            data << endl << user << ";" << pass;
            cout << user << "foi adicionado com sucesso a lista de banco de dados" << endl;
        }
    }
    if (ysnt){cout << "encontrado" << endl;
            cout << "deseja fazer alguma alteracao em sua senha" << user << "?" << endl << "y/n" << endl;
            string alt;
            cin >> alt;
            if (alt == "n") {cout << "voce logou com sucesso" << endl;}
            if (alt == "y") {
                cout << "crie uma senha nova" << endl;
                cin >> pass;
                cout << "confirme sua senha" << endl;
                cin >> pass2;
                if (pass != pass2) {cout << "as senhas nao coincidem" << endl;} else {
                ifstream data("data.txt");
                ofstream temp("log.txt");
                if (data.is_open() && temp.is_open()){
                    while(getline(data, line)){
                        int pos = line.find(';');
                        if (pos == string::npos) continue;
                        string fileuser = line.substr(0, pos);
                        string filepas = line.substr(pos + 1);
                        if (fileuser == user) {
                            temp << fileuser << ";" << pass << endl;
                        } else {temp << line << endl;}
                    }
                }data.close();     temp.close();    remove("data.txt");     rename("log.txt", "data.txt");
            } 
        }
    }  return 0;
}