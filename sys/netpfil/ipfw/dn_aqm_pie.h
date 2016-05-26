begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * PIE - Proportional Integral controller Enhanced AQM algorithm.  *  * $FreeBSD$  *   * Copyright (C) 2016 Centre for Advanced Internet Architectures,  *  Swinburne University of Technology, Melbourne, Australia.  * Portions of this code were made possible in part by a gift from   *  The Comcast Innovation Fund.  * Implemented by Rasool Al-Saadi<ralsaadi@swin.edu.au>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_DN_AQM_PIE_H
end_ifndef

begin_define
define|#
directive|define
name|_IP_DN_AQM_PIE_H
end_define

begin_define
define|#
directive|define
name|DN_AQM_PIE
value|2
end_define

begin_define
define|#
directive|define
name|PIE_DQ_THRESHOLD_BITS
value|14
end_define

begin_comment
comment|/* 2^14 =16KB */
end_comment

begin_define
define|#
directive|define
name|PIE_DQ_THRESHOLD
value|(1UL<< PIE_DQ_THRESHOLD_BITS)
end_define

begin_define
define|#
directive|define
name|MEAN_PKTSIZE
value|800
end_define

begin_comment
comment|/* 31-bits because random() generates range from 0->(2**31)-1 */
end_comment

begin_define
define|#
directive|define
name|PIE_PROB_BITS
value|31
end_define

begin_define
define|#
directive|define
name|PIE_MAX_PROB
value|((1ULL<<PIE_PROB_BITS) -1)
end_define

begin_comment
comment|/* for 16-bits, we have 3-bits for integer part and 13-bits for fraction */
end_comment

begin_define
define|#
directive|define
name|PIE_FIX_POINT_BITS
value|13
end_define

begin_define
define|#
directive|define
name|PIE_SCALE
value|(1UL<<PIE_FIX_POINT_BITS)
end_define

begin_comment
comment|/* PIE options */
end_comment

begin_enum
enum|enum
block|{
name|PIE_ECN_ENABLED
init|=
literal|1
block|,
name|PIE_CAPDROP_ENABLED
init|=
literal|2
block|,
name|PIE_ON_OFF_MODE_ENABLED
init|=
literal|4
block|,
name|PIE_DEPRATEEST_ENABLED
init|=
literal|8
block|,
name|PIE_DERAND_ENABLED
init|=
literal|16
block|}
enum|;
end_enum

begin_comment
comment|/* PIE parameters */
end_comment

begin_struct
struct|struct
name|dn_aqm_pie_parms
block|{
name|aqm_time_t
name|qdelay_ref
decl_stmt|;
comment|/* AQM Latency Target (default: 15ms) */
name|aqm_time_t
name|tupdate
decl_stmt|;
comment|/* a period to calculate drop probability (default:15ms) */
name|aqm_time_t
name|max_burst
decl_stmt|;
comment|/* AQM Max Burst Allowance (default: 150ms) */
name|uint16_t
name|max_ecnth
decl_stmt|;
comment|/*AQM Max ECN Marking Threshold (default: 10%) */
name|uint16_t
name|alpha
decl_stmt|;
comment|/* (default: 1/8) */
name|uint16_t
name|beta
decl_stmt|;
comment|/* (default: 1+1/4) */
name|uint32_t
name|flags
decl_stmt|;
comment|/* PIE options */
block|}
struct|;
end_struct

begin_comment
comment|/* PIE status variables */
end_comment

