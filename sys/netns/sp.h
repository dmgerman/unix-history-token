begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)sp.h	7.4 (Berkeley) 6/28/90  *	$Id$  */
end_comment

begin_comment
comment|/*  * Definitions for Xerox NS style sequenced packet protocol  */
end_comment

begin_struct
struct|struct
name|sphdr
block|{
name|u_char
name|sp_cc
decl_stmt|;
comment|/* connection control */
name|u_char
name|sp_dt
decl_stmt|;
comment|/* datastream type */
define|#
directive|define
name|SP_SP
value|0x80
comment|/* system packet */
define|#
directive|define
name|SP_SA
value|0x40
comment|/* send acknowledgement */
define|#
directive|define
name|SP_OB
value|0x20
comment|/* attention (out of band data) */
define|#
directive|define
name|SP_EM
value|0x10
comment|/* end of message */
name|u_short
name|sp_sid
decl_stmt|;
comment|/* source connection identifier */
name|u_short
name|sp_did
decl_stmt|;
comment|/* destination connection identifier */
name|u_short
name|sp_seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|sp_ack
decl_stmt|;
comment|/* acknowledge number */
name|u_short
name|sp_alo
decl_stmt|;
comment|/* allocation number */
block|}
struct|;
end_struct

end_unit

