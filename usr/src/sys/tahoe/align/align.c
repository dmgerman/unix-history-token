begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)align.c	7.1 (Berkeley) 12/6/90  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_comment
comment|/*  * Part of the parameter list is set up by locore.s.  * First 2 dummy variables MUST BE the first local  * variables; leaving place for registers 0 and 1  * which are not preserved by the current C compiler.  * Then, the array of structures and the last_operand  * HAVE to be in the given order, to correspond to the  * description of process_info in 'alignment.h'.   */
end_comment

begin_macro
name|alignment
argument_list|()
end_macro

begin_block
block|{
name|long
name|space_4_Register_1
decl_stmt|;
comment|/* register 1 */
name|long
name|space_4_Register_0
decl_stmt|;
comment|/* register 0 */
name|struct
name|oprnd
name|space_4_decoded
index|[
literal|4
index|]
decl_stmt|;
name|long
name|space_4_opcode
decl_stmt|;
name|long
name|space_4_last_operand
decl_stmt|;
comment|/* Last operand # processed */
name|long
name|space_4_saved_pc
decl_stmt|;
name|long
name|space_4_saved_sp
decl_stmt|;
specifier|register
name|process_info
modifier|*
name|infop
decl_stmt|;
name|infop
operator|=
operator|(
name|process_info
operator|*
operator|)
operator|&
name|space_4_saved_sp
expr_stmt|;
name|saved_pc
operator|=
name|pc
expr_stmt|;
name|saved_sp
operator|=
name|sp
expr_stmt|;
comment|/* For possible exceptions */
name|last_operand
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* To get the operand routine going correctly */
name|opCODE
operator|=
literal|0xff
operator|&
operator|*
operator|(
name|char
operator|*
operator|)
name|pc
expr_stmt|;
name|pc
operator|++
expr_stmt|;
operator|(
operator|*
name|Table
index|[
name|opCODE
index|]
operator|.
name|routine
operator|)
operator|(
name|infop
operator|)
expr_stmt|;
comment|/* Call relevant handler */
comment|/* 	 * NOTE: nothing should follow, except the return. 	 * The register variables cannot be trusted anymore, 	 * if an exception is signalled.  See 'exception.c' 	 * to understand why. 	 */
block|}
end_block

end_unit

