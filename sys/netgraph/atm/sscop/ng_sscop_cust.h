begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Customisation of the SSCOP code to ng_sscop.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/ng_message.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/netgraph.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<netnatm/saal/sscopdef.h>
end_include

begin_comment
comment|/*  * Allocate zeroed or non-zeroed memory of some size and cast it.  * Return NULL on failure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSCOP_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|MEMINIT
parameter_list|()
define|\
value|MALLOC_DECLARE(M_NG_SSCOP); \ 	DECL_MSGQ_GET \ 	DECL_SIGQ_GET \ 	DECL_MBUF_ALLOC
end_define

begin_define
define|#
directive|define
name|MEMZALLOC
parameter_list|(
name|PTR
parameter_list|,
name|CAST
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|((PTR) = (CAST)malloc((SIZE), M_NG_SSCOP, M_NOWAIT | M_ZERO))
end_define

begin_define
define|#
directive|define
name|MEMFREE
parameter_list|(
name|PTR
parameter_list|)
define|\
value|free((PTR), M_NG_SSCOP)
end_define

begin_define
define|#
directive|define
name|MSG_ALLOC
parameter_list|(
name|PTR
parameter_list|)
define|\
value|MEMZALLOC(PTR, struct sscop_msg *, sizeof(struct sscop_msg))
end_define

begin_define
define|#
directive|define
name|MSG_FREE
parameter_list|(
name|PTR
parameter_list|)
define|\
value|MEMFREE(PTR)
end_define

begin_define
define|#
directive|define
name|SIG_ALLOC
parameter_list|(
name|PTR
parameter_list|)
define|\
value|MEMZALLOC(PTR, struct sscop_sig *, sizeof(struct sscop_sig))
end_define

begin_define
define|#
directive|define
name|SIG_FREE
parameter_list|(
name|PTR
parameter_list|)
define|\
value|MEMFREE(PTR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MEMINIT
parameter_list|()
define|\
value|MALLOC_DEFINE(M_NG_SSCOP_INS, "sscop_ins", "SSCOP instances");	\ 	MALLOC_DEFINE(M_NG_SSCOP_MSG, "sscop_msg", "SSCOP buffers");	\ 	MALLOC_DEFINE(M_NG_SSCOP_SIG, "sscop_sig", "SSCOP signals");	\ 	DECL_MSGQ_GET \ 	DECL_SIGQ_GET \ 	DECL_MBUF_ALLOC
end_define

begin_define
define|#
directive|define
name|MEMZALLOC
parameter_list|(
name|PTR
parameter_list|,
name|CAST
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|((PTR) = (CAST)malloc((SIZE), M_NG_SSCOP_INS, M_NOWAIT | M_ZERO))
end_define

begin_define
define|#
directive|define
name|MEMFREE
parameter_list|(
name|PTR
parameter_list|)
define|\
value|free((PTR), M_NG_SSCOP_INS)
end_define

begin_define
define|#
directive|define
name|MSG_ALLOC
parameter_list|(
name|PTR
parameter_list|)
define|\
value|((PTR) = malloc(sizeof(struct sscop_msg),			\ 	    M_NG_SSCOP_MSG, M_NOWAIT | M_ZERO))
end_define

begin_define
define|#
directive|define
name|MSG_FREE
parameter_list|(
name|PTR
parameter_list|)
define|\
value|free((PTR), M_NG_SSCOP_MSG)
end_define

begin_define
define|#
directive|define
name|SIG_ALLOC
parameter_list|(
name|PTR
parameter_list|)
define|\
value|((PTR) = malloc(sizeof(struct sscop_sig),			\ 	    M_NG_SSCOP_SIG, M_NOWAIT | M_ZERO))
end_define

begin_define
define|#
directive|define
name|SIG_FREE
parameter_list|(
name|PTR
parameter_list|)
define|\
value|free((PTR), M_NG_SSCOP_SIG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Timer support.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|callout
name|sscop_timer_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TIMER_INIT
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
value|ng_callout_init(&(S)->t_##T)
end_define

begin_define
define|#
directive|define
name|TIMER_STOP
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
value|do {						\ 	ng_uncallout(&(S)->t_##T, (S)->aarg);				\     } while (0)
end_define

begin_define
define|#
directive|define
name|TIMER_RESTART
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
value|do {					\ 	TIMER_STOP(S, T);						\ 	ng_callout(&(S)->t_##T, (S)->aarg, NULL,			\ 	    hz * (S)->timer##T / 1000, T##_func, (S), 0);		\     } while (0)
end_define

begin_define
define|#
directive|define
name|TIMER_ISACT
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
value|((S)->t_##T.c_flags& (CALLOUT_PENDING))
end_define

begin_comment
comment|/*  * This assumes, that the user argument is the node pointer.  */
end_comment

