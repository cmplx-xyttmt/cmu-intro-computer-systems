#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

void print_list(node_t * head) {
	node_t * current = head;

	while (current != NULL) {
		printf("%d->", current->val);
		current = current -> next;
	}
	printf("NULL\n");
}

// Add an item to the end of the list
void push(node_t * head, int val) {
	node_t * current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = (node_t *) malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}


// Add an item to the beginning of the list.
void push_start(node_t ** head, int val) {
	node_t * new_node;
	new_node = (node_t *) malloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}

// Removing the first item (popping from the list)
int pop(node_t ** head) {
	int retval = -1;
	node_t * next_node = NULL;

	if (*head == NULL) {
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;
}

int remove_last(node_t * head) {
	int retval = 0;

	// if only one item in the list, remove it
	if(head->next == NULL) {
		retval = head->val;
		free(head);
		return retval;
	}

	node_t * current = head;
	while(current->next->next != NULL) {
		current = current->next;
	}

	// now current points to the second to last item of the list, so we remove current->next
	retval = current->next->val;
	free(current->next);
	current->next = NULL;
	return retval;
}

int remove_by_index(node_t ** head, int n) {
	int i = 0;
	int retval = -1;
	node_t * current = *head;
	node_t * temp_node = NULL;

	if(n == 0) {
		return pop(head);
	}

	for(i = 0; i < n - 1; i++) {
		if(current->next == NULL) {
			return -1;
		}
		current = current->next;
	}

	if(current->next == NULL) {
		return -1;
	}

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;
}

int remove_by_value(node_t ** head, int val) {
	int retval = -1;
	node_t * current = *head;
	node_t * temp_node = NULL;

	if(current->val == val) {
		return pop(head);
	}

	while(current->next != NULL && current->next->val != val) {
		current = current->next;
	}

	if(current->next == NULL) return -1;

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;
}


int main() {
	node_t * test_list = (node_t *) malloc(sizeof(node_t));
	test_list->val = 1;
	test_list->next = (node_t *) malloc(sizeof(node_t));
	test_list->next->val = 2;
	test_list->next->next = (node_t *) malloc(sizeof(node_t));
	test_list->next->next->val = 3;
	test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
	test_list->next->next->next->val = 4;
	test_list->next->next->next->next = NULL;

	printf("Initial list:\n");
	print_list(test_list);

	remove_last(test_list);
	printf("After removing the last item:\n");
	print_list(test_list);

	push_start(&test_list, 5);
	printf("After adding 5 to the start of the list:\n");
	print_list(test_list);

	push(test_list, 6);
	printf("After adding 6 to the end of the list:\n");
	print_list(test_list);

	remove_by_index(&test_list, 2);
	printf("After removing the item at index 2:\n");
	print_list(test_list);

	remove_by_value(&test_list, 3);
	printf("After removing the item with the value 3:\n");
	print_list(test_list);

	return 0;
}

