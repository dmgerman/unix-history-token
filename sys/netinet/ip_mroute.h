begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Stephen Deering.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ip_mroute.h	8.1 (Berkeley) 6/10/93  * $Id: ip_mroute.h,v 1.4 1994/09/06 22:42:23 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IP_MROUTE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IP_MROUTE_H_
end_define

begin_comment
comment|/*  * Definitions for the kernel part of DVMRP,  * a Distance-Vector Multicast Routing Protocol.  * (See RFC-1075.)  *  * Written by David Waitzman, BBN Labs, August 1988.  * Modified by Steve Deering, Stanford, February 1989.  * Modified by Ajit Thyagarajan, PARC, August 1993.  * Modified by Ajit Thyagarajan, PARC, August 1994.  *  * MROUTING 1.5  */
end_comment

begin_comment
comment|/*  * DVMRP-specific setsockopt commands.  */
end_comment

begin_define
define|#
directive|define
name|DVMRP_INIT
value|100
end_define

begin_comment
comment|/* initialize forwarder */
end_comment

begin_define
define|#
directive|define
name|DVMRP_DONE
value|101
end_define

begin_comment
comment|/* shut down forwarder */
end_comment

begin_define
define|#
directive|define
name|DVMRP_ADD_VIF
value|102
end_define

begin_comment
comment|/* create virtual interface */
end_comment

begin_define
define|#
directive|define
name|DVMRP_DEL_VIF
value|103
end_define

begin_comment
comment|/* delete virtual interface */
end_comment

begin_define
define|#
directive|define
name|DVMRP_ADD_MFC
value|104
end_define

begin_comment
comment|/* insert forwarding cache entry */
end_comment

begin_define
define|#
directive|define
name|DVMRP_DEL_MFC
value|105
end_define

begin_comment
comment|/* delete forwarding cache entry */
end_comment

begin_define
define|#
directive|define
name|GET_TIME
parameter_list|(
name|t
parameter_list|)
value|microtime(&t)
end_define

begin_comment
comment|/*  * Types and macros for handling bitmaps with one bit per virtual interface.  */
end_comment

begin_define
define|#
directive|define
name|MAXVIFS
value|32
end_define

begin_typedef
typedef|typedef
name|u_long
name|vifbitmap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|vifi_t
typedef|;
end_typedef

begin_comment
comment|/* type of a vif index */
end_comment

begin_define
define|#
directive|define
name|VIFM_SET
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|((m) |= (1<< (n)))
end_define

begin_define
define|#
directive|define
name|VIFM_CLR
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|((m)&= ~(1<< (n)))
end_define

begin_define
define|#
directive|define
name|VIFM_ISSET
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|((m)& (1<< (n)))
end_define

begin_define
define|#
directive|define
name|VIFM_CLRALL
parameter_list|(
name|m
parameter_list|)
value|((m) = 0x00000000)
end_define

begin_define
define|#
directive|define
name|VIFM_COPY
parameter_list|(
name|mfrom
parameter_list|,
name|mto
parameter_list|)
value|((mto) = (mfrom))
end_define

begin_define
define|#
directive|define
name|VIFM_SAME
parameter_list|(
name|m1
parameter_list|,
name|m2
parameter_list|)
value|((m1) == (m2))
end_define

begin_comment
comment|/*  * Argument structure for DVMRP_ADD_VIF.  * (DVMRP_DEL_VIF takes a single vifi_t argument.)  */
end_comment

