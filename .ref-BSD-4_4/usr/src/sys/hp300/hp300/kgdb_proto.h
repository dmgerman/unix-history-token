begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kgdb_proto.h	8.1 (Berkeley) 6/10/93  *  * $Header: kgdb_proto.h,v 1.3 91/03/12 22:06:43 mccanne Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Message types.  */
end_comment

begin_define
define|#
directive|define
name|KGDB_MEM_R
value|0x01
end_define

begin_define
define|#
directive|define
name|KGDB_MEM_W
value|0x02
end_define

begin_define
define|#
directive|define
name|KGDB_REG_R
value|0x03
end_define

begin_define
define|#
directive|define
name|KGDB_REG_W
value|0x04
end_define

begin_define
define|#
directive|define
name|KGDB_CONT
value|0x05
end_define

begin_define
define|#
directive|define
name|KGDB_STEP
value|0x06
end_define

begin_define
define|#
directive|define
name|KGDB_KILL
value|0x07
end_define

begin_define
define|#
directive|define
name|KGDB_SIGNAL
value|0x08
end_define

begin_define
define|#
directive|define
name|KGDB_EXEC
value|0x09
end_define

begin_define
define|#
directive|define
name|KGDB_CMD
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0f)
end_define

begin_comment
comment|/*  * Message flags.  */
end_comment

begin_define
define|#
directive|define
name|KGDB_ACK
value|0x80
end_define

begin_define
define|#
directive|define
name|KGDB_DELTA
value|0x40
end_define

begin_define
define|#
directive|define
name|KGDB_MORE
value|0x20
end_define

begin_define
define|#
directive|define
name|KGDB_SEQ
value|0x10
end_define

end_unit

