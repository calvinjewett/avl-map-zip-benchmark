#ifndef USCITY_H
#define USCITY_H
#include <string>
using namespace std;

class uscity {
private:
    string zip;
    string lat;
    string lng;
    string city;
    string state_id;
    string state_name;
    string zcta;
    string parent_zcta;
    string population;
    string density;
    string county_fips;
    string county_name;
    string county_weights;
    string county_names_all;
    string imprecise;
    string military;
    string timezone;

public:
    //Default constructor
    uscity() = default;

    //Actual constructor
    uscity(const std::string& zip,
         const std::string& lat,
         const std::string& lng,
         const std::string& city,
         const std::string& state_id,
         const std::string& state_name,
         const std::string& zcta,
         const std::string& parent_zcta,
         const std::string& population,
         const std::string& density,
         const std::string& county_fips,
         const std::string& county_name,
         const std::string& county_weights,
         const std::string& county_names_all,
         const std::string& imprecise,
         const std::string& military,
         const std::string& timezone)
         : zip(zip), lat(lat), lng(lng), city(city), state_id(state_id), state_name(state_name),
          zcta(zcta), parent_zcta(parent_zcta), population(population), density(density),
          county_fips(county_fips), county_name(county_name), county_weights(county_weights),
          county_names_all(county_names_all), imprecise(imprecise), military(military),
          timezone(timezone) {}

    //Getters
    std::string getZip() const { return zip; }
    std::string getLat() const { return lat; }
    std::string getLng() const { return lng; }
    std::string getCity() const { return city; }
    std::string getStateId() const { return state_id; }
    std::string getStateName() const { return state_name; }
    std::string getZcta() const { return zcta; }
    std::string getParentZcta() const { return parent_zcta; }
    std::string getPopulation() const { return population; }
    std::string getDensity() const { return density; }
    std::string getCountyFips() const { return county_fips; }
    std::string getCountyName() const { return county_name; }
    std::string getCountyWeights() const { return county_weights; }
    std::string getCountyNamesAll() const { return county_names_all; }
    std::string getImprecise() const { return imprecise; }
    std::string getMilitary() const { return military; }
    std::string getTimezone() const { return timezone; }

    //Setters
    void setZip(const std::string& val) { zip = val; }
    void setLat(const std::string& val) { lat = val; }
    void setLng(const std::string& val) { lng = val; }
    void setCity(const std::string& val) { city = val; }
    void setStateId(const std::string& val) { state_id = val; }
    void setStateName(const std::string& val) { state_name = val; }
    void setZcta(const std::string& val) { zcta = val; }
    void setParentZcta(const std::string& val) { parent_zcta = val; }
    void setPopulation(const std::string& val) { population = val; }
    void setDensity(const std::string& val) { density = val; }
    void setCountyFips(const std::string& val) { county_fips = val; }
    void setCountyName(const std::string& val) { county_name = val; }
    void setCountyWeights(const std::string& val) { county_weights = val; }
    void setCountyNamesAll(const std::string& val) { county_names_all = val; }
    void setImprecise(const std::string& val) { imprecise = val; }
    void setMilitary(const std::string& val) { military = val; }
    void setTimezone(const std::string& val) { timezone = val; }

    //Print info
    void print() const;

    
    };
#endif
