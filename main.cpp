#include <iostream>
using namespace std;
#include "WorkerManager.h"

//#include "worker.h"
//#include "employee.h"
//#include "boss.h"
//#include "manager.h"

int main()
{
	////测试代码
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->ShowInfo();
	//delete worker;

	//worker = new Manager(2, "李四", 2);
	//worker->ShowInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->ShowInfo();
	//delete worker;

	//实例化管理者对象
	WorkerManager wm;
	int choise = 0; //用来存储用户的选项
	while (true)
	{
		//调用展示菜单成员函数
		wm.ShowMenu();
		cout << "请输入您的选择: " << endl;
		cin >> choise;	//接受用户选项

		switch (choise)
		{
		case 0:	//退出系统
			wm.ExitSystem();
			break;
		case 1:	//增加
			wm.AddEmp();
			break;
		case 2:	//显示
			wm.ShowEmp();
			break;
		case 3:	//删除
			wm.DelEmp();
			break;
		case 4:	//修改
			wm.ModEmp();
			break;
		case 5:	//查找
			wm.FindEmp();
			break;
		case 6:	//排序
			wm.SortEmp();
			break;
		case 7:	//清空
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	//调用展示菜单成员函数
	wm.ShowMenu();
	system("pause");
	return 0;
}