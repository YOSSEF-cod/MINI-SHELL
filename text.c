#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct s_tree
{
    char *value;
    struct s_tree *left;
    struct s_tree *right;
} t_tree;

// Create Node
t_tree *create_node(char *value)
{
    t_tree *node = malloc(sizeof(t_tree));
    node->value = strdup(value);
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int get_precedence(char *op)
{
    if (strcmp(op, "(") == 0 || strcmp(op, ")") == 0)
        return 1;
    if (strcmp(op, "||") == 0)
        return 2;
    if (strcmp(op, "&&") == 0)
        return 3;
    if (strcmp(op, "|") == 0)
        return 4;
    if (strcmp(op, ">") == 0 || strcmp(op, "<") == 0 || strcmp(op, ">>") == 0)
        return 5;
    if (strcmp(op, ";") == 0)
        return 6;
    if (strcmp(op, "&") == 0)
        return 7;
    return 0;
}

// Precedence Climbing
t_tree *precedence_climbing(char **tokens, int *i, int min_prec)
{
    t_tree *left = create_node(tokens[*i]);
    (*i)++;

    while (tokens[*i] && get_precedence(tokens[*i]) >= min_prec)
    {
        char *op = tokens[*i];
        int prec = get_precedence(op);
        (*i)++;

        t_tree *right = precedence_climbing(tokens, i, prec + 1);
        t_tree *new_node = create_node(op);
        new_node->left = left;
        new_node->right = right;
        left = new_node;
    }
    return left;
}

void print_tree(t_tree *root, int depth)
{
    if (!root)
        return;
    print_tree(root->right, depth + 1);
    for (int i = 0; i < depth; i++)
        printf("\t");
    printf("%s\n", root->value);
    print_tree(root->left, depth + 1);
}

void free_tree(t_tree *root)
{
    if (!root)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->value);
    free(root);
}

int main()
{
    char *tokens[] = {"ls", "&&", "grep", ".txt", "&&", "echo", "done", ">", "result.txt", NULL};
    int i = 0;
    t_tree *tree = precedence_climbing(tokens, &i, 0);
    printf("Binary Tree Structure:\n");
    print_tree(tree, 0);
    free_tree(tree);
    return 0;
}
