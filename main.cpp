/*
Autores: 
João Henrique Jorge Carlos RA: 2840482121030
Vitor Hayaxibara Sampaio RA: 2840482121043
*/

// bibliotecas utilizadas:
#include <iostream>
#include <iomanip>
#include <math.h>
#include <locale.h>

// Login do modo administrador
#define senhaLogin 123

using namespace std;

/*
Declaração de variável utilizada na quantidade produtos
e calculo do lucro.
*/
int QntProd[6];
float LucroAtual = 0;

// Funções.
bool ChecarNumero(string str);
void Interface(string produtos[6]);
void ComprarProduto(int Dinheiro);
void ModoUsuario();
void ModoAdministrador();
void Login();
void ReporEstoque();
void VerificarFatura();
void QntInvalida();
void TipoInvalido();
// Função main responsável por rodar o programa.
int main() {
  string produtos[6];
  int Dinheiro;
  setlocale(LC_ALL, "Portuguese");

  for(int i=0;i<6;i++)
    {
      QntProd[i] = 7;
    }

  Login();
}

// Função para entrar no modo usuário.
void ModoUsuario(void)
  {
    string produtos[6];
    int Dinheiro;

    Interface(produtos);
    ComprarProduto(Dinheiro);
  }

// Função para entrar no modo administrador.
void ModoAdministrador(void)
  {
    string produtos[6];
    string Escolha;
    int Senha;

    cout << "Digite a senha para logar no modo administrador: ";
    cin >> Escolha;

    if(ChecarNumero(Escolha))
      {
        int Entrar = stoi(Escolha);

        if(Entrar == senhaLogin)
          { 
            cout << endl << "Bem vindo!, informe o número da opção desejada para realizar uma ação." << endl;
            cout << "1- Repor produtos faltantes" << endl << "2- Listar o inventario de produtos" << endl << "3- Listar o quanto a maquina ja faturou e pode faturar" << endl;

            cout << "Digite sua opção: ";
            cin >> Escolha;

            if(ChecarNumero(Escolha))
              {
                Entrar = stoi(Escolha);

                switch(Entrar)
                  {
                    case 1:
                      ReporEstoque();
                      Login();
                    break;
                
                    case 2:
                      Interface(produtos);
                      Login();
                    break;

                    case 3:
                      VerificarFatura();
                      Login();
                    break;

                    default:
                      TipoInvalido();
                  }
                }else{
                  TipoInvalido();
                    }
            }else{
              TipoInvalido();
                }
        }else{
          TipoInvalido();
            }
  }
// Função para fazer a escolha de login dos modos e/ou encerrar o programa.
void Login(void)
  {
    string Escolha;

    cout << " Opções: " << endl << "1- Usuário" << endl << "2- Administrador" << endl << "3- Encerrar o programa" << endl;
    cout << "informe o número da opção desejada: ";
    cin >> Escolha;

    if(ChecarNumero(Escolha))
      {
        int Modos = stoi(Escolha);

        switch(Modos)
          {
            case 1:
              ModoUsuario();
            break;

            case 2:
              ModoAdministrador();
            break;

            case 3:
              exit(3);
            break;

            default:
              TipoInvalido();
          }
      }else{
        TipoInvalido();
          }
  }

// Função responsável pela interface dos produtos.
void Interface(string produtos[6]) 
  {
    produtos[0] = "ID: 1 - Baconzitos | (55g) | R$ 3,69 |";
    produtos[1] = "ID: 2 - Cebolitos | (48g) | R$ 3,42 |";
    produtos[2] = "ID: 3 - Cheetos Mix | (45g) | R$ 3,69 |";
    produtos[3] = "ID: 4 - Doritos Queijo Nacho | (55g) | R$ 2,42 |";
    produtos[4] = "ID: 5 - Torcida JR Churrasco | (45g) | R$ 0,99 |";
    produtos[5] = "ID: 6 - Torcida JR Queijo | (45g) | R$ 0,99 |";

    cout << endl << "Produtos: " << endl;
    cout << "| " << "--------------------------------------" << endl;
    for (int i=0; i<6; i++)
      {
        cout << "| " << produtos[i] << " (" << QntProd[i]<< ") restantes" <<endl;
      }
    cout << "| " << "--------------------------------------" << endl;
  }

