begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Stephen Deering.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ip_mroute.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Definitions for the kernel part of DVMRP,  * a Distance-Vector Multicast Routing Protocol.  * (See RFC-1075.)  *  * Written by David Waitzman, BBN Labs, August 1988.  * Modified by Steve Deering, Stanford, February 1989.  *  * MROUTING 1.0  */
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

begin_define
define|#
directive|define
name|DVMRP_DONE
value|101
end_define

begin_define
define|#
directive|define
name|DVMRP_ADD_VIF
value|102
end_define

begin_define
define|#
directive|define
name|DVMRP_DEL_VIF
value|103
end_define

begin_define
define|#
directive|define
name|DVMRP_ADD_LGRP
value|104
end_define

begin_define
define|#
directive|define
name|DVMRP_DEL_LGRP
value|105
end_define

begin_define
define|#
directive|define
name|DVMRP_ADD_MRT
value|106
end_define

begin_define
define|#
directive|define
name|DVMRP_DEL_MRT
value|107
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
comment|/*  * Agument structure for DVMRP_ADD_VIF.  * (DVMRP_DEL_VIF takes a single vifi_t argument.)  */
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

begin_comment
comment|/*  * Argument structure for DVMRP_ADD_LGRP and DVMRP_DEL_LGRP.  */
end_comment

begin_struct
struct|struct
name|lgrplctl
block|{
name|vifi_t
name|lgc_vifi
decl_stmt|;
name|struct
name|in_addr
name|lgc_gaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument structure for DVMRP_ADD_MRT.  * (DVMRP_DEL_MRT takes a single struct in_addr argument, containing origin.)  */
end_comment

begin_struct
struct|struct
name|mrtctl
block|{
name|struct
name|in_addr
name|mrtc_origin
decl_stmt|;
comment|/* subnet origin of multicasts */
name|struct
name|in_addr
name|mrtc_originmask
decl_stmt|;
comment|/* subnet mask for origin */
name|vifi_t
name|mrtc_parent
decl_stmt|;
comment|/* incoming vif */
name|vifbitmap_t
name|mrtc_children
decl_stmt|;
comment|/* outgoing children vifs */
name|vifbitmap_t
name|mrtc_leaves
decl_stmt|;
comment|/* subset of outgoing children vifs */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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
comment|/* VIFF_ flags defined above */
name|u_char
name|v_threshold
decl_stmt|;
comment|/* min ttl required to forward on vif */
name|struct
name|in_addr
name|v_lcl_addr
decl_stmt|;
comment|/* local interface address */
name|struct
name|in_addr
name|v_rmt_addr
decl_stmt|;
comment|/* remote address (tunnels only) */
name|struct
name|ifnet
modifier|*
name|v_ifp
decl_stmt|;
comment|/* pointer to interface */
name|struct
name|in_addr
modifier|*
name|v_lcl_grps
decl_stmt|;
comment|/* list of local grps (phyints only) */
name|int
name|v_lcl_grps_max
decl_stmt|;
comment|/* malloc'ed number of v_lcl_grps */
name|int
name|v_lcl_grps_n
decl_stmt|;
comment|/* used number of v_lcl_grps */
name|u_long
name|v_cached_group
decl_stmt|;
comment|/* last grp looked-up (phyints only) */
name|int
name|v_cached_result
decl_stmt|;
comment|/* last look-up result (phyints only) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The kernel's multicast route structure.  */
end_comment

begin_struct
struct|struct
name|mrt
block|{
name|struct
name|in_addr
name|mrt_origin
decl_stmt|;
comment|/* subnet origin of multicasts */
name|struct
name|in_addr
name|mrt_originmask
decl_stmt|;
comment|/* subnet mask for origin */
name|vifi_t
name|mrt_parent
decl_stmt|;
comment|/* incoming vif */
name|vifbitmap_t
name|mrt_children
decl_stmt|;
comment|/* outgoing children vifs */
name|vifbitmap_t
name|mrt_leaves
decl_stmt|;
comment|/* subset of outgoing children vifs */
name|struct
name|mrt
modifier|*
name|mrt_next
decl_stmt|;
comment|/* forward link */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MRTHASHSIZ
value|64
end_define

begin_if
if|#
directive|if
operator|(
name|MRTHASHSIZ
operator|&
operator|(
name|MRTHASHSIZ
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
name|MRTHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h)& (MRTHASHSIZ - 1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MRTHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h) % MRTHASHSIZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The kernel's multicast routing statistics.  */
end_comment

begin_struct
struct|struct
name|mrtstat
block|{
name|u_long
name|mrts_mrt_lookups
decl_stmt|;
comment|/* # multicast route lookups */
name|u_long
name|mrts_mrt_misses
decl_stmt|;
comment|/* # multicast route cache misses */
name|u_long
name|mrts_grp_lookups
decl_stmt|;
comment|/* # group address lookups */
name|u_long
name|mrts_grp_misses
decl_stmt|;
comment|/* # group address cache misses */
name|u_long
name|mrts_no_route
decl_stmt|;
comment|/* no route for packet's origin */
name|u_long
name|mrts_bad_tunnel
decl_stmt|;
comment|/* malformed tunnel options */
name|u_long
name|mrts_cant_tunnel
decl_stmt|;
comment|/* no room for tunnel options */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|ip_mrouter_cmd
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip_mrouter_done
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

