/* 
 * File:   EstanteVertical.cpp
 * Author: ramir
 * 
 * Created on 21 de junio de 2024, 12:23 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "EstanteVertical.h"

EstanteVertical::EstanteVertical() {
}

EstanteVertical::EstanteVertical(const EstanteVertical& orig) {
}

EstanteVertical::~EstanteVertical() {
}

void EstanteVertical::lee(ifstream &archEst){
    Estante::lee(archEst);
}