begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1992 The University of Utah and the Center  *	for Software Science (CSS).  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Center for Software Science of the University of Utah Computer  * Science Department.  CSS requests users of this software to return  * to css-dist@cs.utah.edu any improvements that they make and grant  * CSS redistribution rights.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)rmp.h	8.1 (Berkeley) 6/4/93  *  * From: Utah Hdr: rmp.h 3.1 92/07/06  * Author: Jeff Forys, University of Utah CSS  */
end_comment

begin_comment
comment|/*  *  Define MIN/MAX sizes of RMP (ethernet) packet.  *  For ease of computation, the 4 octet CRC field is not included.  *  *  MCLBYTES is for bpfwrite(); it is adamant about using a cluster.  */
end_comment

begin_define
define|#
directive|define
name|RMP_MAX_PACKET
value|MIN(1514,MCLBYTES)
end_define

begin_define
define|#
directive|define
name|RMP_MIN_PACKET
value|60
end_define

begin_comment
comment|/*  *  Define RMP/Ethernet Multicast address (9:0:9:0:0:4) and its length.  */
end_comment

begin_define
define|#
directive|define
name|RMP_ADDR
value|{ 0x9, 0x0, 0x9, 0x0, 0x0, 0x4 }
end_define

begin_define
define|#
directive|define
name|RMP_ADDRLEN
value|6
end_define

begin_comment
comment|/*  *  Define IEEE802.2 (Logical Link Control) information.  */
end_comment

begin_define
define|#
directive|define
name|IEEE_DSAP_HP
value|0xF8
end_define

begin_comment
comment|/* Destination Service Access Point */
end_comment

begin_define
define|#
directive|define
name|IEEE_SSAP_HP
value|0xF8
end_define

begin_comment
comment|/* Source Service Access Point */
end_comment

begin_define
define|#
directive|define
name|IEEE_CNTL_HP
value|0x0300
end_define

begin_comment
comment|/* Type 1 / I format control information */
end_comment

begin_define
define|#
directive|define
name|HPEXT_DXSAP
value|0x608
end_define

begin_comment
comment|/* HP Destination Service Access Point */
end_comment

begin_define
define|#
directive|define
name|HPEXT_SXSAP
value|0x609
end_define

begin_comment
comment|/* HP Source Service Access Point */
end_comment

begin_comment
comment|/*  *  802.3-style "Ethernet" header.  */
end_comment

begin_struct
struct|struct
name|hp_hdr
block|{
name|u_int8_t
name|daddr
index|[
name|RMP_ADDRLEN
index|]
decl_stmt|;
name|u_int8_t
name|saddr
index|[
name|RMP_ADDRLEN
index|]
decl_stmt|;
name|u_int16_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * HP uses 802.2 LLC with their own local extensions.  This struct makes  * sense out of this data (encapsulated in the above 802.3 packet).  */
end_comment

begin_struct
struct|struct
name|hp_llc
block|{
name|u_int8_t
name|dsap
decl_stmt|;
comment|/* 802.2 DSAP */
name|u_int8_t
name|ssap
decl_stmt|;
comment|/* 802.2 SSAP */
name|u_int16_t
name|cntrl
decl_stmt|;
comment|/* 802.2 control field */
name|u_int16_t
name|filler
decl_stmt|;
comment|/* HP filler (must be zero) */
name|u_int16_t
name|dxsap
decl_stmt|;
comment|/* HP extended DSAP */
name|u_int16_t
name|sxsap
decl_stmt|;
comment|/* HP extended SSAP */
block|}
struct|;
end_struct

end_unit

