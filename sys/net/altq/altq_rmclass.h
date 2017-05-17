begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991-1997 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the Network Research  *	Group at Lawrence Berkeley Laboratory.  * 4. Neither the name of the University nor of the Laboratory may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $KAME: altq_rmclass.h,v 1.10 2003/08/20 23:30:23 itojun Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_RMCLASS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_RMCLASS_H_
end_define

begin_include
include|#
directive|include
file|<net/altq/altq_classq.h>
end_include

begin_comment
comment|/* #pragma ident "@(#)rm_class.h  1.20     97/10/23 SMI" */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|RM_MAXPRIO
value|8
comment|/* Max priority */
ifdef|#
directive|ifdef
name|_KERNEL
typedef|typedef
name|struct
name|mbuf
name|mbuf_t
typedef|;
typedef|typedef
name|struct
name|rm_ifdat
name|rm_ifdat_t
typedef|;
typedef|typedef
name|struct
name|rm_class
name|rm_class_t
typedef|;
struct_decl|struct
name|red
struct_decl|;
comment|/*  * Macros for dealing with time values.  We assume all times are  * 'timevals'.  `microtime' is used to get the best available clock  * resolution.  If `microtime' *doesn't* return a value that's about  * ten times smaller than the average packet time on the fastest  * link that will use these routines, a slightly different clock  * scheme than this one should be used.  * (Bias due to truncation error in this scheme will overestimate utilization  * and discriminate against high bandwidth classes.  To remove this bias an  * integrator needs to be added.  The simplest integrator uses a history of  * 10 * avg.packet.time / min.tick.time packet completion entries.  This is  * straight forward to add but we don't want to pay the extra memory  * traffic to maintain it if it's not necessary (occasionally a vendor  * accidentally builds a workstation with a decent clock - e.g., Sun& HP).)  */
define|#
directive|define
name|RM_GETTIME
parameter_list|(
name|now
parameter_list|)
value|microtime(&now)
define|#
directive|define
name|TV_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)->tv_sec< (b)->tv_sec) ||  \ 	(((a)->tv_usec< (b)->tv_usec)&& ((a)->tv_sec<= (b)->tv_sec)))
define|#
directive|define
name|TV_DELTA
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|delta
parameter_list|)
value|{ \ 	int	xxs;	\ 							\ 	delta = (a)->tv_usec - (b)->tv_usec; \ 	if ((xxs = (a)->tv_sec - (b)->tv_sec)) { \ 		switch (xxs) { \ 		default: \
comment|/* if (xxs< 0) \ 				printf("rm_class: bogus time values\n"); */
value|\ 			delta = 0; \
comment|/* fall through */
value|\ 		case 2: \ 			delta += 1000000; \
comment|/* fall through */
value|\ 		case 1: \ 			delta += 1000000; \ 			break; \ 		} \ 	} \ }
define|#
directive|define
name|TV_ADD_DELTA
parameter_list|(
name|a
parameter_list|,
name|delta
parameter_list|,
name|res
parameter_list|)
value|{ \ 	int xxus = (a)->tv_usec + (delta); \ 	\ 	(res)->tv_sec = (a)->tv_sec; \ 	while (xxus>= 1000000) { \ 		++((res)->tv_sec); \ 		xxus -= 1000000; \ 	} \ 	(res)->tv_usec = xxus; \ }
define|#
directive|define
name|RM_TIMEOUT
value|2
comment|/* 1 Clock tick. */
if|#
directive|if
literal|1
define|#
directive|define
name|RM_MAXQUEUED
value|1
comment|/* this isn't used in ALTQ/CBQ */
else|#
directive|else
define|#
directive|define
name|RM_MAXQUEUED
value|16
comment|/* Max number of packets downstream of CBQ */
endif|#
directive|endif
define|#
directive|define
name|RM_MAXQUEUE
value|64
comment|/* Max queue length */
define|#
directive|define
name|RM_FILTER_GAIN
value|5
comment|/* log2 of gain, e.g., 5 => 31/32 */
define|#
directive|define
name|RM_POWER
value|(1<< RM_FILTER_GAIN)
define|#
directive|define
name|RM_MAXDEPTH
value|32
define|#
directive|define
name|RM_NS_PER_SEC
value|(1000000000)
typedef|typedef
struct|struct
name|_rm_class_stats_
block|{
name|u_int
name|handle
decl_stmt|;
name|u_int
name|depth
decl_stmt|;
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
comment|/* packets sent in this class */
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
comment|/* dropped packets */
name|u_int
name|over
decl_stmt|;
comment|/* # times went over limit */
name|u_int
name|borrows
decl_stmt|;
comment|/* # times tried to borrow */
name|u_int
name|overactions
decl_stmt|;
comment|/* # times invoked overlimit action */
name|u_int
name|delays
decl_stmt|;
comment|/* # times invoked delay actions */
block|}
name|rm_class_stats_t
typedef|;
comment|/*  * CBQ Class state structure  */
struct|struct
name|rm_class
block|{
name|class_queue_t
modifier|*
name|q_
decl_stmt|;
comment|/* Queue of packets */
name|rm_ifdat_t
modifier|*
name|ifdat_
decl_stmt|;
name|int
name|pri_
decl_stmt|;
comment|/* Class priority. */
name|int
name|depth_
decl_stmt|;
comment|/* Class depth */
name|u_int
name|ns_per_byte_
decl_stmt|;
comment|/* NanoSeconds per byte. */
name|u_int
name|maxrate_
decl_stmt|;
comment|/* Bytes per second for this class. */
name|u_int
name|allotment_
decl_stmt|;
comment|/* Fraction of link bandwidth. */
name|u_int
name|w_allotment_
decl_stmt|;
comment|/* Weighted allotment for WRR */
name|int
name|bytes_alloc_
decl_stmt|;
comment|/* Allocation for round of WRR */
name|int
name|avgidle_
decl_stmt|;
name|int
name|maxidle_
decl_stmt|;
name|int
name|minidle_
decl_stmt|;
name|int
name|offtime_
decl_stmt|;
name|int
name|sleeping_
decl_stmt|;
comment|/* != 0 if delaying */
name|int
name|qthresh_
decl_stmt|;
comment|/* Queue threshold for formal link sharing */
name|int
name|leaf_
decl_stmt|;
comment|/* Note whether leaf class or not.*/
name|rm_class_t
modifier|*
name|children_
decl_stmt|;
comment|/* Children of this class */
name|rm_class_t
modifier|*
name|next_
decl_stmt|;
comment|/* Next pointer, used if child */
name|rm_class_t
modifier|*
name|peer_
decl_stmt|;
comment|/* Peer class */
name|rm_class_t
modifier|*
name|borrow_
decl_stmt|;
comment|/* Borrow class */
name|rm_class_t
modifier|*
name|parent_
decl_stmt|;
comment|/* Parent class */
name|void
function_decl|(
modifier|*
name|overlimit
function_decl|)
parameter_list|(
name|struct
name|rm_class
modifier|*
parameter_list|,
name|struct
name|rm_class
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|drop
function_decl|)
parameter_list|(
name|struct
name|rm_class
modifier|*
parameter_list|)
function_decl|;
comment|/* Class drop action. */
union|union
block|{
name|struct
name|red
modifier|*
name|red_
decl_stmt|;
comment|/* RED state pointer */
name|struct
name|codel
modifier|*
name|codel_
decl_stmt|;
comment|/* codel state pointer */
block|}
name|cl_aqm_
union|;
define|#
directive|define
name|red_
value|cl_aqm_.red_
define|#
directive|define
name|codel_
value|cl_aqm_.codel_
name|struct
name|altq_pktattr
modifier|*
name|pktattr_
decl_stmt|;
comment|/* saved hdr used by RED/ECN */
name|int
name|flags_
decl_stmt|;
name|int
name|last_pkttime_
decl_stmt|;
comment|/* saved pkt_time */
name|struct
name|timeval
name|undertime_
decl_stmt|;
comment|/* time can next send */
name|struct
name|timeval
name|last_
decl_stmt|;
comment|/* time last packet sent */
name|struct
name|timeval
name|overtime_
decl_stmt|;
name|struct
name|callout
name|callout_
decl_stmt|;
comment|/* for timeout() calls */
name|rm_class_stats_t
name|stats_
decl_stmt|;
comment|/* Class Statistics */
block|}
struct|;
comment|/*  * CBQ Interface state  */
struct|struct
name|rm_ifdat
block|{
name|int
name|queued_
decl_stmt|;
comment|/* # pkts queued downstream */
name|int
name|efficient_
decl_stmt|;
comment|/* Link Efficiency bit */
name|int
name|wrr_
decl_stmt|;
comment|/* Enable Weighted Round-Robin */
name|u_long
name|ns_per_byte_
decl_stmt|;
comment|/* Link byte speed. */
name|int
name|maxqueued_
decl_stmt|;
comment|/* Max packets to queue */
name|int
name|maxpkt_
decl_stmt|;
comment|/* Max packet size. */
name|int
name|qi_
decl_stmt|;
comment|/* In/out pointers for downstream */
name|int
name|qo_
decl_stmt|;
comment|/* packets */
comment|/* 	 * Active class state and WRR state. 	 */
name|rm_class_t
modifier|*
name|active_
index|[
name|RM_MAXPRIO
index|]
decl_stmt|;
comment|/* Active cl's in each pri */
name|int
name|na_
index|[
name|RM_MAXPRIO
index|]
decl_stmt|;
comment|/* # of active cl's in a pri */
name|int
name|num_
index|[
name|RM_MAXPRIO
index|]
decl_stmt|;
comment|/* # of cl's per pri */
name|int
name|alloc_
index|[
name|RM_MAXPRIO
index|]
decl_stmt|;
comment|/* Byte Allocation */
name|u_long
name|M_
index|[
name|RM_MAXPRIO
index|]
decl_stmt|;
comment|/* WRR weights. */
comment|/* 	 * Network Interface/Solaris Queue state pointer. 	 */
name|struct
name|ifaltq
modifier|*
name|ifq_
decl_stmt|;
name|rm_class_t
modifier|*
name|default_
decl_stmt|;
comment|/* Default Pkt class, BE */
name|rm_class_t
modifier|*
name|root_
decl_stmt|;
comment|/* Root Link class. */
name|rm_class_t
modifier|*
name|ctl_
decl_stmt|;
comment|/* Control Traffic class. */
name|void
function_decl|(
modifier|*
name|restart
function_decl|)
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|)
function_decl|;
comment|/* Restart routine. */
comment|/* 	 * Current packet downstream packet state and dynamic state. 	 */
name|rm_class_t
modifier|*
name|borrowed_
index|[
name|RM_MAXQUEUED
index|]
decl_stmt|;
comment|/* Class borrowed last */
name|rm_class_t
modifier|*
name|class_
index|[
name|RM_MAXQUEUED
index|]
decl_stmt|;
comment|/* class sending */
name|int
name|curlen_
index|[
name|RM_MAXQUEUED
index|]
decl_stmt|;
comment|/* Current pktlen */
name|struct
name|timeval
name|now_
index|[
name|RM_MAXQUEUED
index|]
decl_stmt|;
comment|/* Current packet time. */
name|int
name|is_overlimit_
index|[
name|RM_MAXQUEUED
index|]
decl_stmt|;
comment|/* Current packet time. */
name|int
name|cutoff_
decl_stmt|;
comment|/* Cut-off depth for borrowing */
name|struct
name|timeval
name|ifnow_
decl_stmt|;
comment|/* expected xmit completion time */
if|#
directive|if
literal|1
comment|/* ALTQ4PPP */
name|int
name|maxiftime_
decl_stmt|;
comment|/* max delay inside interface */
endif|#
directive|endif
name|rm_class_t
modifier|*
name|pollcache_
decl_stmt|;
comment|/* cached rm_class by poll operation */
block|}
struct|;
comment|/* flags for rmc_init and rmc_newclass */
comment|/* class flags */
define|#
directive|define
name|RMCF_RED
value|0x0001
define|#
directive|define
name|RMCF_ECN
value|0x0002
define|#
directive|define
name|RMCF_RIO
value|0x0004
define|#
directive|define
name|RMCF_FLOWVALVE
value|0x0008
comment|/* use flowvalve (aka penalty-box) */
define|#
directive|define
name|RMCF_CLEARDSCP
value|0x0010
comment|/* clear diffserv codepoint */
define|#
directive|define
name|RMCF_CODEL
value|0x0020
comment|/* flags for rmc_init */
define|#
directive|define
name|RMCF_WRR
value|0x0100
define|#
directive|define
name|RMCF_EFFICIENT
value|0x0200
define|#
directive|define
name|is_a_parent_class
parameter_list|(
name|cl
parameter_list|)
value|((cl)->children_ != NULL)
specifier|extern
name|rm_class_t
modifier|*
name|rmc_newclass
parameter_list|(
name|int
parameter_list|,
name|struct
name|rm_ifdat
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|rm_class
modifier|*
parameter_list|,
name|struct
name|rm_class
modifier|*
parameter_list|)
parameter_list|,
name|int
parameter_list|,
name|struct
name|rm_class
modifier|*
parameter_list|,
name|struct
name|rm_class
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|rmc_delete_class
parameter_list|(
name|struct
name|rm_ifdat
modifier|*
parameter_list|,
name|struct
name|rm_class
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|rmc_modclass
parameter_list|(
name|struct
name|rm_class
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|rmc_init
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|,
name|struct
name|rm_ifdat
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|)
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|rmc_queue_packet
parameter_list|(
name|struct
name|rm_class
modifier|*
parameter_list|,
name|mbuf_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|mbuf_t
modifier|*
name|rmc_dequeue_next
parameter_list|(
name|struct
name|rm_ifdat
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|rmc_update_class_util
parameter_list|(
name|struct
name|rm_ifdat
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|rmc_delay_action
parameter_list|(
name|struct
name|rm_class
modifier|*
parameter_list|,
name|struct
name|rm_class
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|rmc_dropall
parameter_list|(
name|struct
name|rm_class
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|rmc_get_weight
parameter_list|(
name|struct
name|rm_ifdat
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _KERNEL */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALTQ_ALTQ_RMCLASS_H_ */
end_comment

end_unit

