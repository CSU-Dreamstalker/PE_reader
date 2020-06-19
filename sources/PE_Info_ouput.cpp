//
// Created by Dreamstalker on 2019/8/23.
//

#include "PE_Info_ouput.h"
PEinfo_ouput::PEinfo_ouput() {
	return;
}
PEinfo_ouput::PEinfo_ouput(const char* str) {
	this->init(str);
	return;
}
void PEinfo_ouput::init(const char* str) {
	this->PE_Headers_open(str);
	this->DOS_Head_open(str);
	this->NT_Head_open(str);
	this->SH_init(str);
	return;
}

void PEinfo_ouput::DOS_info() {
	system("cls");
	if (!this->NT_offset()) {
		cout << "can not open the file!";
		exit(-1);
	}
	cout << "name\t\tmeaning\t\t\t\t\tvalue\n\n";
	cout << "e_magic\t\tMagic number��MZ��\t\t\t" <<e_magic()<< '\n';
	cout << "e_cblp\t\tBytes on last page of file\t\t" << e_cblp() << '\n';
	cout << "e_cp\t\tPages in file\t\t\t\t" << e_cp() << '\n';
	cout << "e_crlc\t\tRelocations\t\t\t\t" << e_crlc() << '\n';
	cout << "e_cparhdr\tSize of header in paragraphs\t\t" << e_cparhdr() << '\n';
	cout << "e_minalloc\tMinimum extra paragraphs needed\t\t" << e_minalloc() << '\n';
	cout << "e_maxalloc\tMaximum extra paragraphs needed\t\t" << e_maxalloc() << '\n';
	cout << "e_ss\t\tInitial(relative)SS value\t\t" << e_ss() << '\n';
	cout << "e_sp\t\tInitial SP value\t\t\t" << e_sp() << '\n';
	cout << "e_csum\t\tChecksum\t\t\t\t" << e_csum() << '\n';
	cout << "e_ip\t\tInitial IP value\t\t\t" << e_ip() << '\n';
	cout << "e_cs\t\tInitial(relative)CS value\t\t" << e_cs() << '\n';
	cout << "e_lfarlc\tFile address of relocation table\t" << e_lfarlc() << '\n';
	cout << "e_ovno\t\tOverlay number\t\t\t\t" << e_ovno() << '\n';
	cout << "e_res[4]\tReserved words\t\t\t\t" << e_res() << '\n';
	cout << "e_oemid\t\tOEM identifier (for e_oeminfo)\t\t" << e_oemid() << '\n';
	cout << "e_oeminfo\tOEM information; e_oemid specific\t" << e_oeminfo() << '\n';
	cout << "e_res2[10]\tReserved words\t\t\t\t" << e_res2() << '\n';
	cout << "e_lfanew\tFile address of new exe header\t\t" << e_lfanew() << '\n';
	cout << "\n��ESC������һ���˵�";
	cout << "\nWaitng ketboard input...";
	for (int a = 0; a != 27;)a = getch();
	return;
}

void PEinfo_ouput::NTFILE_info() {
	system("cls");
	if (!this->NT_offset()) {
		cout << "can not open the file!";
		exit(-1);
	}
	cout << "name\t\t\tmeaning\t\t\t\tvalue\n\n";
	cout << "Signature\t\tNTͷǩ��\t\t\t" << NT_Signature() << '\n';
	cout << "Machine\t\t\t�ļ�����ƽ̨\t\t\t" << NTF_Machine() << '\n';
	cout << "NumberOfSections\t��������\t\t\t" << NTF_NumberOfSections() << '\n';
	cout << "TimeDateStamp\t\t�ļ�����ʱ��\t\t\t" << NTF_TimeDateStamp() << '\n';
	cout << "PointerToSymbolTable\t���ű�ƫ��\t\t\t" << NTF_PointerToSymbolTable() << '\n';
	cout << "NumberOfSymbols\t\t���Ÿ���\t\t\t" << NTF_NumberOfSymbols() << '\n';
	cout << "SizeOfOptionalHeader\t��չͷ��С\t\t\t" << NTF_SizeOfOptionalHeader() << '\n';
	cout << "Characteristics\t\tPE�ļ�����\t\t\t" << NTF_Characteristics() << '\n';
	cout << "\n��ESC������һ���˵�";
	cout << "\nWaitng ketboard input...";
	for (int a = 0; a != 27;)a = getch();
	return;
}