begin_define
define|#
directive|define
name|TIMER_FUNC
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
define|\
value|static void								\ T##_func(node_p node, hook_p hook, void *arg1, int arg2)		\ {									\ 	struct sscop *sscop = arg1;					\ 									\ 	VERBOSE(sscop, SSCOP_DBG_TIMER, (sscop, sscop->aarg,		\ 	    "timer_" #T " expired"));					\ 	sscop_signal(sscop, SIG_T_##N, NULL);				\ }
end_define

begin_comment
comment|/*  * Message queues  */
end_comment

begin_typedef
typedef|typedef
name|TAILQ_ENTRY
argument_list|(
argument|sscop_msg
argument_list|)
name|sscop_msgq_link_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|sscop_msgq
argument_list|,
argument|sscop_msg
argument_list|)
name|sscop_msgq_head_t
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|MSGQ_EMPTY
parameter_list|(
name|Q
parameter_list|)
value|TAILQ_EMPTY(Q)
end_define

begin_define
define|#
directive|define
name|MSGQ_INIT
parameter_list|(
name|Q
parameter_list|)
value|TAILQ_INIT(Q)
end_define

begin_define
define|#
directive|define
name|MSGQ_FOREACH
parameter_list|(
name|P
parameter_list|,
name|Q
parameter_list|)
value|TAILQ_FOREACH(P, Q, link)
end_define

begin_define
define|#
directive|define
name|MSGQ_REMOVE
parameter_list|(
name|Q
parameter_list|,
name|M
parameter_list|)
value|TAILQ_REMOVE(Q, M, link)
end_define

begin_define
define|#
directive|define
name|MSGQ_INSERT_BEFORE
parameter_list|(
name|B
parameter_list|,
name|M
parameter_list|)
value|TAILQ_INSERT_BEFORE(B, M, link)
end_define

begin_define
define|#
directive|define
name|MSGQ_APPEND
parameter_list|(
name|Q
parameter_list|,
name|M
parameter_list|)
value|TAILQ_INSERT_TAIL(Q, M, link)
end_define

begin_define
define|#
directive|define
name|MSGQ_PEEK
parameter_list|(
name|Q
parameter_list|)
value|TAILQ_FIRST((Q))
end_define

begin_define
define|#
directive|define
name|MSGQ_GET
parameter_list|(
name|Q
parameter_list|)
value|ng_sscop_msgq_get((Q))
end_define

begin_define
define|#
directive|define
name|DECL_MSGQ_GET
define|\
value|static __inline struct sscop_msg *					\ ng_sscop_msgq_get(struct sscop_msgq *q)					\ {									\ 	struct sscop_msg *m;						\ 									\ 	m = TAILQ_FIRST(q);						\ 	if (m != NULL)							\ 		TAILQ_REMOVE(q, m, link);				\ 	return (m);							\ }
end_define

begin_define
define|#
directive|define
name|MSGQ_CLEAR
parameter_list|(
name|Q
parameter_list|)
define|\
value|do {								\ 		struct sscop_msg *_m1, *_m2;				\ 									\ 		_m1 = TAILQ_FIRST(Q);					\ 		while (_m1 != NULL) {					\ 			_m2 = TAILQ_NEXT(_m1, link);			\ 			SSCOP_MSG_FREE(_m1);				\ 			_m1 = _m2;					\ 		}							\ 		TAILQ_INIT((Q));					\ 	} while (0)
end_define

begin_comment
comment|/*  * Signal queues  */
end_comment

begin_typedef
typedef|typedef
name|TAILQ_ENTRY
argument_list|(
argument|sscop_sig
argument_list|)
name|sscop_sigq_link_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|sscop_sigq
argument_list|,
argument|sscop_sig
argument_list|)
name|sscop_sigq_head_t
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|SIGQ_INIT
parameter_list|(
name|Q
parameter_list|)
value|TAILQ_INIT(Q)
end_define

