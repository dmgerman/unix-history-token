begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * A Pairing Heap implementation.  *  * "The Pairing Heap: A New Form of Self-Adjusting Heap"  * https://www.cs.cmu.edu/~sleator/papers/pairing-heaps.pdf  *  * With auxiliary twopass list, described in a follow on paper.  *  * "Pairing Heaps: Experiments and Analysis"  * http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.106.2988&rep=rep1&type=pdf  *  *******************************************************************************  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PH_H_
end_ifndef

begin_define
define|#
directive|define
name|PH_H_
end_define

begin_comment
comment|/* Node structure. */
end_comment

begin_define
define|#
directive|define
name|phn
parameter_list|(
name|a_type
parameter_list|)
define|\
value|struct {								\ 	a_type	*phn_prev;						\ 	a_type	*phn_next;						\ 	a_type	*phn_lchild;						\ }
end_define

begin_comment
comment|/* Root structure. */
end_comment

begin_define
define|#
directive|define
name|ph
parameter_list|(
name|a_type
parameter_list|)
define|\
value|struct {								\ 	a_type	*ph_root;						\ }
end_define

begin_comment
comment|/* Internal utility macros. */
end_comment

begin_define
define|#
directive|define
name|phn_lchild_get
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn
parameter_list|)
define|\
value|(a_phn->a_field.phn_lchild)
end_define

begin_define
define|#
directive|define
name|phn_lchild_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn
parameter_list|,
name|a_lchild
parameter_list|)
value|do {		\ 	a_phn->a_field.phn_lchild = a_lchild;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|phn_next_get
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn
parameter_list|)
define|\
value|(a_phn->a_field.phn_next)
end_define

begin_define
define|#
directive|define
name|phn_prev_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn
parameter_list|,
name|a_prev
parameter_list|)
value|do {		\ 	a_phn->a_field.phn_prev = a_prev;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|phn_prev_get
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn
parameter_list|)
define|\
value|(a_phn->a_field.phn_prev)
end_define

