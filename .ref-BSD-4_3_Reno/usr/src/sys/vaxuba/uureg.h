begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)uureg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * DL11-E/DL11-W UNIBUS (for TU58) controller registers  */
end_comment

begin_struct
struct|struct
name|uudevice
block|{
name|short
name|rcs
decl_stmt|;
comment|/* receiver status register */
name|short
name|rdb
decl_stmt|;
comment|/* receiver data buffer register */
name|short
name|tcs
decl_stmt|;
comment|/* transmitter status register */
name|short
name|tdb
decl_stmt|;
comment|/* transmitter data buffer register */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Receiver/transmitter status register status/command bits  */
end_comment

begin_define
define|#
directive|define
name|UUCS_DONE
value|0x80
end_define

begin_comment
comment|/* done/ready */
end_comment

begin_define
define|#
directive|define
name|UUCS_READY
value|0x80
end_define

begin_define
define|#
directive|define
name|UUCS_INTR
value|0x40
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|UUCS_MAINT
value|0x02
end_define

begin_comment
comment|/* maintenance check (xmitter only) */
end_comment

begin_define
define|#
directive|define
name|UUCS_BREAK
value|0x01
end_define

begin_comment
comment|/* send break (xmitter only) */
end_comment

begin_comment
comment|/*  * Receiver data buffer register status bits  */
end_comment

begin_define
define|#
directive|define
name|UURDB_ERROR
value|0x8000
end_define

begin_comment
comment|/* Error (overrun or break) */
end_comment

begin_define
define|#
directive|define
name|UURDB_ORUN
value|0x4000
end_define

begin_comment
comment|/* Data overrun error */
end_comment

begin_define
define|#
directive|define
name|UURDB_BREAK
value|0x2000
end_define

begin_comment
comment|/* TU58 break */
end_comment

begin_define
define|#
directive|define
name|UUDB_DMASK
value|0x00ff
end_define

begin_comment
comment|/* data mask (send and receive data) */
end_comment

end_unit

