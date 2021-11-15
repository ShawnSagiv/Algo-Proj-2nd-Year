//This class is the Data Structure for the second and third algorithms - Matrix Multiplication and Alon, Yuster, Zwick.
// the Data Structure is a two dimensions array - if: M[i][j] = 1 - there is an edge i -> j, else: there is not
#pragma once
#include <iostream>
#include "Cell.cpp"
#include "Graph.h"
#include <cmath>
using namespace std;

class Matrix{

private:
    int** matrix; // origin matrix;
    int** res_matrix; // matrix after M^x -> M^3 in our case (second alg)
    int ver; // sum of vertex --> plus 1 for Psize of arrays.
    int edges; // sum of edges
    int* degrees; // the degrees of the vertexes -> degrees[i]= rank(i)
public:
    //Ctor
    Matrix(int ver)
    {
        int count=1;
        int count2 =0;
        this->ver=ver;
        this->edges =0;
        //initialize degrees array
        degrees = new int[ver+1];
        for(int m=0;m<=ver;m++)
        {
            degrees[m]=0;
        }

        matrix  = new int*[ver];
        res_matrix  = new int*[ver];
        for (int i = 0; i < ver; ++i)
        {
            matrix[i] = new int[ver]; // initialize Matrix
            res_matrix[i] = new int[ver];// initialize res_Matrix
        }
        // set up the all the cell to be 0 and the boarders (line-0 and raw-0 to cont from 0 to "ver")
        // for printing.
        for(int i =0;i<ver;i++)
        {
            for(int j=0;j<ver;j++)
            {
                if(i==0 )
                {
                    matrix[i][j]=count2;
                    res_matrix[i][j]=count2;
                    count2++;
                }
                else if(j==0)
                {
                    matrix[i][j]=count;
                    res_matrix[i][j]=count;
                    count++;
                }
                else
                {
                    matrix[i][j]=0;
                    res_matrix[i][j]=0;
                }

            }
        }


    }

    // Setters:
    void set_res_matrix(int** mat)
    {
        this->res_matrix=mat;
    }

    // Getters:
    int get_value(int x, int y)
    {
        return this->matrix[x][y];
    }

    int get_degree(int x)
    {
        return degrees[x];
    }

    //add adge to the graph
    void add_edge(int x, int y)
    {

        this->matrix[x][y] = 1;
        this->res_matrix[x][y]=1;
        this->edges++;
        degrees[x]++;
        degrees[y]++;
    }
    // check for the edge x->y in the matrix
    bool is_edge_exist(int x,int y)
    {
        if(this->matrix[x][y] > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //matrix * res_matrix.
    int** matrix_mult()
    {
        //matrix A
        int** m1 = this->matrix;
        //matrix B
        int** m2 = this->res_matrix;
        //matrix result
        Matrix res(ver);


        for(int i=1; i<ver; i++){
            for(int j=1; j<ver; j++){
                int sum =0;
                for(int k=1; k<ver; k++){
                    sum += (m1[i][k] * m2[k][j]);
                }
                res.matrix[i][j] = sum;
            }
        }

        /*
        //output the result matrix
        cout << "Result Matrix: \n";
        for(int i=0; i<ver; i++){
            for(int j=0; j<ver; j++){
                cout << res.matrix[i][j] << "\t";
            }
            cout << "\n";
        }
        */
        this->res_matrix=res.matrix;
        return res.matrix;

    }


    void print_matrix()
    {
        cout << "Res matrix: \n";
        for(int i=0; i<ver; i++)
        {
            if(i==1)
            {
                cout<<"  _";
                for(int i=0;i<=ver*4;i++)
                {
                    cout<<"_";
                }
                cout<<endl;
            }
            for(int j=0; j<ver; j++)
            {
                if(j==1)
                {
                    cout<<" |  ";
                }
                cout << this->res_matrix[i][j] << "\t";
            }
            cout << "\n";


        }
    }

    //check all matrix[i][i] cells for match triangle and print appropriate message.
    bool check_triangle()
    {
        int sum=0;
        int * res_triangle = new int[ver];
        //int count=0;


        for(int i=1;i<ver;i++)
        {
            sum=sum+res_matrix[i][i];
            if(res_matrix[i][i] >0)
            {
                res_triangle[i] =1;
            }
            else
            {
                res_triangle[i] =0;
            }

        }

        if(sum>0)
        {
            cout<<"There is  a triangle in the graph!"<<endl;
            print_triangle(res_triangle,ver);
            return true;

        }else{
            cout<<"There is NO a triangle in the graph!"<<endl;
            return false;
        }



    }

    // main func for organization only.
    bool find_triangle_two()
    {
        this->matrix_mult();
        this->matrix_mult();
        if(this->check_triangle())
        {
            return true;
        }
        return false;

    }

    void print_triangle(int * arr, int size)
    {
        for(int i=1;i<size;i++)
        {
            for(int j=2;j<size;j++)
            {
                for(int k=3;k<size;k++)
                {

                    if(arr[i]!=0 || arr[j]!=0 || arr[k]!=0)
                    {
                        if(is_edge_exist(i,j) && is_edge_exist(j,k)&& is_edge_exist(k,i))
                        {
                            cout<< "The triangle: ";
                            cout<<i;
                            cout<<"-->";
                            cout<<j;
                            cout<<"-->";
                            cout<<k<<endl;
                            return;
                        }
                        else if(is_edge_exist(j,i) && is_edge_exist(i,k)&& is_edge_exist(k,j))
                        {
                            cout<< "The triangle: ";
                            cout<<i;
                            cout<<"-->";
                            cout<<j;
                            cout<<"-->";
                            cout<<k<<endl;
                            return;

                        }
                    }



                }
            }
        }

    }


    //************** part III *******************//

    bool  part_I()
    {
        float delta = pow(this->edges,0.5);

        for(int i=1;i<ver;i++) // vertexes v ( i=v )
        {
            if(degrees[i]< delta) // if the degree of vertex v < delta -> "Low rank"
            {
                for(int j=1;j<ver;j++)  // j=u
                {
                    for(int k=1;k<ver;k++) // k=w
                    {
                        if(i!=j && j!=k) // disregard the case of i==j==k.
                        {
                            if(is_edge_exist(j,i) && is_edge_exist(i,k)) // for the Route u->v->w
                            {
                                if(is_edge_exist(k,j)) //  check if exist w->u
                                {
                                    cout<<"There is a triangle in the graph!"<<endl;
                                    cout<< "The triangle: ";
                                    cout<<i;
                                    cout<<"-->";
                                    cout<<j;
                                    cout<<"-->";
                                    cout<<k<<endl;
                                    return true;

                                }
                            }

                        }


                    }
                }

            }
        }

        return false;
    }

    bool part_II()
    {
        float delta = pow(this->edges,0.5);

        Matrix g(ver);

        for(int i=1;i<ver;i++)
        {
            for(int j=1;j<ver;j++)
            {
                if(degrees[i] > delta) // if the degree of vertex v > delta -> "High rank"
                {
                    if(is_edge_exist(i,j)) // build the new graph G'.
                    {
                        g.add_edge(i,j);
                    }
                }
            }

        }

        //cout<<"G' Matrix:"<<endl;
       // g.print_matrix();
        if(g.find_triangle_two()) // using the Matrix multiplication algorithm.
        {
            return true;
        }

        return false;

    }

// main func for organization only.
    void find_triangle_three()
    {
        if(this->part_I())
        {
            return;
        }
        if(this->part_II())
        {
            return;
        }


    }


};


