#pragma once
#include <iostream>
using namespace std;
#include <string>

//职工抽象类
class Worker
{
public:

	//显示个人信息
	virtual void ShowInfo() = 0;	//在基类中不做实现，所以将其声明为纯虚函数

	//获取岗位名称
	virtual string GetDeptName() = 0;

	//职工编号
	int m_ID;

	//职工姓名
	string m_name;

	//部门编号
	int m_DeotID;
};