begin_struct
struct|struct
name|pie_status
block|{
name|struct
name|callout
name|aqm_pie_callout
decl_stmt|;
name|aqm_time_t
name|burst_allowance
decl_stmt|;
name|uint32_t
name|drop_prob
decl_stmt|;
name|aqm_time_t
name|current_qdelay
decl_stmt|;
name|aqm_time_t
name|qdelay_old
decl_stmt|;
name|uint64_t
name|accu_prob
decl_stmt|;
name|aqm_time_t
name|measurement_start
decl_stmt|;
name|aqm_time_t
name|avg_dq_time
decl_stmt|;
name|uint32_t
name|dq_count
decl_stmt|;
name|uint32_t
name|sflags
decl_stmt|;
name|struct
name|dn_aqm_pie_parms
modifier|*
name|parms
decl_stmt|;
comment|/* pointer to PIE configurations */
comment|/* pointer to parent queue of FQ-PIE sub-queues, or  queue of owner fs. */
name|struct
name|dn_queue
modifier|*
name|pq
decl_stmt|;
name|struct
name|mtx
name|lock_mtx
decl_stmt|;
name|uint32_t
name|one_third_q_size
decl_stmt|;
comment|/* 1/3 of queue size, for speed optization */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|ENQUE
init|=
literal|1
block|,
name|DROP
block|,
name|MARKECN
block|}
enum|;
end_enum

begin_comment
comment|/* PIE current state */
end_comment

begin_enum
enum|enum
block|{
name|PIE_ACTIVE
init|=
literal|1
block|,
name|PIE_INMEASUREMENT
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/*   * Check if eneque should drop packet to control delay or not based on  * PIe algorithm.  * return  DROP if it is time to drop or  ENQUE otherwise.  * This function is used by PIE and FQ-PIE.  */
end_comment

begin_function
name|__inline
specifier|static
name|int
name|drop_early
parameter_list|(
name|struct
name|pie_status
modifier|*
name|pst
parameter_list|,
name|uint32_t
name|qlen
parameter_list|)
block|{
name|struct
name|dn_aqm_pie_parms
modifier|*
name|pprms
decl_stmt|;
name|pprms
operator|=
name|pst
operator|->
name|parms
expr_stmt|;
comment|/* queue is not congested */
if|if
condition|(
operator|(
name|pst
operator|->
name|qdelay_old
operator|<
operator|(
name|pprms
operator|->
name|qdelay_ref
operator|>>
literal|1
operator|)
operator|&&
name|pst
operator|->
name|drop_prob
operator|<
name|PIE_MAX_PROB
operator|/
literal|5
operator|)
operator|||
name|qlen
operator|<=
literal|2
operator|*
name|MEAN_PKTSIZE
condition|)
return|return
name|ENQUE
return|;
if|if
condition|(
name|pst
operator|->
name|drop_prob
operator|==
literal|0
condition|)
name|pst
operator|->
name|accu_prob
operator|=
literal|0
expr_stmt|;
comment|/* increment accu_prob */
if|if
condition|(
name|pprms
operator|->
name|flags
operator|&
name|PIE_DERAND_ENABLED
condition|)
name|pst
operator|->
name|accu_prob
operator|+=
name|pst
operator|->
name|drop_prob
expr_stmt|;
comment|/* De-randomize option  	 * if accu_prob< 0.85 -> enqueue 	 * if accu_prob>8.5 ->drop 	 * between 0.85 and 8.5 || !De-randomize --> drop on prob 	 */
if|if
condition|(
name|pprms
operator|->
name|flags
operator|&
name|PIE_DERAND_ENABLED
condition|)
block|{
if|if
condition|(
name|pst
operator|->
name|accu_prob
operator|<
call|(
name|uint64_t
call|)
argument_list|(
name|PIE_MAX_PROB
operator|*
literal|0.85
argument_list|)
condition|)
return|return
name|ENQUE
return|;
if|if
condition|(
name|pst
operator|->
name|accu_prob
operator|>=
call|(
name|uint64_t
call|)
argument_list|(
name|PIE_MAX_PROB
operator|*
literal|8.5
argument_list|)
condition|)
return|return
name|DROP
return|;
block|}
if|if
condition|(
name|random
argument_list|()
operator|<
name|pst
operator|->
name|drop_prob
condition|)
block|{
name|pst
operator|->
name|accu_prob
operator|=
literal|0
expr_stmt|;
return|return
name|DROP
return|;
block|}
return|return
name|ENQUE
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

