begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)callout.h	8.2 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__CALLOUT_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS__CALLOUT_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|lock_object
struct_decl|;
end_struct_decl

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|callout_list
argument_list|,
name|callout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|callout_slist
argument_list|,
name|callout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|callout_tailq
argument_list|,
name|callout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|void
name|callout_func_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|callout_args
block|{
name|sbintime_t
name|time
decl_stmt|;
comment|/* absolute time for the event */
name|sbintime_t
name|precision
decl_stmt|;
comment|/* delta allowed wrt opt */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* function argument */
name|callout_func_t
modifier|*
name|func
decl_stmt|;
comment|/* function to call */
name|int
name|flags
decl_stmt|;
comment|/* flags passed to callout_reset() */
name|int
name|cpu
decl_stmt|;
comment|/* CPU we're scheduled on */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|callout
block|{
union|union
block|{
name|LIST_ENTRY
argument_list|(
argument|callout
argument_list|)
name|le
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|callout
argument_list|)
name|sle
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|callout
argument_list|)
name|tqe
expr_stmt|;
block|}
name|c_links
union|;
name|sbintime_t
name|c_time
decl_stmt|;
comment|/* absolute time for the event */
name|sbintime_t
name|c_precision
decl_stmt|;
comment|/* delta allowed wrt opt */
name|void
modifier|*
name|c_arg
decl_stmt|;
comment|/* function argument */
name|callout_func_t
modifier|*
name|c_func
decl_stmt|;
comment|/* function to call */
name|struct
name|lock_object
modifier|*
name|c_lock
decl_stmt|;
comment|/* callback lock */
name|int
name|c_flags
decl_stmt|;
comment|/* state of this entry */
name|int
name|c_cpu
decl_stmt|;
comment|/* CPU we're scheduled on */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

