
#pragma once
using namespace std; 
using namespace System;
using namespace System::Data;
using namespace System::Drawing;


void seg_sort(int boxNum,int minBoundingBox[100][5])
{
	//Xmin Xmax Ymin Ymax Number
	for (int i=0;i<=boxNum-2;i++)
	{
		int min_id=i;
		for (int j=i+1;j<=boxNum-1;j++)
		{
			if (minBoundingBox[j][0]<minBoundingBox[min_id][0])
			{
				min_id=j;
			}
		}
		if (min_id!=i)
		{
			int Xmin, Xmax, Ymin, Ymax, Number;

			Xmin=minBoundingBox[min_id][0];
			Xmax=minBoundingBox[min_id][1];
			Ymin=minBoundingBox[min_id][2];
			Ymax=minBoundingBox[min_id][3];
			Number=minBoundingBox[min_id][4];
			
			minBoundingBox[min_id][0]=minBoundingBox[i][0];
			minBoundingBox[min_id][1]=minBoundingBox[i][1];
			minBoundingBox[min_id][2]=minBoundingBox[i][2];
			minBoundingBox[min_id][3]=minBoundingBox[i][3];
			minBoundingBox[min_id][4]=minBoundingBox[i][4];

			minBoundingBox[i][0]=Xmin;
			minBoundingBox[i][1]=Xmax;
			minBoundingBox[i][2]=Ymin;
			minBoundingBox[i][3]=Ymax;
			minBoundingBox[i][4]=Number; 
		}

	}
} 
void seg_RGB(Byte M[MAX_HEIGHT][MAX_WIDTH][3],Byte N[MAX_HEIGHT][MAX_WIDTH][3],int boxNum,int minBoundingBox[100][5])
{


	memset(&N[0][0][0],0,MAX_HEIGHT*MAX_WIDTH*3);

	//Xmin Xmax Ymin Ymax Number
	for (int k=0;k<=boxNum-1;k++)
	{
		for(int i=minBoundingBox[k][2];i<=minBoundingBox[k][3];i++)
			for(int j=minBoundingBox[k][0];j<=minBoundingBox[k][1];j++) 
			{
				N[i][j][0]=M[i][j][0];
				N[i][j][1]=M[i][j][1];
				N[i][j][2]=M[i][j][2];

			}

	}
}

void bmp_feature(int E[100][100],int column,int row,double X[120],double Y[240])
{

	memset(&X[0],0,120); 
	memset(&Y[0],0,240); 
	int count=0,temp=0;
	double E_x[100]={0},E_y[100]={0};
	if(row<=0 || column <=0) return;

	for (int i=0;i<=row-1;i++) 
		for (int j=0;j<=column-1;j++)  
			if (E[i][j]==100)
			{
				count++;
				E_y[i]++;
				E_x[j]++;
			} 

	temp=240/row;
	if (temp*row<240) temp++;

	for (int i=0;i<=row-1;i++)
	{
		E_y[i]/=(1.0*count);
		for (int j=0;j<temp;j++)
			if (i*temp+j<240) Y[i*temp+j]=E_y[i];
	}

	temp=120/column;
	if (temp*column<120) temp++;

	for (int j=0;j<=column-1;j++) 
	{

		E_x[j]/=(1.0*count);
		for (int i=0;i<temp;i++)
			if (j*temp+i<120) X[j*temp+i]=E_x[j];
	}
}



void number_feature(int E[10][100][100],double X[10][120],double Y[10][240])
{
	memset(&X[0][0],0,120*10); 
	memset(&Y[0][0],0,240*10); 

	for (int number=0;number<=9;number++)
	{
		int row=0,column=0,count=0,temp=0;
		double E_x[100]={0},E_y[100]={0};
		while(E[number][0][column]) column++;
		while(E[number][row][0]) row++;
		if(row<=0 || column <=0) continue;

		for (int i=0;i<=row-1;i++) 
			for (int j=0;j<=column-1;j++)  
				if (E[number][i][j]==100)
				{
					count++;
					E_y[i]++;
					E_x[j]++;
				}
				 
		temp=240/row;
		if (temp*row<240) temp++;

		for (int i=0;i<=row-1;i++)
		{
			E_y[i]/=(1.0*count);
			for (int j=0;j<temp;j++)
				if (i*temp+j<240) Y[number][i*temp+j]=E_y[i];
		}

		temp=120/column;
		if (temp*column<120) temp++;

		for (int j=0;j<=column-1;j++) 
		{
			E_x[j]/=(1.0*count);
			for (int i=0;i<temp;i++)
				if (j*temp+i<120) X[number][j*temp+i]=E_x[j];
		}
	}


}


