/*
Título:manipulaçao de struct
Marco Antonio Betim da Silva
data:25.11.2024*/

//espaço reservado para declaração de biblioteca
//precissa armazenar dados de tipos diferentes
#include <iostream>
#include<limits>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;



//espaço reservado para construção da struct
struct pessoa{
  int codigo;
  string nome;
  float altura;

};

//estaço reservado para prototipaçao de funçoes
int menu();
int lerCodigoValido(const string &mensagem);
void limparBuffer();
void exibirMsErro(const string &mensagem);
void mostrarArray(pessoa array[], int tamanho);
void esperarEnter();
void zerarArray(pessoa array[], int tamanho);
void preencherArray(pessoa array[], int tamanho);
string lerStringValida(const string &mensagem);
float lerAlturaValida(const string &mensagem);
void editarArray(pessoa array[], int tamanho);
void verificarArray(pessoa array[], int tamanho);
void ordenarArray(pessoa array[], int tamanho);
void exibirMaiorMenorArray(pessoa array[], int tamanho);
void contarAlturaSuperior(pessoa array[], int tamanho);
void calcularMediaAltura(pessoa array[], int tamanho);




//função principal
int main() { 
  //declara uma constante
  const int TAMANHO = 3; //DEFINE O TAMANHO DO ARRAY DE PESSOAS
  pessoa array[TAMANHO];//em c++ se ussa o ; em tudo//declara um array para armazenar tamanho registro de de pessoas
  int opcao=0;//declara a variavel para armazenar a opção do usuario
  //menu();
  do{
    opcao = menu();
    switch(opcao){
      case 1:mostrarArray(array,TAMANHO);break;
      case 2:zerarArray(array,TAMANHO);break;
      case 3:preencherArray(array,TAMANHO);break;
      case 4:editarArray(array,TAMANHO);break;
      case 5:verificarArray(array,TAMANHO);break;
      case 6:ordenarArray(array,TAMANHO);break;
      case 7:exibirMaiorMenorArray(array,TAMANHO);break; 
      case 8:contarAlturaSuperior(array,TAMANHO);break;
      case 9:calcularMediaAltura(array,TAMANHO);break;
      case 0:cout<<"Encerrar programa..."<<endl;break;
      default: exibirMsErro("Opção invalida! Escolha umaopçao válida");break;
    }  
  }while(opcao!=0);

  
  return 0;
  
}
//funçaõ que exibe o menu e retorns a escolha do usuario
int menu(){
  cout<< "\nEscolha uma opçao: \n";
  cout<< "1 - Mostrar array de pessoas\n";
  cout<< "2 - zerar array de pessoas\n";
  cout<< "3 - Preencher pessoa\n";
  cout<< "4 - editar pessoa no array\n";
  cout<< "5 - verificar pessoa no array\n";
  cout<< "6 - Ordenar array de pessoas por nome\n";
  cout<< "7 - Exibir Maior e Menor Altura\n";
  cout<< "8 - Contar pessoas com altura superior ao valor fornecido\n";
  cout<< "9 - Calcular a média de altura\n";
  cout<< "0 - sair\n";
  return lerCodigoValido("Opção: ");
}


//Função para ler um numero inteiro válido
int lerCodigoValido(const string &mensagem){
  int numero;
  while(true){
    cout<<mensagem;
    cin>>numero;
    if (cin.fail()){
      limparBuffer();
      exibirMsErro("Entrada invalida.Por favor, Insira um numero inteiro.");
    }else{
      limparBuffer();
      return numero;
    }
  }
}

//Função para limpar o buffer de entrada
void limparBuffer(){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');//ignorar entradas invalidas no Buffer
}

//funçao para exibir mensagem erro 
void exibirMsErro(const string &mensagem){
  cout<<mensagem<<endl;
}
void mostrarArray(pessoa array[], int tamanho){
  cout <<left<<setw(10)<<"código"<<"\t"
       <<left<<setw(20)<<"nome"<<"\t"
       <<left<<setw(10)<<"altura"<<endl;
  cout<<string(50,'-')<<endl;
  for(int i=0;i<tamanho;i++){
    cout<<left<<setw(10)<<array[i].codigo<<"\t"
        <<left<<setw(20)<<array[i].nome<<"\t"
        <<left<<setw(10)<<array[i].altura<<endl;
  }
  esperarEnter();
}

void esperarEnter(){
  cout<<"\nPressione Enter para continuar...";
  cin.get();
}

void zerarArray(pessoa array[], int tamanho){
  for(int i=0;i<tamanho;i++){
    array[i].codigo=0;
    array[i].nome="";
    array[i].altura=0.0;
    
  }
  cout<<"Array de pessoas zerado!"<<endl;
    esperarEnter();
}
//funçao para preencher array de pessoas
void preencherArray(pessoa array[], int tamanho){
  for(int i=0;i<tamanho;i++){
    array[i].codigo = lerCodigoValido("Digite o código da pessoa ["+to_string(i)+"]: ");
    array[i].nome = lerStringValida("digite o nome da pessoa ["+to_string(i)+"]: ");
    array[i].altura = lerAlturaValida("digite a altura da pessoa ["+to_string(i)+"]: ");
    cout<<"Array de pessoas Preenchido! com sucesso"<<endl;
      
  }
  esperarEnter();
}
//funçao para ler uma string valida
string lerStringValida(const string &mensagem){
  string entrada;
  cout<<mensagem;
  getline(cin,entrada);
  return entrada;
}
//funçao para ler uma altura valida
float lerAlturaValida(const string &mensagem){
  float altura;
  while(true){
    cout<<mensagem;
    cin>>altura;
    if(cin.fail() || altura<=0){
      limparBuffer();
      exibirMsErro("Entrada invalida.Por favor, Insira uma altura valida");
    }else{
      limparBuffer();
      return altura;
    }
  }
}