begin_struct
struct|struct
name|vifctl
block|{
name|vifi_t
name|vifc_vifi
decl_stmt|;
comment|/* the index of the vif to be added */
name|u_char
name|vifc_flags
decl_stmt|;
comment|/* VIFF_ flags defined below */
name|u_char
name|vifc_threshold
decl_stmt|;
comment|/* min ttl required to forward on vif */
name|u_int
name|vifc_rate_limit
decl_stmt|;
comment|/* max tate */
name|struct
name|in_addr
name|vifc_lcl_addr
decl_stmt|;
comment|/* local interface address */
name|struct
name|in_addr
name|vifc_rmt_addr
decl_stmt|;
comment|/* remote address (tunnels only) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIFF_TUNNEL
value|0x1
end_define

begin_comment
comment|/* vif represents a tunnel end-point */
end_comment

begin_define
define|#
directive|define
name|VIFF_SRCRT
value|0x2
end_define

begin_comment
comment|/* tunnel uses IP source routing */
end_comment

begin_comment
comment|/*  * Argument structure for DVMRP_ADD_MFC  * (mfcc_tos to be added at a future point)  */
end_comment

begin_struct
struct|struct
name|mfcctl
block|{
name|struct
name|in_addr
name|mfcc_origin
decl_stmt|;
comment|/* subnet origin of mcasts   */
name|struct
name|in_addr
name|mfcc_mcastgrp
decl_stmt|;
comment|/* multicast group associated*/
name|struct
name|in_addr
name|mfcc_originmask
decl_stmt|;
comment|/* subnet mask for origin    */
name|vifi_t
name|mfcc_parent
decl_stmt|;
comment|/* incoming vif              */
name|u_char
name|mfcc_ttls
index|[
name|MAXVIFS
index|]
decl_stmt|;
comment|/* forwarding ttls on vifs   */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument structure for DVMRP_DEL_MFC  */
end_comment

begin_struct
struct|struct
name|delmfcctl
block|{
name|struct
name|in_addr
name|mfcc_origin
decl_stmt|;
comment|/* subnet origin of multicasts      */
name|struct
name|in_addr
name|mfcc_mcastgrp
decl_stmt|;
comment|/* multicast group assoc. w/ origin */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument structure used by RSVP daemon to get vif information  */
end_comment

begin_struct
struct|struct
name|vif_req
block|{
name|u_char
name|v_flags
decl_stmt|;
comment|/* VIFF_ flags defined above           */
name|u_char
name|v_threshold
decl_stmt|;
comment|/* min ttl required to forward on vif  */
name|struct
name|in_addr
name|v_lcl_addr
decl_stmt|;
comment|/* local interface address             */
name|struct
name|in_addr
name|v_rmt_addr
decl_stmt|;
name|char
name|v_if_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vif_conf
block|{
name|u_int
name|vifc_len
decl_stmt|;
name|u_int
name|vifc_num
decl_stmt|;
name|struct
name|vif_req
modifier|*
name|vifc_req
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The kernel's multicast routing statistics.  */
end_comment

begin_struct
struct|struct
name|mrtstat
block|{
name|u_long
name|mrts_mfc_lookups
decl_stmt|;
comment|/* # forw. cache hash table hits   */
name|u_long
name|mrts_mfc_misses
decl_stmt|;
comment|/* # forw. cache hash table misses */
name|u_long
name|mrts_upcalls
decl_stmt|;
comment|/* # calls to mrouted              */
name|u_long
name|mrts_no_route
decl_stmt|;
comment|/* no route for packet's origin    */
name|u_long
name|mrts_bad_tunnel
decl_stmt|;
comment|/* malformed tunnel options        */
name|u_long
name|mrts_cant_tunnel
decl_stmt|;
comment|/* no room for tunnel options      */
name|u_long
name|mrts_wrong_if
decl_stmt|;
comment|/* arrived on wrong interface	   */
name|u_long
name|mrts_upq_ovflw
decl_stmt|;
comment|/* upcall Q overflow		   */
name|u_long
name|mrts_cache_cleanups
decl_stmt|;
comment|/* # entries with no upcalls 	   */
name|u_long
name|mrts_drop_sel
decl_stmt|;
comment|/* pkts dropped selectively        */
name|u_long
name|mrts_q_overflow
decl_stmt|;
comment|/* pkts dropped - Q overflow       */
name|u_long
name|mrts_pkt2large
decl_stmt|;
comment|/* pkts dropped - size> BKT SIZE  */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument structure used by mrouted to get src-grp pkt counts  */
end_comment

begin_struct
struct|struct
name|sioc_sg_req
block|{
name|struct
name|in_addr
name|src
decl_stmt|;
name|struct
name|in_addr
name|grp
decl_stmt|;
name|u_long
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument structure used by mrouted to get vif pkt counts  */
end_comment

begin_struct
struct|struct
name|sioc_vif_req
block|{
name|vifi_t
name|vifi
decl_stmt|;
name|u_long
name|icount
decl_stmt|;
name|u_long
name|ocount
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|vif
block|{
name|u_char
name|v_flags
decl_stmt|;
comment|/* VIFF_ flags defined above         */
name|u_char
name|v_threshold
decl_stmt|;
comment|/* min ttl required to forward on vif*/
name|u_int
name|v_rate_limit
decl_stmt|;
comment|/* max rate			     */
name|struct
name|tbf
modifier|*
name|v_tbf
decl_stmt|;
comment|/* token bucket structure at intf.   */
name|struct
name|in_addr
name|v_lcl_addr
decl_stmt|;
comment|/* local interface address           */
name|struct
name|in_addr
name|v_rmt_addr
decl_stmt|;
comment|/* remote address (tunnels only)     */
name|struct
name|ifnet
modifier|*
name|v_ifp
decl_stmt|;
comment|/* pointer to interface              */
name|u_long
name|v_pkt_in
decl_stmt|;
comment|/* # pkts in on interface            */
name|u_long
name|v_pkt_out
decl_stmt|;
comment|/* # pkts out on interface           */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The kernel's multicast forwarding cache entry structure   * (A field for the type of service (mfc_tos) is to be added   * at a future point)  */
end_comment

begin_struct
struct|struct
name|mfc
block|{
name|struct
name|in_addr
name|mfc_origin
decl_stmt|;
comment|/* subnet origin of mcasts   */
name|struct
name|in_addr
name|mfc_mcastgrp
decl_stmt|;
comment|/* multicast group associated*/
name|struct
name|in_addr
name|mfc_originmask
decl_stmt|;
comment|/* subnet mask for origin    */
name|vifi_t
name|mfc_parent
decl_stmt|;
comment|/* incoming vif              */
name|u_char
name|mfc_ttls
index|[
name|MAXVIFS
index|]
decl_stmt|;
comment|/* forwarding ttls on vifs   */
name|u_long
name|mfc_pkt_cnt
decl_stmt|;
comment|/* pkt count for src-grp     */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument structure used for pkt info. while upcall is made  */
end_comment

begin_struct
struct|struct
name|rtdetq
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|u_long
name|tunnel_src
decl_stmt|;
name|struct
name|ip_moptions
modifier|*
name|imo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MFCTBLSIZ
value|256
end_define

begin_if
if|#
directive|if
operator|(
name|MFCTBLSIZ
operator|&
operator|(
name|MFCTBLSIZ
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
name|MFCHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h)& (MFCTBLSIZ - 1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MFCHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h) % MFCTBLSIZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_UPQ
value|4
end_define

begin_comment
comment|/* max. no of pkts in upcall Q */
end_comment

begin_comment
comment|/*  * Token Bucket filter code   */
end_comment

begin_define
define|#
directive|define
name|MAX_BKT_SIZE
value|10000
end_define

begin_comment
comment|/* 10K bytes size 		*/
end_comment

begin_define
define|#
directive|define
name|MAXQSIZE
value|10
end_define

begin_comment
comment|/* max # of pkts in queue 	*/
end_comment

begin_comment
comment|/*  * queue structure at each vif  */
end_comment

begin_struct
struct|struct
name|pkt_queue
block|{
name|u_long
name|pkt_len
decl_stmt|;
comment|/* length of packet in queue 	*/
name|struct
name|mbuf
modifier|*
name|pkt_m
decl_stmt|;
comment|/* pointer to packet mbuf	*/
name|struct
name|ip
modifier|*
name|pkt_ip
decl_stmt|;
comment|/* pointer to ip header	*/
name|struct
name|ip_moptions
modifier|*
name|pkt_imo
decl_stmt|;
comment|/* IP multicast options assoc. with pkt */
block|}
struct|;
end_struct

begin_comment
comment|/*  * the token bucket filter at each vif  */
end_comment

begin_struct
struct|struct
name|tbf
block|{
name|u_long
name|last_pkt_t
decl_stmt|;
comment|/* arr. time of last pkt 	*/
name|u_long
name|n_tok
decl_stmt|;
comment|/* no of tokens in bucket 	*/
name|u_long
name|q_len
decl_stmt|;
comment|/* length of queue at this vif	*/
block|}
struct|;
end_struct

begin_extern
extern|extern int	(*ip_mrouter_cmd
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|socket
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int	(*ip_mrouter_done
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IP_MROUTE_H_ */
end_comment

end_unit

