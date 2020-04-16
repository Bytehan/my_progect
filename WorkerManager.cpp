#include "WorkerManager.h"


//构造函数实现
WorkerManager::WorkerManager()
{
	
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//读文件

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;

		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;

		//初始化数组指针
		this->m_EmpArray = NULL;

		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.文件存在且数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())	//判断文件读到结尾
	{
		//文件为空
		//cout << "文件为空!" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;

		//初始化数组指针
		this->m_EmpArray = NULL;

		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，并且记录数据
	int num = GetEmpNum();
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->InitEmp();
}
//析构函数实现
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//展示菜单实现
void WorkerManager::ShowMenu()
{
	cout << "**********************************************" << endl;
	cout << "************* 欢迎使用职工管理系统！************" << endl;
	cout << "**************** 0.退出管理程序 ***************" << endl;
	cout << "**************** 1.增加职工信息 ***************" << endl;
	cout << "**************** 2.显示职工信息 ***************" << endl;
	cout << "**************** 3.删除职工信息 ***************" << endl;
	cout << "**************** 4.修改职工信息 ***************" << endl;
	cout << "**************** 5.查找职工信息 ***************" << endl;
	cout << "**************** 6.按照编号排序 ***************" << endl;
	cout << "**************** 7.清空所有文档 ***************" << endl;
	cout << endl;
}

//退出系统实现
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用!";
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::AddEmp()
{
	cout << "请输入添加职工数量: " << endl;
	int addNum = 0;	//保存用户输入量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新空间的大小
		int newSize = this->m_EmpNum + addNum;	//新空间大小=原来记录人数+新增人数

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下数据，拷贝到新空间
		if (this->m_EmpArray != NULL)
		{
			//将原来数组中的内容逐一拷贝到新空间
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;		//编号
			string name;	//姓名
			int dSelect;	//职位

			cout << "请输入第 " << i + 1 << "个新员工的编号： " << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << "个新员工的姓名： " << endl;
			cin >> name;

			cout << "请选择该职工的岗位: " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空标志                                                                                                     
		this->m_FileIsEmpty = false;

		//成功添加后，保存到文件中


		//添加成功提示
		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存数据到文件中
		this->Save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}

	//按任意键后，清屏回到上级目录
	system("pause");
	system("cls");	
}

//保存文件
void WorkerManager::Save()
{
	//创建文件流
	ofstream ofs;

	//打开文件
	ofs.open(FILENAME, ios::out);	//用输出方式打开文件 -- 写文件
	
	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeotID << " " << endl;
	}

	//关闭文件
	ofs.close();
}

//统计人数
int WorkerManager::GetEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//打开文件，读
	int id;
	string name;
	int dID;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		//统计人数
		num++;
	}
	return num;
}

//初始化员工
void WorkerManager::InitEmp
()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dID;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		if (dID == 1)
		{
			worker = new Employee(id, name, dID);
		}
		else if(dID == 2)
		{
			worker = new Manager(id, name, dID);
		}
		else
		{
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}

//显示职工
void WorkerManager::ShowEmp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::DelEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在!" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工的编号: " << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)	//职工存在，且要删除掉index位置上的职工
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;	//更新数组中记录的人员个数
			//同步更新到文件中
			this->Save();
			cout << "删除成功!" << endl;
		}
		else
		{
			cout << "删除失败,未找到该职工！" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//判断职工是否存在:如果存在返回职工所在数组的位置，不存在发会-1;
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			//找到对应职工
			index = i;
		}
	}
	return index;
}

//修改职工
void WorkerManager::ModEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空!" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号: " << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到该编号的职工
			delete this->m_EmpArray[ret];
			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到: " << id << "号职工，请输入新的职工号: " << endl;
			cin >> newID;
			cout << "请输入新的姓名: " << endl;
			cin >> newName;
			cout << "请输入新的岗位: " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newID, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newID, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newID, newName, dSelect);
				break;
			default:
				break;
			}

			//更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功!" << endl;

			//保存到文件中
			this->Save();
		}
		else
		{
			cout << "修改失败!" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入查找的方式:" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入所要查找职工的编号:" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找到该职工,信息如下:" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "查无此人!" << endl;
			}
		}
		else if(select == 2)
		{
			string name;
			cout << "请输入要查找职工的姓名:" << endl;
			cin >> name;

			//加入判断是否查到的标志
			bool flag = false;	//默认未找到该职工

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功,职工编号为: " 
						<< this->m_EmpArray[i]->m_ID 
						<< "号职工信息如下：" << endl;

					flag = true;
					this->m_EmpArray[i]->ShowInfo();
				}
			}

			if (!flag)
			{
				cout << "查找失败!" << endl;
			}
		}
		else
		{
			cout << "输入选项有误,请重新输入!" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//按照编号进行排序
void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式:" << endl;
		cout << "1.按照职工号升序排" << endl;
		cout << "2.按照职工号降序排" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;	//声明最小值或最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrMax = i;
					}
				}
				else
				{
					//降序
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}

			//判断一开始认定的最大值或者最小值是否是真的最大值或者最小值，如果不是，交换数据
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "排序成功,排序后的结果为:" << endl;
		this->Save();	
		this->ShowEmp();
	}
}

//清空数据
void WorkerManager::CleanFile()
{
	cout << "确定清空吗?" << endl;
	cout << "1.确定" << endl;
	cout << "2.取消" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);	//删除文件后再创建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{	
			//删除堆区每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功!" << endl;
	}
	system("pause");
	system("cls");
}