begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ip6_mroute.h,v 1.19 2001/06/14 06:12:55 suz Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*	BSDI ip_mroute.h,v 2.5 1996/10/11 16:01:48 pjd Exp	*/
end_comment

begin_comment
comment|/*  * Definitions for IP multicast forwarding.  *  * Written by David Waitzman, BBN Labs, August 1988.  * Modified by Steve Deering, Stanford, February 1989.  * Modified by Ajit Thyagarajan, PARC, August 1993.  * Modified by Ajit Thyagarajan, PARC, August 1994.  * Modified by Ahmed Helmy, USC, September 1996.  *  * MROUTING Revision: 1.2  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IP6_MROUTE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IP6_MROUTE_H_
end_define

begin_comment
comment|/*  * Multicast Routing set/getsockopt commands.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MRT6_OINIT
value|100
end_define

begin_comment
comment|/* initialize forwarder (omrt6msg) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MRT6_DONE
value|101
end_define

begin_comment
comment|/* shut down forwarder */
end_comment

begin_define
define|#
directive|define
name|MRT6_ADD_MIF
value|102
end_define

begin_comment
comment|/* add multicast interface */
end_comment

begin_define
define|#
directive|define
name|MRT6_DEL_MIF
value|103
end_define

begin_comment
comment|/* delete multicast interface */
end_comment

begin_define
define|#
directive|define
name|MRT6_ADD_MFC
value|104
end_define

begin_comment
comment|/* insert forwarding cache entry */
end_comment

begin_define
define|#
directive|define
name|MRT6_DEL_MFC
value|105
end_define

begin_comment
comment|/* delete forwarding cache entry */
end_comment

begin_define
define|#
directive|define
name|MRT6_PIM
value|107
end_define

begin_comment
comment|/* enable pim code */
end_comment

begin_define
define|#
directive|define
name|MRT6_INIT
value|108
end_define

begin_comment
comment|/* initialize forwarder (mrt6msg) */
end_comment

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199103
end_if

begin_define
define|#
directive|define
name|GET_TIME
parameter_list|(
name|t
parameter_list|)
value|microtime(&t)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sun
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GET_TIME
parameter_list|(
name|t
parameter_list|)
value|uniqtime(&t)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_TIME
parameter_list|(
name|t
parameter_list|)
value|((t) = time)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Types and macros for handling bitmaps with one bit per multicast interface.  */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|mifi_t
typedef|;
end_typedef

begin_comment
comment|/* type of a mif index */
end_comment

begin_define
define|#
directive|define
name|MAXMIFS
value|64
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IF_SETSIZE
end_ifndef

begin_define
define|#
directive|define
name|IF_SETSIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|u_int32_t
name|if_mask
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NIFBITS
value|(sizeof(if_mask) * NBBY)
end_define

begin_comment
comment|/* bits per mask */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|howmany
end_ifndef

begin_define
define|#
directive|define
name|howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) + ((y) - 1)) / (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|if_set
block|{
name|if_mask
name|ifs_bits
index|[
name|howmany
argument_list|(
name|IF_SETSIZE
argument_list|,
name|NIFBITS
argument_list|)
index|]
decl_stmt|;
block|}
name|if_set
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IF_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->ifs_bits[(n)/NIFBITS] |= (1<< ((n) % NIFBITS)))
end_define

begin_define
define|#
directive|define
name|IF_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->ifs_bits[(n)/NIFBITS]&= ~(1<< ((n) % NIFBITS)))
end_define

begin_define
define|#
directive|define
name|IF_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->ifs_bits[(n)/NIFBITS]& (1<< ((n) % NIFBITS)))
end_define

begin_define
define|#
directive|define
name|IF_COPY
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|bcopy(f, t, sizeof(*(f)))
end_define

begin_define
define|#
directive|define
name|IF_ZERO
parameter_list|(
name|p
parameter_list|)
value|bzero(p, sizeof(*(p)))
end_define

begin_comment
comment|/*  * Argument structure for MRT6_ADD_IF.  */
end_comment

