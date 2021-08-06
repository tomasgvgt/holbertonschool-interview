#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
	{
		binary_tree_t *node;

		node = malloc(sizeof(binary_tree_t));
		if (!node)
			return (NULL);

		node->n = value;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;

		return (node);
	}
