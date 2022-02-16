#pragma once
#include "BinaryTree.h"
#include "LinkStack.h"			//�������ڸ�������ֵ
#include <string>

bool IsLeaf(const BinTreeNode<string>* r)			//�Ƿ�Ҷ�ӽڵ�
{
	if (r == NULL)
		return false;
	return ((r->leftChild == NULL) && (r->rightChild == NULL));
}

LinkStack<double> DictBuilding(int num = 0)
{
	LinkStack<double> dictionary;
	double buffer;
	for (int i = 0; i < num; i++)
	{
		cin >> buffer;
		dictionary.Push(buffer);						//��ȡʱ�����չ�����������ķ�ʽ��ȡ��ÿһ������� ����һ��
	}
	return dictionary;
}

string Operate(const string &first, const string &op,const string &second, LinkStack<double> &dict)		// R(string1,string2) = F(num1,num2) = num3 �� string3
// ���������ִ������first op second
{
	double num1,num2;											//����Ǳ���(��λΪСд��ĸ) ��dictionaryջ�ж�ȡ
	if (char(second[0]) >= 'a' && char(second[0]) <= 'z')		//��ȡʱ�����չ�����������ķ�ʽ��ȡ��ÿһ������� ����һ��
		dict.Pop(num2);						//!!!�����ȳ�num1��ջ��Ӧ�������ҵ��� �������ϴ�������num2��ջ
	else
		num2 = stod(second);
	if (char(first[0]) >= 'a' && char(first[0]) <= 'z')			
		dict.Pop(num1);											
	else
		num1 = stod(first);	

	double result;
	switch (op[0]) 
	{
	case '+': result = num1 + num2;			    // �ӷ�����
		break;
	case '-': result = num1 - num2;			    // ��������
		break;
	case '*': result = num1 * num2;			    // �˷�����
		break;
	case '/': 
		if (num2 == 0)							  // �������� 
		throw Error("��������Ϊ��!");			// �׳��쳣
		result = num1 / num2;
		break;
	default:
		throw Error("δ����������");
		break;
	}
	return to_string(result);				// ���������� 
}

string Calculate(const BinTreeNode<string>* r, LinkStack<double> &dict)
{
	if (r == NULL)
		return "û�ж�����";
	if (!IsLeaf(r))
		return Operate(Calculate(r->leftChild, dict), r->data, Calculate(r->rightChild, dict), dict);
	else
		return r->data;
}

double Calculate(const BinaryTree<string>&tree, LinkStack<double> &dict)
{
	return stod(Calculate(tree.GetRoot(), dict));
}