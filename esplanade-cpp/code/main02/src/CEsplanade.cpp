#include <CEsplanade.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


CEsplanade::CEsplanade()
{
    /*CDalle d;
    m_dalles.push_back (d);
    */
    m_taille=sf::Vector3i(1,1,1);
    m_taille_dalle=sf::Vector3f(1.f,1.f,0.1f);
    m_nb_cube=sf::Vector3i(10,10,1);//carré
    m_origine=sf::Vector3f(0.0f,0.0f,0.0f) ;
    //sf::Vector3f m_taille_du_cube;

    sf::Vector3f position;
    for (int i=0;i<m_taille.x;i++){
        for (int j=0;j<m_taille.y;j++){
            for (int k=0;k<m_taille.z;k++){
                {
                    position=m_origine+sf::Vector3f(m_taille_dalle.x*i,m_taille_dalle.y*j, - m_taille_dalle.z*k) ;;
                    CDalle d(m_taille_dalle,m_nb_cube,position);
                    //d.m_taille=m_taille_dalle;
                    //d.m_taille_du_cube=m_taille_du_cube;
                    m_dalles.push_back (d);
                    }
                }
            }
        }

    }

CEsplanade::~CEsplanade()
{
    //dtor
}

