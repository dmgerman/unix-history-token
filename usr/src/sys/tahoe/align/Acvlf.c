begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)Acvlf.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_macro
name|cvlf
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

begin_comment
comment|/* /*	Convert integer to float (into accumulator). /* /******************************************************/
end_comment

begin_block
block|{
specifier|register
name|long
name|Register_12
decl_stmt|;
comment|/* Has to be first reg ! */
specifier|register
name|long
name|Register_11
decl_stmt|;
specifier|register
name|float
modifier|*
name|Register_10
decl_stmt|;
comment|/* 	register	long	Register_9; 	register	long	Register_8; 	*/
specifier|register
name|struct
name|oprnd
modifier|*
name|oppnt
decl_stmt|;
name|Register_11
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|0
argument_list|)
operator|->
name|data
expr_stmt|;
name|Register_10
operator|=
operator|(
name|float
operator|*
operator|)
operator|&
name|acc_high
expr_stmt|;
name|Register_12
operator|=
name|psl
expr_stmt|;
name|Set_psl
argument_list|(
name|r12
argument_list|)
expr_stmt|;
asm|asm ("	cvlf	r11");
comment|/* Don't change the order !! */
asm|asm ("	movpsl	r12");
asm|asm ("	stf	(r10)");
name|New_cc
argument_list|(
name|Register_12
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

