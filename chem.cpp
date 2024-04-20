#include <iostream>
#include <cmath>
#include <vector>

class ZerothOrderReactionSimulator {
private:
    double initialConcentration;
    double rateConstant;

public:
    ZerothOrderReactionSimulator(double initialConc, double rateConst) : initialConcentration(initialConc), rateConstant(rateConst) {}

    double simulateAtTime(double time) {
        return initialConcentration - rateConstant * time;
    }

    std::vector<double> simulateOverTime(double startTime, double endTime, double timeStep) {
        std::vector<double> concentrations;
        for (double time = startTime; time <= endTime; time += timeStep) {
            concentrations.push_back(simulateAtTime(time));
        }
        return concentrations;
    }
};

class FirstOrderReactionSimulator {
private:
    double initialConcentration;
    double rateConstant;

public:
    FirstOrderReactionSimulator(double initialConc, double rateConst) : initialConcentration(initialConc), rateConstant(rateConst) {}

    double simulateAtTime(double time) {
        return initialConcentration * exp(-rateConstant * time);
    }

    std::vector<double> simulateOverTime(double startTime, double endTime, double timeStep) {
        std::vector<double> concentrations;
        for (double time = startTime; time <= endTime; time += timeStep) {
            concentrations.push_back(simulateAtTime(time));
        }
        return concentrations;
    }
};

class SecondOrderReactionSimulator {
private:
    double initialConcentrationA;
    double initialConcentrationB;
    double rateConstant;

public:
    SecondOrderReactionSimulator(double initialConcA, double initialConcB, double rateConst) : initialConcentrationA(initialConcA), initialConcentrationB(initialConcB), rateConstant(rateConst) {}

    double simulateAtTime(double time) {
        return 1 / (1 / initialConcentrationA + rateConstant * time);
    }

    std::vector<double> simulateOverTime(double startTime, double endTime, double timeStep) {
        std::vector<double> concentrations;
        for (double time = startTime; time <= endTime; time += timeStep) {
            concentrations.push_back(simulateAtTime(time));
        }
        return concentrations;
    }
};

int main() {
    int choice;
    std::cout << "Choose the type of reaction to simulate:" << std::endl;
    std::cout << "1. Zeroth-order reaction" << std::endl;
    std::cout << "2. First-order reaction" << std::endl;
    std::cout << "3. Second-order reaction" << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1: {
        double initialConcentration = 1.0; // Initial concentration of reactant
        double rateConstant = 0.1; // Rate constant of the reaction
        double startTime = 0.0; // Start time of the interval
        double endTime = 10.0; // End time of the interval
        double timeStep = 1.0; // Time step for simulation

        ZerothOrderReactionSimulator zerothOrderSimulator(initialConcentration, rateConstant);
        std::vector<double> zerothOrderConcentrations = zerothOrderSimulator.simulateOverTime(startTime, endTime, timeStep);

        // Output the results
        for (size_t i = 0; i < zerothOrderConcentrations.size(); ++i) {
            std::cout << "Time: " << startTime + i * timeStep << ", Concentration: " << zerothOrderConcentrations[i] << std::endl;
        }
        break;
    }
    case 2: {
        double initialConcentration = 1.0; // Initial concentration of reactant
        double rateConstant = 0.1; // Rate constant of the reaction
        double startTime = 0.0; // Start time of the interval
        double endTime = 10.0; // End time of the interval
        double timeStep = 1.0; // Time step for simulation

        FirstOrderReactionSimulator firstOrderSimulator(initialConcentration, rateConstant);
        std::vector<double> firstOrderConcentrations = firstOrderSimulator.simulateOverTime(startTime, endTime, timeStep);

        // Output the results
        for (size_t i = 0; i < firstOrderConcentrations.size(); ++i) {
            std::cout << "Time: " << startTime + i * timeStep << ", Concentration: " << firstOrderConcentrations[i] << std::endl;
        }
        break;
    }
    case 3: {
        double initialConcentrationA = 1.0; // Initial concentration of reactant A
        double initialConcentrationB = 1.0; // Initial concentration of reactant B
        double rateConstant = 0.1; // Rate constant of the reaction
        double startTime = 0.0; // Start time of the interval
        double endTime = 10.0; // End time of the interval
        double timeStep = 1.0; // Time step for simulation

        SecondOrderReactionSimulator secondOrderSimulator(initialConcentrationA, initialConcentrationB, rateConstant);
        std::vector<double> secondOrderConcentrations = secondOrderSimulator.simulateOverTime(startTime, endTime, timeStep);

        // Output the results
        for (size_t i = 0; i < secondOrderConcentrations.size(); ++i) {
            std::cout << "Time: " << startTime + i * timeStep << ", Concentration: " << secondOrderConcentrations[i] << std::endl;
        }
        break;
    }
    default:
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
