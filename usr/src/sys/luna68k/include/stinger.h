begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)stinger.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * stinger.h -- Stinger Kernel Interface Definitions  * by A.Fujita, MAR-14-1992  *  * This file should be remade.  */
end_comment

begin_include
include|#
directive|include
file|<machine/rdvar.h>
end_include

begin_include
include|#
directive|include
file|<machine/memory.h>
end_include

begin_struct
struct|struct
name|KernInter
block|{
name|caddr_t
name|maxaddr
decl_stmt|;
name|struct
name|prgmem
name|prg
decl_stmt|;
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|struct
name|rd_partition
modifier|*
name|rd
decl_stmt|;
block|}
struct|;
end_struct

end_unit