begin_define
define|#
directive|define
name|phn_next_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn
parameter_list|,
name|a_next
parameter_list|)
value|do {		\ 	a_phn->a_field.phn_next = a_next;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|phn_merge_ordered
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn0
parameter_list|,
name|a_phn1
parameter_list|,
name|a_cmp
parameter_list|)
value|do {	\ 	a_type *phn0child;						\ 									\ 	assert(a_phn0 != NULL);						\ 	assert(a_phn1 != NULL);						\ 	assert(a_cmp(a_phn0, a_phn1)<= 0);				\ 									\ 	phn_prev_set(a_type, a_field, a_phn1, a_phn0);			\ 	phn0child = phn_lchild_get(a_type, a_field, a_phn0);		\ 	phn_next_set(a_type, a_field, a_phn1, phn0child);		\ 	if (phn0child != NULL) {					\ 		phn_prev_set(a_type, a_field, phn0child, a_phn1);	\ 	}								\ 	phn_lchild_set(a_type, a_field, a_phn0, a_phn1);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|phn_merge
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn0
parameter_list|,
name|a_phn1
parameter_list|,
name|a_cmp
parameter_list|,
name|r_phn
parameter_list|)
value|do {	\ 	if (a_phn0 == NULL) {						\ 		r_phn = a_phn1;						\ 	} else if (a_phn1 == NULL) {					\ 		r_phn = a_phn0;						\ 	} else if (a_cmp(a_phn0, a_phn1)< 0) {				\ 		phn_merge_ordered(a_type, a_field, a_phn0, a_phn1,	\ 		    a_cmp);						\ 		r_phn = a_phn0;						\ 	} else {							\ 		phn_merge_ordered(a_type, a_field, a_phn1, a_phn0,	\ 		    a_cmp);						\ 		r_phn = a_phn1;						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|ph_merge_siblings
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn
parameter_list|,
name|a_cmp
parameter_list|,
name|r_phn
parameter_list|)
value|do {	\ 	a_type *head = NULL;						\ 	a_type *tail = NULL;						\ 	a_type *phn0 = a_phn;						\ 	a_type *phn1 = phn_next_get(a_type, a_field, phn0);		\ 									\
comment|/*								\ 	 * Multipass merge, wherein the first two elements of a FIFO	\ 	 * are repeatedly merged, and each result is appended to the	\ 	 * singly linked FIFO, until the FIFO contains only a single	\ 	 * element.  We start with a sibling list but no reference to	\ 	 * its tail, so we do a single pass over the sibling list to	\ 	 * populate the FIFO.						\ 	 */
value|\ 	if (phn1 != NULL) {						\ 		a_type *phnrest = phn_next_get(a_type, a_field, phn1);	\ 		if (phnrest != NULL) {					\ 			phn_prev_set(a_type, a_field, phnrest, NULL);	\ 		}							\ 		phn_prev_set(a_type, a_field, phn0, NULL);		\ 		phn_next_set(a_type, a_field, phn0, NULL);		\ 		phn_prev_set(a_type, a_field, phn1, NULL);		\ 		phn_next_set(a_type, a_field, phn1, NULL);		\ 		phn_merge(a_type, a_field, phn0, phn1, a_cmp, phn0);	\ 		head = tail = phn0;					\ 		phn0 = phnrest;						\ 		while (phn0 != NULL) {					\ 			phn1 = phn_next_get(a_type, a_field, phn0);	\ 			if (phn1 != NULL) {				\ 				phnrest = phn_next_get(a_type, a_field,	\ 				    phn1);				\ 				if (phnrest != NULL) {			\ 					phn_prev_set(a_type, a_field,	\ 					    phnrest, NULL);		\ 				}					\ 				phn_prev_set(a_type, a_field, phn0,	\ 				    NULL);				\ 				phn_next_set(a_type, a_field, phn0,	\ 				    NULL);				\ 				phn_prev_set(a_type, a_field, phn1,	\ 				    NULL);				\ 				phn_next_set(a_type, a_field, phn1,	\ 				    NULL);				\ 				phn_merge(a_type, a_field, phn0, phn1,	\ 				    a_cmp, phn0);			\ 				phn_next_set(a_type, a_field, tail,	\ 				    phn0);				\ 				tail = phn0;				\ 				phn0 = phnrest;				\ 			} else {					\ 				phn_next_set(a_type, a_field, tail,	\ 				    phn0);				\ 				tail = phn0;				\ 				phn0 = NULL;				\ 			}						\ 		}							\ 		phn0 = head;						\ 		phn1 = phn_next_get(a_type, a_field, phn0);		\ 		if (phn1 != NULL) {					\ 			while (true) {					\ 				head = phn_next_get(a_type, a_field,	\ 				    phn1);				\ 				assert(phn_prev_get(a_type, a_field,	\ 				    phn0) == NULL);			\ 				phn_next_set(a_type, a_field, phn0,	\ 				    NULL);				\ 				assert(phn_prev_get(a_type, a_field,	\ 				    phn1) == NULL);			\ 				phn_next_set(a_type, a_field, phn1,	\ 				    NULL);				\ 				phn_merge(a_type, a_field, phn0, phn1,	\ 				    a_cmp, phn0);			\ 				if (head == NULL) {			\ 					break;				\ 				}					\ 				phn_next_set(a_type, a_field, tail,	\ 				    phn0);				\ 				tail = phn0;				\ 				phn0 = head;				\ 				phn1 = phn_next_get(a_type, a_field,	\ 				    phn0);				\ 			}						\ 		}							\ 	}								\ 	r_phn = phn0;							\ } while (0)
end_define

begin_define
define|#
directive|define
name|ph_merge_aux
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_ph
parameter_list|,
name|a_cmp
parameter_list|)
value|do {			\ 	a_type *phn = phn_next_get(a_type, a_field, a_ph->ph_root);	\ 	if (phn != NULL) {						\ 		phn_prev_set(a_type, a_field, a_ph->ph_root, NULL);	\ 		phn_next_set(a_type, a_field, a_ph->ph_root, NULL);	\ 		phn_prev_set(a_type, a_field, phn, NULL);		\ 		ph_merge_siblings(a_type, a_field, phn, a_cmp, phn);	\ 		assert(phn_next_get(a_type, a_field, phn) == NULL);	\ 		phn_merge(a_type, a_field, a_ph->ph_root, phn, a_cmp,	\ 		    a_ph->ph_root);					\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|ph_merge_children
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_phn
parameter_list|,
name|a_cmp
parameter_list|,
name|r_phn
parameter_list|)
value|do {	\ 	a_type *lchild = phn_lchild_get(a_type, a_field, a_phn);	\ 	if (lchild == NULL) {						\ 		r_phn = NULL;						\ 	} else {							\ 		ph_merge_siblings(a_type, a_field, lchild, a_cmp,	\ 		    r_phn);						\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * The ph_proto() macro generates function prototypes that correspond to the  * functions generated by an equivalently parameterized call to ph_gen().  */
end_comment

begin_define
define|#
directive|define
name|ph_proto
parameter_list|(
name|a_attr
parameter_list|,
name|a_prefix
parameter_list|,
name|a_ph_type
parameter_list|,
name|a_type
parameter_list|)
define|\
value|a_attr void	a_prefix##new(a_ph_type *ph);				\ a_attr bool	a_prefix##empty(a_ph_type *ph);				\ a_attr a_type	*a_prefix##first(a_ph_type *ph);			\ a_attr a_type	*a_prefix##any(a_ph_type *ph);				\ a_attr void	a_prefix##insert(a_ph_type *ph, a_type *phn);		\ a_attr a_type	*a_prefix##remove_first(a_ph_type *ph);			\ a_attr a_type	*a_prefix##remove_any(a_ph_type *ph);			\ a_attr void	a_prefix##remove(a_ph_type *ph, a_type *phn);
end_define

begin_comment
comment|/*  * The ph_gen() macro generates a type-specific pairing heap implementation,  * based on the above cpp macros.  */
end_comment

begin_define
define|#
directive|define
name|ph_gen
parameter_list|(
name|a_attr
parameter_list|,
name|a_prefix
parameter_list|,
name|a_ph_type
parameter_list|,
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|)
define|\
value|a_attr void								\ a_prefix##new(a_ph_type *ph) {						\ 	memset(ph, 0, sizeof(ph(a_type)));				\ }									\ a_attr bool								\ a_prefix##empty(a_ph_type *ph) {					\ 	return (ph->ph_root == NULL);					\ }									\ a_attr a_type *								\ a_prefix##first(a_ph_type *ph) {					\ 	if (ph->ph_root == NULL) {					\ 		return NULL;						\ 	}								\ 	ph_merge_aux(a_type, a_field, ph, a_cmp);			\ 	return ph->ph_root;						\ }									\ a_attr a_type *								\ a_prefix##any(a_ph_type *ph) {						\ 	if (ph->ph_root == NULL) {					\ 		return NULL;						\ 	}								\ 	a_type *aux = phn_next_get(a_type, a_field, ph->ph_root);	\ 	if (aux != NULL) {						\ 		return aux;						\ 	}								\ 	return ph->ph_root;						\ }									\ a_attr void								\ a_prefix##insert(a_ph_type *ph, a_type *phn) {				\ 	memset(&phn->a_field, 0, sizeof(phn(a_type)));			\ 									\
comment|/*								\ 	 * Treat the root as an aux list during insertion, and lazily	\ 	 * merge during a_prefix##remove_first().  For elements that	\ 	 * are inserted, then removed via a_prefix##remove() before the	\ 	 * aux list is ever processed, this makes insert/remove		\ 	 * constant-time, whereas eager merging would make insert	\ 	 * O(log n).							\ 	 */
value|\ 	if (ph->ph_root == NULL) {					\ 		ph->ph_root = phn;					\ 	} else {							\ 		phn_next_set(a_type, a_field, phn, phn_next_get(a_type,	\ 		    a_field, ph->ph_root));				\ 		if (phn_next_get(a_type, a_field, ph->ph_root) !=	\ 		    NULL) {						\ 			phn_prev_set(a_type, a_field,			\ 			    phn_next_get(a_type, a_field, ph->ph_root),	\ 			    phn);					\ 		}							\ 		phn_prev_set(a_type, a_field, phn, ph->ph_root);	\ 		phn_next_set(a_type, a_field, ph->ph_root, phn);	\ 	}								\ }									\ a_attr a_type *								\ a_prefix##remove_first(a_ph_type *ph) {					\ 	a_type *ret;							\ 									\ 	if (ph->ph_root == NULL) {					\ 		return NULL;						\ 	}								\ 	ph_merge_aux(a_type, a_field, ph, a_cmp);			\ 									\ 	ret = ph->ph_root;						\ 									\ 	ph_merge_children(a_type, a_field, ph->ph_root, a_cmp,		\ 	    ph->ph_root);						\ 									\ 	return ret;							\ }									\ a_attr a_type *								\ a_prefix##remove_any(a_ph_type *ph) {					\
comment|/*								\ 	 * Remove the most recently inserted aux list element, or the	\ 	 * root if the aux list is empty.  This has the effect of	\ 	 * behaving as a LIFO (and insertion/removal is therefore	\ 	 * constant-time) if a_prefix##[remove_]first() are never	\ 	 * called.							\ 	 */
value|\ 	if (ph->ph_root == NULL) {					\ 		return NULL;						\ 	}								\ 	a_type *ret = phn_next_get(a_type, a_field, ph->ph_root);	\ 	if (ret != NULL) {						\ 		a_type *aux = phn_next_get(a_type, a_field, ret);	\ 		phn_next_set(a_type, a_field, ph->ph_root, aux);	\ 		if (aux != NULL) {					\ 			phn_prev_set(a_type, a_field, aux,		\ 			    ph->ph_root);				\ 		}							\ 		return ret;						\ 	}								\ 	ret = ph->ph_root;						\ 	ph_merge_children(a_type, a_field, ph->ph_root, a_cmp,		\ 	    ph->ph_root);						\ 	return ret;							\ }									\ a_attr void								\ a_prefix##remove(a_ph_type *ph, a_type *phn) {				\ 	a_type *replace, *parent;					\ 									\ 	if (ph->ph_root == phn) {					\
comment|/*							\ 		 * We can delete from aux list without merging it, but	\ 		 * we need to merge if we are dealing with the root	\ 		 * node and it has children.				\ 		 */
value|\ 		if (phn_lchild_get(a_type, a_field, phn) == NULL) {	\ 			ph->ph_root = phn_next_get(a_type, a_field,	\ 			    phn);					\ 			if (ph->ph_root != NULL) {			\ 				phn_prev_set(a_type, a_field,		\ 				    ph->ph_root, NULL);			\ 			}						\ 			return;						\ 		}							\ 		ph_merge_aux(a_type, a_field, ph, a_cmp);		\ 		if (ph->ph_root == phn) {				\ 			ph_merge_children(a_type, a_field, ph->ph_root,	\ 			    a_cmp, ph->ph_root);			\ 			return;						\ 		}							\ 	}								\ 									\
comment|/* Get parent (if phn is leftmost child) before mutating. */
value|\ 	if ((parent = phn_prev_get(a_type, a_field, phn)) != NULL) {	\ 		if (phn_lchild_get(a_type, a_field, parent) != phn) {	\ 			parent = NULL;					\ 		}							\ 	}								\
comment|/* Find a possible replacement node, and link to parent. */
value|\ 	ph_merge_children(a_type, a_field, phn, a_cmp, replace);	\
comment|/* Set next/prev for sibling linked list. */
value|\ 	if (replace != NULL) {						\ 		if (parent != NULL) {					\ 			phn_prev_set(a_type, a_field, replace, parent);	\ 			phn_lchild_set(a_type, a_field, parent,		\ 			    replace);					\ 		} else {						\ 			phn_prev_set(a_type, a_field, replace,		\ 			    phn_prev_get(a_type, a_field, phn));	\ 			if (phn_prev_get(a_type, a_field, phn) !=	\ 			    NULL) {					\ 				phn_next_set(a_type, a_field,		\ 				    phn_prev_get(a_type, a_field, phn),	\ 				    replace);				\ 			}						\ 		}							\ 		phn_next_set(a_type, a_field, replace,			\ 		    phn_next_get(a_type, a_field, phn));		\ 		if (phn_next_get(a_type, a_field, phn) != NULL) {	\ 			phn_prev_set(a_type, a_field,			\ 			    phn_next_get(a_type, a_field, phn),		\ 			    replace);					\ 		}							\ 	} else {							\ 		if (parent != NULL) {					\ 			a_type *next = phn_next_get(a_type, a_field,	\ 			    phn);					\ 			phn_lchild_set(a_type, a_field, parent, next);	\ 			if (next != NULL) {				\ 				phn_prev_set(a_type, a_field, next,	\ 				    parent);				\ 			}						\ 		} else {						\ 			assert(phn_prev_get(a_type, a_field, phn) !=	\ 			    NULL);					\ 			phn_next_set(a_type, a_field,			\ 			    phn_prev_get(a_type, a_field, phn),		\ 			    phn_next_get(a_type, a_field, phn));	\ 		}							\ 		if (phn_next_get(a_type, a_field, phn) != NULL) {	\ 			phn_prev_set(a_type, a_field,			\ 			    phn_next_get(a_type, a_field, phn),		\ 			    phn_prev_get(a_type, a_field, phn));	\ 		}							\ 	}								\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PH_H_ */
end_comment

end_unit

