#include <CIsotope.h>
#include <CModeDeDesintegration.h>

using namespace rad;

//std::map< Isotopes , Isotope* >  Isotope::m_isotopes();
/*
Isotope::Initialise ()
{
    m_ModesDeDesintegration

    m_isotopes.insert (Isotopes::U235,  new Isotope()   )
    m_isotopes[ Isotopes::U235_1 ].m_demi_vie =1.0E5 ;
    m_isotopes[ Isotopes::U235_1 ].m_type =TypeRadioactivite::Gamma;
    m_isotopes[ Isotopes::U235_1 ].m_MultHumain =1.0 ;
    m_isotopes[ Isotopes::U235_1 ].m_MultCompteurGeiger =1.0 ;

    new isotope U235;

}
*/


CIsotope::CIsotope()
{
    m_Nombre_Atomique=-1;
    m_Masse_Molaire=-1.0;
    m_Proportion=0.0;
    m_Demi_Vie=-1.0;
    //CModeDeDesintegration c;m_ModesDeDesintegration.push_back(c);
}

CIsotope::~CIsotope()
{
    //dtor
}

