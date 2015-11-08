#include <CMateriau.h>
#include <CMolecule.h>
#include <iostream>
#include <fstream>

using namespace rad;
using namespace std;


CMateriau::CMateriau(sf::Vector3f position)
{
    m_position=position;
    m_nom="matériau";
	//CMateriau m;
    // m_materiaux.push_back (m);
	CMolecule mol;
    m_molecules.push_back (mol);
    //m_taille_du_cube=sf::Vector3f(0.01,0.01,0.01);
    //ctor
}

CMateriau::~CMateriau()
{
    //dtor
}
/*
Length
Normalize
Rotate ( 2D vector only )
Angle Between 2 vectors ( functions for both radians and degrees )
Dot Product
Cross Product
*/
void CMateriau::Creemap(float z){
    for (auto m : m_molecules)
        for (auto a : m.m_atomes)
            for (auto i : a.m_isotopes)
                for (auto mod : i.m_ModesDeDesintegration)

    CModeDeDesintegration mode=m_molecules[0].m_atomes[0].m_isotopes[0].m_ModesDeDesintegration[0];
    //mode.affiche_mode();//m_map[11][11];
    double valeur;
    for (int i=-5;i<6;i++){
        for (int j=-5;j<6;j++){
            //sf::Vector3f pos=sf::Vector3f (i*1.0+m_position.x,j*1.0+m_position.y,z+m_position.z);//position relative pr cube
            sf::Vector3f pos=sf::Vector3f (i*1.0,j*1.0,z);
            double distance2=pos.x*pos.x+pos.y*pos.y+pos.z*pos.z;
            //pow(a,exposaqnt)
            valeur= 100.0f/distance2  ;
            std::cout << "\n";
            std::cout << distance2 <<"\n";
            std::cout << valeur <<"\n";
            m_map[11*(i+5)+(j+5)]=valeur;
            mt_map.push_back(test_tuple(i,j,valeur));


            }
        }
    EcritFichiermap();
    //for (auto s : m_map ) std::cout << s <<"\n";
    };
       // Declare the array.




void CMateriau::EcritFichiermap(){
{
    std::ofstream fichier("poub.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
    if(fichier)  // si l'ouverture a réussi
        {   for (auto s : mt_map ) {

            fichier << get<0>(s) << " " << get<1>(s)<< " " << get<2>(s) << "\n";
            }
            // instructions
            fichier.close();  // on referme le fichier
        }
    else  // sinon
            cerr << "Erreur à l'ouverture !" << endl;
   // return 0;
    }

}
/*
   m_Demi_Vie=10.0;
m_Type =TypeRadioactivite::Gamma;
m_Energie =0.0;
m_Mult_Humain =1.0 ;
m_Mult_Compteur_Geiger =1.0 ;
*/
