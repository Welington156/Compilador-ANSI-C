#include "ExpressaoIgual.hpp"
#include <iostream>
#include "../debug-util.hpp"
using namespace std;

ExpressaoIgual::ExpressaoIgual() {}

tuple<Tipo, int, float> ExpressaoIgual::avalia(stack<Tabela*> &pilha_de_tabelas) {
    auto esq = esquerda->avalia(pilha_de_tabelas);
    auto dir = direita->avalia(pilha_de_tabelas);

    // Se ambos os operandos forem inteiros
    if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::INTEGER) {
        int resultado = (get<1>(esq) == get<1>(dir)) ? 1 : 0;
        return make_tuple(Tipo::INTEGER, resultado, 0.0f);
    } 
    // Se ambos os operandos forem floats
    else if (get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::FLOAT) {
        int resultado = (get<2>(esq) == get<2>(dir)) ? 1 : 0;
        return make_tuple(Tipo::INTEGER, resultado, 0.0f);
    } 
    // Se o operando da esquerda for INTEGER e o da direita for FLOAT
    else if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::FLOAT) {
        int resultado = (static_cast<float>(get<1>(esq)) == get<2>(dir)) ? 1 : 0;
        return make_tuple(Tipo::INTEGER, resultado, 0.0f);
    } 
    // Se o operando da esquerda for FLOAT e o da direita for INTEGER
    else if (get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::INTEGER) {
        int resultado = (get<2>(esq) == static_cast<float>(get<1>(dir))) ? 1 : 0;
        return make_tuple(Tipo::INTEGER, resultado, 0.0f);
    }
    // Se houver tipos incompatíveis
    else {
        throw runtime_error("Erro: ExpressaoIgual com tipos incompatíveis.");
    }
}

void ExpressaoIgual::debug_com_tab(int tab) {
    //tab3(tab);
    cerr << "INICIO EXP [ ";
    esquerda->debug_com_tab(tab + 1);
    //tab3(tab);
    cerr << " == ";
    direita->debug_com_tab(tab + 1);
    //tab3(tab);
    cerr << " ] FIM EXP ";
}