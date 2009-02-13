begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<machine/gdb_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_include
include|#
directive|include
file|<gdb/gdb.h>
end_include

begin_include
include|#
directive|include
file|<gdb/gdb_int.h>
end_include

begin_function
name|void
modifier|*
name|gdb_cpu_getreg
parameter_list|(
name|int
name|regnum
parameter_list|,
name|size_t
modifier|*
name|regsz
parameter_list|)
block|{
operator|*
name|regsz
operator|=
name|gdb_cpu_regsz
argument_list|(
name|regnum
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|regnum
condition|)
block|{ 	}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
name|void
name|gdb_cpu_setreg
parameter_list|(
name|int
name|regnum
parameter_list|,
name|void
modifier|*
name|val
parameter_list|)
block|{
switch|switch
condition|(
name|regnum
condition|)
block|{
case|case
name|GDB_REG_PC
case|:
break|break;
block|}
block|}
end_function

begin_function
name|int
name|gdb_cpu_signal
parameter_list|(
name|int
name|vector
parameter_list|,
name|int
name|dummy
name|__unused
parameter_list|)
block|{
if|if
condition|(
name|vector
operator|==
name|EXC_TRC
operator|||
name|vector
operator|==
name|EXC_RUNMODETRC
condition|)
return|return
operator|(
name|SIGTRAP
operator|)
return|;
return|return
operator|(
name|vector
operator|)
return|;
block|}
end_function

end_unit

