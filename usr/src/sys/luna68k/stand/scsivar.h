begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)scsivar.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|scsi_softc
block|{
name|struct
name|hp_ctlr
modifier|*
name|sc_hc
decl_stmt|;
name|u_char
modifier|*
name|sc_buf
decl_stmt|;
comment|/* Data Buffer Pointor*/
name|u_char
modifier|*
name|sc_cdb
decl_stmt|;
comment|/* CDB Buffer Pointor */
name|int
modifier|*
name|sc_lock
decl_stmt|;
comment|/* Lock Flag addres   */
name|int
name|sc_flags
decl_stmt|;
comment|/* SPC Status Flags   */
name|int
name|sc_phase
decl_stmt|;
comment|/* Current SCSI Phase */
name|int
name|sc_target
decl_stmt|;
comment|/* Current Target ID  */
name|int
name|sc_len
decl_stmt|;
comment|/* Buffer Length      */
name|int
name|sc_cdblen
decl_stmt|;
comment|/* CDB length         */
name|u_char
name|sc_stat
decl_stmt|;
name|u_char
name|sc_msg
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sc_lock  */
end_comment

begin_define
define|#
directive|define
name|SC_IN_PROGRESS
value|0
end_define

begin_define
define|#
directive|define
name|SC_IO_COMPLETE
value|1
end_define

begin_define
define|#
directive|define
name|SC_DISCONNECTED
value|2
end_define

begin_define
define|#
directive|define
name|SC_IO_FAILED
value|-1
end_define

begin_define
define|#
directive|define
name|SC_DEV_NOT_FOUND
value|-2
end_define

begin_comment
comment|/* sc_flags */
end_comment

begin_define
define|#
directive|define
name|SC_SEL_TIMEOUT
value|0x00000001
end_define

end_unit

