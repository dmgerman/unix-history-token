begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Van Jacobson of Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)scsivar.h	7.1 (Berkeley) %G%  */
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
name|struct
name|devqueue
name|sc_dq
decl_stmt|;
name|struct
name|devqueue
name|sc_sq
decl_stmt|;
name|u_char
name|sc_flags
decl_stmt|;
name|u_char
name|sc_sync
decl_stmt|;
name|u_char
name|sc_scsi_addr
decl_stmt|;
name|u_char
name|sc_stat
index|[
literal|2
index|]
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
comment|/* sc_flags */
end_comment

begin_define
define|#
directive|define
name|SCSI_IO
value|0x80
end_define

begin_comment
comment|/* DMA I/O in progress */
end_comment

begin_define
define|#
directive|define
name|SCSI_DMA32
value|0x40
end_define

begin_comment
comment|/* 32-bit DMA should be used */
end_comment

begin_define
define|#
directive|define
name|SCSI_ALIVE
value|0x01
end_define

begin_comment
comment|/* controller initialized */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SCSI_PAD
value|0x02
end_define

begin_comment
comment|/* 'padded' transfer in progress */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

