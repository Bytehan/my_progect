#include "boss.h"

//构造函数
Boss::Boss(int ID, string name, int dID)
{
	//初始化
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeotID = dID;
}

//显示个人信息
void Boss::ShowInfo()
{
	cout << "职工编号: " << this->m_ID
		<< "\t职工姓名: " << this->m_name
		<< "\t岗位: " << this->GetDeptName()
		<< "\t岗位职责: 管理公司所有事务" << endl;
}

//获取岗位名称
string Boss::GetDeptName()
{
	return string("老板");
}