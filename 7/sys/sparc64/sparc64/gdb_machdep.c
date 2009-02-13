begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<machine/asm.h>
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
file|<gdb/gdb.h>
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
specifier|static
name|uint64_t
name|synth
decl_stmt|;
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
block|{
comment|/* 0-7: g0-g7 */
comment|/* 8-15: o0-o7 */
case|case
literal|14
case|:
name|synth
operator|=
name|kdb_thrctx
operator|->
name|pcb_sp
operator|-
name|CCFSZ
expr_stmt|;
return|return
operator|(
operator|&
name|synth
operator|)
return|;
comment|/* 16-23: l0-l7 */
comment|/* 24-31: i0-i7 */
case|case
literal|30
case|:
return|return
operator|(
operator|&
name|kdb_thrctx
operator|->
name|pcb_sp
operator|)
return|;
comment|/* 32-63: f0-f31 */
comment|/* 64-79: f32-f62 (16 double FP) */
case|case
literal|80
case|:
return|return
operator|(
operator|&
name|kdb_thrctx
operator|->
name|pcb_pc
operator|)
return|;
block|}
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
block|{ 	}
block|}
end_function

end_unit

