begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)memory.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * memory.h -- ??? ( This file should be removed )  * by A.Fujita, MAR-14-1992  */
end_comment

begin_struct
struct|struct
name|prgmem
block|{
name|u_long
name|pg_start
decl_stmt|;
name|u_long
name|pg_end
decl_stmt|;
name|u_long
name|pg_stack
decl_stmt|;
block|}
struct|;
end_struct

end_unit

