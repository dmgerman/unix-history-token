begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Daniel Hartmeier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *    - Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    - Redistributions in binary form must reproduce the above  *      copyright notice, this list of conditions and the following  *      disclaimer in the documentation and/or other materials provided  *      with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	$OpenBSD: pfvar.h,v 1.282 2009/01/29 15:12:28 pyr Exp $  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_PF_ALTQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_PF_ALTQ_H_
end_define

begin_struct
struct|struct
name|cbq_opts
block|{
name|u_int
name|minburst
decl_stmt|;
name|u_int
name|maxburst
decl_stmt|;
name|u_int
name|pktsize
decl_stmt|;
name|u_int
name|maxpktsize
decl_stmt|;
name|u_int
name|ns_per_byte
decl_stmt|;
name|u_int
name|maxidle
decl_stmt|;
name|int
name|minidle
decl_stmt|;
name|u_int
name|offtime
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|priq_opts
block|{
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hfsc_opts
block|{
comment|/* real-time service curve */
name|u_int
name|rtsc_m1
decl_stmt|;
comment|/* slope of the 1st segment in bps */
name|u_int
name|rtsc_d
decl_stmt|;
comment|/* the x-projection of m1 in msec */
name|u_int
name|rtsc_m2
decl_stmt|;
comment|/* slope of the 2nd segment in bps */
comment|/* link-sharing service curve */
name|u_int
name|lssc_m1
decl_stmt|;
name|u_int
name|lssc_d
decl_stmt|;
name|u_int
name|lssc_m2
decl_stmt|;
comment|/* upper-limit service curve */
name|u_int
name|ulsc_m1
decl_stmt|;
name|u_int
name|ulsc_d
decl_stmt|;
name|u_int
name|ulsc_m2
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_altq
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|void
modifier|*
name|altq_disc
decl_stmt|;
comment|/* discipline-specific state */
name|TAILQ_ENTRY
argument_list|(
argument|pf_altq
argument_list|)
name|entries
expr_stmt|;
comment|/* scheduler spec */
name|uint8_t
name|scheduler
decl_stmt|;
comment|/* scheduler type */
name|uint16_t
name|tbrsize
decl_stmt|;
comment|/* tokenbucket regulator size */
name|uint32_t
name|ifbandwidth
decl_stmt|;
comment|/* interface bandwidth */
comment|/* queue spec */
name|char
name|qname
index|[
name|PF_QNAME_SIZE
index|]
decl_stmt|;
comment|/* queue name */
name|char
name|parent
index|[
name|PF_QNAME_SIZE
index|]
decl_stmt|;
comment|/* parent name */
name|uint32_t
name|parent_qid
decl_stmt|;
comment|/* parent queue id */
name|uint32_t
name|bandwidth
decl_stmt|;
comment|/* queue bandwidth */
name|uint8_t
name|priority
decl_stmt|;
comment|/* priority */
name|uint8_t
name|local_flags
decl_stmt|;
comment|/* dynamic interface */
define|#
directive|define
name|PFALTQ_FLAG_IF_REMOVED
value|0x01
name|uint16_t
name|qlimit
decl_stmt|;
comment|/* queue size limit */
name|uint16_t
name|flags
decl_stmt|;
comment|/* misc flags */
union|union
block|{
name|struct
name|cbq_opts
name|cbq_opts
decl_stmt|;
name|struct
name|priq_opts
name|priq_opts
decl_stmt|;
name|struct
name|hfsc_opts
name|hfsc_opts
decl_stmt|;
block|}
name|pq_u
union|;
name|uint32_t
name|qid
decl_stmt|;
comment|/* return value */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_PF_ALTQ_H_ */
end_comment

end_unit

