#ifndef CMOLECULE_H
#define CMOLECULE_H

#include <CAtome.h>
#include <memory>
#include <vector>




/*
enum CAtomes {
    C,
    U,
    H
};
*/

class CMolecule
{
    public:
        std::vector< CAtome> m_atomes;     ///<
        char * m_nom;
        float m_Proportion;
        CMolecule();
        virtual ~CMolecule();


    /*    struct Isotope{
            std::vector<Mode2Desintegration> m_Modes;
            };

        std::vector<Isotope,int proportion> m_Isotopes;
    */

    //static  std::map< Isotopes , Isotope* >  m_isotopes;

};


#endif // MOLECULE_H
