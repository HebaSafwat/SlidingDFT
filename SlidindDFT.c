/******************************************************************************

                             the Slding DFT 

*******************************************************************************/

#include <stdio.h> 
#include <complex.h> 
#include <math.h> 

#define pi 3.1416
#define N 10
int main(void)  
{ 
   int mainarray[N][1]= {1,-5,2,7,1,7,2,4,0,9};        /*the main matrix*/
   int a[N/2][1];                                      /*empty matrix for the sup component from the main matrix*/
   int i ,j,n,k,l=0,summ =0;                           /*variables for counting*/
                                
   int save1[N/2][1];                                  /*empty matrix to save the last array*/        
   double complex fft[N/2][1];                         /*the fft for the elements using fft function*/
   double complex test[N/2][1];                        /*the fft for the elements using sliding FFT*/
   /************************array to calculate the FFt ***********************************/
   double complex array1[N/2][N/2]= {  1,1,1,1,1,
                                   1 ,0.3-0.95*I,-0.8-0.59*I,-0.8+0.59*I,0.3+0.95*I,
                                   1 ,-0.8-0.59*I, 0.3+0.95*I, 0.3-0.95*I, -0.8+0.59*I ,
                                   1 , -0.8+0.59*I , 0.3-0.95*I, 0.3+0.95*I ,-0.8-0.59*I,
                                   1 , 0.3+0.95*I , -0.8+0.59*I, -0.8-0.59*I , 0.3-0.95*I 
                                };
	
    /**********************the component a ant its fft*********************************/
	for (k = summ;k<summ+(N/2);k++)
	{
	    a[l][0]= mainarray[k][0];          /*copy first five elements to the matrix a*/
	    save1[l][0]=a[l][0]; 
	    l++;
	}
	/********************calculate the FFT for a matrix *****************************/
	for (i=0;i<(N/2);i++)
    {
	    double complex sum ;
	    double complex sop =0;
	    for ( j = 0; j < (N/2); j++)
	    {
	         sum = array1[i][j]*a[j][0];
	         sop = sum +sop ;
	    } 
	    fft[i][0]=sop;
	 }
	 printf("the FFT for the first five element\n");
	 for (j=0;j<(N/2);j++)
     {
        printf("%.1f %+.1fi\n",fft[j][0]);
     }

     /*the other componnents and their FFTusing the wo methods (FFT function & Sliding DFT)*/
	 for (n=0;n<(N/2);n++)
	 {
	    summ++;
	    l=0;
	    for (k = summ;k<summ+(N/2);k++)
	    {
	         a[l][0]= mainarray[k][0];
	         l++;
	    }
	    /*print the components*/
	    printf("*****************************\n");
	    printf("the element of the array:\n");
	    for (l=0;l<(N/2);l++)
	    {
	        printf(" %d\n",a[l][0]);
	    }
	    /*******************calculate FFT using sliding DFT method******************/
	    for (j=0;j<((N/2));j++)
	    {
	        test[j][0] = (fft[j][0] +a[((N/2)-1)][0] - save1[0][0])* (cos((2*pi*j)/(N/2)) + I * sin((2*pi*j)/(N/2)));
	    }
	    for(j=0;j<(N/2);j++)
	    {
	       save1[j][0] = a[j][0] ;
	    }
	    printf("the DFT from Sliding method:\n");
	    for (  i = 0; i < (N/2); i++)
	    {
	       printf("%.1f %+.1fi\n", test[i][0]);
	    }
        
	    /*****************calculate FFT using FFt function method******************/
	    for (i=0;i<(N/2);i++)
	    {
	        double complex sum ;
	        double complex sop =0;
	        for ( j = 0; j < (N/2); j++)
	        {
	             sum = array1[i][j]*a[j][0];
	             sop = sum +sop ;
	        } 
	        fft[i][0]=sop;
	     }
	     printf("the DFT from FFT function:\n");
	     for (  i = 0; i < (N/2); i++)
	     {
	        printf("%.1f %+.1fi\n", fft[i][0]);
	     }
	}
} 