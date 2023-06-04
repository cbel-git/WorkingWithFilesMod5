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

    // opens file for extraction
    fileInput.open("FahrenheitTemperature.txt");

    // checking if the file is open, if not return error.
    if (!fileInput.is_open()) {
        cout << "file not open" << endl;
        return 1;
    }
    else {
        string line;


        // informs user file opened
        cout << "File opened." << endl << endl;


        // pulls information from the file, puts it in a vector
        while (getline(fileInput, line)) {
            istringstream iss(line);
            string cityName;
            int temperature;

            // adding info to their respective vector
            if (iss >> cityName >> temperature) {
                cityNames.push_back(cityName);
                cityTempsF.push_back(temperature);
            }
        }

        // takes temp vector and makes a converted vector
        for (int i = 0; i < cityTempsF.size(); i++) {
            int tempF = cityTempsF[i];
            int tempC;
            tempC = static_cast<int>((tempF - 32) * (5.0 / 9.0));

            cityTempsC.push_back(tempC);
        }
        // informs user of text extraction success
        fileInput.close();
        cout << "File text extraction successful." << endl << endl;
    }


    // for putting data into the new file
    ofstream fileOutput;
    fileOutput.open("CelsiusTemperature.txt");

    // checking if output file is opened
    if (fileOutput.is_open()) {

        //informs user of success
        cout << "Output file opened successfully." << endl << endl;

        // writes new data to the new file
        for (int i = 0; i < cityNames.size(); i++) {
            fileOutput << cityNames[i] << " " << cityTempsC[i] << endl;
        }
        fileOutput.close();
        cout << "File creation and text output successful." << endl;

    }
    else {
        // if file not opened, inform user
        cout << "Output file not opened.";
        return 1;
    }







}
