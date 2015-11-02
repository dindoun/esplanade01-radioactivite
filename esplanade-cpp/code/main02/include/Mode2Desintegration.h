#ifndef MODE2DESINTEGRATION_H
#define MODE2DESINTEGRATION_H

#include <memory>

namespace rad
{


enum TypeRadioactivite{
    Alpha,Electron,Positron,Gamma,X
};;

struct Mode2Desintegration
{




    double m_demi_vie;
    TypeRadioactivite m_type;
    double m_energie;
    float m_MultHumain;///< passage du physique au biologique ( J -> Sievert )
    float m_MultCompteurGeiger;///<  erreur multiplicative sur  la mesure


    static  std::map< int , Mode2Desintegration* >  m_Mode2Desintegration;
    static void initialise ();
};


}; // fin nemaspace


#endif // MODE2DESINTEGRATION_H
