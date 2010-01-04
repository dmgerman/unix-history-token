begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010, David Xu<davidxu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__UMTX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__UMTX_H_
end_define

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_struct
struct|struct
name|umtx
block|{
specifier|volatile
name|unsigned
name|long
name|u_owner
decl_stmt|;
comment|/* Owner of the mutex. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|umutex
block|{
specifier|volatile
name|__lwpid_t
name|m_owner
decl_stmt|;
comment|/* Owner of the mutex */
name|__uint32_t
name|m_flags
decl_stmt|;
comment|/* Flags of the mutex */
name|__uint32_t
name|m_ceilings
index|[
literal|2
index|]
decl_stmt|;
comment|/* Priority protect ceiling */
name|__uint32_t
name|m_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ucond
block|{
specifier|volatile
name|__uint32_t
name|c_has_waiters
decl_stmt|;
comment|/* Has waiters in kernel */
name|__uint32_t
name|c_flags
decl_stmt|;
comment|/* Flags of the condition variable */
name|__uint32_t
name|c_spare
index|[
literal|2
index|]
decl_stmt|;
comment|/* Spare space */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|urwlock
block|{
specifier|volatile
name|__int32_t
name|rw_state
decl_stmt|;
name|__uint32_t
name|rw_flags
decl_stmt|;
name|__uint32_t
name|rw_blocked_readers
decl_stmt|;
name|__uint32_t
name|rw_blocked_writers
decl_stmt|;
name|__uint32_t
name|rw_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_usem
block|{
specifier|volatile
name|__uint32_t
name|_has_waiters
decl_stmt|;
specifier|volatile
name|__uint32_t
name|_count
decl_stmt|;
name|__uint32_t
name|_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__UMTX_H_ */
end_comment

end_unit

