begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003 Alexander Kabaev.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/kse.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_expr_stmt
name|__strong_reference
argument_list|(
name|clock_gettime
argument_list|,
name|_thr_clock_gettime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|kse_exit
argument_list|,
name|_thr_kse_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|kse_wakeup
argument_list|,
name|_thr_kse_wakeup
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|kse_create
argument_list|,
name|_thr_kse_create
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|kse_thr_interrupt
argument_list|,
name|_thr_kse_thr_interrupt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|kse_release
argument_list|,
name|_thr_kse_release
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|kse_switchin
argument_list|,
name|_thr_kse_switchin
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|sigaction
argument_list|,
name|_thr_sigaction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|sigprocmask
argument_list|,
name|_thr_sigprocmask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|sigemptyset
argument_list|,
name|_thr_sigemptyset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|sigaddset
argument_list|,
name|_thr_sigaddset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|sigfillset
argument_list|,
name|_thr_sigfillset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|sigismember
argument_list|,
name|_thr_sigismember
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|sigdelset
argument_list|,
name|_thr_sigdelset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|memset
argument_list|,
name|_thr_memset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|memcpy
argument_list|,
name|_thr_memcpy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|strcpy
argument_list|,
name|_thr_strcpy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|strlen
argument_list|,
name|_thr_strlen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|bzero
argument_list|,
name|_thr_bzero
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|bcopy
argument_list|,
name|_thr_bcopy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sys_write
argument_list|,
name|_thr__sys_write
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sys_sigtimedwait
argument_list|,
name|_thr__sys_sigtimedwait
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

