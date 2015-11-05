#include <CDalle.h>
using namespace rad;

CDalle::CDalle(sf::Vector3f taille_dalle,sf::Vector3i nb_cube,sf::Vector3f position)
    {   m_taille_du_cube=sf::Vector3f(1.0,1.0,0.01) ;
        m_taille=sf::Vector3f(1.0,1.0,0.01);



        m_taille=taille_dalle;
        m_nb_cube=nb_cube;
        m_position=position;

        m_taille_du_cube.x=m_taille.x/m_nb_cube.x;
        m_taille_du_cube.y=m_taille.y/m_nb_cube.y;
        m_taille_du_cube.z=m_taille.z/m_nb_cube.z;



        for (int i=0;i<m_nb_cube.x;i++){
            for (int j=0;j<m_nb_cube.y;j++){
                for (int k=0;k<m_nb_cube.z;k++){
                    {
                        position=m_position+sf::Vector3f(m_taille_du_cube.x*i,m_taille_du_cube.y*j, m_taille_du_cube.z*k) ;;
                        CMateriau m(position);
                        //m.m_taille_du_cube=sf::Vector3f(1.0,1.0,0.01) ;

                        m_materiaux.push_back (m);
                        }
                    }
                }
            }



        //ctor
        }

CDalle::~CDalle()
{
    //dtor
}
