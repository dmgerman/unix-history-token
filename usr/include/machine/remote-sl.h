begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Steven McCanne of Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)remote-sl.h	8.1 (Berkeley) 6/10/93  *  * $Header: remote-sl.h,v 1.2 92/07/23 19:38:20 mccanne Exp $ (LBL)  */
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

