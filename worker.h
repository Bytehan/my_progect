#pragma once
#include <iostream>
using namespace std;
#include <string>

//ְ��������
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;	//�ڻ����в���ʵ�֣����Խ�������Ϊ���麯��

	//��ȡ��λ����
	virtual string GetDeptName() = 0;

	//ְ�����
	int m_ID;

	//ְ������
	string m_name;

	//���ű��
	int m_DeotID;
};