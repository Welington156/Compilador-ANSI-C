#ifndef _VARIAVEL_HPP_
#define _VARIAVEL_HPP_

#include "ID.hpp"
#include "../Arvore.hpp"
#include <vector>
using namespace std;

class Variavel {
public:
  ID* tipo;
  ID* nome;

  // Métodos para extrair listas de parâmetros
  static vector<Variavel*> extrai_lista_parametros(No_arv_parse* no);
  static vector<Variavel*> extrai_lista_nao_vazia_parametros(No_arv_parse* no);
  static Variavel* extrai_variavel_PARAM(No_arv_parse* no);
  static Variavel *extrai_variavel(No_arv_parse *no);
  
  // Método de debug
  void debug_com_tab(int tab);
};

#endif