#include "ComandoIf.hpp"

ComandoIf::ComandoIf() {
    expressao = nullptr;
    comando = vector<Comando*>();
    comando_else = vector<Comando*>();
}

tuple<Tipo, int, float> ComandoIf::avalia_comando(stack<Tabela*>& pilha_de_tabelas) {
    if (expressao != nullptr) {
        // Avaliar a expressão lógica
        auto resultado = expressao->avalia(pilha_de_tabelas);

        // Verificar se a expressão é verdadeira (considerando que expressao agora avalia int ou float)
        bool condicao = static_cast<bool>(get<1>(resultado) || get<2>(resultado));
        if (condicao) {
            // Executar os comandos do bloco "if"
            vector<tuple<Tipo, int, float>> resultados;
            for (auto cmd : comando) {
                auto res = cmd->avalia_comando(pilha_de_tabelas);

                resultados.push_back(res);
            }

            // Retornar o resultado da execução dos comandos "if"
            return resultados.back();
        } else {
            // Executar os comandos do bloco "else" (se houver)
            vector<tuple<Tipo, int, float>> resultados;
            for (auto cmd : comando_else) {
                auto res = cmd->avalia_comando(pilha_de_tabelas);
                
                resultados.push_back(res);
            }

            // Retornar o resultado da execução dos comandos "else"
            return resultados.back();
        }
    }
    
    // Retornar um valor padrão se a expressão for nula ou não houver comando a ser executado
    return make_tuple(Tipo::INTEGER, 0, 0.0f);
}

void debug_comandoss(const vector<Comando*> &coms, int tab) {
  for (int ic = 0; ic < coms.size(); ++ic) {
    coms[ic]->debug_com_tab(tab + 1);
  }
}
void ComandoIf::debug_com_tab(int tab)
{
  tab3(tab);
  cerr << "IF ( ";
  expressao->debug_com_tab(tab);  
  cerr << " )" << endl;
    tab3(tab+1);
    cerr << "INICIO BLOCO IF { " << endl;
  debug_comandoss(comando, 1);
  tab3(tab+1);
  cerr << "} FIM BLOCO IF" << endl;
  
    if(comando_else.size() != 0){
        tab3(tab+1);
        cerr << "INICIO BLOCO ELSE { " << endl;
        debug_comandoss(comando_else, 1);
        tab3(tab+1);
        cerr << "} FIM BLOCO IELSE" << endl;
    }
}