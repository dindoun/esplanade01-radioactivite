#include "ModeDeDesintegration.h"


namespace rad
{
//std::map< Isotopes , Isotope* >  Isotope::m_isotopes();

void ModeDeDesintegration::Initialise ()
{
    //m_ModeDeDesintegration.insert (1,  new ModeDeDesintegration()   );
    ModeDeDesintegration m_ModeDeDesintegration;
    m_ModeDeDesintegration.m_demi_vie =1.0E5 ;
    m_ModeDeDesintegration.m_type =TypeRadioactivite::Gamma;
    m_ModeDeDesintegration.m_energie =0.0;
    m_ModeDeDesintegration.m_MultHumain =1.0 ;
    m_ModeDeDesintegration.m_MultCompteurGeiger =1.0 ;
    }

}