begin_define
define|#
directive|define
name|SIGQ_APPEND
parameter_list|(
name|Q
parameter_list|,
name|S
parameter_list|)
value|TAILQ_INSERT_TAIL(Q, S, link)
end_define

begin_define
define|#
directive|define
name|SIGQ_EMPTY
parameter_list|(
name|Q
parameter_list|)
value|TAILQ_EMPTY(Q)
end_define

begin_define
define|#
directive|define
name|SIGQ_GET
parameter_list|(
name|Q
parameter_list|)
value|ng_sscop_sigq_get((Q))
end_define

begin_define
define|#
directive|define
name|DECL_SIGQ_GET
define|\
value|static __inline struct sscop_sig *					\ ng_sscop_sigq_get(struct sscop_sigq *q)					\ {									\ 	struct sscop_sig *s;						\ 									\ 	s = TAILQ_FIRST(q);						\ 	if (s != NULL)							\ 		TAILQ_REMOVE(q, s, link);				\ 	return (s);							\ }
end_define

begin_define
define|#
directive|define
name|SIGQ_MOVE
parameter_list|(
name|F
parameter_list|,
name|T
parameter_list|)
define|\
value|do {								\ 	struct sscop_sig *_s;						\ 									\ 	while (!TAILQ_EMPTY(F)) {					\ 		_s = TAILQ_FIRST(F);					\ 		TAILQ_REMOVE(F, _s, link);				\ 		TAILQ_INSERT_TAIL(T, _s, link);				\ 	}								\     } while (0)
end_define

begin_define
define|#
directive|define
name|SIGQ_PREPEND
parameter_list|(
name|F
parameter_list|,
name|T
parameter_list|)
define|\
value|do {								\ 	struct sscop_sig *_s;						\ 									\ 	while (!TAILQ_EMPTY(F)) {					\ 		_s = TAILQ_LAST(F, sscop_sigq);				\ 		TAILQ_REMOVE(F, _s, link);				\ 		TAILQ_INSERT_HEAD(T, _s, link);				\ 	}								\     } while (0)
end_define

begin_define
define|#
directive|define
name|SIGQ_CLEAR
parameter_list|(
name|Q
parameter_list|)
define|\
value|do {								\ 	struct sscop_sig *_s1, *_s2;					\ 									\ 	_s1 = TAILQ_FIRST(Q);						\ 	while (_s1 != NULL) {						\ 		_s2 = TAILQ_NEXT(_s1, link);				\ 		SSCOP_MSG_FREE(_s1->msg);				\ 		SIG_FREE(_s1);						\ 		_s1 = _s2;						\ 	}								\ 	TAILQ_INIT(Q);							\     } while (0)
end_define

begin_comment
comment|/*  * Message buffers  */
end_comment

begin_define
define|#
directive|define
name|MBUF_FREE
parameter_list|(
name|M
parameter_list|)
value|do { if ((M)) m_freem((M)); } while(0)
end_define

