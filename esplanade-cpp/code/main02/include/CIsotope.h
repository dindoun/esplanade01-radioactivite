#ifndef CISOTOPE_H
#define CISOTOPE_H
#include <CModeDeDesintegration.h>
#include <memory>
#include <vector>
using namespace rad;


class CIsotope
{   public:
        //std::vector< std::shared_ptr<CModeDeDesintegration>> m_ModesDeDesintegration;     ///<
        std::vector<CModeDeDesintegration> m_ModesDeDesintegration;     ///<
        CIsotope();
        virtual ~CIsotope();

};


#endif // ISOTOPE_H
