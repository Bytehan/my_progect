//老板文件
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Boss :public Worker
{
public:

	//构造函数
	Boss(int ID, string name, int dID);

	//显示个人信息
	virtual void ShowInfo();

	//获取岗位名称
	virtual string GetDeptName();
};
