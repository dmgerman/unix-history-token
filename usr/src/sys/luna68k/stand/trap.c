begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)trap.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/stand/romvec.h>
end_include

begin_define
define|#
directive|define
name|USER
value|040
end_define

begin_comment
comment|/* user-mode flag added to type */
end_comment

begin_decl_stmt
name|char
modifier|*
name|trap_type
index|[]
init|=
block|{
literal|"Bus error"
block|,
literal|"Address error"
block|,
literal|"Illegal instruction"
block|,
literal|"Zero divide"
block|,
literal|"CHK instruction"
block|,
literal|"TRAPV instruction"
block|,
literal|"Privilege violation"
block|,
literal|"Trace trap"
block|,
literal|"MMU fault"
block|,
literal|"SSIR trap"
block|,
literal|"Format error"
block|,
literal|"68881 exception"
block|,
literal|"Coprocessor violation"
block|,
literal|"Async system trap"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TRAP_TYPES
value|(sizeof trap_type / sizeof trap_type[0])
end_define

begin_comment
comment|/*  * Called from the trap handler when a processor trap occurs.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|trap
argument_list|(
argument|type
argument_list|,
argument|code
argument_list|,
argument|v
argument_list|,
argument|frame
argument_list|)
end_macro

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|unsigned
name|v
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|frame
name|frame
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|type
condition|)
block|{
default|default:
name|dopanic
label|:
name|printf
argument_list|(
literal|"trap type %d, code = %x, v = %x\n"
argument_list|,
name|type
argument_list|,
name|code
argument_list|,
name|v
argument_list|)
expr_stmt|;
name|regdump
argument_list|(
name|frame
operator|.
name|f_regs
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|type
operator|&=
operator|~
name|USER
expr_stmt|;
if|if
condition|(
operator|(
name|unsigned
operator|)
name|type
operator|<
name|TRAP_TYPES
condition|)
name|panic
argument_list|(
name|trap_type
index|[
name|type
index|]
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"trap"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