int seg_Number(Byte E[MAX_HEIGHT][MAX_WIDTH],Byte M[MAX_HEIGHT][MAX_WIDTH],int column,int row,int minBox[100][5],double number_feature_X[10][120],double number_feature_Y[10][240])
{  
	memset(&M[0][0],0,MAX_WIDTH*MAX_HEIGHT); 
	int boxID=0,locNeighbor[10000][2]={0};
	const int locN8[8][2]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};

	int locHead=0,locArea=1;
	int m=0,n=0,km=0,kn=0;
	int minX=0,minY=0,maxX=0,maxY=0;
	 
	for (int i=0;i<row-1;i++)
		for (int j=0;j<column-1;j++)
		{
			if (E[i][j]==255 && M[i][j]==0)
			{  
				locNeighbor[0][0]=i;
				locNeighbor[0][1]=j;
				locHead=0;
				locArea=1;

				minX=j;
				minY=i;
				maxX=j;
				maxY=i;

				while(locArea-locHead>0)
				{
					km=locNeighbor[locHead][0];
					if (minY>km) minY=km;
					if (maxY<km) maxY=km;

					kn=locNeighbor[locHead][1];
					if (minX>kn) minX=kn;
					if (maxX<kn) maxX=kn;

					M[km][kn]=100;
					locHead++; 
					for (int locN=0;locN<=7;locN++)
					{
						m=km+locN8[locN][0];
						n=kn+locN8[locN][1];
						if (m>=0 && m<=row-1 && n>=0 && n<=column-1)
							if (E[m][n]==255 && M[m][n]==0)
							{
								M[m][n]=254;
								locNeighbor[locArea][0]=m;
								locNeighbor[locArea][1]=n;
								locArea++;
							}
					} 
				} 
				int lenX=maxX-minX,lenY=maxY-minY;
				int lenArea=lenX*lenY;

				if (lenX>column/30 && lenX<column/7 &&  (1.0*lenX)/(1.0*lenY)>0.4 && (1.0*lenX)/(1.0*lenY)<0.7  && (locArea*1.0)/lenArea>0.3 && (locArea*1.0)/lenArea<0.75)
				{

					// box  
					minBox[boxID][0]=minX;
					minBox[boxID][1]=maxX;
					minBox[boxID][2]=minY;
					minBox[boxID][3]=maxY;				

					//void bmp_feature(int E[100][100],int column,int row,int X[120],int Y[240])
					int bmp_M[100][100]={0};
					double feature_X[100]={0},feature_Y[100]={0};
					int iim=0,jjn=0;
					for (int iii=minY;iii<=maxY;iii++,iim++)
					{
						jjn=0;
						for (int jjj=minX;jjj<=maxX;jjj++,jjn++)
						{
							if (M[iii][jjj])
								bmp_M[iim][jjn]=100; 
							else
								bmp_M[iim][jjn]=200;
						}
					}
					bmp_feature(bmp_M,jjn,iim,feature_X,feature_Y);

					double min=999999999;
					int id=0;
					for (int number=0;number<=9;number++)
					{
						double tempX=0,tempY=0;;
						for (int iii=0;iii<=240-1;iii++)
							tempY+= (feature_Y[iii]-number_feature_Y[number][iii])*(feature_Y[iii]-number_feature_Y[number][iii]);
						for (int jjj=0;jjj<=120-1;jjj++) 
							tempX+=(feature_X[jjj]-number_feature_X[number][jjj])*(feature_X[jjj]-number_feature_X[number][jjj]); 
						 
							if (tempX*tempY<min)
							{
								min=tempX*tempY;
								id=number;
							}

					}
					minBox[boxID][4]=id;

					for (int iii=minY;iii<=maxY;iii++)
					{
						M[iii][minX]=255;
						M[iii][maxX]=255;
					}

					for (int jjj=minX;jjj<=maxX;jjj++)
					{
						M[minY][jjj]=255;
						M[maxY][jjj]=255;
					}
					boxID++;
					
					/*
					ofstream outfile("C:\\Users\\Asin\\Desktop\\a.txt");  
					for (int iii=minY;iii<=maxY;iii++)
					{
						for (int jjj=minX;jjj<=maxX;jjj++)
						{
							if (M[iii][jjj])
								outfile<<"1"; 
							else
								outfile<<"0";  	 
						} 
						outfile<<endl;
					}	
					outfile.close();  
					*/
				} 
					//return boxID;
			}
		}
		return boxID;
		//	out("C:\\Users\\Asin\\Desktop\\car_test\\a.txt",M,column,row);
}



