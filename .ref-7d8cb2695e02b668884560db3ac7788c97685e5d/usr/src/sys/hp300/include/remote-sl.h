begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Steven McCanne of Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)remote-sl.h	7.4 (Berkeley) %G%  *  * $Header: remote-sl.h,v 1.2 92/07/23 19:38:20 mccanne Exp $ (LBL)  */
end_comment

begin_define
define|#
directive|define
name|FRAME_START
value|0xc1
end_define

begin_comment
comment|/* Frame End */
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
name|TRANS_FRAME_START
value|0xde
end_define

begin_comment
comment|/* transposed frame start */
end_comment

begin_define
define|#
directive|define
name|TRANS_FRAME_END
value|0xdc
end_define

begin_comment
comment|/* transposed frame esc */
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
comment|/*  * Message limits.  SL_MAXDATA is the maximum number of bytes that can  * be read or written.  SL_RPCSIZE is the maximum message size for  * the serial link.  The actual MTU is two times the max message (since  * each byte might be escaped), plus the two framing bytes.  We add two   * to the message length to account for the type byte and checksum.  */
end_comment

begin_define
define|#
directive|define
name|SL_MAXDATA
value|62
end_define

begin_comment
comment|/* max data that can be read */
end_comment

begin_define
define|#
directive|define
name|SL_RPCSIZE
value|(1 + SL_MAXDATA)
end_define

begin_comment
comment|/* errno byte + data */
end_comment

begin_define
define|#
directive|define
name|SL_MTU
value|((2 * (SL_RPCSIZE + 2) + 2))
end_define

end_unit

