begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Lock definitions used in both libc and libpthread.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPINLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPINLOCK_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * Lock structure with room for debugging information.  */
end_comment

begin_struct
struct|struct
name|_spinlock
block|{
specifier|volatile
name|long
name|access_lock
decl_stmt|;
specifier|volatile
name|long
name|lock_owner
decl_stmt|;
specifier|volatile
name|char
modifier|*
name|fname
decl_stmt|;
specifier|volatile
name|int
name|lineno
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_spinlock
name|spinlock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SPINLOCK_INITIALIZER
value|{ 0, 0, 0, 0 }
end_define

begin_define
define|#
directive|define
name|_SPINUNLOCK
parameter_list|(
name|_lck
parameter_list|)
value|_spinunlock(_lck);
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LOCK_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|_SPINLOCK
parameter_list|(
name|_lck
parameter_list|)
value|_spinlock_debug(_lck, __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_SPINLOCK
parameter_list|(
name|_lck
parameter_list|)
value|_spinlock(_lck)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Thread function prototype definitions:  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|long
name|_atomic_lock
parameter_list|(
specifier|volatile
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_spinlock
parameter_list|(
name|spinlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_spinunlock
parameter_list|(
name|spinlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_spinlock_debug
parameter_list|(
name|spinlock_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPINLOCK_H_ */
end_comment

end_unit

