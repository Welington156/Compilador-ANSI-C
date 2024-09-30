#include "Funcao.hpp"
#include "../debug-util.hpp"
#include <iostream>

Funcao::Funcao() {
}

Funcao* Funcao::extrai_funcao(No_arv_parse *no) {
  Funcao* res = new Funcao();

  if (no->regra != 10) return NULL;
  // FUNCTION -> TYPE ID LPAREN PARAM_LIST RPAREN BLOCK
  res->tipo_retorno = ID::extrai_ID(no->filhos[0]->filhos[0]);  // TYPE
  res->nome_funcao = ID::extrai_ID(no->filhos[1]);   // ID
  res->parametros = Variavel::extrai_lista_parametros(no->filhos[3]);  // PARAM_LIST
  //BLOCK -> LBRACE STATEMENT_S RBRACE
  res->comandos = Comando::extrai_lista_comandos(no->filhos[5]->filhos[1]);  // BLOCK
  //cerr << no->regra;

  return res;
}


void debug_variaveis(const vector<Variavel*> &vars, int tab) {
  for (int iv = 0; iv < vars.size(); ++iv) {
    tab3(tab);
    vars[iv]->debug_com_tab(tab + 1);
  }
}

void debug_comandos(const vector<Comando*> &coms, int tab) {
  for (int ic = 0; ic < coms.size(); ++ic) {
    coms[ic]->debug_com_tab(tab + 1);
  }
}

void Funcao::debug() {
  
  if (tipo_retorno == NULL) cerr << "TR NULL" << endl;
  if (nome_funcao == NULL) cerr << "NF NULL" << endl;
  cerr << "FUNCTION:" <<endl;
  cerr << "[ TYPE = " << tipo_retorno->nome << "  ID = " << nome_funcao->nome;
  cerr << "  PARAMETROS = ( ";

  fflush(stderr);

  if(parametros.size()==0)
    cerr << "Sem Parametros ";
  else{

    for (int i_par = 0; i_par < parametros.size(); ++i_par) {
      cerr << (parametros[i_par])->tipo->nome << " " <<
        (parametros[i_par])->nome->nome;
          if(i_par != parametros.size()-1)
            cerr << ", ";
    }
  } 

  cerr << ") ]" << endl;
  cerr << "INICIO BLOCO FUNCTION {" << endl;
  debug_comandos(comandos, 1);
  cerr << "} FIM BLOCO FUNCTION" << endl;
  
}