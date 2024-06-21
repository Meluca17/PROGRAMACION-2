/* 
 * File:   EstanteHorizontal.cpp
 * Author: ramir
 * 
 * Created on 21 de junio de 2024, 12:23 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "EstanteHorizontal.h"

EstanteHorizontal::EstanteHorizontal() {
}

EstanteHorizontal::EstanteHorizontal(const EstanteHorizontal& orig) {
}

EstanteHorizontal::~EstanteHorizontal() {
}

void EstanteHorizontal::lee(ifstream &archEst){
    Estante::lee(archEst);
}