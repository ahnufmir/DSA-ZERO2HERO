#include "functions.h"
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\n========== Graph Operations Menu ==========\n";
    cout << "1. Add Node\n";
    cout << "2. Add Edge\n";
    cout << "3. Delete Node\n";
    cout << "4. Delete Edge\n";
    cout << "5. Update Node Value\n";
    cout << "6. Get Edge Cost\n";
    cout << "7. Get Edge Count for Node\n";
    cout << "8. Get Total Node Count\n";
    cout << "9. Check if Node Exists\n";
    cout << "10. Display Graph\n";
    cout << "0. Exit\n";
    cout << "==========================================\n";
    cout << "Enter your choice: ";
}

int main() {
    Graph graph;
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int nodeValue;
                cout << "Enter node value: ";
                cin >> nodeValue;
                graph.addNode(nodeValue);
                cout << "Node " << nodeValue << " added.\n";
                break;
            }
            
            case 2: {
                int source, destination, cost;
                cout << "Enter source node: ";
                cin >> source;
                cout << "Enter destination node: ";
                cin >> destination;
                cout << "Enter edge cost: ";
                cin >> cost;
                graph.addEdge(source, destination, cost);
                cout << "Edge from " << source << " to " << destination << " with cost " << cost << " added.\n";
                break;
            }
            
            case 3: {
                int nodeValue;
                cout << "Enter node value to delete: ";
                cin >> nodeValue;
                graph.deleteNode(nodeValue);
                cout << "Node " << nodeValue << " deleted.\n";
                break;
            }
            
            case 4: {
                int source, destination;
                cout << "Enter source node: ";
                cin >> source;
                cout << "Enter destination node: ";
                cin >> destination;
                graph.deleteEdge(source, destination);
                cout << "Edge from " << source << " to " << destination << " deleted.\n";
                break;
            }
            
            case 5: {
                int oldValue, newValue;
                cout << "Enter old node value: ";
                cin >> oldValue;
                cout << "Enter new node value: ";
                cin >> newValue;
                graph.updateNode(oldValue, newValue);
                cout << "Node " << oldValue << " updated to " << newValue << ".\n";
                break;
            }
            
            case 6: {
                int source, destination;
                cout << "Enter source node: ";
                cin >> source;
                cout << "Enter destination node: ";
                cin >> destination;
                int cost = graph.getEdgeCost(source, destination);
                if (cost != -1) {
                    cout << "Edge cost from " << source << " to " << destination << " is: " << cost << endl;
                } else {
                    cout << "Edge does not exist or nodes not found.\n";
                }
                break;
            }
            
            case 7: {
                int nodeValue;
                cout << "Enter node value: ";
                cin >> nodeValue;
                int edgeCount = graph.getEdgeCountForNode(nodeValue);
                if (edgeCount >= 0) {
                    cout << "Node " << nodeValue << " has " << edgeCount << " outgoing edges.\n";
                } else {
                    cout << "Node does not exist.\n";
                }
                break;
            }
            
            case 8: {
                cout << "Total number of nodes in graph: " << graph.getNodeCount() << endl;
                break;
            }
            
            case 9: {
                int nodeValue;
                cout << "Enter node value to check: ";
                cin >> nodeValue;
                if (graph.hasNode(nodeValue)) {
                    cout << "Node " << nodeValue << " exists in the graph.\n";
                } else {
                    cout << "Node " << nodeValue << " does not exist in the graph.\n";
                }
                break;
            }
            
            case 10: {
                graph.display();
                break;
            }
            
            // case 11: {
            //   //  runPredefinedTests(graph);
            //     break;
            // }
            
            case 0: {
                cout << "Exiting program. Goodbye!\n";
                break;
            }
            
            default: {
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
        
        // Clear input buffer
        // cin.clear();
        
    } while (choice != 0);
    
    return 0;
}