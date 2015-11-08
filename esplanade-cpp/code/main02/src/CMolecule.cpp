#include <CMolecule.h>
#include <memory>
#include <vector>

using namespace rad;

/*
enum CAtomes {
    C,
    U,
    H
};
*/

CMolecule::CMolecule()
{
    m_nom="molécule";
    m_Proportion=1.0;
    //std::vector< std::shared_ptr<CAtome>> m_atomes;     ///<
    CAtome a;
    m_atomes.push_back (a);
/*    struct Isotope{
        std::vector<Mode2Desintegration> m_Modes;
        };

    std::vector<Isotope,int proportion> m_Isotopes;
*/

//static  std::map< Isotopes , Isotope* >  m_isotopes;

};


CMolecule::~CMolecule(){};
