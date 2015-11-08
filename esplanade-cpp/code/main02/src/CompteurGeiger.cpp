#include <fonctions.h>
#include <CompteurGeiger.h>

using namespace rad;

CCompteurGeiger::CCompteurGeiger(){
    m_nom="radex RD 1503";

    CIntervalleEnergie c;
      Alpha,Electron,Positron,Gamma,X,Beta
    c.m_type=TypeRadioactivite::Beta;
        c.m_min=250;
        c.m_max=3500;
        c.m_fonction="intervalle(x,c.m_min,c.m_max)";
        m_intervalles.push_back(c);
    c.m_type=TypeRadioactivite::X;
        c.m_min=30;
        c.m_max=3000;
        c.m_fonction="intervalle(x,c.m_min,c.m_max)";
        m_intervalles.push_back(c);
    c.m_type=TypeRadioactivite::Gamma;
        c.m_min=100;
        c.m_max=1250;
        c.m_fonction="intervalle(x,c.m_min,c.m_max)";
        m_intervalles.push_back(c);


    };

CCompteurGeiger::~CCompteurGeiger(){};


/*
radex RD 1503
keV
beta : 250 à 3500
X : 30 à 3000
gamma : 100 à 1250



*/
