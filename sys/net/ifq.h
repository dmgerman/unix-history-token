begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: @(#)if.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IFQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IFQ_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_comment
comment|/* ifqueue only? */
end_comment

begin_include
include|#
directive|include
file|<sys/buf_ring.h>
end_include

begin_include
include|#
directive|include
file|<net/vnet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_comment
comment|/* struct ifqueue */
end_comment

begin_define
define|#
directive|define
name|IF_DUNIT_NONE
value|-1
end_define

begin_include
include|#
directive|include
file|<altq/if_altq.h>
end_include

begin_comment
comment|/*  * Structure defining a queue for a network interface.  */
end_comment

begin_struct
struct|struct
name|ifqueue
block|{
name|struct
name|mbuf
modifier|*
name|ifq_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ifq_tail
decl_stmt|;
name|int
name|ifq_len
decl_stmt|;
name|int
name|ifq_maxlen
decl_stmt|;
name|struct
name|mtx
name|ifq_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Output queues (ifp->if_snd) and slow device input queues (*ifp->if_slowq)  * are queues of messages stored on ifqueue structures  * (defined above).  Entries are added to and deleted from these structures  * by these macros.  */
end_comment

begin_define
define|#
directive|define
name|IF_LOCK
parameter_list|(
name|ifq
parameter_list|)
value|mtx_lock(&(ifq)->ifq_mtx)
end_define

begin_define
define|#
directive|define
name|IF_UNLOCK
parameter_list|(
name|ifq
parameter_list|)
value|mtx_unlock(&(ifq)->ifq_mtx)
end_define

begin_define
define|#
directive|define
name|IF_LOCK_ASSERT
parameter_list|(
name|ifq
parameter_list|)
value|mtx_assert(&(ifq)->ifq_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|_IF_QFULL
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len>= (ifq)->ifq_maxlen)
end_define

begin_define
define|#
directive|define
name|_IF_QLEN
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len)
end_define

begin_define
define|#
directive|define
name|_IF_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do { 				\ 	(m)->m_nextpkt = NULL;					\ 	if ((ifq)->ifq_tail == NULL) 				\ 		(ifq)->ifq_head = m; 				\ 	else 							\ 		(ifq)->ifq_tail->m_nextpkt = m; 		\ 	(ifq)->ifq_tail = m; 					\ 	(ifq)->ifq_len++; 					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IF_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {					\ 	IF_LOCK(ifq); 						\ 	_IF_ENQUEUE(ifq, m); 					\ 	IF_UNLOCK(ifq); 					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_IF_PREPEND
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {				\ 	(m)->m_nextpkt = (ifq)->ifq_head; 			\ 	if ((ifq)->ifq_tail == NULL) 				\ 		(ifq)->ifq_tail = (m); 				\ 	(ifq)->ifq_head = (m); 					\ 	(ifq)->ifq_len++; 					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IF_PREPEND
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {		 			\ 	IF_LOCK(ifq); 						\ 	_IF_PREPEND(ifq, m); 					\ 	IF_UNLOCK(ifq); 					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_IF_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do { 				\ 	(m) = (ifq)->ifq_head; 					\ 	if (m) { 						\ 		if (((ifq)->ifq_head = (m)->m_nextpkt) == NULL)	\ 			(ifq)->ifq_tail = NULL; 		\ 		(m)->m_nextpkt = NULL; 				\ 		(ifq)->ifq_len--; 				\ 	} 							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IF_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do { 				\ 	IF_LOCK(ifq); 						\ 	_IF_DEQUEUE(ifq, m); 					\ 	IF_UNLOCK(ifq); 					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_IF_DEQUEUE_ALL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {				\ 	(m) = (ifq)->ifq_head;					\ 	(ifq)->ifq_head = (ifq)->ifq_tail = NULL;		\ 	(ifq)->ifq_len = 0;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IF_DEQUEUE_ALL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {				\ 	IF_LOCK(ifq); 						\ 	_IF_DEQUEUE_ALL(ifq, m);				\ 	IF_UNLOCK(ifq); 					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_IF_POLL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|((m) = (ifq)->ifq_head)
end_define

begin_define
define|#
directive|define
name|IF_POLL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|_IF_POLL(ifq, m)
end_define

begin_define
define|#
directive|define
name|_IF_DRAIN
parameter_list|(
name|ifq
parameter_list|)
value|do { 					\ 	struct mbuf *m; 					\ 	for (;;) { 						\ 		_IF_DEQUEUE(ifq, m); 				\ 		if (m == NULL) 					\ 			break; 					\ 		m_freem(m); 					\ 	} 							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IF_DRAIN
parameter_list|(
name|ifq
parameter_list|)
value|do {					\ 	IF_LOCK(ifq);						\ 	_IF_DRAIN(ifq);						\ 	IF_UNLOCK(ifq);						\ } while(0)
end_define

begin_function_decl
name|int
name|if_handoff
parameter_list|(
name|struct
name|ifqueue
modifier|*
name|ifq
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
name|adjust
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IF_HANDOFF
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|ifp
parameter_list|)
define|\
value|if_handoff((struct ifqueue *)ifq, m, ifp, 0)
end_define

begin_define
define|#
directive|define
name|IF_HANDOFF_ADJ
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|ifp
parameter_list|,
name|adj
parameter_list|)
define|\
value|if_handoff((struct ifqueue *)ifq, m, ifp, adj)
end_define

begin_function_decl
name|void
name|if_start
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IFQ_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|err
parameter_list|)
define|\
value|do {									\ 	IF_LOCK(ifq);							\ 	if (ALTQ_IS_ENABLED(ifq))					\ 		ALTQ_ENQUEUE(ifq, m, NULL, err);			\ 	else {								\ 		if (_IF_QFULL(ifq)) {					\ 			m_freem(m);					\ 			(err) = ENOBUFS;				\ 		} else {						\ 			_IF_ENQUEUE(ifq, m);				\ 			(err) = 0;					\ 		}							\ 	}								\ 	IF_UNLOCK(ifq);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_DEQUEUE_NOLOCK
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	if (TBR_IS_ENABLED(ifq))					\ 		(m) = tbr_dequeue_ptr(ifq, ALTDQ_REMOVE);		\ 	else if (ALTQ_IS_ENABLED(ifq))					\ 		ALTQ_DEQUEUE(ifq, m);					\ 	else								\ 		_IF_DEQUEUE(ifq, m);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	IF_LOCK(ifq);							\ 	IFQ_DEQUEUE_NOLOCK(ifq, m);					\ 	IF_UNLOCK(ifq);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_POLL_NOLOCK
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	if (TBR_IS_ENABLED(ifq))					\ 		(m) = tbr_dequeue_ptr(ifq, ALTDQ_POLL);			\ 	else if (ALTQ_IS_ENABLED(ifq))					\ 		ALTQ_POLL(ifq, m);					\ 	else								\ 		_IF_POLL(ifq, m);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_POLL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	IF_LOCK(ifq);							\ 	IFQ_POLL_NOLOCK(ifq, m);					\ 	IF_UNLOCK(ifq);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_PURGE_NOLOCK
parameter_list|(
name|ifq
parameter_list|)
define|\
value|do {									\ 	if (ALTQ_IS_ENABLED(ifq)) {					\ 		ALTQ_PURGE(ifq);					\ 	} else								\ 		_IF_DRAIN(ifq);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_PURGE
parameter_list|(
name|ifq
parameter_list|)
define|\
value|do {									\ 	IF_LOCK(ifq);							\ 	IFQ_PURGE_NOLOCK(ifq);						\ 	IF_UNLOCK(ifq);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_SET_READY
parameter_list|(
name|ifq
parameter_list|)
define|\
value|do { ((ifq)->altq_flags |= ALTQF_READY); } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_LOCK
parameter_list|(
name|ifq
parameter_list|)
value|IF_LOCK(ifq)
end_define

begin_define
define|#
directive|define
name|IFQ_UNLOCK
parameter_list|(
name|ifq
parameter_list|)
value|IF_UNLOCK(ifq)
end_define

begin_define
define|#
directive|define
name|IFQ_LOCK_ASSERT
parameter_list|(
name|ifq
parameter_list|)
value|IF_LOCK_ASSERT(ifq)
end_define

begin_define
define|#
directive|define
name|IFQ_IS_EMPTY
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len == 0)
end_define

begin_define
define|#
directive|define
name|IFQ_INC_LEN
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len++)
end_define

begin_define
define|#
directive|define
name|IFQ_DEC_LEN
parameter_list|(
name|ifq
parameter_list|)
value|(--(ifq)->ifq_len)
end_define

begin_define
define|#
directive|define
name|IFQ_SET_MAXLEN
parameter_list|(
name|ifq
parameter_list|,
name|len
parameter_list|)
value|((ifq)->ifq_maxlen = (len))
end_define

begin_comment
comment|/*  * The IFF_DRV_OACTIVE test should really occur in the device driver, not in  * the handoff logic, as that flag is locked by the device driver.  */
end_comment

begin_define
define|#
directive|define
name|IFQ_HANDOFF_ADJ
parameter_list|(
name|ifp
parameter_list|,
name|m
parameter_list|,
name|adj
parameter_list|,
name|err
parameter_list|)
define|\
value|do {									\ 	int len;							\ 	short mflags;							\ 									\ 	len = (m)->m_pkthdr.len;					\ 	mflags = (m)->m_flags;						\ 	IFQ_ENQUEUE(&(ifp)->if_snd, m, err);				\ 	if ((err) == 0) {						\ 		(ifp)->if_obytes += len + (adj);			\ 		if (mflags& M_MCAST)					\ 			(ifp)->if_omcasts++;				\ 		if (((ifp)->if_drv_flags& IFF_DRV_OACTIVE) == 0)	\ 			if_start(ifp);					\ 	} else								\ 		ifp->if_oqdrops++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_HANDOFF
parameter_list|(
name|ifp
parameter_list|,
name|m
parameter_list|,
name|err
parameter_list|)
define|\
value|IFQ_HANDOFF_ADJ(ifp, m, 0, err)
end_define

begin_define
define|#
directive|define
name|IFQ_DRV_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	(m) = (ifq)->ifq_drv_head;					\ 	if (m) {							\ 		if (((ifq)->ifq_drv_head = (m)->m_nextpkt) == NULL)	\ 			(ifq)->ifq_drv_tail = NULL;			\ 		(m)->m_nextpkt = NULL;					\ 		(ifq)->ifq_drv_len--;					\ 	} else {							\ 		IFQ_LOCK(ifq);						\ 		IFQ_DEQUEUE_NOLOCK(ifq, m);				\ 		while ((ifq)->ifq_drv_len< (ifq)->ifq_drv_maxlen) {	\ 			struct mbuf *m0;				\ 			IFQ_DEQUEUE_NOLOCK(ifq, m0);			\ 			if (m0 == NULL)					\ 				break;					\ 			m0->m_nextpkt = NULL;				\ 			if ((ifq)->ifq_drv_tail == NULL)		\ 				(ifq)->ifq_drv_head = m0;		\ 			else						\ 				(ifq)->ifq_drv_tail->m_nextpkt = m0;	\ 			(ifq)->ifq_drv_tail = m0;			\ 			(ifq)->ifq_drv_len++;				\ 		}							\ 		IFQ_UNLOCK(ifq);					\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_DRV_PREPEND
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	(m)->m_nextpkt = (ifq)->ifq_drv_head;				\ 	if ((ifq)->ifq_drv_tail == NULL)				\ 		(ifq)->ifq_drv_tail = (m);				\ 	(ifq)->ifq_drv_head = (m);					\ 	(ifq)->ifq_drv_len++;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_DRV_IS_EMPTY
parameter_list|(
name|ifq
parameter_list|)
define|\
value|(((ifq)->ifq_drv_len == 0)&& ((ifq)->ifq_len == 0))
end_define

begin_define
define|#
directive|define
name|IFQ_DRV_PURGE
parameter_list|(
name|ifq
parameter_list|)
define|\
value|do {									\ 	struct mbuf *m, *n = (ifq)->ifq_drv_head;			\ 	while((m = n) != NULL) {					\ 		n = m->m_nextpkt;					\ 		m_freem(m);						\ 	}								\ 	(ifq)->ifq_drv_head = (ifq)->ifq_drv_tail = NULL;		\ 	(ifq)->ifq_drv_len = 0;						\ 	IFQ_PURGE(ifq);							\ } while (0)
end_define

begin_function
specifier|static
name|__inline
name|int
name|drbr_enqueue
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
name|IFQ_ENQUEUE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|,
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|ifp
operator|->
name|if_oqdrops
operator|++
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
endif|#
directive|endif
name|error
operator|=
name|buf_ring_enqueue
argument_list|(
name|br
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|drbr_putback
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|,
name|struct
name|mbuf
modifier|*
name|new
parameter_list|)
block|{
comment|/* 	 * The top of the list needs to be swapped  	 * for this one. 	 */
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
comment|/*  		 * Peek in altq case dequeued it 		 * so put it back. 		 */
name|IFQ_DRV_PREPEND
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|new
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|buf_ring_putback_sc
argument_list|(
name|br
argument_list|,
name|new
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|drbr_peek
argument_list|(
argument|struct ifnet *ifp
argument_list|,
argument|struct buf_ring *br
argument_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
block|struct
name|mbuf
operator|*
name|m
block|;
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
comment|/*  		 * Pull it off like a dequeue 		 * since drbr_advance() does nothing 		 * for altq and drbr_putback() will 		 * use the old prepend function. 		 */
name|IFQ_DEQUEUE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
operator|(
name|buf_ring_peek
argument_list|(
name|br
argument_list|)
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|drbr_flush
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
name|IFQ_PURGE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
operator|(
name|m
operator|=
name|buf_ring_dequeue_sc
argument_list|(
name|br
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|drbr_free
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|)
block|{
name|drbr_flush
argument_list|(
name|NULL
argument_list|,
name|br
argument_list|)
expr_stmt|;
name|buf_ring_free
argument_list|(
name|br
argument_list|,
name|type
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|drbr_dequeue
argument_list|(
argument|struct ifnet *ifp
argument_list|,
argument|struct buf_ring *br
argument_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
block|struct
name|mbuf
operator|*
name|m
block|;
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
name|IFQ_DEQUEUE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
operator|(
name|buf_ring_dequeue_sc
argument_list|(
name|br
argument_list|)
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|drbr_advance
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
comment|/* Nothing to do here since peek dequeues in altq case */
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
return|return;
endif|#
directive|endif
return|return
operator|(
name|buf_ring_advance_sc
argument_list|(
name|br
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|drbr_dequeue_cond
argument_list|(
argument|struct ifnet *ifp
argument_list|,
argument|struct buf_ring *br
argument_list|,
argument|int (*func) (struct mbuf *, void *)
argument_list|,
argument|void *arg
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|m
block|;
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
name|IFQ_LOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
expr_stmt|;
name|IFQ_POLL_NOLOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|!=
name|NULL
operator|&&
name|func
argument_list|(
name|m
argument_list|,
name|arg
argument_list|)
operator|==
literal|0
condition|)
block|{
name|IFQ_UNLOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|IFQ_DEQUEUE_NOLOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|IFQ_UNLOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|m
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|m
operator|=
name|buf_ring_peek
argument_list|(
name|br
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|m
operator|==
name|NULL
operator|||
name|func
argument_list|(
name|m
argument_list|,
name|arg
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
end_if

begin_return
return|return
operator|(
name|buf_ring_dequeue_sc
argument_list|(
name|br
argument_list|)
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|drbr_empty
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
return|return
operator|(
name|IFQ_IS_EMPTY
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
name|buf_ring_empty
argument_list|(
name|br
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|drbr_needs_enqueue
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
operator|!
name|buf_ring_empty
argument_list|(
name|br
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|drbr_inuse
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
return|return
operator|(
name|ifp
operator|->
name|if_snd
operator|.
name|ifq_len
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
name|buf_ring_count
argument_list|(
name|br
argument_list|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|ifqmaxlen
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|if_qflush
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifq_init
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifq_delete
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEVICE_POLLING
end_ifdef

begin_enum
enum|enum
name|poll_cmd
block|{
name|POLL_ONLY
block|,
name|POLL_AND_CHECK_STATUS
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|int
name|poll_handler_t
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|enum
name|poll_cmd
name|cmd
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|ether_poll_register
parameter_list|(
name|poll_handler_t
modifier|*
name|h
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ether_poll_deregister
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following should be temporary, till all drivers use the driver API */
end_comment

begin_typedef
typedef|typedef
name|int
name|poll_handler_drv_t
parameter_list|(
name|if_t
name|ifh
parameter_list|,
name|enum
name|poll_cmd
name|cmd
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|ether_poll_register_drv
parameter_list|(
name|poll_handler_drv_t
modifier|*
name|h
parameter_list|,
name|if_t
name|ifh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ether_poll_deregister_drv
parameter_list|(
name|if_t
name|ifh
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEVICE_POLLING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IFQ_H_ */
end_comment

end_unit

