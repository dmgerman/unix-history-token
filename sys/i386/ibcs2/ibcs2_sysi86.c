begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Søren Schmidt  * Copyright (c) 1995 Steven Wallace  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	ibcs2_sysi86.c,v 1.1 1994/10/14 08:53:11 sos Exp  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
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
file|<i386/ibcs2/ibcs2_util.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_proto.h>
end_include

begin_define
define|#
directive|define
name|IBCS2_FP_NO
value|0
end_define

begin_comment
comment|/* no fp support */
end_comment

begin_define
define|#
directive|define
name|IBCS2_FP_SW
value|1
end_define

begin_comment
comment|/* software emulator */
end_comment

begin_define
define|#
directive|define
name|IBCS2_FP_287
value|2
end_define

begin_comment
comment|/* 80287 FPU */
end_comment

begin_define
define|#
directive|define
name|IBCS2_FP_387
value|3
end_define

begin_comment
comment|/* 80387 FPU */
end_comment

begin_define
define|#
directive|define
name|SI86_FPHW
value|40
end_define

begin_define
define|#
directive|define
name|STIME
value|54
end_define

begin_define
define|#
directive|define
name|SETNAME
value|56
end_define

begin_define
define|#
directive|define
name|SI86_MEM
value|65
end_define

begin_decl_stmt
specifier|extern
name|int
name|hw_float
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|ibcs2_sysi86
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ibcs2_sysi86_args
modifier|*
name|args
parameter_list|)
block|{
switch|switch
condition|(
name|SCARG
argument_list|(
name|args
argument_list|,
name|cmd
argument_list|)
condition|)
block|{
case|case
name|SI86_FPHW
case|:
block|{
comment|/* Floating Point information */
name|int
name|val
decl_stmt|,
name|error
decl_stmt|;
if|if
condition|(
name|hw_float
condition|)
name|val
operator|=
name|IBCS2_FP_387
expr_stmt|;
comment|/* FPU hardware */
else|else
name|val
operator|=
name|IBCS2_FP_SW
expr_stmt|;
comment|/* FPU emulator */
if|if
condition|(
operator|(
name|error
operator|=
name|copyout
argument_list|(
operator|&
name|val
argument_list|,
name|SCARG
argument_list|(
name|args
argument_list|,
name|arg
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|val
argument_list|)
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
name|error
return|;
return|return
literal|0
return|;
block|}
case|case
name|STIME
case|:
comment|/* set the system time given pointer to long */
comment|/* gettimeofday; time.tv_sec = *args->arg; settimeofday */
return|return
name|EINVAL
return|;
case|case
name|SETNAME
case|:
block|{
comment|/* set hostname given string w/ len<= 7 chars */
name|int
name|name
index|[
literal|2
index|]
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
operator|(
name|error
operator|=
name|suser
argument_list|(
name|p
argument_list|)
operator|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|name
index|[
literal|0
index|]
operator|=
name|CTL_KERN
expr_stmt|;
name|name
index|[
literal|1
index|]
operator|=
name|KERN_HOSTNAME
expr_stmt|;
return|return
operator|(
name|userland_sysctl
argument_list|(
name|p
argument_list|,
name|name
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|SCARG
argument_list|(
name|args
argument_list|,
name|arg
argument_list|)
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
case|case
name|SI86_MEM
case|:
comment|/* size of physical memory */
name|p
operator|->
name|p_retval
index|[
literal|0
index|]
operator|=
name|ctob
argument_list|(
name|physmem
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
default|default:
ifdef|#
directive|ifdef
name|DIAGNOSTIC
name|printf
argument_list|(
literal|"IBCS2: 'sysi86' function %d(0x%x) "
literal|"not implemented yet\n"
argument_list|,
name|SCARG
argument_list|(
name|args
argument_list|,
name|cmd
argument_list|)
argument_list|,
name|args
operator|->
name|cmd
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|EINVAL
return|;
block|}
block|}
end_function

end_unit

