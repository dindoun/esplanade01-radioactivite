#ifndef ISOTOPE_H
#define ISOTOPE_H

#include <memory>

namespace rad
{


enum TypeRadioactivite{
    Alpha,Electron,Positron,Gamma,X
};;
enum Isotopes {
    C14,
    U235,
    H2
};


struct Isotope
{
    static void initialise ();
    static  std::map< Isotopes , Isotope* >  m_isotopes;



    double m_demi_vie;
    TypeRadioactivite m_type;
    double m_energie;
    float m_MultHumain;///< passage du physique au biologique ( J -> Sievert )
    float m_MultCompteurGeiger;///<  erreur multiplicative sur  la mesure

};


}; // fin nemaspace

#endif // ISOTOPE_H
