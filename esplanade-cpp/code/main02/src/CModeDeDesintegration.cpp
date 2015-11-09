#include <CModeDeDesintegration.h>


//std::map< Isotopes , Isotope* >  Isotope::m_isotopes();
using namespace rad;
void CModeDeDesintegration::affiche_mode(){
    printf("demi-vie : %e secondes \n", m_Demi_Vie);
    //printf("%s \n", m_Type);
    printf("énergie : %e Joules \n", m_Energie);
    printf("1 Joule = %e Sievert \n", m_Mult_Humain);///< passage du physique au biologique ( J -> Sievert )
    printf("1 Joule = %e Joules lus par le compteur geiger \n", m_Mult_Compteur_Geiger);
    };
CModeDeDesintegration::CModeDeDesintegration(){
    m_Demi_Vie=-1.0;
    m_Type =TypeRadioactivite::Gamma;
    m_Energie =0.0;
    m_Mult_Humain =1.0 ;
    m_Mult_Compteur_Geiger =1.0 ;
    m_Proportion=0.0;
    };


CModeDeDesintegration::~CModeDeDesintegration(){};


