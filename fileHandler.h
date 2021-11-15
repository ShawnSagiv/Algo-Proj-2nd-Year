#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>


using namespace std;


namespace file {

	class FileHandler {

	private:
		int numOfAlgo;
		int numOfVertexes;

		typedef list< pair<int, int> > list_t;
		list_t listPair;

	public:
		//constructor
		
		FileHandler(string fileName) {
			ifstream myfile;
			int lineNum = 0;
			string line;
            string v,v1;

			myfile.open(fileName);
			if (myfile.fail())
			{
				cout << "Sorry, I was unable to open file." << endl;
				exit(1);
			}
			
			while (!myfile.eof()) {
				// Output the text from the file
				try
				{
					if (lineNum == 0)
					{

						//validity check to int

						myfile>>v;
						numOfAlgo = stoi(v);
						if(numOfAlgo > 4 || numOfAlgo  <1)
                        {
						    cout<<"Incorrect num of func!!!"<<endl;
                        }
					}
					else if (lineNum == 1)
					{
					    myfile>>v1;
						//validity check to int
						numOfVertexes = stoi(v1);
					}
					else
					{
                        int first, second;
					    myfile>>first>>second;
					    cout<<"first: "<<first<<endl;
                        cout<<"second: "<<second<<endl;
                        if(first<1 ||  first > numOfVertexes || second<1 || second>numOfVertexes)
                        {
                            cout<<"incorect details"<<endl;
                            cout<<"the edge :" << first<<  " -> "<< second<< "is not in range" << endl;
                            exit(1);
                        }
						appendEdgesToList(first, second);

					}
				}
				catch (const std::exception&)
				{
					cout << "failed reading INT from file" << endl;
					exit(1);
				}
				
				lineNum++;
			}
			if (getNumberOfEdges() < 2)
			{
				cout << "file doesnt contain enough data" << endl;
				exit(1);
			}
			
		}

		//getters
		int getNumOfAlgo() { return numOfAlgo; }
		int getNumOfVertexes() { return numOfVertexes; }
		list_t getEdgesList() { return listPair; }
		int getNumberOfEdges() { return listPair.size(); }


		//setters
		void setNumOfAlgo(int num) { numOfAlgo = num; }
		void setNumOfVertexes(int num) { numOfVertexes = num; }
		void appendEdgesToList(int first, int second) { listPair.push_back(make_pair(first, second)); }
		

	};
}



/*
 * while (getline(myfile, line)) {
				// Output the text from the file
				try
				{
					if (lineNum == 0)
					{
						//validity check to int
						numOfAlgo = stoi(line);
						if(numOfAlgo > 4 || numOfAlgo  <1)
                        {
						    cout<<"Incorrect num of func!!!"<<endl;
                        }
					}
					else if (lineNum == 1)
					{
						//validity check to int
						numOfVertexes = stoi(line);
					}
					else
					{
					    cout<<"first: "<<line[0]<<endl;
                        cout<<"second: "<<line[2]<<endl;
                        int first =line[0]-48;
                        int second = line[2]-48;


						appendEdgesToList(first, second);

					}
				}
 */