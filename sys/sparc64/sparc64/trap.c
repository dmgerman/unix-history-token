begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/pv.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_include
include|#
directive|include
file|<machine/tte.h>
end_include

begin_include
include|#
directive|include
file|<machine/tlb.h>
end_include

begin_include
include|#
directive|include
file|<machine/tsb.h>
end_include

begin_function_decl
name|void
name|trap
parameter_list|(
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|char
modifier|*
name|trap_msg
index|[]
init|=
block|{
literal|"reserved"
block|,
literal|"power on reset"
block|,
literal|"watchdog reset"
block|,
literal|"externally initiated reset"
block|,
literal|"software initiated reset"
block|,
literal|"red state exception"
block|,
literal|"instruction access exception"
block|,
literal|"instruction access error"
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
literal|"memory address not aligned"
block|,
literal|"lddf memory address not aligned"
block|,
literal|"stdf memory address not aligned"
block|,
literal|"privileged action"
block|,
literal|"interrupt vector"
block|,
literal|"physical address watchpoint"
block|,
literal|"virtual address watchpoint"
block|,
literal|"corrected ecc error"
block|,
literal|"fast instruction access mmu miss"
block|,
literal|"fast data access mmu miss"
block|,
literal|"fast data access protection"
block|,
literal|"bad spill"
block|,
literal|"bad fill"
block|,
literal|"breakpoint"
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|trap
parameter_list|(
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
block|{
switch|switch
condition|(
name|tf
operator|->
name|tf_type
condition|)
block|{
ifdef|#
directive|ifdef
name|DDB
case|case
name|T_BREAKPOINT
operator||
name|T_KERNEL
case|:
if|if
condition|(
name|kdb_trap
argument_list|(
name|tf
argument_list|)
operator|!=
literal|0
condition|)
return|return;
break|break;
endif|#
directive|endif
default|default:
break|break;
block|}
name|panic
argument_list|(
literal|"trap: %s"
argument_list|,
name|trap_msg
index|[
name|tf
operator|->
name|tf_type
operator|&
operator|~
name|T_KERNEL
index|]
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

