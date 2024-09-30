#ifndef _EXPRESSAO_AND_HPP_
#define _EXPRESSAO_AND_HPP_

#include "Expressao.hpp"
using namespace std;

class ExpressaoAnd : public Expressao {
public:
    Expressao* esquerda;
    Expressao* direita;
    ExpressaoAnd();
    virtual tuple<Tipo, int, float> avalia(stack<Tabela*>& pilha_de_tabelas);
    void debug_com_tab(int tab);
};

#endif