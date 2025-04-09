#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_depth - Computes the depth of the leftmost path
 * @tree: Pointer to the root node
 *
 * Return: Depth (number of levels)
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree)
    {
        depth++;
        tree = tree->left;
    }

    return (depth);
}

/**
 * is_perfect_recursive - Recursively checks if tree is perfect
 * @tree: Current node
 * @depth: Expected depth of all leaf nodes
 * @level: Current level in the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */

int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
    if (tree == NULL)
    {
        return (1);
    }

    if (tree->left == NULL && tree->right == NULL)
    {
        return (depth == level + 1);
    }

    if (tree->left == NULL || tree->right == NULL)
    {
        return (0);
    }

    return (
        is_perfect_recursive(tree->left, depth, level + 1) &&
        is_perfect_recursive(tree->right, depth, level + 1)
    );
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t depth;

    if (tree == NULL)
    {
        return (0);
    }

    depth = binary_tree_depth(tree);
    return (is_perfect_recursive(tree, depth, 0));
}
