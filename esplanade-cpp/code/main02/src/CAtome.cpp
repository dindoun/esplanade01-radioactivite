#include <CAtome.h>
#include <CModeDeDesintegration.h>

#include <string>
#include <fstream>

#include <vector>
#include <iostream>
#include <fonctions.h>
#include <stdio.h>

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
    bool debug=true;//
    debug=false;

    std::string filepath ;
    filepath = "/home/bruno/Bureau/PROGRAMMATION/ESPLANADE MUSEE BEAUX ARTS-NUCLEAIRE/20151028-esplanade/esplanade-cpp/code/main02/media/isotopes/br_isotopes.txt";
    //filepath = "/home/bruno/Bureau/PROGRAMMATION/ESPLANADE MUSEE BEAUX ARTS-NUCLEAIRE/20151028-esplanade/esplanade-cpp/code/main02/media/isotopes/br_isotopes-U217.txt";
    //filepath = "media/isotopes/br_isotopes.txt";
    std::ifstream fichier(filepath);
    //CIsotope iso;
    //CModeDeDesintegration mode;
    //std::vector<CIsotope*> isotopes;
    int IsotopeCourant=-1;
    //std::vector<CModeDeDesintegration*> modes;
    int ModeCourant=-1;
    if ( fichier ) // ce test échoue si le fichier n'est pas ouvert
        {
            std::string ligne,atome,dictref=""; // variable contenant chaque ligne lue
            atome="";
            int NombreAtomique,nucleons;
            vector<string> tmp,tmp0,v;
            string spin,unites;
            float proportion,masse,demivie,MomentMagnetique,errorValue,energie;
            float machin;
            float alphaDecay,alphaDecayLikeliness,betaminusDecay,ecDecayLikeliness,exactMass,betaminusDecayLikeliness,halfLife,relativeAbundance,magneticMoment,betaplusDecay,betaplusDecayLikeliness,ecDecay;
            // cette boucle s'arrête dès qu'une erreur de lecture survient
            while ( std::getline( fichier, ligne ) )
                {
                // afficher la ligne à l'écran

                Affiche_Debug("----------------------->"+ligne,debug);

                v = split<string>(ligne,"/");
                if (v[1]=="isotopeList"){

                    if ((v.size()==3)&&(v[2]!="isotope")){/**< première ligne de l'atome /cml/isotopeList/@id=H */
                        tmp = split<string>(v[2],"=");
                        atome=tmp[1];
                        Affiche_Debug("atome:" + atome ,debug);
                        }





                    if ((v.size()==4)&&(atome==m_nom_atome)){

                        tmp = split<string>(v[3],"=");


                        if (tmp[0]=="@id"){/**< première ligne de l'isotope /cml/isotopeList/isotope/@id=H1 */
                            //if  (m_isotopes[IsotopeCourant].m_Nombre_Atomique!=-1){ m_isotopes.push_back(iso);}//le dernier du fichier ne passe pas
                            m_isotopes.push_back(CIsotope());/**< on crée un isotope */
                            IsotopeCourant+=1;
                            ModeCourant=-1;
                            Affiche_Debug("\ton crée un isotope",debug);
                            }

                        if (tmp[0]=="@number"){


                            //delete iso;
                            //delete mode;
                            //CIsotope iso=&isotopes;
                            nucleons= stoi(tmp[1]);
                            m_isotopes[IsotopeCourant].m_Nombre_De_Masse=nucleons;
                            Affiche_Debug("\t\tnucleons:"+nucleons ,debug);
                            }

                        if (tmp[0]=="@elementType"){
                            //
                            }

                        if ((tmp[0]=="scalar")&& (tmp.size()==1)){
                            //
                            }

                        //Affiche_Debug("0dictref:"+dictref,debug);

                        if ((tmp[0]=="scalar")&& (tmp.size()==2)){//vient apres sie=5 et dictref
                            Affiche_Debug("\t\t\t"+dictref+":scalar=",debug);
                            Affiche_Debug("\t\t\t"+to_string(IsotopeCourant)+";"+to_string(ModeCourant),debug);
                            if (dictref=="atomicNumber"){NombreAtomique=stoi(tmp[1]);
                                //m_isotopes[IsotopeCourant].m_Nombre_Atomique=NombreAtomique;
                                //Affiche_Debug("m_Nombre_Atomique:" + to_string(NombreAtomique) + ":"+to_string(m_isotopes[IsotopeCourant].m_Nombre_Atomique),debug);
                                }
                            if (dictref=="alphaDecay"){energie=stof(tmp[1]);
                                Affiche_Debug("\t\t\t\ténergie:"+to_string(energie),debug);
                                m_isotopes[IsotopeCourant].m_ModesDeDesintegration[ModeCourant].m_Energie =energie;}
                            if (dictref=="alphaDecayLikeliness"){proportion=0.01*stof(tmp[1]);//@units=bo:percentage
                                m_isotopes[IsotopeCourant].m_ModesDeDesintegration[ModeCourant].m_Proportion =proportion;
                               // m_isotopes[IsotopeCourant].m_ModesDeDesintegration.push_back(mode);
                                //delete mode;
                                }
                            if (dictref=="betaminusDecay"){energie=stof(tmp[1]);
                                m_isotopes[IsotopeCourant].m_ModesDeDesintegration[ModeCourant].m_Energie =energie;}
                            if (dictref=="betaminusDecayLikeliness"){proportion=0.01*stof(tmp[1]);
                                m_isotopes[IsotopeCourant].m_ModesDeDesintegration[ModeCourant].m_Proportion =proportion;
                               // m_isotopes[IsotopeCourant].m_ModesDeDesintegration.push_back(mode);
                                //delete mode;
								}
                            if (dictref=="betaplusDecay"){energie=stof(tmp[1]);
                                m_isotopes[IsotopeCourant].m_ModesDeDesintegration[ModeCourant].m_Energie =energie;}
                            if (dictref=="betaplusDecayLikeliness"){proportion=0.01*stof(tmp[1]);
                                m_isotopes[IsotopeCourant].m_ModesDeDesintegration[ModeCourant].m_Proportion =proportion;
                               // m_isotopes[IsotopeCourant].m_ModesDeDesintegration.push_back(mode);
                                //delete mode;
								}
                            if (dictref=="ecDecay"){energie=stof(tmp[1]);
                                m_isotopes[IsotopeCourant].m_ModesDeDesintegration[ModeCourant].m_Energie =energie;}
                            if (dictref=="ecDecayLikeliness"){proportion=0.01*stof(tmp[1]);
                                m_isotopes[IsotopeCourant].m_ModesDeDesintegration[ModeCourant].m_Proportion =proportion;
                               // m_isotopes[IsotopeCourant].m_ModesDeDesintegration.push_back(mode);
                                //delete mode;
								}
                            if (dictref=="exactMass"){masse=stof(tmp[1]);/**< (g/mol) */
                                m_isotopes[IsotopeCourant].m_Masse_Molaire=masse;}
                            if (dictref=="halfLife"){demivie=stof(tmp[1]);/**< au moins un mode de désintégration */
                                m_isotopes[IsotopeCourant].m_Demi_Vie=m_isotopes[IsotopeCourant].m_Demi_Vie*demivie;/**<(s)  unité * valeur */
                                //CModeDeDesintegration mode;//m_ModesDeDesintegration.push_back(c);

                                }
                            if (dictref=="magneticMoment"){MomentMagnetique==stof(tmp[1]);}
                            if (dictref=="relativeAbundance"){proportion=0.01*stof(tmp[1]);
                                m_isotopes[IsotopeCourant].m_Proportion=proportion;}
                            if (dictref=="spin"){spin=tmp[1];}//5/2+
                            //std::cout << "machin:"<<tmp[1] << std::endl;
                            }
                        }//if (v.size()==4){









                    if ((v.size()==5)&&(atome==m_nom_atome)){
                        tmp0 = split<string>(v[4],"=");
                        if (tmp0[0]=="@dictRef"){
                            Affiche_Debug("\t\t\t\t@dictRef:"+tmp0[1],debug);
                            tmp = split<string>(tmp0[1],":");
                            dictref=tmp[1]; // relativeAbundance exactMass spin magneticMoment atomicNumber
                            Affiche_Debug("\t\t\t\tdictRef:"+dictref,debug);
                            if (dictref=="halfLife"){
                                m_isotopes[IsotopeCourant].m_ModesDeDesintegration.push_back(CModeDeDesintegration());
                                ModeCourant+=1;
                                Affiche_Debug("\t\t\t\t\tcréation d'un mode désintégration:"+to_string(ModeCourant),debug);
                                }
                            }
                        if (tmp0[0]=="@errorValue"){// on ne fait rien
                            //std::cout << "error"<< std::endl;
                            errorValue=stof(tmp0[1]);
                            //dictref='_';
                            }
                        if (tmp0[0]=="@units"){
                                //std::cout << "tmp1 : " << tmp0[1] << std::endl;
                            //std::cout << "unite" << std::endl;
                            tmp = split<string>(tmp0[1],":");
                            unites=tmp[1]; //s y
                            if (unites==(string)("y")){m_isotopes[IsotopeCourant].m_Demi_Vie=31557600.0;}
                            if (unites==string("s")){m_isotopes[IsotopeCourant].m_Demi_Vie=1.0;}
                            if (unites==string("percentage")){//
                                ;}
                            if ((unites!=string("y"))&&(unites!=string("s"))&&(unites!=string("percentage"))){std::cout << "problème d'unités : " << unites << std::endl;}
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

