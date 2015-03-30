begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_lists.h - linked lists common code  *  * SLIST: singly-linked lists  * ==========================  *  * These macros implement a simple singly-linked list template.  Both  * the listhead and per-entry next fields are declared as pointers to  * the list entry struct type.  Initialization to NULL is typically  * implicit (for globals and statics) or handled by zeroing of the  * containing structure.  *  * The name of the next link field is passed as an argument to allow  * membership in several lists at once using multiple next link fields.  *  * When possible, placing the link field first in the entry structure  * allows slightly smaller code to be generated on some platforms.  *  * LINK_SLIST(listhead, pentry, nextlink)  *	add entry at head  *  * LINK_TAIL_SLIST(listhead, pentry, nextlink, entrytype)  *	add entry at tail.  This is O(n), if this is a common  *	operation the FIFO template may be more appropriate.  *  * LINK_SORT_SLIST(listhead, pentry, beforecur, nextlink, entrytype)  *	add entry in sorted order.  beforecur is an expression comparing  *	pentry with the current list entry.  The current entry can be  *	referenced within beforecur as L_S_S_CUR(), which is short for  *	LINK_SORT_SLIST_CUR().  beforecur is nonzero if pentry sorts  *	before L_S_S_CUR().  *  * UNLINK_HEAD_SLIST(punlinked, listhead, nextlink)  *	unlink first entry and point punlinked to it, or set punlinked  *	to NULL if the list is empty.  *  * UNLINK_SLIST(punlinked, listhead, ptounlink, nextlink, entrytype)  *	unlink entry pointed to by ptounlink.  punlinked is set to NULL  *	if the entry is not found on the list, otherwise it is set to  *	ptounlink.  *  * UNLINK_EXPR_SLIST(punlinked, listhead, expr, nextlink, entrytype)  *	unlink entry where expression expr is nonzero.  expr can refer  *	to the entry being tested using UNLINK_EXPR_SLIST_CURRENT(),  *	alias U_E_S_CUR().  See the implementation of UNLINK_SLIST()  *	below for an example. U_E_S_CUR() is NULL iff the list is empty.  *	punlinked is pointed to the removed entry or NULL if none  *	satisfy expr.  *  * FIFO: singly-linked lists plus tail pointer  * ===========================================  *  * This is the same as FreeBSD's sys/queue.h STAILQ -- a singly-linked  * list implementation with tail-pointer maintenance, so that adding  * at the tail for first-in, first-out access is O(1).  *  * DECL_FIFO_ANCHOR(entrytype)  *	provides the type specification portion of the declaration for  *	a variable to refer to a FIFO queue (similar to listhead).  The  *	anchor contains the head and indirect tail pointers.  Example:  *  *		#include "ntp_lists.h"  *  *		typedef struct myentry_tag myentry;  *		struct myentry_tag {  *			myentry *next_link;  *			...  *		};  *  *		DECL_FIFO_ANCHOR(myentry) my_fifo;  *  *		void somefunc(myentry *pentry)  *		{  *			LINK_FIFO(my_fifo, pentry, next_link);  *		}  *  *	If DECL_FIFO_ANCHOR is used with stack or heap storage, it  *	should be initialized to NULL pointers using a = { NULL };  *	initializer or memset.  *  * HEAD_FIFO(anchor)  * TAIL_FIFO(anchor)  *	Pointer to first/last entry, NULL if FIFO is empty.  *  * LINK_FIFO(anchor, pentry, nextlink)  *	add entry at tail.  *  * UNLINK_FIFO(punlinked, anchor, nextlink)  *	unlink head entry and point punlinked to it, or set punlinked  *	to NULL if the list is empty.  *  * CONCAT_FIFO(q1, q2, nextlink)  *	empty fifoq q2 moving its nodes to q1 following q1's existing  *	nodes.  *  * DLIST: doubly-linked lists  * ==========================  *  * Elements on DLISTs always have non-NULL forward and back links,  * because both link chains are circular.  The beginning/end is marked  * by the listhead, which is the same type as elements for simplicity.  * An empty list's listhead has both links set to its own address.  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_LISTS_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_LISTS_H
end_define

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/* TRUE and FALSE */
end_comment

