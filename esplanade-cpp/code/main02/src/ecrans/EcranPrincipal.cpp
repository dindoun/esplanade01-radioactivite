

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans\EcranPrincipal.h"
#include <iostream>
#include <Config.h>
//#include "GUI.h"

namespace app {

/////////////////////////////////////////////////
EcranPrincipal::EcranPrincipal( Application*  appli ): Ecran ( appli )
{
    // Initialisation de l'interface graphique.
    initGUI();
}


/////////////////////////////////////////////////
void EcranPrincipal::traiter_evenements    ( const sf::Event& event )
{

}


/////////////////////////////////////////////////
void EcranPrincipal::actualiser            ( float deltaT )
{

}


/////////////////////////////////////////////////
void EcranPrincipal::dessiner ()
{

}



/////////////////////////////////////////////////
void
EcranPrincipal::initGUI  ( )
{


}   // fin init GUI




}   // fin namespace app