begin_struct
struct|struct
name|mif6ctl
block|{
name|mifi_t
name|mif6c_mifi
decl_stmt|;
comment|/* the index of the mif to be added  */
name|u_char
name|mif6c_flags
decl_stmt|;
comment|/* MIFF_ flags defined below         */
name|u_short
name|mif6c_pifi
decl_stmt|;
comment|/* the index of the physical IF */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MIFF_REGISTER
value|0x1
end_define

begin_comment
comment|/* mif represents a register end-point */
end_comment

begin_comment
comment|/*  * Argument structure for MRT6_ADD_MFC and MRT6_DEL_MFC  */
end_comment

begin_struct
struct|struct
name|mf6cctl
block|{
name|struct
name|sockaddr_in6
name|mf6cc_origin
decl_stmt|;
comment|/* IPv6 origin of mcasts */
name|struct
name|sockaddr_in6
name|mf6cc_mcastgrp
decl_stmt|;
comment|/* multicast group associated */
name|mifi_t
name|mf6cc_parent
decl_stmt|;
comment|/* incoming ifindex */
name|struct
name|if_set
name|mf6cc_ifset
decl_stmt|;
comment|/* set of forwarding ifs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The kernel's multicast routing statistics.  */
end_comment

begin_struct
struct|struct
name|mrt6stat
block|{
name|u_quad_t
name|mrt6s_mfc_lookups
decl_stmt|;
comment|/* # forw. cache hash table hits   */
name|u_quad_t
name|mrt6s_mfc_misses
decl_stmt|;
comment|/* # forw. cache hash table misses */
name|u_quad_t
name|mrt6s_upcalls
decl_stmt|;
comment|/* # calls to multicast routing daemon */
name|u_quad_t
name|mrt6s_no_route
decl_stmt|;
comment|/* no route for packet's origin    */
name|u_quad_t
name|mrt6s_bad_tunnel
decl_stmt|;
comment|/* malformed tunnel options        */
name|u_quad_t
name|mrt6s_cant_tunnel
decl_stmt|;
comment|/* no room for tunnel options      */
name|u_quad_t
name|mrt6s_wrong_if
decl_stmt|;
comment|/* arrived on wrong interface	   */
name|u_quad_t
name|mrt6s_upq_ovflw
decl_stmt|;
comment|/* upcall Q overflow		   */
name|u_quad_t
name|mrt6s_cache_cleanups
decl_stmt|;
comment|/* # entries with no upcalls 	   */
name|u_quad_t
name|mrt6s_drop_sel
decl_stmt|;
comment|/* pkts dropped selectively        */
name|u_quad_t
name|mrt6s_q_overflow
decl_stmt|;
comment|/* pkts dropped - Q overflow       */
name|u_quad_t
name|mrt6s_pkt2large
decl_stmt|;
comment|/* pkts dropped - size> BKT SIZE  */
name|u_quad_t
name|mrt6s_upq_sockfull
decl_stmt|;
comment|/* upcalls dropped - socket full   */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|MRT6_OINIT
end_ifdef

begin_comment
comment|/*  * Struct used to communicate from kernel to multicast router  * note the convenient similarity to an IPv6 header.  * XXX old version, superseded by mrt6msg.  */
end_comment

begin_struct
struct|struct
name|omrt6msg
block|{
name|u_long
name|unused1
decl_stmt|;
name|u_char
name|im6_msgtype
decl_stmt|;
comment|/* what type of message	    */
if|#
directive|if
literal|0
define|#
directive|define
name|MRT6MSG_NOCACHE
value|1
define|#
directive|define
name|MRT6MSG_WRONGMIF
value|2
define|#
directive|define
name|MRT6MSG_WHOLEPKT
value|3
comment|/* used for user level encap*/
endif|#
directive|endif
name|u_char
name|im6_mbz
decl_stmt|;
comment|/* must be zero		    */
name|u_char
name|im6_mif
decl_stmt|;
comment|/* mif rec'd on		    */
name|u_char
name|unused2
decl_stmt|;
name|struct
name|in6_addr
name|im6_src
decl_stmt|,
name|im6_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure used to communicate from kernel to multicast router.  * We'll overlay the structure onto an MLD header (not an IPv6 header  * like igmpmsg{} used for IPv4 implementation). This is because this  * structure will be passed via an IPv6 raw socket, on which an application  * will only receive the payload i.e. the data after the IPv6 header and all  * the extension headers. (see Section 3 of RFC3542)  */
end_comment

begin_struct
struct|struct
name|mrt6msg
block|{
define|#
directive|define
name|MRT6MSG_NOCACHE
value|1
define|#
directive|define
name|MRT6MSG_WRONGMIF
value|2
define|#
directive|define
name|MRT6MSG_WHOLEPKT
value|3
comment|/* used for user level encap*/
name|u_char
name|im6_mbz
decl_stmt|;
comment|/* must be zero		    */
name|u_char
name|im6_msgtype
decl_stmt|;
comment|/* what type of message	    */
name|u_int16_t
name|im6_mif
decl_stmt|;
comment|/* mif rec'd on		    */
name|u_int32_t
name|im6_pad
decl_stmt|;
comment|/* padding for 64bit arch   */
name|struct
name|in6_addr
name|im6_src
decl_stmt|,
name|im6_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument structure used by multicast routing daemon to get src-grp  * packet counts  */
end_comment

begin_struct
struct|struct
name|sioc_sg_req6
block|{
name|struct
name|sockaddr_in6
name|src
decl_stmt|;
name|struct
name|sockaddr_in6
name|grp
decl_stmt|;
name|u_quad_t
name|pktcnt
decl_stmt|;
name|u_quad_t
name|bytecnt
decl_stmt|;
name|u_quad_t
name|wrong_if
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument structure used by mrouted to get mif pkt counts  */
end_comment

begin_struct
struct|struct
name|sioc_mif_req6
block|{
name|mifi_t
name|mifi
decl_stmt|;
comment|/* mif number				*/
name|u_quad_t
name|icount
decl_stmt|;
comment|/* Input packet count on mif		*/
name|u_quad_t
name|ocount
decl_stmt|;
comment|/* Output packet count on mif		*/
name|u_quad_t
name|ibytes
decl_stmt|;
comment|/* Input byte count on mif		*/
name|u_quad_t
name|obytes
decl_stmt|;
comment|/* Output byte count on mif		*/
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_comment
comment|/*  * The kernel's multicast-interface structure.  */
end_comment

begin_struct
struct|struct
name|mif6
block|{
name|u_char
name|m6_flags
decl_stmt|;
comment|/* MIFF_ flags defined above         */
name|u_int
name|m6_rate_limit
decl_stmt|;
comment|/* max rate			     */
name|struct
name|in6_addr
name|m6_lcl_addr
decl_stmt|;
comment|/* local interface address           */
name|struct
name|ifnet
modifier|*
name|m6_ifp
decl_stmt|;
comment|/* pointer to interface              */
name|u_quad_t
name|m6_pkt_in
decl_stmt|;
comment|/* # pkts in on interface            */
name|u_quad_t
name|m6_pkt_out
decl_stmt|;
comment|/* # pkts out on interface           */
name|u_quad_t
name|m6_bytes_in
decl_stmt|;
comment|/* # bytes in on interface	     */
name|u_quad_t
name|m6_bytes_out
decl_stmt|;
comment|/* # bytes out on interface	     */
name|struct
name|route_in6
name|m6_route
decl_stmt|;
comment|/* cached route if this is a tunnel */
ifdef|#
directive|ifdef
name|notyet
name|u_int
name|m6_rsvp_on
decl_stmt|;
comment|/* RSVP listening on this vif */
name|struct
name|socket
modifier|*
name|m6_rsvpd
decl_stmt|;
comment|/* RSVP daemon socket */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The kernel's multicast forwarding cache entry structure  */
end_comment

begin_struct
struct|struct
name|mf6c
block|{
name|struct
name|sockaddr_in6
name|mf6c_origin
decl_stmt|;
comment|/* IPv6 origin of mcasts     */
name|struct
name|sockaddr_in6
name|mf6c_mcastgrp
decl_stmt|;
comment|/* multicast group associated*/
name|mifi_t
name|mf6c_parent
decl_stmt|;
comment|/* incoming IF               */
name|struct
name|if_set
name|mf6c_ifset
decl_stmt|;
comment|/* set of outgoing IFs */
name|u_quad_t
name|mf6c_pkt_cnt
decl_stmt|;
comment|/* pkt count for src-grp     */
name|u_quad_t
name|mf6c_byte_cnt
decl_stmt|;
comment|/* byte count for src-grp    */
name|u_quad_t
name|mf6c_wrong_if
decl_stmt|;
comment|/* wrong if for src-grp	     */
name|int
name|mf6c_expire
decl_stmt|;
comment|/* time to clean entry up    */
name|struct
name|timeval
name|mf6c_last_assert
decl_stmt|;
comment|/* last time I sent an assert*/
name|struct
name|rtdetq
modifier|*
name|mf6c_stall
decl_stmt|;
comment|/* pkts waiting for route */
name|struct
name|mf6c
modifier|*
name|mf6c_next
decl_stmt|;
comment|/* hash table linkage */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MF6C_INCOMPLETE_PARENT
value|((mifi_t)-1)
end_define

begin_comment
comment|/*  * Argument structure used for pkt info. while upcall is made  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IP_MROUTE_H_
end_ifndef

begin_struct
struct|struct
name|rtdetq
block|{
comment|/* XXX: rtdetq is also defined in ip_mroute.h */
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* A copy of the packet	    	    */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* Interface pkt came in on 	    */
ifdef|#
directive|ifdef
name|UPCALL_TIMING
name|struct
name|timeval
name|t
decl_stmt|;
comment|/* Timestamp */
endif|#
directive|endif
comment|/* UPCALL_TIMING */
name|struct
name|rtdetq
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IP_MROUTE_H_ */
end_comment

begin_define
define|#
directive|define
name|MF6CTBLSIZ
value|256
end_define

begin_if
if|#
directive|if
operator|(
name|MF6CTBLSIZ
operator|&
operator|(
name|MF6CTBLSIZ
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
end_if

begin_comment
comment|/* from sys:route.h */
end_comment

begin_define
define|#
directive|define
name|MF6CHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h)& (MF6CTBLSIZ - 1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MF6CHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h) % MF6CTBLSIZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_UPQ6
value|4
end_define

begin_comment
comment|/* max. no of pkts in upcall Q */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip6_mrouter_set
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip6_mrouter_get
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip6_mrouter_done
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|mrt6_ioctl
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_NETINET6_IP6_MROUTE_H_ */
end_comment

end_unit

