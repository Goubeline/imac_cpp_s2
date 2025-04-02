#include "ex02.hpp"

#include <iomanip>
#include <functional>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

std::vector<std::pair<Insect, int>> get_insect_observations(
    const size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    const unsigned int seed = std::random_device{}()) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { randInsectIndex() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        //If we have already seen the same insect, increment the count on the last observation
        auto& previous_observation { observations.back() };
        if(previous_observation.first == random_insect) {
            previous_observation.second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts)
{
    std::vector<float> probas;
    size_t total = 0;
    for (int count : counts)
    {
        total += count;
        probas.push_back(count);
    }

    for (size_t i = 0; i < probas.size(); i++)
    {
        probas[i] /= total;
    }
    return probas;
}

int main()
{
    std::vector<float> probabilites = probabilities_from_count(expected_insect_counts);
    std::vector<std::pair<Insect, int>> observation = get_insect_observations(10000, probabilites);
    std::unordered_map<Insect, int>classifie;

    for(std::pair<Insect, int> vu : observation)
    {
        classifie[vu.first] += vu.second;
    }

    std::vector<int> actual_insect_count;
    for (Insect insect : insect_values)
    {
        actual_insect_count.push_back(classifie.find(insect)->second);
    }
    std::vector<float> statistiques = probabilities_from_count(actual_insect_count);

    std::cout << "Probabilities of observed insects vs expected probabilities" << std::endl;
    int defile = 0;
    float diff;
    for (Insect insect : insect_values)
    {
        std::cout << insect_to_string.find(insect)->second << " : " << std::setprecision(3) << std::fixed
                    << statistiques[defile] << " vs " << probabilites[defile];
        
        diff = probabilites[defile] - statistiques[defile];
        if (diff < 0.01 && diff > -0.01)
            std::cout << " OK" << std::endl;
        else
            std::cout << " BAD" << std::endl;

        defile++;
    }
    
}