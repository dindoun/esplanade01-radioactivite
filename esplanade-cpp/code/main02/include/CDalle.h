#ifndef CDALLE_H
#define CDALLE_H
#include <CMateriau.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace rad;
class CDalle
{
    public:
        CDalle(sf::Vector3f,sf::Vector3i,sf::Vector3f);
        virtual ~CDalle();
        sf::Vector3f m_position;
        sf::Vector3f m_taille_du_cube;
        sf::Vector3i m_nb_cube;/**< /nb de cubes élémentaires dans une dalle */
        std::vector<CMateriau> m_materiaux;
        //sf::Image m_map_radioactivite; // chaque dalle cree une map de radioactivite
        void creemap();
        void calcule_radioactivite();
        sf::Vector3f m_taille;
    protected:
    private:
};

#endif // DALLE_H

