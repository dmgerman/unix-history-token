begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Don't build these stubs into libc_r: */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_THREAD_SAFE
end_ifndef

begin_include
include|#
directive|include
file|"spinlock.h"
end_include

begin_comment
comment|/*  * Declare weak references in case the application is not linked  * with libpthread.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|_spinlock
name|=
name|_spinlock_stub
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|_spinlock_debug
name|=
name|_spinlock_debug_stub
end_pragma

begin_comment
comment|/*  * This function is a stub for the spinlock function in libpthread.  */
end_comment

begin_function
name|void
name|_spinlock_stub
parameter_list|(
name|spinlock_t
modifier|*
name|lck
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  * This function is a stub for the debug spinlock function in libpthread.  */
end_comment

begin_function
name|void
name|_spinlock_debug_stub
parameter_list|(
name|spinlock_t
modifier|*
name|lck
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|lineno
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

