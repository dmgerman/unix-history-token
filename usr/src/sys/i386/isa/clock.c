begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.386.c%  *  *	@(#)clock.c	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Primitive clock interrupt routines.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"icu.h"
end_include

begin_macro
name|startrtclock
argument_list|()
end_macro

begin_block
block|{
comment|/* initialize 8253 clock */
name|outb
argument_list|(
literal|0x43
argument_list|,
literal|0x36
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0x40
argument_list|,
literal|1193182
operator|/
literal|60
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0x40
argument_list|,
operator|(
literal|1193182
operator|/
literal|60
operator|)
operator|/
literal|256
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|clkreld
argument_list|()
end_macro

begin_block
block|{
name|pg
argument_list|(
literal|"clkreld"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Initialze the time of day register, based on the time base which is, e.g.  * from a filesystem.  */
end_comment

begin_macro
name|inittodr
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|time_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|time
operator|.
name|tv_sec
operator|=
name|base
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Restart the clock.  */
end_comment

begin_macro
name|resettodr
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|enablertclock
argument_list|()
end_macro

begin_block
block|{
name|INTREN
argument_list|(
name|IRQ0
argument_list|)
expr_stmt|;
name|splnone
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

