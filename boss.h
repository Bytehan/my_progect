//�ϰ��ļ�
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Boss :public Worker
{
public:

	//���캯��
	Boss(int ID, string name, int dID);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string GetDeptName();
};
