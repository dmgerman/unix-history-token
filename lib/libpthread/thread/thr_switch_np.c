begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Daniel Eischen<eischen@vigrid.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Daniel Eischen.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY DANIEL EISCHEN AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<pthread_np.h>
end_include

begin_include
include|#
directive|include
file|"pthread_private.h"
end_include

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_switch_add_np
name|=
name|_pthread_switch_add_np
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_switch_delete_np
name|=
name|_pthread_switch_delete_np
end_pragma

begin_function
name|int
name|_pthread_switch_add_np
parameter_list|(
name|pthread_switch_routine_t
name|routine
parameter_list|)
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|routine
operator|==
name|NULL
condition|)
comment|/* Return an invalid argument error: */
name|ret
operator|=
name|EINVAL
expr_stmt|;
else|else
comment|/* Shouldn't need a lock to protect this assigment. */
name|_sched_switch_hook
operator|=
name|routine
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
name|int
name|_pthread_switch_delete_np
parameter_list|(
name|pthread_switch_routine_t
name|routine
parameter_list|)
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|routine
operator|!=
name|_sched_switch_hook
condition|)
comment|/* Return an invalid argument error: */
name|ret
operator|=
name|EINVAL
expr_stmt|;
else|else
comment|/* Shouldn't need a lock to protect this assigment. */
name|_sched_switch_hook
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

