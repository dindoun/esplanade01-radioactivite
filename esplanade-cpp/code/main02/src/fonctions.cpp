

#include <vector>
#include <iostream>
using namespace std;

/*
Example usage:
    string str("Split me by whitespaces");
    vector<string> v = split<string>("Hello, there; World", ";,");
    vector<string> v = split<string>(str,";,");

   for (auto s : v ) std::cout << s << std::endl;

    */







/** \brief fonction creneau
*
* \param
* \param
* \return 1 si x>=0
*
*/


float creneau(float x){
    if (x<0.0 ) return 0.0;
    if (x>=0.0) return 1.0;
    }




/** \brief fonction intervalle
 *
 * \param
 * \param
 * \return 1 si a<=x<=b ou b<=x<=a
 *
 */

float intervalle(float x , float a, float b){
    if ( (a<=b) &&  (x>=a)  && (x<=b) ) return 1.0;
    else if ( (a>=b) &&  (x<=a)  && (x>=b) ) return 1.0;
    else return 0.0;

    }

