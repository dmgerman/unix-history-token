begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Steven McCanne of Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)remote-sl.h	7.3 (Berkeley) %G%  *  * $Header: remote-sl.h,v 1.3 91/03/22 15:34:27 mccanne Exp $ (LBL)  */
end_comment

begin_define
define|#
directive|define
name|FRAME_END
value|0xc0
end_define

begin_comment
comment|/* Frame End */
end_comment

begin_define
define|#
directive|define
name|FRAME_ESCAPE
value|0xdb
end_define

begin_comment
comment|/* Frame Esc */
end_comment

begin_define
define|#
directive|define
name|TRANS_FRAME_END
value|0xdc
end_define

begin_comment
comment|/* transposed frame end */
end_comment

begin_define
define|#
directive|define
name|TRANS_FRAME_ESCAPE
value|0xdd
end_define

begin_comment
comment|/* transposed frame esc */
end_comment

begin_comment
comment|/*  * Error codes.  */
end_comment

begin_define
define|#
directive|define
name|EKGDB_CSUM
value|1
end_define

begin_define
define|#
directive|define
name|EKGDB_2BIG
value|2
end_define

begin_define
define|#
directive|define
name|EKGDB_RUNT
value|3
end_define

begin_comment
comment|/*  * Message limits.  SL_MAXMSG is the longest message that can be passed  * down to the serial link.  The actual MTU is two times the max message  * (since each byte might be escaped), plus the two framing bytes.  We add   * two to the message length to account for the type byte and check sum.  * SL_BUFSIZE is one character larger than SL_MAXMSG so we can stuff  * a checksum into the input buffer without special casing.  */
end_comment

begin_define
define|#
directive|define
name|SL_MAXMSG
value|64
end_define

begin_define
define|#
directive|define
name|SL_BUFSIZE
value|(SL_MAXMSG + 1)
end_define

begin_define
define|#
directive|define
name|SL_MTU
value|((2 * (SL_MAXMSG + 2) + 2))
end_define

end_unit

