begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989 Stephen Deering.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ip_mroute.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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
comment|/*  * Definitions for IP multicast forwarding.  *  * Written by David Waitzman, BBN Labs, August 1988.  * Modified by Steve Deering, Stanford, February 1989.  * Modified by Ajit Thyagarajan, PARC, August 1993.  * Modified by Ajit Thyagarajan, PARC, August 1994.  * Modified by Ahmed Helmy, SGI, June 1996.  * Modified by Pavlin Radoslavov, ICSI, October 2002.  *  * MROUTING Revision: 3.3.1.3  * and PIM-SMv2 and PIM-DM support, advanced API support,  * bandwidth metering and signaling.  */
end_comment

begin_comment
comment|/*  * Multicast Routing set/getsockopt commands.  */
end_comment

begin_define
define|#
directive|define
name|MRT_INIT
value|100
end_define

begin_comment
comment|/* initialize forwarder */
end_comment

begin_define
define|#
directive|define
name|MRT_DONE
value|101
end_define

begin_comment
comment|/* shut down forwarder */
end_comment

begin_define
define|#
directive|define
name|MRT_ADD_VIF
value|102
end_define

begin_comment
comment|/* create virtual interface */
end_comment

begin_define
define|#
directive|define
name|MRT_DEL_VIF
value|103
end_define

begin_comment
comment|/* delete virtual interface */
end_comment

begin_define
define|#
directive|define
name|MRT_ADD_MFC
value|104
end_define

begin_comment
comment|/* insert forwarding cache entry */
end_comment

begin_define
define|#
directive|define
name|MRT_DEL_MFC
value|105
end_define

begin_comment
comment|/* delete forwarding cache entry */
end_comment

begin_define
define|#
directive|define
name|MRT_VERSION
value|106
end_define

begin_comment
comment|/* get kernel version number */
end_comment

begin_define
define|#
directive|define
name|MRT_ASSERT
value|107
end_define

begin_comment
comment|/* enable assert processing */
end_comment

begin_define
define|#
directive|define
name|MRT_PIM
value|MRT_ASSERT
end_define

begin_comment
comment|/* enable PIM processing */
end_comment

begin_define
define|#
directive|define
name|MRT_API_SUPPORT
value|109
end_define

begin_comment
comment|/* supported MRT API */
end_comment

begin_define
define|#
directive|define
name|MRT_API_CONFIG
value|110
end_define

begin_comment
comment|/* config MRT API */
end_comment

begin_define
define|#
directive|define
name|MRT_ADD_BW_UPCALL
value|111
end_define

begin_comment
comment|/* create bandwidth monitor */
end_comment

begin_define
define|#
directive|define
name|MRT_DEL_BW_UPCALL
value|112
end_define

begin_comment
comment|/* delete bandwidth monitor */
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
name|ALL_VIFS
value|(vifi_t)-1
end_define

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
comment|/*  * Argument structure for MRT_ADD_VIF.  * (MRT_DEL_VIF takes a single vifi_t argument.)  */
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
comment|/* max rate */
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
comment|/* no-op; retained for old source */
end_comment

begin_define
define|#
directive|define
name|VIFF_SRCRT
value|0x2
end_define

begin_comment
comment|/* no-op; retained for old source */
end_comment

begin_define
define|#
directive|define
name|VIFF_REGISTER
value|0x4
end_define

begin_comment
comment|/* used for PIM Register encap/decap */
end_comment

begin_comment
comment|/*  * Argument structure for MRT_ADD_MFC and MRT_DEL_MFC  * XXX if you change this, make sure to change struct mfcctl2 as well.  */
end_comment

