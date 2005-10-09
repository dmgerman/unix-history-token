begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * @(#) $Id: arcnet.h,v 1.3 2003/01/23 09:05:37 guy Exp $ (LBL)  *  * from: NetBSD: if_arc.h,v 1.13 1999/11/19 20:41:19 thorpej Exp  */
end_comment

begin_comment
comment|/*  * Structure of a 2.5MB/s Arcnet header on the BSDs,  * as given to interface code.  */
end_comment

begin_struct
struct|struct
name|arc_header
block|{
name|u_int8_t
name|arc_shost
decl_stmt|;
name|u_int8_t
name|arc_dhost
decl_stmt|;
name|u_int8_t
name|arc_type
decl_stmt|;
comment|/* 	 * only present for newstyle encoding with LL fragmentation. 	 * Don't use sizeof(anything), use ARC_HDR{,NEW}LEN instead. 	 */
name|u_int8_t
name|arc_flag
decl_stmt|;
name|u_int16_t
name|arc_seqid
decl_stmt|;
comment|/* 	 * only present in exception packets (arc_flag == 0xff) 	 */
name|u_int8_t
name|arc_type2
decl_stmt|;
comment|/* same as arc_type */
name|u_int8_t
name|arc_flag2
decl_stmt|;
comment|/* real flag value */
name|u_int16_t
name|arc_seqid2
decl_stmt|;
comment|/* real seqid value */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ARC_HDRLEN
value|3
end_define

begin_define
define|#
directive|define
name|ARC_HDRNEWLEN
value|6
end_define

begin_define
define|#
directive|define
name|ARC_HDRNEWLEN_EXC
value|10
end_define

begin_comment
comment|/* RFC 1051 */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_IP_OLD
value|240
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_ARP_OLD
value|241
end_define

begin_comment
comment|/* address resolution protocol */
end_comment

begin_comment
comment|/* RFC 1201 */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_IP
value|212
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_ARP
value|213
end_define

begin_comment
comment|/* address resolution protocol */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_REVARP
value|214
end_define

begin_comment
comment|/* reverse addr resolution protocol */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_ATALK
value|221
end_define

begin_comment
comment|/* Appletalk */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_BANIAN
value|247
end_define

begin_comment
comment|/* Banyan Vines */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_IPX
value|250
end_define

begin_comment
comment|/* Novell IPX */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_INET6
value|0xc4
end_define

begin_comment
comment|/* IPng */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_DIAGNOSE
value|0x80
end_define

begin_comment
comment|/* as per ANSI/ATA 878.1 */
end_comment

begin_comment
comment|/*  * Structure of a 2.5MB/s Arcnet header on Linux.  Linux has  * an extra "offset" field when given to interface code, and  * never presents packets that look like exception frames.  */
end_comment

begin_struct
struct|struct
name|arc_linux_header
block|{
name|u_int8_t
name|arc_shost
decl_stmt|;
name|u_int8_t
name|arc_dhost
decl_stmt|;
name|u_int16_t
name|arc_offset
decl_stmt|;
name|u_int8_t
name|arc_type
decl_stmt|;
comment|/* 	 * only present for newstyle encoding with LL fragmentation. 	 * Don't use sizeof(anything), use ARC_LINUX_HDR{,NEW}LEN 	 * instead. 	 */
name|u_int8_t
name|arc_flag
decl_stmt|;
name|u_int16_t
name|arc_seqid
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ARC_LINUX_HDRLEN
value|5
end_define

begin_define
define|#
directive|define
name|ARC_LINUX_HDRNEWLEN
value|8
end_define

end_unit

