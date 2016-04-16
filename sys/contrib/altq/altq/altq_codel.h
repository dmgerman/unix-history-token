begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CoDel - The Controlled-Delay Active Queue Management algorithm  *  *  Copyright (C) 2013 Ermal LuÃ§i<eri@FreeBSD.org>  *  Copyright (C) 2011-2012 Kathleen Nichols<nichols@pollere.com>  *  Copyright (C) 2011-2012 Van Jacobson<van@pollere.net>  *  Copyright (C) 2012 Michael D. Taht<dave.taht@bufferbloat.net>  *  Copyright (C) 2012 Eric Dumazet<edumazet@google.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, provided that this notice is retained in full, this  * software may be distributed under the terms of the GNU General  * Public License ("GPL") version 2, in which case the provisions of the  * GPL apply INSTEAD OF those given above.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_CODEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_CODEL_H_
end_define

begin_struct
struct|struct
name|codel_stats
block|{
name|u_int32_t
name|maxpacket
decl_stmt|;
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
name|u_int
name|marked_packets
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|codel_ifstats
block|{
name|u_int
name|qlength
decl_stmt|;
name|u_int
name|qlimit
decl_stmt|;
name|struct
name|codel_stats
name|stats
decl_stmt|;
name|struct
name|pktcntr
name|cl_xmitcnt
decl_stmt|;
comment|/* transmitted packet counter */
name|struct
name|pktcntr
name|cl_dropcnt
decl_stmt|;
comment|/* dropped packet counter */
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
file|<altq/altq_classq.h>
end_include

begin_comment
comment|/**  * struct codel_params - contains codel parameters  *<at> target:	target queue size (in time units)  *<at> interval:	width of moving time window  *<at> ecn:	is Explicit Congestion Notification enabled  */
end_comment

begin_struct
struct|struct
name|codel_params
block|{
name|u_int64_t
name|target
decl_stmt|;
name|u_int64_t
name|interval
decl_stmt|;
name|int
name|ecn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct codel_vars - contains codel variables  *<at> count:		how many drops we've done since the last time we  *			entered dropping state  *<at> lastcount:	count at entry to dropping state  *<at> dropping:	set to true if in dropping state  *<at> rec_inv_sqrt:	reciprocal value of sqrt(count)>> 1  *<at> first_above_time:	when we went (or will go) continuously above  *				target for interval  *<at> drop_next:	time to drop next packet, or when we dropped last  *<at> ldelay:	sojourn time of last dequeued packet  */
end_comment

begin_struct
struct|struct
name|codel_vars
block|{
name|u_int32_t
name|count
decl_stmt|;
name|u_int32_t
name|lastcount
decl_stmt|;
name|int
name|dropping
decl_stmt|;
name|u_int16_t
name|rec_inv_sqrt
decl_stmt|;
name|u_int64_t
name|first_above_time
decl_stmt|;
name|u_int64_t
name|drop_next
decl_stmt|;
name|u_int64_t
name|ldelay
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|codel
block|{
name|int
name|last_pps
decl_stmt|;
name|struct
name|codel_params
name|params
decl_stmt|;
name|struct
name|codel_vars
name|vars
decl_stmt|;
name|struct
name|codel_stats
name|stats
decl_stmt|;
name|struct
name|timeval
name|last_log
decl_stmt|;
name|u_int32_t
name|drop_overlimit
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * codel interface state  */
end_comment

begin_struct
struct|struct
name|codel_if
block|{
name|struct
name|codel_if
modifier|*
name|cif_next
decl_stmt|;
comment|/* interface state list */
name|struct
name|ifaltq
modifier|*
name|cif_ifq
decl_stmt|;
comment|/* backpointer to ifaltq */
name|u_int
name|cif_bandwidth
decl_stmt|;
comment|/* link bandwidth in bps */
name|class_queue_t
modifier|*
name|cl_q
decl_stmt|;
comment|/* class queue structure */
name|struct
name|codel
name|codel
decl_stmt|;
comment|/* statistics */
name|struct
name|codel_ifstats
name|cl_stats
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|codel
modifier|*
name|codel_alloc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|codel_destroy
parameter_list|(
name|struct
name|codel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|codel_addq
parameter_list|(
name|struct
name|codel
modifier|*
parameter_list|,
name|class_queue_t
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|codel_getq
parameter_list|(
name|struct
name|codel
modifier|*
parameter_list|,
name|class_queue_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|codel_getstats
parameter_list|(
name|struct
name|codel
modifier|*
parameter_list|,
name|struct
name|codel_stats
modifier|*
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
comment|/* _ALTQ_ALTQ_CODEL_H_ */
end_comment

end_unit

