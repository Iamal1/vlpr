// vlpr.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "BitmapByte.h"
#include "Coarse.h" 
#include "segmentation.h"
#include "Form1.h" 


using namespace vlpr;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Application::Run(gcnew Form1());
	return 0;
}
