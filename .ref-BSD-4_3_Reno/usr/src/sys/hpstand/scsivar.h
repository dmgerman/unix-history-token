begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Van Jacobson of Lawrence Berkeley Laboratory and the Systems  * Programming Group of the University of Utah Computer Science Department.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)scsivar.h	7.1 (Berkeley) 5/8/90  */
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

