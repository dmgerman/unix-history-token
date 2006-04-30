begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: altq_red.h,v 1.8 2003/07/10 12:07:49 kjc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1997-2003  *	Sony Computer Science Laboratories Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY SONY CSL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL SONY CSL OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_RED_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_RED_H_
end_define

begin_include
include|#
directive|include
file|<altq/altq_classq.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_struct
struct|struct
name|red_interface
block|{
name|char
name|red_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|red_stats
block|{
name|struct
name|red_interface
name|iface
decl_stmt|;
name|int
name|q_len
decl_stmt|;
name|int
name|q_avg
decl_stmt|;
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
name|u_int
name|drop_forced
decl_stmt|;
name|u_int
name|drop_unforced
decl_stmt|;
name|u_int
name|marked_packets
decl_stmt|;
comment|/* static red parameters */
name|int
name|q_limit
decl_stmt|;
name|int
name|weight
decl_stmt|;
name|int
name|inv_pmax
decl_stmt|;
name|int
name|th_min
decl_stmt|;
name|int
name|th_max
decl_stmt|;
comment|/* flowvalve related stuff */
name|u_int
name|fv_flows
decl_stmt|;
name|u_int
name|fv_pass
decl_stmt|;
name|u_int
name|fv_predrop
decl_stmt|;
name|u_int
name|fv_alloc
decl_stmt|;
name|u_int
name|fv_escape
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|red_conf
block|{
name|struct
name|red_interface
name|iface
decl_stmt|;
name|int
name|red_weight
decl_stmt|;
comment|/* weight for EWMA */
name|int
name|red_inv_pmax
decl_stmt|;
comment|/* inverse of max drop probability */
name|int
name|red_thmin
decl_stmt|;
comment|/* red min threshold */
name|int
name|red_thmax
decl_stmt|;
comment|/* red max threshold */
name|int
name|red_limit
decl_stmt|;
comment|/* max queue length */
name|int
name|red_pkttime
decl_stmt|;
comment|/* average packet time in usec */
name|int
name|red_flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_COMPAT */
end_comment

begin_comment
comment|/* red flags */
end_comment

begin_define
define|#
directive|define
name|REDF_ECN4
value|0x01
end_define

begin_comment
comment|/* use packet marking for IPv4 packets */
end_comment

begin_define
define|#
directive|define
name|REDF_ECN6
value|0x02
end_define

begin_comment
comment|/* use packet marking for IPv6 packets */
end_comment

begin_define
define|#
directive|define
name|REDF_ECN
value|(REDF_ECN4 | REDF_ECN6)
end_define

begin_define
define|#
directive|define
name|REDF_FLOWVALVE
value|0x04
end_define

begin_comment
comment|/* use flowvalve (aka penalty-box) */
end_comment

begin_comment
comment|/*  * simpler versions of red parameters and statistics used by other  * disciplines (e.g., CBQ)  */
end_comment

begin_struct
struct|struct
name|redparams
block|{
name|int
name|th_min
decl_stmt|;
comment|/* red min threshold */
name|int
name|th_max
decl_stmt|;
comment|/* red max threshold */
name|int
name|inv_pmax
decl_stmt|;
comment|/* inverse of max drop probability */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|redstats
block|{
name|int
name|q_avg
decl_stmt|;
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
name|u_int
name|drop_forced
decl_stmt|;
name|u_int
name|drop_unforced
decl_stmt|;
name|u_int
name|marked_packets
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_comment
comment|/*  * IOCTLs for RED  */
end_comment

begin_define
define|#
directive|define
name|RED_IF_ATTACH
value|_IOW('Q', 1, struct red_interface)
end_define

begin_define
define|#
directive|define
name|RED_IF_DETACH
value|_IOW('Q', 2, struct red_interface)
end_define

begin_define
define|#
directive|define
name|RED_ENABLE
value|_IOW('Q', 3, struct red_interface)
end_define

begin_define
define|#
directive|define
name|RED_DISABLE
value|_IOW('Q', 4, struct red_interface)
end_define

begin_define
define|#
directive|define
name|RED_CONFIG
value|_IOWR('Q', 6, struct red_conf)
end_define

begin_define
define|#
directive|define
name|RED_GETSTATS
value|_IOWR('Q', 12, struct red_stats)
end_define

begin_define
define|#
directive|define
name|RED_SETDEFAULTS
value|_IOW('Q', 30, struct redparams)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_COMPAT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_struct_decl
struct_decl|struct
name|flowvalve
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* weight table structure for idle time calibration */
end_comment

begin_struct
struct|struct
name|wtab
block|{
name|struct
name|wtab
modifier|*
name|w_next
decl_stmt|;
name|int
name|w_weight
decl_stmt|;
name|int
name|w_param_max
decl_stmt|;
name|int
name|w_refcount
decl_stmt|;
name|int32_t
name|w_tab
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|red
block|{
name|int
name|red_pkttime
decl_stmt|;
comment|/* average packet time in micro sec 					   used for idle calibration */
name|int
name|red_flags
decl_stmt|;
comment|/* red flags */
comment|/* red parameters */
name|int
name|red_weight
decl_stmt|;
comment|/* weight for EWMA */
name|int
name|red_inv_pmax
decl_stmt|;
comment|/* inverse of max drop probability */
name|int
name|red_thmin
decl_stmt|;
comment|/* red min threshold */
name|int
name|red_thmax
decl_stmt|;
comment|/* red max threshold */
comment|/* variables for internal use */
name|int
name|red_wshift
decl_stmt|;
comment|/* log(red_weight) */
name|int
name|red_thmin_s
decl_stmt|;
comment|/* th_min scaled by avgshift */
name|int
name|red_thmax_s
decl_stmt|;
comment|/* th_max scaled by avgshift */
name|int
name|red_probd
decl_stmt|;
comment|/* drop probability denominator */
name|int
name|red_avg
decl_stmt|;
comment|/* queue len avg scaled by avgshift */
name|int
name|red_count
decl_stmt|;
comment|/* packet count since last dropped/ 					   marked packet */
name|int
name|red_idle
decl_stmt|;
comment|/* queue was empty */
name|int
name|red_old
decl_stmt|;
comment|/* avg is above th_min */
name|struct
name|wtab
modifier|*
name|red_wtab
decl_stmt|;
comment|/* weight table */
name|struct
name|timeval
name|red_last
decl_stmt|;
comment|/* time when the queue becomes idle */
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
name|struct
name|flowvalve
modifier|*
name|red_flowvalve
decl_stmt|;
comment|/* flowvalve state */
endif|#
directive|endif
struct|struct
block|{
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
name|u_int
name|drop_forced
decl_stmt|;
name|u_int
name|drop_unforced
decl_stmt|;
name|u_int
name|marked_packets
decl_stmt|;
block|}
name|red_stats
struct|;
block|}
name|red_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|red_queue
block|{
name|struct
name|red_queue
modifier|*
name|rq_next
decl_stmt|;
comment|/* next red_state in the list */
name|struct
name|ifaltq
modifier|*
name|rq_ifq
decl_stmt|;
comment|/* backpointer to ifaltq */
name|class_queue_t
modifier|*
name|rq_q
decl_stmt|;
name|red_t
modifier|*
name|rq_red
decl_stmt|;
block|}
name|red_queue_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_COMPAT */
end_comment

begin_comment
comment|/* red drop types */
end_comment

begin_define
define|#
directive|define
name|DTYPE_NODROP
value|0
end_define

begin_comment
comment|/* no drop */
end_comment

begin_define
define|#
directive|define
name|DTYPE_FORCED
value|1
end_define

begin_comment
comment|/* a "forced" drop */
end_comment

begin_define
define|#
directive|define
name|DTYPE_EARLY
value|2
end_define

begin_comment
comment|/* an "unforced" (early) drop */
end_comment

begin_function_decl
specifier|extern
name|red_t
modifier|*
name|red_alloc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|red_destroy
parameter_list|(
name|red_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|red_getstats
parameter_list|(
name|red_t
modifier|*
parameter_list|,
name|struct
name|redstats
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|red_addq
parameter_list|(
name|red_t
modifier|*
parameter_list|,
name|class_queue_t
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|altq_pktattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|red_getq
parameter_list|(
name|red_t
modifier|*
parameter_list|,
name|class_queue_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drop_early
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
specifier|extern
name|int
name|mark_ecn
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|altq_pktattr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|wtab
modifier|*
name|wtab_alloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|wtab_destroy
parameter_list|(
name|struct
name|wtab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|pow_w
parameter_list|(
name|struct
name|wtab
modifier|*
parameter_list|,
name|int
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
comment|/* _ALTQ_ALTQ_RED_H_ */
end_comment

end_unit

