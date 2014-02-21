begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 SÃ¸ren Schmidt  * Copyright (c) 1994 Sean Eric Fagan  * Copyright (c) 1995 Steven Wallace  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_types.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_signal.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_proto.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_isc_syscall.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|sysent
name|isc_sysent
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|ibcs2_isc
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|ibcs2_isc_args
modifier|*
name|uap
parameter_list|)
block|{
name|struct
name|trapframe
modifier|*
name|tf
init|=
name|td
operator|->
name|td_frame
decl_stmt|;
name|struct
name|sysent
modifier|*
name|callp
decl_stmt|;
name|u_int
name|code
decl_stmt|;
name|int
name|error
decl_stmt|;
name|code
operator|=
operator|(
name|tf
operator|->
name|tf_eax
operator|&
literal|0xffffff00
operator|)
operator|>>
literal|8
expr_stmt|;
name|callp
operator|=
operator|&
name|isc_sysent
index|[
name|code
index|]
expr_stmt|;
if|if
condition|(
name|code
operator|<
name|IBCS2_ISC_MAXSYSCALL
condition|)
name|error
operator|=
call|(
modifier|*
name|callp
operator|->
name|sy_call
call|)
argument_list|(
name|td
argument_list|,
operator|(
name|void
operator|*
operator|)
name|uap
argument_list|)
expr_stmt|;
else|else
name|error
operator|=
name|ENOSYS
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

end_unit

