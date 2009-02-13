begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Customisation of signalling source to the NG environment.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
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
file|<netgraph/atm/ngatmbase.h>
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
value|KASSERT(E,M)
end_define

begin_comment
comment|/*  * Memory  */
end_comment

begin_enum
enum|enum
name|unimem
block|{
name|UNIMEM_INS
init|=
literal|0
block|,
name|UNIMEM_ALL
block|,
name|UNIMEM_SIG
block|,
name|UNIMEM_CALL
block|,
name|UNIMEM_PARTY
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|UNIMEM_TYPES
value|5
end_define

begin_function_decl
name|void
modifier|*
name|ng_uni_malloc
parameter_list|(
name|enum
name|unimem
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_uni_free
parameter_list|(
name|enum
name|unimem
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|INS_ALLOC
parameter_list|()
value|ng_uni_malloc(UNIMEM_INS, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|INS_FREE
parameter_list|(
name|P
parameter_list|)
value|ng_uni_free(UNIMEM_INS, P, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|UNI_ALLOC
parameter_list|()
value|ng_uni_malloc(UNIMEM_ALL, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|UNI_FREE
parameter_list|(
name|P
parameter_list|)
value|ng_uni_free(UNIMEM_ALL, P, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|SIG_ALLOC
parameter_list|()
value|ng_uni_malloc(UNIMEM_SIG, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|SIG_FREE
parameter_list|(
name|P
parameter_list|)
value|ng_uni_free(UNIMEM_SIG, P, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|CALL_ALLOC
parameter_list|()
value|ng_uni_malloc(UNIMEM_CALL, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|CALL_FREE
parameter_list|(
name|P
parameter_list|)
value|ng_uni_free(UNIMEM_CALL, P, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|PARTY_ALLOC
parameter_list|()
value|ng_uni_malloc(UNIMEM_PARTY, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|PARTY_FREE
parameter_list|(
name|P
parameter_list|)
value|ng_uni_free(UNIMEM_PARTY, P, __FILE__, __LINE__)
end_define

begin_comment
comment|/*  * Timers  */
end_comment

begin_struct
struct|struct
name|uni_timer
block|{
name|struct
name|callout
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
value|ng_callout_init(&(X)->T.c)
end_define

begin_define
define|#
directive|define
name|_TIMER_DESTROY
parameter_list|(
name|UNI
parameter_list|,
name|FIELD
parameter_list|)
value|_TIMER_STOP(UNI,FIELD)
end_define

begin_define
define|#
directive|define
name|_TIMER_STOP
parameter_list|(
name|UNI
parameter_list|,
name|FIELD
parameter_list|)
value|do {						\ 	ng_uncallout(&FIELD.c, (UNI)->arg);					\     } while (0)
end_define

begin_define
define|#
directive|define
name|TIMER_ISACT
parameter_list|(
name|UNI
parameter_list|,
name|T
parameter_list|)
value|((UNI)->T.c.c_flags& (CALLOUT_ACTIVE |	\ 							CALLOUT_PENDING))
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
value|do {			\ 	_TIMER_STOP(UNI, FIELD);					\ 	ng_callout(&FIELD.c, (UNI)->arg, NULL,				\ 	    hz * (DUE) / 1000, FUNC, (ARG), 0);				\     } while (0)
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
value|static void F(struct uni *);						\ static void								\ _##T##_func(node_p node, hook_p hook, void *arg1, int arg2)		\ {									\ 	struct uni *uni = (struct uni *)arg1;				\ 									\ 	(F)(uni);							\ 	uni_work(uni);							\ }
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
value|static void F(struct call *);						\ static void								\ _##T##_func(node_p node, hook_p hook, void *arg1, int arg2)		\ {									\ 	struct call *call = (struct call *)arg1;			\ 	struct uni *uni = call->uni;					\ 									\ 	(F)(call);							\ 	uni_work(uni);							\ }
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
value|static void F(struct party *);						\ static void								\ _##T##_func(node_p node, hook_p hook, void *arg1, int arg2)		\ {									\ 	struct party *party = (struct party *)arg1;			\ 	struct uni *uni = party->call->uni;				\ 									\ 	(F)(party);							\ 	uni_work(uni);							\ }
end_define

begin_decl_stmt
specifier|extern
name|size_t
name|unimem_sizes
index|[
name|UNIMEM_TYPES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UNICORE
define|\
value|size_t unimem_sizes[UNIMEM_TYPES] = {					\ 	[UNIMEM_INS]	= sizeof(struct uni),				\ 	[UNIMEM_ALL]	= sizeof(struct uni_all),			\ 	[UNIMEM_SIG]	= sizeof(struct sig),				\ 	[UNIMEM_CALL]	= sizeof(struct call),				\ 	[UNIMEM_PARTY]	= sizeof(struct party)				\ };
end_define

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|T
parameter_list|,
name|F
parameter_list|,
name|L
parameter_list|)
value|bcopy((F), (T), (L))
end_define

end_unit

