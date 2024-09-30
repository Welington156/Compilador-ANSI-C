#include "Comando.hpp"
#include "ComandoAtribuicao.hpp"
#include "ComandoIf.hpp"
#include "ComandoDeclaracao.hpp"
#include "ID.hpp"
#include "Variavel.hpp"
#include <iostream>
#include "../debug-util.hpp"

vector<Comando *> Comando::extrai_lista_comandos(No_arv_parse *no)
{

  switch (no->regra)
  {
    //STATEMENT_S ->
    case 13:
    {
      return vector<Comando *>();
    }
    // STATEMENT_S -> STATEMENT STATEMENT_S
    case 12:
    {
      vector<Comando *> res;
      Comando *c = extrai_comando(no->filhos[0]->filhos[0]);
      if (c != NULL)
        res.push_back(c);
      vector<Comando *> restante = extrai_lista_comandos(no->filhos[1]);
      res.insert(res.end(), restante.begin(), restante.end());
      return res;
    }
    case 15:
    {
      // STATEMENT -> DECLARATION
      vector<Comando *> res;
      res.push_back(extrai_comando(no->filhos[0]));
      return res;
    }

    case 16:
    {
      //STATEMENT -> EXPRESSION SEMICOLON ;
      vector<Comando *> res;
      res.push_back(extrai_comando(no->filhos[0]));
      return res;
    }

    /*

    case 17:
    {
      //STATEMENT -> RETURN EXPRESSION SEMICOLON
      vector<Comando *> res;
      res.push_back(extrai_comando(no));
      return res;
    }

    */
    case 18:
    {
     // STATEMENT -> IF_STATEMENT
      vector<Comando *> cmd;
      cmd.push_back(extrai_comando(no->filhos[0]));
      return cmd;
    }

    default:
    {
     return vector<Comando *>();
    }
  }

}
Comando *Comando::extrai_comando(No_arv_parse *no)
{

  switch (no->regra)
  {
    case 20:
    {
      // IF_STATEMENT -> IF LPAREN EXPRESSION RPAREN BLOCK ELSE_STATEMENT
      ComandoIf *res = new ComandoIf();
      //cerr << "IF" <<endl;
      res->expressao = Expressao::extrai_expressao(no->filhos[2]);
      res->comando = extrai_lista_comandos(no->filhos[4]->filhos[1]);
      res->comando_else = extrai_lista_comandos(no->filhos[5]->filhos[1]->filhos[1]);
      return res;
    }
    

    case 7:
    {
      //DECLARATION -> TYPE ID SEMICOLON
      //ComandoDeclaracao 
      ComandoDeclaracao  *res = new ComandoDeclaracao();
      res->variavel = Variavel::extrai_variavel(no);
      return res;
    }

    case 8:
    {
      //DECLARATION -> TYPE ID ASSIGN EXPRESSION SEMICOLON
      //ComandoDeclaracao 
      ComandoDeclaracao  *res = new ComandoDeclaracao();
      res->variavel = Variavel::extrai_variavel(no);
      res->expressao = Expressao::extrai_expressao(no->filhos[3]);
      return res;
    }

    case 39:
    { //EXPRESSION -> B ASSIGN_OP EXPRESSION

      ComandoAtribuicao *res13 = new ComandoAtribuicao();
      res13->esquerda = ID::extrai_ID(no->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]);
      //cerr <<"Regra id"<< no->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]->filhos[0]->regra <<endl;
      res13->direita = Expressao::extrai_expressao(no->filhos[2]);

      return res13;
    }

    default:
    {
      return NULL;
    }
  }
}


tuple<Tipo, int, float> Comando::avalia_comando(stack<Tabela *> &simbolos)
{
  cout << "Executa comando genérico" << endl;
  return make_tuple(Tipo::INTEGER, 0, 0);
}


void Comando::debug_com_tab(int tab)
{
  tab3(tab);
  cerr << "Comando generico" << endl;
}
