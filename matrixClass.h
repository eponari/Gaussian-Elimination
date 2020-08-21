#include <iostream>
#include <iomanip>
#include <vector>
#include <unistd.h>
using namespace std;


class matrix{
  private:
    vector<vector<double> > matrix_values;
    int size;

  public:
  	
  	//Constructor
    matrix(int size){
      system("CLS");
      int num;
      this->size=size;
      cout<<"Please enter each row with "<<size<<"+1 values, the variables and the result of each equation.\n";
      //get each row
      for(int i=0;i<size;i++){
      	//each row has size+1 values, size meaning the number of variables and +1 is the result of each equation in the matrix
        vector <double> new_row;
        for(int j=0;j<=size;j++){
          cin>>num;
          new_row.push_back(num);
        }
        matrix_values.push_back(new_row);
      }
    }
    
    //the functions below are simple algorithms used in Gaussian Elimination. Link: http://acm.epoka.edu.al/share/gaussian_elimination.pdf
    void eleminate_down(int pos,int target){
      double multi=matrix_values[target][pos];
      for(int i=pos;i<matrix_values.size()+1;i++){
        matrix_values[target][i]-=multi*matrix_values[pos][i];
      }
    }
    
    void eleminate_up(int pos,int target){
      double multi=matrix_values[target][pos];
      for(int i=0;i<matrix_values.size()+1;i++){
        matrix_values[target][i]-=multi*matrix_values[pos][i];
      }
    }
    
    void make_pivot(int pos){
      double div=matrix_values[pos][pos];
      for(int i=pos;i<matrix_values.size()+1;i++){
        matrix_values[pos][i]=double(matrix_values[pos][i])/div;
      }
    }
    
    //prints the matrix and waits 3 seconds so the user knows what is going on
    void print_vector(int n){
      for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
          cout<<matrix_values[i][j]<<" ";
        }
        cout<<"\n";
      }
      sleep(3);
    }
    
    //main algorithm used to solve the problem by using the functions above.
    void solve_matrix(){
      for(int i=0;i<size;i++){
          make_pivot(i);
          for(int j=i+1;j<size;j++){
          	system("CLS");
            eleminate_down(i,j);
            print_vector(size);
          }
      }
      for(int i=size-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
          system("CLS");
          eleminate_up(i,j);
          print_vector(size);
        }
      }
      system("CLS");
      cout<<"Final Results: \n";
      print_vector(size);
      cout<<"(If you get inf or error value,\nthe matrix either has no solution or has infinite solutions.)\n";
    }
};
