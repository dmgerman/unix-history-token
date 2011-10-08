begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2010 Lawrence Stewart<lstewart@freebsd.org>  * Copyright (c) 2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Lawrence Stewart while studying at the Centre  * for Advanced Internet Architectures, Swinburne University of Technology, made  * possible in part by a grant from the Cisco University Research Program Fund  * at Community Foundation Silicon Valley.  *  * Portions of this software were developed at the Centre for Advanced  * Internet Architectures, Swinburne University of Technology, Melbourne,  * Australia by David Hayes under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_CC_CUBIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_CC_CUBIC_H_
end_define

begin_comment
comment|/* Number of bits of precision for fixed point math calcs. */
end_comment

begin_define
define|#
directive|define
name|CUBIC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CUBIC_SHIFT_4
value|32
end_define

begin_comment
comment|/* 0.5<< CUBIC_SHIFT. */
end_comment

begin_define
define|#
directive|define
name|RENO_BETA
value|128
end_define

begin_comment
comment|/* ~0.8<< CUBIC_SHIFT. */
end_comment

begin_define
define|#
directive|define
name|CUBIC_BETA
value|204
end_define

begin_comment
comment|/* ~0.2<< CUBIC_SHIFT. */
end_comment

begin_define
define|#
directive|define
name|ONE_SUB_CUBIC_BETA
value|51
end_define

begin_comment
comment|/* 3 * ONE_SUB_CUBIC_BETA. */
end_comment

begin_define
define|#
directive|define
name|THREE_X_PT2
value|153
end_define

begin_comment
comment|/* (2<< CUBIC_SHIFT) - ONE_SUB_CUBIC_BETA. */
end_comment

begin_define
define|#
directive|define
name|TWO_SUB_PT2
value|461
end_define

begin_comment
comment|/* ~0.4<< CUBIC_SHIFT. */
end_comment

begin_define
define|#
directive|define
name|CUBIC_C_FACTOR
value|102
end_define

begin_comment
comment|/* CUBIC fast convergence factor: ~0.9<< CUBIC_SHIFT. */
end_comment

begin_define
define|#
directive|define
name|CUBIC_FC_FACTOR
value|230
end_define

begin_comment
comment|/* Don't trust s_rtt until this many rtt samples have been taken. */
end_comment

begin_define
define|#
directive|define
name|CUBIC_MIN_RTT_SAMPLES
value|8
end_define

begin_comment
comment|/* Userland only bits. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|hz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Implementation based on the formulae found in the CUBIC Internet Draft  * "draft-rhee-tcpm-cubic-02".  *  * Note BETA used in cc_cubic is equal to (1-beta) in the I-D  */
end_comment

