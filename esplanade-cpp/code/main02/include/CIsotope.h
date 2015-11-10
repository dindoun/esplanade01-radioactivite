#ifndef CISOTOPE_H
#define CISOTOPE_H
#include <CModeDeDesintegration.h>
#include <memory>
#include <vector>
using namespace rad;


class CIsotope
{   public:
        //std::vector< std::shared_ptr<CModeDeDesintegration>> m_ModesDeDesintegration;
        std::vector<CModeDeDesintegration> m_ModesDeDesintegration; /**<  les différents modes de désintégration de l'isotope */
        int m_Nombre_De_Masse;/**< nombre de nucléons de l'isotope*/
        float m_Masse_Molaire;/**< g/mol */
        float m_Proportion;/**< proportion de cet isotope dans l'atome ( < 1.0 ) */
        CIsotope();
        virtual ~CIsotope();
        float m_Demi_Vie;

};


#endif // ISOTOPE_H
