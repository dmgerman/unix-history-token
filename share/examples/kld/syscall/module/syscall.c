begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Assar Westerlund  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/*  * The function for implementing the syscall.  */
end_comment

begin_function
specifier|static
name|int
name|hello
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|printf
argument_list|(
literal|"hello kernel\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * The `sysent' for the new syscall  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|sysent
name|hello_sysent
init|=
block|{
literal|0
block|,
comment|/* sy_narg */
name|hello
comment|/* sy_call */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The offset in sysent where the syscall is allocated.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|offset
init|=
name|NO_SYSCALL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The function called at load/unload.  */
end_comment

begin_function
specifier|static
name|int
name|load
parameter_list|(
name|struct
name|module
modifier|*
name|module
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|MOD_LOAD
case|:
name|printf
argument_list|(
literal|"syscall loaded at %d\n"
argument_list|,
name|offset
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
name|printf
argument_list|(
literal|"syscall unloaded from %d\n"
argument_list|,
name|offset
argument_list|)
expr_stmt|;
break|break;
default|default :
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
return|return
name|error
return|;
block|}
end_function

begin_expr_stmt
name|SYSCALL_MODULE
argument_list|(
name|syscall
argument_list|,
operator|&
name|offset
argument_list|,
operator|&
name|hello_sysent
argument_list|,
name|load
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

