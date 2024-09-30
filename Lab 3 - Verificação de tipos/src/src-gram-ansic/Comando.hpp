#ifndef _COMANDO_HPP_
#define _COMANDO_HPP_
#include <vector>
#include <stack>
#include <iostream>
#include <tuple>
#include "Tabela.hpp"
#include "../Arvore.hpp"

using namespace std;



class Comando {
public:
  
  static vector<Comando*> extrai_lista_comandos(No_arv_parse* no);
  static Comando* extrai_comando(No_arv_parse* no);
  virtual void debug_com_tab(int tab);
  virtual tuple<Tipo,int,float> avalia_comando(stack<Tabela*> &simbolos);
};

#endif