/**
* \file     Application.h
* \brief    La classe principale du programme.
* \author   Christophe Pages
* \version  0.1
* \date     2015
* \details  Programme minimal g�rant differents �crans (intro, accueil, jeu, options...)
*/


#ifndef APPLICATION_H
#define APPLICATION_H

/////////////////////////////////////////////////
//  Headers
/////////////////////////////////////////////////
#include <Ecran.h>
#include <Gestion_ecrans.h>
#include <SFML/Graphics.hpp>
#include <vector>


namespace app {  ///<  app Espace de l'application.

class Ecran;

/////////////////////////////////////////////////
/// \class  Application
/// \brief  La classe de base du programme.
///
/// G�re les diff�rents �crans du programme
/// (�cran d'introduction, accueil, pause, �cran du jeu ....)
/////////////////////////////////////////////////
class Application
{
    public:

        /////////////////////////////////////////////////
        /// \brief Constructeur
        ///
        /////////////////////////////////////////////////
        Application();

        /////////////////////////////////////////////////
        /// \brief Destructeur
        ///
        /////////////////////////////////////////////////
        virtual ~Application();

    public:

        /////////////////////////////////////////////////
        /// \brief La boucle principale.
        ///
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        void executer();

        /////////////////////////////////////////////////
         /// \brief La gestion des �v�nements utilisateurs.
        ///
        ///  G�re les entr�es claviers, souris, fenetre ...
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        void traiterEvenements ();

        /////////////////////////////////////////////////
        /// \brief Actualiser les �l�ments.
        ///
        /// Actualiser les diff�rents �l�ments du ou des �crans actifs.
        /// \param deltaT          Un \e float qui indique le delta du temps �coul� depuis la derni�re actualisation.
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        void actualiser ( float deltaT );

        /////////////////////////////////////////////////
        /// \brief Rendre les �l�ments.
        ///
        /// Dessiner les diff�rents �l�ments du ou des �crans actifs.
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        void dessiner ( );

        /////////////////////////////////////////////////
        /// \brief renvois la fenetre sfml de l'application
        ///
        /// \return la fenetre sfml de l'application
        ///
        /////////////////////////////////////////////////
        sf::RenderWindow&    getFenetre();

    private:

        /////////////////////////////////////////////////
        /// Les membres
        /////////////////////////////////////////////////
        Gestion_ecrans      m_ecrans;    ///< Le gestionnaire des �crans.
        sf::RenderWindow    m_fenetre;   ///< La fen�tre SFML

};
}; // fin namespace app


#endif // APPLICATION_H


////////////////////////////////////////////////////////////
/// \class app::Application
/// \ingroup application
///
/// Manipule les diff�rents �crans de l'application � travers une boucle principale,
/// coeur de l'application, en simplifiant l�g�rement:
/// \li Ecouter les �venements utilisateurs ( claviers, cliques...).
/// \li Actualiser les parametres de tout les �l�ments.
/// \li Dessiner les �l�ments en vue dans la fenetre
///
/// C'est le getionnaire des �crans qui se charge du traitement de la pile des �crans.
///
/// Quand il n'y a plus d'�crans dans la pile, l'application qse ferme.
///
/// \see app::Ecran, app::EcranPrincipal
///
////////////////////////////////////////////////////////////
