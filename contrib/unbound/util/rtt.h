begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/rtt.h - UDP round trip time estimator for resend timeouts.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains a data type and functions to help estimate good  * round trip times for UDP resend timeout values.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_RTT_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_RTT_H
end_define

begin_comment
comment|/**  * RTT information. Keeps packet Round Trip Time.  */
end_comment

begin_struct
struct|struct
name|rtt_info
block|{
comment|/** smoothed rtt estimator, in milliseconds */
name|int
name|srtt
decl_stmt|;
comment|/** smoothed mean deviation, in milliseconds */
name|int
name|rttvar
decl_stmt|;
comment|/** current RTO in use, in milliseconds */
name|int
name|rto
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** min retransmit timeout value, in milliseconds */
end_comment

begin_define
define|#
directive|define
name|RTT_MIN_TIMEOUT
value|50
end_define

begin_comment
comment|/** max retransmit timeout value, in milliseconds */
end_comment

begin_define
define|#
directive|define
name|RTT_MAX_TIMEOUT
value|120000
end_define

begin_comment
comment|/**  * Initialize RTT estimators.  * @param rtt: The structure. Caller is responsible for allocation of it.  */
end_comment

begin_function_decl
name|void
name|rtt_init
parameter_list|(
name|struct
name|rtt_info
modifier|*
name|rtt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Get timeout to use for sending a UDP packet.  * @param rtt: round trip statistics structure.  * @return: timeout to use in milliseconds. Relative time value.  */
end_comment

begin_function_decl
name|int
name|rtt_timeout
parameter_list|(
specifier|const
name|struct
name|rtt_info
modifier|*
name|rtt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Get unclamped timeout to use for server selection.  * Recent timeouts are reflected in the returned value.  * @param rtt: round trip statistics structure.  * @return: value to use in milliseconds.   */
end_comment

begin_function_decl
name|int
name|rtt_unclamped
parameter_list|(
specifier|const
name|struct
name|rtt_info
modifier|*
name|rtt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * RTT for valid responses. Without timeouts.  * @param rtt: round trip statistics structure.  * @return: value in msec.  */
end_comment

begin_function_decl
name|int
name|rtt_notimeout
parameter_list|(
specifier|const
name|struct
name|rtt_info
modifier|*
name|rtt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Update the statistics with a new roundtrip estimate observation.  * @param rtt: round trip statistics structure.  * @param ms: estimate of roundtrip time in milliseconds.  */
end_comment

begin_function_decl
name|void
name|rtt_update
parameter_list|(
name|struct
name|rtt_info
modifier|*
name|rtt
parameter_list|,
name|int
name|ms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Update the statistics with a new timout expired observation.  * @param rtt: round trip statistics structure.  * @param orig: original rtt time given for the query that timed out.  * 	Used to calculate the maximum responsible backed off time that  * 	can reasonably be applied.  */
end_comment

begin_function_decl
name|void
name|rtt_lost
parameter_list|(
name|struct
name|rtt_info
modifier|*
name|rtt
parameter_list|,
name|int
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_RTT_H */
end_comment

end_unit

