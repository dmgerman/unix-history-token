begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if.h	8.1 (Berkeley) 6/10/93  *	$Id: if.h,v 1.46 1997/05/03 21:07:12 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_H_
end_define

begin_comment
comment|/*  * Structure describing information about an interface  * which may be of interest to management entities.  */
end_comment

begin_struct
struct|struct
name|if_data
block|{
comment|/* generic interface information */
name|u_char
name|ifi_type
decl_stmt|;
comment|/* ethernet, tokenring, etc */
name|u_char
name|ifi_physical
decl_stmt|;
comment|/* e.g., AUI, Thinnet, 10base-T, etc */
name|u_char
name|ifi_addrlen
decl_stmt|;
comment|/* media address length */
name|u_char
name|ifi_hdrlen
decl_stmt|;
comment|/* media header length */
name|u_char
name|ifi_recvquota
decl_stmt|;
comment|/* polling quota for receive intrs */
name|u_char
name|ifi_xmitquota
decl_stmt|;
comment|/* polling quota for xmit intrs */
name|u_long
name|ifi_mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|u_long
name|ifi_metric
decl_stmt|;
comment|/* routing metric (external only) */
name|u_long
name|ifi_baudrate
decl_stmt|;
comment|/* linespeed */
comment|/* volatile statistics */
name|u_long
name|ifi_ipackets
decl_stmt|;
comment|/* packets received on interface */
name|u_long
name|ifi_ierrors
decl_stmt|;
comment|/* input errors on interface */
name|u_long
name|ifi_opackets
decl_stmt|;
comment|/* packets sent on interface */
name|u_long
name|ifi_oerrors
decl_stmt|;
comment|/* output errors on interface */
name|u_long
name|ifi_collisions
decl_stmt|;
comment|/* collisions on csma interfaces */
name|u_long
name|ifi_ibytes
decl_stmt|;
comment|/* total number of octets received */
name|u_long
name|ifi_obytes
decl_stmt|;
comment|/* total number of octets sent */
name|u_long
name|ifi_imcasts
decl_stmt|;
comment|/* packets received via multicast */
name|u_long
name|ifi_omcasts
decl_stmt|;
comment|/* packets sent via multicast */
name|u_long
name|ifi_iqdrops
decl_stmt|;
comment|/* dropped on input, this interface */
name|u_long
name|ifi_noproto
decl_stmt|;
comment|/* destined for unsupported protocol */
name|u_long
name|ifi_recvtiming
decl_stmt|;
comment|/* usec spent receiving when timing */
name|u_long
name|ifi_xmittiming
decl_stmt|;
comment|/* usec spent xmitting when timing */
name|struct
name|timeval
name|ifi_lastchange
decl_stmt|;
comment|/* time of last administrative change */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFF_UP
value|0x1
end_define

begin_comment
comment|/* interface is up */
end_comment

begin_define
define|#
directive|define
name|IFF_BROADCAST
value|0x2
end_define

begin_comment
comment|/* broadcast address valid */
end_comment

begin_define
define|#
directive|define
name|IFF_DEBUG
value|0x4
end_define

begin_comment
comment|/* turn on debugging */
end_comment

begin_define
define|#
directive|define
name|IFF_LOOPBACK
value|0x8
end_define

begin_comment
comment|/* is a loopback net */
end_comment

begin_define
define|#
directive|define
name|IFF_POINTOPOINT
value|0x10
end_define

begin_comment
comment|/* interface is point-to-point link */
end_comment

begin_comment
comment|/*#define IFF_NOTRAILERS 0x20		 * obsolete: avoid use of trailers */
end_comment

begin_define
define|#
directive|define
name|IFF_RUNNING
value|0x40
end_define

begin_comment
comment|/* resources allocated */
end_comment

begin_define
define|#
directive|define
name|IFF_NOARP
value|0x80
end_define

begin_comment
comment|/* no address resolution protocol */
end_comment

begin_define
define|#
directive|define
name|IFF_PROMISC
value|0x100
end_define

begin_comment
comment|/* receive all packets */
end_comment

begin_define
define|#
directive|define
name|IFF_ALLMULTI
value|0x200
end_define

begin_comment
comment|/* receive all multicast packets */
end_comment

begin_define
define|#
directive|define
name|IFF_OACTIVE
value|0x400
end_define

begin_comment
comment|/* transmission in progress */
end_comment

begin_define
define|#
directive|define
name|IFF_SIMPLEX
value|0x800
end_define

begin_comment
comment|/* can't hear own transmissions */
end_comment

begin_define
define|#
directive|define
name|IFF_LINK0
value|0x1000
end_define

begin_comment
comment|/* per link layer defined bit */
end_comment

begin_define
define|#
directive|define
name|IFF_LINK1
value|0x2000
end_define

begin_comment
comment|/* per link layer defined bit */
end_comment

begin_define
define|#
directive|define
name|IFF_LINK2
value|0x4000
end_define

begin_comment
comment|/* per link layer defined bit */
end_comment

begin_define
define|#
directive|define
name|IFF_ALTPHYS
value|IFF_LINK2
end_define

begin_comment
comment|/* use alternate physical connection */
end_comment

begin_define
define|#
directive|define
name|IFF_MULTICAST
value|0x8000
end_define

begin_comment
comment|/* supports multicast */
end_comment

begin_comment
comment|/* flags set internally only: */
end_comment

begin_define
define|#
directive|define
name|IFF_CANTCHANGE
define|\
value|(IFF_BROADCAST|IFF_POINTOPOINT|IFF_RUNNING|IFF_OACTIVE|\ 	    IFF_SIMPLEX|IFF_MULTICAST|IFF_ALLMULTI)
end_define

begin_define
define|#
directive|define
name|IFQ_MAXLEN
value|50
end_define

begin_define
define|#
directive|define
name|IFNET_SLOWHZ
value|1
end_define

begin_comment
comment|/* granularity is 1 second */
end_comment

begin_comment
comment|/*  * Message format for use in obtaining information about interfaces  * from getkerninfo and the routing socket  */
end_comment

begin_struct
struct|struct
name|if_msghdr
block|{
name|u_short
name|ifm_msglen
decl_stmt|;
comment|/* to skip over non-understood messages */
name|u_char
name|ifm_version
decl_stmt|;
comment|/* future binary compatability */
name|u_char
name|ifm_type
decl_stmt|;
comment|/* message type */
name|int
name|ifm_addrs
decl_stmt|;
comment|/* like rtm_addrs */
name|int
name|ifm_flags
decl_stmt|;
comment|/* value of if_flags */
name|u_short
name|ifm_index
decl_stmt|;
comment|/* index for associated ifp */
name|struct
name|if_data
name|ifm_data
decl_stmt|;
comment|/* statistics and other data about if */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Message format for use in obtaining information about interface addresses  * from getkerninfo and the routing socket  */
end_comment

begin_struct
struct|struct
name|ifa_msghdr
block|{
name|u_short
name|ifam_msglen
decl_stmt|;
comment|/* to skip over non-understood messages */
name|u_char
name|ifam_version
decl_stmt|;
comment|/* future binary compatability */
name|u_char
name|ifam_type
decl_stmt|;
comment|/* message type */
name|int
name|ifam_addrs
decl_stmt|;
comment|/* like rtm_addrs */
name|int
name|ifam_flags
decl_stmt|;
comment|/* value of ifa_flags */
name|u_short
name|ifam_index
decl_stmt|;
comment|/* index for associated ifp */
name|int
name|ifam_metric
decl_stmt|;
comment|/* value of ifa_metric */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Message format for use in obtaining information about multicast addresses  * from the routing socket  */
end_comment

begin_struct
struct|struct
name|ifma_msghdr
block|{
name|u_short
name|ifmam_msglen
decl_stmt|;
comment|/* to skip over non-understood messages */
name|u_char
name|ifmam_version
decl_stmt|;
comment|/* future binary compatability */
name|u_char
name|ifmam_type
decl_stmt|;
comment|/* message type */
name|int
name|ifmam_addrs
decl_stmt|;
comment|/* like rtm_addrs */
name|int
name|ifmam_flags
decl_stmt|;
comment|/* value of ifa_flags */
name|u_short
name|ifmam_index
decl_stmt|;
comment|/* index for associated ifp */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface request structure used for socket  * ioctl's.  All interface ioctl's must have parameter  * definitions which begin with ifr_name.  The  * remainder may be interface specific.  */
end_comment

begin_struct
struct|struct
name|ifreq
block|{
define|#
directive|define
name|IFNAMSIZ
value|16
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
union|union
block|{
name|struct
name|sockaddr
name|ifru_addr
decl_stmt|;
name|struct
name|sockaddr
name|ifru_dstaddr
decl_stmt|;
name|struct
name|sockaddr
name|ifru_broadaddr
decl_stmt|;
name|short
name|ifru_flags
decl_stmt|;
name|int
name|ifru_metric
decl_stmt|;
name|int
name|ifru_mtu
decl_stmt|;
name|int
name|ifru_phys
decl_stmt|;
name|int
name|ifru_media
decl_stmt|;
name|caddr_t
name|ifru_data
decl_stmt|;
block|}
name|ifr_ifru
union|;
define|#
directive|define
name|ifr_addr
value|ifr_ifru.ifru_addr
comment|/* address */
define|#
directive|define
name|ifr_dstaddr
value|ifr_ifru.ifru_dstaddr
comment|/* other end of p-to-p link */
define|#
directive|define
name|ifr_broadaddr
value|ifr_ifru.ifru_broadaddr
comment|/* broadcast address */
define|#
directive|define
name|ifr_flags
value|ifr_ifru.ifru_flags
comment|/* flags */
define|#
directive|define
name|ifr_metric
value|ifr_ifru.ifru_metric
comment|/* metric */
define|#
directive|define
name|ifr_mtu
value|ifr_ifru.ifru_mtu
comment|/* mtu */
define|#
directive|define
name|ifr_phys
value|ifr_ifru.ifru_phys
comment|/* physical wire */
define|#
directive|define
name|ifr_media
value|ifr_ifru.ifru_media
comment|/* physical media */
define|#
directive|define
name|ifr_data
value|ifr_ifru.ifru_data
comment|/* for use by interface */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifaliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr
name|ifra_broadaddr
decl_stmt|;
name|struct
name|sockaddr
name|ifra_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifmediareq
block|{
name|char
name|ifm_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|int
name|ifm_current
decl_stmt|;
comment|/* current media options */
name|int
name|ifm_mask
decl_stmt|;
comment|/* don't care mask */
name|int
name|ifm_status
decl_stmt|;
comment|/* media status */
name|int
name|ifm_active
decl_stmt|;
comment|/* active options */
name|int
name|ifm_count
decl_stmt|;
comment|/* # entries in ifm_ulist array */
name|int
modifier|*
name|ifm_ulist
decl_stmt|;
comment|/* media words */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used in SIOCGIFCONF request.  * Used to retrieve interface configuration  * for machine (useful for programs which  * must know all networks accessible).  */
end_comment

begin_struct
struct|struct
name|ifconf
block|{
name|int
name|ifc_len
decl_stmt|;
comment|/* size of associated buffer */
union|union
block|{
name|caddr_t
name|ifcu_buf
decl_stmt|;
name|struct
name|ifreq
modifier|*
name|ifcu_req
decl_stmt|;
block|}
name|ifc_ifcu
union|;
define|#
directive|define
name|ifc_buf
value|ifc_ifcu.ifcu_buf
comment|/* buffer address */
define|#
directive|define
name|ifc_req
value|ifc_ifcu.ifcu_req
comment|/* array of structures returned */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IFADDR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IFMADDR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX - this should go away soon */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_H_ */
end_comment

end_unit

