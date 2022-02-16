#pragma once
#include "BinaryTree.h"
#include "LinkStack.h"			//ջ���ڸ�������ֵ
#include <string>

bool IsLeaf(const BinTreeNode<string>* r);			//�Ƿ�Ҷ�ӽڵ�
LinkStack<double> DictBuilding(int num = 0);		//���������ʵ�
string Operate(const string& first, const string& op, const string& second, LinkStack<double>& dict);	// ��������(֧�ֱ����볣��): R(string1,string2) = F(num1,num2) = num3 �� string3
string Calculate(const BinTreeNode<string>* r, LinkStack<double>& dict);		//���������б��ʽ������
double Calculate(const BinaryTree<string>& tree, LinkStack<double>& dict);		//���������б��ʽ������