begin_struct
struct|struct
name|mfcctl
block|{
name|struct
name|in_addr
name|mfcc_origin
decl_stmt|;
comment|/* ip origin of mcasts       */
name|struct
name|in_addr
name|mfcc_mcastgrp
decl_stmt|;
comment|/* multicast group associated*/
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
comment|/*  * The new argument structure for MRT_ADD_MFC and MRT_DEL_MFC overlays  * and extends the old struct mfcctl.  */
end_comment

begin_struct
struct|struct
name|mfcctl2
block|{
comment|/* the mfcctl fields */
name|struct
name|in_addr
name|mfcc_origin
decl_stmt|;
comment|/* ip origin of mcasts	     */
name|struct
name|in_addr
name|mfcc_mcastgrp
decl_stmt|;
comment|/* multicast group associated*/
name|vifi_t
name|mfcc_parent
decl_stmt|;
comment|/* incoming vif		     */
name|u_char
name|mfcc_ttls
index|[
name|MAXVIFS
index|]
decl_stmt|;
comment|/* forwarding ttls on vifs   */
comment|/* extension fields */
name|uint8_t
name|mfcc_flags
index|[
name|MAXVIFS
index|]
decl_stmt|;
comment|/* the MRT_MFC_FLAGS_* flags */
name|struct
name|in_addr
name|mfcc_rp
decl_stmt|;
comment|/* the RP address            */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The advanced-API flags.  *  * The MRT_MFC_FLAGS_XXX API flags are also used as flags  * for the mfcc_flags field.  */
end_comment

begin_define
define|#
directive|define
name|MRT_MFC_FLAGS_DISABLE_WRONGVIF
value|(1<< 0)
end_define

begin_comment
comment|/* disable WRONGVIF signals */
end_comment

begin_define
define|#
directive|define
name|MRT_MFC_FLAGS_BORDER_VIF
value|(1<< 1)
end_define

begin_comment
comment|/* border vif		     */
end_comment

begin_define
define|#
directive|define
name|MRT_MFC_RP
value|(1<< 8)
end_define

begin_comment
comment|/* enable RP address	     */
end_comment

begin_define
define|#
directive|define
name|MRT_MFC_BW_UPCALL
value|(1<< 9)
end_define

begin_comment
comment|/* enable bw upcalls	     */
end_comment

begin_define
define|#
directive|define
name|MRT_MFC_FLAGS_ALL
value|(MRT_MFC_FLAGS_DISABLE_WRONGVIF |    \ 					 MRT_MFC_FLAGS_BORDER_VIF)
end_define

begin_define
define|#
directive|define
name|MRT_API_FLAGS_ALL
value|(MRT_MFC_FLAGS_ALL |		     \ 					 MRT_MFC_RP |			     \ 					 MRT_MFC_BW_UPCALL)
end_define

begin_comment
comment|/*  * Structure for installing or delivering an upcall if the  * measured bandwidth is above or below a threshold.  *  * User programs (e.g. daemons) may have a need to know when the  * bandwidth used by some data flow is above or below some threshold.  * This interface allows the userland to specify the threshold (in  * bytes and/or packets) and the measurement interval. Flows are  * all packet with the same source and destination IP address.  * At the moment the code is only used for multicast destinations  * but there is nothing that prevents its use for unicast.  *  * The measurement interval cannot be shorter than some Tmin (currently, 3s).  * The threshold is set in packets and/or bytes per_interval.  *  * Measurement works as follows:  *  * For>= measurements:  * The first packet marks the start of a measurement interval.  * During an interval we count packets and bytes, and when we  * pass the threshold we deliver an upcall and we are done.  * The first packet after the end of the interval resets the  * count and restarts the measurement.  *  * For<= measurement:  * We start a timer to fire at the end of the interval, and  * then for each incoming packet we count packets and bytes.  * When the timer fires, we compare the value with the threshold,  * schedule an upcall if we are below, and restart the measurement  * (reschedule timer and zero counters).  */
end_comment

begin_struct
struct|struct
name|bw_data
block|{
name|struct
name|timeval
name|b_time
decl_stmt|;
name|uint64_t
name|b_packets
decl_stmt|;
name|uint64_t
name|b_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bw_upcall
block|{
name|struct
name|in_addr
name|bu_src
decl_stmt|;
comment|/* source address            */
name|struct
name|in_addr
name|bu_dst
decl_stmt|;
comment|/* destination address       */
name|uint32_t
name|bu_flags
decl_stmt|;
comment|/* misc flags (see below)    */
define|#
directive|define
name|BW_UPCALL_UNIT_PACKETS
value|(1<< 0)
comment|/* threshold (in packets)    */
define|#
directive|define
name|BW_UPCALL_UNIT_BYTES
value|(1<< 1)
comment|/* threshold (in bytes)      */
define|#
directive|define
name|BW_UPCALL_GEQ
value|(1<< 2)
comment|/* upcall if bw>= threshold */
define|#
directive|define
name|BW_UPCALL_LEQ
value|(1<< 3)
comment|/* upcall if bw<= threshold */
define|#
directive|define
name|BW_UPCALL_DELETE_ALL
value|(1<< 4)
comment|/* delete all upcalls for s,d*/
name|struct
name|bw_data
name|bu_threshold
decl_stmt|;
comment|/* the bw threshold	     */
name|struct
name|bw_data
name|bu_measured
decl_stmt|;
comment|/* the measured bw	     */
block|}
struct|;
end_struct

begin_comment
comment|/* max. number of upcalls to deliver together */
end_comment

begin_define
define|#
directive|define
name|BW_UPCALLS_MAX
value|128
end_define

begin_comment
comment|/* min. threshold time interval for bandwidth measurement */
end_comment

begin_define
define|#
directive|define
name|BW_UPCALL_THRESHOLD_INTERVAL_MIN_SEC
value|3
end_define

begin_define
define|#
directive|define
name|BW_UPCALL_THRESHOLD_INTERVAL_MIN_USEC
value|0
end_define

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
comment|/* # calls to multicast routing daemon */
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
comment|/* # entries with no upcalls	   */
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
name|u_long
name|mrts_upq_sockfull
decl_stmt|;
comment|/* upcalls dropped - socket full */
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
name|pktcnt
decl_stmt|;
name|u_long
name|bytecnt
decl_stmt|;
name|u_long
name|wrong_if
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
comment|/* vif number				*/
name|u_long
name|icount
decl_stmt|;
comment|/* Input packet count on vif		*/
name|u_long
name|ocount
decl_stmt|;
comment|/* Output packet count on vif		*/
name|u_long
name|ibytes
decl_stmt|;
comment|/* Input byte count on vif		*/
name|u_long
name|obytes
decl_stmt|;
comment|/* Output byte count on vif		*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * The kernel's virtual-interface structure.  */
end_comment

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
comment|/* ignored; kept for compatibility */
name|struct
name|tbf
modifier|*
name|v_tbf
decl_stmt|;
comment|/* ignored; kept for compatibility */
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
name|u_long
name|v_bytes_in
decl_stmt|;
comment|/* # bytes in on interface	     */
name|u_long
name|v_bytes_out
decl_stmt|;
comment|/* # bytes out on interface	     */
name|struct
name|route
name|v_route
decl_stmt|;
comment|/* cached route */
name|u_int
name|v_rsvp_on
decl_stmt|;
comment|/* RSVP listening on this vif */
name|struct
name|socket
modifier|*
name|v_rsvpd
decl_stmt|;
comment|/* RSVP daemon socket */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The kernel's multicast forwarding cache entry structure  * (A field for the type of service (mfc_tos) is to be added  * at a future point)  */
end_comment

begin_struct
struct|struct
name|mfc
block|{
name|struct
name|in_addr
name|mfc_origin
decl_stmt|;
comment|/* IP origin of mcasts	     */
name|struct
name|in_addr
name|mfc_mcastgrp
decl_stmt|;
comment|/* multicast group associated*/
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
name|u_long
name|mfc_byte_cnt
decl_stmt|;
comment|/* byte count for src-grp    */
name|u_long
name|mfc_wrong_if
decl_stmt|;
comment|/* wrong if for src-grp	     */
name|int
name|mfc_expire
decl_stmt|;
comment|/* time to clean entry up    */
name|struct
name|timeval
name|mfc_last_assert
decl_stmt|;
comment|/* last time I sent an assert*/
name|struct
name|rtdetq
modifier|*
name|mfc_stall
decl_stmt|;
comment|/* q of packets awaiting mfc */
name|struct
name|mfc
modifier|*
name|mfc_next
decl_stmt|;
comment|/* next mfc entry            */
name|uint8_t
name|mfc_flags
index|[
name|MAXVIFS
index|]
decl_stmt|;
comment|/* the MRT_MFC_FLAGS_* flags */
name|struct
name|in_addr
name|mfc_rp
decl_stmt|;
comment|/* the RP address	     */
name|struct
name|bw_meter
modifier|*
name|mfc_bw_meter
decl_stmt|;
comment|/* list of bandwidth meters  */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Struct used to communicate from kernel to multicast router  * note the convenient similarity to an IP packet  */
end_comment

begin_struct
struct|struct
name|igmpmsg
block|{
name|uint32_t
name|unused1
decl_stmt|;
name|uint32_t
name|unused2
decl_stmt|;
name|u_char
name|im_msgtype
decl_stmt|;
comment|/* what type of message	    */
define|#
directive|define
name|IGMPMSG_NOCACHE
value|1
comment|/* no MFC in the kernel		    */
define|#
directive|define
name|IGMPMSG_WRONGVIF
value|2
comment|/* packet came from wrong interface */
define|#
directive|define
name|IGMPMSG_WHOLEPKT
value|3
comment|/* PIM pkt for user level encap.    */
define|#
directive|define
name|IGMPMSG_BW_UPCALL
value|4
comment|/* BW monitoring upcall		    */
name|u_char
name|im_mbz
decl_stmt|;
comment|/* must be zero		    */
name|u_char
name|im_vif
decl_stmt|;
comment|/* vif rec'd on		    */
name|u_char
name|unused3
decl_stmt|;
name|struct
name|in_addr
name|im_src
decl_stmt|,
name|im_dst
decl_stmt|;
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
comment|/* A copy of the packet		    */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* Interface pkt came in on	    */
name|vifi_t
name|xmt_vif
decl_stmt|;
comment|/* Saved copy of imo_multicast_vif  */
name|struct
name|rtdetq
modifier|*
name|next
decl_stmt|;
comment|/* Next in list of packets          */
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
comment|/*  * Structure for measuring the bandwidth and sending an upcall if the  * measured bandwidth is above or below a threshold.  */
end_comment

begin_struct
struct|struct
name|bw_meter
block|{
name|struct
name|bw_meter
modifier|*
name|bm_mfc_next
decl_stmt|;
comment|/* next bw meter (same mfc)  */
name|struct
name|bw_meter
modifier|*
name|bm_time_next
decl_stmt|;
comment|/* next bw meter (same time) */
name|uint32_t
name|bm_time_hash
decl_stmt|;
comment|/* the time hash value       */
name|struct
name|mfc
modifier|*
name|bm_mfc
decl_stmt|;
comment|/* the corresponding mfc     */
name|uint32_t
name|bm_flags
decl_stmt|;
comment|/* misc flags (see below)    */
define|#
directive|define
name|BW_METER_UNIT_PACKETS
value|(1<< 0)
comment|/* threshold (in packets)    */
define|#
directive|define
name|BW_METER_UNIT_BYTES
value|(1<< 1)
comment|/* threshold (in bytes)      */
define|#
directive|define
name|BW_METER_GEQ
value|(1<< 2)
comment|/* upcall if bw>= threshold */
define|#
directive|define
name|BW_METER_LEQ
value|(1<< 3)
comment|/* upcall if bw<= threshold */
define|#
directive|define
name|BW_METER_USER_FLAGS
value|(BW_METER_UNIT_PACKETS |		\ 				 BW_METER_UNIT_BYTES |			\ 				 BW_METER_GEQ |				\ 				 BW_METER_LEQ)
define|#
directive|define
name|BW_METER_UPCALL_DELIVERED
value|(1<< 24)
comment|/* upcall was delivered      */
name|struct
name|bw_data
name|bm_threshold
decl_stmt|;
comment|/* the upcall threshold	     */
name|struct
name|bw_data
name|bm_measured
decl_stmt|;
comment|/* the measured bw	     */
name|struct
name|timeval
name|bm_start_time
decl_stmt|;
comment|/* abs. time		     */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip_mrouter_set
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip_mrouter_get
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip_mrouter_done
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
name|mrt_ioctl
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
comment|/* _NETINET_IP_MROUTE_H_ */
end_comment

end_unit

