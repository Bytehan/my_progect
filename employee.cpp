#include "employee.h"

//构造函数
Employee::Employee(int ID, string name, int dID)
{
	//初始化
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeotID = dID;
}

//显示个人信息
void Employee::ShowInfo()
{
	cout << "职工编号: " << this->m_ID
		<< "\t职工姓名: " << this->m_name
		<< "\t岗位: " << this->GetDeptName()
		<< "\t岗位职责: 完成经理交给的任务" << endl;
}

//获取岗位名称
string Employee::GetDeptName()
{
	return string("员工");
}