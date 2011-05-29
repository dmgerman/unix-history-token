begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 The FreeBSD Project  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PROC_H_
end_define

begin_struct
struct|struct
name|mdthread
block|{
name|int
name|md_spinlock_count
decl_stmt|;
comment|/* (k) */
name|int
name|md_saved_intr
decl_stmt|;
comment|/* (k) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdproc
block|{
name|int
name|__dummy
decl_stmt|;
comment|/* Avoid having an empty struct. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|1088
end_define

begin_define
define|#
directive|define
name|KINFO_PROC32_SIZE
value|768
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|syscall_args
block|{
name|u_int
name|code
decl_stmt|;
name|struct
name|sysent
modifier|*
name|callp
decl_stmt|;
name|register_t
modifier|*
name|args
decl_stmt|;
name|register_t
name|args32
index|[
literal|8
index|]
decl_stmt|;
name|int
name|narg
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HAVE_SYSCALL_ARGS_DEF
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PROC_H_ */
end_comment

end_unit

