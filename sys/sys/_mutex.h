begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MUTEX_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MUTEX_TYPES_H_
end_define

begin_comment
comment|/*  * Sleep/spin mutex  */
end_comment

begin_struct
struct|struct
name|mtx
block|{
name|struct
name|lock_object
name|mtx_object
decl_stmt|;
comment|/* Common lock properties. */
specifier|volatile
name|uintptr_t
name|mtx_lock
decl_stmt|;
comment|/* owner (and state for sleep locks) */
specifier|volatile
name|u_int
name|mtx_recurse
decl_stmt|;
comment|/* number of recursive holds */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|thread
argument_list|)
name|mtx_blocked
expr_stmt|;
comment|/* threads blocked on this lock */
name|LIST_ENTRY
argument_list|(
argument|mtx
argument_list|)
name|mtx_contested
expr_stmt|;
comment|/* list of all contested locks */
comment|/* #ifdef MUTEX_PROFILING */
name|u_int64_t
name|acqtime
decl_stmt|;
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
comment|/* #endif */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_MUTEX_TYPES_H_ */
end_comment

end_unit

