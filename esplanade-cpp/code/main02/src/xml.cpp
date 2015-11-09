#include <string>
#include <fstream>

#include <vector>
#include <iostream>
using namespace std;

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

/*
Example usage:
    string str("Split me by whitespaces");
    vector<string> v = split<string>("Hello, there; World", ";,");
    vector<string> v = split<string>(str,";,");

   for (auto s : v ) std::cout << s << std::endl;

    */

/*

int main(){

std::string filepath = "/tmp/xmlparser/xmlparseur/br_isotopes.txt";
std::ifstream fichier(filepath);

if ( fichier ) // ce test échoue si le fichier n'est pas ouvert
    {
        std::string ligne,atome,nucleons,dictref=""; // variable contenant chaque ligne lue
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

                if ((v.size()==3)&&(v[2]!="isotope")){// /cml/isotopeList/@id=H
                    tmp = split<string>(v[2],"=");
                    atome=tmp[1];
                    std::cout << "atome" << atome << std::endl;
                    }
                if (v.size()==4){
                    tmp = split<string>(v[3],"=");
                    if (tmp[0]=="@number"){
                        nucleons= tmp[1];// /cml/isotopeList/isotope/@id=H1
                        std::cout << "nucleons:" << nucleons << std::endl;
                        }
                    if ((tmp[0]=="scalar")&& (tmp[0].size()==2)){//vient apres sie=5 et dictref
                        std::cout << "dictref:" << dictref << std::endl;
                        if (dictref=="atomicNumber"){NombreAtomique=stoi(tmp[1]);}
                        if (dictref=="alphaDecay"){energie=stof(tmp[1]);}//mev
                        if (dictref=="alphaDecayLikeliness"){proportion=0.01*stof(tmp[1]);}//@units=bo:percentage
                        if (dictref=="betaminusDecay"){energie=stof(tmp[1]);}
                        if (dictref=="betaminusDecayLikeliness"){proportion=0.01*stof(tmp[1]);}
                        if (dictref=="betaplusDecay"){machin=stof(tmp[1]);}
                        if (dictref=="betaplusDecayLikeliness"){proportion=0.01*stof(tmp[1]);}
                        if (dictref=="ecDecay"){machin=stof(tmp[1]);}
                        if (dictref=="ecDecayLikeliness"){proportion=0.01*stof(tmp[1]);}
                        if (dictref=="exactMass"){masse=stof(tmp[1]);}
                        if (dictref=="halfLife"){demivie=stof(tmp[1]);}
                        if (dictref=="magneticMoment"){MomentMagnetique==stof(tmp[1]);}
                        if (dictref=="relativeAbundance"){proportion=0.01*stof(tmp[1]);}
                        if (dictref=="spin"){spin=tmp[1];}//5/2+
                        std::cout << "machin:"<<tmp[1] << std::endl;
                        }
                    }//if (v.size()==4){
                if (v.size()==5){
                    tmp0 = split<string>(v[4],"=");
                    if (tmp0[0]=="@dictRef"){
                        std::cout <<  "@dictRef" <<tmp0[1] << std::endl;
                        tmp = split<string>(tmp0[1],":");
                        dictref=tmp[1]; // relativeAbundance exactMass spin magneticMoment atomicNumber
                        }
                    if (tmp0[0]=="@errorValue"){
                        std::cout << "error"<< std::endl;
                        errorValue=stof(tmp0[1]);
                        dictref='_';
                        }
                    if (tmp0[0]=="@units"){
                        std::cout << "unite" << std::endl;
                        tmp = split<string>(tmp0[1],":");
                        unites=tmp[1]; //s y
                        dictref='_';
                        }
                    }//if (v.size()==5){

                //std::cout << ligne << std::endl;
                //std::cout << v.size() << std::endl;
                //for (auto s : v ) std::cout << s << std::endl;
                }
        }
    }
}

*/
