begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)Aaddd.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_macro
name|addd
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
comment|/* /*	Add operand with accumulator to accumulator (double). /* /*************************************************************/
end_comment

begin_block
block|{
specifier|register
name|double
modifier|*
name|operand_pnt
decl_stmt|;
specifier|register
name|double
modifier|*
name|acc_pnt
decl_stmt|;
name|operand_pnt
operator|=
operator|(
name|double
operator|*
operator|)
operator|&
name|operand
argument_list|(
name|infop
argument_list|,
literal|0
argument_list|)
operator|->
name|data
expr_stmt|;
name|acc_pnt
operator|=
operator|(
name|double
operator|*
operator|)
operator|&
name|acc_high
expr_stmt|;
operator|*
name|acc_pnt
operator|=
operator|*
name|acc_pnt
operator|+
operator|*
name|operand_pnt
expr_stmt|;
block|}
end_block

end_unit

