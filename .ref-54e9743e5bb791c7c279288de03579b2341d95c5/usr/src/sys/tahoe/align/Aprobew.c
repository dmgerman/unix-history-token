begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)Aprobew.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_define
define|#
directive|define
name|PSL_USER
value|PSL_CURMOD
end_define

begin_macro
name|probew
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
comment|/* /*	Probe write accessability. /* /*************************************/
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
name|Register_9
decl_stmt|;
name|Register_9
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|0
argument_list|)
operator|->
name|data
operator|&
literal|1
expr_stmt|;
comment|/* Required mode */
if|if
condition|(
name|psl
operator|&
name|PSL_USER
condition|)
name|Register_9
operator|=
literal|1
expr_stmt|;
comment|/* user can't probe as 							 *  kernel ! */
name|Register_10
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
operator|->
name|address
expr_stmt|;
comment|/* Base address */
name|Register_11
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|2
argument_list|)
operator|->
name|data
expr_stmt|;
comment|/* Length */
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
asm|asm ("	probew	r9,(r10),r11");
asm|asm ("	movpsl	r12");
name|New_cc
argument_list|(
name|Register_12
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

