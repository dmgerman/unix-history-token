begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)Ashlq.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_macro
name|shlq
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
comment|/* /*	Shift left quadword. /* /********************************/
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
name|long
name|Register_10
decl_stmt|;
specifier|register
name|long
modifier|*
name|Register_9
decl_stmt|;
name|quadword
name|result
decl_stmt|;
name|Register_12
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
comment|/* Counter */
name|Register_9
operator|=
operator|&
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
operator|->
name|data
expr_stmt|;
comment|/* Source */
name|Register_10
operator|=
name|psl
expr_stmt|;
name|Set_psl
argument_list|(
name|r10
argument_list|)
expr_stmt|;
comment|/* restore the user psl */
asm|asm ("	shlq	r12,(r9),r10");
asm|asm ("	movpsl	r12");
name|New_cc
argument_list|(
name|Register_12
argument_list|)
expr_stmt|;
name|result
operator|.
name|high
operator|=
name|Register_10
expr_stmt|;
name|result
operator|.
name|low
operator|=
name|Register_11
expr_stmt|;
name|write_quadword
argument_list|(
name|infop
argument_list|,
name|result
argument_list|,
name|operand
argument_list|(
name|infop
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

