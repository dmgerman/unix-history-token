begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2002 Niels Provos<provos@citi.umich.edu>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TREE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TREE_H_
end_define

begin_comment
comment|/*  * This file defines data structures for different types of trees:  * splay trees and red-black trees.  *  * A splay tree is a self-organizing data structure.  Every operation  * on the tree causes a splay to happen.  The splay moves the requested  * node to the root of the tree and partly rebalances it.  *  * This has the benefit that request locality causes faster lookups as  * the requested nodes move to the top of the tree.  On the other hand,  * every lookup causes memory writes.  *  * The Balance Theorem bounds the total access time for m operations  * and n inserts on an initially empty tree as O((m + n)lg n).  The  * amortized cost for a sequence of m accesses to a splay tree is O(lg n);  *  * A red-black tree is a binary search tree with the node color as an  * extra attribute.  It fulfills a set of conditions:  *	- every search path from the root to a leaf consists of the  *	  same number of black nodes,  *	- each red node (except for the root) has a black parent,  *	- each leaf node is black.  *  * Every operation on a red-black tree is bounded as O(lg n).  * The maximum height of a red-black tree is 2lg (n+1).  */
end_comment

begin_define
define|#
directive|define
name|SPLAY_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {								\ 	struct type *sph_root;
comment|/* root of the tree */
value|\ }
end_define

begin_define
define|#
directive|define
name|SPLAY_INITIALIZER
parameter_list|(
name|root
parameter_list|)
define|\
value|{ NULL }
end_define

