begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)Aediv.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_decl_stmt
name|int
name|zzz1
decl_stmt|,
name|zzz2
decl_stmt|,
name|zzz3
decl_stmt|,
name|zzz4
decl_stmt|,
name|zzz5
decl_stmt|;
end_decl_stmt

begin_macro
name|ediv
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
comment|/* /*	Extended precision division. /* /***************************************/
end_comment

begin_block
block|{
specifier|register
name|long
name|Register_12
decl_stmt|;
comment|/* Has to be the first reg !! */
specifier|register
name|long
name|Register_11
decl_stmt|;
comment|/* remainder */
specifier|register
name|long
name|Register_10
decl_stmt|;
comment|/* quotient */
specifier|register
name|long
name|Register_9
decl_stmt|;
comment|/* divident least */
specifier|register
name|long
name|Register_8
decl_stmt|;
comment|/* divident most */
specifier|register
name|long
name|Register_7
decl_stmt|;
comment|/* divisor */
name|Register_7
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
name|Register_8
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
operator|->
name|data
expr_stmt|;
name|Register_9
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
operator|->
name|data2
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
comment|/* restore the user psl */
asm|asm ("	ediv	r7,r8,r10,r11");
asm|asm ("	movpsl	r12");
name|New_cc
argument_list|(
name|Register_12
argument_list|)
expr_stmt|;
name|write_back
argument_list|(
name|infop
argument_list|,
name|Register_10
argument_list|,
name|operand
argument_list|(
name|infop
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|write_back
argument_list|(
name|infop
argument_list|,
name|Register_11
argument_list|,
name|operand
argument_list|(
name|infop
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

