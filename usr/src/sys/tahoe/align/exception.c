begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)exception.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_comment
comment|/*  * Signal an exception. It will be handled by 'locore.s'. Here, I:  *	1) Put the exception code where it belongs on the stack.  *	2) Restore pc and sp to show that the current opcode  *		'was not executed'.  *	3) Execute one big non-local-goto. In the process we take care  *		to reset the current HW fp such that 'alignment' will  *		indeed return to 'locore.s'.  *		IMPORTANT NOTE : the process I use will NOT restore  *		all registers (like normal returns) so the call to the  *		handling routine HAS TO BE the last thing in 'alignment'.  *		Otherwise, all its own register variables will be a mess !!  *		I also know that 'alignment' itself WILL restore all  *		registers for 'locore.s' since its entry mask is all-1.  */
end_comment

begin_macro
name|exception
argument_list|(
argument|infop
argument_list|,
argument|type
argument_list|,
argument|param1
argument_list|,
argument|param2
argument_list|)
end_macro

begin_decl_stmt
name|process_info
modifier|*
name|infop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|,
name|param1
decl_stmt|,
name|param2
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|long
modifier|*
name|my_fp
decl_stmt|;
specifier|register
name|long
modifier|*
name|current_fp
decl_stmt|,
modifier|*
name|prev_fp
decl_stmt|;
name|my_fp
operator|=
operator|(
name|long
operator|*
operator|)
operator|&
name|infop
operator|-
literal|1
expr_stmt|;
name|infop
operator|->
name|ret_exception
operator|=
name|type
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|ARITHMETIC
case|:
name|infop
operator|->
name|ret_code
operator|=
name|param1
expr_stmt|;
break|break;
case|case
name|ILL_ACCESS
case|:
name|infop
operator|->
name|ret_addr
operator|=
name|param1
expr_stmt|;
name|infop
operator|->
name|ret_code
operator|=
name|param2
expr_stmt|;
break|break;
case|case
name|ALIGNMENT
case|:
case|case
name|ILL_ADDRMOD
case|:
case|case
name|ILL_OPRND
case|:
break|break;
default|default :
name|printf
argument_list|(
literal|"Bad exception type %d (alignment code)\n"
argument_list|,
name|type
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/*  * Now the big trick. Look up the stack until the frame of  * 'alignment' is found. prev_fp will point to it and current_fp  * will then point to the frame of whoever 'alignment' called.  * This should better work ...  */
name|prev_fp
operator|=
name|my_fp
expr_stmt|;
while|while
condition|(
name|prev_fp
operator|!=
operator|&
name|fp
condition|)
block|{
name|current_fp
operator|=
name|prev_fp
expr_stmt|;
name|prev_fp
operator|=
operator|(
name|long
operator|*
operator|)
operator|*
name|prev_fp
expr_stmt|;
block|}
comment|/*  * Found it. Now fool the HW into thinking that 'alignment' called  * us directly here, so this routine's 'return' will go back  * all the way to 'alignment', stopping any further emulation  * for the current offending opcode.  *  "fool the HW..." ha ha, am I realy fooling myself ?  */
operator|*
name|my_fp
operator|=
operator|*
name|current_fp
expr_stmt|;
operator|*
operator|(
name|my_fp
operator|-
literal|2
operator|)
operator|=
operator|*
operator|(
name|current_fp
operator|-
literal|2
operator|)
expr_stmt|;
comment|/* Alter program counter */
comment|/*  * Without further ado, just go back now !!!!  */
block|}
end_block

begin_macro
name|not_needed
argument_list|(
argument|infop
argument_list|)
end_macro

begin_decl_stmt
name|process_info
modifier|*
name|infop
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/*  * Shouldn't ever come to this routine.  */
name|printf
argument_list|(
literal|"Opcode 0x%x should not trap to alignment code."
argument_list|,
name|opCODE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" OS or machine problem!! \n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cannot_do
argument_list|(
argument|infop
argument_list|)
end_macro

begin_decl_stmt
name|process_info
modifier|*
name|infop
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/*  * Some opcode-caused alignments cannot be emulated. See table.c for  * specific reasons. Reflect this back to the process as alignment  * exception.  */
name|exception
argument_list|(
name|infop
argument_list|,
name|ALIGNMENT
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