void PEinfo_ouput::NTOPT_info() {
	system("cls");
	if (!this->NT_offset()) {
		cout << "can not open the file!";
		exit(-1);
	}
	int a = '1';
	while (1) {
	switch_loop:
		switch (a) {
		case '1':this->NTO_info_1(); a = 0; break;
		case '2':this->NTO_info_2(); a = 0; break;
		case '3':this->NTO_info_3(); a = 0; break;
		case 27:return;
		default:a = getch(); goto switch_loop;//�Ҳ�֪��զ���ģ�switch����default��Ȼ���˳�switch
		}
		cout << "\n\n�����鿴��ϸ��Ϣ:\n1:��һҳ\n2:�ڶ�ҳ\n3:����ҳ\nESC:������һ���˵�\n\nWaitng ketboard input...";
	}
}

void PEinfo_ouput::NTO_info_1() {
	system("cls");
	cout << "name\t\t\t\tmeaning\t\t\t\t\tvalue\n\n";

	cout << "Magic\t\t\t\t�ļ����Ա�־��\t\t\t\t" << NTOPT_Magic() << '\n';
	cout << "MajorLinkerVersion\t\t���ӳ�������汾��\t\t\t" << NTOPT_MajorLinkerVersion() << '\n';
	cout << "MinorLinkerVersion\t\t���ӳ���Ĵΰ汾��\t\t\t" << NTOPT_MinorLinkerVersion() << '\n';
	cout << "SizeOfCode\t\t\t���к�����Ľڵ��ܴ�С\t\t\t" << NTOPT_SizeOfCode() << '\n';
	cout << "SizeOfInitializedData\t\t���к��ѳ�ʼ�����ݵĽڵ��ܴ�С\t\t" << NTOPT_SizeOfInitializedData() << '\n';
	cout << "SizeOfUninitializedData\t\t���к�δ��ʼ�����ݵĽڵĴ�С\t\t" << NTOPT_SizeOfUninitializedData() << '\n';
	cout << "AddressOfEntryPoint\t\t����ִ�����RVA\t\t\t\t" << NTOPT_AddressOfEntryPoint() << '\n';
	cout << "BaseOfCode\t\t\t�����������ʼRVA\t\t\t" << NTOPT_BaseOfCode() << '\n';

	if (if32())cout << "BaseOfData\t\t\t�����������ʼRVA\t\t\t" << NTOPT_BaseOfData() << '\n';
	else cout << "BaseOfData\t\t\t�����������ʼRVA\t\t\t" << NTOPT_BaseOfData() << '\n';

	cout << "ImageBase\t\t\t�������ѡװ�ص�ַ\t\t\t" << NTOPT_ImageBase() << '\n';
	cout << "SectionAlignment\t\t�ڴ��е�����Ķ����С\t\t\t" << NTOPT_SectionAlignment() << '\n';
	cout << "FileAlignment\t\t\t�ļ��е�����Ķ����С\t\t\t" << NTOPT_FileAlignment() << '\n';
	cout << "MajorOperatingSystemVersion\tҪ�����ϵͳ��Ͱ汾�ŵ����汾��\t" << NTOPT_MajorOperatingSystemVersion() << '\n';
	cout << "MinorOperatingSystemVersion\tҪ�����ϵͳ��Ͱ汾�ŵĸ��汾��\t" << NTOPT_MinorOperatingSystemVersion() << '\n';
	return;
}

