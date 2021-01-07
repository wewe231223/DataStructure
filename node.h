#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct Node {
	int data;
	struct Node* link;
} node;


void node_reconnection(node* pre, node* target);
void node_free(node* head);
void node_print(node* head);
void node_initialize(node* Node, node* pre, node* next, int data);
void node_package(node* head, node* tail, int HeadData, int TailData);

node* node_prenode(node* head, int index);

bool node_search(node* head, int target_data);
bool node_delete(node* head, int target_index);
