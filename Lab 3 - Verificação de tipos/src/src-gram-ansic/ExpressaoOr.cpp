#include "ExpressaoOr.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoOr::ExpressaoOr() {}

tuple<Tipo, int, float> ExpressaoOr::avalia(stack<Tabela*>& pilha_de_tabelas) {  
    auto esq = esquerda->avalia(pilha_de_tabelas);
    auto dir = direita->avalia(pilha_de_tabelas);

    // Avalia o valor do operando da esquerda
    bool esq_valido = (get<0>(esq) == Tipo::INTEGER) ? (get<1>(esq) != 0) : (get<2>(esq) != 0.0);

    // Avalia o valor do operando da direita
    bool dir_valido = (get<0>(dir) == Tipo::INTEGER) ? (get<1>(dir) != 0) : (get<2>(dir) != 0.0);

    // Calcula o resultado da operação OR
    int resultado = (esq_valido || dir_valido) ? 1 : 0;
    
    return make_tuple(Tipo::INTEGER, resultado, 0.0);
}

void ExpressaoOr::debug_com_tab(int tab) {
    tab3(tab);
    cerr << " INICIO OR ["<< endl;
    esquerda->debug_com_tab(tab+1);
    tab3(tab);
    cerr << " || " << endl;
    direita->debug_com_tab(tab+1);
    tab3(tab);
    cerr << "] FIM OR"<< endl;
}