begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)siovar.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * siovar.h --  */
end_comment

begin_struct
struct|struct
name|sio_portc
block|{
name|int
name|pc_major
decl_stmt|;
name|int
name|pc_unit
decl_stmt|;
name|int
name|pc_port
decl_stmt|;
name|struct
name|siodevice
modifier|*
name|pc_addr
decl_stmt|;
name|int
function_decl|(
modifier|*
name|pc_intr
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sio_softc
block|{
name|struct
name|sio_portc
modifier|*
name|sc_pc
decl_stmt|;
block|}
struct|;
end_struct

end_unit

