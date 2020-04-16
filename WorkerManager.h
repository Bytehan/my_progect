#pragma once	//��ֹͷ�ļ��ظ�����
#include <iostream>	//���������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#include <fstream>

#define FILENAME "empFile.txt"


class WorkerManager
{
public:

	//���캯��
	WorkerManager();

	//��������
	~WorkerManager();

	//չʾ�˵�
	void ShowMenu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//��¼ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void AddEmp();

	//�����ļ�
	void Save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ������
	int GetEmpNum();

	//��ʼ��Ա��
	void InitEmp();

	//��ʾְ��
	void ShowEmp();

	//ɾ��ְ��
	void DelEmp();

	//�ж�ְ���Ƿ����:������ڷ���ְ�����������λ�ã������ڷ���-1;
	int IsExist(int id);

	//�޸�ְ��
	void ModEmp();

	//����ְ��
	void FindEmp();

	//���ձ�Ž�������
	void SortEmp();

	//�������
	void CleanFile();
};