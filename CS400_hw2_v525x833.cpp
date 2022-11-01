// cs400_hw2_v525x833.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm>

// TODO: implement this function to return a Pascal Triangle
std::vector<std::vector<int>> pascalTriangle(int row) {

    std::vector<std::vector<int>> result; //declare new vector 

    for (int line = 0; line < row; line++) //loop for first 8 rows
    {
 
        std::vector<int> v; //another vector
        for (int i = 0; i <= line; i++) //loop for the double vector
        {

             if(line==i || i==0){ //if this condition is true 
                    v.push_back(1); //push back the 1 to the new vector result
                }
                else{
                    v.push_back(result[line-1][i-1]+result[line-1][i]); //otherwise do this calculation for pascal triangle
                }
            } 
            result.push_back(v); //push back any remaining cases
           
            
        }
    return result; //return it
}

// TODO: implement this function to print Pascal Triangles 
void printPascalTriangle(const std::vector<std::vector<int>>& triangle) {
    for (int i = 0; i < triangle.size(); i++) //loop for internal vector
    {
        for (int j = 0; j < triangle[i].size(); j++) //loop again for the 2d vector
        {
            std::cout << triangle[i][j] << " "; //output the result
        }
        std::cout << std::endl;
     }
}

// TODO: implement this function to return comparison result. See main() for usage. 
std::vector<bool> compare(const std::vector<std::vector<int>>& triangle,
    const std::vector<int>& allegedSummations) {

    int k = 0;
    std::vector<bool> r;
    double sum = 0.0;
    int n = 0; //initialize these
      
    while (k < allegedSummations.size()) //for the first 8 rows
    {
        //sum = pow(2, n); //take the 2^n because thats what each row is 
        sum = std::accumulate(triangle[k].begin(), triangle[k].end(), 0); //use of accumulate function
        if (allegedSummations.at(k) == sum) //check against this vector
        { 
            r.push_back(true); //if they equal return true
        } 
        else
            r.push_back(false); //if not 
       // n++;
        k++; // go up
    }

    return r; //return result
}


int main()
{
    
    // part 1: generate and print Pascal Triangle
    // expected output
    // 1
    // 1 1
    // 1 2 1
    // 1 3 3 1
    // 1 4 6 4 1
    // 1 5 10 10 5 1
    // 1 6 15 20 15 6 1
    // 1 7 21 35 35 21 7 1

    int rows = 8;
    auto triangle = pascalTriangle(rows);
    printPascalTriangle(triangle);
    std::cout << std::endl;

    // part 2: check alleged summations
    // expected returrn: {1, 1, 0, 1, 0, 1, 0, 1, 1, 0}
    std::vector<int> allegedSum{ 1, 2, 5, 8, 17, 32, 65, 128, 256, 511 };
    auto sumCheck = compare(pascalTriangle(allegedSum.size()), allegedSum);
    for (auto b : sumCheck) {
        std::cout << b << " ";
    }

    std::cout << std::endl;

}

