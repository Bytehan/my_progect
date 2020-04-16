//普通员工文件
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

class Employee :public Worker
{
public:

	//构造函数
	Employee(int ID, string name, int dID);

	//显示个人信息
	virtual void ShowInfo();	

	//获取岗位名称
	virtual string GetDeptName();
};