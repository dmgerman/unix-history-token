begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: in6_prefix.h,v 1.10 2001/02/08 16:30:30 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, 1998 and 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_struct
struct|struct
name|rr_prefix
block|{
name|struct
name|ifprefix
name|rp_ifpr
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|rr_prefix
argument_list|)
name|rp_entry
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument|rp_addrhead
argument_list|,
argument|rp_addr
argument_list|)
name|rp_addrhead
expr_stmt|;
name|struct
name|sockaddr_in6
name|rp_prefix
decl_stmt|;
comment|/* prefix */
name|u_int32_t
name|rp_vltime
decl_stmt|;
comment|/* advertised valid lifetime */
name|u_int32_t
name|rp_pltime
decl_stmt|;
comment|/* advertised preferred lifetime */
name|time_t
name|rp_expire
decl_stmt|;
comment|/* expiration time of the prefix */
name|time_t
name|rp_preferred
decl_stmt|;
comment|/* preferred time of the prefix */
name|struct
name|in6_prflags
name|rp_flags
decl_stmt|;
name|u_char
name|rp_origin
decl_stmt|;
comment|/* from where this prefix info is obtained */
struct|struct
name|rp_stateflags
block|{
comment|/* if some prefix should be added to this prefix */
name|u_char
name|addmark
range|:
literal|1
decl_stmt|;
name|u_char
name|delmark
range|:
literal|1
decl_stmt|;
comment|/* if this prefix will be deleted */
block|}
name|rp_stateflags
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rp_type
value|rp_ifpr.ifpr_type
end_define

begin_define
define|#
directive|define
name|rp_ifp
value|rp_ifpr.ifpr_ifp
end_define

begin_define
define|#
directive|define
name|rp_plen
value|rp_ifpr.ifpr_plen
end_define

begin_define
define|#
directive|define
name|rp_raf
value|rp_flags.prf_ra
end_define

begin_define
define|#
directive|define
name|rp_raf_onlink
value|rp_flags.prf_ra.onlink
end_define

begin_define
define|#
directive|define
name|rp_raf_auto
value|rp_flags.prf_ra.autonomous
end_define

begin_define
define|#
directive|define
name|rp_statef_addmark
value|rp_stateflags.addmark
end_define

begin_define
define|#
directive|define
name|rp_statef_delmark
value|rp_stateflags.delmark
end_define

begin_define
define|#
directive|define
name|rp_rrf
value|rp_flags.prf_rr
end_define

begin_define
define|#
directive|define
name|rp_rrf_decrvalid
value|rp_flags.prf_rr.decrvalid
end_define

begin_define
define|#
directive|define
name|rp_rrf_decrprefd
value|rp_flags.prf_rr.decrprefd
end_define

begin_struct
struct|struct
name|rp_addr
block|{
name|LIST_ENTRY
argument_list|(
argument|rp_addr
argument_list|)
name|ra_entry
expr_stmt|;
name|struct
name|in6_addr
name|ra_ifid
decl_stmt|;
name|struct
name|in6_ifaddr
modifier|*
name|ra_addr
decl_stmt|;
struct|struct
name|ra_flags
block|{
name|u_char
name|anycast
range|:
literal|1
decl_stmt|;
block|}
name|ra_flags
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ifpr2rp
parameter_list|(
name|ifpr
parameter_list|)
value|((struct rr_prefix *)(ifpr))
end_define

begin_define
define|#
directive|define
name|rp2ifpr
parameter_list|(
name|rp
parameter_list|)
value|((struct ifprefix *)(rp))
end_define

begin_define
define|#
directive|define
name|RP_IN6
parameter_list|(
name|rp
parameter_list|)
value|(&(rp)->rp_prefix.sin6_addr)
end_define

begin_define
define|#
directive|define
name|RR_INFINITE_LIFETIME
value|0xffffffff
end_define

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|rr_prhead
argument_list|,
name|rr_prefix
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rr_prhead
name|rr_prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in6_rr_timer
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|callout
name|in6_rr_timer_ch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|delete_each_prefix
name|__P
argument_list|(
operator|(
expr|struct
name|rr_prefix
operator|*
name|rpp
operator|,
name|u_char
name|origin
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

