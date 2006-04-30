begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/libngatm/unicust.h,v 1.4 2003/09/19 13:10:35 hbb Exp $  *  * Customisation of signalling source to user space.  */
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
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|E
parameter_list|,
name|M
parameter_list|)
value|assert(E)
end_define

begin_function
specifier|static
name|__inline__
name|void
modifier|*
name|mzalloc
parameter_list|(
name|size_t
name|s
parameter_list|)
block|{
name|void
modifier|*
name|ptr
init|=
name|malloc
argument_list|(
name|s
argument_list|)
decl_stmt|;
if|if
condition|(
name|ptr
condition|)
name|bzero
argument_list|(
name|ptr
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|ptr
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|INS_ALLOC
parameter_list|()
value|mzalloc(sizeof(struct uni))
end_define

begin_define
define|#
directive|define
name|INS_FREE
parameter_list|(
name|P
parameter_list|)
value|free(P)
end_define

begin_define
define|#
directive|define
name|UNI_ALLOC
parameter_list|()
value|mzalloc(sizeof(struct uni_all))
end_define

begin_define
define|#
directive|define
name|UNI_FREE
parameter_list|(
name|P
parameter_list|)
value|free(P)
end_define

begin_define
define|#
directive|define
name|SIG_ALLOC
parameter_list|()
value|mzalloc(sizeof(struct sig))
end_define

begin_define
define|#
directive|define
name|SIG_FREE
parameter_list|(
name|P
parameter_list|)
value|free(P)
end_define

begin_define
define|#
directive|define
name|CALL_ALLOC
parameter_list|()
value|mzalloc(sizeof(struct call))
end_define

begin_define
define|#
directive|define
name|CALL_FREE
parameter_list|(
name|P
parameter_list|)
value|free(P)
end_define

begin_define
define|#
directive|define
name|PARTY_ALLOC
parameter_list|()
value|mzalloc(sizeof(struct party))
end_define

begin_define
define|#
directive|define
name|PARTY_FREE
parameter_list|(
name|P
parameter_list|)
value|free(P)
end_define

begin_comment
comment|/*  * Timers  */
end_comment

begin_struct
struct|struct
name|uni_timer
block|{
name|void
modifier|*
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_TIMER_INIT
parameter_list|(
name|X
parameter_list|,
name|T
parameter_list|)
value|(X)->T.c = NULL
end_define

begin_define
define|#
directive|define
name|_TIMER_DESTROY
parameter_list|(
name|U
parameter_list|,
name|F
parameter_list|)
value|_TIMER_STOP(U,F)
end_define

begin_define
define|#
directive|define
name|_TIMER_STOP
parameter_list|(
name|U
parameter_list|,
name|F
parameter_list|)
define|\
value|do {							\ 	if (F.c != NULL) {					\ 		(U)->funcs->stop_timer(U, U->arg, F.c);		\ 		F.c = NULL;					\ 	}							\     } while(0)
end_define

begin_define
define|#
directive|define
name|_TIMER_START
parameter_list|(
name|UNI
parameter_list|,
name|ARG
parameter_list|,
name|FIELD
parameter_list|,
name|DUE
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|(void)(FIELD.c = (UNI)->funcs->start_timer(UNI,		\ 	    UNI->arg, DUE, FUNC, ARG))
end_define

begin_define
define|#
directive|define
name|TIMER_ISACT
parameter_list|(
name|X
parameter_list|,
name|T
parameter_list|)
value|(X->T.c != NULL)
end_define

begin_define
define|#
directive|define
name|TIMER_FUNC_UNI
parameter_list|(
name|T
parameter_list|,
name|F
parameter_list|)
define|\
value|static void F(struct uni *);						\ static void								\ _##T##_func(void *varg)							\ {									\ 	struct uni *uni = (struct uni *)varg;				\ 	uni->T.c = NULL;						\ 	(F)(uni);							\ }
end_define

begin_comment
comment|/*  * Be careful: call may be invalid after the call to F  */
end_comment

begin_define
define|#
directive|define
name|TIMER_FUNC_CALL
parameter_list|(
name|T
parameter_list|,
name|F
parameter_list|)
define|\
value|static void F(struct call *);						\ static void								\ _##T##_func(void *varg)							\ {									\ 	struct call *call = (struct call *)varg;			\ 	call->T.c = NULL;						\ 	(F)(call);							\ }
end_define

begin_comment
comment|/*  * Be careful: call/party may be invalid after the call to F  */
end_comment

begin_define
define|#
directive|define
name|TIMER_FUNC_PARTY
parameter_list|(
name|T
parameter_list|,
name|F
parameter_list|)
define|\
value|static void F(struct party *);						\ static void								\ _##T##_func(void *varg)							\ {									\ 	struct party *party = (struct party *)varg;			\ 	party->T.c = NULL;						\ 	(F)(party);							\ }
end_define

end_unit

