#include "uscity.h"
#include <iostream>

void uscity::print() const {
    cout      << "Zip: " << zip << "\n"
              << "City: " << city << "\n"
              << "State: " << state_name << " (" << state_id << ")\n"
              << "Population: " << population << "\n"
              << "Density: " << density << "\n"
              << "County: " << county_name << "\n"
              << "Timezone: " << timezone << "\n" << endl;
}

