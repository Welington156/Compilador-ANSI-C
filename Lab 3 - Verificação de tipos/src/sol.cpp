#include <algorithm>
#include<vector>
#include<string>
#include<iostream>
#include <fstream>   
#include<sstream>
#include<map>
#include<stack>
using namespace std;

#include "Gramatica.hpp"
#include "TabelaLR1.hpp"
#include "Arvore.hpp"
#include "Parser.hpp"
#include "src-gram-ansic/Funcao.hpp"
#include "src-gram-ansic/Analisador.hpp"


int main(int argc, char * argv[]) {
  if (argc != 3 && argc != 1) {
    cerr << "Parametros nomes dos arquivos: 1) csv com gramática e 2) csv com tabela LR1" << endl;
    return 1;
  }
  string nome_gramatica, nome_tab_lr1;
  if (argc == 1) {
    //cerr << "Valores padrao utilizados: gramatica.conf e tabela_lr1.conf" << endl;
    nome_gramatica = string("gramatica.conf");
    nome_tab_lr1 = string("tabela_lr1.conf");
  } else {
    nome_gramatica = string(argv[1]);
    nome_tab_lr1 = string(argv[2]);
  }

  ifstream arq_gramatica(nome_gramatica);
  ifstream arq_tabela_lr1(nome_tab_lr1);
  if (arq_tabela_lr1.fail() || arq_gramatica.fail()) {
    cerr << "Falha ao abrir arquivos: " << 
      ((arq_gramatica.fail()) ? nome_gramatica : "") << ", " << 
      ((arq_tabela_lr1.fail()) ? nome_tab_lr1 : "") << endl;
    return 1;    
  }
  Parser parser(arq_gramatica, arq_tabela_lr1);
  parser.tabela.debug();
  parser.gram.debug();

  
  Arvore_parse arv = parser.executa_parse(cin);
  cerr << "Parse executado" << endl;

  arv.debug();

  //INICIO -> S S -> INPUT INPUT -> FUNCTION INPUT

  Funcao* func = Funcao::extrai_funcao(arv.raiz -> filhos[0] -> filhos[0]);

  func->debug();

  // Exemplo de chamada do analisador semantico.
  vector<tuple<Tipo, int, float>> parametros_passados;
	for (int i = 1; i <= 3; ++i) {
    // Aqui você está assumindo que todos os parâmetros são do tipo INTEGER. 
    // Se precisar de FLOAT, você pode alterar o segundo valor da tupla para 0 e o terceiro para o valor float.
    		parametros_passados.push_back(make_tuple(Tipo::INTEGER, i * 10, 0.0f));
	}

	Analisador ana;
	cout << ana.calcula_ultimo_valor(func, parametros_passados) << endl;
  
  return 0;
  
}
