#include "ExpressaoDivisao.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoDivisao::ExpressaoDivisao() {}

tuple<Tipo, int, float> ExpressaoDivisao::avalia(stack<Tabela*> &pilha_de_tabelas) {
    tuple<Tipo, int, float> resultado;
    
    // Avalia a expressão da esquerda
    auto esq = esquerda->avalia(pilha_de_tabelas);
    
    // Avalia a expressão da direita
    auto dir = direita->avalia(pilha_de_tabelas);

    // Se os dois operandos forem inteiros
    if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::INTEGER) {
        int divisor = get<1>(dir);
        if (divisor != 0) {
            int div = get<1>(esq) / divisor;
            resultado = make_tuple(Tipo::INTEGER, div, 0.0f);
        } else {
            throw runtime_error("Erro: Divisão por zero");
        }
    }
    // Se os dois operandos forem float
    else if (get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::FLOAT) {
        float divisor = get<2>(dir);
        if (divisor != 0.0f) {
            float div = get<2>(esq) / divisor;
            resultado = make_tuple(Tipo::FLOAT, 0, div);
        } else {
            throw runtime_error("Erro: Divisão por zero");
        }
    }
    // Se o operando da esquerda for INTEGER e o da direita for FLOAT
    else if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::FLOAT) {
        float divisor = get<2>(dir);
        if (divisor != 0.0f) {
            float div = get<1>(esq) / divisor;
            resultado = make_tuple(Tipo::FLOAT, 0, div);
        } else {
            throw runtime_error("Erro: Divisão por zero");
        }
    }
    // Se o operando da esquerda for FLOAT e o da direita for INTEGER
    else if (get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::INTEGER) {
        int divisor = get<1>(dir);
        if (divisor != 0) {
            float div = get<2>(esq) / divisor;
            resultado = make_tuple(Tipo::FLOAT, 0, div);
        } else {
            throw runtime_error("Erro: Divisão por zero");
        }
    }
    // Se houver tipos incompatíveis
    else {
        throw runtime_error("Erro: Expressão de divisão com tipos incompatíveis");
    }
  
    return resultado;
}

void ExpressaoDivisao::debug_com_tab(int tab) {
    tab3(tab);
    cerr << "INICIO DIVISAO [ " << endl;
    esquerda->debug_com_tab(tab + 1);
    tab3(tab);
    cerr << " / "<< endl ;
    direita->debug_com_tab(tab + 1);
    tab3(tab);
    cerr << " ] FIM DIVISAO" << endl;
}
