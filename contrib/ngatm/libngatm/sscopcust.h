begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/libngatm/sscopcust.h,v 1.4 2004/07/08 08:21:40 brandt Exp $  *  * Customisation of the SSCOP code for the user space library.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SSCOP_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<netnatm/unimsg.h>
end_include

begin_comment
comment|/*  * Allocate zeroed or non-zeroed memory of some size and cast it.  * Return NULL on failure.  */
end_comment

begin_define
define|#
directive|define
name|MEMINIT
parameter_list|()
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
value|do {				\ 	void *_m = malloc(SIZE);				\ 	if (_m != NULL)						\ 		bzero(_m, SIZE);				\ 	(PTR) = (CAST)_m;					\ } while(0)
end_define

begin_define
define|#
directive|define
name|MEMFREE
parameter_list|(
name|PTR
parameter_list|)
value|free(PTR);
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

begin_comment
comment|/*  * Timer support.  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
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
value|(S)->t_##T = NULL
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
value|do {						\ 	if ((S)->t_##T != NULL) {					\ 		(S)->funcs->stop_timer((S), (S)->aarg, (S)->t_##T);	\ 		(S)->t_##T = NULL;					\ 	}								\     } while(0)
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
value|do {						\ 	if ((S)->t_##T != NULL)						\ 		(S)->funcs->stop_timer((S), (S)->aarg, (S)->t_##T);	\ 	(S)->t_##T = (S)->funcs->start_timer((S), (S)->aarg,		\ 	    (S)->timer##T, T##_func);					\     } while(0)
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
value|((S)->t_##T != NULL)
end_define

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
value|static void								\ T##_func(void *varg)							\ {									\ 	struct sscop *sscop = varg;					\ 	VERBOSE(sscop, SSCOP_DBG_TIMER, (sscop, sscop->aarg,		\ 	    "timer_" #T " expired"));					\ 	sscop->t_##T = NULL;						\ 	sscop_signal(sscop, SIG_T_##N, NULL);				\ }
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
value|TAILQ_FOREACH(P,Q,link)
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
value|TAILQ_REMOVE(Q,M,link)
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
value|TAILQ_INSERT_BEFORE(B,M,link)
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
value|TAILQ_INSERT_TAIL(Q,M,link)
end_define

begin_define
define|#
directive|define
name|MSGQ_PEEK
parameter_list|(
name|Q
parameter_list|)
value|(TAILQ_EMPTY((Q)) ? NULL : TAILQ_FIRST((Q)))
end_define

begin_define
define|#
directive|define
name|MSGQ_GET
parameter_list|(
name|Q
parameter_list|)
define|\
value|({									\ 	struct sscop_msg *_m = NULL;					\ 									\ 	if(!TAILQ_EMPTY(Q)) {						\ 		_m = TAILQ_FIRST(Q);					\ 		TAILQ_REMOVE(Q, _m, link);				\ 	}								\ 	_m;								\     })
end_define

begin_define
define|#
directive|define
name|MSGQ_CLEAR
parameter_list|(
name|Q
parameter_list|)
define|\
value|do {								\ 		struct sscop_msg *_m1, *_m2;				\ 									\ 		_m1 = TAILQ_FIRST(Q);					\ 		while(_m1 != NULL) {					\ 			_m2 = TAILQ_NEXT(_m1, link);			\ 			SSCOP_MSG_FREE(_m1);				\ 			_m1 = _m2;					\ 		}							\ 		TAILQ_INIT((Q));					\ 	} while(0)
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
define|\
value|({									\ 	struct sscop_sig *_s = NULL;					\ 									\ 	if(!TAILQ_EMPTY(Q)) {						\ 		_s = TAILQ_FIRST(Q);					\ 		TAILQ_REMOVE(Q, _s, link);				\ 	}								\ 	_s;								\     })
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
value|do {								\ 	struct sscop_sig *_s;						\ 									\ 	while(!TAILQ_EMPTY(F)) {					\ 		_s = TAILQ_FIRST(F);					\ 		TAILQ_REMOVE(F, _s, link);				\ 		TAILQ_INSERT_TAIL(T, _s, link);				\ 	}								\     } while(0)
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
value|do {								\ 	struct sscop_sig *_s;						\ 									\ 	while(!TAILQ_EMPTY(F)) {					\ 		_s = TAILQ_LAST(F, sscop_sigq);				\ 		TAILQ_REMOVE(F, _s, link);				\ 		TAILQ_INSERT_HEAD(T, _s, link);				\ 	}								\     } while(0)
end_define

begin_define
define|#
directive|define
name|SIGQ_CLEAR
parameter_list|(
name|Q
parameter_list|)
define|\
value|do {								\ 	struct sscop_sig *_s1, *_s2;					\ 									\ 	_s1 = TAILQ_FIRST(Q);						\ 	while(_s1 != NULL) {						\ 		_s2 = TAILQ_NEXT(_s1, link);				\ 		SSCOP_MSG_FREE(_s1->msg);				\ 		SIG_FREE(_s1);						\ 		_s1 = _s2;						\ 	}								\ 	TAILQ_INIT(Q);							\     } while(0)
end_define

begin_comment
comment|/*  * Message buffers  */
end_comment

begin_comment
comment|/* Free a buffer (if there is one) */
end_comment

begin_define
define|#
directive|define
name|MBUF_FREE
parameter_list|(
name|M
parameter_list|)
value|do { if(M) uni_msg_destroy(M); } while(0)
end_define

begin_comment
comment|/* duplicate a buffer */
end_comment

begin_define
define|#
directive|define
name|MBUF_DUP
parameter_list|(
name|M
parameter_list|)
value|uni_msg_dup(M)
end_define

begin_comment
comment|/* compute current length */
end_comment

begin_define
define|#
directive|define
name|MBUF_LEN
parameter_list|(
name|M
parameter_list|)
value|uni_msg_len((M))
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
value|uni_msg_trail32((M), (I))
end_define

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
value|uni_msg_strip32((M))
end_define

begin_comment
comment|/*  * Strip 32bit value from head  */
end_comment

begin_define
define|#
directive|define
name|MBUF_GET32
parameter_list|(
name|M
parameter_list|)
value|uni_msg_get32((M))
end_define

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
value|uni_msg_append32((M), (W))
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
define|\
value|({									\ 	int _npad = 0;							\ 	while (uni_msg_len(M) % 4 != 0) {				\ 		uni_msg_append8((M), 0);				\ 		_npad++;						\ 	}								\ 	_npad;								\     })
end_define

begin_define
define|#
directive|define
name|MBUF_UNPAD
parameter_list|(
name|M
parameter_list|,
name|P
parameter_list|)
value|do { (M)->b_wptr -= (P); } while(0)
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
value|uni_msg_alloc(N)
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
value|assert(X)
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

