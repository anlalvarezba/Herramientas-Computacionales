#include <random>
#include <iostream>
#include <cstdio>


 
int main()
{

  double ran=0.0;
  int x=0;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for(int i=0; i<10; i++){
      
    for (int n = 0; n < 4; ++n) {
      ran= dis(gen);
      // Use dis to transform the random unsigned int generated by gen into a 
        // double in [1, 2). Each call to dis(gen) generates a new random double
      if(ran<0.5){
	x -=1;
      }
      else{
	x +=1;
	}
      printf("%10d %10.3f %10d \n", n, ran, x);
    }
     printf(" \n");
    }
}
