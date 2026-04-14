        #include <fstream>
        #include <iostream>
        #include <string>
        using namespace std; //Build barrosmlk
        int main (){
        bool cor = false;
        bool ext = false;
        bool paspas = false;
        bool create = false;
        string dab;
        string pas;
        string line;
        string pas2;
        ifstream file("Database.txt");
        if (file.is_open()){
                while(getline(file, line)){
                        cout << line << endl;
                } file.close();
        }      
        cout << endl << "banco de dados " << endl;
        cout << "login" << endl;
        cin >> dab;
        cout << "senha" << endl;
        cin >> pas;     
        file.close();
        file.open("Database.txt");
        if(file.is_open()){
                while (getline(file, line)){
                        int post = line.find (';');
                        string user = line.substr(0, post);
                        string pass = line.substr(post +1);
                        if (user == dab && pass == pas) 
                                {cor = true;
                                break;}
                        }
                } if (cor == true)  {cout << "correto" << endl;} else {cout << "o login nao existe, deseja criar uma nova conta?" << endl;}
                if (!cor) {cout << "login" << endl;
                        cin >> dab;
                        cout << "senha" << endl;
                        cin >> pas;
                        cout << "repita sua senha novamente" << endl;
                        cin >> pas2;}
                if (pas == pas2){paspas = true;} else {cout << "senha icorreta" << endl;}
                if (paspas == true) {
if (!cor) {
        ofstream save("Database.txt", ios::app);
        if (save.is_open()){
                save << dab << ";" << pas << endl;
                save.close();}
                }
        }
        return 0;
}