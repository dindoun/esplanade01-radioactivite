#include "Mode2Desintegration.h"


namespace rad
{
//std::map< Isotopes , Isotope* >  Isotope::m_isotopes();

Mode2Desintegration::Initialise ()
{
    m_Mode2Desintegration.insert (1,  new Mode2Desintegration()   );
    m_Mode2Desintegration[ 1 ].m_demi_vie =1.0E5 ;
    m_Mode2Desintegration[ 1].m_type =TypeRadioactivite::Gamma;
    m_Mode2Desintegration[ 1].m_energie =0.0;
    m_Mode2Desintegration[ 1].m_MultHumain =1.0 ;
    m_Mode2Desintegration[ 1].m_MultCompteurGeiger =1.0 ;



}



Mode2Desintegration::Mode2Desintegration()
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

Mode2Desintegration::~Mode2Desintegration()
{
    //dtor
}

} // fin namspace