// Função responsável pela compra de produtos.
void ComprarProduto(int Dinheiro)
  {
    string Escolha;
    char Encerrar;
    string produtos[6];
    int aux;
    
    cout << "Por favor, ao realizar uma compra na máquina informe o ID correspondente ao produto de sua escolha." << endl << endl;

    cout << "Escreva o ID do produto que deseja comprar: ";
    cin >> Escolha;

    if(ChecarNumero(Escolha))
      {
        int ID = stoi(Escolha);
        if(ID > 0 && ID <= 6)
          {
            switch(ID)
              {
                case 1:
                  cout << "Por favor, informe o valor inserido na máquina. Aceitamos apenas cédulas! ";
                  cin >> Escolha;

                if(ChecarNumero(Escolha))
                  {
                    Dinheiro = stof(Escolha);
                    aux = Dinheiro;
                    if(aux == Dinheiro)
                      {
                        if(QntProd[0]>=1 && QntProd[0]<=7)
                          {
                            if(Dinheiro >= 3.69)
                              {
                                cout << fixed << setprecision(2);
                                cout << "Troco: R$ " << Dinheiro - 3.69 << endl;
                                QntProd[0]--;
                                LucroAtual += 3.69;
                              }else{
                                cout << "Quantidade insuficiente, volte com mais dinheiro por favor." << endl;
                                Login();
                                  }
                            cout << endl << "caso seja de seu agrado comprar mais produtos digite S, se não, digite N para voltar a tela de login. : ";
                            cin >> Encerrar;

                            if(Encerrar == 'S')
                              {
                                cout << endl;
                                Interface(produtos);
                                ComprarProduto(Dinheiro);
                              }else if(Encerrar == 'N')
                                {
                                  Login();
                                }else{
                                  TipoInvalido();
                                }
                            }else{
                              cout << "Infelizmente estamos sem esse produto no estoque, informe ao administrador para repor." << endl;
                              Login();
                                }
                        }else{
                          TipoInvalido();
                            }
                    }else{
                      TipoInvalido();
                        }
                break;
              
                case 2:
                  cout << "Por favor, informe o valor inserido na máquina. Aceitamos apenas cédulas! ";
                  cin >> Escolha;

                  if(ChecarNumero(Escolha))
                  {
                    int Dinheiro = stof(Escolha);
                    aux = Dinheiro;
                     if(aux == Dinheiro)
                       {
                         if(QntProd[1]>=1 && QntProd[1]<=7)
                           {
                             if(Dinheiro >= 3.42)
                               {
                                cout << fixed << setprecision(2);
                                cout << "Troco: R$ " << Dinheiro - 3.42 << endl;
                                QntProd[1]--;
                                LucroAtual += 3.42;
                               }else{
                                 cout << "Quantidade insuficiente, volte com mais dinheiro por favor.";
                                 Login();
                                   }
                              cout << endl << "caso seja de seu agrado comprar mais produtos digite S, se não, digite N para voltar a tela de login. : ";
                              cin >> Encerrar;

                              if(Encerrar == 'S')
                                {
                                  cout << endl;
                                  Interface(produtos);
                                  ComprarProduto(Dinheiro);
                                }else if(Encerrar == 'N')
                                  {
                                    Login();
                                  }else{
                                    TipoInvalido();
                                      }
                              }else{
                                cout << "Infelizmente estamos sem esse produto no estoque, informe ao administrador para repor." << endl;
                                Login();
                                  }
                          }else{
                            TipoInvalido();
                              }
                    }else{
                      TipoInvalido();
                        }
                break;

                case 3:
                  cout << "Por favor, informe o valor inserido na máquina. Aceitamos apenas cédulas! ";
                  cin >> Escolha;

                  if(ChecarNumero(Escolha))
                  {
                    int Dinheiro = stoi(Escolha);
                    aux = Dinheiro;
                    if(aux == Dinheiro)
                      {
                        if(QntProd[2]>=1 && QntProd[2]<=7)
                          {
                            if(Dinheiro >= 3.69)
                              {
                                cout << fixed << setprecision(2);
                                cout << "Troco: R$ " << Dinheiro - 3.69 << endl;
                                QntProd[2]--;
                                LucroAtual += 3.69;
                              }else{
                                cout << "Quantidade insuficiente, volte com mais dinheiro por favor.";
                                Login();
                                  }
                                cout << endl << "caso seja de seu agrado comprar mais produtos digite S, se não, digite N para para voltar a tela de login. : ";
                                cin >> Encerrar;

                            if(Encerrar == 'S')
                              {
                                cout << endl;
                                Interface(produtos);
                                ComprarProduto(Dinheiro);
                              }else if(Encerrar == 'N')
                                {
                                  Login();
                                }else{
                                 TipoInvalido();
                                    }
                            }else{
                              cout << "Infelizmente estamos sem esse produto no estoque, informe ao administrador para repor." << endl;
                              Login();
                                }
                        }else{
                          TipoInvalido();
                            }
                  }else{
                    TipoInvalido();
                  }
                break;

                case 4:
                  cout << "Por favor, informe o valor inserido na máquina. Aceitamos apenas cédulas! ";
                  cin >> Escolha;

                  if(ChecarNumero(Escolha))
                  {
                    int Dinheiro = stoi(Escolha);
                    aux = Dinheiro;
                    if(aux == Dinheiro)
                      {
                        if(QntProd[3]>=1 && QntProd[3]<=7)
                          {
                            if(Dinheiro >= 2.42)
                              {
                                cout << fixed << setprecision(2);
                                cout << "Troco: R$ " << Dinheiro - 2.42 << endl;
                                QntProd[3]--;
                                LucroAtual += 2.42;
                              }else{
                                cout << "Quantidade insuficiente, volte com mais dinheiro por favor.";
                                Login();
                                 }
                            cout << endl << "caso seja de seu agrado comprar mais produtos digite S, se não, digite N para voltar a tela de login. : ";
                            cin >> Encerrar;

                            if(Encerrar == 'S')
                              {
                                cout << endl;
                                Interface(produtos);
                                ComprarProduto(Dinheiro);
                              }else if(Encerrar == 'N')
                                {
                                  Login();
                                }else{
                                  TipoInvalido();
                                    }
                            }else{
                              cout << "Infelizmente estamos sem esse produto no estoque, informe ao administrador para repor." << endl;
                              Login();
                                }
                        }else{
                          TipoInvalido();
                           }
                  }else{
                    TipoInvalido();
                  }
                break;

                case 5:
                  cout << "Por favor, informe o valor inserido na máquina. Aceitamos apenas cédulas! ";
                  cin >> Escolha;

                  if(ChecarNumero(Escolha))
                    {
                      int Dinheiro = stoi(Escolha);
                      aux = Dinheiro;
                      if(aux == Dinheiro)
                        {
                          if(QntProd[4]>=1 && QntProd[4]<=7)
                            {
                              if(Dinheiro >= 0.99)
                                {
                                  cout << fixed << setprecision(2);
                                  cout << "Troco: R$ " << Dinheiro - 0.99 << endl;
                                  QntProd[4]--;
                                  LucroAtual += 0.99;
                                }else{
                                  cout << "Quantidade insuficiente, volte com mais dinheiro por favor.";
                                  Login();
                                   }
                              cout << endl << "caso seja de seu agrado comprar mais produtos digite S, se não, digite N para voltar a tela de login. : ";
                              cin >> Encerrar;

                              if(Encerrar == 'S')
                                {
                                  cout << endl;
                                  Interface(produtos);
                                  ComprarProduto(Dinheiro);
                                }else if(Encerrar == 'N')
                                  {
                                    Login();
                                  }else{
                                    TipoInvalido();
                                      }
                              }else{
                                cout << "Infelizmente estamos sem esse produto no estoque, informe ao administrador para repor." << endl;
                                Login();
                                  }
                          }else{
                            TipoInvalido();
                              }
                  }else{
                    TipoInvalido();
                  }
                break;

                case 6:
                  cout << "Por favor, informe o valor inserido na máquina. Aceitamos apenas cédulas! ";
                  cin >> Escolha;

                  if(ChecarNumero(Escolha))
                  {
                    int Dinheiro = stoi(Escolha);
                    aux = Dinheiro;
                    if(aux == Dinheiro)
                      {
                        if(QntProd[5]>=1 && QntProd[5]<=7)
                          {
                            if(Dinheiro >= 0.99)
                              {
                                cout << fixed << setprecision(2);
                                cout << "Troco: R$ " << Dinheiro - 0.99 << endl;
                                QntProd[5]--;
                                LucroAtual += 0.99;
                              }else{
                                cout << "Quantidade insuficiente, volte com mais dinheiro por favor.";
                                Login();
                                  }
                            cout << endl << "caso seja de seu agrado comprar mais produtos digite S, se não, digite N para para voltar a tela de login. : ";
                            cin >> Encerrar;

                            if(Encerrar == 'S')
                              {
                                cout << endl;
                                Interface(produtos);
                                ComprarProduto(Dinheiro);
                              }else if(Encerrar == 'N')
                                {
                                  Login();
                                }else{
                                  TipoInvalido();
                                    }
                            }else{
                              cout << "Infelizmente estamos sem esse produto no estoque, informe ao administrador para repor." << endl;
                              Login();
                                }
                        }else{
                          TipoInvalido();
                            }
                  }else{
                    TipoInvalido();
                  }
                break;

                default:
                  cout << endl << "Por favor, informe o ID correto." << endl;
                  Interface(produtos);
                  ComprarProduto(Dinheiro);
                break;
              }
            }else{
              cout << endl << "Por favor, informe os numeros corretos!" << endl;
              Interface(produtos);
              ComprarProduto(Dinheiro);
                }
        }else{
          cout << endl << "Por favor, informe o ID correto." << endl;
          Interface(produtos);
          ComprarProduto(Dinheiro);
            }
  }

