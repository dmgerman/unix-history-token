begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)ip_icmp.h	7.5 (Berkeley) 6/28/90  *	$Id: ip_icmp.h,v 1.3 1993/11/07 17:47:57 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IP_ICMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IP_ICMP_H_
value|1
end_define

begin_comment
comment|/*  * Interface Control Message Protocol Definitions.  * Per RFC 792, September 1981.  */
end_comment

begin_comment
comment|/*  * Structure of an icmp header.  */
end_comment

begin_struct
struct|struct
name|icmp
block|{
name|u_char
name|icmp_type
decl_stmt|;
comment|/* type of message, see below */
name|u_char
name|icmp_code
decl_stmt|;
comment|/* type sub code */
name|u_short
name|icmp_cksum
decl_stmt|;
comment|/* ones complement cksum of struct */
union|union
block|{
name|u_char
name|ih_pptr
decl_stmt|;
comment|/* ICMP_PARAMPROB */
name|struct
name|in_addr
name|ih_gwaddr
decl_stmt|;
comment|/* ICMP_REDIRECT */
struct|struct
name|ih_idseq
block|{
name|n_short
name|icd_id
decl_stmt|;
name|n_short
name|icd_seq
decl_stmt|;
block|}
name|ih_idseq
struct|;
struct|struct
name|ih_mtu
block|{
name|n_short
name|imt_unused
decl_stmt|;
name|n_short
name|imt_nhmtu
decl_stmt|;
block|}
name|ih_mtu
struct|;
name|int
name|ih_void
decl_stmt|;
block|}
name|icmp_hun
union|;
define|#
directive|define
name|icmp_pptr
value|icmp_hun.ih_pptr
define|#
directive|define
name|icmp_gwaddr
value|icmp_hun.ih_gwaddr
define|#
directive|define
name|icmp_id
value|icmp_hun.ih_idseq.icd_id
define|#
directive|define
name|icmp_seq
value|icmp_hun.ih_idseq.icd_seq
define|#
directive|define
name|icmp_void
value|icmp_hun.ih_void
define|#
directive|define
name|icmp_mtu
value|icmp_hun.ih_mtu.imt_nhmtu
define|#
directive|define
name|icmp_mtuvoid
value|icmp_hun.ih_mtu.imt_unused
union|union
block|{
struct|struct
name|id_ts
block|{
name|n_time
name|its_otime
decl_stmt|;
name|n_time
name|its_rtime
decl_stmt|;
name|n_time
name|its_ttime
decl_stmt|;
block|}
name|id_ts
struct|;
struct|struct
name|id_ip
block|{
name|struct
name|ip
name|idi_ip
decl_stmt|;
comment|/* options and then 64 bits of data */
block|}
name|id_ip
struct|;
name|u_long
name|id_mask
decl_stmt|;
name|char
name|id_data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|icmp_dun
union|;
define|#
directive|define
name|icmp_otime
value|icmp_dun.id_ts.its_otime
define|#
directive|define
name|icmp_rtime
value|icmp_dun.id_ts.its_rtime
define|#
directive|define
name|icmp_ttime
value|icmp_dun.id_ts.its_ttime
define|#
directive|define
name|icmp_ip
value|icmp_dun.id_ip.idi_ip
define|#
directive|define
name|icmp_mask
value|icmp_dun.id_mask
define|#
directive|define
name|icmp_data
value|icmp_dun.id_data
block|}
struct|;
end_struct

begin_comment
comment|/*  * Lower bounds on packet lengths for various types.  * For the error advice packets must first insure that the  * packet is large enought to contain the returned ip header.  * Only then can we do the check to see if 64 bits of packet  * data have been returned, since we need to check the returned  * ip header length.  */
end_comment

begin_define
define|#
directive|define
name|ICMP_MINLEN
value|8
end_define

begin_comment
comment|/* abs minimum */
end_comment

begin_define
define|#
directive|define
name|ICMP_TSLEN
value|(8 + 3 * sizeof (n_time))
end_define

begin_comment
comment|/* timestamp */
end_comment

begin_define
define|#
directive|define
name|ICMP_MASKLEN
value|12
end_define

begin_comment
comment|/* address mask */
end_comment

begin_define
define|#
directive|define
name|ICMP_ADVLENMIN
value|(8 + sizeof (struct ip) + 8)
end_define

begin_comment
comment|/* min */
end_comment

begin_define
define|#
directive|define
name|ICMP_ADVLEN
parameter_list|(
name|p
parameter_list|)
value|(8 + ((p)->icmp_ip.ip_hl<< 2) + 8)
end_define

begin_comment
comment|/* N.B.: must separately check that ip_hl>= 5 */
end_comment

begin_comment
comment|/*  * Definition of type and code field values.  */
end_comment

begin_define
define|#
directive|define
name|ICMP_ECHOREPLY
value|0
end_define

begin_comment
comment|/* echo reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH
value|3
end_define

begin_comment
comment|/* dest unreachable, codes: */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET
value|0
end_define

begin_comment
comment|/* bad net */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST
value|1
end_define

begin_comment
comment|/* bad host */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_PROTOCOL
value|2
end_define

begin_comment
comment|/* bad protocol */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_PORT
value|3
end_define

begin_comment
comment|/* bad port */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_NEEDFRAG
value|4
end_define

begin_comment
comment|/* IP_DF caused drop */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_SRCFAIL
value|5
end_define

begin_comment
comment|/* src route failed */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_NETUNKNOWN
value|6
end_define

begin_comment
comment|/* dest net unknown */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_HSTUNKNOWN
value|7
end_define

begin_comment
comment|/* dst host unknown */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_ISOLATED
value|8
end_define

begin_comment
comment|/* src host isolated*/
end_comment

begin_comment
comment|/* next two are for administratively prohibited */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_NETADMIN
value|9
end_define

begin_comment
comment|/* dest net */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOSTADMIN
value|10
end_define

begin_comment
comment|/* dest host */
end_comment

begin_comment
comment|/* next two are for TOS unreachables */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSNET
value|11
end_define

begin_comment
comment|/* dest net+tos */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSHOST
value|12
end_define

begin_comment
comment|/* dest host+tos */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_MAXCODE
value|12
end_define

begin_define
define|#
directive|define
name|ICMP_SOURCEQUENCH
value|4
end_define

begin_comment
comment|/* packet lost, slow down */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT
value|5
end_define

begin_comment
comment|/* shorter route, codes: */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT_NET
value|0
end_define

begin_comment
comment|/* for network */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT_HOST
value|1
end_define

begin_comment
comment|/* for host */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT_TOSNET
value|2
end_define

begin_comment
comment|/* for tos and net */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT_TOSHOST
value|3
end_define

begin_comment
comment|/* for tos and host */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT_MAXCODE
value|3
end_define

begin_define
define|#
directive|define
name|ICMP_ECHO
value|8
end_define

begin_comment
comment|/* echo service */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMXCEED
value|11
end_define

begin_comment
comment|/* time exceeded, code: */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMXCEED_INTRANS
value|0
end_define

begin_comment
comment|/* ttl==0 in transit */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMXCEED_REASS
value|1
end_define

begin_comment
comment|/* ttl==0 in reass */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMXCEED_MAXCODE
value|1
end_define

begin_define
define|#
directive|define
name|ICMP_PARAMPROB
value|12
end_define

begin_comment
comment|/* ip header bad */
end_comment

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_GENERAL
value|0
end_define

begin_comment
comment|/* generic problems */
end_comment

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_REQDOPT
value|1
end_define

begin_comment
comment|/* option  misssing */
end_comment

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_MAXCODE
value|1
end_define

begin_define
define|#
directive|define
name|ICMP_TSTAMP
value|13
end_define

begin_comment
comment|/* timestamp request */
end_comment

begin_define
define|#
directive|define
name|ICMP_TSTAMPREPLY
value|14
end_define

begin_comment
comment|/* timestamp reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_IREQ
value|15
end_define

begin_comment
comment|/* information request */
end_comment

begin_define
define|#
directive|define
name|ICMP_IREQREPLY
value|16
end_define

begin_comment
comment|/* information reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_MASKREQ
value|17
end_define

begin_comment
comment|/* address mask request */
end_comment

begin_define
define|#
directive|define
name|ICMP_MASKREPLY
value|18
end_define

begin_comment
comment|/* address mask reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_MAXTYPE
value|18
end_define

begin_define
define|#
directive|define
name|ICMP_INFOTYPE
parameter_list|(
name|type
parameter_list|)
define|\
value|((type) == ICMP_ECHOREPLY || (type) == ICMP_ECHO || \ 	(type) == ICMP_TSTAMP || (type) == ICMP_TSTAMPREPLY || \ 	(type) == ICMP_IREQ || (type) == ICMP_IREQREPLY || \ 	(type) == ICMP_MASKREQ || (type) == ICMP_MASKREPLY)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|icmp_error
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|icmp_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|n_time
name|iptime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IP_ICMP_H_ */
end_comment

end_unit

