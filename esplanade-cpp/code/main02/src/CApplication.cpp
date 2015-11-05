

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Application.h"

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Config.h"
#include "ecrans\EcranPrincipal.h"


namespace app
{
/////////////////////////////////////////////////
Application::Application()
{

    //   Initialisation de la class Config.
    Config::init();

    //   Creation de la fen�tre SFML.
    sf::ContextSettings 	contextFenetre  ( 	0,  //  depth
                                                0,  //  stencil
                                                0,  //  antialiasing
                                                2,  //  major
                                                0); //  minor
    m_fenetre.create(sf::VideoMode(800, 600), "Appli de base" , sf::Style::Default , contextFenetre );

    //   Ajout du premier �cran.
    m_ecrans.ajouter( new EcranPrincipal( this ) );

}


/////////////////////////////////////////////////
Application::~Application()
{
    // vider la pile.
    m_ecrans.vider();
}


/////////////////////////////////////////////////
void    Application::executer()
{

    sf::Clock   horloge;
    sf::Time    tempsDepuisMAJ = sf::Time::Zero;

    while ( m_fenetre.isOpen() )
    {
        traiterEvenements();
        tempsDepuisMAJ += horloge.restart();
        while (tempsDepuisMAJ > Config::_dureeImage)
        {
            tempsDepuisMAJ -= Config::_dureeImage;

            // Traitement des �venements.
            traiterEvenements();

            // Actualisation des �l�ments des �crans.
            actualiser( Config::_dureeImage.asSeconds() );

            // si la pile d'�crans est vide, on ferme.
            if ( m_ecrans.estVide() )
                m_fenetre.close();
        }

        // Dessiner les �crans actifs.
        dessiner();
    }
}


/////////////////////////////////////////////////
sf::RenderWindow&    Application::getFenetre()
{
    return m_fenetre;
}



/////////////////////////////////////////////////
void Application::traiterEvenements()
{
    sf::Event event;
    while (m_fenetre.pollEvent(event)){

        m_ecrans.traiter_evenements ( event );

        if (event.type == sf::Event::Closed)
            m_fenetre.close();
    }
}


/////////////////////////////////////////////////
void Application::actualiser ( float deltaT )
{
    m_ecrans.actualiser ( deltaT );
}


/////////////////////////////////////////////////
void Application::dessiner ( )
{

    /// > Vider la fenetre.
    m_fenetre.clear(sf::Color::Black);

    /// > Rendu des ecrans courants.
    m_ecrans.dessiner();

    /// > Afficher la fen�tre.
    m_fenetre.display();


}
} // namespace app
