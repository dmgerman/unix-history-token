begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Van Jacobson of Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)scsivar.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|scsi_queue
block|{
name|struct
name|scsi_queue
modifier|*
name|dq_forw
decl_stmt|;
name|struct
name|scsi_queue
modifier|*
name|dq_back
decl_stmt|;
name|int
name|dq_ctlr
decl_stmt|;
name|int
name|dq_unit
decl_stmt|;
name|int
name|dq_slave
decl_stmt|;
name|struct
name|driver
modifier|*
name|dq_driver
decl_stmt|;
name|int
name|dq_flags
decl_stmt|;
name|int
name|dq_imax
decl_stmt|;
name|int
name|dq_imin
decl_stmt|;
name|int
name|dq_omax
decl_stmt|;
name|int
name|dq_omin
decl_stmt|;
name|struct
name|scsi_fmt_cdb
modifier|*
name|dq_cdb
decl_stmt|;
name|struct
name|buf
modifier|*
name|dq_bp
decl_stmt|;
name|u_char
modifier|*
name|dq_xferp
decl_stmt|;
comment|/* Current Pointor */
name|int
name|dq_xfercnt
decl_stmt|;
comment|/* Data Counter    */
block|}
struct|;
end_struct

begin_comment
comment|/* dq_flags */
end_comment

begin_define
define|#
directive|define
name|DQ_DISCONNECT
value|0x00000001
end_define

begin_struct
struct|struct
name|scsi_softc
block|{
name|struct
name|hp_ctlr
modifier|*
name|sc_hc
decl_stmt|;
name|struct
name|scsi_queue
name|sc_sq
decl_stmt|;
name|struct
name|scsi_queue
name|sc_wq
decl_stmt|;
name|u_char
modifier|*
name|sc_cdb
decl_stmt|;
comment|/* CDB Buffer Pointor */
name|u_char
modifier|*
name|sc_buf
decl_stmt|;
comment|/* Data Buffer Pointor*/
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
name|sc_cdblen
decl_stmt|;
comment|/* CDB length         */
name|int
name|sc_len
decl_stmt|;
comment|/* Buffer Length      */
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
name|SC_BUSY
value|-1
end_define

begin_define
define|#
directive|define
name|SC_IO_FAILED
value|-2
end_define

begin_define
define|#
directive|define
name|SC_DEV_NOT_FOUND
value|-3
end_define

begin_define
define|#
directive|define
name|SC_IO_TIMEOUT
value|-4
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

