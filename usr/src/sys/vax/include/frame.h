begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  *  *	@(#)frame.h	7.2 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/*  * Definition of the vax calls/callg frame.  */
end_comment

begin_struct
struct|struct
name|frame
block|{
name|int
name|fr_handler
decl_stmt|;
name|u_int
name|fr_psw
range|:
literal|16
decl_stmt|,
comment|/* saved psw */
name|fr_mask
range|:
literal|12
decl_stmt|,
comment|/* register save mask */
range|:
literal|1
decl_stmt|,
name|fr_s
range|:
literal|1
decl_stmt|,
comment|/* call was a calls, not callg */
name|fr_spa
range|:
literal|2
decl_stmt|;
comment|/* stack pointer alignment */
name|int
name|fr_savap
decl_stmt|;
comment|/* saved arg pointer */
name|int
name|fr_savfp
decl_stmt|;
comment|/* saved frame pointer */
name|int
name|fr_savpc
decl_stmt|;
comment|/* saved program counter */
block|}
struct|;
end_struct

end_unit

