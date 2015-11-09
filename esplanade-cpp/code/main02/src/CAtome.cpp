#include <CAtome.h>
#include <CModeDeDesintegration.h>

#include <string>
#include <fstream>

#include <vector>
#include <iostream>
#include <fonctions.h>


using namespace rad;
using namespace std;

CAtome::CAtome()
{
    //CIsotope i;m_isotopes.push_back(i);
    m_nom_atome="";//ATOMES::VIDE;

    }

CAtome::~CAtome()
{
    //dtor
}



/** \brief fonction split ( T )
 *
 * \param
 * \param
 * \return  vector<T>
 *
 */


template<typename T>
vector<T>
split(const T & str, const T & delimiters) {
    vector<T> v;
    typename T::size_type start = 0;
    auto pos = str.find_first_of(delimiters, start);
    while(pos != T::npos) {
        if(pos != start) // ignore empty tokens
            v.emplace_back(str, start, pos - start);
        start = pos + 1;
        pos = str.find_first_of(delimiters, start);
    }
    if(start < str.length()) // ignore trailing delimiter
        v.emplace_back(str, start, str.length() - start); // add what's left of the string
    return v;
}




/** \brief cree la liste des isotopes de l'atome
 *
 * \param
 * \param
 * \return
 *
 */


void CAtome::remplis_isotopes(){
    std::string filepath ;
    filepath = "/home/bruno/Bureau/PROGRAMMATION/ESPLANADE MUSEE BEAUX ARTS-NUCLEAIRE/20151028-esplanade/esplanade-cpp/code/main02/media/isotopes/br_isotopes.txt";
    //filepath = "media/isotopes/br_isotopes.txt";
    std::ifstream fichier(filepath);
    CIsotope iso;
    CModeDeDesintegration mode;
    if ( fichier ) // ce test échoue si le fichier n'est pas ouvert
        {
            std::string ligne,atome,nucleons,dictref=""; // variable contenant chaque ligne lue
            atome="";
            int NombreAtomique;
            vector<string> tmp,tmp0,v;
            string spin,unites;
            float proportion,masse,demivie,MomentMagnetique,errorValue,energie;
            float machin;
            float alphaDecay,alphaDecayLikeliness,betaminusDecay,ecDecayLikeliness,exactMass,betaminusDecayLikeliness,halfLife,relativeAbundance,magneticMoment,betaplusDecay,betaplusDecayLikeliness,ecDecay;
            // cette boucle s'arrête dès qu'une erreur de lecture survient
            while ( std::getline( fichier, ligne ) )
                {
                // afficher la ligne à l'écran

                v = split<string>(ligne,"/");
                if (v[1]=="isotopeList"){

                    if ((v.size()==3)&&(v[2]!="isotope")){/**< première ligne de l'atome /cml/isotopeList/@id=H */
                        tmp = split<string>(v[2],"=");
                        atome=tmp[1];
                        //std::cout << "atome" << atome << std::endl;
                        }
                    if ((v.size()==4)&&(atome==m_nom_atome)){
                        tmp = split<string>(v[3],"=");
                        if (tmp[0]=="@number"){/**< première ligne de l'isotope /cml/isotopeList/isotope/@id=H1 */
                            if  (iso.m_Nombre_Atomique!=-1){ m_isotopes.push_back(iso);}//le dernier du fichier ne passe pas
                            delete iso;
                            delete mode;
                            CIsotope iso;
                            nucleons= tmp[1];
                            //std::cout << "nucleons:" << nucleons << std::endl;
                            }
                        if ((tmp[0]=="scalar")&& (tmp[0].size()==2)){//vient apres sie=5 et dictref
                            //std::cout << "dictref:" << dictref << std::endl;
                            if (dictref=="atomicNumber"){NombreAtomique=stoi(tmp[1]);
                                iso.m_Nombre_Atomique=NombreAtomique;  }
                            if (dictref=="alphaDecay"){energie=stof(tmp[1]);
                                mode.m_Energie =energie;}
                            if (dictref=="alphaDecayLikeliness"){proportion=0.01*stof(tmp[1]);//@units=bo:percentage
                                mode.m_Proportion =proportion;
                                iso.m_ModesDeDesintegration.push_back(mode);
                                delete mode;}
                            if (dictref=="betaminusDecay"){energie=stof(tmp[1]);
                                mode.m_Energie =energie;}
                            if (dictref=="betaminusDecayLikeliness"){proportion=0.01*stof(tmp[1]);
                                mode.m_Proportion =proportion;
                                iso.m_ModesDeDesintegration.push_back(mode);
                                delete mode;}
                            if (dictref=="betaplusDecay"){energie=stof(tmp[1]);
                                mode.m_Energie =energie;}
                            if (dictref=="betaplusDecayLikeliness"){proportion=0.01*stof(tmp[1]);
                                mode.m_Proportion =proportion;
                                iso.m_ModesDeDesintegration.push_back(mode);
                                delete mode;}
                            if (dictref=="ecDecay"){energie=stof(tmp[1]);
                                mode.m_Energie =energie;}
                            if (dictref=="ecDecayLikeliness"){proportion=0.01*stof(tmp[1]);
                                mode.m_Proportion =proportion;
                                iso.m_ModesDeDesintegration.push_back(mode);
                                delete mode;}
                            if (dictref=="exactMass"){masse=stof(tmp[1]);/**< (g/mol) */
                                iso.m_Masse_Molaire=masse;}
                            if (dictref=="halfLife"){demivie=stof(tmp[1]);/**< au moins un mode de désintégration */
                                iso.m_Demi_Vie=iso.m_Demi_Vie*demivie;/**<(s)  unité * valeur */
                                CModeDeDesintegration mode;//m_ModesDeDesintegration.push_back(c);
                                }
                            if (dictref=="magneticMoment"){MomentMagnetique==stof(tmp[1]);}
                            if (dictref=="relativeAbundance"){proportion=0.01*stof(tmp[1]);
                                iso.m_Proportion=proportion;}
                            if (dictref=="spin"){spin=tmp[1];}//5/2+
                            //std::cout << "machin:"<<tmp[1] << std::endl;
                            }
                        }//if (v.size()==4){
                    if ((v.size()==5)&&(atome==m_nom_atome)){
                        tmp0 = split<string>(v[4],"=");
                        if (tmp0[0]=="@dictRef"){
                            //std::cout <<  "@dictRef" <<tmp0[1] << std::endl;
                            tmp = split<string>(tmp0[1],":");
                            dictref=tmp[1]; // relativeAbundance exactMass spin magneticMoment atomicNumber
                            }
                        if (tmp0[0]=="@errorValue"){
                            //std::cout << "error"<< std::endl;
                            errorValue=stof(tmp0[1]);
                            dictref='_';
                            }
                        if (tmp0[0]=="@units"){
                            //std::cout << "unite" << std::endl;
                            tmp = split<string>(tmp0[1],":");
                            unites=tmp[1]; //s y
                            if (unites=='y'){iso.m_Demi_Vie=31557600.0;}
                            if (unites=='s'){iso.m_Demi_Vie=1.0;}
                            if ((unites!='y')&&(unites!='s'){std::cout << "problème d'unités : " << unites << std::endl;}
                            dictref='_';
                            }
                        }//if (v.size()==5){

                    //std::cout << ligne << std::endl;
                    //std::cout << v.size() << std::endl;
                    //for (auto s : v ) std::cout << s << std::endl;
                    }
            }
        }
    };
