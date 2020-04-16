#include "WorkerManager.h"


//���캯��ʵ��
WorkerManager::WorkerManager()
{
	
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//���ļ�

	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;

		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.�ļ�����������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())	//�ж��ļ�������β
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��!" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����Ҽ�¼����
	int num = GetEmpNum();
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->InitEmp();
}
//��������ʵ��
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//չʾ�˵�ʵ��
void WorkerManager::ShowMenu()
{
	cout << "**********************************************" << endl;
	cout << "************* ��ӭʹ��ְ������ϵͳ��************" << endl;
	cout << "**************** 0.�˳�������� ***************" << endl;
	cout << "**************** 1.����ְ����Ϣ ***************" << endl;
	cout << "**************** 2.��ʾְ����Ϣ ***************" << endl;
	cout << "**************** 3.ɾ��ְ����Ϣ ***************" << endl;
	cout << "**************** 4.�޸�ְ����Ϣ ***************" << endl;
	cout << "**************** 5.����ְ����Ϣ ***************" << endl;
	cout << "**************** 6.���ձ������ ***************" << endl;
	cout << "**************** 7.��������ĵ� ***************" << endl;
	cout << endl;
}

//�˳�ϵͳʵ��
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��!";
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::AddEmp()
{
	cout << "���������ְ������: " << endl;
	int addNum = 0;	//�����û�������
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;	//�¿ռ��С=ԭ����¼����+��������

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ������ݣ��������¿ռ�
		if (this->m_EmpArray != NULL)
		{
			//��ԭ�������е�������һ�������¿ռ�
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;		//���
			string name;	//����
			int dSelect;	//ְλ

			cout << "������� " << i + 1 << "����Ա���ı�ţ� " << endl;
			cin >> id;

			cout << "������� " << i + 1 << "����Ա���������� " << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ: " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־                                                                                                     
		this->m_FileIsEmpty = false;

		//�ɹ���Ӻ󣬱��浽�ļ���


		//��ӳɹ���ʾ
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//�������ݵ��ļ���
		this->Save();
	}
	else
	{
		cout << "������������" << endl;
	}

	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");	
}

//�����ļ�
void WorkerManager::Save()
{
	//�����ļ���
	ofstream ofs;

	//���ļ�
	ofs.open(FILENAME, ios::out);	//�������ʽ���ļ� -- д�ļ�
	
	//��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeotID << " " << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ������
int WorkerManager::GetEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//���ļ�����
	int id;
	string name;
	int dID;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		//ͳ������
		num++;
	}
	return num;
}

//��ʼ��Ա��
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
	//�ر��ļ�
	ifs.close();
}

//��ʾְ��
void WorkerManager::ShowEmp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//�������������
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManager::DelEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�������!" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ���ı��: " << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)	//ְ�����ڣ���Ҫɾ����indexλ���ϵ�ְ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;	//���������м�¼����Ա����
			//ͬ�����µ��ļ���
			this->Save();
			cout << "ɾ���ɹ�!" << endl;
		}
		else
		{
			cout << "ɾ��ʧ��,δ�ҵ���ְ����" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����:������ڷ���ְ�����������λ�ã������ڷ���-1;
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			//�ҵ���Ӧְ��
			index = i;
		}
	}
	return index;
}

//�޸�ְ��
void WorkerManager::ModEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��!" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��: " << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ��ñ�ŵ�ְ��
			delete this->m_EmpArray[ret];
			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽: " << id << "��ְ�����������µ�ְ����: " << endl;
			cin >> newID;
			cout << "�������µ�����: " << endl;
			cin >> newName;
			cout << "�������µĸ�λ: " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�!" << endl;

			//���浽�ļ���
			this->Save();
		}
		else
		{
			cout << "�޸�ʧ��!" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ:" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������Ҫ����ְ���ı��:" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҵ���ְ��,��Ϣ����:" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "���޴���!" << endl;
			}
		}
		else if(select == 2)
		{
			string name;
			cout << "������Ҫ����ְ��������:" << endl;
			cin >> name;

			//�����ж��Ƿ�鵽�ı�־
			bool flag = false;	//Ĭ��δ�ҵ���ְ��

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ: " 
						<< this->m_EmpArray[i]->m_ID 
						<< "��ְ����Ϣ���£�" << endl;

					flag = true;
					this->m_EmpArray[i]->ShowInfo();
				}
			}

			if (!flag)
			{
				cout << "����ʧ��!" << endl;
			}
		}
		else
		{
			cout << "����ѡ������,����������!" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//���ձ�Ž�������
void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ:" << endl;
		cout << "1.����ְ����������" << endl;
		cout << "2.����ְ���Ž�����" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;	//������Сֵ�����ֵ�±�
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
					//����
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}

			//�ж�һ��ʼ�϶������ֵ������Сֵ�Ƿ���������ֵ������Сֵ��������ǣ���������
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "����ɹ�,�����Ľ��Ϊ:" << endl;
		this->Save();	
		this->ShowEmp();
	}
}

//�������
void WorkerManager::CleanFile()
{
	cout << "ȷ�������?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);	//ɾ���ļ����ٴ���
		ofs.close();
		if (this->m_EmpArray != NULL)
		{	
			//ɾ������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�!" << endl;
	}
	system("pause");
	system("cls");
}