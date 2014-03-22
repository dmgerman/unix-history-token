begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tree.h -- AVL trees (in the spirit of BSD's 'queue.h')	-*- C -*-	*/
end_comment

begin_comment
comment|/* Copyright (c) 2005 Ian Piumarta  *   * All rights reserved.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the 'Software'), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, and/or sell copies of the  * Software, and to permit persons to whom the Software is furnished to do so,  * provided that the above copyright notice(s) and this permission notice appear  * in all copies of the Software and that both the above copyright notice(s) and  * this permission notice appear in supporting documentation.  *  * THE SOFTWARE IS PROVIDED 'AS IS'.  USE ENTIRELY AT YOUR OWN RISK.  */
end_comment

begin_comment
comment|/* This file defines an AVL balanced binary tree [Georgii M. Adelson-Velskii and  * Evgenii M. Landis, 'An algorithm for the organization of information',  * Doklady Akademii Nauk SSSR, 146:263-266, 1962 (Russian).  Also in Myron  * J. Ricci (trans.), Soviet Math, 3:1259-1263, 1962 (English)].  *   * An AVL tree is headed by pointers to the root node and to a function defining  * the ordering relation between nodes.  Each node contains an arbitrary payload  * plus three fields per tree entry: the depth of the subtree for which it forms  * the root and two pointers to child nodes (singly-linked for minimum space, at  * the expense of direct access to the parent node given a pointer to one of the  * children).  The tree is rebalanced after every insertion or removal.  The  * tree may be traversed in two directions: forward (in-order left-to-right) and  * reverse (in-order, right-to-left).  *   * Because of the recursive nature of many of the operations on trees it is  * necessary to define a number of helper functions for each type of tree node.  * The macro TREE_DEFINE(node_tag, entry_name) defines these functions with  * unique names according to the node_tag.  This macro should be invoked,  * thereby defining the necessary functions, once per node tag in the program.  *   * For details on the use of these macros, see the tree(3) manual page.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__tree_h
end_ifndef

begin_define
define|#
directive|define
name|__tree_h
end_define

begin_define
define|#
directive|define
name|TREE_DELTA_MAX
value|1
end_define

begin_define
define|#
directive|define
name|TREE_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {					\     struct type	*avl_left;			\     struct type	*avl_right;			\     int		 avl_height;			\   }
end_define

begin_define
define|#
directive|define
name|TREE_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {						\     struct type *th_root;				\     int  (*th_cmp)(struct type *lhs, struct type *rhs);	\   }
end_define

begin_define
define|#
directive|define
name|TREE_INITIALIZER
parameter_list|(
name|cmp
parameter_list|)
value|{ 0, cmp }
end_define

begin_define
define|#
directive|define
name|TREE_DELTA
parameter_list|(
name|self
parameter_list|,
name|field
parameter_list|)
define|\
value|(( (((self)->field.avl_left)  ? (self)->field.avl_left->field.avl_height  : 0))	\    - (((self)->field.avl_right) ? (self)->field.avl_right->field.avl_height : 0))
end_define

begin_comment
comment|/* Recursion prevents the following from being defined as macros. */
end_comment

begin_define
define|#
directive|define
name|TREE_DEFINE
parameter_list|(
name|node
parameter_list|,
name|field
parameter_list|)
define|\ 													\
value|struct node *TREE_BALANCE_##node##_##field(struct node *);						\ 													\   struct node *TREE_ROTL_##node##_##field(struct node *self)						\   {													\     struct node *r= self->field.avl_right;								\     self->field.avl_right= r->field.avl_left;								\     r->field.avl_left= TREE_BALANCE_##node##_##field(self);						\     return TREE_BALANCE_##node##_##field(r);								\   }													\ 													\   struct node *TREE_ROTR_##node##_##field(struct node *self)						\   {													\     struct node *l= self->field.avl_left;								\     self->field.avl_left= l->field.avl_right;								\     l->field.avl_right= TREE_BALANCE_##node##_##field(self);						\     return TREE_BALANCE_##node##_##field(l);								\   }													\ 													\   struct node *TREE_BALANCE_##node##_##field(struct node *self)						\   {													\     int delta= TREE_DELTA(self, field);									\ 													\     if (delta< -TREE_DELTA_MAX)									\       {													\ 	if (TREE_DELTA(self->field.avl_right, field)> 0)						\ 	  self->field.avl_right= TREE_ROTR_##node##_##field(self->field.avl_right);			\ 	return TREE_ROTL_##node##_##field(self);							\       }													\     else if (delta> TREE_DELTA_MAX)									\       {													\ 	if (TREE_DELTA(self->field.avl_left, field)< 0)						\ 	  self->field.avl_left= TREE_ROTL_##node##_##field(self->field.avl_left);			\ 	return TREE_ROTR_##node##_##field(self);							\       }													\     self->field.avl_height= 0;										\     if (self->field.avl_left&& (self->field.avl_left->field.avl_height> self->field.avl_height))	\       self->field.avl_height= self->field.avl_left->field.avl_height;					\     if (self->field.avl_right&& (self->field.avl_right->field.avl_height> self->field.avl_height))	\       self->field.avl_height= self->field.avl_right->field.avl_height;					\     self->field.avl_height += 1;									\     return self;											\   }													\ 													\   struct node *TREE_INSERT_##node##_##field								\     (struct node *self, struct node *elm, int (*compare)(struct node *lhs, struct node *rhs))		\   {													\     if (!self)												\       return elm;											\     if (compare(elm, self)< 0)										\       self->field.avl_left= TREE_INSERT_##node##_##field(self->field.avl_left, elm, compare);		\     else												\       self->field.avl_right= TREE_INSERT_##node##_##field(self->field.avl_right, elm, compare);		\     return TREE_BALANCE_##node##_##field(self);								\   }													\ 													\   struct node *TREE_FIND_##node##_##field								\     (struct node *self, struct node *elm, int (*compare)(struct node *lhs, struct node *rhs))		\   {													\     if (!self)												\       return 0;												\     if (compare(elm, self) == 0)									\       return self;											\     if (compare(elm, self)< 0)										\       return TREE_FIND_##node##_##field(self->field.avl_left, elm, compare);				\     else												\       return TREE_FIND_##node##_##field(self->field.avl_right, elm, compare);				\   }													\ 													\   struct node *TREE_MOVE_RIGHT(struct node *self, struct node *rhs)					\   {													\     if (!self)												\       return rhs;											\     self->field.avl_right= TREE_MOVE_RIGHT(self->field.avl_right, rhs);					\     return TREE_BALANCE_##node##_##field(self);								\   }													\ 													\   struct node *TREE_REMOVE_##node##_##field								\     (struct node *self, struct node *elm, int (*compare)(struct node *lhs, struct node *rhs))		\   {													\     if (!self) return 0;										\ 													\     if (compare(elm, self) == 0)									\       {													\ 	struct node *tmp= TREE_MOVE_RIGHT(self->field.avl_left, self->field.avl_right);			\ 	self->field.avl_left= 0;									\ 	self->field.avl_right= 0;									\ 	return tmp;											\       }													\     if (compare(elm, self)< 0)										\       self->field.avl_left= TREE_REMOVE_##node##_##field(self->field.avl_left, elm, compare);		\     else												\       self->field.avl_right= TREE_REMOVE_##node##_##field(self->field.avl_right, elm, compare);		\     return TREE_BALANCE_##node##_##field(self);								\   }													\ 													\   void TREE_FORWARD_APPLY_ALL_##node##_##field								\     (struct node *self, void (*function)(struct node *node, void *data), void *data)			\   {													\     if (self)												\       {													\ 	TREE_FORWARD_APPLY_ALL_##node##_##field(self->field.avl_left, function, data);			\ 	function(self, data);										\ 	TREE_FORWARD_APPLY_ALL_##node##_##field(self->field.avl_right, function, data);			\       }													\   }													\ 													\   void TREE_REVERSE_APPLY_ALL_##node##_##field								\     (struct node *self, void (*function)(struct node *node, void *data), void *data)			\   {													\     if (self)												\       {													\ 	TREE_REVERSE_APPLY_ALL_##node##_##field(self->field.avl_right, function, data);			\ 	function(self, data);										\ 	TREE_REVERSE_APPLY_ALL_##node##_##field(self->field.avl_left, function, data);			\       }													\   }
end_define

begin_define
define|#
directive|define
name|TREE_INSERT
parameter_list|(
name|head
parameter_list|,
name|node
parameter_list|,
name|field
parameter_list|,
name|elm
parameter_list|)
define|\
value|((head)->th_root= TREE_INSERT_##node##_##field((head)->th_root, (elm), (head)->th_cmp))
end_define

begin_define
define|#
directive|define
name|TREE_FIND
parameter_list|(
name|head
parameter_list|,
name|node
parameter_list|,
name|field
parameter_list|,
name|elm
parameter_list|)
define|\
value|(TREE_FIND_##node##_##field((head)->th_root, (elm), (head)->th_cmp))
end_define

begin_define
define|#
directive|define
name|TREE_REMOVE
parameter_list|(
name|head
parameter_list|,
name|node
parameter_list|,
name|field
parameter_list|,
name|elm
parameter_list|)
define|\
value|((head)->th_root= TREE_REMOVE_##node##_##field((head)->th_root, (elm), (head)->th_cmp))
end_define

begin_define
define|#
directive|define
name|TREE_DEPTH
parameter_list|(
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|((head)->th_root->field.avl_height)
end_define

begin_define
define|#
directive|define
name|TREE_FORWARD_APPLY
parameter_list|(
name|head
parameter_list|,
name|node
parameter_list|,
name|field
parameter_list|,
name|function
parameter_list|,
name|data
parameter_list|)
define|\
value|TREE_FORWARD_APPLY_ALL_##node##_##field((head)->th_root, function, data)
end_define

begin_define
define|#
directive|define
name|TREE_REVERSE_APPLY
parameter_list|(
name|head
parameter_list|,
name|node
parameter_list|,
name|field
parameter_list|,
name|function
parameter_list|,
name|data
parameter_list|)
define|\
value|TREE_REVERSE_APPLY_ALL_##node##_##field((head)->th_root, function, data)
end_define

begin_define
define|#
directive|define
name|TREE_INIT
parameter_list|(
name|head
parameter_list|,
name|cmp
parameter_list|)
value|do {		\     (head)->th_root= 0;				\     (head)->th_cmp= (cmp);			\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __tree_h */
end_comment

end_unit

