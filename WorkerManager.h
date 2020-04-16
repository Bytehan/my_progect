#pragma once	//防止头文件重复包含
#include <iostream>	//包含输入输出流的头文件
using namespace std;	//使用标准命名空间
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#include <fstream>

#define FILENAME "empFile.txt"


class WorkerManager
{
public:

	//构造函数
	WorkerManager();

	//析构函数
	~WorkerManager();

	//展示菜单
	void ShowMenu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//记录职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void AddEmp();

	//保存文件
	void Save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计人数
	int GetEmpNum();

	//初始化员工
	void InitEmp();

	//显示职工
	void ShowEmp();

	//删除职工
	void DelEmp();

	//判断职工是否存在:如果存在返回职工所在数组的位置，不存在发会-1;
	int IsExist(int id);

	//修改职工
	void ModEmp();

	//查找职工
	void FindEmp();

	//按照编号进行排序
	void SortEmp();

	//清空数据
	void CleanFile();
};