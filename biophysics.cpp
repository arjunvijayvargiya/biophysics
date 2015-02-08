#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//stdlib for atof support function
// author:Arjun Vijayvargiya******* GHOSTID:DRAVA332****************
/*
   1)Parsing the ATOM
   2)Saving it into local files
   3)Parsing the transformation matrix
   4)saving it into local files
   5)step 3 includes saving the translate into local file
   6)calculation
   [3x3]*[3X1]=[3x1]+translation
   7)reorganisation into the final file as output
*/
int main()
{char str[80];
  int i=0;
  
	FILE *fp=fopen("pdb.txt","r");
	FILE *fn=fopen("output.txt","w");
	while(!feof(fp))
	{
		char ch=getc(fp);
		if(ch=='\n')
		{ 
		   char iter=getc(fp);
		   //printf("%c\n",iter);
		   while(iter!=' ')
		    {
		    	str[i++]=iter;
		    	iter=getc(fp);
		    }
		    str[i]='\0';
		    //printf("%s\n",str);
		    if(strcmp(str,"ATOM")==0)
		    {
		    	//printf("%s\n",str);
		      char y=getc(fp);
		      while(y!='.')
		      {
		      	   y=getc(fp);
		      }
		      while(y!=' ')
		       {
		        fseek(fp,-2L,1);
		        y=getc(fp);
			   }
			  y=getc(fp);
			  while(y!=' ')
			  {
			  	fprintf(fn,"%c",y);
			  	y=getc(fp);
			  }
			  fprintf(fn,"%c",',');
			  while(y!='.')
		      {
		      	   y=getc(fp);
		      }
		       while(y!=' ')
		       {
		        fseek(fp,-2L,1);
		        y=getc(fp);
			   }
		      y=getc(fp);
			  while(y!=' ')
			  {
			  	fprintf(fn,"%c",y);
			  	y=getc(fp);
			  }
			  fprintf(fn,"%c",',');
			  while(y!='.')
		      {
		      	   y=getc(fp);
		      }
		       while(y!=' ')
		       {
		        fseek(fp,-2L,1);
		        y=getc(fp);
			   }
		      y=getc(fp);
			  while(y!=' ')
			  {
			  	fprintf(fn,"%c",y);
			  	y=getc(fp);
			  }
			  /*fprintf(fn,"%c",',');
			  while(y!='.')
		      {
		      	   y=getc(fp);
		      }
		       while(y!=' ')
		       {
		        fseek(fp,-2L,1);
		        y=getc(fp);
			   }
		      y=getc(fp);
			  while(y!=' ')
			  {
			  	fprintf(fn,"%c",y);
			  	y=getc(fp);
			  }
			  fprintf(fn,"%c",',');
			  while(y!='.')
		      {
		      	   y=getc(fp);
		      }
		       while(y!=' ')
		       {
		        fseek(fp,-2L,1);
		        y=getc(fp);
			   }
		      y=getc(fp);
			  while(y!=' ')
			  {
			  	fprintf(fn,"%c",y);
			  	y=getc(fp);
			  }*/
			  fprintf(fn,"%c",'\n');
			}
		    i=0;
		}
	
	}
	printf("**********PDB FILE SUCCESSFULLY PARSED***********\a");
	fclose(fp);
	fclose(fn);
	FILE *fp2=fopen("pdb.txt","r");
	FILE *fp3=fopen("transformation.txt","w");
	FILE *fp7=fopen("translator.txt","w");
	while(!feof(fp2))
	{
		char ch=getc(fp);
		if(ch=='\n')
		{ 
		   char iter=getc(fp);
		   //printf("%c\n",iter);
		   while(iter!=' ')
		    {
		    	str[i++]=iter;
		    	iter=getc(fp);
		    }
		    str[i]='\0';
		    //printf("%s\n",str);
		    char number[10];
		    if(strcmp(str,"REMARK")==0)
		    {int u=0;
		     int h=0;
		        while(u<3)
		        {
		        	char ch=getc(fp2);
		            number[h++]=ch;
		            u++;
				}
				number[h]='\0';
				if(strcmp(number,"290")==0)
				{
					//printf("hey I got it\n");
					char t;
					t=getc(fp2);
					while(t==' ')
					{
						t=getc(fp2);
					}
					fseek(fp2,-1L,1);
					char symstr[10];
					int u=0;
		            int h=0;
		        while(u<5)
		        {
		        	char ch=getc(fp2);
		            symstr[h++]=ch;
		            u++;
				}
				    symstr[h]='\0';
					if(strcmp(symstr,"SMTRY")==0)
					{
						//printf("found trans\n");
						char y=getc(fp2);
		      while(y!='.')
		      {
		      	   y=getc(fp2);
		      }
		      while(y!=' ')
		       {
		        fseek(fp2,-2L,1);
		        y=getc(fp2);
			   }
			  y=getc(fp2);
			  while(y!=' ')
			  {
			  	fprintf(fp3,"%c",y);
			  	y=getc(fp2);
			  }
			  fprintf(fp3,"%c",',');
			  while(y!='.')
		      {
		      	   y=getc(fp2);
		      }
		       while(y!=' ')
		       {
		        fseek(fp2,-2L,1);
		        y=getc(fp2);
			   }
		      y=getc(fp2);
			  while(y!=' ')
			  {
			  	fprintf(fp3,"%c",y);
			  	y=getc(fp2);
			  }
			  fprintf(fp3,"%c",',');
			  while(y!='.')
		      {
		      	   y=getc(fp2);
		      }
		       while(y!=' ')
		       {
		        fseek(fp2,-2L,1);
		        y=getc(fp2);
			   }
		      y=getc(fp2);
			  while(y!=' ')
			  {
			  	fprintf(fp3,"%c",y);
			  	y=getc(fp2);
			  }
			  fprintf(fp3,"%c",',');
			  char temp[10];
			  int x=0;
			  while(y!='.')
		      {
		      	   y=getc(fp2);
		      }
		       while(y!=' ')
		       {
		        fseek(fp2,-2L,1);
		        y=getc(fp2);
			   }
		      y=getc(fp2);
			  while(y!=' ')
			  {
			  	//fprintf(fp3,"%c",y);
			  	temp[x++]=y;
				y=getc(fp2);
			  }
			  temp[x]='\0';
			  fprintf(fp7,"%s\n",temp);
			  //fprintf(fp3,"%c",'\n');
		    }
		       
					
					  
				}
			}
		    i=0;
		}
	
	}
	fclose(fp2);
	fclose(fp3);
	fclose(fp7);
	FILE *fp4=fopen("transformation.txt","r");
	double matrix[9];
	int line=0;
	int mat=0;
	char wrd[20];
	int j=0;
	while(!feof(fp4) && mat<9)
	{char ch=getc(fp4);
	
		if(ch!=',')
		{
			wrd[j++]=ch;
		}
		else
		{ wrd[j]='\0';
		  double val=atof(wrd);
		  //printf("\n%lf\n",val);
		  matrix[mat++]=val;
		  j=0;	
		}
		
	}
	fclose(fp4);
	/*for(int b=0;b<9;b++)
	  printf("\n%lf\n",matrix[b]);
	*/
	FILE *ret=fopen("translator.txt","r");
	double translate[3];
	int trans=0;
	char stx[20];
	int z=0;
	while(!feof(ret) && trans<3)
	{
		char ch=getc(fp4);
	
		if(ch!='\n')
		{
			stx[z++]=ch;
		}
		else
		{ stx[j]='\0';
		  double val=atof(stx);
		  //printf("\n%lf\n",val);
		  translate[trans++]=val;
		  j=0;	
		}	
		
	}
	fclose(ret);
	/*for(int i=0;i<3;i++)
	 printf("%lf,",translate[i]);
	*/
	//moving on to final operation 
	FILE *fin=fopen("output.txt","r");
	FILE *ftra=fopen("result.txt","w");
	double d1,d2,d3;
	double b1,b2,b3;

	while(!feof(fin))
	{	int g=0;
	    int trx=0;
		fscanf(fin,"%lf,%lf,%lf\n",&d1,&d2,&d3);
		//printf("%lf,%lf,%lf\n",d1,d2,d3);
		while(g<9)
		{double sum=0;
		 
		  b1=matrix[g];
		  b2=matrix[g+1];
		  b3=matrix[g+2];
		  sum=matrix[g]*d1+matrix[g+1]*d2+matrix[g+2]*d3+translate[trx];
		  fprintf(ftra,"%lf,",sum);
		  g=g+3;	
		  trx++;
		}
		fprintf(ftra,"%s","\n");
	}
	fclose(fin);
	fclose(ftra);
	return 0;
}
