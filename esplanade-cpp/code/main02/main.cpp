#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <CModeDeDesintegration.h>

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




#include <CIsotope.h>










using namespace rad;
int main()
{   //  creation de l'application.

    CEsplanade esplanade;
    CDalle unedalle=esplanade.m_dalles[0];
    CMateriau unmateriau=unedalle.m_materiaux[0];
    CMolecule unemolecule=unmateriau.m_molecules[0];
    CAtome unatome=unemolecule.m_atomes[0];//U
    CIsotope unisotoperadioactif=unatome.m_isotopes[0];//U23
    //unisotopeNONradioactif=unatome.isotopes[1];//
    CModeDeDesintegration modeDeDesintegration00=unisotoperadioactif.m_ModesDeDesintegration[0];
    CModeDeDesintegration modeDeDesintegration01=unisotoperadioactif.m_ModesDeDesintegration[1];
unmateriau.Creemap(1.0);
    //modeDeDesintegration00.affiche_mode();
    //modeDeDesintegration01.affiche_mode();
/*
    CMateriau m;
    CMolecule c;
    CAtome a;
    CIsotope i;*/

/*
    CModeDeDesintegration mo;
    mo.affiche_mode();*/
    //mo.m_demi_vie=1.0;

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
