
#pragma once
using namespace std; 
using namespace System;
using namespace System::Data;
using namespace System::Drawing;

// vector<_BoundingBox> minBoundingBox;
// struct _BoundingBox{
// 	int Xmin;
// 	int Xmax;
// 	int Ymin;
// 	int Ymax;
// };


//Y=0.299*rgbRed+0.587* rgbGreen+0.114*rgbBlue
void rgb2gray(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH][3],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int width,int height)
{
	memset(&bmp_dst[0][0],0,MAX_WIDTH*MAX_HEIGHT);
	 
	for (int h = 0; h < height; h++)
		for (int w = 0; w < width ; w++) 
		{
			bmp_dst[h][w]=0.299*bmp_src[h][w][0]+0.587*bmp_src[h][w][1]+0.114*bmp_src[h][w][2];
			//bmp_dst[h][w]=(bmp_src[h][w][0]+bmp_src[h][w][1]+bmp_src[h][w][2])/3; 
		}

}

//a mathematical morphological transformation and is a non-linear filter
//has multiple functions such as restraining noises, extracting features, segmenting images
//The performance of top-hat transformation mostly depends on a square structuring element whose width is 3 pixels
void TopHat(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int column,int row)//width=column  height=row
{
	memset(&bmp_dst[0][0],0,MAX_WIDTH*MAX_HEIGHT);

	//腐蚀
	Byte min=255;;
	for (int i=1;i<=row-2;i++)
		for (int j=1;j<=column-2;j++)
		{
			min=255;
			for (int m=i-1;m<=i+1;m++)
				for (int n=j-1;n<=j+1;n++) 
				{
					if (min>bmp_src[m][n])
						min=bmp_src[m][n]; 
				}
			bmp_dst[i][j]=min; 
		}     

	//膨胀
	Byte max=0;
	for (int i=1;i<=row-2;i++)
		for (int j=1;j<=column-2;j++)
		{
			max=0;
			for (int m=i-1;m<=i+1;m++)
				for (int n=j-1;n<=j+1;n++) 
				{
					if (max<bmp_src[m][n])
						max=bmp_src[m][n]; 
				}
			bmp_dst[i][j]=max; 
		}     

	 
	for (int i=0;i<=row-1;i++) 
		for (int j=0;j<=column-1;j++) 
		{
			bmp_dst[i][j]=System::Math::Abs(bmp_src[i][j]-bmp_dst[i][j]); 

			/* pixels with value above 5 are added by 30 for demonstration			 
			if(bmp_dst[i][j]<5) bmp_dst[i][j]=0;
			else bmp_dst[i][j]+=30;
			//*/
		}

}


// the Sobel filter is used to get vertical edges 
void Soble(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int column,int row)//width=column  height=row
{
	memset(&bmp_dst[0][0],0,MAX_WIDTH*MAX_HEIGHT);

	int k=0;
	//int temp=0,Soble_Y[9]={-1,-2,-1,0,0,0,1,2,1};//Byte temp=0,Soble_Y[9]={1,2,1,0,0,0,-1,-2,-1,};
	int temp=0,Soble_X[3][3]={-1,0,1,-2,0,2,-1,0,1};//X==column
	for (int i=1;i<=row-2;i++)
		for (int j=1;j<=column-2;j++)
		{
			k=0,temp=0; 
			for (int m=0;m<3;m++)  
				for (int n=0;n<3;n++)   
					temp+=Soble_X[m][n]*bmp_src[m+i-1][n+j-1]; 
			
			if (temp>255)
				temp=255;
			else if (temp<0)
				temp=0; 
			bmp_dst[i][j]=temp;//System::Math::Abs(temp); 
		}
}


