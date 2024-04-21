#include <iostream>
#include <cmath>
#include<fstream>
#include <vector>
using namespace std;

class ZerothOrderReactionSimulator {
private:
    double initialConcentration;
    double rateConstant;

public:
    ZerothOrderReactionSimulator(double initialConc, double rateConst) : initialConcentration(initialConc), rateConstant(rateConst) {}

    double simulateAtTime(double time) {
        return initialConcentration - rateConstant * time;
    }

    vector<double> simulateOverTime(double startTime, double endTime, double timeStep) {
        vector<double> concentrations;
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

    vector<double> simulateOverTime(double startTime, double endTime, double timeStep) {
        vector<double> concentrations;
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

    vector<double> simulateOverTime(double startTime, double endTime, double timeStep) {
        vector<double> concentrations;
        for (double time = startTime; time <= endTime; time += timeStep) {
            concentrations.push_back(simulateAtTime(time));
        }
        return concentrations;
    }
};

int main() {
    int choice;
    cout << "Choose the type of reaction to simulate:" << std::endl;
    cout << "1. Zeroth-order reaction" << std::endl;
    cout << "2. First-order reaction" << std::endl;
    cout << "3. Second-order reaction" << std::endl;
    cin >> choice;

    switch (choice) {
    case 1: {
        double initialConcentration = 1.0; 
        double rateConstant = 0.1; 
        double startTime = 0.0; 
        double endTime = 10.0; 
        double timeStep = 1.0; 

        ZerothOrderReactionSimulator zerothOrderSimulator(initialConcentration, rateConstant);
        vector<double> zerothOrderConcentrations = zerothOrderSimulator.simulateOverTime(startTime, endTime, timeStep);

         for (size_t i = 0; i < zerothOrderConcentrations.size(); ++i) {
            cout << "Time: " << startTime + i * timeStep << ", Concentration: " << zerothOrderConcentrations[i] << std::endl;
        }

        ofstream dataFile("zeroth_order_data.txt");
        for (size_t i = 0; i < zerothOrderConcentrations.size(); ++i) {
            dataFile << startTime + i * timeStep << " " << zerothOrderConcentrations[i] << std::endl;
        }
        dataFile.close();

        string gnuplotScript = "plot 'zeroth_order_data.txt' with lines title 'Zeroth-order Reaction'\n";
        ofstream scriptFile("plot_script.gnu");
        scriptFile << gnuplotScript;
        scriptFile.close();

        system("gnuplot -persistent plot_script.gnu");

        break;
    }
    case 2: {
        double initialConcentration = 1.0; 
        double rateConstant = 0.4;
        double startTime = 0.0; 
        double endTime = 10.0; 
        double timeStep = 1.0; 

        FirstOrderReactionSimulator firstOrderSimulator(initialConcentration, rateConstant);
        vector<double> firstOrderConcentrations = firstOrderSimulator.simulateOverTime(startTime, endTime, timeStep);

        for (size_t i = 0; i < firstOrderConcentrations.size(); ++i) {
            cout << "Time: " << startTime + i * timeStep << ", Concentration: " << firstOrderConcentrations[i] << std::endl;
        }

        ofstream dataFile("first_order_data.txt");
        for (size_t i = 0; i < firstOrderConcentrations.size(); ++i) {
            dataFile << startTime + i * timeStep << " " << firstOrderConcentrations[i] << std::endl;
        }
        dataFile.close();

        string gnuplotScript = "plot 'first_order_data.txt' with lines title 'First-order Reaction'\n";
        ofstream scriptFile("plot_script.gnu");
        scriptFile << gnuplotScript;
        scriptFile.close();

        system("gnuplot -persistent plot_script.gnu");

        break;
    }
    case 3: {
        double initialConcentrationA = 1.0; 
        double initialConcentrationB = 1.0; 
        double rateConstant = 0.1; 
        double startTime = 0.0; 
        double endTime = 10.0; 
        double timeStep = 1.0; 

        SecondOrderReactionSimulator secondOrderSimulator(initialConcentrationA, initialConcentrationB, rateConstant);
        vector<double> secondOrderConcentrations = secondOrderSimulator.simulateOverTime(startTime, endTime, timeStep);

        for (size_t i = 0; i < secondOrderConcentrations.size(); ++i) {
            cout << "Time: " << startTime + i * timeStep << ", Concentration: " << secondOrderConcentrations[i] << std::endl;
        }

        ofstream dataFile("second_order_data.txt");
        for (size_t i = 0; i < secondOrderConcentrations.size(); ++i) {
            dataFile << startTime + i * timeStep << " " << secondOrderConcentrations[i] << std::endl;
        }
        dataFile.close();

        string gnuplotScript = "plot 'second_order_data.txt' with lines title 'Second-order Reaction'\n";
        ofstream scriptFile("plot_script.gnu");
        scriptFile << gnuplotScript;
        scriptFile.close();

        system("gnuplot -persistent plot_script.gnu");

        break;
    }
    default:
        cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