begin_define
define|#
directive|define
name|MBUF_DUP
parameter_list|(
name|M
parameter_list|)
value|m_copypacket((M), M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|MBUF_LEN
parameter_list|(
name|M
parameter_list|)
value|((size_t)(M)->m_pkthdr.len)
end_define

begin_comment
comment|/*  * Return the i-th word counted from the end of the buffer.  * i=-1 will return the last 32bit word, i=-2 the 2nd last.  * Assumes that there is enough space.  */
end_comment

begin_define
define|#
directive|define
name|MBUF_TRAIL32
parameter_list|(
name|M
parameter_list|,
name|I
parameter_list|)
value|ng_sscop_mbuf_trail32((M), (I))
end_define

begin_function
specifier|static
name|uint32_t
name|__inline
name|ng_sscop_mbuf_trail32
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|i
parameter_list|)
block|{
name|uint32_t
name|w
decl_stmt|;
name|m_copydata
argument_list|(
name|m
argument_list|,
name|m
operator|->
name|m_pkthdr
operator|.
name|len
operator|+
literal|4
operator|*
name|i
argument_list|,
literal|4
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|w
argument_list|)
expr_stmt|;
return|return
operator|(
name|ntohl
argument_list|(
name|w
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Strip 32bit value from the end  */
end_comment

begin_define
define|#
directive|define
name|MBUF_STRIP32
parameter_list|(
name|M
parameter_list|)
value|ng_sscop_mbuf_strip32((M))
end_define

begin_function
specifier|static
name|uint32_t
name|__inline
name|ng_sscop_mbuf_strip32
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|uint32_t
name|w
decl_stmt|;
name|m_copydata
argument_list|(
name|m
argument_list|,
name|m
operator|->
name|m_pkthdr
operator|.
name|len
operator|-
literal|4
argument_list|,
literal|4
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|w
argument_list|)
expr_stmt|;
name|m_adj
argument_list|(
name|m
argument_list|,
operator|-
literal|4
argument_list|)
expr_stmt|;
return|return
operator|(
name|ntohl
argument_list|(
name|w
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|MBUF_GET32
parameter_list|(
name|M
parameter_list|)
value|ng_sscop_mbuf_get32((M))
end_define

begin_function
specifier|static
name|uint32_t
name|__inline
name|ng_sscop_mbuf_get32
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|uint32_t
name|w
decl_stmt|;
name|m_copydata
argument_list|(
name|m
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|w
argument_list|)
expr_stmt|;
name|m_adj
argument_list|(
name|m
argument_list|,
literal|4
argument_list|)
expr_stmt|;
return|return
operator|(
name|ntohl
argument_list|(
name|w
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Append a 32bit value to an mbuf. Failures are ignored.  */
end_comment

begin_define
define|#
directive|define
name|MBUF_APPEND32
parameter_list|(
name|M
parameter_list|,
name|W
parameter_list|)
define|\
value|do {								\ 	uint32_t _w = (W);						\ 									\ 	_w = htonl(_w);							\ 	m_copyback((M), (M)->m_pkthdr.len, 4, (caddr_t)&_w);		\     } while (0)
end_define

begin_comment
comment|/*  * Pad a message to a multiple of four byte and return the amount of padding  * Failures are ignored.  */
end_comment

begin_define
define|#
directive|define
name|MBUF_PAD4
parameter_list|(
name|M
parameter_list|)
value|ng_sscop_mbuf_pad4((M))
end_define

begin_function
specifier|static
name|u_int
name|__inline
name|ng_sscop_mbuf_pad4
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
specifier|static
name|u_char
name|pad
index|[
literal|4
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|int
name|len
init|=
name|m
operator|->
name|m_pkthdr
operator|.
name|len
decl_stmt|;
name|int
name|npad
init|=
literal|3
operator|-
operator|(
operator|(
name|len
operator|+
literal|3
operator|)
operator|&
literal|3
operator|)
decl_stmt|;
if|if
condition|(
name|npad
operator|!=
literal|0
condition|)
name|m_copyback
argument_list|(
name|m
argument_list|,
name|len
argument_list|,
name|npad
argument_list|,
operator|(
name|caddr_t
operator|)
name|pad
argument_list|)
expr_stmt|;
return|return
operator|(
name|npad
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|MBUF_UNPAD
parameter_list|(
name|M
parameter_list|,
name|P
parameter_list|)
value|do { if( (P)> 0) m_adj((M), -(P)); } while (0)
end_define

begin_comment
comment|/*  * Allocate a message that will probably hold N bytes.  */
end_comment

begin_define
define|#
directive|define
name|MBUF_ALLOC
parameter_list|(
name|N
parameter_list|)
value|ng_sscop_mbuf_alloc((N))
end_define

begin_define
define|#
directive|define
name|DECL_MBUF_ALLOC
define|\
value|static __inline struct mbuf *						\ ng_sscop_mbuf_alloc(size_t n)						\ {									\ 	struct mbuf *m;							\ 									\ 	MGETHDR(m, M_NOWAIT, MT_DATA);					\ 	if (m != NULL) {						\ 		m->m_len = 0;						\ 		m->m_pkthdr.len = 0;					\ 		if (n> MHLEN) {					\ 			MCLGET(m, M_NOWAIT);				\ 			if (!(m->m_flags& M_EXT)){			\ 				m_free(m);				\ 				m = NULL;				\ 			}						\ 		}							\ 	}								\ 	return (m);							\ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SSCOP_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|X
parameter_list|)
value|KASSERT(X, (#X))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

