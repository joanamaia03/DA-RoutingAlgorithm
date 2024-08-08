#include "menu.h"
#include "data_structures/reader.h"

menu::menu() = default;

void menu::mainMenuDisplay() {
    cout<<"\n""|--------------------------------------------|\n"
              "|                    Menu                    |\n"
              "|--------------------------------------------|\n"
              "|           Solutions to the TSP:            |\n"
              "|          1:Backtracking Algorithm          |\n"
              "|    2:Triangular Approximation Heuristic    |\n"
              "|             3:Other Heuristics             |\n"
              "|                  4: Exit                   |\n"
              "|--------------------------------------------|\n";
}
void menu::mainMenu() {
    int choice;
    do {
        mainMenuDisplay();
        choice = readInteger("Select your option: ");
        switch(choice){
            case 1:{
                Reader h;
                Graph graph = h.readToy("shipping");
                vector<bool> visited;
                queue<int> shortestPath;
                double bestCost = INT_MAX;
                for (int i = 0; i < graph.getVertexQuant(); i++) {
                    visited.push_back(false);
                }
                graph.backtrackTSP(visited,0, 1, 0, bestCost, shortestPath);
                cout<<"Best Cost: "<<bestCost<<endl;
                while (!shortestPath.empty()) {
                    cout << shortestPath.front() << " ";
                    shortestPath.pop();
                }
                cout << endl;
                break;
            }
            case 2:{
                Graph graph = reader.readReal("graph3");
                double result = graph.triangleAproximationHeuristic();
                cout << "RESULT: " << result;
                cout << 0;
                break;
            }
            case 3:{
                cout<<"function 3";
                break;
            }
            default:{
                if(choice!=4){
                    cout<<"Invalid number! Select a number between 1 and 3";
                }
                continue;
            }
        }
    }
    while(choice!=4);
}
int menu::readInteger(const string& x) {
    int result;
    cout << '\n' << x;
    while(!(cin >> result)){
        cout<<"Please insert an integer number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return result;
}
