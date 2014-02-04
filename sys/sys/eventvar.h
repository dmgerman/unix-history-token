begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000 Jonathan Lemon<jlemon@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EVENTVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EVENTVAR_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-servicable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/_task.h>
end_include

begin_define
define|#
directive|define
name|KQ_NEVENTS
value|8
end_define

begin_comment
comment|/* minimize copy{in,out} calls */
end_comment

begin_define
define|#
directive|define
name|KQEXTENT
value|256
end_define

begin_comment
comment|/* linear growth by this amount */
end_comment

begin_struct
struct|struct
name|kqueue
block|{
name|struct
name|mtx
name|kq_lock
decl_stmt|;
name|int
name|kq_refcnt
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|kqueue
argument_list|)
name|kq_list
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|knote
argument_list|)
name|kq_head
expr_stmt|;
comment|/* list of pending event */
name|int
name|kq_count
decl_stmt|;
comment|/* number of pending events */
name|struct
name|selinfo
name|kq_sel
decl_stmt|;
name|struct
name|sigio
modifier|*
name|kq_sigio
decl_stmt|;
name|struct
name|filedesc
modifier|*
name|kq_fdp
decl_stmt|;
name|int
name|kq_state
decl_stmt|;
define|#
directive|define
name|KQ_SEL
value|0x01
define|#
directive|define
name|KQ_SLEEP
value|0x02
define|#
directive|define
name|KQ_FLUXWAIT
value|0x04
comment|/* waiting for a in flux kn */
define|#
directive|define
name|KQ_ASYNC
value|0x08
define|#
directive|define
name|KQ_CLOSING
value|0x10
define|#
directive|define
name|KQ_TASKSCHED
value|0x20
comment|/* task scheduled */
define|#
directive|define
name|KQ_TASKDRAIN
value|0x40
comment|/* waiting for task to drain */
name|int
name|kq_knlistsize
decl_stmt|;
comment|/* size of knlist */
name|struct
name|klist
modifier|*
name|kq_knlist
decl_stmt|;
comment|/* list of knotes */
name|u_long
name|kq_knhashmask
decl_stmt|;
comment|/* size of knhash */
name|struct
name|klist
modifier|*
name|kq_knhash
decl_stmt|;
comment|/* hash table for knotes */
name|struct
name|task
name|kq_task
decl_stmt|;
name|struct
name|ucred
modifier|*
name|kq_cred
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_EVENTVAR_H_ */
end_comment

end_unit

