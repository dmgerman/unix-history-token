begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1988 Stephen Deering.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)igmp.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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
comment|/* Minimum length of any IGMP protocol message. */
end_comment

begin_define
define|#
directive|define
name|IGMP_MINLEN
value|8
end_define

begin_comment
comment|/*  * IGMPv1/v2 query and host report format.  */
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

begin_comment
comment|/*  * IGMP v3 query format.  */
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

begin_define
define|#
directive|define
name|IGMP_V3_QUERY_MINLEN
value|12
end_define

begin_define
define|#
directive|define
name|IGMP_EXP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x07)
end_define

begin_define
define|#
directive|define
name|IGMP_MANT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0f)
end_define

begin_define
define|#
directive|define
name|IGMP_QRESV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x0f)
end_define

begin_define
define|#
directive|define
name|IGMP_SFLAG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x01)
end_define

begin_define
define|#
directive|define
name|IGMP_QRV
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x07)
end_define

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

begin_define
define|#
directive|define
name|IGMP_GRPREC_HDRLEN
value|8
end_define

begin_comment
comment|/*  * IGMPv3 host membership report header.  */
end_comment

begin_struct
struct|struct
name|igmp_report
block|{
name|u_char
name|ir_type
decl_stmt|;
comment|/* IGMP_v3_HOST_MEMBERSHIP_REPORT */
name|u_char
name|ir_rsv1
decl_stmt|;
comment|/* must be zero */
name|u_short
name|ir_cksum
decl_stmt|;
comment|/* checksum */
name|u_short
name|ir_rsv2
decl_stmt|;
comment|/* must be zero */
name|u_short
name|ir_numgrps
decl_stmt|;
comment|/* number of group records */
comment|/*struct	igmp_grouprec ir_groups[1];*/
comment|/* group records */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IGMP_V3_REPORT_MINLEN
value|8
end_define

begin_define
define|#
directive|define
name|IGMP_V3_REPORT_MAXRECS
value|65535
end_define

begin_comment
comment|/*  * Message types, including version number.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_HOST_MEMBERSHIP_QUERY
value|0x11
end_define

begin_comment
comment|/* membership query         */
end_comment

begin_define
define|#
directive|define
name|IGMP_v1_HOST_MEMBERSHIP_REPORT
value|0x12
end_define

begin_comment
comment|/* Ver. 1 membership report */
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
comment|/* PIMv1 message (historic) */
end_comment

begin_define
define|#
directive|define
name|IGMP_v2_HOST_MEMBERSHIP_REPORT
value|0x16
end_define

begin_comment
comment|/* Ver. 2 membership report */
end_comment

begin_define
define|#
directive|define
name|IGMP_HOST_LEAVE_MESSAGE
value|0x17
end_define

begin_comment
comment|/* Leave-group message     */
end_comment

begin_define
define|#
directive|define
name|IGMP_MTRACE_REPLY
value|0x1e
end_define

begin_comment
comment|/* mtrace(8) reply */
end_comment

begin_define
define|#
directive|define
name|IGMP_MTRACE_QUERY
value|0x1f
end_define

begin_comment
comment|/* mtrace(8) probe */
end_comment

begin_define
define|#
directive|define
name|IGMP_v3_HOST_MEMBERSHIP_REPORT
value|0x22
end_define

begin_comment
comment|/* Ver. 3 membership report */
end_comment

begin_comment
comment|/*  * IGMPv3 report modes.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_DO_NOTHING
value|0
end_define

begin_comment
comment|/* don't send a record */
end_comment

begin_define
define|#
directive|define
name|IGMP_MODE_IS_INCLUDE
value|1
end_define

begin_comment
comment|/* MODE_IN */
end_comment

begin_define
define|#
directive|define
name|IGMP_MODE_IS_EXCLUDE
value|2
end_define

begin_comment
comment|/* MODE_EX */
end_comment

begin_define
define|#
directive|define
name|IGMP_CHANGE_TO_INCLUDE_MODE
value|3
end_define

begin_comment
comment|/* TO_IN */
end_comment

begin_define
define|#
directive|define
name|IGMP_CHANGE_TO_EXCLUDE_MODE
value|4
end_define

begin_comment
comment|/* TO_EX */
end_comment

begin_define
define|#
directive|define
name|IGMP_ALLOW_NEW_SOURCES
value|5
end_define

begin_comment
comment|/* ALLOW_NEW */
end_comment

begin_define
define|#
directive|define
name|IGMP_BLOCK_OLD_SOURCES
value|6
end_define

begin_comment
comment|/* BLOCK_OLD */
end_comment

begin_comment
comment|/*  * IGMPv3 query types.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_V3_GENERAL_QUERY
value|1
end_define

begin_define
define|#
directive|define
name|IGMP_V3_GROUP_QUERY
value|2
end_define

begin_define
define|#
directive|define
name|IGMP_V3_GROUP_SOURCE_QUERY
value|3
end_define

begin_comment
comment|/*  * Maximum report interval for IGMP v1/v2 host membership reports [RFC 1112]  */
end_comment

begin_define
define|#
directive|define
name|IGMP_V1V2_MAX_RI
value|10
end_define

begin_define
define|#
directive|define
name|IGMP_MAX_HOST_REPORT_DELAY
value|IGMP_V1V2_MAX_RI
end_define

begin_comment
comment|/*  * IGMP_TIMER_SCALE denotes that the igmp code field specifies  * time in tenths of a second.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_TIMER_SCALE
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IGMP_H_ */
end_comment

end_unit

