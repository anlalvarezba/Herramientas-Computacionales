#include <random>
#include <iostream>
#include <cstdio>

 
int main()
{

  int nsteps=40;
  int npaths=1000;
  double ran=0.0;
  int cont = 0;
 
  float M [nsteps*npaths];
  float N [nsteps*npaths];
  float K [nsteps*npaths];
  float R [nsteps*npaths*3];
  float T [nsteps];

  for(int i=0; i<nsteps; i++){
   T[i]=0.0;
  }


  

   for(int i=0; i<nsteps*npaths; i++){
    M[i]=0.0;
    N[i]=0.0;
    K[i]=0.0;
    }

     for(int i=0; i<nsteps*npaths*3; i++){
    R[i]=0.0;
    }

    int seed=10;
    std::mt19937 gen(seed);
     
    //std::random_device rd;  //Will be used to obtain a seed for the random number engine
    //std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    std::uniform_real_distribution<> dis(0.0, 1.0);

    for(int i=0; i<npaths; i++){
      int x=0;
      int y=0;
      int z=0;
        
      
    for (int n = 1; n <nsteps; ++n) {

      ran= dis(gen);
      double prob = 1.0/6.0;
     
      if(ran<prob ){
	x -=1;
      }
      else if(ran<2*prob){
	y -=1;
      }
      else if(ran<3*prob){
	z -=1;
      }
       else if(ran<4*prob){
	x +=1;
      }
      else if(ran<5*prob){
	y +=1;
      }
      else {
	z +=1;
	}
      
	       M[n+i*nsteps] = 1.0*x;
	       N[n+i*nsteps] = 1.0*y;
	       K[n+i*nsteps] = 1.0*z;
	       


       for(int j=i*nsteps; j<n+i*nsteps; j++){
       	if(( M[n+i*nsteps] == M[j]) && ( N[n+i*nsteps] == N[j]) && (K[n+i*nsteps] == K[j])){
       	       n=0;
       	       x=0;
       	       y=0;
       	       z=0;
       	       break;
       	  }
       }
      
	   
    }


    for(int n=0; n<nsteps*npaths; n++){
      R[n]=M[n];
     }

    for(int n=nsteps*npaths ; n<2*nsteps*npaths; n++){
      R[n]=N[n-nsteps*npaths];
     }

    for(int n=2*nsteps*npaths ; n<3*nsteps*npaths; n++){
      R[n]=K[n-2*nsteps*npaths];
     }


    
    }

    
    //for(int j=0; j<cont1; j++){
    for(int j=0; j<nsteps; j++){
      for(int i=j; i<npaths*nsteps; i += nsteps){
	
	//printf("%5.0f %5.0f  ", R[i], R[i + nsteps*npaths]);
	T[j] += ((R[i]*R[i]) + ( R[i + nsteps*npaths]* R[i + nsteps*npaths]) + (R[i + 2*nsteps*npaths]* R[i + 2*nsteps*npaths]));
      }
     
      printf("%3d %5.3f ", cont, T[j]/npaths);
      // printf(" \n");
       cont++;
       for(int i=j; i<npaths*nsteps; i += nsteps){

	  printf("%5.0f %5.0f  %5.0f  ", R[i], R[i + nsteps*npaths], R[i + 2*nsteps*npaths]);
	//T[j] += ((R[i]*R[i]) + ( R[i + nsteps*npaths]* R[i + nsteps*npaths]));
	
      }
        printf(" \n");
    } 
    
     //  printf(" \n");
     
    

     // delete [] X;
     // delete [] Y;
     //delete [] M;
     //delete [] N;
     //delete [] R;
}

