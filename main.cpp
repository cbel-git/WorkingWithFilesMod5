#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream fileInput;
    vector<int> cityTempsF;
    vector<int> cityTempsC;
    vector<string> cityNames;


    fileInput.open("FahrenheitTemperature.txt");

    if (!fileInput.is_open()) {
        cout << "file not open" << endl;
        return 1;
    }
    else {
        string line;

        cout << "File opened." << endl << endl;

        while (getline(fileInput, line)) {
            istringstream iss(line);
            string cityName;
            int temperature;

            if (iss >> cityName >> temperature) {
                cityNames.push_back(cityName);
                cityTempsF.push_back(temperature);
            }
        }

        for (int i = 0; i < cityTempsF.size(); i++) {
            int tempF = cityTempsF[i];
            int tempC;
            tempC = static_cast<int>((tempF - 32) * (5.0 / 9.0));

            cityTempsC.push_back(tempC);
        }
        fileInput.close();
        cout << "File text extraction successful." << endl << endl;
    }


    // for putting data into the new file
    ofstream fileOutput;
    fileOutput.open("CelsiusTemperature.txt");


    if (fileOutput.is_open()) {

        cout << "Output file opened successfully." << endl << endl;

        for (int i = 0; i < cityNames.size(); i++) {
            fileOutput << cityNames[i] << " " << cityTempsC[i] << endl;
        }
        fileOutput.close();
        cout << "File creation and text output successful." << endl;

    }
    else {
        cout << "Output file not opened.";
        return 1;
    }







}
