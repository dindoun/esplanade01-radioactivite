#ifndef MODEDEDESINTEGRATION_H
#define MODEDEDESINTEGRATION_H

#include <memory>

namespace rad
{
    enum TypeRadioactivite{
        Alpha,Electron,Positron,Gamma,X
    };

//typedef std::tuple< TypeRadioactivite & , ModeDeDesintegration* > t_ModeDeDesintegration ;

struct ModeDeDesintegration
{
    double m_demi_vie;
    TypeRadioactivite m_type;
    double m_energie;
    float m_MultHumain;///< passage du physique au biologique ( J -> Sievert )
    float m_MultCompteurGeiger;///<  erreur multiplicative sur  la mesure
    //static  std::map< int , ModeDeDesintegration* >  m_ModeDeDesintegration;
    //static t_ModeDeDesintegration m_ModeDeDesintegration;
    static void Initialise ();
    };

}; // fin nemaspace


#endif // ModeDeDesintegration_H
/*

typedef tuple< int, double, long &, const char * > test_tuple ;
long lengthy = 12 ;
test_tuple proof( 18, 6.5, lengthy, "Ciao!" ) ;
lengthy = get<0>(proof) ; // Assigne à ‘lengthy’ la valeur 18
get<3>(proof) = " Beautiful!" ; // Modifie la 4ème valeur du tuple

*/
