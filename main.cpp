#include <iostream>
using namespace std;
#include "WorkerManager.h"

//#include "worker.h"
//#include "employee.h"
//#include "boss.h"
//#include "manager.h"

int main()
{
	////���Դ���
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->ShowInfo();
	//delete worker;

	//worker = new Manager(2, "����", 2);
	//worker->ShowInfo();
	//delete worker;

	//worker = new Boss(3, "����", 3);
	//worker->ShowInfo();
	//delete worker;

	//ʵ���������߶���
	WorkerManager wm;
	int choise = 0; //�����洢�û���ѡ��
	while (true)
	{
		//����չʾ�˵���Ա����
		wm.ShowMenu();
		cout << "����������ѡ��: " << endl;
		cin >> choise;	//�����û�ѡ��

		switch (choise)
		{
		case 0:	//�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:	//����
			wm.AddEmp();
			break;
		case 2:	//��ʾ
			wm.ShowEmp();
			break;
		case 3:	//ɾ��
			wm.DelEmp();
			break;
		case 4:	//�޸�
			wm.ModEmp();
			break;
		case 5:	//����
			wm.FindEmp();
			break;
		case 6:	//����
			wm.SortEmp();
			break;
		case 7:	//���
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	//����չʾ�˵���Ա����
	wm.ShowMenu();
	system("pause");
	return 0;
}