begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/utrap.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"fpu_extern.h"
end_include

begin_include
include|#
directive|include
file|"__sparc_utrap_private.h"
end_include

begin_function_decl
specifier|extern
name|ssize_t
name|__sys_write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sys_kill
parameter_list|(
name|pid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pid_t
name|__sys_getpid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|utrap_msg
index|[]
init|=
block|{
literal|"reserved"
block|,
literal|"instruction access exception"
block|,
literal|"instruction access error"
block|,
literal|"instruction access protection"
block|,
literal|"illtrap instruction"
block|,
literal|"illegal instruction"
block|,
literal|"privileged opcode"
block|,
literal|"floating point disabled"
block|,
literal|"floating point exception ieee 754"
block|,
literal|"floating point exception other"
block|,
literal|"tag overflow"
block|,
literal|"division by zero"
block|,
literal|"data access exception"
block|,
literal|"data access error"
block|,
literal|"data access protection"
block|,
literal|"memory address not aligned"
block|,
literal|"privileged action"
block|,
literal|"async data error"
block|,
literal|"trap instruction 16"
block|,
literal|"trap instruction 17"
block|,
literal|"trap instruction 18"
block|,
literal|"trap instruction 19"
block|,
literal|"trap instruction 20"
block|,
literal|"trap instruction 21"
block|,
literal|"trap instruction 22"
block|,
literal|"trap instruction 23"
block|,
literal|"trap instruction 24"
block|,
literal|"trap instruction 25"
block|,
literal|"trap instruction 26"
block|,
literal|"trap instruction 27"
block|,
literal|"trap instruction 28"
block|,
literal|"trap instruction 29"
block|,
literal|"trap instruction 30"
block|,
literal|"trap instruction 31"
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|__sparc_utrap
parameter_list|(
name|struct
name|utrapframe
modifier|*
name|uf
parameter_list|)
block|{
name|int
name|sig
decl_stmt|;
switch|switch
condition|(
name|uf
operator|->
name|uf_type
condition|)
block|{
case|case
name|UT_FP_EXCEPTION_IEEE_754
case|:
case|case
name|UT_FP_EXCEPTION_OTHER
case|:
name|sig
operator|=
name|__fpu_exception
argument_list|(
name|uf
argument_list|)
expr_stmt|;
break|break;
case|case
name|UT_ILLEGAL_INSTRUCTION
case|:
name|sig
operator|=
name|__emul_insn
argument_list|(
name|uf
argument_list|)
expr_stmt|;
break|break;
case|case
name|UT_MEM_ADDRESS_NOT_ALIGNED
case|:
name|sig
operator|=
name|__unaligned_fixup
argument_list|(
name|uf
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|sig
condition|)
block|{
name|__utrap_write
argument_list|(
literal|"__sparc_utrap: fatal "
argument_list|)
expr_stmt|;
name|__utrap_write
argument_list|(
name|utrap_msg
index|[
name|uf
operator|->
name|uf_type
index|]
argument_list|)
expr_stmt|;
name|__utrap_write
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|__utrap_kill_self
argument_list|(
name|sig
argument_list|)
expr_stmt|;
block|}
name|UF_DONE
argument_list|(
name|uf
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__utrap_write
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|int
name|berrno
decl_stmt|;
name|berrno
operator|=
name|errno
expr_stmt|;
name|__sys_write
argument_list|(
name|STDERR_FILENO
argument_list|,
name|str
argument_list|,
name|strlen
argument_list|(
name|str
argument_list|)
argument_list|)
expr_stmt|;
name|errno
operator|=
name|berrno
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__utrap_kill_self
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
name|int
name|berrno
decl_stmt|;
name|berrno
operator|=
name|errno
expr_stmt|;
name|__sys_kill
argument_list|(
name|__sys_getpid
argument_list|()
argument_list|,
name|sig
argument_list|)
expr_stmt|;
name|errno
operator|=
name|berrno
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__utrap_panic
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|__utrap_write
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|__utrap_write
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|__utrap_kill_self
argument_list|(
name|SIGKILL
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

