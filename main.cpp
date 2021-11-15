#include <iostream>
#include "Graph.h"
#include "Cell.h"
#include "Matrix.h"
#include <cmath>
#include "fileHandler.h"
#include <string>
void main_func(file::FileHandler file);


int main(int argc, char* argv[] )
{

    //insert  file

   // Graph m(10);

   file::FileHandler file(argv[1]);
    main_func(file);
/*
    m.add_edge(1,2);
    m.add_edge(5,3);
    m.add_edge(5,6);
    m.add_edge(4,5);
    m.add_edge(9,5);
    m.add_edge(1,5);
    m.add_edge(3,1);
    m.add_edge(3,9);
    m.add_edge(3,10);
    m.add_edge(3,7);

    m.print_graph();
    m.find_triangle_one();


*/


    /*
    Matrix m(11); // we suppose to enter - num of vertex + 1;

    m.add_edge(1,2);
    m.add_edge(5,3);
    m.add_edge(5,6);
    m.add_edge(4,5);
    m.add_edge(9,5);
    m.add_edge(1,5);
    m.add_edge(3,1);
    m.add_edge(3,9);
    m.add_edge(3,10);
    m.add_edge(3,7);

    m.add_edge(1,3);
    m.add_edge(7,3);
    m.add_edge(7,5);
    m.add_edge(7,6);
    m.add_edge(1,7);
    m.add_edge(9,7);
    m.add_edge(6,1);
    m.add_edge(10,6);
    m.add_edge(8,10);
    m.add_edge(8,9);
    m.add_edge(2,6);
    m.add_edge(9,1);

    m.print_matrix();
    m.find_triangle_three();
*/




}



void main_func(file::FileHandler file)
{
    int number_of_edges  = file.getNumberOfEdges();
    int num_of_vertex = file.getNumOfVertexes();
    int func_num = file.getNumOfAlgo();
    cout<<"Number of vertex: "<<num_of_vertex <<endl;
    cout<<"Number of edges: "<<number_of_edges <<endl;
    cout<<"func num : "<<func_num <<endl;

    //import thelistof edges
    list< pair<int, int> > list_of_edge = file.getEdgesList();

    if(func_num == 1)
    {
        Graph g(num_of_vertex);

        for(pair<int,int> t  : list_of_edge)
        {
            g.add_edge(t.first,t.second);
            cout<<"FIRST: "<< t.first<<endl;
            cout<<"SECOND: "<< t.second<<endl;

        }
        g.print_graph();
        g.find_triangle_one();
    }
    else if(func_num == 2|| func_num ==3)
    {

        Matrix m(num_of_vertex + 1);
        for(pair<int,int> t  : list_of_edge)
        {
            m.add_edge(t.first,t.second);
            cout<<"FIRST: "<< t.first<<endl;
            cout<<"SECOND: "<< t.second<<endl;

        }
        if(func_num == 2)
        {
            m.print_matrix();
            m.find_triangle_two();
        }
        else if (func_num ==3)
        {
            m.print_matrix();
            m.find_triangle_three();
        }

    }

    else if(func_num == 4)
    {

        cout<<"func num 1 :"<<endl;
        Graph g(num_of_vertex);

        for(pair<int,int> t  : list_of_edge)
        {
            g.add_edge(t.first,t.second);
            cout<<"FIRST: "<< t.first<<endl;
            cout<<"SECOND: "<< t.second<<endl;

        }
        g.print_graph();
        g.find_triangle_one();


        Matrix m(num_of_vertex + 1);
        for(pair<int,int> t  : list_of_edge)
        {
            m.add_edge(t.first,t.second);
            cout<<"FIRST: "<< t.first<<endl;
            cout<<"SECOND: "<< t.second<<endl;

        }

        cout<<"func num 2 :"<<endl;
        m.print_matrix();
        m.find_triangle_two();

        cout<<"func num 3 :"<<endl;

        m.print_matrix();
        m.find_triangle_three();



    }else{
        cout<<"Incorrect func number:"<<endl;

    }


}







/*

    Graph g(7);

    int x =0 , y=0;
    while(x>=0 || y>=0)
    {

        cin>>x;
        cin>>y;
        if(x<0 || y<0)
        {
            return 0;
        }

        g.add_edge(x,y);
    }
    g.print_graph();


if(g.find_triangle(5))
{
    cout<<"yes!";
}


cout<<endl;
cout<<endl;
cout<<endl;

    int i=0;
    while(i<=5)
    {
        cout << g.get_cell_of_arr_by_index(i)->get_from()<<endl;
        i++;
    }
*/



/*
    Matrix m(11);

    m.add_edge(1,2);
    m.add_edge(2,3);
    m.add_edge(1,5);
    m.add_edge(5,2);
    m.add_edge(2,1);
    m.add_edge(6,8);
    m.add_edge(10,9);
    m.add_edge(9,1);
    m.add_edge(9,5);
    m.add_edge(8,10);
    m.add_edge(4,8);
    m.add_edge(10,6);
    //m.print_matrix();
  m.find_triangle_two();
  //m.print_matrix();
*/

/*
Graph g(10);


g.add_edge(1,2);
g.add_edge(2,3);
g.add_edge(2,5);
g.add_edge(5,2);
g.add_edge(11,1);
g.add_edge(6,8);
g.add_edge(10,9);
g.add_edge(9,1);
g.add_edge(9,5);
g.add_edge(8,10);
g.add_edge(4,8);
g.add_edge(10,6);
g.print_graph();

g.find_triangle_one();

*/