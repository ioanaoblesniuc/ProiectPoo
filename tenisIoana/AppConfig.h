#include "includes.h"
#include "Properties.h"

class AppConfig{
	std::map<Properties,char*> properties;
	std::map<Feature, float> pricePerFeature;
public:
	void setup()
	{
		properties.insert(*new std::pair<Properties, char*>(Properties::PATH_PLAYERS, "players.txt")); //per day
		properties.insert(*new std::pair<Properties, char*>(Properties::PATH_USERS, "users.txt")); // per day

		pricePerFeature.insert(*new std::pair<Feature, int>(Feature::GHID_TURISTIIC, 100)); //per day
		pricePerFeature.insert(*new std::pair<Feature, int>(Feature::HOTEL, 70)); // per da

	}
	char* get(Properties proprety)
	{
		return  properties.find(proprety)->second;
	}
};
