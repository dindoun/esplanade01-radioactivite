#ifndef ESPLANADE_H
#define ESPLANADE_H

namespace rad
{
class Esplanade
{
    public:
        Esplanade();
        virtual ~Esplanade();
        std::vector< std::shared_ptr<dalle>> m_dalles;
        sf::Vector3i taille;
        void afficher_dallage();
        void afficher_radioactivite();
        void initialisation();
        void set_dalle();
    protected:
    private:
};
}
#endif // ESPLANADE_H
