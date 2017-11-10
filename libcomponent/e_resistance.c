#include <stdio.h>
#include <stdlib.h>
#include "e_resistance.h"

int e_resistance(float orig_resistance, float *res_array )
{
int ans=0;
int count=0;
int *e12=(int*)malloc(32*sizeof(int));
e12[0]=10;
e12[1]=12;
e12[2]=15;
e12[3]=18;
e12[4]=22;
e12[5]=27;
e12[6]=33;
e12[7]=39;
e12[8]=47;
e12[9]=56;
e12[10]=68;
e12[11]=82;
 
int len=32;

for (int i=0; i< len-12; i++){

	e12[i+12]=e12[i]*10;
	
}

res_array[0]=0;
res_array[1]=0;
res_array[2]=0;

	for (int i=len-1; i>=0; i--)
	{
		for (int j=len-1; j>=0; j--)
		{
			for (int k=len-1; k>=0; k--)
			{
				if (orig_resistance-e12[i]==0)
				{
					res_array[0]=e12[i];
					res_array[1]=0;
					res_array[2]=0;
					ans=1;
					i,j,k=-1;
				}
				else if (orig_resistance-e12[i]-e12[j]==0)
				{
		                        res_array[0]=e12[i];
			                res_array[1]=e12[j];
					res_array[2]=0;
					ans=2;
					i,j,k=-1;		
				}
				else if (orig_resistance-e12[i]-e12[j]-e12[k]==0)
				{
                                        res_array[0]=e12[i];
                                        res_array[1]=e12[j];
                                        res_array[2]=e12[k];
					ans=3;
					i,j,k=-1;
				}
			}
		}
	}
return ans;
}