begin_function
specifier|static
name|__inline
name|float
name|theoretical_cubic_k
parameter_list|(
name|double
name|wmax_pkts
parameter_list|)
block|{
name|double
name|C
decl_stmt|;
name|C
operator|=
literal|0.4
expr_stmt|;
return|return
operator|(
name|pow
argument_list|(
operator|(
name|wmax_pkts
operator|*
literal|0.2
operator|)
operator|/
name|C
argument_list|,
operator|(
literal|1.0
operator|/
literal|3.0
operator|)
argument_list|)
operator|*
name|pow
argument_list|(
literal|2
argument_list|,
name|CUBIC_SHIFT
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|theoretical_cubic_cwnd
parameter_list|(
name|int
name|ticks_since_cong
parameter_list|,
name|unsigned
name|long
name|wmax
parameter_list|,
name|uint32_t
name|smss
parameter_list|)
block|{
name|double
name|C
decl_stmt|,
name|wmax_pkts
decl_stmt|;
name|C
operator|=
literal|0.4
expr_stmt|;
name|wmax_pkts
operator|=
name|wmax
operator|/
operator|(
name|double
operator|)
name|smss
expr_stmt|;
return|return
operator|(
name|smss
operator|*
operator|(
name|wmax_pkts
operator|+
operator|(
name|C
operator|*
name|pow
argument_list|(
name|ticks_since_cong
operator|/
operator|(
name|double
operator|)
name|hz
operator|-
name|theoretical_cubic_k
argument_list|(
name|wmax_pkts
argument_list|)
operator|/
name|pow
argument_list|(
literal|2
argument_list|,
name|CUBIC_SHIFT
argument_list|)
argument_list|,
literal|3.0
argument_list|)
operator|)
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|theoretical_reno_cwnd
parameter_list|(
name|int
name|ticks_since_cong
parameter_list|,
name|int
name|rtt_ticks
parameter_list|,
name|unsigned
name|long
name|wmax
parameter_list|,
name|uint32_t
name|smss
parameter_list|)
block|{
return|return
operator|(
operator|(
name|wmax
operator|*
literal|0.5
operator|)
operator|+
operator|(
operator|(
name|ticks_since_cong
operator|/
operator|(
name|float
operator|)
name|rtt_ticks
operator|)
operator|*
name|smss
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|theoretical_tf_cwnd
parameter_list|(
name|int
name|ticks_since_cong
parameter_list|,
name|int
name|rtt_ticks
parameter_list|,
name|unsigned
name|long
name|wmax
parameter_list|,
name|uint32_t
name|smss
parameter_list|)
block|{
return|return
operator|(
operator|(
name|wmax
operator|*
literal|0.8
operator|)
operator|+
operator|(
operator|(
literal|3
operator|*
literal|0.2
operator|)
operator|/
operator|(
literal|2
operator|-
literal|0.2
operator|)
operator|*
operator|(
name|ticks_since_cong
operator|/
operator|(
name|float
operator|)
name|rtt_ticks
operator|)
operator|*
name|smss
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * Compute the CUBIC K value used in the cwnd calculation, using an  * implementation of eqn 2 in the I-D. The method used  * here is adapted from Apple Computer Technical Report #KT-32.  */
end_comment

begin_function
specifier|static
name|__inline
name|int64_t
name|cubic_k
parameter_list|(
name|unsigned
name|long
name|wmax_pkts
parameter_list|)
block|{
name|int64_t
name|s
decl_stmt|,
name|K
decl_stmt|;
name|uint16_t
name|p
decl_stmt|;
name|K
operator|=
name|s
operator|=
literal|0
expr_stmt|;
name|p
operator|=
literal|0
expr_stmt|;
comment|/* (wmax * beta)/C with CUBIC_SHIFT worth of precision. */
name|s
operator|=
operator|(
operator|(
name|wmax_pkts
operator|*
name|ONE_SUB_CUBIC_BETA
operator|)
operator|<<
name|CUBIC_SHIFT
operator|)
operator|/
name|CUBIC_C_FACTOR
expr_stmt|;
comment|/* Rebase s to be between 1 and 1/8 with a shift of CUBIC_SHIFT. */
while|while
condition|(
name|s
operator|>=
literal|256
condition|)
block|{
name|s
operator|>>=
literal|3
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
comment|/* 	 * Some magic constants taken from the Apple TR with appropriate 	 * shifts: 275 == 1.072302<< CUBIC_SHIFT, 98 == 0.3812513<< 	 * CUBIC_SHIFT, 120 == 0.46946116<< CUBIC_SHIFT. 	 */
name|K
operator|=
operator|(
operator|(
operator|(
name|s
operator|*
literal|275
operator|)
operator|>>
name|CUBIC_SHIFT
operator|)
operator|+
literal|98
operator|)
operator|-
operator|(
operator|(
operator|(
name|s
operator|*
name|s
operator|*
literal|120
operator|)
operator|>>
name|CUBIC_SHIFT
operator|)
operator|>>
name|CUBIC_SHIFT
operator|)
expr_stmt|;
comment|/* Multiply by 2^p to undo the rebasing of s from above. */
return|return
operator|(
name|K
operator|<<=
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Compute the new cwnd value using an implementation of eqn 1 from the I-D.  * Thanks to Kip Macy for help debugging this function.  *  * XXXLAS: Characterise bounds for overflow.  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|cubic_cwnd
parameter_list|(
name|int
name|ticks_since_cong
parameter_list|,
name|unsigned
name|long
name|wmax
parameter_list|,
name|uint32_t
name|smss
parameter_list|,
name|int64_t
name|K
parameter_list|)
block|{
name|int64_t
name|cwnd
decl_stmt|;
comment|/* K is in fixed point form with CUBIC_SHIFT worth of precision. */
comment|/* t - K, with CUBIC_SHIFT worth of precision. */
name|cwnd
operator|=
operator|(
call|(
name|int64_t
call|)
argument_list|(
name|ticks_since_cong
operator|<<
name|CUBIC_SHIFT
argument_list|)
operator|-
operator|(
name|K
operator|*
name|hz
operator|)
operator|)
operator|/
name|hz
expr_stmt|;
comment|/* (t - K)^3, with CUBIC_SHIFT^3 worth of precision. */
name|cwnd
operator|*=
operator|(
name|cwnd
operator|*
name|cwnd
operator|)
expr_stmt|;
comment|/* 	 * C(t - K)^3 + wmax 	 * The down shift by CUBIC_SHIFT_4 is because cwnd has 4 lots of 	 * CUBIC_SHIFT included in the value. 3 from the cubing of cwnd above, 	 * and an extra from multiplying through by CUBIC_C_FACTOR. 	 */
name|cwnd
operator|=
operator|(
operator|(
name|cwnd
operator|*
name|CUBIC_C_FACTOR
operator|*
name|smss
operator|)
operator|>>
name|CUBIC_SHIFT_4
operator|)
operator|+
name|wmax
expr_stmt|;
return|return
operator|(
operator|(
name|unsigned
name|long
operator|)
name|cwnd
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Compute an approximation of the NewReno cwnd some number of ticks after a  * congestion event. RTT should be the average RTT estimate for the path  * measured over the previous congestion epoch and wmax is the value of cwnd at  * the last congestion event. The "TCP friendly" concept in the CUBIC I-D is  * rather tricky to understand and it turns out this function is not required.  * It is left here for reference.  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|reno_cwnd
parameter_list|(
name|int
name|ticks_since_cong
parameter_list|,
name|int
name|rtt_ticks
parameter_list|,
name|unsigned
name|long
name|wmax
parameter_list|,
name|uint32_t
name|smss
parameter_list|)
block|{
comment|/* 	 * For NewReno, beta = 0.5, therefore: W_tcp(t) = wmax*0.5 + t/RTT 	 * W_tcp(t) deals with cwnd/wmax in pkts, so because our cwnd is in 	 * bytes, we have to multiply by smss. 	 */
return|return
operator|(
operator|(
operator|(
name|wmax
operator|*
name|RENO_BETA
operator|)
operator|+
operator|(
operator|(
operator|(
name|ticks_since_cong
operator|*
name|smss
operator|)
operator|<<
name|CUBIC_SHIFT
operator|)
operator|/
name|rtt_ticks
operator|)
operator|)
operator|>>
name|CUBIC_SHIFT
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Compute an approximation of the "TCP friendly" cwnd some number of ticks  * after a congestion event that is designed to yield the same average cwnd as  * NewReno while using CUBIC's beta of 0.8. RTT should be the average RTT  * estimate for the path measured over the previous congestion epoch and wmax is  * the value of cwnd at the last congestion event.  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|tf_cwnd
parameter_list|(
name|int
name|ticks_since_cong
parameter_list|,
name|int
name|rtt_ticks
parameter_list|,
name|unsigned
name|long
name|wmax
parameter_list|,
name|uint32_t
name|smss
parameter_list|)
block|{
comment|/* Equation 4 of I-D. */
return|return
operator|(
operator|(
operator|(
name|wmax
operator|*
name|CUBIC_BETA
operator|)
operator|+
operator|(
operator|(
operator|(
name|THREE_X_PT2
operator|*
name|ticks_since_cong
operator|*
name|smss
operator|)
operator|<<
name|CUBIC_SHIFT
operator|)
operator|/
name|TWO_SUB_PT2
operator|/
name|rtt_ticks
operator|)
operator|)
operator|>>
name|CUBIC_SHIFT
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_CC_CUBIC_H_ */
end_comment

end_unit

