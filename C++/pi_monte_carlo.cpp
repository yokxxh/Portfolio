#include <iostream>
#include <random>
#include <cmath>

double estimate_pi(int num_simulations)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    int points_inside_circle{};
    for (int i = 0; i < num_simulations; ++i)
    {
        double x = dis(gen);
        double y = dis(gen);
        
        if (std::sqrt(x * x + y * y ) < 1.0 )
        {
            points_inside_circle++;
        }
    }

    return 4.0 * points_inside_circle / num_simulations;

}

int main()
{
    int num_simulations{};
    std::cout << "Enter the number of simulations: ";
    std::cin >> num_simulations;

    double pi_estimation{estimate_pi(num_simulations)};
    std::cout << "Estimated pi :" << pi_estimation;

    return 0;
}