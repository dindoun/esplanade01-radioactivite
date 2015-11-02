#ifndef MATERIAU_H
#define MATERIAU_H
namespace rad
{

/////////////////////////////////////////////////
/// \brief  cube de matiere homogene
///
///
/////////////////////////////////////////////////
class materiau
{
public:
    materiau();

    virtual ~materiau();


    /////////////////////////////////////////////////
    // les membres
    /////////////////////////////////////////////////
    std::vector< std::shared_ptr<materiau>> m_materiau;     ///<
    std::vector< std::shared_ptr<molecule>> m_materiau;     ///<
    sf::vect std::vector< std::shared_ptr<materiau>> m_materiau;     ///<
protected:
private:
};
}; // fin namspace
#endif // MATERIAU_H
