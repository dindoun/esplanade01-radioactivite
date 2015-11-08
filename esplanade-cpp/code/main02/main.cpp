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

    /*
    CAtome unatome=unemolecule.m_atomes[0];//U
    CIsotope unisotoperadioactif=unatome.m_isotopes[0];//U23
    CModeDeDesintegration modeDeDesintegration00=unisotoperadioactif.m_ModesDeDesintegration[0];
    CModeDeDesintegration modeDeDesintegration01=unisotoperadioactif.m_ModesDeDesintegration[1];
    */

    //unemolecule.m_atomes[0]=CAtome();


    // GRANITE / 1-10ppm d URANIUM 12.5-125 bq/kg // 5-30 ppm Th 20-120 bq/kg // 4% K40 100bq/kg
    unmateriau.m_nom="granite";

    unemolecule.m_nom="granite";
    unemolecule.m_Proportion=0.1;


    CAtome unatome=unemolecule.m_atomes[0];
        unatome.m_nom_atome=ATOMES::U;

        unatome.m_isotopes[0].m_Numero_Atomique=234;
            //CIsotope unisotoperadioactif=unatome.m_isotopes[0];
            unatome.m_isotopes[0].m_Proportion=0.000056;

            CModeDeDesintegration mode=unatome.m_isotopes[0].m_ModesDeDesintegration[0];
                mode.m_Demi_Vie=245.5E3*( 365.25 * 24.0 * 3600.0 );


        //unatome.m_isotopes[1].m_Numero_Atomique=235;
        CIsotope unisotoperadioactif;


        unisotoperadioactif.m_Numero_Atomique=235;
            unisotoperadioactif.m_Proportion=0.007202;
            unisotoperadioactif.m_ModesDeDesintegration[0].m_Demi_Vie=703.8E6*( 365.25 * 24.0 * 3600.0 );
            unatome.m_isotopes.push_back(unisotoperadioactif);



        unisotoperadioactif.m_Numero_Atomique=238;
            unisotoperadioactif.m_Proportion=0.992742;
            unisotoperadioactif.m_ModesDeDesintegration[0].m_Demi_Vie=4.4688E9*( 365.25 * 24.0 * 3600.0 );
            unatome.m_isotopes.push_back(unisotoperadioactif);

    for (auto iso : unatome.m_isotopes){
        printf("%d \n",iso.m_Numero_Atomique);

        }
    //    m_isotopes


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
