begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)kern_clock.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * The hz hardware interval timer.  * We update the events relating to real time.  * If this timer is also being used to gather statistics,  * we run through the statistics gathering routine as well.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|hardclock
argument_list|(
argument|pc
argument_list|,
argument|ps
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ps
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

end_unit

