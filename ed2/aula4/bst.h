#pragma once

typedef struct bst bst;

bst* BST_init();

bst* BST_insert(bst* t, int key);

int BST_get_key(bst* t);

void BST_pre_treverse(bst* t, void (*cb) (bst*));
void BST_pre_treverse_it(bst* t, void (*cb) (bst*));

void BST_in_treverse(bst* t, void (*cb) (bst*));
void BST_in_treverse_it(bst* t, void (*cb) (bst*));

void BST_post_treverse(bst* t, void (*cb) (bst*));
void BST_post_treverse_it(bst* t, void (*cb) (bst*));

void BST_level_treverse(bst* t, void (*cb) (bst*));

int BST_height(bst* t);

bst* BST_delete(bst* t);