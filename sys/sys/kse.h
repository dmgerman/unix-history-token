begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2001 Julian Elischer<julian@freebsd.org>  * for the FreeBSD Foundation.  *  *  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible   *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_KSE_H
end_ifndef

begin_define
define|#
directive|define
name|SYS_KSE_H
end_define

begin_include
include|#
directive|include
file|<machine/kse.h>
end_include

begin_comment
comment|/*   * This file defines the structures needed for communication between  * the userland and the kernel when running a KSE-based threading system.  * The only programs that should see this file are the UTS and the kernel.  */
end_comment

begin_comment
comment|/*   * Each userland thread has one of these buried in it's   * Thread control structure somewhere.  */
end_comment

begin_struct
struct|struct
name|thread_mailbox
block|{
name|struct
name|thread_mailbox
modifier|*
name|next_completed
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|void
modifier|*
name|UTS_handle
decl_stmt|;
comment|/* The UTS can use this for anything */
name|union
name|kse_td_ctx
name|ctx
decl_stmt|;
comment|/* thread's saved context goes here. */
block|}
struct|;
end_struct

begin_comment
comment|/*   * You need to supply one of these as the argument to the   * kse_new() system call.  */
end_comment

begin_struct
struct|struct
name|kse_mailbox
block|{
name|struct
name|thread_mailbox
modifier|*
name|current_thread
decl_stmt|;
name|struct
name|thread_mailbox
modifier|*
name|completed_threads
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|void
modifier|*
name|UTS_handle
decl_stmt|;
comment|/* The UTS can use this for anything */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KEMBXF_CRITICAL
value|0x00000001
end_define

begin_struct
struct|struct
name|kse_global_mailbox
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GMBXF_CRITICAL
value|0x00000001
end_define

begin_comment
comment|/* some provisional sycalls: */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

