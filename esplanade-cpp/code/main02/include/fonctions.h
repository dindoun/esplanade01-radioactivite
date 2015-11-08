#ifndef FONCTION_H
#define FONCTION_H


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







/** \brief fonction creneau
*
* \param
* \param
* \return 1 si x>=0
*
*/


float creneau(float x){
    if (x<0 ) return 0;
    if (x>=0) return 1;
    }




/** \brief fonction intervalle
 *
 * \param
 * \param
 * \return 1 si a<=x<=b ou b<=x<=a
 *
 */

float intervalle(float x , float a, float b){
    if ( (a<=b) &&  (x>=a)  && (x<=b) ) return 1;
    else if ( (a>=b) &&  (x<=a)  && (x>=b) ) return 1;
    else return 0;

    }



#endif // FONCTION_H
