#include "boss.h"

//���캯��
Boss::Boss(int ID, string name, int dID)
{
	//��ʼ��
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeotID = dID;
}

//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ�����: " << this->m_ID
		<< "\tְ������: " << this->m_name
		<< "\t��λ: " << this->GetDeptName()
		<< "\t��λְ��: ����˾��������" << endl;
}

//��ȡ��λ����
string Boss::GetDeptName()
{
	return string("�ϰ�");
}