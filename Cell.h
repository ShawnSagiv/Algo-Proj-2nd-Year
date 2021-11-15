//This class is the nodes that Ingredients the linked list of neighbors from every.
// cell onn the array that also from "Cell" kind.
#pragma once
#include <iostream>
using namespace std;

class Cell{

private:
    int from; // for array cells - the number of vertex, linked list - the destination of the edge
    Cell* next_nighboor;// pointer for the next cell.

public:
    //Ctor
    Cell()
    {
        this->from =0;
        this->next_nighboor=NULL;

    }
    //Ctor
    Cell(int vertex)
    {
        this->from=vertex;
        this->next_nighboor=NULL;

    }

    // Getters:
    Cell* get_next_cell()
    {
        return this->next_nighboor;

    }

    int get_from()
    {
        return this->from;
    }

    Cell* get_last_vertex()
    {
        Cell* temp = this;
        while(temp->next_nighboor!=NULL)
        {
            temp=temp->next_nighboor;

        }
        return temp;
    }

    //Setters:
    void set_next_cell(Cell* c)
    {

        this->next_nighboor=c;

    }

    void set_from(int f)
    {
        this->from=f;
    }

    void set_next_ver(Cell v)
    {
        this->next_nighboor=&v;
    }

    bool is_the_edge_exist(int to)
    {
        Cell* temp = this->next_nighboor;

        while(temp!=NULL)
        {
            if(temp->from == to)
            {
                return true;
            }
            temp = temp->next_nighboor;
        }
        return false;
    }





















};



