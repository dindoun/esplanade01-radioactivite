#ifndef ECRANPRINCIPAL_H
#define ECRANPRINCIPAL_H

/////////////////////////////////////////////////
//  Headers
/////////////////////////////////////////////////
#include    <SFML/Graphics.hpp>
#include    <Ecran.h>
#include    <Application.h>

namespace app {

/////////////////////////////////////////////////
/// \class  EcranPrincipal
/// \brief  Ecran de d�monstration
///
/// Peut-�tre pour tester d'autre trucs, comme la bibilo d'interface graphique...
///
/////////////////////////////////////////////////
class EcranPrincipal : public Ecran
{
public:

    /////////////////////////////////////////////////
    /// \brief Constructeur
    ///
    /////////////////////////////////////////////////
    EcranPrincipal( Application* appli );

private:
    /////////////////////////////////////////////////
    /// \brief La gestion des �v�nements utilisateurs.
    ///
    /// \details  G�re les entr�es claviers, souris, fenetre ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void traiter_evenements ( const sf::Event& event );

    /////////////////////////////////////////////////
    /// \brief Actualiser les �l�ments.
    ///
    /// \details Actualiser les diff�rents �l�ments du ou des �crans actifs.
    /// \param   deltaT          Un \e float qui indique le delta du temps �coul� depuis la derni�re actualisation.
    /// \return  Rien
    ///
    /////////////////////////////////////////////////
    virtual     void actualiser ( float deltaT );

    /////////////////////////////////////////////////
    /// \brief Rendre les �l�ments.
    ///
    /// Dessiner les diff�rents �l�ments du ou des �crans actifs.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void dessiner  ( );

    /////////////////////////////////////////////////
    /// \brief Fonction a supprimer
    ///
    /// juste l� pour tester des machins bidules.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void test ();

    /////////////////////////////////////////////////
    /// \brief Initialisation de l'interface graphique.
    ///
    /// Creation des fenetres, boutons, menus... ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void initGUI ();

private:

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////

    sf::View            m_vue;   ///< La vue SFML de l'�cran.
    sf::RectangleShape  m_fond;  ///< Le shape SFML du fond de l'�cran.
   // gui::Groupe*     m_gui;         ///< Le groupe de GUI du menu principal.


}; // fin EcranPrincipal
}; // fin app
#endif // ECRANPRINCIPAL_H
