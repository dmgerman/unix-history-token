begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)rdvar.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * rdvar.h -- ??? ( This file should be removed )  * by A.Fujita, MAR-14-1992  */
end_comment

begin_struct
struct|struct
name|rd_partition
block|{
name|u_long
name|p_size
decl_stmt|;
name|u_char
modifier|*
name|p_addr
decl_stmt|;
name|int
name|p_fstype
decl_stmt|;
block|}
struct|;
end_struct

end_unit

