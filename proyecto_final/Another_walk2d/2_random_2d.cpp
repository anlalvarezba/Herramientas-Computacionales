#include <random>
#include <iostream>
#include <cstdio>

 
int main()
{

  int nsteps=5;
  int npaths=1;
  double ran=0.0;
  // int x=0;
  int *X = new int [nsteps];
  int *Y = new int [nsteps];
  float *M = new float [nsteps*npaths];
  float *N = new float [nsteps*npaths];
  float *R = new float [nsteps*npaths*2];

  for(int i=0; i<nsteps; i++){
    X[i]=0;
    Y[i]=0;
  }

   for(int i=0; i<nsteps*npaths; i++){
    M[i]=0.0;
    N[i]=0.0;
    //R[i]=0.0;
    }

     for(int i=0; i<nsteps*npaths*2; i++){
    R[i]=0.0;
    }
  
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for(int i=0; i<npaths; i++){
      //  printf("%3d  ", i+1);
      
    for (int n = 0; n <nsteps; ++n) {
      ran= dis(gen);
      // Use dis to transform the random unsigned int generated by gen into a 
        // double in [1, 2). Each call to dis(gen) generates a new random double
      if(ran<0.25){
	X[n] -=1;
      }
      else if(ran<0.5){
	Y[n] -=1;
      }
      else if(ran<0.75){
	X[n] +=1;
      }
      else{
	Y[n] +=1;
	}
	
	M[n+i*nsteps] = 1.0*X[n];
	N[n+i*nsteps] = 1.0*Y[n];
	//R[i] += 1.0*((X[n]*X[n]) +(Y[n]*Y[n])) ;
	
	//printf("%3d %3d ", X[n], Y[n]);
    }
    
    // printf("%5.3f %5.3f  ", M[i]/npaths, N[i]/npaths);
    // printf("%5.3f %5.3f  ", (M[i]*M[i])/npaths,  (N[i]*N[i])/npaths);
    // printf("%5.3f  ", R[i]/npaths);

    for(int n=0; n<nsteps*npaths; n++){
      R[n]=M[n];
     }

    for(int n=nsteps*npaths ; n<2*nsteps*npaths; n++){
      R[n]=N[n-nsteps*npaths];
     }
    }


     for(int j=0; j<nsteps*npaths; j++){
       printf("%5.3f %5.3f  ", R[j], R[j+nsteps*npaths]);
        printf(" \n");
    }
    
    
     printf(" \n");
     
    

    delete [] X;
    delete [] Y;
    delete [] M;
    delete [] N;
    delete [] R;
}
