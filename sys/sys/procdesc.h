begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Robert N. M. Watson  * All rights reserved.  *  * This software was developed at the University of Cambridge Computer  * Laboratory with support from a grant from Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PROCDESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PROCDESC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_comment
comment|/* struct selinfo */
end_comment

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_comment
comment|/*-  * struct procdesc describes a process descriptor, and essentially consists  * of two pointers -- one to the file descriptor, and one to the process.  * When both become NULL, the process descriptor will be freed.  An important  * invariant is that there is only ever one process descriptor for a process,  * so a single file pointer will suffice.  *  * Locking key:  * (c) - Constant after initial setup.  * (p) - Protected by the process descriptor mutex.  * (r) - Atomic reference count.  * (s) - Protected by selinfo.  * (t) - Protected by the proctree_lock  */
end_comment

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sigio
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|procdesc
block|{
comment|/* 	 * Basic process descriptor state: the process, a cache of its pid to 	 * satisfy queries after the process exits, and process descriptor 	 * refcount. 	 */
name|struct
name|proc
modifier|*
name|pd_proc
decl_stmt|;
comment|/* (t) Process. */
name|pid_t
name|pd_pid
decl_stmt|;
comment|/* (c) Cached pid. */
name|u_int
name|pd_refcount
decl_stmt|;
comment|/* (r) Reference count. */
comment|/* 	 * In-flight data and notification of events. 	 */
name|int
name|pd_flags
decl_stmt|;
comment|/* (p) PD_ flags. */
name|struct
name|selinfo
name|pd_selinfo
decl_stmt|;
comment|/* (p) Event notification. */
name|struct
name|mtx
name|pd_lock
decl_stmt|;
comment|/* Protect data + events. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Locking macros for the procdesc itself.  */
end_comment

begin_define
define|#
directive|define
name|PROCDESC_LOCK_DESTROY
parameter_list|(
name|pd
parameter_list|)
value|mtx_destroy(&(pd)->pd_lock)
end_define

begin_define
define|#
directive|define
name|PROCDESC_LOCK_INIT
parameter_list|(
name|pd
parameter_list|)
value|mtx_init(&(pd)->pd_lock, "procdesc", NULL, \ 				    MTX_DEF)
end_define

begin_define
define|#
directive|define
name|PROCDESC_LOCK
parameter_list|(
name|pd
parameter_list|)
value|mtx_lock(&(pd)->pd_lock)
end_define

begin_define
define|#
directive|define
name|PROCDESC_UNLOCK
parameter_list|(
name|pd
parameter_list|)
value|mtx_unlock(&(pd)->pd_lock)
end_define

begin_comment
comment|/*  * Flags for the pd_flags field.  */
end_comment

begin_define
define|#
directive|define
name|PDF_CLOSED
value|0x00000001
end_define

begin_comment
comment|/* Descriptor has closed. */
end_comment

begin_define
define|#
directive|define
name|PDF_SELECTED
value|0x00000002
end_define

begin_comment
comment|/* Issue selwakeup(). */
end_comment

begin_define
define|#
directive|define
name|PDF_EXITED
value|0x00000004
end_define

begin_comment
comment|/* Process exited. */
end_comment

begin_define
define|#
directive|define
name|PDF_DAEMON
value|0x00000008
end_define

begin_comment
comment|/* Don't exit when procdesc closes. */
end_comment

begin_comment
comment|/*  * In-kernel interfaces to process descriptors.  */
end_comment

begin_function_decl
name|int
name|procdesc_exit
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procdesc_find
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|int
name|fd
parameter_list|,
name|cap_rights_t
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kern_pdgetpid
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|int
name|fd
parameter_list|,
name|cap_rights_t
modifier|*
parameter_list|,
name|pid_t
modifier|*
name|pidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|procdesc_new
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|procdesc_finit
parameter_list|(
name|struct
name|procdesc
modifier|*
parameter_list|,
name|struct
name|file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|procdesc_pid
parameter_list|(
name|struct
name|file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|procdesc_reap
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * Process descriptor system calls.  */
end_comment

begin_struct_decl
struct_decl|struct
name|rusage
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|pdfork
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pdkill
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pdgetpid
parameter_list|(
name|int
parameter_list|,
name|pid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Flags which can be passed to pdfork(2).  */
end_comment

begin_define
define|#
directive|define
name|PD_DAEMON
value|0x00000001
end_define

begin_comment
comment|/* Don't exit when procdesc closes. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_PROCDESC_H_ */
end_comment

end_unit

