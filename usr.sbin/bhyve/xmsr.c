begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<machine/vmm.h>
end_include

begin_include
include|#
directive|include
file|<vmmapi.h>
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
file|"xmsr.h"
end_include

begin_function
name|int
name|emulate_wrmsr
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|uint32_t
name|code
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
switch|switch
condition|(
name|code
condition|)
block|{
case|case
literal|0xd04
case|:
comment|/* Sandy Bridge uncore PMC MSRs */
case|case
literal|0xc24
case|:
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|0x79
case|:
return|return
operator|(
literal|0
operator|)
return|;
comment|/* IA32_BIOS_UPDT_TRIG MSR */
default|default:
break|break;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|int
name|emulate_rdmsr
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|uint32_t
name|code
parameter_list|,
name|uint64_t
modifier|*
name|val
parameter_list|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

