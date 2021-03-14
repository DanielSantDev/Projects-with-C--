/*ESSE PROGRAMA SIMULA UM SISTEMA DE VENDA DE INGRESSOS DE UM TEATRO
EM QUE � POSS�VEL FAZER A COMPRA, O REEMBOLSO E MUDAN�A DE ASSENTO.

ESTRUTURAS DE DADOS

by DANIEL SANTANA
*/

#include <iostream>
#include <stdlib.h>
#include <locale.h>

#include "Teatro.h"

using namespace std;

int main(void) {
    Teatro Teatroo;
    bool sair = true;
    int linha=10,coluna=6,linha2,coluna2;
    Teatroo=Teatro(linha,coluna);
    setlocale(LC_ALL, "portuguese");
    system("color 2");
    while(sair) {
        cout<<"\n\n  ";
        for(int k = 0 ; k < Teatroo.Colunas; k++) {
                if(k < 9)
                    cout<<"  "<<(k+1)<<"  ";
                else
                    cout<<"  "<<(k+1)<<"  ";
        }
        cout<<"\n";
        for(int i=0;i<Teatroo.Linhas;i++) {
                if(i<9){
                    cout<<(i + 1)<<" ";
                }
                else{
                    cout<<(i + 1);
                }
                for(int j=0;j<Teatroo.Colunas;j++) {
                    if(Teatroo.Assentos[i * Teatroo.Colunas + j] == true){
                        cout<<" [X] ";
                    }else
                        cout<<" [ ] ";
                }
                cout<<endl;
        }
        cout<<"\n_________________________________\n";
        cout<<"_BEM VINDO AO TEATRO AMAZONAS.___"<<endl;
        cout<<"_1)COMPRAR UM ASSENTO.___________"<<endl;
        cout<<"_2)REEMBOLSO DO ASSENTO._________"<<endl;
        cout<<"_3)MUDAN�A DE ASSENTO.___________"<<endl;
        cout<<"_0)DIGITE 0 E ENTER PARA SAIR.___"<<endl;
        cout<<"\nOP��O; "<<endl;
        int option;
        cin>>option;
        switch(option) {
        case 1:
            cout<<"Digite o assento e coluna desejados: "<<endl;
            cout<<"linha: ";
            cin>>linha;
            linha -= 1;
            cout<<"Coluna: ";
            cin>>coluna;
            coluna -= 1;
            if(!Teatroo.Disponibilidade(linha,coluna)) {
                system("cls");
                cout<<"O assento n�o est� dispon�vel. ";
            }
            else{
                Teatroo.MarcarLugar(linha,coluna);
                system("cls");
                cout<<"O assento foi reservado! Tenha um �timo Espet�culo!";
            }
            break;
        case 2:
            cout<<"Digite a linha e coluna que voc� deseja reembolsar: "<<endl;
            cout<<"Linha: ";
            cin>>linha;
            linha -= 1;
            cout<<"Coluna: ";
            cin>>coluna;
            coluna -= 1;
            if(Teatroo.Disponibilidade(linha ,coluna)) {
                system("cls");
                cout<<"Assento vazio! Voc� pode compra-lo!";
            }
            else {
                Teatroo.Reembolso(linha,coluna);
                system("cls");
                cout<<"Reembolso feito com sucesso!";
            }
            break;
        case 3:
            cout<<"Digite a linha e coluna que voc� comprou: "<<endl;
            cout<<"Linha: ";
            cin>>linha;
            linha -= 1;
            cout<<"Coluna: ";
            cin>>coluna;
            coluna -= 1;
            cout<<"Digite a linha e coluna que voc� deseja: "<<endl;
            cout<<"Linha: ";
            cin>>linha2;
            linha2 -= 1;
            cout<<"Coluna: ";
            cin>>coluna2;
            coluna2 -= 1;
            if(!Teatroo.Disponibilidade(linha,coluna) && (Teatroo.Disponibilidade(linha2,coluna2))){
                Teatroo.Reembolso(linha,coluna);
                Teatroo.MarcarLugar(linha2,coluna2);
                system("cls");
                cout<<"A mudan�a foi realizada com sucesso!";
            }
            else{
                cout<<"N�o foi poss�vel fazer a mudan�a. Tente novamente";
            }
            break;
        case 0:
            sair = false;
            system("cls");
            cout<<"Voc� saiu do Menu! Agradecemos a prefer�ncia!"<<endl;
            break;
        default:
            system("cls");
            cout<<"Voc� digitou errado, tente novamente!"<<endl;
            break;
        }
    }

    return 0;
}
