#ifndef define CLASSES_HPP
#include <stdbool.h>
#include <vector>

class particle{
    public:
        //position
        double position[3];
        vector<double>* p_position;
        //speed
        double speed[3];
        vector<double>* p_speed;
        //force
        double force[3];
        vector<double>* p_force;
        //successive positions taken by the particle
        vector<vector<double>>* successive_positions;
        int successive_positions_size;
        //pointer to the next particle
        particle* p_next_particle;
        particle(vector<double> vector_);
};

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