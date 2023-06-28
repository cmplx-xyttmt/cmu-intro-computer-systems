/**
 * @file queue.c
 * @brief Implementation of a queue that supports FIFO and LIFO operations.
 *
 * This queue implementation uses a singly-linked list to represent the
 * queue elements. Each queue element stores a string value.
 *
 * Assignment for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Extended to store strings, 2018
 *
 * 
 * @author Isaac Owomugisha github.com/cmplx-xyttmt
 */

#include "queue.h"
#include "harness.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Allocates a new queue
 * @return The new queue, or NULL if memory allocation failed
 */
queue_t *queue_new(void) {
    queue_t *q = (queue_t *) malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
	if(q == NULL) return NULL;
    q->head = NULL;
	q->num_elements = 0;
    return q;
}

/**
 * @brief Frees all memory used by a queue
 * @param[in] q The queue to free
 */
void queue_free(queue_t *q) {
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
	if(q == NULL) return;

	while(q->head != NULL) {
		queue_remove_head(q, NULL, 0);
	}
    free(q);
}

/**
 * @brief Attempts to insert an element at head of a queue
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, instead of `s` itself.
 *
 * @param[in] q The queue to insert into
 * @param[in] s String to be copied and inserted into the queue
 *
 * @return true if insertion was successful
 * @return false if q is NULL, or memory allocation failed
 */
bool queue_insert_head(queue_t *q, const char *s) {
	if(q == NULL) return false;
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    newh = malloc(sizeof(list_ele_t));
	if(newh == NULL) return false;
    /* Don't forget to allocate space for the string and copy it */ 
	char * new_s = malloc(strlen(s) + 1);
	/* What if either call to malloc returns NULL? */
	if(new_s == NULL) {
		free(newh);
		return false;
	}
	strcpy(new_s, s);
	newh->next = q->head;
	newh->value = new_s;
	if(q->head == NULL) q->tail = newh;
    q->head = newh;
	q->num_elements += 1;
    return true;
}

/**
 * @brief Attempts to insert an element at tail of a queue
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, instead of `s` itself.
 *
 * @param[in] q The queue to insert into
 * @param[in] s String to be copied and inserted into the queue
 *
 * @return true if insertion was successful
 * @return false if q is NULL, or memory allocation failed
 */
bool queue_insert_tail(queue_t *q, const char *s) {
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
	if(q == NULL) return false;
	list_ele_t *newh;
	newh = malloc(sizeof(list_ele_t));
	if(newh == NULL) return false;
	
	char * new_s = malloc(strlen(s) + 1);
	if(new_s == NULL) {
		free(newh);
		return false;
	}
	strcpy(new_s, s);

	newh->value = new_s;
	newh->next = NULL;
	q->tail->next = newh;
	q->tail = newh;
	q->num_elements += 1;
    return true;
}

/**
 * @brief Attempts to remove an element from head of a queue
 *
 * If removal succeeds, this function frees all memory used by the
 * removed list element and its string value before returning.
 *
 * If removal succeeds and `buf` is non-NULL, this function copies up to
 * `bufsize - 1` characters from the removed string into `buf`, and writes
 * a null terminator '\0' after the copied string.
 *
 * @param[in]  q       The queue to remove from
 * @param[out] buf     Output buffer to write a string value into
 * @param[in]  bufsize Size of the buffer `buf` points to
 *
 * @return true if removal succeeded
 * @return false if q is NULL or empty
 */
bool queue_remove_head(queue_t *q, char *buf, size_t bufsize) {
    /* You need to fix up this code. */
	if(q == NULL || q->head == NULL) return false;

    list_ele_t * temp = q->head;
	q->head = q->head->next;
	q->num_elements -= 1;
	if(buf != NULL) {
		strncpy(buf, temp->value, bufsize - 1);
		buf[bufsize - 1] = '\0';
	}
	free(temp->value);
	free(temp);
    return true;
}

/**
 * @brief Returns the number of elements in a queue
 *
 * This function runs in O(1) time.
 *
 * @param[in] q The queue to examine
 *
 * @return the number of elements in the queue, or
 *         0 if q is NULL or empty
 */
size_t queue_size(queue_t *q) {
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
	if(q == NULL) return 0;
    return q->num_elements;
}

/**
 * @brief Reverse the elements in a queue
 *
 * This function does not allocate or free any list elements, i.e. it does
 * not call malloc or free, including inside helper functions. Instead, it
 * rearranges the existing elements of the queue.
 *
 * @param[in] q The queue to reverse
 */
void queue_reverse(queue_t *q) {
    /* You need to write the code for this function */
	if(q == NULL) return;

	list_ele_t * current_ele;
	list_ele_t * prev_ele;
	prev_ele = NULL;
	current_ele = q->head;

	while (current_ele != NULL) {
		list_ele_t * temp = current_ele;
		current_ele = current_ele->next;
		temp->next = prev_ele;
		prev_ele = temp;
	}

	q->tail = q->head;
	q->head = prev_ele;
}
