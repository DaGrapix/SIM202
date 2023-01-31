#ifndef BOX_HPP
#define BOX_HPP
#include "particle.hpp"

double LENGTH = 10;

class box{
    public:
        int level;
        double center[3];
        double mass_center[3];
        double mass;
        particle* p_particle;
        box* p_sub_box;
        box* p_sister_box;
        double* force();
        void append_particle(particle& part);
        void pop_particle(particle& part);
};

bool is_in_box(particle& p, box& b);


#endif