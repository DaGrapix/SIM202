#include "particle.hpp"
#include <cmath>
#include <vector>

//Reinitialising a particle
void particle::erase_particle(){
    if (position.empty()==false){
        position.clear();
    }
    if (speed.empty()==false){
        speed.clear();
    }
    if (force.empty()==false){
        force.clear();
    }
    if (successive_positions.empty()==false){
        successive_positions.clear();
    }
    p_next_particle = nullptr;
}

//Constructors
particle::particle(){
    erase_particle();
    position = vector<double>(3, 0);
    speed = vector<double>(3, 0);
    force = vector<double>(3, 0);

    vector<double> default_vector = vector<double>(3,0);
    successive_positions = vector<vector<double>>(1, default_vector);
    p_next_particle = nullptr;
}

particle::particle(vector<double> position_vector, vector<double> speed_vector, vector<double> force_vector){
    erase_particle();
    position = position_vector;
    speed = speed_vector;
    force = force_vector;
}

//Destructor
particle::~particle(){
    erase_particle();
};


void particle::print(ostream& out){
    out << "position :     [";
    for (int i = 0; i <= 1; i++){
        out << position[i] << ", ";
    }
    out << position[2] << "]" << endl;

    out << "speed :        [";
    for (int i = 0; i <= 1; i++){
        out << speed[i] << ", ";
    }
    out << speed[2] << "]" << endl;

    out << "force :        [";
    for (int i = 0; i <= 1; i++){
        out << force[i] << ", ";
    }
    out << force[2] << "]" << endl;
}

ostream& operator <<(ostream& out, particle& particle_){
    particle_.print(out);
    return out;
}