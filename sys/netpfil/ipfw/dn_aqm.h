begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2016 Centre for Advanced Internet Architectures,  *  Swinburne University of Technology, Melbourne, Australia.  * Portions of this code were made possible in part by a gift from   *  The Comcast Innovation Fund.  * Implemented by Rasool Al-Saadi<ralsaadi@swin.edu.au>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * API for writing an Active Queue Management algorithm for Dummynet  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_DN_AQM_H
end_ifndef

begin_define
define|#
directive|define
name|_IP_DN_AQM_H
end_define

begin_comment
comment|/* NOW is the current time in millisecond*/
end_comment

begin_define
define|#
directive|define
name|NOW
value|((dn_cfg.curr_time * tick) / 1000)
end_define

begin_define
define|#
directive|define
name|AQM_UNOW
value|(dn_cfg.curr_time * tick)
end_define

begin_define
define|#
directive|define
name|AQM_TIME_1US
value|((aqm_time_t)(1))
end_define

begin_define
define|#
directive|define
name|AQM_TIME_1MS
value|((aqm_time_t)(1000))
end_define

begin_define
define|#
directive|define
name|AQM_TIME_1S
value|((aqm_time_t)(AQM_TIME_1MS * 1000))
end_define

begin_comment
comment|/* aqm time allows to store up to 4294 seconds */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|aqm_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|aqm_stime_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DN_AQM_MTAG_TS
value|55345
end_define

begin_comment
comment|/* Macro for variable bounding */
end_comment

begin_define
define|#
directive|define
name|BOUND_VAR
parameter_list|(
name|x
parameter_list|,
name|l
parameter_list|,
name|h
parameter_list|)
value|((x)> (h)? (h) : ((x)> (l)? (x) : (l)))
end_define

begin_comment
comment|/* sysctl variable to count number of dropped packets */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|io_pkt_drop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structure for holding data and function pointers that together represent a  * AQM algorithm.  */
end_comment

begin_struct
struct|struct
name|dn_aqm
block|{
define|#
directive|define
name|DN_AQM_NAME_MAX
value|50
name|char
name|name
index|[
name|DN_AQM_NAME_MAX
index|]
decl_stmt|;
comment|/* name of AQM algorithm */
name|uint32_t
name|type
decl_stmt|;
comment|/* AQM type number */
comment|/* Methods implemented by AQM algorithm: 	 *  	 * enqueue	enqueue packet 'm' on queue 'q'. 	 * 	Return 0 on success, 1 on drop. 	 *  	 * dequeue	dequeue a packet from queue 'q'. 	 * 	Return a packet, NULL if no packet available. 	 *  	 * config	configure AQM algorithm 	 * If required, this function should allocate space to store  	 * the configurations and set 'fs->aqmcfg' to point to this space. 	 * 'dn_extra_parms' includes array of parameters send 	 * from ipfw userland command. 	 * 	Return 0 on success, non-zero otherwise. 	 *  	 * deconfig	deconfigure AQM algorithm. 	 * The allocated configuration memory space should be freed here. 	 * 	Return 0 on success, non-zero otherwise. 	 *  	 * init	initialise AQM status variables of queue 'q' 	 * This function is used to allocate space and init AQM status for a 	 * queue and q->aqm_status to point to this space. 	 * 	Return 0 on success, non-zero otherwise. 	 *  	 * cleanup	cleanup AQM status variables of queue 'q' 	 * The allocated memory space for AQM status should be freed here. 	 * 	Return 0 on success, non-zero otherwise. 	 *  	 * getconfig	retrieve AQM configurations  	 * This function is used to return AQM parameters to userland 	 * command. The function should fill 'dn_extra_parms' struct with  	 * the AQM configurations using 'par' array. 	 *  	 */
name|int
function_decl|(
modifier|*
name|enqueue
function_decl|)
parameter_list|(
name|struct
name|dn_queue
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|dequeue
function_decl|)
parameter_list|(
name|struct
name|dn_queue
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|config
function_decl|)
parameter_list|(
name|struct
name|dn_fsk
modifier|*
parameter_list|,
name|struct
name|dn_extra_parms
modifier|*
name|ep
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|deconfig
function_decl|)
parameter_list|(
name|struct
name|dn_fsk
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|dn_queue
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|struct
name|dn_queue
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|getconfig
function_decl|)
parameter_list|(
name|struct
name|dn_fsk
modifier|*
parameter_list|,
name|struct
name|dn_extra_parms
modifier|*
parameter_list|)
function_decl|;
name|int
name|ref_count
decl_stmt|;
comment|/*Number of queues instances in the system */
name|int
name|cfg_ref_count
decl_stmt|;
comment|/*Number of AQM instances in the system */
name|SLIST_ENTRY
argument_list|(
argument|dn_aqm
argument_list|)
name|next
expr_stmt|;
comment|/* Next AQM in the list */
block|}
struct|;
end_struct

begin_comment
comment|/* Helper function to update queue and scheduler statistics.  * negative len + drop -> drop  * negative len -> dequeue  * positive len -> enqueue  * positive len + drop -> drop during enqueue  */
end_comment

begin_function
name|__inline
specifier|static
name|void
name|update_stats
parameter_list|(
name|struct
name|dn_queue
modifier|*
name|q
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
name|struct
name|dn_flow
modifier|*
name|sni
decl_stmt|;
name|struct
name|dn_flow
modifier|*
name|qni
decl_stmt|;
name|sni
operator|=
operator|&
name|q
operator|->
name|_si
operator|->
name|ni
expr_stmt|;
name|qni
operator|=
operator|&
name|q
operator|->
name|ni
expr_stmt|;
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
name|qni
operator|->
name|drops
operator|++
expr_stmt|;
name|sni
operator|->
name|drops
operator|++
expr_stmt|;
name|io_pkt_drop
operator|++
expr_stmt|;
block|}
else|else
block|{
comment|/*update queue stats */
name|qni
operator|->
name|length
operator|+=
name|inc
expr_stmt|;
name|qni
operator|->
name|len_bytes
operator|+=
name|len
expr_stmt|;
comment|/*update scheduler instance stats */
name|sni
operator|->
name|length
operator|+=
name|inc
expr_stmt|;
name|sni
operator|->
name|len_bytes
operator|+=
name|len
expr_stmt|;
block|}
comment|/* tot_pkts  is updated in dn_enqueue function */
block|}
end_function

begin_comment
comment|/* kernel module related function */
end_comment

begin_function_decl
name|int
name|dn_aqm_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DECLARE_DNAQM_MODULE
parameter_list|(
name|name
parameter_list|,
name|dnaqm
parameter_list|)
define|\
value|static moduledata_t name##_mod = {			\ 		#name, dn_aqm_modevent, dnaqm		\ 	};							\ 	DECLARE_MODULE(name, name##_mod, 			\ 		SI_SUB_PROTO_IFATTACHDOMAIN, SI_ORDER_ANY); 	\         MODULE_DEPEND(name, dummynet, 3, 3, 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

