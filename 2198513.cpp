// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct Node
{
	int element;
	struct Node* next;
} Node;


Node *createList(int x)
{
	Node *tmp;
	tmp = (Node *)malloc(sizeof(Node));
	tmp->element = x;
	tmp->next = NULL;
	return tmp;
}
Node* insertOrdered(Node *head, int x)
{
	Node *tmp;
	tmp = head;
	if (head->element > x) /* insert at beginning */
	{
		tmp = (Node *)malloc(sizeof(Node));
		tmp->element = x;
		tmp->next = head;
		return tmp;
	}
	while (tmp->next != NULL && tmp->next->element <= x)
		tmp = tmp->next;
	if (tmp->next == NULL) /* insert at the end */
	{
		tmp->next = (Node *)malloc(sizeof(Node));
		tmp->next->element = x;
		tmp->next->next = NULL;
	}
	else /* insert in the middle */
	{
		Node *tmp2 = tmp->next;
		tmp->next = (Node *)malloc(sizeof(Node));
		tmp->next->element = x;
		tmp->next->next = tmp2;
	}
	return head;
}
void printList(Node *head)
{
	Node *tmp;
	tmp = head;
	while (tmp != NULL)
	{
		printf("%d ", tmp->element);
		tmp = tmp->next;
	}
	printf("\n");
}
Node* mergeLists(Node* list1, Node* list2)
{
	Node *myNode;
	Node *last;
	if (list1->element <= list2->element) {
		myNode = list1;
		last = myNode;
		list1 = list1->next;
	}
	else {
		myNode = list2;
		last = list2;
		list2 = list2->next;
	}
	while (list1 != NULL && list2 != NULL) {
		if (list1->element <= list2->element) {
			last->next = list1;
			list1 = list1->next;
		}
		else {
			last->next = list2;
			list2 = list2->next;
		}
		last = last->next;
	}
	if (list2 != NULL) {
		while (list2 != NULL)
		{
			last->next = list2;
			list2 = list2->next;
			last = last->next;
		}
		
	}
	else 
	{
		while (list1 != NULL)
		{
			last->next = list1;
			list1 = list1->next;
			last = last->next;
		}
		

	}
	return myNode;
}
int main()
{
	Node *listA;
	Node *listB;
	Node *merged;
	listA = createList(6);
	listB = createList(4);
	listA = insertOrdered(listA, 3);
	listA = insertOrdered(listA, 9);
	listA = insertOrdered(listA, 5);
	listA = insertOrdered(listA, 10);
	listA = insertOrdered(listA, 2);
	listB = insertOrdered(listB, 1);
	listB = insertOrdered(listB, 8);
	listB = insertOrdered(listB, 7);
	listB = insertOrdered(listB, 14);
	listB = insertOrdered(listB, 11);
	listB = insertOrdered(listB, 19);
	listB = insertOrdered(listB, 15);
	cout << "list A : ";
	printList(listA);
	cout << "list B : ";
	printList(listB);
	merged = mergeLists(listA, listB);
	cout << "Merged List : ";
	printList(merged);
	system("PAUSE");
}