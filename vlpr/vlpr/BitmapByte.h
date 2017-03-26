#pragma once
 using namespace std;
using namespace System;
using namespace System::Data;
using namespace System::Drawing;

Bitmap^ rgbByte2Bitmap(Byte bits_bmp[MAX_HEIGHT][MAX_WIDTH][3],int width,int height)
{
	Bitmap^ newbitmap = gcnew Bitmap(width,height); 
	for (int h = 0; h < height; h++)
		for (int w = 0; w < width ; w++)   
			newbitmap->SetPixel(w, h, Color::FromArgb(bits_bmp[h][w][0],bits_bmp[h][w][1], bits_bmp[h][w][2]));

	return newbitmap;
}
Bitmap^ grayByte2Bitmap(Byte bits_bmp[MAX_HEIGHT][MAX_WIDTH],int width,int height)
{
	Bitmap^ newbitmap = gcnew Bitmap(width,height); 
	Byte gray=0;
	for (int h = 0; h < height; h++)
		for (int w = 0; w < width ; w++)
		{
			gray=bits_bmp[h][w];
			newbitmap->SetPixel(w, h,Color::FromArgb(gray,gray,gray));
		}

	return newbitmap;
} 

void Bitmap2Byte(Bitmap^ bmp,Byte bits_bmp[MAX_HEIGHT][MAX_WIDTH][3] )
{

	memset(&bits_bmp[0][0][0],0,MAX_WIDTH*MAX_HEIGHT*3);// void *memset(void *dest,int c,size_t count ); 

	Color pixel; 
	for (int h = 0; h < bmp->Size.Height  ; h++)
		for (int w = 0; w < bmp->Size.Width ; w++)
		{							 
			pixel=bmp->GetPixel(w,h);
			bits_bmp[h][w][0]=pixel.R;
			bits_bmp[h][w][1]=pixel.G;
			bits_bmp[h][w][2]=pixel.B;

			//copy bits
			// ok // newbitmap->SetPixel(w, h,bmp->GetPixel(w, h));
			// ok //newbitmap->SetPixel(w, h, Color::FromArgb( bmp->GetPixel(w, h).R, bmp->GetPixel(w, h).G,   bmp->GetPixel(w, h).B));
			// ok // newbitmap->SetPixel(w, h, Color::FromArgb(bits_bmp_src[h][w][0],bits_bmp_src[h][w][1], bits_bmp_src[h][w][2]));
		} 
} 

void out(char* str,Byte M[MAX_HEIGHT][MAX_WIDTH],int column,int row)
{
	ofstream outfile(str); 
	int i=100;
	for(int i=0;i<=row-1;i++)
	{
		for(int j=0;j<=column-1;j++)  
		{
			// outfile<<"("<<i<<","<<j<<")"<< (int)src[i][j]<<" "; 
			outfile<<(int)M[i][j]<<" "; 		 
		} 
		outfile<<endl;
	}	

	outfile.close(); 
}
void in_f(int M[10][100][100])
{
	memset(&M[0][0][0],0,100*100*10); 
	char* str2[10]={
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\0.txt",
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\1.txt",
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\2.txt",
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\3.txt",
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\4.txt",
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\5.txt",
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\6.txt",
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\7.txt",
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\8.txt",
		"C:\\Users\\Asin\\Desktop\\car\\vlpr\\shuzi\\9.txt"};
	for (int number=0;number<=9;number++)
	{
		ifstream fin(str2[number]);
		if(fin)
		{
			int i=0;
			char c[100];
			while(fin.getline(c,100))
			{
				int j=0;
				while(c[j]>0)
				{
					if (c[j]=='1') M[number][i][j]=100;
					else M[number][i][j]=200;
					j++;
				}
				i++;
			}//while(fin.getline(c))
		}
		fin.close();
	}
	  
}