//função para editar pessoa especifica no array
void editarArray(pessoa array[], int tamanho){
  int posicao = lerCodigoValido("Digite a posição quie deseja editar (0 a "+to_string(tamanho-1)+"): ");
  while(posicao<0 || posicao>=tamanho){
    exibirMsErro("Posição invalida.Por favor,Tente novamente");
    posicao = lerCodigoValido("Digite a posição valida");
  }
  array[posicao].codigo = lerCodigoValido("Digite um novo código para a posição ["+to_string(posicao)+"]: ");
  limparBuffer();
  array[posicao].nome = lerStringValida("Digite um novo nome para a pessoa ["+to_string(posicao)+"]: ");
  array[posicao].altura = lerAlturaValida("Digite um nova altura para a pessoa ["+to_string(posicao)+"]: ");
  cout<<"Pessoa editada com sucesso";
  esperarEnter();
}
//funçao para verificar se uma pessoa existe no array
void verificarArray(pessoa array[], int tamanho){
  int codigo = lerCodigoValido("Digite o codigo que a pessoa deseja verificar: ");
  bool encontrado = false;
  for(int i=0;i<tamanho;i++){
    if(array[i].codigo==codigo){
      cout<<"Pessoa com o código"<<codigo<<"encontrada!"<<endl;
      cout<<"Nome: "<<array[i].nome<<endl;
      cout<<"Altura: "<<array[i].altura<<endl;
      encontrado = true;
      break;
    }
  }
  if(!encontrado){
    cout<<"Pessoa com o código"<<codigo<<"não encontrada no array."<<endl;
  }
  esperarEnter();
}
// Aqui começa a modificação para a atividade:Manipulando Struct
// Função para Ordenar e Registrar por NOME
void ordenarArray(pessoa array[], int tamanho){
    sort(array,array+tamanho,[](pessoa a, pessoa b){
    return a.nome<b.nome;
  });
  //exibir o array ordenado por nome
  cout<<"Array de pessoas ordenado por Nome."<<endl;
  esperarEnter();
}

//Função para Exibir a Pessoa com a Maior e Menor Altura:
void exibirMaiorMenorArray(pessoa array[], int tamanho){
  if(tamanho==0){
    cout<<"\nNão há pessoas no array para exibir a menor e maior altura.";
      return;
  }
  //variaveis 
  pessoa maiorAltura = array[0];
  pessoa menorAltura = array[0];

  for (int i=1;i<tamanho;i++){
    if (array[i].altura>maiorAltura.altura){
      maiorAltura = array[i];
    }
    if (array[i].altura<menorAltura.altura){
      menorAltura = array[i];
    }
  }
  //exibir informações da pessoa com maior e menor altura, Código e nome
    cout<<"\nMaior altura: "<<maiorAltura.altura<<" - Nome: "<<maiorAltura.nome<<" - Código:"<<maiorAltura.codigo<<endl;
    cout<<"\nMenor altura: "<<menorAltura.altura<<" - Nome: "<<menorAltura.nome<<" - Código:"<<menorAltura.codigo<<endl;
    esperarEnter();
} 
//FUNÇÃO para contar quantas pessoas t~em uma altura superior a um valor fornecido
void contarAlturaSuperior(pessoa array[], int tamanho){
  if(tamanho==0){
    cout<<"\nNão há pessoas no array para exibir a altura superior.";
      return;
  }
  int alturaLimite = lerAlturaValida("Digite a altura limite: ");
  int contador = 0;

// Percorrer o array e contar as pessoas com a altura superior ao limite fornecido 
  for(int i=0;i<tamanho;i++){
    if(array[i].altura > alturaLimite){
      contador++;
    }
  }
  //Exibir a quantidade de pessoas quem tem a altura superior ao limite
  cout<< "Quantidade de pessoas com a altura superior ao limite:"<<contador<<endl;
  esperarEnter();
}
// Aqui sera a minha FUNÇÃO autoral e criativa
// FUNÇÃO para calcular a média de altura das pessoas
void calcularMediaAltura(pessoa array[], int tamanho){
  if(tamanho==0){
    cout<<"\nNão há pessoas no array para calcular a média.";
      return;
  }
  float soma = 0;
  int contagem = 0;
  // Percorrer o array para calcular a media de altura
  for (int i = 0; i < tamanho; i++){
    if(array[i].altura>0){
    soma += array[i].altura;
    contagem++;
    }
  }
  int media = contagem > 0 ? soma / contagem : 0;
  // exibir a media de altura das pessoas
  cout<<"\n A altura média das pessoas é: "<<media<<endl;
  esperarEnter();

}