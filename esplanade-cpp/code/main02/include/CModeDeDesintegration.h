#ifndef CMODEDEDESINTEGRATION_H
#define CMODEDEDESINTEGRATION_H

#include <memory>

namespace rad
{
    enum TypeRadioactivite{
        Alpha,Electron,Positron,Gamma,X
    };
}; // fin nemaspace


//typedef std::tuple< TypeRadioactivite & , ModeDeDesintegration* > t_ModeDeDesintegration ;
using namespace rad;
class CModeDeDesintegration
{   public:
        float m_Demi_Vie;
        TypeRadioactivite m_Type;
        float m_Energie;
        float m_Mult_Humain;///< passage du physique au biologique ( J -> Sievert )
        float m_Mult_Compteur_Geiger;///<  erreur multiplicative sur  la mesure
        //static  std::map< int , ModeDeDesintegration* >  m_ModeDeDesintegration;
        //static t_ModeDeDesintegration m_ModeDeDesintegration;
        void affiche_mode();
        CModeDeDesintegration();
        virtual ~CModeDeDesintegration();
    protected:
    private:
};



#endif // ModeDeDesintegration_H
/*

typedef tuple< int, double, long &, const char * > test_tuple ;
long lengthy = 12 ;
test_tuple proof( 18, 6.5, lengthy, "Ciao!" ) ;
lengthy = get<0>(proof) ; // Assigne à ‘lengthy’ la valeur 18
get<3>(proof) = " Beautiful!" ; // Modifie la 4ème valeur du tuple

*/
