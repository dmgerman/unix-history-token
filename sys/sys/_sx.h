begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Attilio Rao<attilio@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible   *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__SX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__SX_H_
end_define

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_comment
comment|/*  * Shared/exclusive lock main structure definition.  *  * Note, to preserve compatibility we have extra fields from  * the previous implementation left over.  */
end_comment

begin_struct
struct|struct
name|sx
block|{
name|struct
name|lock_object
name|lock_object
decl_stmt|;
comment|/* was: struct mtx *sx_lock; */
specifier|volatile
name|uintptr_t
name|sx_lock
decl_stmt|;
comment|/* was: int sx_cnt; */
specifier|volatile
name|unsigned
name|sx_recurse
decl_stmt|;
comment|/* 	 * The following fields are unused but kept to preserve 	 * sizeof(struct sx) for 6.x compat. 	 */
name|struct
name|cv
name|sx_shrd_cv
decl_stmt|;
comment|/* unused */
name|int
name|sx_shrd_wcnt
decl_stmt|;
comment|/* unused */
name|struct
name|cv
name|sx_excl_cv
decl_stmt|;
comment|/* unused */
name|int
name|sx_excl_wcnt
decl_stmt|;
comment|/* unused */
name|struct
name|thread
modifier|*
name|sx_xholder
decl_stmt|;
comment|/* unused */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__SX_H_ */
end_comment

end_unit

