#ifndef COMPTEURGEIGER_H_INCLUDED
#define COMPTEURGEIGER_H_INCLUDED

#include <fonctions.h>
#include <NamespaceRad.h>


using namespace rad;



class CIntervalleEnergie
{
    public:
        string m_nom;
        CIntervalleEnergie();
        virtual ~CIntervalleEnergie();
        TypeRadioactivite m_type; /**<  type de radiation*/
        float m_min,m_max;/**< min et max de l'intervalle de lecture  */
        string m_fonction; /**< fonction exprimant l'efficacité pour la lecture */

};

class CCompteurGeiger
{
    public:
        string m_nom;
        CCompteurGeiger(string);
        virtual ~CCompteurGeiger();
        std::vector<CIntervalleEnergie> m_intervalles;/**< les intervalles de lecture des radiations */
        };


/*
radex RD 1503
keV
beta : 250 à 3500
X : 30 à 3000
gamma : 100 à 1250



*/


#endif // COMPTEURGEIGER_H_INCLUDED