begin_include
include|#
directive|include
file|"ntp_assert.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|NTP_DEBUG_LISTS_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If list debugging is not enabled, save a little time by not clearing  * an entry's link pointer when it is unlinked, as the stale pointer  * is harmless as long as it is ignored when the entry is not in a  * list.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_DEBUG_LISTS_H
end_ifndef

begin_define
define|#
directive|define
name|MAYBE_Z_LISTS
parameter_list|(
name|p
parameter_list|)
value|do { } while (FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAYBE_Z_LISTS
parameter_list|(
name|p
parameter_list|)
value|(p) = NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINK_SLIST
parameter_list|(
name|listhead
parameter_list|,
name|pentry
parameter_list|,
name|nextlink
parameter_list|)
define|\
value|do {								\ 	(pentry)->nextlink = (listhead);			\ 	(listhead) = (pentry);					\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|LINK_TAIL_SLIST
parameter_list|(
name|listhead
parameter_list|,
name|pentry
parameter_list|,
name|nextlink
parameter_list|,
name|entrytype
parameter_list|)
define|\
value|do {								\ 	entrytype **pptail;					\ 								\ 	pptail =&(listhead);					\ 	while (*pptail != NULL)					\ 		pptail =&((*pptail)->nextlink);		\ 								\ 	(pentry)->nextlink = NULL;				\ 	*pptail = (pentry);					\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|LINK_SORT_SLIST_CURRENT
parameter_list|()
value|(*ppentry)
end_define

begin_define
define|#
directive|define
name|L_S_S_CUR
parameter_list|()
value|LINK_SORT_SLIST_CURRENT()
end_define

begin_define
define|#
directive|define
name|LINK_SORT_SLIST
parameter_list|(
name|listhead
parameter_list|,
name|pentry
parameter_list|,
name|beforecur
parameter_list|,
name|nextlink
parameter_list|,	\
name|entrytype
parameter_list|)
define|\
value|do {								\ 	entrytype **ppentry;					\ 								\ 	ppentry =&(listhead);					\ 	while (TRUE) {						\ 		if (NULL == *ppentry || (beforecur)) {		\ 			(pentry)->nextlink = *ppentry;		\ 			*ppentry = (pentry);			\ 			break;					\ 		}						\ 		ppentry =&((*ppentry)->nextlink);		\ 		if (NULL == *ppentry) {				\ 			(pentry)->nextlink = NULL;		\ 			*ppentry = (pentry);			\ 			break;					\ 		}						\ 	}							\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|UNLINK_HEAD_SLIST
parameter_list|(
name|punlinked
parameter_list|,
name|listhead
parameter_list|,
name|nextlink
parameter_list|)
define|\
value|do {								\ 	(punlinked) = (listhead);				\ 	if (NULL != (punlinked)) {				\ 		(listhead) = (punlinked)->nextlink;		\ 		MAYBE_Z_LISTS((punlinked)->nextlink);		\ 	}							\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|UNLINK_EXPR_SLIST_CURRENT
parameter_list|()
value|(*ppentry)
end_define

begin_define
define|#
directive|define
name|U_E_S_CUR
parameter_list|()
value|UNLINK_EXPR_SLIST_CURRENT()
end_define

begin_define
define|#
directive|define
name|UNLINK_EXPR_SLIST
parameter_list|(
name|punlinked
parameter_list|,
name|listhead
parameter_list|,
name|expr
parameter_list|,
name|nextlink
parameter_list|,	\
name|entrytype
parameter_list|)
define|\
value|do {								\ 	entrytype **ppentry;					\ 								\ 	ppentry =&(listhead);					\ 								\ 	while (!(expr))						\ 		if (*ppentry != NULL&&				\ 		    (*ppentry)->nextlink != NULL) {		\ 			ppentry =&((*ppentry)->nextlink);	\ 		} else {					\ 			ppentry = NULL;				\ 			break;					\ 		}						\ 								\ 	if (ppentry != NULL) {					\ 		(punlinked) = *ppentry;				\ 		*ppentry = (punlinked)->nextlink;		\ 		MAYBE_Z_LISTS((punlinked)->nextlink);		\ 	} else {						\ 		(punlinked) = NULL;				\ 	}							\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|UNLINK_SLIST
parameter_list|(
name|punlinked
parameter_list|,
name|listhead
parameter_list|,
name|ptounlink
parameter_list|,
name|nextlink
parameter_list|,	\
name|entrytype
parameter_list|)
define|\
value|UNLINK_EXPR_SLIST(punlinked, listhead, (ptounlink) ==	\ 	    U_E_S_CUR(), nextlink, entrytype)
end_define

begin_define
define|#
directive|define
name|CHECK_SLIST
parameter_list|(
name|listhead
parameter_list|,
name|nextlink
parameter_list|,
name|entrytype
parameter_list|)
define|\
value|do {								\ 	entrytype *pentry;					\ 								\ 	for (pentry = (listhead);				\ 	     pentry != NULL;					\ 	     pentry = pentry->nextlink){			\ 		NTP_INSIST(pentry != pentry->nextlink);		\ 		NTP_INSIST((listhead) != pentry->nextlink);	\ 	}							\ } while (FALSE)
end_define

begin_comment
comment|/*  * FIFO  */
end_comment

begin_define
define|#
directive|define
name|DECL_FIFO_ANCHOR
parameter_list|(
name|entrytype
parameter_list|)
define|\
value|struct {							\ 	entrytype *	phead;
comment|/* NULL if list empty */
value|\ 	entrytype **	pptail;
comment|/* NULL if list empty */
value|\ }
end_define

begin_define
define|#
directive|define
name|HEAD_FIFO
parameter_list|(
name|anchor
parameter_list|)
value|((anchor).phead)
end_define

begin_define
define|#
directive|define
name|TAIL_FIFO
parameter_list|(
name|anchor
parameter_list|)
value|((NULL == (anchor).pptail)	\ 					? NULL			\ 					: *((anchor).pptail))
end_define

begin_comment
comment|/*  * For DEBUG builds only, verify both or neither of the anchor pointers  * are NULL with each operation.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NTP_DEBUG_LISTS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|CHECK_FIFO_CONSISTENCY
parameter_list|(
name|anchor
parameter_list|)
value|do { } while (FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK_FIFO_CONSISTENCY
parameter_list|(
name|anchor
parameter_list|)
define|\
value|check_gen_fifo_consistency(&(anchor))
end_define

begin_function_decl
name|void
name|check_gen_fifo_consistency
parameter_list|(
name|void
modifier|*
name|fifo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * generic FIFO element used to access any FIFO where each element  * begins with the link pointer  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gen_node_tag
name|gen_node
typedef|;
end_typedef

begin_struct
struct|struct
name|gen_node_tag
block|{
name|gen_node
modifier|*
name|link
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* generic FIFO */
end_comment

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|gen_node
argument_list|)
name|gen_fifo
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|LINK_FIFO
parameter_list|(
name|anchor
parameter_list|,
name|pentry
parameter_list|,
name|nextlink
parameter_list|)
define|\
value|do {								\ 	CHECK_FIFO_CONSISTENCY(anchor);				\ 								\ 	(pentry)->nextlink = NULL;				\ 	if (NULL != (anchor).pptail) {				\ 		(*((anchor).pptail))->nextlink = (pentry);	\ 		(anchor).pptail =				\&(*((anchor).pptail))->nextlink;		\ 	} else {						\ 		(anchor).phead = (pentry);			\ 		(anchor).pptail =&(anchor).phead;		\ 	}							\ 								\ 	CHECK_FIFO_CONSISTENCY(anchor);				\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|UNLINK_FIFO
parameter_list|(
name|punlinked
parameter_list|,
name|anchor
parameter_list|,
name|nextlink
parameter_list|)
define|\
value|do {								\ 	CHECK_FIFO_CONSISTENCY(anchor);				\ 								\ 	(punlinked) = (anchor).phead;				\ 	if (NULL != (punlinked)) {				\ 		(anchor).phead = (punlinked)->nextlink;		\ 		if (NULL == (anchor).phead)			\ 			(anchor).pptail = NULL;			\ 		else if ((anchor).pptail ==			\&(punlinked)->nextlink)		\ 			(anchor).pptail =&(anchor).phead;	\ 		MAYBE_Z_LISTS((punlinked)->nextlink);		\ 		CHECK_FIFO_CONSISTENCY(anchor);			\ 	}							\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|UNLINK_MID_FIFO
parameter_list|(
name|punlinked
parameter_list|,
name|anchor
parameter_list|,
name|tounlink
parameter_list|,
name|nextlink
parameter_list|,	\
name|entrytype
parameter_list|)
define|\
value|do {								\ 	entrytype **ppentry;					\ 								\ 	CHECK_FIFO_CONSISTENCY(anchor);				\ 								\ 	ppentry =&(anchor).phead;				\ 								\ 	while ((tounlink) != *ppentry)				\ 		if ((*ppentry)->nextlink != NULL) {		\ 			ppentry =&((*ppentry)->nextlink);	\ 		} else {					\ 			ppentry = NULL;				\ 			break;					\ 		}						\ 								\ 	if (ppentry != NULL) {					\ 		(punlinked) = *ppentry;				\ 		*ppentry = (punlinked)->nextlink;		\ 		if (NULL == *ppentry)				\ 			(anchor).pptail = NULL;			\ 		else if ((anchor).pptail ==			\&(punlinked)->nextlink)		\ 			(anchor).pptail =&(anchor).phead;	\ 		MAYBE_Z_LISTS((punlinked)->nextlink);		\ 		CHECK_FIFO_CONSISTENCY(anchor);			\ 	} else {						\ 		(punlinked) = NULL;				\ 	}							\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|CONCAT_FIFO
parameter_list|(
name|f1
parameter_list|,
name|f2
parameter_list|,
name|nextlink
parameter_list|)
define|\
value|do {								\ 	CHECK_FIFO_CONSISTENCY(f1);				\ 	CHECK_FIFO_CONSISTENCY(f2);				\ 								\ 	if ((f2).pptail != NULL) {				\ 		if ((f1).pptail != NULL) {			\ 			(*(f1).pptail)->nextlink = (f2).phead;	\ 			if ((f2).pptail ==&(f2).phead)		\ 				(f1).pptail =			\&(*(f1).pptail)->nextlink;	\ 			else					\ 				(f1).pptail = (f2).pptail;	\ 			CHECK_FIFO_CONSISTENCY(f1);		\ 		} else	{					\ 			(f1) = (f2);				\ 		}						\ 		MAYBE_Z_LISTS((f2).phead);			\ 		MAYBE_Z_LISTS((f2).pptail);			\ 	}							\ } while (FALSE)
end_define

begin_comment
comment|/*  * DLIST  */
end_comment

begin_define
define|#
directive|define
name|DECL_DLIST_LINK
parameter_list|(
name|entrytype
parameter_list|,
name|link
parameter_list|)
define|\
value|struct {							\ 	entrytype *	b;					\ 	entrytype *	f;					\ } link
end_define

begin_define
define|#
directive|define
name|INIT_DLIST
parameter_list|(
name|listhead
parameter_list|,
name|link
parameter_list|)
define|\
value|do {								\ 	(listhead).link.f =&(listhead);			\ 	(listhead).link.b =&(listhead);			\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|HEAD_DLIST
parameter_list|(
name|listhead
parameter_list|,
name|link
parameter_list|)
define|\
value|(							\ 		(&(listhead) != (listhead).link.f)		\ 		    ? (listhead).link.f				\ 		    : NULL					\ 	)
end_define

begin_define
define|#
directive|define
name|TAIL_DLIST
parameter_list|(
name|listhead
parameter_list|,
name|link
parameter_list|)
define|\
value|(							\ 		(&(listhead) != (listhead).link.b)		\ 		    ? (listhead).link.b				\ 		    : NULL					\ 	)
end_define

begin_define
define|#
directive|define
name|NEXT_DLIST
parameter_list|(
name|listhead
parameter_list|,
name|entry
parameter_list|,
name|link
parameter_list|)
define|\
value|(							\ 		(&(listhead) != (entry)->link.f)		\ 		    ? (entry)->link.f				\ 		    : NULL					\ 	)
end_define

begin_define
define|#
directive|define
name|PREV_DLIST
parameter_list|(
name|listhead
parameter_list|,
name|entry
parameter_list|,
name|link
parameter_list|)
define|\
value|(							\ 		(&(listhead) != (entry)->link.b)		\ 		    ? (entry)->link.b				\ 		    : NULL					\ 	)
end_define

begin_define
define|#
directive|define
name|LINK_DLIST
parameter_list|(
name|listhead
parameter_list|,
name|pentry
parameter_list|,
name|link
parameter_list|)
define|\
value|do {								\ 	(pentry)->link.f = (listhead).link.f;			\ 	(pentry)->link.b =&(listhead);				\ 	(listhead).link.f->link.b = (pentry);			\ 	(listhead).link.f = (pentry);				\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|LINK_TAIL_DLIST
parameter_list|(
name|listhead
parameter_list|,
name|pentry
parameter_list|,
name|link
parameter_list|)
define|\
value|do {								\ 	(pentry)->link.b = (listhead).link.b;			\ 	(pentry)->link.f =&(listhead);				\ 	(listhead).link.b->link.f = (pentry);			\ 	(listhead).link.b = (pentry);				\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|UNLINK_DLIST
parameter_list|(
name|ptounlink
parameter_list|,
name|link
parameter_list|)
define|\
value|do {								\ 	(ptounlink)->link.b->link.f = (ptounlink)->link.f;	\ 	(ptounlink)->link.f->link.b = (ptounlink)->link.b;	\ 	MAYBE_Z_LISTS((ptounlink)->link.b);			\ 	MAYBE_Z_LISTS((ptounlink)->link.f);			\ } while (FALSE)
end_define

begin_define
define|#
directive|define
name|ITER_DLIST_BEGIN
parameter_list|(
name|listhead
parameter_list|,
name|iter
parameter_list|,
name|link
parameter_list|,
name|entrytype
parameter_list|)
define|\
value|{								\ 	entrytype *i_dl_nextiter;				\ 								\ 	for ((iter) = (listhead).link.f;			\ 	     (iter) !=&(listhead)				\&& ((i_dl_nextiter = (iter)->link.f), TRUE);	\ 	     (iter) = i_dl_nextiter) {
end_define

begin_define
define|#
directive|define
name|ITER_DLIST_END
parameter_list|()
define|\
value|}							\ }
end_define

begin_define
define|#
directive|define
name|REV_ITER_DLIST_BEGIN
parameter_list|(
name|listhead
parameter_list|,
name|iter
parameter_list|,
name|link
parameter_list|,
name|entrytype
parameter_list|)
define|\
value|{								\ 	entrytype *i_dl_nextiter;				\ 								\ 	for ((iter) = (listhead).link.b;			\ 	     (iter) !=&(listhead)				\&& ((i_dl_nextiter = (iter)->link.b), TRUE);	\ 	     (iter) = i_dl_nextiter) {
end_define

begin_define
define|#
directive|define
name|REV_ITER_DLIST_END
parameter_list|()
define|\
value|}							\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_LISTS_H */
end_comment

end_unit

