#pragma once
//
// Created by Dreamstalker on 2019/8/23.
//

#ifndef PEREADER_PEINFO_FILE_OUPUT_H
#define PEREADER_PEINFO_FILE_OUPUT_H
#include"DOS_Head.h"
#include"NT_Head.h"
#include"Section_Headers.h"
#include<conio.h>
class PEinfo_ouput :public DOS_Head, public NT_Head ,public Section_Headers{
private:
	explicit PEinfo_ouput(const char*);//����ӿڷ�������ֻ������ɾ����
	void NTO_info_1();
	void NTO_info_2();//��18����ҳ9����������ʾ��Ϣ
	void NTO_info_3();//����ʮ��λ����
	void SH_pages(int);//�����intҳ��������Ϣ
protected:
	void DOS_info();
	void NTFILE_info();
	void NTOPT_info();
	void SH_info();
	void init(const char*);
public:
	PEinfo_ouput();
	void main_menu();//���˵������ļ�����ʾ��Ҫ��Ϣ���л�����
};


#endif //PEREADER_PEINFO_FILE_OUPUT_H