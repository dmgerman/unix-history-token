begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)Atst.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_macro
name|tst
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
comment|/* /*	Test operand, set condition codes. /* /************************************************/
end_comment

begin_block
block|{
specifier|register
name|long
name|quantity
decl_stmt|;
name|quantity
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
if|if
condition|(
name|quantity
operator|<
literal|0
condition|)
name|negative_1
expr_stmt|;
else|else
name|negative_0
expr_stmt|;
if|if
condition|(
name|quantity
operator|==
literal|0
condition|)
name|zero_1
expr_stmt|;
else|else
name|zero_0
expr_stmt|;
name|overflow_0
expr_stmt|;
name|carry_1
expr_stmt|;
block|}
end_block

end_unit

