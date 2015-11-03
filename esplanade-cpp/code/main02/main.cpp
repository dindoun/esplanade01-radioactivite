#include <ModeDeDesintegration.h>
using namespace rad;
int main()
{   //  creation de l'application.
    ModeDeDesintegration mo;
    mo.Initialise();
    printf("%f ", mo.m_demi_vie);
    return 0;
    }


/*
/////////////////////////////////////////////////
// Headers
//////////////////
///////////////////////////////
#include <Application.h>

/////////////////////////////////////////////////
/// Point d'éntrée de l'application
///
/// \return Sortie de l'application.
///
/////////////////////////////////////////////////
int main()
{
    //  creation de l'application.
    app::Application     appli;

    //  execution de l'application
    appli.executer();

    return 0;
}
*/
