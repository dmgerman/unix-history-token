begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)stinger.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * stinger.h -- Stinger Kernel Interface Definitions  *   remade by A.Fujita, JAN-12-1993  */
end_comment

begin_struct
struct|struct
name|KernInter
block|{
name|caddr_t
name|maxaddr
decl_stmt|;
name|u_int
name|dipsw
decl_stmt|;
name|int
name|plane
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|KernInter
name|KernInter
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KIFF_DIPSW_NOBM
value|0x0002
end_define

begin_comment
comment|/* not use bitmap display as console */
end_comment

end_unit

