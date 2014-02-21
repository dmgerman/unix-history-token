begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Bruce Simpson.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_MLD6_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_MLD6_H_
end_define

begin_comment
comment|/*  * Multicast Listener Discovery (MLD) definitions.  */
end_comment

begin_comment
comment|/* Minimum length of any MLD protocol message. */
end_comment

begin_define
define|#
directive|define
name|MLD_MINLEN
value|sizeof(struct icmp6_hdr)
end_define

begin_comment
comment|/*  * MLD v2 query format.  * See<netinet/icmp6.h> for struct mld_hdr  * (MLDv1 query and host report format).  */
end_comment

begin_struct
struct|struct
name|mldv2_query
block|{
name|struct
name|icmp6_hdr
name|mld_icmp6_hdr
decl_stmt|;
comment|/* ICMPv6 header */
name|struct
name|in6_addr
name|mld_addr
decl_stmt|;
comment|/* address being queried */
name|uint8_t
name|mld_misc
decl_stmt|;
comment|/* reserved/suppress/robustness   */
name|uint8_t
name|mld_qqi
decl_stmt|;
comment|/* querier's query interval       */
name|uint16_t
name|mld_numsrc
decl_stmt|;
comment|/* number of sources              */
comment|/* followed by 1..numsrc source addresses */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MLD_V2_QUERY_MINLEN
value|sizeof(struct mldv2_query)
end_define

begin_define
define|#
directive|define
name|MLD_MRC_EXP
parameter_list|(
name|x
parameter_list|)
value|((ntohs((x))>> 12)& 0x0007)
end_define

begin_define
define|#
directive|define
name|MLD_MRC_MANT
parameter_list|(
name|x
parameter_list|)
value|(ntohs((x))& 0x0fff)
end_define

begin_define
define|#
directive|define
name|MLD_QQIC_EXP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x07)
end_define

begin_define
define|#
directive|define
name|MLD_QQIC_MANT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0f)
end_define

begin_define
define|#
directive|define
name|MLD_QRESV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x0f)
end_define

begin_define
define|#
directive|define
name|MLD_SFLAG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x01)
end_define

begin_define
define|#
directive|define
name|MLD_QRV
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x07)
end_define

begin_comment
comment|/*  * MLDv2 host membership report header.  * mld_type: MLDV2_LISTENER_REPORT  */
end_comment

begin_struct
struct|struct
name|mldv2_report
block|{
name|struct
name|icmp6_hdr
name|mld_icmp6_hdr
decl_stmt|;
comment|/* followed by 1..numgrps records */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* overlaid on struct icmp6_hdr. */
end_comment

begin_define
define|#
directive|define
name|mld_numrecs
value|mld_icmp6_hdr.icmp6_data16[1]
end_define

begin_struct
struct|struct
name|mldv2_record
block|{
name|uint8_t
name|mr_type
decl_stmt|;
comment|/* record type */
name|uint8_t
name|mr_datalen
decl_stmt|;
comment|/* length of auxiliary data */
name|uint16_t
name|mr_numsrc
decl_stmt|;
comment|/* number of sources */
name|struct
name|in6_addr
name|mr_addr
decl_stmt|;
comment|/* address being reported */
comment|/* followed by 1..numsrc source addresses */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MLD_V2_REPORT_MAXRECS
value|65535
end_define

begin_comment
comment|/*  * MLDv2 report modes.  */
end_comment

begin_define
define|#
directive|define
name|MLD_DO_NOTHING
value|0
end_define

begin_comment
comment|/* don't send a record */
end_comment

begin_define
define|#
directive|define
name|MLD_MODE_IS_INCLUDE
value|1
end_define

begin_comment
comment|/* MODE_IN */
end_comment

begin_define
define|#
directive|define
name|MLD_MODE_IS_EXCLUDE
value|2
end_define

begin_comment
comment|/* MODE_EX */
end_comment

begin_define
define|#
directive|define
name|MLD_CHANGE_TO_INCLUDE_MODE
value|3
end_define

begin_comment
comment|/* TO_IN */
end_comment

begin_define
define|#
directive|define
name|MLD_CHANGE_TO_EXCLUDE_MODE
value|4
end_define

begin_comment
comment|/* TO_EX */
end_comment

begin_define
define|#
directive|define
name|MLD_ALLOW_NEW_SOURCES
value|5
end_define

begin_comment
comment|/* ALLOW_NEW */
end_comment

begin_define
define|#
directive|define
name|MLD_BLOCK_OLD_SOURCES
value|6
end_define

begin_comment
comment|/* BLOCK_OLD */
end_comment

begin_comment
comment|/*  * MLDv2 query types.  */
end_comment

begin_define
define|#
directive|define
name|MLD_V2_GENERAL_QUERY
value|1
end_define

begin_define
define|#
directive|define
name|MLD_V2_GROUP_QUERY
value|2
end_define

begin_define
define|#
directive|define
name|MLD_V2_GROUP_SOURCE_QUERY
value|3
end_define

begin_comment
comment|/*  * Maximum report interval for MLDv1 host membership reports.  */
end_comment

begin_define
define|#
directive|define
name|MLD_V1_MAX_RI
value|10
end_define

begin_comment
comment|/*  * MLD_TIMER_SCALE denotes that the MLD code field specifies  * time in milliseconds.  */
end_comment

begin_define
define|#
directive|define
name|MLD_TIMER_SCALE
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET6_MLD6_H_ */
end_comment

end_unit

