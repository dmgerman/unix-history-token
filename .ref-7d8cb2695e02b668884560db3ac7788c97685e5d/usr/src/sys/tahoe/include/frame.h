begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)frame.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definition of the tahoe call frame.  */
end_comment

begin_struct
struct|struct
name|frame
block|{
name|int
name|fr_savpc
decl_stmt|;
comment|/* saved program counter */
name|u_int
name|fr_mask
range|:
literal|16
decl_stmt|,
comment|/* register save mask */
name|fr_removed
range|:
literal|16
decl_stmt|;
comment|/* 4*number of arguments + 4 */
name|int
name|fr_savfp
decl_stmt|;
comment|/* saved frame pointer */
block|}
struct|;
end_struct

end_unit

