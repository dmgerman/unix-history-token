begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Stephen Deering.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)igmp.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/* Internet Group Management Protocol (IGMP) definitions. */
end_comment

begin_comment
comment|/*  * IGMP packet format.  */
end_comment

begin_struct
struct|struct
name|igmp
block|{
name|u_char
name|igmp_type
decl_stmt|;
comment|/* version& type of IGMP message  */
name|u_char
name|igmp_code
decl_stmt|;
comment|/* unused, should be zero          */
name|u_short
name|igmp_cksum
decl_stmt|;
comment|/* IP-style checksum               */
name|struct
name|in_addr
name|igmp_group
decl_stmt|;
comment|/* group address being reported    */
block|}
struct|;
end_struct

begin_comment
comment|/*  (zero for queries)             */
end_comment

begin_define
define|#
directive|define
name|IGMP_MINLEN
value|8
end_define

begin_define
define|#
directive|define
name|IGMP_HOST_MEMBERSHIP_QUERY
value|0x11
end_define

begin_comment
comment|/* message types, incl. version */
end_comment

begin_define
define|#
directive|define
name|IGMP_HOST_MEMBERSHIP_REPORT
value|0x12
end_define

begin_define
define|#
directive|define
name|IGMP_DVMRP
value|0x13
end_define

begin_comment
comment|/* for experimental multicast   */
end_comment

begin_comment
comment|/*  routing protocol            */
end_comment

begin_define
define|#
directive|define
name|IGMP_MAX_HOST_REPORT_DELAY
value|10
end_define

begin_comment
comment|/* max delay for response to    */
end_comment

end_unit

