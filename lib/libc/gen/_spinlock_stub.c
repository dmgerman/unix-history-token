begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"spinlock.h"
end_include

begin_comment
comment|/*  * Declare weak definitions in case the application is not linked  * with libpthread.  */
end_comment

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_atomic_lock_stub
argument_list|,
name|_atomic_lock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_spinlock_stub
argument_list|,
name|_spinlock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_spinunlock_stub
argument_list|,
name|_spinunlock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_spinlock_debug_stub
argument_list|,
name|_spinlock_debug
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This function is a stub for the _atomic_lock function in libpthread.  */
end_comment

begin_function
name|long
name|_atomic_lock_stub
parameter_list|(
specifier|volatile
name|long
modifier|*
name|lck
parameter_list|)
block|{
return|return
operator|(
literal|0L
operator|)
return|;
block|}
end_function

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
comment|/*  * This function is a stub for the spinunlock function in libpthread.  */
end_comment

begin_function
name|void
name|_spinunlock_stub
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

end_unit

