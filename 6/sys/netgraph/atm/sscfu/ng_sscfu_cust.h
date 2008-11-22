begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Customisation of the SSCFU code to ng_sscfu.  *  * $FreeBSD$  */
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
file|<sys/callout.h>
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
file|<machine/stdarg.h>
end_include

begin_comment
comment|/*  * Allocate zeroed or non-zeroed memory of some size and cast it.  * Return NULL on failure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSCFU_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|MEMINIT
parameter_list|()
define|\
value|MALLOC_DECLARE(M_NG_SSCFU); \ 	DECL_SIGQ_GET
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
value|((PTR) = (CAST)malloc((SIZE), M_NG_SSCFU, M_NOWAIT | M_ZERO))
end_define

begin_define
define|#
directive|define
name|MEMFREE
parameter_list|(
name|PTR
parameter_list|)
define|\
value|free(PTR, M_NG_SSCFU)
end_define

begin_define
define|#
directive|define
name|SIG_ALLOC
parameter_list|(
name|PTR
parameter_list|)
define|\
value|MEMZALLOC(PTR, struct sscfu_sig *, sizeof(struct sscfu_sig))
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
value|MALLOC_DEFINE(M_NG_SSCFU_INS, "sscfu_ins", "SSCFU instances");	\ 	MALLOC_DEFINE(M_NG_SSCFU_SIG, "sscfu_sig", "SSCFU signals");	\ 	DECL_SIGQ_GET
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
value|((PTR) = (CAST)malloc((SIZE), M_NG_SSCFU_INS, M_NOWAIT | M_ZERO))
end_define

begin_define
define|#
directive|define
name|MEMFREE
parameter_list|(
name|PTR
parameter_list|)
define|\
value|FREE(PTR, M_NG_SSCFU_INS)
end_define

begin_define
define|#
directive|define
name|SIG_ALLOC
parameter_list|(
name|PTR
parameter_list|)
define|\
value|((PTR) = malloc(sizeof(struct sscfu_sig),			\ 	    M_NG_SSCFU_SIG, M_NOWAIT | M_ZERO))
end_define

begin_define
define|#
directive|define
name|SIG_FREE
parameter_list|(
name|PTR
parameter_list|)
define|\
value|FREE(PTR, M_NG_SSCFU_SIG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Signal queues  */
end_comment

begin_typedef
typedef|typedef
name|TAILQ_ENTRY
argument_list|(
argument|sscfu_sig
argument_list|)
name|sscfu_sigq_link_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|sscfu_sigq
argument_list|,
argument|sscfu_sig
argument_list|)
name|sscfu_sigq_head_t
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
name|SIGQ_GET
parameter_list|(
name|Q
parameter_list|)
value|ng_sscfu_sigq_get((Q))
end_define

begin_define
define|#
directive|define
name|DECL_SIGQ_GET
define|\
value|static __inline struct sscfu_sig *					\ ng_sscfu_sigq_get(struct sscfu_sigq *q)					\ {									\ 	struct sscfu_sig *s;						\ 									\ 	s = TAILQ_FIRST(q);						\ 	if (s != NULL)							\ 		TAILQ_REMOVE(q, s, link);				\ 	return (s);							\ }
end_define

begin_define
define|#
directive|define
name|SIGQ_CLEAR
parameter_list|(
name|Q
parameter_list|)
define|\
value|do {								\ 	struct sscfu_sig *_s1, *_s2;					\ 									\ 	_s1 = TAILQ_FIRST(Q);						\ 	while (_s1 != NULL) {						\ 		_s2 = TAILQ_NEXT(_s1, link);				\ 		if (_s1->m)						\ 			MBUF_FREE(_s1->m);				\ 		SIG_FREE(_s1);						\ 		_s1 = _s2;						\ 	}								\ 	TAILQ_INIT(Q);							\     } while (0)
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
value|m_freem(M)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SSCFU_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|S
parameter_list|)
value|KASSERT(S, (#S))
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
name|S
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

