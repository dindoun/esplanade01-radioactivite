#ifndef CESPLANADE_H
#define CESPLANADE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <CEsplanade.h>
#include <CDalle.h>
#include <CMateriau.h>
#include <CMolecule.h>
#include <CAtome.h>
#include <CIsotope.h>













#include <assert.h>
#include <cmath>
#include <complex.h>
#include <ctgmath>
#include <ctype.h>
#include <dirent.h>

#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <fenv.h>
#include <float.h>



#include <inttypes.h>
#include <iso646.h>
#include <jerror.h>

#include <jpeglib.h>

#include <libgen.h>
#include <libudev.h>
#include <limits.h>
#include <locale.h>
#include <math.h>



#include <setjmp.h>
#include <signal.h>



#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <tgmath.h>
#include <time.h>
#include <time.h>
#include <uchar.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>


using namespace rad;
class CEsplanade
{
    public:
        CEsplanade();
        virtual ~CEsplanade();
        std::vector<CDalle> m_dalles;
        sf::Vector3i m_taille;/**< nb de dalles dans esplanade */
        sf::Vector3i m_nb_cube;/**< /nb de cubes élémentaires dans une dalle */
        sf::Vector3f m_taille_dalle;
        sf::Vector3f m_origine;
        void afficher_dallage();
        void afficher_radioactivite();
        void initialisation();
        void set_dalle();
    protected:
    private:
};

#endif // ESPLANADE_H
