begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/ether.h,v 1.6 2000/10/09 03:24:24 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_ether.h	8.3 (Berkeley) 5/2/95  */
end_comment

begin_define
define|#
directive|define
name|ETHERMTU
value|1500
end_define

begin_comment
comment|/*  * The number of bytes in an ethernet (MAC) address.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_ADDR_LEN
value|6
end_define

begin_comment
comment|/*  * Structure of a DEC/Intel/Xerox or 802.3 Ethernet header.  */
end_comment

begin_struct
struct|struct
name|ether_header
block|{
name|u_int8_t
name|ether_dhost
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|ether_shost
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int16_t
name|ether_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Length of a DEC/Intel/Xerox or 802.3 Ethernet header; note that some  * compilers may pad "struct ether_header" to a multiple of 4 bytes,  * for example, so "sizeof (struct ether_header)" may not give the right  * answer.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_HDRLEN
value|14
end_define

end_unit

