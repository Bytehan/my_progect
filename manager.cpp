#include "manager.h"

//���캯��
Manager::Manager(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeotID = dID;
}
//��ʾ������Ϣ
void Manager::ShowInfo()
{
	cout << "ְ�����: " << this->m_ID
		<< "\tְ������: " << this->m_name
		<< "\t��λ: " << this->GetDeptName()
		<< "\t��λְ��: ����ϰ彻��������" << endl;
}

//��ȡ��λ����
string Manager::GetDeptName()
{
	return string("����");
}