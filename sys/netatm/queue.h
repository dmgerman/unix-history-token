begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * General queueing/linking definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_QUEUE_H
end_define

begin_comment
comment|/*  * Structure defining the queue controls for a doubly linked queue  */
end_comment

begin_struct
struct|struct
name|q_queue
block|{
name|caddr_t
name|q_head
decl_stmt|;
comment|/* Head of queue */
name|caddr_t
name|q_tail
decl_stmt|;
comment|/* Tail of queue */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|q_queue
name|Queue_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure defining the queue elements of a doubly linked queue  */
end_comment

begin_struct
struct|struct
name|q_elem
block|{
name|caddr_t
name|q_forw
decl_stmt|;
comment|/* Forward link */
name|caddr_t
name|q_back
decl_stmt|;
comment|/* Backward link */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|q_elem
name|Qelem_t
typedef|;
end_typedef

begin_comment
comment|/*  * Macro to add a control block onto the tail of a doubly linked queue  *	e = control block to add  *	t = control block structure type  *	el = name of control block's q_elem field  *	q = pointer to queue controls  */
end_comment

begin_define
define|#
directive|define
name|ENQUEUE
parameter_list|(
name|e
parameter_list|,
name|t
parameter_list|,
name|el
parameter_list|,
name|q
parameter_list|)
define|\
value|{								\ 	(e)->el.q_forw = NULL;					\ 	(e)->el.q_back = (q).q_tail;				\ 	if ((q).q_head == NULL) {				\ 		(q).q_head = (caddr_t)(e);			\ 		(q).q_tail = (caddr_t)(e);			\ 	} else {						\ 		((t *)(q).q_tail)->el.q_forw = (caddr_t)(e);	\ 		(q).q_tail = (caddr_t)(e);			\ 	}							\ }
end_define

begin_comment
comment|/*  * Macro to remove a control block from a doubly linked queue  *	e = control block to remove  *	t = control block structure type  *	el = name of control block's q_elem field  *	q = pointer to queue controls  */
end_comment

begin_define
define|#
directive|define
name|DEQUEUE
parameter_list|(
name|e
parameter_list|,
name|t
parameter_list|,
name|el
parameter_list|,
name|q
parameter_list|)
define|\
value|{								\
comment|/* Ensure control block is on queue */
value|\ 	if ((e)->el.q_forw || (q).q_tail == (caddr_t)(e)) {	\ 		if ((e)->el.q_forw)				\ 			((t *)(e)->el.q_forw)->el.q_back = (e)->el.q_back;\ 		else						\ 			(q).q_tail = (e)->el.q_back;		\ 		if ((e)->el.q_back)				\ 			((t *)(e)->el.q_back)->el.q_forw = (e)->el.q_forw;\ 		else						\ 			(q).q_head = (e)->el.q_forw;		\ 	}							\ 	(e)->el.q_back = (e)->el.q_forw = NULL;			\ }
end_define

begin_comment
comment|/*  * Macro to return the head of a doubly linked queue  *	q = pointer to queue controls  *	t = control block structure type  */
end_comment

begin_define
define|#
directive|define
name|Q_HEAD
parameter_list|(
name|q
parameter_list|,
name|t
parameter_list|)
value|((t *)(q).q_head)
end_define

begin_comment
comment|/*  * Macro to return the next control block of a doubly linked queue  *	e = current control block  *	t = control block structure type  *	el = name of control block's q_elem field  */
end_comment

begin_define
define|#
directive|define
name|Q_NEXT
parameter_list|(
name|e
parameter_list|,
name|t
parameter_list|,
name|el
parameter_list|)
value|((t *)(e)->el.q_forw)
end_define

begin_comment
comment|/*  * Macro to add a control block onto the head of a singly linked chain  *	u = control block to add  *	t = structure type  *	h = head of chain  *	l = name of link field  */
end_comment

begin_define
define|#
directive|define
name|LINK2HEAD
parameter_list|(
name|u
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|,
name|l
parameter_list|)
define|\
value|{								\ 	(u)->l = (h);						\ 	(h) = (u);						\ }
end_define

begin_comment
comment|/*  * Macro to add a control block onto the tail of a singly linked chain  *	u = control block to add  *	t = structure type  *	h = head of chain  *	l = name of link field  */
end_comment

begin_define
define|#
directive|define
name|LINK2TAIL
parameter_list|(
name|u
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|,
name|l
parameter_list|)
define|\
value|{								\ 	(u)->l = (t *)NULL;					\
comment|/* Check for empty chain */
value|\ 	if ((h) == (t *)NULL) {					\ 		(h) = (u);					\ 	} else {						\ 		t	*tp;					\
comment|/* Loop until we find the end of chain */
value|\ 		for (tp = (h); tp->l != (t *)NULL; tp = tp->l)	\ 			;					\ 		tp->l = (u);					\ 	}							\ }
end_define

begin_comment
comment|/*  * Macro to remove a control block from a singly linked chain  *	u = control block to unlink  *	t = structure type  *	h = head of chain  *	l = name of link field  */
end_comment

begin_define
define|#
directive|define
name|UNLINK
parameter_list|(
name|u
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|,
name|l
parameter_list|)
define|\
value|{								\
comment|/* Check for control block at head of chain */
value|\ 	if ((u) == (h)) {					\ 		(h) = (u)->l;					\ 	} else {						\ 		t	*tp;					\
comment|/* Loop until we find the control block */
value|\ 		for (tp = (h); tp != (t *)NULL; tp = tp->l) {	\ 			if (tp->l == (u))			\ 				break;				\ 		}						\ 		if (tp) {					\
comment|/* Remove it from chain */
value|\ 			tp->l = (u)->l;				\ 		}						\ 	}							\ 	(u)->l = (t *)NULL;					\ }
end_define

begin_comment
comment|/*  * Macro to remove a control block from a singly linked chain and return  * an indication of whether the block was found  *	u = control block to unlink  *	t = structure type  *	h = head of chain  *	l = name of link field  *	f = flag; 1 => control block found on chain; else 0  */
end_comment

begin_define
define|#
directive|define
name|UNLINKF
parameter_list|(
name|u
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
define|\
value|{								\
comment|/* Check for control block at head of chain */
value|\ 	if ((u) == (h)) {					\ 		(h) = (u)->l;					\ 		(f) = 1;					\ 	} else {						\ 		t	*tp;					\
comment|/* Loop until we find the control block */
value|\ 		for (tp = (h); tp != (t *)NULL; tp = tp->l) {	\ 			if (tp->l == (u))			\ 				break;				\ 		}						\ 		if (tp) {					\
comment|/* Remove it from chain */
value|\ 			tp->l = (u)->l;				\ 			(f) = 1;				\ 		} else						\
comment|/* It wasn't on the chain */
value|\ 			(f) = 0;				\ 	}							\ 	(u)->l = (t *)NULL;					\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATM_QUEUE_H */
end_comment

end_unit

