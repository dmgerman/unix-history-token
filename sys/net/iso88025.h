begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998, Larry Lile  * All rights reserved.  *  * For latest sources and information on this driver, please  * go to http://anarchy.stdio.com.  *  * Questions, comments or suggestions should be directed to  * Larry Lile<lile@stdio.com>.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Information gathered from tokenring@freebsd, /sys/net/ethernet.h and  * the Mach token ring driver.  */
end_comment

begin_comment
comment|/*  * Fundamental constants relating to iso 802.5  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_ISO88025_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_ISO88025_H_
end_define

begin_comment
comment|/*  * General ISO 802.5 definitions  */
end_comment

begin_define
define|#
directive|define
name|ISO88025_ADDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|ISO88025_HDR_LEN
value|(ISO88025_CF_LEN + (ISO88025_ADDR_LEN * 2))
end_define

begin_define
define|#
directive|define
name|ISO88025_CF_LEN
value|2
end_define

begin_define
define|#
directive|define
name|RCF_LEN
value|2
end_define

begin_define
define|#
directive|define
name|RIF_MAX_RD
value|14
end_define

begin_define
define|#
directive|define
name|RIF_MAX_LEN
value|16
end_define

begin_define
define|#
directive|define
name|TR_AC
value|0x10
end_define

begin_define
define|#
directive|define
name|TR_LLC_FRAME
value|0x40
end_define

begin_define
define|#
directive|define
name|TR_4MBPS
value|4000000
end_define

begin_define
define|#
directive|define
name|TR_16MBPS
value|16000000
end_define

begin_define
define|#
directive|define
name|TR_100MBPS
value|100000000
end_define

begin_comment
comment|/*  * Source routing   */
end_comment

begin_define
define|#
directive|define
name|TR_RII
value|0x80
end_define

begin_define
define|#
directive|define
name|TR_RCF_BCST_MASK
value|0xe000
end_define

begin_define
define|#
directive|define
name|TR_RCF_LEN_MASK
value|0x1f00
end_define

begin_define
define|#
directive|define
name|TR_RCF_DIR
value|0x0080
end_define

begin_define
define|#
directive|define
name|TR_RCF_LF_MASK
value|0x0070
end_define

begin_define
define|#
directive|define
name|TR_RCF_RIFLEN
parameter_list|(
name|x
parameter_list|)
value|((ntohs(x)& TR_RCF_LEN_MASK)>> 8)
end_define

begin_comment
comment|/*  * Minimum and maximum packet payload lengths.  */
end_comment

begin_define
define|#
directive|define
name|ISO88025_MIN_LEN
value|0
end_define

begin_define
define|#
directive|define
name|ISO88025_MAX_LEN
value|17960
end_define

begin_comment
comment|/*  * A macro to validate a length with  */
end_comment

begin_define
define|#
directive|define
name|ISO88025_IS_VALID_LEN
parameter_list|(
name|foo
parameter_list|)
define|\
value|((foo)>= ISO88025_MIN_LEN&& (foo)<= ISO88025_MAX_LEN)
end_define

begin_comment
comment|/*  * ISO 802.5 physical header  */
end_comment

begin_struct
struct|struct
name|iso88025_header
block|{
name|u_char
name|ac
decl_stmt|;
comment|/* access control field */
name|u_char
name|fc
decl_stmt|;
comment|/* frame control field */
name|u_char
name|iso88025_dhost
index|[
name|ISO88025_ADDR_LEN
index|]
decl_stmt|;
comment|/* destination address */
name|u_char
name|iso88025_shost
index|[
name|ISO88025_ADDR_LEN
index|]
decl_stmt|;
comment|/* source address */
name|u_short
name|rcf
decl_stmt|;
comment|/* route control field */
name|u_short
name|rd
index|[
name|RIF_MAX_RD
index|]
decl_stmt|;
comment|/* routing designators */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iso88025_sockaddr_data
block|{
name|u_char
name|ether_dhost
index|[
name|ISO88025_ADDR_LEN
index|]
decl_stmt|;
name|u_char
name|ether_shost
index|[
name|ISO88025_ADDR_LEN
index|]
decl_stmt|;
name|u_char
name|ac
decl_stmt|;
name|u_char
name|fc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a 48-bit iso 802.5 address.  *  ( We could also add the 16 bit addresses as a union)  */
end_comment

begin_struct
struct|struct
name|iso88025_addr
block|{
name|u_char
name|octet
index|[
name|ISO88025_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISO88025_MAX_MTU
value|18000
end_define

begin_define
define|#
directive|define
name|ISO88025_DEFAULT_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|senderr
parameter_list|(
name|e
parameter_list|)
value|{ error = (e); goto bad;}
end_define

begin_decl_stmt
name|void
name|iso88025_ifattach
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iso88025_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iso88025_output
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iso88025_input
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|iso88025_header
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

