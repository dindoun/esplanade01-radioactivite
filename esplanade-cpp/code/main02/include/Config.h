#ifndef CONFIG_H
#define CONFIG_H

/**
* \file     Config.h
* \brief    Fichier contenant les différents éléments de Config.
* \author   Christophe Pages
* \version  0.1
* \date     5 Octobre 2015
* \details  Config des textures, sons, musiques polices, tailles, couleurs ....
*/

#include <SFML/Graphics.hpp>
#include <map>

#include <ResourceMgr.h>



namespace app {

    /**
    * \class    Config
    * \brief    La classe contenant les différents éléments de Config.
    * \details  Config des textures, sons, musiques polices, tailles, couleurs ....
    */
    class Config
    {
        public:




            Config();
            virtual ~Config();



            enum Polices                :  int  { police_1
                                                , police_2   };



            /** \brief    Manager des textures */
            static  ResourceMgr<sf::Texture,int>                 _textures;

            /** \brief    Manager des polices */
            static  ResourceMgr<sf::Font,int>                    _polices;

         //   /** \brief    les styles pour le GUI */
          //  static  std::map < gui::Styles , gui::Style* >      _styles;



            /**
            * \brief    Durée d'une image
            * \details  Autrement dit on a 1/FrameRate = \e _dureeImage
            */
            static  sf::Time                                    _dureeImage;



            static void init();

        private:

            static void initTextures();
            static void initPolices();
            static void initStyles();


    };
}; // fin app
#endif // CONFIG_H


