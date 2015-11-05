#ifndef CATOME_H
#define CATOME_H
#include <CIsotope.h>

#include <memory>
#include <vector>

using namespace rad;

enum TypeRadioactivite{
    Alpha,Electron,Positron,Gamma,X
};;
enum Atomes {
    C,
    U,
    H
};


class CAtome
{   public:
        //std::vector< std::shared_ptr<CIsotope>> m_isotopes;     ///<
        std::vector<CIsotope> m_isotopes;     ///<
        CAtome();
        virtual ~CAtome();
        /*
        struct Isotope{
        std::vector<CModeDeDesintegration> m_Modes;
        };

        std::vector<Isotope,int proportion> m_Isotopes;

        static void initialise ();*/
        //static  std::map< Isotopes , Isotope* >  m_isotopes;

};





#endif // ATOME_H
