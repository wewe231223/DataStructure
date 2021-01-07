#include "node.h"

void node_reconnection(node* pre, node* target) {
	pre->link = target->link;
}

void node_free(node* head) {
	node* current = head;
	node* temp = NULL;
	while (current != NULL) {
		temp = current;
		current = current->link;
		free(temp);
	}
}

void node_print(node* head) {
	node* current = head;
	int index = 1;

	while (current != NULL) {
		printf("%d th node is %d\n", index, current->data);
		current = current->link;
		index++;
	}
}

void node_initialize(node* Node, node* pre, node* next, int data) {

	Node->link = next;
	Node->data = data;
	if (pre == NULL) {

	}
	else { pre->link = Node; }
}

void node_package(node* head, node* tail, int HeadData, int TailData) {
	head->link = NULL;
	head->data = HeadData;
	tail->link = NULL;
	tail->data = TailData;
}

node* node_prenode(node* head, int index) {
	node* current = head;
	node* current_buffer = head;
	int idx = 0;
	while (current != NULL) {
		if (idx == index) {
			return current_buffer;
		}

		idx++;
		current_buffer = current;
		current = current->link;
	}
	return NULL;
}

bool node_search(node* head, int target_data) {
	node* current = head;
	int index = 0;
	while (current != NULL) {
		if (current->data == target_data) {
			return index;
		}
		index++;
		current = current->link;
	}
	printf("target is not exist");
	return false;
}

bool node_delete(node* head, int target_index) {
	node* current = head;
	int index = 0;

	while (current != NULL) {
		if (index == target_index) {
			node_reconnection(node_prenode(head, index), current);
			free(current);
			return true;
		}
		index++;
		current = current->link;
	}

	return false;
}


