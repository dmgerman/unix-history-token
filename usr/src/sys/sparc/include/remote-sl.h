begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)remote-sl.h	7.3 (Berkeley) %G%  *  * from: $Header: remote-sl.h,v 1.6 92/11/26 02:04:45 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * These definitions are factored out into an include file so  * the kernel stub has access to them.  */
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
comment|/*  * Message limits. SL_MAXDATA is the maximum number of bytes that can  * be read or written. SL_BUFSIZE is the maximum amount of data that  * can be passed across the serial link. The actual MTU is two times  * the max message (since each byte might be escaped), plus the two  * framing bytes. We add two to the message length to account for the  * type byte and checksum.  */
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

