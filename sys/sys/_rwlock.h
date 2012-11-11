begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 John Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__RWLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__RWLOCK_H_
end_define

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_comment
comment|/*  * Reader/writer lock.  *  * All reader/writer lock implementations must always have a member  * called rw_lock.  Other locking primitive structures are not allowed to  * use this name for their members.  * If this rule needs to change, the bits in the reader/writer lock  * implementation must be modified appropriately.  */
end_comment

begin_struct
struct|struct
name|rwlock
block|{
name|struct
name|lock_object
name|lock_object
decl_stmt|;
specifier|volatile
name|uintptr_t
name|rw_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Members of struct rwlock_padalign must mirror members of struct rwlock.  * rwlock_padalign rwlocks can use the rwlock(9) API transparently without  * modification.  * Pad-aligned rwlocks used within structures should generally be the  * first member of the struct.  Otherwise, the compiler can generate  * additional padding for the struct to keep a correct alignment for  * the rwlock.  */
end_comment

begin_struct
struct|struct
name|rwlock_padalign
block|{
name|struct
name|lock_object
name|lock_object
decl_stmt|;
specifier|volatile
name|uintptr_t
name|rw_lock
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__RWLOCK_H_ */
end_comment

end_unit

