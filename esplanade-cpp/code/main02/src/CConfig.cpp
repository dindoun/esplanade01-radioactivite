#include "Config.h"


#include <iostream>


namespace app {


    ResourceMgr<sf::Font,int>                   Config::_polices;
    sf::Time                                    Config::_dureeImage  ;
    //  std::map < gui::Styles , gui::Style * > Config::_styles = {};





    Config::Config()
    {
        //ctor
    }

    Config::~Config()
    {
        //dtor
    }

    void Config::init()
    {
        _dureeImage =     sf::seconds (1.f / 60.f);

        initPolices();
        initTextures();
        initStyles();
    }

    void Config::initPolices()
    {
        app::Config::_polices.load(     Polices::police_1 ,    "media/polices/arial.ttf"  );
        app::Config::_polices.load(     Polices::police_2 ,    "media/polices/bgothl.ttf"  );
    }

    void Config::initTextures()
    {
      //  _textures.

    }


    void Config::initStyles()
    {
/*
        _styles.insert ( { gui::Styles::Root , new gui::Style() } ) ;

        _styles[ gui::Styles::Root ]->txtPolice     =   _polices.get( Polices::police_2 );
        _styles[ gui::Styles::Root ]->txtTaille     =   15;
        _styles[ gui::Styles::Root ]->txtCouleur    =   sf::Color ( 200 , 200 , 200 );
        _styles[ gui::Styles::Root ]->lgnEpaisseur  =   0;
        _styles[ gui::Styles::Root ]->lgnCouleur    =   sf::Color ( 200 , 200 , 200 );
        _styles[ gui::Styles::Root ]->fndCouleur    =   sf::Color ( 20 , 20 , 20 );
        _styles[ gui::Styles::Root ]->alignement    =   gui::Align::Sans;


        _styles.insert ( { gui::Styles::Fenetre_1 , new gui::Style() } ) ;

        _styles[ gui::Styles::Fenetre_1 ]->txtPolice     =   _polices.get( Polices::police_2 );
        _styles[ gui::Styles::Fenetre_1 ]->txtTaille     =   15;
        _styles[ gui::Styles::Fenetre_1 ]->txtCouleur    =   sf::Color ( 200 , 200 , 200 );
        _styles[ gui::Styles::Fenetre_1 ]->lgnEpaisseur  =   1;
        _styles[ gui::Styles::Fenetre_1 ]->lgnCouleur    =   sf::Color ( 255 , 255 , 255, 50 );
        _styles[ gui::Styles::Fenetre_1 ]->fndCouleur    =   sf::Color ( 25 , 25 , 25 );
        _styles[ gui::Styles::Fenetre_1 ]->alignement    =   gui::Align::Hori;


        _styles.insert ( { gui::Styles::Menu_1 , new gui::Style() } ) ;

        _styles[ gui::Styles::Menu_1 ]->txtPolice     =   _polices.get( Polices::police_2 );
        _styles[ gui::Styles::Menu_1 ]->txtTaille     =   15;
        _styles[ gui::Styles::Menu_1 ]->txtCouleur    =   sf::Color ( 200 , 200 , 200 );
        _styles[ gui::Styles::Menu_1 ]->lgnEpaisseur  =   1;
        _styles[ gui::Styles::Menu_1 ]->lgnCouleur    =   sf::Color ( 255 , 255 , 255, 50 );
        _styles[ gui::Styles::Menu_1 ]->fndCouleur    =   sf::Color ( 200 , 200 , 200 );
        _styles[ gui::Styles::Menu_1 ]->alignement    =   gui::Align::Hori;


        _styles.insert ( { gui::Styles::Menu_2 , new gui::Style() } ) ;

        _styles[ gui::Styles::Menu_2 ]->txtPolice     =   _polices.get( Polices::police_1 );
        _styles[ gui::Styles::Menu_2 ]->txtTaille     =   10;
        _styles[ gui::Styles::Menu_2 ]->txtCouleur    =   sf::Color ( 200 , 200 , 200 );
        _styles[ gui::Styles::Menu_2 ]->lgnEpaisseur  =   1;
        _styles[ gui::Styles::Menu_2 ]->lgnCouleur    =   sf::Color ( 255 , 255 , 255, 50 );
        _styles[ gui::Styles::Menu_2 ]->fndCouleur    =   sf::Color ( 200 , 200 , 200 );
        _styles[ gui::Styles::Menu_2 ]->alignement    =   gui::Align::Hori;
        */
    }


}




















