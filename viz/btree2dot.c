#include <stdio.h>
#include "../pokemon_dyntables.h"

// Copied wholesale from this site:
// https://eli.thegreenplace.net/2009/11/23/visualizing-binary-trees-with-graphviz

void bst_print_dot_null(const char *key, int nullcount, FILE* stream)
{
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    \"%s\" -> null%d;\n", key, nullcount);
}

void bst_print_dot_aux(btree *node, FILE* stream)
{
    static int nullcount = 0;
    const char *name = pokemon_names[node->val & 0x7FF];

    if (node->l)
    {
        const char *next_name = pokemon_names[node->l->val & 0x7FF];
        fprintf(stream, "    \"%s\" -> \"%s\";\n", name, next_name);
        bst_print_dot_aux(node->l, stream);
    }
    else
        bst_print_dot_null(name, nullcount++, stream);

    if (node->r)
    {
        const char *next_name = pokemon_names[node->r->val & 0x7FF];
        fprintf(stream, "    \"%s\" -> \"%s\";\n", name, next_name);
        bst_print_dot_aux(node->r, stream);
    }
    else
        bst_print_dot_null(name, nullcount++, stream);
}

void bst_print_dot(btree *tree, FILE* stream)
{
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->r && !tree->l)
        fprintf(stream, "    \"%s\";\n", pokemon_names[tree->val & 0x7FF]);
    else
        bst_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}

int main(void) {
  bst_print_dot(pokemon_hashed_names_btree, stdout);
  return 0;
}