void PEinfo_ouput::NTO_info_2() {
	system("cls");
	cout << "name\t\t\t\tmeaning\t\t\t\t\tvalue\n\n";

	cout << "MajorImageVersion\t\t�������ڲ���ϵͳ�����汾��\t\t" << NTOPT_MajorImageVersion() << '\n';
	cout << "MinorImageVersion\t\t�������ڲ���ϵͳ�Ĵΰ汾��\t\t" << NTOPT_MinorImageVersion() << '\n';
	cout << "MajorSubsystemVersion\t\tҪ�������ϵͳ�汾�����汾��\t\t" << NTOPT_MajorSubsystemVersion() << '\n';
	cout << "MinorSubsystemVersion\t\tҪ�������ϵͳ�汾�Ĵΰ汾��\t\t" << NTOPT_MinorSubsystemVersion() << '\n';
	cout << "Win32VersionValue\t\tĪ�����ֶΣ������������õĻ�һ��Ϊ0\t" << NTOPT_Win32VersionValue() << '\n';
	cout << "SizeOfImage\t\t\tӳ��װ���ڴ����ܳߴ�\t\t\t" << NTOPT_SizeOfImage() << '\n';
	cout << "SizeOfHeaders\t\t\t����ͷ+�����ĳߴ��С\t\t\t" << NTOPT_SizeOfHeaders() << '\n';
	cout << "CheckSum\t\t\tӳ���У���\t\t\t\t" << NTOPT_CheckSum() << '\n';
	cout << "Subsystem\t\t\t��ִ���ļ���������ϵͳ\t\t\t" << NTOPT_Subsystem() << '\n';
	cout << "DllCharacteristics\t\tDllMain()������ʱ������,Ĭ��Ϊ0\t\t" << NTOPT_DllCharacteristics() << '\n';
	cout << "SizeOfStackReserve\t\t��ʼ��ʱ��ջ��С\t\t\t" << NTOPT_SizeOfStackReserve() << '\n';
	cout << "SizeOfStackCommit\t\t��ʼ��ʱʵ���ύ��ջ��С\t\t" << NTOPT_SizeOfStackCommit() << '\n';
	cout << "SizeOfHeapReserve\t\t��ʼ��ʱ�����ĶѴ�С\t\t\t" << NTOPT_SizeOfHeapReserve() << '\n';
	cout << "SizeOfHeapCommit\t\t��ʼ��ʱʵ���ύ�ĶѴ�С\t\t" << NTOPT_SizeOfHeapCommit() << '\n';
	cout << "LoaderFlags\t\t\t������й�,Ĭ��Ϊ0\t\t\t" << NTOPT_LoaderFlags() << '\n';
	return;
}
//��29+1����ÿҳ14����������ʾ��Ϣ

void PEinfo_ouput::NTO_info_3() {
	system("cls");
	cout << "name\t\t\tmeaning\t\t\t\tRVA\t,Size\n\n";

	cout << "DataDirectory[0]\t�����\t\t\t\t" << this->NTOPT_DataDirectory(0) << '\n';
	cout << "DataDirectory[1]\t������\t\t\t\t" << this->NTOPT_DataDirectory(1) << '\n';
	cout << "DataDirectory[2]\t��Դ\t\t\t\t" << this->NTOPT_DataDirectory(2) << '\n';
	cout << "DataDirectory[3]\t�쳣(�������ϲ���)\t\t" << this->NTOPT_DataDirectory(3) << '\n';
	cout << "DataDirectory[4]\t��ȫ(�������ϲ���)\t\t" << this->NTOPT_DataDirectory(4) << '\n';
	cout << "DataDirectory[5]\t�ض�λ��\t\t\t" << this->NTOPT_DataDirectory(5) << '\n';
	cout << "DataDirectory[6]\t������Ϣ\t\t\t" << this->NTOPT_DataDirectory(6) << '\n';
	cout << "DataDirectory[7]\t��Ȩ��Ϣ\t\t\t" << this->NTOPT_DataDirectory(7) << '\n';
	cout << "DataDirectory[8]\tGLOBALPTR(�������ϲ���)\t\t" << this->NTOPT_DataDirectory(8) << '\n';
	cout << "DataDirectory[9]\tTLS(Thread Local Storage)\t" << this->NTOPT_DataDirectory(9) << '\n';
	cout << "DataDirectory[A]\tLOAD_CONFIG(�������ϲ���)\t" << this->NTOPT_DataDirectory(10) << '\n';
	cout << "DataDirectory[B]\tBOUND_IMPORT(�������ϲ���)\t" << this->NTOPT_DataDirectory(11) << '\n';
	cout << "DataDirectory[C]\tIAT(���뺯����ַ��)\t\t" << this->NTOPT_DataDirectory(12) << '\n';
	cout << "DataDirectory[D]\tDELAY_IMPORT(�������ϲ���)\t" << this->NTOPT_DataDirectory(13) << '\n';
	cout << "DataDirectory[E]\tCOM_DESRRIPTOR(�������ϲ���)\t" << this->NTOPT_DataDirectory(14) << '\n';
	cout << "DataDirectory[F]\tδʹ��\t\t\t\t" << this->NTOPT_DataDirectory(15) << '\n';
	return;
}
//����ʮ��λ����


