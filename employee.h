//��ͨԱ���ļ�
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

class Employee :public Worker
{
public:

	//���캯��
	Employee(int ID, string name, int dID);

	//��ʾ������Ϣ
	virtual void ShowInfo();	

	//��ȡ��λ����
	virtual string GetDeptName();
};