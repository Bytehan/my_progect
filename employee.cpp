#include "employee.h"

//���캯��
Employee::Employee(int ID, string name, int dID)
{
	//��ʼ��
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeotID = dID;
}

//��ʾ������Ϣ
void Employee::ShowInfo()
{
	cout << "ְ�����: " << this->m_ID
		<< "\tְ������: " << this->m_name
		<< "\t��λ: " << this->GetDeptName()
		<< "\t��λְ��: ��ɾ�����������" << endl;
}

//��ȡ��λ����
string Employee::GetDeptName()
{
	return string("Ա��");
}