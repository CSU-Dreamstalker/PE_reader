//
// Created by Dreamstalker on 2019/8/21.
//
#pragma once
//#pragma execution_character_set("GBK")
#pragma warning(disable:4996)

#ifndef PEREADER_PE_HEADERS_H
#define PEREADER_PE_HEADERS_H
#include<windows.h>
#include<iostream>
#include<fstream>
#include <sstream>
using std::stringstream;
using std::ofstream;
using std::ifstream;
using std::string;
using std::cin;
using std::cout;
using std::wcout;
using std::ios;

class PE_Headers {
private:
	string FILE_LOC;//�ļ�����
	LONG NT_OFFSET;//�����ʼ�������ж�ȡʧ�ܣ����������Ϊ0
protected:
	string temp_string;
	LONG NT_offset() const;
	const char* File_loc() const;
	const char* data2str(BYTE) const;
	const char* data2str(WORD) const;
	const char* data2str(DWORD) const;
	const char* data2str(LONG) const; 
	const char* data2str(ULONGLONG) const;
	const char* data2str(_IMAGE_DATA_DIRECTORY) const;
	const wchar_t* GetWC(const char*) const;
	explicit PE_Headers(const char*);//��ʼ�������������ӿ�
public:
	PE_Headers();
	void PE_Headers_open(const char*); //��ʼ������
};

#endif //PEREADER_PE_HEADERS_H