void seg_BoundingBox(Byte E[MAX_HEIGHT][MAX_WIDTH][3],Byte M[MAX_HEIGHT][MAX_WIDTH][3],Byte N[MAX_HEIGHT][MAX_WIDTH][3],int minBox[100][4],int boxNum,int* w,int* h)
{
	memset(&M[0][0][0],255,MAX_WIDTH*MAX_HEIGHT*3); 

	for (int k=0;k<boxNum;k++)
	{
		int i2=0,j2=0;
		for(int i=minBox[k][2];i<=minBox[k][3];i++,i2++)
		{
			j2=0;
			for(int j=minBox[k][0];j<=minBox[k][1];j++,j2++)
			{
				M[i][j][0]=E[i][j][0];
				M[i][j][1]=E[i][j][1];
				M[i][j][2]=E[i][j][2];

				N[i2][j2][0]=E[i][j][0];
				N[i2][j2][1]=E[i][j][1];
				N[i2][j2][2]=E[i][j][2];
			}
		}
		*w=j2;
		*h=i2;
	}
}


void Segmentation(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{

		for (int i=0;i<=row-1;i++)
			for (int j=0;j<=column-1;j++)
				if (bmp_src[i][j]==0) bmp_src[i][j]=255;
				else bmp_src[i][j]=0;
}




int BlackPixelCount(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{
	int k=0;
	int row_min=row/4,row_max=(row*3)/4;
	int column_min=column/4,column_max=(column*3)/4;

	for (int i=row_min;i<=row_max;i++)
		for (int j=column_min;j<=column_max;j++) 
			if (bmp_src[i][j]==0) k++;

	return k;
}

void Plate(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{ 
	if ((4.0*BlackPixelCount(bmp_src,column,row))/(1.0*column*row)<0.4)
		for (int i=0;i<=row-1;i++)
			for (int j=0;j<=column-1;j++)
				if (bmp_src[i][j]==0) bmp_src[i][j]=255;
				else bmp_src[i][j]=0;
}

 // bgs_img = filter2(fspecial('average',2),二值化(直方图均衡化(灰度化),0.8));
void HistogramEqualization(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH][3],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH][3],int column,int row)
{ 
	memset(&bmp_dst[0][0][0],0,MAX_WIDTH*MAX_HEIGHT*3);

	//进行像素灰度统计; 统计各灰度数目，共256个灰度级  
	int i_count_Pixel[256][3]={0};
	for (int i=0;i<=row-1;i++)
		for (int j=0;j<=column-1;j++)
		{
			i_count_Pixel[bmp_src[i][j][0]][0]++; 
			i_count_Pixel[bmp_src[i][j][1]][1]++; 
			i_count_Pixel[bmp_src[i][j][2]][2]++; 
		}

	//计算灰度分布密度  
	float f_count_Pixel[256][3]={0}; 
	for (int i=0;i<=255;i++) 
	{
		f_count_Pixel[i][0]=i_count_Pixel[i][0]/(1.0*column*row);
		f_count_Pixel[i][1]=i_count_Pixel[i][1]/(1.0*column*row);
		f_count_Pixel[i][2]=i_count_Pixel[i][2]/(1.0*column*row);
	}


	//计算累计直方图分布  
	float f_cumulate_Pixel[256][3]={0},cumulate[3]={0};  
	for (int i=0;i<=255;i++) 
	{
		cumulate[0]+=f_count_Pixel[i][0];
		f_cumulate_Pixel[i][0]=255.0*cumulate[0];
		cumulate[1]+=f_count_Pixel[i][1];
		f_cumulate_Pixel[i][1]=255.0*cumulate[1];
		cumulate[2]+=f_count_Pixel[i][2];
		f_cumulate_Pixel[i][2]=255.0*cumulate[2];
	}

	for (int i=0;i<=row-1;i++)
		for (int j=0;j<=column-1;j++)
		{
			bmp_dst[i][j][0]=(Byte)f_cumulate_Pixel[bmp_src[i][j][0]][0];
			bmp_dst[i][j][1]=(Byte)f_cumulate_Pixel[bmp_src[i][j][1]][1];
			bmp_dst[i][j][2]=(Byte)f_cumulate_Pixel[bmp_src[i][j][2]][2];
		}

}

void HistogramEqualization(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{ 
	memset(&bmp_dst[0][0],0,MAX_WIDTH*MAX_HEIGHT);

	//进行像素灰度统计; 统计各灰度数目，共256个灰度级  
	int i_count_Pixel[256]={0};
	for (int i=0;i<=row-1;i++)
		for (int j=0;j<=column-1;j++)
			i_count_Pixel[bmp_src[i][j]]++; 

	//计算灰度分布密度  
	float f_count_Pixel[256]={0}; 
	for (int i=0;i<=255;i++) 
		f_count_Pixel[i]=i_count_Pixel[i]/(1.0*column*row);


	//计算累计直方图分布  
	float f_cumulate_Pixel[256]={0},cumulate=0;  
	for (int i=0;i<=255;i++) 
	{
		cumulate+=f_count_Pixel[i];
		f_cumulate_Pixel[i]=255.0*cumulate;
	}

	for (int i=0;i<=row-1;i++)
		for (int j=0;j<=column-1;j++)
			bmp_dst[i][j]=(Byte)f_cumulate_Pixel[bmp_src[i][j]];
	 
}

void setPoint(Byte bmp_rgb[MAX_HEIGHT][MAX_WIDTH][3],int x,int y)
{
	if (x>=0 && y>=0)
	{
		bmp_rgb[y][x][0]=255;
		bmp_rgb[y][x][1]=0;
		bmp_rgb[y][x][2]=0;

	} 
}

void kTan(Byte bmp_gray[MAX_HEIGHT][MAX_WIDTH],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{

	memset(&bmp_dst[0][0],0,MAX_WIDTH*MAX_HEIGHT);

	int columnMeans[MAX_PLATE_WIDTH][2]={0};
	for (int i=0;i<row-1;i++)
		for (int j=0;j<=column-1;j++)
			if (bmp_gray[i][j]>30)
			{
				columnMeans[j][0]+=i;
				columnMeans[j][1]++;
			}

	for (int j=0;j<=column-1;j++)
	{
		if (columnMeans[j][1]<10)
			columnMeans[j][0]=0;
		else
			columnMeans[j][0]/=columnMeans[j][1];

		if (columnMeans[j][0])
			bmp_dst[columnMeans[j][0]][j]=255;
	}

	int count=0;
	double sigma_x=0,sigma_y=0,sigma_xx=0,sigma_xy=0;
	for (int j=0;j<=column-1;j++)   // j==x  columnMeans[j][0]==y
		if (columnMeans[j][0])
		{
			count++;
			sigma_x+=j;
			sigma_xx+=j*j;
			sigma_x+=columnMeans[j][0];
			sigma_xy+=columnMeans[j][0];
		}
	double k=(sigma_xy*count-sigma_x*sigma_y)/(sigma_xx*count-sigma_x*sigma_x);





}

 
void PCA(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int column,int row0)
{
	int coords[2][MAX_PLATE_HEIGHT*MAX_PLATE_WIDTH]={0};
	int coords_count=0;


	for (int i=0;i<=row0-1;i++) 
		for (int j=0;j<=column-1;j++) 
		{
			if(bmp_src[i][j]>50)
				coords_count=coords_count+1;
			coords[0][coords_count]=j;
			coords[1][coords_count]=i;

		}

		double data[MAX_PLATE_HEIGHT*MAX_PLATE_WIDTH] = {0};

		for (int i=0;i<=1;i++) 
			for (int j=0;j<=coords_count-1;j++) 
			{
				data[i*coords_count+j]=(double)coords[i][j] ; 
			}
			int   row=2,col = coords_count;
			double signals[2*MAX_PLATE_HEIGHT*MAX_PLATE_WIDTH], PC[2*2], V[2];
			int x, y;

			//pca2( data, 2, col, signals, PC, V );

			printf( "Project to Principal Component: \n" );

			for ( x = 0; x < col; x++ )
			{
				printf( "%7.4f ", signals[y*col+x] );

				bmp_dst[int(signals[col+x])][int(signals[x])]=255;
			} 
			printf( "Eigen Values (in deceasing order): \n" );
			for ( y = 0; y < row; y++ )
				printf( "%7.4f ", V[y] );
			printf( "\n" );
			printf( "Eigen Vectors: \n" );
			for ( y = 0; y < row; y++ )
			{
				for ( x = 0; x < row; x++ )
				{
					printf( "%7.4f ", PC[y*row+x] );
				}
				printf( "\n" );
			} 
} 