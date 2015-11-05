#ifndef CMATERIAU_H
#define CMATERIAU_H
#include <CMolecule.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <utility>
using namespace rad;

/////////////////////////////////////////////////
/// \brief  cube de matiere homogene
///
///
/////////////////////////////////////////////////
class CMateriau
{
public:
    CMateriau(sf::Vector3f);
    virtual ~CMateriau();
    void Creemap(float);
    void EcritFichiermap();

    //double m_map[11][11];   // Declare the array.
    //std::vector<double> m_map[];
    double m_map[121];
    typedef std::tuple< double, double, double > test_tuple ;
    std::vector<test_tuple> mt_map;




    sf::Vector3f m_taille_du_cube;
    sf::Vector3f m_position;
    /////////////////////////////////////////////////
    // les membres
    /////////////////////////////////////////////////
//    std::vector<CMateriau> m_materiaux;     ///<
    std::vector<CMolecule> m_molecules;     ///<
protected:
private:
};
#endif // MATERIAU_H
