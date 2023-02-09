#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>


using json = nlohmann::json;

int main() {

    std::ifstream f("cost_info.json");
    json cost_data = json::parse(f);

    std::string region_name = cost_data["aws-us-east"]["region_name"].get<std::string>();

    // example of looping across elements in a json object
    for (auto& regions : cost_data.items()) {    
        json region = regions.value();
        std::cout << "key: " << regions.key() <<  "'\n'region_name: " << region["region_name"].get<std::string>() << "\n\n";

        std::cout << "Network Costs: \n\n";

        for (auto& network_costs : region["network_cost"].items()) {
            std::cout << "to: " << network_costs.key() << "\ncost: " << network_costs.value().get<double>() << "\n\n";
        }

    }


    std::cout << region_name;



    return 0;
}
