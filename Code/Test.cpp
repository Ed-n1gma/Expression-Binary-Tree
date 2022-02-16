#include "Calculate.h"

int main()
{	
	BinaryTree<string> tree;
	/*		//��������1
	string pre[] = {"+", "a", "*", "b" , "+", "c", "d"};			// ��������
	string in[] = { "a", "+", "b", "*", "c", "+", "d"};				// ��������
	int n = 7; */
	/*		//��������1 ��ֵ
	string pre[] = { "+", "1.1", "*", "4.0" , "+", "3.0", "5.1" };			// ��������
	string in[] = { "1.1", "+", "4.0", "*", "3.0", "+", "5.1" };			// ��������
	int n = 7;  */
	/*
			//��������2: PBL�ϵ�ͼ
	string pre[] = { "-", "1", "/","-", "2", "3", "*", "4", "+", "5", "6" };			// ��������
	string in[] = { "1", "-", "2","-", "3", "/", "4", "*", "5", "+", "6" };				// ��������
	int n = 11;  */
			//��������2 
	string pre[] = { "-", "a", "/","-", "b", "c", "*", "e", "+", "f", "g" };			// ��������
	string in[] = { "a", "-", "b","-", "c", "/", "e", "*", "f", "+", "g" };				// ��������
	int n = 11; 
	
	/*
		//��������3: !!!�����������:�޷������� �����
	string pre[] = {"-", "-", "a","b", "-","c", "d"};			// ��������
	string in[] = { "a", "-","b", "-", "c","-", "d"};			// ��������
	int n = 7;	*/

	tree = CreateBinaryTree(pre, in, n);         // ���������

	cout << "��ǰ������: " << endl;
	DisplayBTWithTreeShape(tree);			
	cout << endl;

	LinkStack<double> dictionary1,dictionary2;
	
	while (1)
	{	
		dictionary2 = DictBuilding(6);			//�������޸���ջ��С
		cout << Calculate(tree, dictionary2) << endl;
	}
	/*		//��������1
	dictionary1.Push(1.1);	// a = 1.1
	dictionary1.Push(4.0);	// b = 4.0
	dictionary1.Push(3);	// c = 3.0
	dictionary1.Push(5.1);	// d = 5.1
	cout << Calculate(tree, dictionary1) <<endl;*/

}