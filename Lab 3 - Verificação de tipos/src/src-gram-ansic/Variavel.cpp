#include "Variavel.hpp"
#include "ID.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

// Função para extrair a lista de parâmetros (não vazia)
vector<Variavel*> Variavel::extrai_lista_nao_vazia_parametros(No_arv_parse* no) {
    vector<Variavel*> res;
    // PARAM_LIST_AUX -> PARAM
    res.push_back(extrai_variavel_PARAM(no->filhos[0]));
    if (no->filhos.size() == 1) return res;
    // PARAM_LIST_AUX -> PARAM COMMA PARAM_LIST_AUX
    vector<Variavel*> restante = extrai_lista_nao_vazia_parametros(no->filhos[2]);
    res.insert(res.end(), restante.begin(), restante.end());
    return res;
}

// Função para extrair a lista de parâmetros 
vector<Variavel *> Variavel::extrai_lista_parametros(No_arv_parse* no) {
    if (no->filhos.size() == 0) return vector<Variavel*>();
    // PARAM_LIST -> PARAM_LIST_AUX
    return extrai_lista_nao_vazia_parametros(no->filhos[0]);
}

// Função para extrair uma variável a partir de um parâmetro
Variavel* Variavel::extrai_variavel_PARAM(No_arv_parse* no) {
    Variavel* res = new Variavel();
    // PARAM -> TYPE ID
    res->tipo = ID::extrai_ID(no->filhos[0]->filhos[0]);
    res->nome = ID::extrai_ID(no->filhos[1]);
    return res;
}


Variavel *Variavel::extrai_variavel(No_arv_parse *no)
{

  Variavel *variavel = new Variavel();
  variavel->nome = ID::extrai_ID(no->filhos[1]);
  variavel->tipo = ID::extrai_ID(no->filhos[0]->filhos[0]);
  return variavel;
}

// Função de debug para exibir variáveis com tabulação
void Variavel::debug_com_tab(int tab) {
    //tab3(tab);
    cerr << "[" << nome->nome << ":" <<  tipo->nome << "] Variavel Declarada" << endl;
}