// função responsável pela reposição de estoque.
  void ReporEstoque(void)
    {
      string ID;
      char resposta;
      int resposta2;
      int valorEstoque;
      int id;
      string resposta3;

      cout << "Gostaria de repor todo o estoque? Digite S para repor, caso contrario digite N: ";
      cin >> resposta;


      if (resposta == 'S')
        {
          if(QntProd[0] == 7 && QntProd[1] == 7 && QntProd[2] == 7 && QntProd[3] == 7 && QntProd[4] == 7 && QntProd[5] == 7)
            {
              cout << "O estoque ja está cheio. Por favor, compre alguns produtos <3!" << endl << endl;
              Login();
            }else{
              for(int i=0;i<6;i++)
                {
                  QntProd[i] = 7;
                }
              cout << "Estoque completo!" << endl;
              Login();
                }
        }
    else if (resposta == 'N')
      {
        cout << "Informe o código (ID) do produto que deseja repor.: ";
        cin >> ID;

        if(ChecarNumero(ID))
          {
            id = stoi(ID);
            while (id < 1 || id > 6)
              {
                cout << "Informe um código (ID) válido!" << endl;
                cout << "Informe o código (ID) do produto que deseja repor.: ";
                cin >> id;
              }
            }else{
              TipoInvalido();
                }
      }else{
        TipoInvalido();
          }
    
    switch(id)
      {
        case 1:
          cout << "Informe o quanto gostaria de repor." << endl;
          cin >> resposta3;
          
          if(ChecarNumero(resposta3))
            {
              resposta2 = stoi(resposta3);
              valorEstoque = resposta2 + QntProd[0];
              
              if(valorEstoque <= 7 && resposta2 > 0)
                {
                  cout << "Produto reposto!" << endl;
                  QntProd[0] = valorEstoque;
                }else{
              QntInvalida();
                    }
            }else
              TipoInvalido();
        break;

        case 2:
          cout << "Informe o quanto gostaria de repor: ";
          cin >> resposta3;
          
          if(ChecarNumero(resposta3))
            {
              resposta2 = stoi(resposta3);
              valorEstoque = resposta2 + QntProd[1];
              if(valorEstoque <= 7 && resposta2 > 0)
                {
                  cout << "Produto reposto!" << endl;
                  QntProd[1] = valorEstoque;
                }
              else{
              QntInvalida();
                }
            }else
              TipoInvalido();
        break;

        case 3:
          cout << "Informe o quanto gostaria de repor: ";
          cin >> resposta3;
          
          if(ChecarNumero(resposta3))
            {
              resposta2 = stoi(resposta3);
              valorEstoque = resposta2 + QntProd[2];
              if(valorEstoque <= 7 && resposta2 > 0)
                {
                  cout << "Produto reposto!" << endl;
                  QntProd[2] = valorEstoque;
                }else{
                  QntInvalida();
                    }
            }else
              TipoInvalido();
        break;

        case 4:
          cout << "Informe o quanto gostaria de repor: ";
          cin >> resposta3;
          
          if(ChecarNumero(resposta3))
            {
              resposta2 = stoi(resposta3);
              valorEstoque = resposta2 + QntProd[3];
              if(valorEstoque <= 7 && resposta2 > 0)
                {
                  cout << "Produto reposto!" << endl;
                  QntProd[3] = valorEstoque;
                }else{
              QntInvalida();
                    }
            }else
              TipoInvalido();
        break;

        case 5:
          cout << "Informe o quanto gostaria de repor: ";
          cin >> resposta3;
          
          if(ChecarNumero(resposta3))
            {
              resposta2 = stoi(resposta3);
              valorEstoque = resposta2 + QntProd[4];
              if(valorEstoque <= 7 && resposta2 > 0)
                {
                  cout << "Produto reposto!" << endl;
                  QntProd[4] = valorEstoque;
                }else{
                  QntInvalida();
                    }
            }else
              TipoInvalido();
        break;

        case 6:
          cout << "Informe o quanto gostaria de repor: ";
          cin >> resposta3;
          
          if(ChecarNumero(resposta3))
            {
              resposta2 = stoi(resposta3);
              valorEstoque = resposta2 + QntProd[5];
              if(valorEstoque <= 7 && resposta2 > 0)
                {
                  cout << "Produto reposto!" << endl;
                  QntProd[5] = valorEstoque;
                }else{
                  QntInvalida();
                    }
            }else
              TipoInvalido();
        break;
      }
    }

// Função responsável por checar se o que foi inserido é um número.
bool ChecarNumero(string str)
  {
    for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
        return false; 
    return true;
  }

// Função para Verificar os lucros da máquina de vendas.
void VerificarFatura(void)
  {
    float LucroMax;
    cout << "Lucro atual: R$ " << LucroAtual << endl;
    LucroMax = (7 * 3.69) + (7 * 3.42) + (7 * 3.69) + (7 * 2.42) + (7 * 0.99) + (7 * 0.99) - LucroAtual;
    cout << "Quanto ainda pode faturar: R$" << LucroMax << endl;
  }

// Função para informar que a quantidade é inválida.
void QntInvalida(void)
  {
    cout << "Quantidade inválida, a quantidade máxima de cada produto é 7 e só é possível repor 1 ou mais produtos." << endl;
    Login();
  }
  
void TipoInvalido(void)
  {
    cout << "Informe corretamente o que foi proposto!" << endl << endl;
    Login();
  }