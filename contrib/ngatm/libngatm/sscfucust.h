begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/libngatm/sscfucust.h,v 1.4 2004/07/08 08:21:40 brandt Exp $  *  * Customisation of the SSCFU code for the user space library.  */
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
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SSCFU_DEBUG
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
define|\
value|free(PTR)
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
define|\
value|({									\ 	struct sscfu_sig *_s = NULL;					\ 									\ 	if(!TAILQ_EMPTY(Q)) {						\ 		_s = TAILQ_FIRST(Q);					\ 		TAILQ_REMOVE(Q, _s, link);				\ 	}								\ 	_s;								\     })
end_define

begin_define
define|#
directive|define
name|SIGQ_CLEAR
parameter_list|(
name|Q
parameter_list|)
define|\
value|do {								\ 	struct sscfu_sig *_s1, *_s2;					\ 									\ 	_s1 = TAILQ_FIRST(Q);						\ 	while(_s1 != NULL) {						\ 		_s2 = TAILQ_NEXT(_s1, link);				\ 		if(_s1->m)						\ 			MBUF_FREE(_s1->m);				\ 		SIG_FREE(_s1);						\ 		_s1 = _s2;						\ 	}								\ 	TAILQ_INIT(Q);							\     } while(0)
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
value|uni_msg_destroy(M)
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
value|assert(S)
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

