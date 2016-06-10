begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2016 Centre for Advanced Internet Architectures,  *  Swinburne University of Technology, Melbourne, Australia.  * Portions of this code were made possible in part by a gift from   *  The Comcast Innovation Fund.  * Implemented by Rasool Al-Saadi<ralsaadi@swin.edu.au>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * FQ_Codel Structures and helper functions  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_DN_SCHED_FQ_CODEL_H
end_ifndef

begin_define
define|#
directive|define
name|_IP_DN_SCHED_FQ_CODEL_H
end_define

begin_comment
comment|/* list of queues */
end_comment

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|fq_codel_list
argument_list|,
name|fq_codel_flow
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* fq_codel parameters including codel */
end_comment

begin_struct
struct|struct
name|dn_sch_fq_codel_parms
block|{
name|struct
name|dn_aqm_codel_parms
name|ccfg
decl_stmt|;
comment|/* CoDel Parameters */
comment|/* FQ_CODEL Parameters */
name|uint32_t
name|flows_cnt
decl_stmt|;
comment|/* number of flows */
name|uint32_t
name|limit
decl_stmt|;
comment|/* hard limit of fq_codel queue size*/
name|uint32_t
name|quantum
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* defaults */
end_comment

begin_comment
comment|/* flow (sub-queue) stats */
end_comment

begin_struct
struct|struct
name|flow_stats
block|{
name|uint64_t
name|tot_pkts
decl_stmt|;
comment|/* statistics counters  */
name|uint64_t
name|tot_bytes
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
comment|/* Queue length, in packets */
name|uint32_t
name|len_bytes
decl_stmt|;
comment|/* Queue length, in bytes */
name|uint32_t
name|drops
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A flow of packets (sub-queue).*/
end_comment

begin_struct
struct|struct
name|fq_codel_flow
block|{
name|struct
name|mq
name|mq
decl_stmt|;
comment|/* list of packets */
name|struct
name|flow_stats
name|stats
decl_stmt|;
comment|/* statistics */
name|int
name|deficit
decl_stmt|;
name|int
name|active
decl_stmt|;
comment|/* 1: flow is active (in a list) */
name|struct
name|codel_status
name|cst
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|fq_codel_flow
argument_list|)
name|flowchain
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* extra fq_codel scheduler configurations */
end_comment

begin_struct
struct|struct
name|fq_codel_schk
block|{
name|struct
name|dn_sch_fq_codel_parms
name|cfg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* fq_codel scheduler instance */
end_comment

begin_struct
struct|struct
name|fq_codel_si
block|{
name|struct
name|dn_sch_inst
name|_si
decl_stmt|;
comment|/* standard scheduler instance */
name|struct
name|dn_queue
name|main_q
decl_stmt|;
comment|/* main queue is after si directly */
name|struct
name|fq_codel_flow
modifier|*
name|flows
decl_stmt|;
comment|/* array of flows (queues) */
name|uint32_t
name|perturbation
decl_stmt|;
comment|/* random value */
name|struct
name|fq_codel_list
name|newflows
decl_stmt|;
comment|/* list of new queues */
name|struct
name|fq_codel_list
name|oldflows
decl_stmt|;
comment|/* list of old queues */
block|}
struct|;
end_struct

begin_comment
comment|/* Helper function to update queue&main-queue and scheduler statistics.  * negative len + drop -> drop  * negative len -> dequeue  * positive len -> enqueue  * positive len + drop -> drop during enqueue  */
end_comment

begin_function
name|__inline
specifier|static
name|void
name|fq_update_stats
parameter_list|(
name|struct
name|fq_codel_flow
modifier|*
name|q
parameter_list|,
name|struct
name|fq_codel_si
modifier|*
name|si
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|drop
parameter_list|)
block|{
name|int
name|inc
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|len
operator|<
literal|0
condition|)
name|inc
operator|=
operator|-
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|len
operator|>
literal|0
condition|)
name|inc
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|drop
condition|)
block|{
name|si
operator|->
name|main_q
operator|.
name|ni
operator|.
name|drops
operator|++
expr_stmt|;
name|q
operator|->
name|stats
operator|.
name|drops
operator|++
expr_stmt|;
name|si
operator|->
name|_si
operator|.
name|ni
operator|.
name|drops
operator|++
expr_stmt|;
name|io_pkt_drop
operator|++
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|drop
operator|||
operator|(
name|drop
operator|&&
name|len
operator|<
literal|0
operator|)
condition|)
block|{
comment|/* Update stats for the main queue */
name|si
operator|->
name|main_q
operator|.
name|ni
operator|.
name|length
operator|+=
name|inc
expr_stmt|;
name|si
operator|->
name|main_q
operator|.
name|ni
operator|.
name|len_bytes
operator|+=
name|len
expr_stmt|;
comment|/*update sub-queue stats */
name|q
operator|->
name|stats
operator|.
name|length
operator|+=
name|inc
expr_stmt|;
name|q
operator|->
name|stats
operator|.
name|len_bytes
operator|+=
name|len
expr_stmt|;
comment|/*update scheduler instance stats */
name|si
operator|->
name|_si
operator|.
name|ni
operator|.
name|length
operator|+=
name|inc
expr_stmt|;
name|si
operator|->
name|_si
operator|.
name|ni
operator|.
name|len_bytes
operator|+=
name|len
expr_stmt|;
block|}
if|if
condition|(
name|inc
operator|>
literal|0
condition|)
block|{
name|si
operator|->
name|main_q
operator|.
name|ni
operator|.
name|tot_bytes
operator|+=
name|len
expr_stmt|;
name|si
operator|->
name|main_q
operator|.
name|ni
operator|.
name|tot_pkts
operator|++
expr_stmt|;
name|q
operator|->
name|stats
operator|.
name|tot_bytes
operator|+=
name|len
expr_stmt|;
name|q
operator|->
name|stats
operator|.
name|tot_pkts
operator|++
expr_stmt|;
name|si
operator|->
name|_si
operator|.
name|ni
operator|.
name|tot_bytes
operator|+=
name|len
expr_stmt|;
name|si
operator|->
name|_si
operator|.
name|ni
operator|.
name|tot_pkts
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* extract the head of fq_codel sub-queue */
end_comment

begin_expr_stmt
name|__inline
specifier|static
expr|struct
name|mbuf
operator|*
name|fq_codel_extract_head
argument_list|(
argument|struct fq_codel_flow *q
argument_list|,
argument|aqm_time_t *pkt_ts
argument_list|,
argument|struct fq_codel_si *si
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|m
operator|=
name|q
operator|->
name|mq
operator|.
name|head
block|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
return|return
name|m
return|;
name|q
operator|->
name|mq
operator|.
name|head
operator|=
name|m
operator|->
name|m_nextpkt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fq_update_stats
argument_list|(
name|q
argument_list|,
name|si
argument_list|,
operator|-
name|m
operator|->
name|m_pkthdr
operator|.
name|len
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|si
operator|->
name|main_q
operator|.
name|ni
operator|.
name|length
operator|==
literal|0
condition|)
comment|/* queue is now idle */
name|si
operator|->
name|main_q
operator|.
name|q_time
operator|=
name|dn_cfg
operator|.
name|curr_time
expr_stmt|;
end_if

begin_comment
comment|/* extract packet timestamp*/
end_comment

begin_decl_stmt
name|struct
name|m_tag
modifier|*
name|mtag
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|mtag
operator|=
name|m_tag_locate
argument_list|(
name|m
argument_list|,
name|MTAG_ABI_COMPAT
argument_list|,
name|DN_AQM_MTAG_TS
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|mtag
operator|==
name|NULL
condition|)
block|{
name|D
argument_list|(
literal|"timestamp tag is not found!"
argument_list|)
expr_stmt|;
operator|*
name|pkt_ts
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
operator|*
name|pkt_ts
operator|=
operator|*
operator|(
name|aqm_time_t
operator|*
operator|)
operator|(
name|mtag
operator|+
literal|1
operator|)
expr_stmt|;
name|m_tag_delete
argument_list|(
name|m
argument_list|,
name|mtag
argument_list|)
expr_stmt|;
block|}
end_if

begin_return
return|return
name|m
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