begin_define
define|#
directive|define
name|SPLAY_INIT
parameter_list|(
name|root
parameter_list|)
value|do {						\ 	(root)->sph_root = NULL;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|SPLAY_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {								\ 	struct type *spe_left;
comment|/* left element */
value|\ 	struct type *spe_right;
comment|/* right element */
value|\ }
end_define

begin_define
define|#
directive|define
name|SPLAY_LEFT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|(elm)->field.spe_left
end_define

begin_define
define|#
directive|define
name|SPLAY_RIGHT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|(elm)->field.spe_right
end_define

begin_define
define|#
directive|define
name|SPLAY_ROOT
parameter_list|(
name|head
parameter_list|)
value|(head)->sph_root
end_define

begin_define
define|#
directive|define
name|SPLAY_EMPTY
parameter_list|(
name|head
parameter_list|)
value|(SPLAY_ROOT(head) == NULL)
end_define

begin_comment
comment|/* SPLAY_ROTATE_{LEFT,RIGHT} expect that tmp hold SPLAY_{RIGHT,LEFT} */
end_comment

begin_define
define|#
directive|define
name|SPLAY_ROTATE_RIGHT
parameter_list|(
name|head
parameter_list|,
name|tmp
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	SPLAY_LEFT((head)->sph_root, field) = SPLAY_RIGHT(tmp, field);	\ 	SPLAY_RIGHT(tmp, field) = (head)->sph_root;			\ 	(head)->sph_root = tmp;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|SPLAY_ROTATE_LEFT
parameter_list|(
name|head
parameter_list|,
name|tmp
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	SPLAY_RIGHT((head)->sph_root, field) = SPLAY_LEFT(tmp, field);	\ 	SPLAY_LEFT(tmp, field) = (head)->sph_root;			\ 	(head)->sph_root = tmp;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|SPLAY_LINKLEFT
parameter_list|(
name|head
parameter_list|,
name|tmp
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	SPLAY_LEFT(tmp, field) = (head)->sph_root;			\ 	tmp = (head)->sph_root;						\ 	(head)->sph_root = SPLAY_LEFT((head)->sph_root, field);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|SPLAY_LINKRIGHT
parameter_list|(
name|head
parameter_list|,
name|tmp
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	SPLAY_RIGHT(tmp, field) = (head)->sph_root;			\ 	tmp = (head)->sph_root;						\ 	(head)->sph_root = SPLAY_RIGHT((head)->sph_root, field);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|SPLAY_ASSEMBLE
parameter_list|(
name|head
parameter_list|,
name|node
parameter_list|,
name|left
parameter_list|,
name|right
parameter_list|,
name|field
parameter_list|)
value|do {		\ 	SPLAY_RIGHT(left, field) = SPLAY_LEFT((head)->sph_root, field);	\ 	SPLAY_LEFT(right, field) = SPLAY_RIGHT((head)->sph_root, field);\ 	SPLAY_LEFT((head)->sph_root, field) = SPLAY_RIGHT(node, field);	\ 	SPLAY_RIGHT((head)->sph_root, field) = SPLAY_LEFT(node, field);	\ } while (0)
end_define

begin_comment
comment|/* Generates prototypes and inline functions */
end_comment

begin_define
define|#
directive|define
name|SPLAY_PROTOTYPE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|cmp
parameter_list|)
define|\
value|void name##_SPLAY(struct name *, struct type *);			\ void name##_SPLAY_MINMAX(struct name *, int);				\ 									\ static __inline void							\ name##_SPLAY_INSERT(struct name *head, struct type *elm)		\ {									\     if (SPLAY_EMPTY(head)) {						\ 	    SPLAY_LEFT(elm, field) = SPLAY_RIGHT(elm, field) = NULL;	\     } else {								\ 	    int __comp;							\ 	    name##_SPLAY(head, elm);					\ 	    __comp = (cmp)(elm, (head)->sph_root);			\ 	    if(__comp< 0) {						\ 		    SPLAY_LEFT(elm, field) = SPLAY_LEFT((head)->sph_root, field);\ 		    SPLAY_RIGHT(elm, field) = (head)->sph_root;		\ 		    SPLAY_LEFT((head)->sph_root, field) = NULL;		\ 	    } else if (__comp> 0) {					\ 		    SPLAY_RIGHT(elm, field) = SPLAY_RIGHT((head)->sph_root, field);\ 		    SPLAY_LEFT(elm, field) = (head)->sph_root;		\ 		    SPLAY_RIGHT((head)->sph_root, field) = NULL;	\ 	    } else							\ 		    return;						\     }									\     (head)->sph_root = (elm);						\ }									\ 									\ static __inline void							\ name##_SPLAY_REMOVE(struct name *head, struct type *elm)		\ {									\ 	struct type *__tmp;						\ 	if (SPLAY_EMPTY(head))						\ 		return;							\ 	name##_SPLAY(head, elm);					\ 	if ((cmp)(elm, (head)->sph_root) == 0) {			\ 		if (SPLAY_LEFT((head)->sph_root, field) == NULL) {	\ 			(head)->sph_root = SPLAY_RIGHT((head)->sph_root, field);\ 		} else {						\ 			__tmp = SPLAY_RIGHT((head)->sph_root, field);	\ 			(head)->sph_root = SPLAY_LEFT((head)->sph_root, field);\ 			name##_SPLAY(head, elm);			\ 			SPLAY_RIGHT((head)->sph_root, field) = __tmp;	\ 		}							\ 	}								\ }									\ 									\
comment|/* Finds the node with the same key as elm */
value|\ static __inline struct type *						\ name##_SPLAY_FIND(struct name *head, struct type *elm)			\ {									\ 	if (SPLAY_EMPTY(head))						\ 		return(NULL);						\ 	name##_SPLAY(head, elm);					\ 	if ((cmp)(elm, (head)->sph_root) == 0)				\ 		return (head->sph_root);				\ 	return (NULL);							\ }									\ 									\ static __inline struct type *						\ name##_SPLAY_NEXT(struct name *head, struct type *elm)			\ {									\ 	name##_SPLAY(head, elm);					\ 	if (SPLAY_RIGHT(elm, field) != NULL) {				\ 		elm = SPLAY_RIGHT(elm, field);				\ 		while (SPLAY_LEFT(elm, field) != NULL) {		\ 			elm = SPLAY_LEFT(elm, field);			\ 		}							\ 	} else								\ 		elm = NULL;						\ 	return (elm);							\ }									\ 									\ static __inline struct type *						\ name##_SPLAY_MIN_MAX(struct name *head, int val)			\ {									\ 	name##_SPLAY_MINMAX(head, val);					\         return (SPLAY_ROOT(head));					\ }
end_define

begin_comment
comment|/* Main splay operation.  * Moves node close to the key of elm to top  */
end_comment

begin_define
define|#
directive|define
name|SPLAY_GENERATE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|cmp
parameter_list|)
define|\
value|void name##_SPLAY(struct name *head, struct type *elm)			\ {									\ 	struct type __node, *__left, *__right, *__tmp;			\ 	int __comp;							\ \ 	SPLAY_LEFT(&__node, field) = SPLAY_RIGHT(&__node, field) = NULL;\ 	__left = __right =&__node;					\ \ 	while ((__comp = (cmp)(elm, (head)->sph_root))) {		\ 		if (__comp< 0) {					\ 			__tmp = SPLAY_LEFT((head)->sph_root, field);	\ 			if (__tmp == NULL)				\ 				break;					\ 			if ((cmp)(elm, __tmp)< 0){			\ 				SPLAY_ROTATE_RIGHT(head, __tmp, field);	\ 				if (SPLAY_LEFT((head)->sph_root, field) == NULL)\ 					break;				\ 			}						\ 			SPLAY_LINKLEFT(head, __right, field);		\ 		} else if (__comp> 0) {				\ 			__tmp = SPLAY_RIGHT((head)->sph_root, field);	\ 			if (__tmp == NULL)				\ 				break;					\ 			if ((cmp)(elm, __tmp)> 0){			\ 				SPLAY_ROTATE_LEFT(head, __tmp, field);	\ 				if (SPLAY_RIGHT((head)->sph_root, field) == NULL)\ 					break;				\ 			}						\ 			SPLAY_LINKRIGHT(head, __left, field);		\ 		}							\ 	}								\ 	SPLAY_ASSEMBLE(head,&__node, __left, __right, field);		\ }									\ 									\
comment|/* Splay with either the minimum or the maximum element			\  * Used to find minimum or maximum element in tree.			\  */
value|\ void name##_SPLAY_MINMAX(struct name *head, int __comp) \ {									\ 	struct type __node, *__left, *__right, *__tmp;			\ \ 	SPLAY_LEFT(&__node, field) = SPLAY_RIGHT(&__node, field) = NULL;\ 	__left = __right =&__node;					\ \ 	while (1) {							\ 		if (__comp< 0) {					\ 			__tmp = SPLAY_LEFT((head)->sph_root, field);	\ 			if (__tmp == NULL)				\ 				break;					\ 			if (__comp< 0){				\ 				SPLAY_ROTATE_RIGHT(head, __tmp, field);	\ 				if (SPLAY_LEFT((head)->sph_root, field) == NULL)\ 					break;				\ 			}						\ 			SPLAY_LINKLEFT(head, __right, field);		\ 		} else if (__comp> 0) {				\ 			__tmp = SPLAY_RIGHT((head)->sph_root, field);	\ 			if (__tmp == NULL)				\ 				break;					\ 			if (__comp> 0) {				\ 				SPLAY_ROTATE_LEFT(head, __tmp, field);	\ 				if (SPLAY_RIGHT((head)->sph_root, field) == NULL)\ 					break;				\ 			}						\ 			SPLAY_LINKRIGHT(head, __left, field);		\ 		}							\ 	}								\ 	SPLAY_ASSEMBLE(head,&__node, __left, __right, field);		\ }
end_define

begin_define
define|#
directive|define
name|SPLAY_NEGINF
value|-1
end_define

begin_define
define|#
directive|define
name|SPLAY_INF
value|1
end_define

begin_define
define|#
directive|define
name|SPLAY_INSERT
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|name##_SPLAY_INSERT(x, y)
end_define

begin_define
define|#
directive|define
name|SPLAY_REMOVE
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|name##_SPLAY_REMOVE(x, y)
end_define

begin_define
define|#
directive|define
name|SPLAY_FIND
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|name##_SPLAY_FIND(x, y)
end_define

begin_define
define|#
directive|define
name|SPLAY_NEXT
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|name##_SPLAY_NEXT(x, y)
end_define

begin_define
define|#
directive|define
name|SPLAY_MIN
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|)
value|(SPLAY_EMPTY(x) ? NULL	\ 					: name##_SPLAY_MIN_MAX(x, SPLAY_NEGINF))
end_define

begin_define
define|#
directive|define
name|SPLAY_MAX
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|)
value|(SPLAY_EMPTY(x) ? NULL	\ 					: name##_SPLAY_MIN_MAX(x, SPLAY_INF))
end_define

begin_define
define|#
directive|define
name|SPLAY_FOREACH
parameter_list|(
name|x
parameter_list|,
name|name
parameter_list|,
name|head
parameter_list|)
define|\
value|for ((x) = SPLAY_MIN(name, head);				\ 	     (x) != NULL;						\ 	     (x) = SPLAY_NEXT(name, head, x))
end_define

begin_comment
comment|/* Macros that define a red-back tree */
end_comment

begin_define
define|#
directive|define
name|RB_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {								\ 	struct type *rbh_root;
comment|/* root of the tree */
value|\ }
end_define

begin_define
define|#
directive|define
name|RB_INITIALIZER
parameter_list|(
name|root
parameter_list|)
define|\
value|{ NULL }
end_define

begin_define
define|#
directive|define
name|RB_INIT
parameter_list|(
name|root
parameter_list|)
value|do {						\ 	(root)->rbh_root = NULL;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|RB_BLACK
value|0
end_define

begin_define
define|#
directive|define
name|RB_RED
value|1
end_define

begin_define
define|#
directive|define
name|RB_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {								\ 	struct type *rbe_left;
comment|/* left element */
value|\ 	struct type *rbe_right;
comment|/* right element */
value|\ 	struct type *rbe_parent;
comment|/* parent element */
value|\ 	int rbe_color;
comment|/* node color */
value|\ }
end_define

begin_define
define|#
directive|define
name|RB_LEFT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|(elm)->field.rbe_left
end_define

begin_define
define|#
directive|define
name|RB_RIGHT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|(elm)->field.rbe_right
end_define

begin_define
define|#
directive|define
name|RB_PARENT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|(elm)->field.rbe_parent
end_define

begin_define
define|#
directive|define
name|RB_COLOR
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|(elm)->field.rbe_color
end_define

begin_define
define|#
directive|define
name|RB_ROOT
parameter_list|(
name|head
parameter_list|)
value|(head)->rbh_root
end_define

begin_define
define|#
directive|define
name|RB_EMPTY
parameter_list|(
name|head
parameter_list|)
value|(RB_ROOT(head) == NULL)
end_define

begin_define
define|#
directive|define
name|RB_SET
parameter_list|(
name|elm
parameter_list|,
name|parent
parameter_list|,
name|field
parameter_list|)
value|do {					\ 	RB_PARENT(elm, field) = parent;					\ 	RB_LEFT(elm, field) = RB_RIGHT(elm, field) = NULL;		\ 	RB_COLOR(elm, field) = RB_RED;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|RB_SET_BLACKRED
parameter_list|(
name|black
parameter_list|,
name|red
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	RB_COLOR(black, field) = RB_BLACK;				\ 	RB_COLOR(red, field) = RB_RED;					\ } while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RB_AUGMENT
end_ifndef

begin_define
define|#
directive|define
name|RB_AUGMENT
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RB_ROTATE_LEFT
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|tmp
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	(tmp) = RB_RIGHT(elm, field);					\ 	if ((RB_RIGHT(elm, field) = RB_LEFT(tmp, field))) {		\ 		RB_PARENT(RB_LEFT(tmp, field), field) = (elm);		\ 	}								\ 	RB_AUGMENT(elm);						\ 	if ((RB_PARENT(tmp, field) = RB_PARENT(elm, field))) {		\ 		if ((elm) == RB_LEFT(RB_PARENT(elm, field), field))	\ 			RB_LEFT(RB_PARENT(elm, field), field) = (tmp);	\ 		else							\ 			RB_RIGHT(RB_PARENT(elm, field), field) = (tmp);	\ 		RB_AUGMENT(RB_PARENT(elm, field));			\ 	} else								\ 		(head)->rbh_root = (tmp);				\ 	RB_LEFT(tmp, field) = (elm);					\ 	RB_PARENT(elm, field) = (tmp);					\ 	RB_AUGMENT(tmp);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|RB_ROTATE_RIGHT
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|tmp
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	(tmp) = RB_LEFT(elm, field);					\ 	if ((RB_LEFT(elm, field) = RB_RIGHT(tmp, field))) {		\ 		RB_PARENT(RB_RIGHT(tmp, field), field) = (elm);		\ 	}								\ 	RB_AUGMENT(elm);						\ 	if ((RB_PARENT(tmp, field) = RB_PARENT(elm, field))) {		\ 		if ((elm) == RB_LEFT(RB_PARENT(elm, field), field))	\ 			RB_LEFT(RB_PARENT(elm, field), field) = (tmp);	\ 		else							\ 			RB_RIGHT(RB_PARENT(elm, field), field) = (tmp);	\ 		RB_AUGMENT(RB_PARENT(elm, field));			\ 	} else								\ 		(head)->rbh_root = (tmp);				\ 	RB_RIGHT(tmp, field) = (elm);					\ 	RB_PARENT(elm, field) = (tmp);					\ 	RB_AUGMENT(tmp);						\ } while (0)
end_define

begin_comment
comment|/* Generates prototypes and inline functions */
end_comment

begin_define
define|#
directive|define
name|RB_PROTOTYPE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|cmp
parameter_list|)
define|\
value|void name##_RB_INSERT_COLOR(struct name *, struct type *);	\ void name##_RB_REMOVE_COLOR(struct name *, struct type *, struct type *);\ void name##_RB_REMOVE(struct name *, struct type *);			\ struct type *name##_RB_INSERT(struct name *, struct type *);		\ struct type *name##_RB_FIND(struct name *, struct type *);		\ struct type *name##_RB_NEXT(struct name *, struct type *);		\ struct type *name##_RB_MINMAX(struct name *, int);
end_define

begin_comment
unit|\ 									\
comment|/* Main rb operation.  * Moves node close to the key of elm to top  */
end_comment

begin_define
define|#
directive|define
name|RB_GENERATE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|cmp
parameter_list|)
define|\
value|void									\ name##_RB_INSERT_COLOR(struct name *head, struct type *elm)		\ {									\ 	struct type *parent, *gparent, *tmp;				\ 	while ((parent = RB_PARENT(elm, field))&&			\ 	    RB_COLOR(parent, field) == RB_RED) {			\ 		gparent = RB_PARENT(parent, field);			\ 		if (parent == RB_LEFT(gparent, field)) {		\ 			tmp = RB_RIGHT(gparent, field);			\ 			if (tmp&& RB_COLOR(tmp, field) == RB_RED) {	\ 				RB_COLOR(tmp, field) = RB_BLACK;	\ 				RB_SET_BLACKRED(parent, gparent, field);\ 				elm = gparent;				\ 				continue;				\ 			}						\ 			if (RB_RIGHT(parent, field) == elm) {		\ 				RB_ROTATE_LEFT(head, parent, tmp, field);\ 				tmp = parent;				\ 				parent = elm;				\ 				elm = tmp;				\ 			}						\ 			RB_SET_BLACKRED(parent, gparent, field);	\ 			RB_ROTATE_RIGHT(head, gparent, tmp, field);	\ 		} else {						\ 			tmp = RB_LEFT(gparent, field);			\ 			if (tmp&& RB_COLOR(tmp, field) == RB_RED) {	\ 				RB_COLOR(tmp, field) = RB_BLACK;	\ 				RB_SET_BLACKRED(parent, gparent, field);\ 				elm = gparent;				\ 				continue;				\ 			}						\ 			if (RB_LEFT(parent, field) == elm) {		\ 				RB_ROTATE_RIGHT(head, parent, tmp, field);\ 				tmp = parent;				\ 				parent = elm;				\ 				elm = tmp;				\ 			}						\ 			RB_SET_BLACKRED(parent, gparent, field);	\ 			RB_ROTATE_LEFT(head, gparent, tmp, field);	\ 		}							\ 	}								\ 	RB_COLOR(head->rbh_root, field) = RB_BLACK;			\ }									\ 									\ void									\ name##_RB_REMOVE_COLOR(struct name *head, struct type *parent, struct type *elm) \ {									\ 	struct type *tmp;						\ 	while ((elm == NULL || RB_COLOR(elm, field) == RB_BLACK)&&	\ 	    elm != RB_ROOT(head)) {					\ 		if (RB_LEFT(parent, field) == elm) {			\ 			tmp = RB_RIGHT(parent, field);			\ 			if (RB_COLOR(tmp, field) == RB_RED) {		\ 				RB_SET_BLACKRED(tmp, parent, field);	\ 				RB_ROTATE_LEFT(head, parent, tmp, field);\ 				tmp = RB_RIGHT(parent, field);		\ 			}						\ 			if ((RB_LEFT(tmp, field) == NULL ||		\ 			    RB_COLOR(RB_LEFT(tmp, field), field) == RB_BLACK)&&\ 			    (RB_RIGHT(tmp, field) == NULL ||		\ 			    RB_COLOR(RB_RIGHT(tmp, field), field) == RB_BLACK)) {\ 				RB_COLOR(tmp, field) = RB_RED;		\ 				elm = parent;				\ 				parent = RB_PARENT(elm, field);		\ 			} else {					\ 				if (RB_RIGHT(tmp, field) == NULL ||	\ 				    RB_COLOR(RB_RIGHT(tmp, field), field) == RB_BLACK) {\ 					struct type *oleft;		\ 					if ((oleft = RB_LEFT(tmp, field)))\ 						RB_COLOR(oleft, field) = RB_BLACK;\ 					RB_COLOR(tmp, field) = RB_RED;	\ 					RB_ROTATE_RIGHT(head, tmp, oleft, field);\ 					tmp = RB_RIGHT(parent, field);	\ 				}					\ 				RB_COLOR(tmp, field) = RB_COLOR(parent, field);\ 				RB_COLOR(parent, field) = RB_BLACK;	\ 				if (RB_RIGHT(tmp, field))		\ 					RB_COLOR(RB_RIGHT(tmp, field), field) = RB_BLACK;\ 				RB_ROTATE_LEFT(head, parent, tmp, field);\ 				elm = RB_ROOT(head);			\ 				break;					\ 			}						\ 		} else {						\ 			tmp = RB_LEFT(parent, field);			\ 			if (RB_COLOR(tmp, field) == RB_RED) {		\ 				RB_SET_BLACKRED(tmp, parent, field);	\ 				RB_ROTATE_RIGHT(head, parent, tmp, field);\ 				tmp = RB_LEFT(parent, field);		\ 			}						\ 			if ((RB_LEFT(tmp, field) == NULL ||		\ 			    RB_COLOR(RB_LEFT(tmp, field), field) == RB_BLACK)&&\ 			    (RB_RIGHT(tmp, field) == NULL ||		\ 			    RB_COLOR(RB_RIGHT(tmp, field), field) == RB_BLACK)) {\ 				RB_COLOR(tmp, field) = RB_RED;		\ 				elm = parent;				\ 				parent = RB_PARENT(elm, field);		\ 			} else {					\ 				if (RB_LEFT(tmp, field) == NULL ||	\ 				    RB_COLOR(RB_LEFT(tmp, field), field) == RB_BLACK) {\ 					struct type *oright;		\ 					if ((oright = RB_RIGHT(tmp, field)))\ 						RB_COLOR(oright, field) = RB_BLACK;\ 					RB_COLOR(tmp, field) = RB_RED;	\ 					RB_ROTATE_LEFT(head, tmp, oright, field);\ 					tmp = RB_LEFT(parent, field);	\ 				}					\ 				RB_COLOR(tmp, field) = RB_COLOR(parent, field);\ 				RB_COLOR(parent, field) = RB_BLACK;	\ 				if (RB_LEFT(tmp, field))		\ 					RB_COLOR(RB_LEFT(tmp, field), field) = RB_BLACK;\ 				RB_ROTATE_RIGHT(head, parent, tmp, field);\ 				elm = RB_ROOT(head);			\ 				break;					\ 			}						\ 		}							\ 	}								\ 	if (elm)							\ 		RB_COLOR(elm, field) = RB_BLACK;			\ }									\ 									\ void									\ name##_RB_REMOVE(struct name *head, struct type *elm)			\ {									\ 	struct type *child, *parent;					\ 	int color;							\ 	if (RB_LEFT(elm, field) == NULL)				\ 		child = RB_RIGHT(elm, field);				\ 	else if (RB_RIGHT(elm, field) == NULL)				\ 		child = RB_LEFT(elm, field);				\ 	else {								\ 		struct type *old = elm, *left;				\ 		elm = RB_RIGHT(elm, field);				\ 		while ((left = RB_LEFT(elm, field)))			\ 			elm = left;					\ 		child = RB_RIGHT(elm, field);				\ 		parent = RB_PARENT(elm, field);				\ 		color = RB_COLOR(elm, field);				\ 		if (child)						\ 			RB_PARENT(child, field) = parent;		\ 		if (parent) {						\ 			if (RB_LEFT(parent, field) == elm)		\ 				RB_LEFT(parent, field) = child;		\ 			else						\ 				RB_RIGHT(parent, field) = child;	\ 			RB_AUGMENT(parent);				\ 		} else							\ 			RB_ROOT(head) = child;				\ 		if (RB_PARENT(elm, field) == old)			\ 			parent = elm;					\ 		(elm)->field = (old)->field;				\ 		if (RB_PARENT(old, field)) {				\ 			if (RB_LEFT(RB_PARENT(old, field), field) == old)\ 				RB_LEFT(RB_PARENT(old, field), field) = elm;\ 			else						\ 				RB_RIGHT(RB_PARENT(old, field), field) = elm;\ 			RB_AUGMENT(RB_PARENT(old, field));		\ 		} else							\ 			RB_ROOT(head) = elm;				\ 		RB_PARENT(RB_LEFT(old, field), field) = elm;		\ 		if (RB_RIGHT(old, field))				\ 			RB_PARENT(RB_RIGHT(old, field), field) = elm;	\ 		if (parent) {						\ 			left = parent;					\ 			do {						\ 				RB_AUGMENT(left);			\ 			} while ((left = RB_PARENT(left, field)));	\ 		}							\ 		goto color;						\ 	}								\ 	parent = RB_PARENT(elm, field);					\ 	color = RB_COLOR(elm, field);					\ 	if (child)							\ 		RB_PARENT(child, field) = parent;			\ 	if (parent) {							\ 		if (RB_LEFT(parent, field) == elm)			\ 			RB_LEFT(parent, field) = child;			\ 		else							\ 			RB_RIGHT(parent, field) = child;		\ 		RB_AUGMENT(parent);					\ 	} else								\ 		RB_ROOT(head) = child;					\ color:									\ 	if (color == RB_BLACK)						\ 		name##_RB_REMOVE_COLOR(head, parent, child);		\ }									\ 									\
comment|/* Inserts a node into the RB tree */
value|\ struct type *								\ name##_RB_INSERT(struct name *head, struct type *elm)			\ {									\ 	struct type *tmp;						\ 	struct type *parent = NULL;					\ 	int comp = 0;							\ 	tmp = RB_ROOT(head);						\ 	while (tmp) {							\ 		parent = tmp;						\ 		comp = (cmp)(elm, parent);				\ 		if (comp< 0)						\ 			tmp = RB_LEFT(tmp, field);			\ 		else if (comp> 0)					\ 			tmp = RB_RIGHT(tmp, field);			\ 		else							\ 			return (tmp);					\ 	}								\ 	RB_SET(elm, parent, field);					\ 	if (parent != NULL) {						\ 		if (comp< 0)						\ 			RB_LEFT(parent, field) = elm;			\ 		else							\ 			RB_RIGHT(parent, field) = elm;			\ 		RB_AUGMENT(parent);					\ 	} else								\ 		RB_ROOT(head) = elm;					\ 	name##_RB_INSERT_COLOR(head, elm);				\ 	return (NULL);							\ }									\ 									\
comment|/* Finds the node with the same key as elm */
value|\ struct type *								\ name##_RB_FIND(struct name *head, struct type *elm)			\ {									\ 	struct type *tmp = RB_ROOT(head);				\ 	int comp;							\ 	while (tmp) {							\ 		comp = cmp(elm, tmp);					\ 		if (comp< 0)						\ 			tmp = RB_LEFT(tmp, field);			\ 		else if (comp> 0)					\ 			tmp = RB_RIGHT(tmp, field);			\ 		else							\ 			return (tmp);					\ 	}								\ 	return (NULL);							\ }									\ 									\ struct type *								\ name##_RB_NEXT(struct name *head, struct type *elm)			\ {									\ 	if (RB_RIGHT(elm, field)) {					\ 		elm = RB_RIGHT(elm, field);				\ 		while (RB_LEFT(elm, field))				\ 			elm = RB_LEFT(elm, field);			\ 	} else {							\ 		if (RB_PARENT(elm, field)&&				\ 		    (elm == RB_LEFT(RB_PARENT(elm, field), field)))	\ 			elm = RB_PARENT(elm, field);			\ 		else {							\ 			while (RB_PARENT(elm, field)&&			\ 			    (elm == RB_RIGHT(RB_PARENT(elm, field), field)))\ 				elm = RB_PARENT(elm, field);		\ 			elm = RB_PARENT(elm, field);			\ 		}							\ 	}								\ 	return (elm);							\ }									\ 									\ struct type *								\ name##_RB_MINMAX(struct name *head, int val)				\ {									\ 	struct type *tmp = RB_ROOT(head);				\ 	struct type *parent = NULL;					\ 	while (tmp) {							\ 		parent = tmp;						\ 		if (val< 0)						\ 			tmp = RB_LEFT(tmp, field);			\ 		else							\ 			tmp = RB_RIGHT(tmp, field);			\ 	}								\ 	return (parent);						\ }
end_define

begin_define
define|#
directive|define
name|RB_NEGINF
value|-1
end_define

begin_define
define|#
directive|define
name|RB_INF
value|1
end_define

begin_define
define|#
directive|define
name|RB_INSERT
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|name##_RB_INSERT(x, y)
end_define

begin_define
define|#
directive|define
name|RB_REMOVE
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|name##_RB_REMOVE(x, y)
end_define

begin_define
define|#
directive|define
name|RB_FIND
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|name##_RB_FIND(x, y)
end_define

begin_define
define|#
directive|define
name|RB_NEXT
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|name##_RB_NEXT(x, y)
end_define

begin_define
define|#
directive|define
name|RB_MIN
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|)
value|name##_RB_MINMAX(x, RB_NEGINF)
end_define

begin_define
define|#
directive|define
name|RB_MAX
parameter_list|(
name|name
parameter_list|,
name|x
parameter_list|)
value|name##_RB_MINMAX(x, RB_INF)
end_define

begin_define
define|#
directive|define
name|RB_FOREACH
parameter_list|(
name|x
parameter_list|,
name|name
parameter_list|,
name|head
parameter_list|)
define|\
value|for ((x) = RB_MIN(name, head);					\ 	     (x) != NULL;						\ 	     (x) = name##_RB_NEXT(head, x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_TREE_H_ */
end_comment

end_unit

