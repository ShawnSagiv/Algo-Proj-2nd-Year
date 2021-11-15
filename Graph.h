// Shawn Sagiv - 204816631
// This Class is the main Class which holds the graph itself.
// I use one-dimension array that symbolized the n - vertexes (zero is nothing)
// from every cell in the array the neighbors are Illustrated to be a list of nodes = "Cells"
#pragma once
#include <iostream>
#include "Cell.h"
using namespace std;

class Graph{
private:
    int num_of_vertexes; // sum of vertex
    int num_of_edges; // sum of edges
    Cell* graph; // List of neighbors
    int ver; // sum of vertex

public:

    // Ctor fo the graph
    // Allocation of memory the size of vertexes and update the "left line" (the array)
    Graph(int num_of_vertex)
    {
        this->num_of_vertexes=num_of_vertex;
        this->num_of_edges=0;
        this->graph = new Cell [num_of_vertex +1]; // im not gonna use graph[0]
        this->ver = num_of_vertex;

        for(int i=0;i<=num_of_vertex;i++)
        {
            this->get_cell_of_arr_by_index(i)->set_from(i);
        }

    }

    // Getters:

    Cell* get_graph()
    {
        return this->graph;
    }

    Cell* get_cell_of_arr_by_index(int idx)
    {
        return &this->graph[idx];
    }

    int get_num_of_vertex()
    {
        return this->num_of_vertexes;
    }

    //Setters:
    void set_num_of_vertexes(int num)
    {
        this->num_of_vertexes = num;
    }

    //add an edge to the graph.
    void add_edge(int from, int to)
    {

        if(from==to)
        {
            cout<<"This is a SIMPLE graph! there are no Repeating edges";
            return;
        }

        Cell * newCell = new Cell(to); //memory Allocation
        Cell* temp = this->get_cell_of_arr_by_index(from);
        this->num_of_edges++;

        while(temp->get_next_cell() !=NULL)
        {
            if(to == temp->get_next_cell()->get_from())
            {
                cout<<"This edge is already exist!";
                return;

            }
            temp = temp->get_next_cell();
        }
        temp->set_next_cell(newCell);
    }

    void print_graph()
    {
        for(int i=1;i<=num_of_vertexes;i++)
        {
            Cell* x = get_cell_of_arr_by_index(i);
            while(x !=NULL)
            {
                cout<<x->get_from();
                cout<<" -> ";
            x=x->get_next_cell();
            }
            cout<<"NULL";
        cout<<endl;
        }
    }

//Algorithm #1: pseudo code:
// for each edge (u,v) in g:
//      for each vertex m in g:
//          if (m,u) and (v,m) are edges: return true;
//    return false
    bool find_triangle_one()
    {
        for(int i=1;i<=ver;i++)
        {

            Cell* temp;
            temp = this->get_cell_of_arr_by_index(i);
            int flag =0;

            while(flag < 1)
            {
                if(temp->get_next_cell() == NULL)
                {
                    flag=2;
                }
                else
                {
                    temp = temp->get_next_cell();
                }

                for(int j=1;j<=ver;j++)
                {
                    if(this->get_cell_of_arr_by_index(j)->is_the_edge_exist(i) && this->get_cell_of_arr_by_index(temp->get_from())->is_the_edge_exist(j) )
                    {
                        if(j!=i  && temp->get_from() != i ) // disregard the case of i==j==k. (temp->get_from() = k)
                        {
                            if(i != j && temp->get_from() !=i )
                            {
                                cout<<"There is a triangle in the graph!"<<endl;
                                cout<< "The triangle: ";
                                cout<<j;
                                cout<<"-->";
                                cout<<i;
                                cout<<"-->";
                                cout<<temp->get_from()<<endl;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        cout<<"There is NO a triangle in the graph!"<<endl;
        return false;
    }







};