// A binary method with a global threshold 	cannot generate satisfactory results 
// because the brightness distribution of a LP may vary due to lighting environment
// the adaptive local binary method is applied
Byte Otsu(Byte bmp[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{
	float N=column*row;
	float cumulate=0,pixel=0;

	float histogram_pixel[256]={0};
	float histogram_w[256]={0};
	float histogram_u[256]={0};

	for(int i=0;i<=row-1;i++)
		for(int j=0;j<=column-1;j++) 
			histogram_pixel[bmp[i][j]]++; 


	float w0=0,u0,u=0,g=0,gmax=0;	
	for(int i=0;i<=255;i++) 
	{
		pixel=histogram_pixel[i]/N;		//此数值的像素数的比例
		u+=pixel*i;
		cumulate+=pixel;

		histogram_w[i]=cumulate;		//小于等于此数值的像素的 累积比例
		histogram_u[i]=u/cumulate;		//小于等于此数值的像素的 灰度均值
	}

	int threshold=0;
	for(int i=0;i<=255;i++)
	{  
		g=0;
		w0=histogram_w[i];
		u0=histogram_u[i];

		g=(w0*(u-u0)*(u-u0))/(1.0-w0);
		if(g>gmax)
		{
			gmax=g;
			threshold=i;
		}		
	}
	return (Byte)threshold;
}


void OtsuBinarization(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],int column,int row)//width=column  height=row
{
	Byte threshold=Otsu(bmp_src,column,row);

	for(int i=0;i<=row-1;i++)
		for(int j=0;j<=column-1;j++)  
		{
			if (bmp_src[i][j]<threshold) 
				bmp_src[i][j]=0;
			else
				bmp_src[i][j]=255; 
		}
}

int max_4(int a,int b,int c,int d)
{
	if(a<b) a=b;
	if(c<d) c=d;
	if(a<c) a=c;
	return a;

}
int max_6(int a,int b,int c,int d,int e,int f)
{
	if(a<b) a=b;
	if(c<d) c=d;
	if(a<c) a=c;
	if(e<f) e=f;
	if(a<e) a=e;
	return a;
}

//if the edge point has a very long (background curve) or very short (noise edge) actual edge length, then the edge point will be removed
void CurveNoiseRemove(Byte E[MAX_HEIGHT][MAX_WIDTH],Byte M[MAX_HEIGHT][MAX_WIDTH],Byte N[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{
	memset(&M[0][0],0,MAX_WIDTH*MAX_HEIGHT);
	memset(&N[0][0],0,MAX_WIDTH*MAX_HEIGHT);

	//伪二值
	for(int i=0;i<=row-1;i++)
		for(int j=0;j<=column-1;j++)  
		{
			if (E[i][j]==255) 
				E[i][j]=1;
			else
				E[i][j]=0; 
		}
		 

	// the first scan will record the edge lengths away from the top (or left) start points
	for(int i=2;i<=row-3;i++)
		for(int j=2;j<=column-3;j++) 
			if (E[i][j]==1)
			{
				if (E[i-1][j-1]+E[i-1][j]+E[i-1][j+1]+E[i][j-1]>0) 
					M[i][j]=max_4(M[i-1][j-1],M[i-1][j],M[i-1][j+1],M[i][j-1])+1;
				else   
					M[i][j]=max_6(M[i-2][j-1],M[i-2][j],M[i-2][j+1],M[i-1][j-2],M[i-1][j+2],M[i][j-2])+1;
			}
			 
	// the second scan will record the edge lengths away from the bottom (or right)	end points
	for(int i=row-3;i>=2;i--)
		for(int j=column-3;j>=2;j--) 
			if (E[i][j]==1)
			{
				if (E[i+1][j-1]+E[i+1][j]+E[i+1][j+1]+E[i][j+1]>0) 
					N[i][j]=max_4(N[i+1][j-1],N[i+1][j],N[i+1][j+1],N[i][j+1])+1;
				else   
					N[i][j]=max_6(N[i+2][j-1],N[i+2][j],N[i+2][j+1],N[i+1][j-2],N[i+1][j+2],N[i][j+2])+1;
			}	
	
	// the last scan will add up the two kinds of lengths to denote the actual edge lengths
	for(int i=0;i<=row-1;i++)
		for(int j=0;j<=column-1;j++)
			if (E[i][j]==1)
			{
				if (M[i][j]+N[i][j]>row/6 || M[i][j]+N[i][j]<row/20)
					E[i][j]=0;
				else
					E[i][j]=255;
			}
}

//applied to connect text pixels into plate regions
void CloseOp(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{
	memset(&bmp_dst[0][0],0,MAX_WIDTH*MAX_HEIGHT);

	for(int i=0;i<=row-1;i++)
		for(int j=0;j<=column-1;j++) 
		{
			if (bmp_src[i][j]==0)
				bmp_src[i][j]=255;
			else
				bmp_src[i][j]=0;
		}

	Byte max=0;
	for (int i=1;i<=row-2;i++)
		for (int j=1;j<=column-2;j++)
		{
			max=0;
			for (int m=i-1;m<=i+1;m++)
				for (int n=j-1;n<=j+1;n++) 
				{
					if (max<bmp_src[m][n])
						max=bmp_src[m][n]; 
				}
				bmp_dst[i][j]=max; 
		}

	Byte min=255;;
	for (int i=1;i<=row-2;i++)
		for (int j=1;j<=column-2;j++)
		{
			min=255;
			for (int m=i-1;m<=i+1;m++)
				for (int n=j-1;n<=j+1;n++) 
				{
					if (min>bmp_src[m][n])
						min=bmp_src[m][n]; 
				}
				bmp_dst[i][j]=min; 
		}

		{
			int y_row[4]={0,1,row-2,row-1};
			int x_column[4]={0,1,column-2,column-1}; 

			for(int i=0;i<=3;i++)
				for(int j=0;j<=column-1;j++)
					bmp_src[y_row[i]][j]=255;
			for(int i=0;i<=row-1;i++)
				for(int j=0;j<=3;j++)
					bmp_src[i][x_column[j]]=255; 
		}  

}



void Fill(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{
	memset(&bmp_dst[0][0],255,MAX_WIDTH*MAX_HEIGHT);

	for(int i=3;i<=row-4;i++)
		for(int j=3;j<=column-4;j++) 
		{
			if (bmp_src[i][j]==0)
			{
				for (int m=i-1;m<=i+1;m++)
					if (m>=0 && m<=row-1)
						for (int n=j-4;n<=j+5;n++) 
							if (n>=0 && n<=column-1)
								bmp_dst[m][n]=0; 
			}
		}
		{
			int y_row[4]={0,1,row-2,row-1};
			for(int i=0;i<=3;i++)
				for(int j=0;j<=column-1;j++)
					bmp_src[y_row[i]][j]=255;

			int x_column[4]={0,1,column-2,column-1}; 
			for(int i=0;i<=row-1;i++)
				for(int j=0;j<=3;j++)
					bmp_src[i][x_column[j]]=255; 
		}  
}

void Contours(Byte bmp_src[MAX_HEIGHT][MAX_WIDTH],Byte bmp_dst[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{
	memset(&bmp_dst[0][0],255,MAX_WIDTH*MAX_HEIGHT); 

	for(int i=1;i<=row-2;i++)
		for(int j=1;j<=column-2;j++) 
			if (bmp_src[i-1][j]!=bmp_src[i+1][j] || bmp_src[i][j-1]!=bmp_src[i][j+1]) 
				bmp_dst[i][j]=0;
}

int BoundingColor(Byte E[MAX_HEIGHT][MAX_WIDTH],Byte M[MAX_HEIGHT][MAX_WIDTH],int column,int row,int minBox[100][5])
{  
	memset(&M[0][0],255,MAX_WIDTH*MAX_HEIGHT); 
	int boxID=0,locColor=0,locNeighbor[10000][2]={0};
	const int locN8[8][2]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};

	int locHead=0,locArea=1;
	int m=0,n=0,km=0,kn=0;
	int minX=0,minY=0,maxX=0,maxY=0;

	for(int i=1;i<=row-2;i++)
		for(int j=1;j<=column-2;j++) 
		{
			if (E[i][j]==0 && M[i][j]==255)
			{ 
				locColor+=20;
				if (locColor>200) locColor=0;

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

					M[km][kn]=locColor;
					locHead++; 
					for (int locN=0;locN<=7;locN++)
					{
						m=km+locN8[locN][0];
						n=kn+locN8[locN][1];
						if (m>=0 && m<=row-1 && n>=0 && n<=column-1)
							if (E[m][n]==0 && M[m][n]==255)
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

				if (lenX>60 && lenX<150 && lenY>10 &&lenY<50 && locArea>800 && locArea<5000 && (locArea*1.0)/lenArea>0.5)
				{

				// box  
					minBox[boxID][0]=minX;
					minBox[boxID][1]=maxX;
					minBox[boxID][2]=minY;
					minBox[boxID][3]=maxY; 
					boxID++;
				} 
			}
		}
		return boxID;
	//	out("C:\\Users\\Asin\\Desktop\\car_test\\a.txt",M,column,row);
}

void BoundingBox(Byte E[MAX_HEIGHT][MAX_WIDTH][3],Byte M[MAX_HEIGHT][MAX_WIDTH][3],Byte N[MAX_HEIGHT][MAX_WIDTH][3],int minBox[100][5],int boxNum,int* w,int* h)
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