#include <CAtome.h>
#include <CModeDeDesintegration.h>

using namespace rad;


CAtome::CAtome()
{
    CIsotope i;
    m_isotopes.push_back(i);


    }

CAtome::~CAtome()
{
    //dtor
}

