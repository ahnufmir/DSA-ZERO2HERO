#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
using namespace std;

template <typename T>
class Graph
{
private:
    int V;                // Stores the fixed number of vertices the graph supports.
    T **adjacency_matrix; // Dynamically allocated 2D array

public:
    Graph<T>()
    {
        V = 0;
        adjacency_matrix = nullptr;
    }
    Graph<T>(int initial_number_of_vertices)
    {
        V = initial_number_of_vertices;
        adjacency_matrix = new T *[initial_number_of_vertices];
        for (int i = 0; i < initial_number_of_vertices; i++)
        {
            adjacency_matrix[i] = new T[initial_number_of_vertices];
            for (int j = 0; j < initial_number_of_vertices; j++)
            {
                adjacency_matrix[i][j] = -1;
            }
        }
    } // Constructor; Dynamically allocate matrix int** adjacency_matrix. Initialize all entries to 0 to indicate no edges exist.
    ~Graph<T>()
    {
        for (int i = 0; i < V; i++)
        {
            delete[] adjacency_matrix[i];
        }
        delete[] adjacency_matrix;
    } // Destructor; Manually deallocate all dynamically allocated memory for the 2D matrix to prevent memory leaks.
    bool isValidVertex(int vertex_index) const
    {
        return ((vertex_index >= 0) && (vertex_index < V));
    } // Confirms the vertex index is positive and smaller than the total number of vertices in the graph.
    void addEdge(T source, T dest, T weight)
    {
        if (!isValidVertex(source) || !isValidVertex(dest))
        {
            cout << "Invalid Source or Destination" << endl;
            return;
        }

        adjacency_matrix[source][dest] = weight;
        adjacency_matrix[dest][source] = weight;
    } // Sets up a two-way connection between two existing nodes by marking the corresponding positions in the adjacency matrix as connected.
    void expandMatrix()
    {
        // V = V+1;
        T **temp = new T *[V + 1];

        for (int i = 0; i < V; i++)
        {
            temp[i] = new T[V + 1];
            for (int j = 0; j < V; j++)
            {

                temp[i][j] = adjacency_matrix[i][j];
            }
            temp[i][V] = -1;
        }
        temp[V] = new T[V + 1];
        for (int j = 0; j < V + 1; j++)
        {
            temp[V][j] = -1; 
        }
        for (int i = 0; i < V; i++)
        {
            delete[] adjacency_matrix[i];
        }
        delete[] adjacency_matrix;
        adjacency_matrix = temp;
        // temp[V-1][V-1] = T;
        V = V + 1;
    }
    void deleteEdge(T source, T dest)
    {
        if (!isValidVertex(source) || !isValidVertex(dest))
        {
            cout << "Invalid Source or Destination" << endl;
            return;
        }
        adjacency_matrix[source][dest] = -1;
        adjacency_matrix[dest][source] = -1;
    } // Removes the connection between two valid nodes by resetting the corresponding cells in the adjacency matrix to zero.
    void updateEdge(T old_source, T old_destination, T new_source, T new_destination, T weight)
    {
        if (!isValidVertex(old_source) || !isValidVertex(old_destination) || !isValidVertex(new_source) || !isValidVertex(new_destination))
        {
            cout << "Invalid Source or Destination" << endl;
            return;
        }
        // If there is an old edge, remove it first
        if (adjacency_matrix[old_source][old_destination] >= 0)
            deleteEdge(old_source, old_destination);

        // Add new edge
        adjacency_matrix[new_source][new_destination] = weight;
        adjacency_matrix[new_destination][new_source] = weight;
        // if ((adjacency_matrix[old_source][old_destination] == 0) && (adjacency_matrix[old_destination][old_source] == 0))
        // {
        //     adjacency_matrix[old_source][old_destination] = 1;
        //     adjacency_matrix[old_destination][old_source] == 1;
        // }
        // else
        // {
        //     adjacency_matrix[old_source][old_destination] = 0;
        //     adjacency_matrix[old_destination][old_source] == 0;
        // }
        // deleteEdge(old_source, old_destination);
    } // Update the connection of two existing nodes.
    bool checkEdgeStatus(T source, T dest)
    {
        if (adjacency_matrix[source][dest] >= 0)
        {
            return true;
        }
        else
            return false;

    } // To check the connection between two nodes is connected.
    int getDegree(int vertex_index)
    {
        if (!isValidVertex(vertex_index))
        {
            cout << "Invalid Vertex Index" << endl;
            return -1;
        }
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if ((adjacency_matrix[vertex_index][i]) >= 0)
                count++;
        }
        return count;
    } // return the total count of edges of this node.
    void displayGraph()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << adjacency_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void setWeight(T source, T dest, T weight)
    {
        if (!isValidVertex(source) || !isValidVertex(dest))
        {
            cout << "Invalid Vertex" << endl;
            return;
        }
        adjacency_matrix[source][dest] = weight;
        adjacency_matrix[dest][source] = weight;
    }
    T getWeight(T source, T dest)
    {
        if (!isValidVertex(source) || !isValidVertex(dest))
        {
            cout << "Invalid Vertex" << endl;
            return T();
        }
        return (adjacency_matrix[source][dest]);
    }
    T *getNeighbours(T vertex_index, int &count)
    {
        if (!isValidVertex(vertex_index))
        {
            cout << "Invalid Vertex Index" << endl;
            return nullptr;
        }
        count = 0;
        for (int i = 0; i < V; i++)
        {
            if ((adjacency_matrix[vertex_index][i]) != 0)
                count++;
        }
        T *arr = new T[count];
        int k = 0;
        for (int i = 0; i < V; i++)
        {
            if (adjacency_matrix[vertex_index][i] != 0)
            {
                arr[k] = i;
                k++;
            }
        }
        return arr;
    }
    // void setVertexName(int index, const T* name){
    //     adjacency_matrix[index] = name;
    // }
    // string getVertexName(int index) const{
    //     return adjacency_matrix[index];
    // }
    // void checkIndex(T* name){

    // }
    void menu()
    {
        cout << "=================== MENU =====================" << endl;
        cout << "1. Add Edge" << endl;
        cout << "2. Delete Edge" << endl;
        cout << "3. Update Edge" << endl;
        cout << "4. Check Edge Status" << endl;
        cout << "5. Check count of edges of node" << endl;
        cout << "6. Check Neighbours" << endl;
        cout << "7. Display Graph" << endl;
    } // print the entire graph with adjacent nodes.
};

#endif
