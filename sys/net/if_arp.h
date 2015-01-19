begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_arp.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_ARP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_ARP_H_
end_define

begin_comment
comment|/*  * Address Resolution Protocol.  *  * See RFC 826 for protocol description.  ARP packets are variable  * in size; the arphdr structure defines the fixed-length portion.  * Protocol type values are the same as those for 10 Mb/s Ethernet.  * It is followed by the variable-sized fields ar_sha, arp_spa,  * arp_tha and arp_tpa in that order, according to the lengths  * specified.  Field names used correspond to RFC 826.  */
end_comment

begin_struct
struct|struct
name|arphdr
block|{
name|u_short
name|ar_hrd
decl_stmt|;
comment|/* format of hardware address */
define|#
directive|define
name|ARPHRD_ETHER
value|1
comment|/* ethernet hardware format */
define|#
directive|define
name|ARPHRD_IEEE802
value|6
comment|/* token-ring hardware format */
define|#
directive|define
name|ARPHRD_ARCNET
value|7
comment|/* arcnet hardware format */
define|#
directive|define
name|ARPHRD_FRELAY
value|15
comment|/* frame relay hardware format */
define|#
directive|define
name|ARPHRD_IEEE1394
value|24
comment|/* firewire hardware format */
define|#
directive|define
name|ARPHRD_INFINIBAND
value|32
comment|/* infiniband hardware format */
name|u_short
name|ar_pro
decl_stmt|;
comment|/* format of protocol address */
name|u_char
name|ar_hln
decl_stmt|;
comment|/* length of hardware address */
name|u_char
name|ar_pln
decl_stmt|;
comment|/* length of protocol address */
name|u_short
name|ar_op
decl_stmt|;
comment|/* one of: */
define|#
directive|define
name|ARPOP_REQUEST
value|1
comment|/* request to resolve address */
define|#
directive|define
name|ARPOP_REPLY
value|2
comment|/* response to previous request */
define|#
directive|define
name|ARPOP_REVREQUEST
value|3
comment|/* request protocol address given hardware */
define|#
directive|define
name|ARPOP_REVREPLY
value|4
comment|/* response giving protocol address */
define|#
directive|define
name|ARPOP_INVREQUEST
value|8
comment|/* request to identify peer */
define|#
directive|define
name|ARPOP_INVREPLY
value|9
comment|/* response identifying peer */
comment|/*  * The remaining fields are variable in size,  * according to the sizes above.  */
ifdef|#
directive|ifdef
name|COMMENT_ONLY
name|u_char
name|ar_sha
index|[]
decl_stmt|;
comment|/* sender hardware address */
name|u_char
name|ar_spa
index|[]
decl_stmt|;
comment|/* sender protocol address */
name|u_char
name|ar_tha
index|[]
decl_stmt|;
comment|/* target hardware address */
name|u_char
name|ar_tpa
index|[]
decl_stmt|;
comment|/* target protocol address */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ar_sha
parameter_list|(
name|ap
parameter_list|)
value|(((caddr_t)((ap)+1)) +   0)
end_define

begin_define
define|#
directive|define
name|ar_spa
parameter_list|(
name|ap
parameter_list|)
value|(((caddr_t)((ap)+1)) +   (ap)->ar_hln)
end_define

begin_define
define|#
directive|define
name|ar_tha
parameter_list|(
name|ap
parameter_list|)
value|(((caddr_t)((ap)+1)) +   (ap)->ar_hln + (ap)->ar_pln)
end_define

begin_define
define|#
directive|define
name|ar_tpa
parameter_list|(
name|ap
parameter_list|)
value|(((caddr_t)((ap)+1)) + 2*(ap)->ar_hln + (ap)->ar_pln)
end_define

begin_define
define|#
directive|define
name|arphdr_len2
parameter_list|(
name|ar_hln
parameter_list|,
name|ar_pln
parameter_list|)
define|\
value|(sizeof(struct arphdr) + 2*(ar_hln) + 2*(ar_pln))
end_define

begin_define
define|#
directive|define
name|arphdr_len
parameter_list|(
name|ap
parameter_list|)
value|(arphdr_len2((ap)->ar_hln, (ap)->ar_pln))
end_define

begin_comment
comment|/*  * ARP ioctl request  */
end_comment

begin_struct
struct|struct
name|arpreq
block|{
name|struct
name|sockaddr
name|arp_pa
decl_stmt|;
comment|/* protocol address */
name|struct
name|sockaddr
name|arp_ha
decl_stmt|;
comment|/* hardware address */
name|int
name|arp_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  arp_flags and at_flags field values */
end_comment

begin_define
define|#
directive|define
name|ATF_INUSE
value|0x01
end_define

begin_comment
comment|/* entry in use */
end_comment

begin_define
define|#
directive|define
name|ATF_COM
value|0x02
end_define

begin_comment
comment|/* completed entry (enaddr valid) */
end_comment

begin_define
define|#
directive|define
name|ATF_PERM
value|0x04
end_define

begin_comment
comment|/* permanent entry */
end_comment

begin_define
define|#
directive|define
name|ATF_PUBL
value|0x08
end_define

begin_comment
comment|/* publish entry (respond for other host) */
end_comment

begin_define
define|#
directive|define
name|ATF_USETRAILERS
value|0x10
end_define

begin_comment
comment|/* has requested trailers */
end_comment

begin_struct
struct|struct
name|arpstat
block|{
comment|/* Normal things that happen: */
name|uint64_t
name|txrequests
decl_stmt|;
comment|/* # of ARP requests sent by this host. */
name|uint64_t
name|txreplies
decl_stmt|;
comment|/* # of ARP replies sent by this host. */
name|uint64_t
name|rxrequests
decl_stmt|;
comment|/* # of ARP requests received by this host. */
name|uint64_t
name|rxreplies
decl_stmt|;
comment|/* # of ARP replies received by this host. */
name|uint64_t
name|received
decl_stmt|;
comment|/* # of ARP packets received by this host. */
name|uint64_t
name|arp_spares
index|[
literal|4
index|]
decl_stmt|;
comment|/* For either the upper or lower half. */
comment|/* Abnormal event and error  counting: */
name|uint64_t
name|dropped
decl_stmt|;
comment|/* # of packets dropped waiting for a reply. */
name|uint64_t
name|timeouts
decl_stmt|;
comment|/* # of times with entries removed */
comment|/* due to timeout. */
name|uint64_t
name|dupips
decl_stmt|;
comment|/* # of duplicate IPs detected. */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/counter.h>
end_include

begin_include
include|#
directive|include
file|<net/vnet.h>
end_include

begin_expr_stmt
name|VNET_PCPUSTAT_DECLARE
argument_list|(
expr|struct
name|arpstat
argument_list|,
name|arpstat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * In-kernel consumers can use these accessor macros directly to update  * stats.  */
end_comment

begin_define
define|#
directive|define
name|ARPSTAT_ADD
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|VNET_PCPUSTAT_ADD(struct arpstat, arpstat, name, (val))
end_define

begin_define
define|#
directive|define
name|ARPSTAT_SUB
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
value|ARPSTAT_ADD(name, -(val))
end_define

begin_define
define|#
directive|define
name|ARPSTAT_INC
parameter_list|(
name|name
parameter_list|)
value|ARPSTAT_ADD(name, 1)
end_define

begin_define
define|#
directive|define
name|ARPSTAT_DEC
parameter_list|(
name|name
parameter_list|)
value|ARPSTAT_SUB(name, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_ARP_H_ */
end_comment

end_unit

