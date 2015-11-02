#include "Isotope.h"

namespace rad
{
//std::map< Isotopes , Isotope* >  Isotope::m_isotopes();

Isotope::Initialise ()
{
    m_isotopes.insert (Isotopes::U235,  new Isotope()   )
    m_isotopes[ Isotopes::U235_1 ].m_demi_vie =1.0E5 ;
    m_isotopes[ Isotopes::U235_1 ].m_type =TypeRadioactivite::Gamma;
    m_isotopes[ Isotopes::U235_1 ].m_MultHumain =1.0 ;
    m_isotopes[ Isotopes::U235_1 ].m_MultCompteurGeiger =1.0 ;

new isotope U235;

}



Isotope::Isotope()
{
//    //ctor
//
//    double m_demi_vie;
//    TypeRadioactivite m_type;
//    double m_energie;
//    float m_MultHumain;///< passage du physique au biologique ( J -> Sievert )
//    float m_MultCompteurGeiger;///<  erreur multiplicative sur  la mesure
//


}

Isotope::~Isotope()
{
    //dtor
}

} // fin namspace
