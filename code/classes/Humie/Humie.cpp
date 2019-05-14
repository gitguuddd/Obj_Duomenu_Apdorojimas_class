//
// Created by Mindaugas K on 5/2/2019.
#include "Humie.h"

void Humie::scan_name(istringstream &t_stream){
    t_stream>>m_name;
    if(t_stream.fail())
        m_name="Vardas";
}
void Humie::scan_surname(istringstream &t_stream){
    t_stream>>m_surname;
    if(t_stream.fail())
        m_surname="Pavarde";
}
