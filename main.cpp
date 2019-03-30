#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include <chrono>
//#include <thread>

using namespace std;

void geracao(char (&mundo)[22][80]){
    char novo_mundo[22][80];

    for (int percorre_linha = 0; percorre_linha < 22; percorre_linha++){
        for (int percorre_coluna = 0; percorre_coluna < 80; percorre_coluna++){
            novo_mundo[percorre_linha][percorre_coluna] = mundo[percorre_linha][percorre_coluna];
        }
    }

    for (int percorre_linha = 0; percorre_linha <= 22; percorre_linha++){
		for (int percorre_coluna = 0; percorre_coluna <= 80; percorre_coluna++){
            
			//Verifica vidas ao redor do indivíduo
        	int verifica_vida = 0;
        	
			if (mundo[percorre_linha-1][percorre_coluna-1] == '*'){	
        		verifica_vida+=1;
			}
			else if (mundo[percorre_linha-1][percorre_coluna] == '*'){
				verifica_vida+=1;
			}
			else if (mundo[percorre_linha-1][percorre_coluna+1] == '*'){
				verifica_vida+=1;
			}
			else if (mundo[percorre_linha][percorre_coluna-1] == '*'){
				verifica_vida+=1;
			}
			else if (mundo[percorre_linha][percorre_coluna+1] == '*'){
				verifica_vida+=1;
			}
			else if (mundo[percorre_linha+1][percorre_coluna-1] == '*'){
				verifica_vida+=1;
			}			
			else if (mundo[percorre_linha+1][percorre_coluna] == '*'){
				verifica_vida+=1;
			}			
			else if (mundo[percorre_linha+1][percorre_coluna+1] == '*'){
				verifica_vida+=1;
			}						
			
            char individuo = mundo[percorre_linha][percorre_coluna];

            //Célula viva
            if (individuo == '*'){
                if (verifica_vida <= 1){    novo_mundo[percorre_linha][percorre_coluna] = ',';   }
                if (verifica_vida >= 3){    novo_mundo[percorre_linha][percorre_coluna] = ',';   }
            }

            //Célula morta
            if (individuo == ','){
                if(verifica_vida == 3) {    novo_mundo[percorre_linha][percorre_coluna] = '*';     }
            }
		}
    }
    for (int percorre_linha = 0; percorre_linha < 22; percorre_linha++){
        for (int percorre_coluna = 0; percorre_coluna < 80; percorre_coluna++){
            mundo[percorre_linha][percorre_coluna] = novo_mundo[percorre_linha][percorre_coluna];
        }
    }
}

void mostra (char(&mundo)[22][80]){
    for (int aux_imprimi_linha = 0; aux_imprimi_linha < 22; aux_imprimi_linha++ ){
        for (int aux_imprimi_coluna = 0; aux_imprimi_coluna < 80; aux_imprimi_coluna++){
            if (mundo[aux_imprimi_linha][aux_imprimi_coluna] == ',') { mundo[aux_imprimi_linha][aux_imprimi_coluna] = ' '; }
            cout << mundo[aux_imprimi_linha][aux_imprimi_coluna];
        }
        cout << "\n";
    }
}

int main(){

    ifstream arquivo("teste.txt");
    string linha;
    vector <string> matriz_ambiente;
    char mundo[22][80];

    if (arquivo.is_open()){
        while(getline(arquivo, linha)){
            matriz_ambiente.push_back(linha);
        }

        for (int aux_imprimi_linha = 0; aux_imprimi_linha < 22; aux_imprimi_linha++ ){
            for (int aux_imprimi_coluna = 0; aux_imprimi_coluna < 80; aux_imprimi_coluna++){
                mundo[aux_imprimi_linha][aux_imprimi_coluna] = matriz_ambiente[aux_imprimi_linha][aux_imprimi_coluna];
            }
        }
    }

    else {
        cout << "Nao foi possivel abrir o arquivo"<< endl;
    }

    cout << "O programa segue o padrao de um txt simulando exatamente a matriz, com o seguinte formato:"<<endl;
    cout << "Os espacos em branco sao virgulas (objetos sem vida), as vidas sao representadas por Asteriscos." << endl;



    while(true){
    	mostra(mundo);
        geracao(mundo);
        //this_thread::sleep_for(chrono::milliseconds(500));
    }
    arquivo.close();
}


