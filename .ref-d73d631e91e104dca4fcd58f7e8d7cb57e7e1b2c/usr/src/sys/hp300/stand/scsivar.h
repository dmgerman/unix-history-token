begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Van Jacobson of Lawrence Berkeley Laboratory and the Systems  * Programming Group of the University of Utah Computer Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)scsivar.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|scsi_softc
block|{
name|int
name|sc_ba
decl_stmt|;
name|char
modifier|*
name|sc_addr
decl_stmt|;
name|char
name|sc_alive
decl_stmt|;
name|char
name|sc_scsi_addr
decl_stmt|;
name|char
name|sc_stat
decl_stmt|;
name|char
name|sc_msg
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|scsi_softc
name|scsi_softc
index|[]
decl_stmt|;
end_decl_stmt

end_unit

