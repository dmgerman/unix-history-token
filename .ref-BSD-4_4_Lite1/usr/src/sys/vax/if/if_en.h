begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_en.h	7.3 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Structure of a Ethernet header.  */
end_comment

begin_struct
struct|struct
name|en_header
block|{
name|u_char
name|en_shost
decl_stmt|;
name|u_char
name|en_dhost
decl_stmt|;
name|u_short
name|en_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ENTYPE_PUP
value|0x0200
end_define

begin_comment
comment|/* PUP protocol */
end_comment

begin_define
define|#
directive|define
name|ENTYPE_IP
value|0x0201
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_comment
comment|/*  * The ENTYPE_NTRAILER packet types starting at  * ENTYPE_TRAIL have (type-ENTYPE_TRAIL)*512 bytes  * of data followed by an Ethernet type (as given above)  * and then the (variable-length) header.  */
end_comment

begin_define
define|#
directive|define
name|ENTYPE_TRAIL
value|0x1000
end_define

begin_comment
comment|/* Trailer type */
end_comment

begin_define
define|#
directive|define
name|ENTYPE_NTRAILER
value|16
end_define

begin_define
define|#
directive|define
name|EN_BROADCAST
value|0
end_define

begin_comment
comment|/* Hardware broadcast address */
end_comment

end_unit

