//
// Created by betelgeuse on 20/03/25.
//

#include "Festa.h"
#include "../ClassesAjudantes/DateUtils.hpp"


namespace Sistema {
    Parcela *Festa::getParcelasFesta() {
        return parcela;
    }

    void Festa::imprimeFesta() {
        printf("Local: %s, preco: %f, data: %s\n", local.c_str(), precoPago, cpp_util::formatDate(data, cpp_util::DATE_FORMAT_PT_BR_SHORT).c_str());
        if (listaConvidados.size()>0){
            printf("Convidados:\n");
            for(string conv : listaConvidados){
                printf("%s\n", conv.c_str());
            }
        }
        
    }

    Festa::Festa(const string &_local, double preco_pago, time_t _data, const string &_horario,
        const list<string> &lista_convidados, Parcela *_parcela) {
        local = _local;
        precoPago = preco_pago;
        data = _data;
        horario = _horario;
        listaConvidados = lista_convidados;
        parcela = _parcela;

    }

    double Festa::getPrecoPago(){
        return precoPago;
    }

    list<string> Festa::getListaConvidados(){
        return listaConvidados;
    }
} // Sistema