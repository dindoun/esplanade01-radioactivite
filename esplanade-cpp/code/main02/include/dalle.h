#ifndef DALLE_H
#define DALLE_H

namespace rad
{
class dalle
{
    public:
        dalle();
        virtual ~dalle();
        sf::Vector3i position;
        std::vector< std::shared_ptr<materiau>> m_materiau;
        sf::Image m_map_radioactivite; // chaque dalle cree une map de radioactivite
        void creemap();
        void calcule_radioactivite();
    protected:
    private:
};

#endif // DALLE_H
};