void PEinfo_ouput::main_menu() {
	string file_name;
	while (1) {
		cout << "�뽫����������Ҫ�򿪵��ļ�����ͬһĿ¼��\n"
			 << "�������ļ�����:";
		cin >> file_name;
		this->init(file_name.c_str());
		if (!this->NT_offset()) {
			system("cls");
			cout << "�޷���ָ���ļ�!\n��ȷ���ļ������ļ�·����ȷ\n\n";
			continue;
		}
		break;
	}
	int a = 0;
	while (1) {
		system("cls");
		cout << "�ļ���:" << file_name << "\n��Ҫ��Ϣ:\n";
		cout << "�ļ�λ��:  ";
		if (this->if32())cout << "32bit\t\t";
		else             cout << "64bit\t\t";
		cout << "��������:  " << NTF_NumberOfSections() << '\n';
		cout << "NTͷƫ��:  " << e_lfanew() << "\t\t";
		cout << "��ѡװ�ص�ַ:  " << NTOPT_ImageBase() << "\n\n\n";
		cout << "�����鿴��ϸ��Ϣ:\nd:Dosͷ\nf:NTǩ����NT�ļ�ͷ\no:NT��ѡͷ\nh:����ͷ����\nESC:�˳�����\n\nWaitng ketboard input...";

		switch_loop:
		switch (a) {
		    case 'D':case 'd':this->DOS_info(); a = 0; break;
		    case 'F':case 'f':this->NTFILE_info(); a = 0; break;
		    case 'O':case 'o':this->NTOPT_info(); a = 0; break;
			case 'H':case 'h':this->SH_info(); a = 0; break;
			case 27:return;
			default:a = getch(); goto switch_loop;//�Ҳ�֪��զ���ģ�switch����default��Ȼ���˳�switch
		}
	}
}//���˵������ļ�����ʾ��Ҫ��Ϣ���л�����

void PEinfo_ouput::SH_info() {
	system("cls");
	int page_arr = 0;
	int con = 0;
	this->SH_pages(page_arr);
	while (1) {
		this->SH_pages(page_arr);
	switch_loop:
		switch (getch()) {
		    case 27:return;
			case 224:switch (getch()) {
			    case 75:if (page_arr)--page_arr; break;
				case 77:if ((page_arr + 1) < this->Numbers_of_sections())++page_arr; break;
			}break;
			default:goto switch_loop;
		}
	}
}

void  PEinfo_ouput::SH_pages(int array) {
	system("cls");
	cout << "SECTION_HEADER[" << array << "]\tmeaning\t\t\t\tvalue\n\n";
	cout << "name\t\t\t������\t\t\t\t" << SH_Name(array) << '\n';//int:ָ�����������еĵ�i����Ա
	cout << "VirtualSize\t\t�ڴ��н�����С\t\t\t" << SH_Misc(array) << '\n';//�����ַ���ڴ��н�����ռ��С��union������˫��
	cout << "VirtualAddress\t\t�ڴ��н�����ʼλ��(RVA)\t\t" << SH_VirtualAddress(array) << '\n';
	cout << "SizeOfRawData\t\t�����ļ��н�����С\t\t" << SH_SizeOfRawData(array) << '\n';
	cout << "PointerToRawdata\t�����ļ��н�����ʼλ��\t\t" << SH_PointerToRawData(array) << '\n';
	cout << "PointerToRelocations\t��OBJ�ļ���ʹ��m\,�ض�λ��ƫ��\t" << SH_PointerToRelocations(array) << '\n';
	cout << "PointerToLinenumbers\t�кű��ƫ��(������ʹ��)\t" << SH_PointerToLinenumbers(array) << '\n';
	cout << "NumberOfRelocations\t��OBJ�ļ���ʹ�ã��ض�λ����Ŀ\t" << SH_NumberOfRelocations(array) << '\n';
	cout << "NumberOfLinenumbers\t�кű����кŵ���Ŀ\t\t" << SH_NumberOfLinenumbers(array) << '\n';
	cout << "Characteristics\t\t��������ɶ�,��д,��ִ�е�\t" << SH_Characteristics(array) << '\n';
	cout << "\n��ǰ��" << array+1 << "ҳ,��" << this->Numbers_of_sections() << "ҳ\n";
	cout << "�����鿴��ϸ��Ϣ:\n��:��һҳ\n��:��һҳ\nESC:������һ��\n\nWaitng ketboard input...";
	return;
}