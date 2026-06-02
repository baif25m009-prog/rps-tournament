#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Save match result to results.txt file
void saveResult(string result)
{
    ofstream file("results.txt", ios::app);
    if(file)
    {
    file << result << endl;
    file.close();
    }
    else 
    {
        cout << "File not Opened Error!";
    }
}
// Read and show all results from results.txt file
void showResults()
{
    ifstream file("results.txt");
    if(file)
    {
    string line;

    cout << "\n===== TOURNAMENT RESULTS =====" << endl;

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
  }
  else
  {
    cout << "Error opening file!";
  }
}