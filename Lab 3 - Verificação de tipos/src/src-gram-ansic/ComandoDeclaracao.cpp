#include "ComandoDeclaracao.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ComandoDeclaracao::ComandoDeclaracao()
{
    variavel = NULL;
    expressao = NULL;
}

tuple<Tipo, int, float> ComandoDeclaracao::avalia_comando(stack<Tabela *> &pilha_de_tabelas)
{
    Tabela *tabela_atual = pilha_de_tabelas.top();
    string nome_variavel = variavel->nome->nome;

    // Verifica se a variável já está declarada na tabela atual
    if (tabela_atual->tabela_simbolos.find(nome_variavel) != tabela_atual->tabela_simbolos.end())
    {
        throw runtime_error("Erro: Variável '" + nome_variavel + "' já declarada.");
    }

    // Obtém o tipo da variável
    string tipo_variavel = variavel->tipo->nome;

    // Avalia a expressão e obtém o resultado, se houver
    tuple<Tipo, int, float> valor;
    if (expressao != NULL)
    {
        valor = expressao->avalia(pilha_de_tabelas);
        Tipo tipo_expressao = get<0>(valor);
        
    }
    else
    {
        // Inicializa a variável sem valor (padrão)
        if (tipo_variavel == "int")
        {
            valor = make_tuple(Tipo::INTEGER, 0, 0.0f);
        }
        else if (tipo_variavel == "float")
        {
            valor = make_tuple(Tipo::FLOAT, 0, 0.0f);
        }
    }

    // Insere a variável na tabela de símbolos
    tabela_atual->adicionar_simbolo(nome_variavel, new Valor(valor));

    // Retorna a tupla com as informações da variável
    return valor;
}

void ComandoDeclaracao::debug_com_tab(int tab)
{
    tab3(tab);
    cerr << "INICIO DECLARACAO: " << variavel->nome->nome << " [" << variavel->tipo->nome << "] " << " = ";
    if (expressao != NULL)
    {
        expressao->debug_com_tab(tab);
    }
    else
    {
        cerr << "(Sem Expressão)" << endl;
    }
    tab3(tab);
    cerr << "FIM DECLARACAO" << endl;
}