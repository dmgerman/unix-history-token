begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)align.c	7.1 (Berkeley) %G%  */
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

