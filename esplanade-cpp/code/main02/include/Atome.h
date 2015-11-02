#ifndef ATOME_H
#define ATOME_H


#include <memory>
#include <vector>

namespace rad
{


enum TypeRadioactivite{
    Alpha,Electron,Positron,Gamma,X
};;
enum Atomes {
    C,
    U,
    H
};


struct Atome
{
    struct Isotope{
        std::vector<Mode2Desintegration> m_Modes;
        };

    std::vector<Isotope,int proportion> m_Isotopes;

    static void initialise ();
//static  std::map< Isotopes , Isotope* >  m_isotopes;

};


}; // fin nemaspace


#endif // ATOME_H
