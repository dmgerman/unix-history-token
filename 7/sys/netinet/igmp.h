begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 Stephen Deering.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)igmp.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IGMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IGMP_H_
end_define

begin_comment
comment|/*  * Internet Group Management Protocol (IGMP) definitions.  *  * Written by Steve Deering, Stanford, May 1988.  *  * MULTICAST Revision: 3.5.1.2  */
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
comment|/* subtype for routing msgs        */
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

begin_struct
struct|struct
name|igmpv3
block|{
name|u_char
name|igmp_type
decl_stmt|;
comment|/* version& type of IGMP message  */
name|u_char
name|igmp_code
decl_stmt|;
comment|/* subtype for routing msgs        */
name|u_short
name|igmp_cksum
decl_stmt|;
comment|/* IP-style checksum               */
name|struct
name|in_addr
name|igmp_group
decl_stmt|;
comment|/* group address being reported    */
comment|/*  (zero for queries)             */
name|u_char
name|igmp_misc
decl_stmt|;
comment|/* reserved/suppress/robustness    */
name|u_char
name|igmp_qqi
decl_stmt|;
comment|/* querier's query interval        */
name|u_short
name|igmp_numsrc
decl_stmt|;
comment|/* number of sources               */
comment|/*struct in_addr	igmp_sources[1];*/
comment|/* source addresses */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|igmp_grouprec
block|{
name|u_char
name|ig_type
decl_stmt|;
comment|/* record type */
name|u_char
name|ig_datalen
decl_stmt|;
comment|/* length of auxiliary data */
name|u_short
name|ig_numsrc
decl_stmt|;
comment|/* number of sources */
name|struct
name|in_addr
name|ig_group
decl_stmt|;
comment|/* group address being reported */
comment|/*struct in_addr	ig_sources[1];*/
comment|/* source addresses */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|igmp_report
block|{
name|u_char
name|ir_type
decl_stmt|;
comment|/* record type */
name|u_char
name|ir_rsv1
decl_stmt|;
comment|/* reserved */
name|u_short
name|ir_cksum
decl_stmt|;
comment|/* checksum */
name|u_short
name|ir_rsv2
decl_stmt|;
comment|/* reserved */
name|u_short
name|ir_numgrps
decl_stmt|;
comment|/* number of group records */
name|struct
name|igmp_grouprec
name|ir_groups
index|[
literal|1
index|]
decl_stmt|;
comment|/* group records */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IGMP_MINLEN
value|8
end_define

begin_define
define|#
directive|define
name|IGMP_HDRLEN
value|8
end_define

begin_define
define|#
directive|define
name|IGMP_GRPREC_HDRLEN
value|8
end_define

begin_define
define|#
directive|define
name|IGMP_PREPEND
value|0
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|IGMP_QRV
parameter_list|(
name|pigmp
parameter_list|)
value|((pigmp)->igmp_misc& (0x07))
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|IGMP_MAXSOURCES
parameter_list|(
name|len
parameter_list|)
value|(((len) - 12)>> 2)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Message types, including version number.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_MEMBERSHIP_QUERY
value|0x11
end_define

begin_comment
comment|/* membership query         */
end_comment

begin_define
define|#
directive|define
name|IGMP_V1_MEMBERSHIP_REPORT
value|0x12
end_define

begin_comment
comment|/* Ver. 1 membership report */
end_comment

begin_define
define|#
directive|define
name|IGMP_V2_MEMBERSHIP_REPORT
value|0x16
end_define

begin_comment
comment|/* Ver. 2 membership report */
end_comment

begin_define
define|#
directive|define
name|IGMP_V2_LEAVE_GROUP
value|0x17
end_define

begin_comment
comment|/* Leave-group message	    */
end_comment

begin_define
define|#
directive|define
name|IGMP_DVMRP
value|0x13
end_define

begin_comment
comment|/* DVMRP routing message    */
end_comment

begin_define
define|#
directive|define
name|IGMP_PIM
value|0x14
end_define

begin_comment
comment|/* PIM routing message	    */
end_comment

begin_define
define|#
directive|define
name|IGMP_MTRACE_RESP
value|0x1e
end_define

begin_comment
comment|/* traceroute resp.(to sender)*/
end_comment

begin_define
define|#
directive|define
name|IGMP_MTRACE
value|0x1f
end_define

begin_comment
comment|/* mcast traceroute messages  */
end_comment

begin_define
define|#
directive|define
name|IGMP_V3_MEMBERSHIP_REPORT
value|0x22
end_define

begin_comment
comment|/* Ver. 3 membership report */
end_comment

begin_define
define|#
directive|define
name|IGMP_MAX_HOST_REPORT_DELAY
value|10
end_define

begin_comment
comment|/* max delay for response to     */
end_comment

begin_comment
comment|/*  query (in seconds) according */
end_comment

begin_comment
comment|/*  to RFC1112                   */
end_comment

begin_define
define|#
directive|define
name|IGMP_TIMER_SCALE
value|10
end_define

begin_comment
comment|/* denotes that the igmp code field */
end_comment

begin_comment
comment|/* specifies time in 10th of seconds*/
end_comment

begin_comment
comment|/*  * The following four defininitions are for backwards compatibility.  * They should be removed as soon as all applications are updated to  * use the new constant names.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_HOST_MEMBERSHIP_QUERY
value|IGMP_MEMBERSHIP_QUERY
end_define

begin_define
define|#
directive|define
name|IGMP_HOST_MEMBERSHIP_REPORT
value|IGMP_V1_MEMBERSHIP_REPORT
end_define

begin_define
define|#
directive|define
name|IGMP_HOST_NEW_MEMBERSHIP_REPORT
value|IGMP_V2_MEMBERSHIP_REPORT
end_define

begin_define
define|#
directive|define
name|IGMP_HOST_LEAVE_MESSAGE
value|IGMP_V2_LEAVE_GROUP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IGMP_H_ */
end_comment

end_unit

