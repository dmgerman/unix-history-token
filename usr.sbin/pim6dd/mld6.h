begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Constans for Multicast Listener Discovery protocol for IPv6.  */
end_comment

begin_define
define|#
directive|define
name|MLD6_ROBUSTNESS_VARIABLE
value|2
end_define

begin_define
define|#
directive|define
name|MLD6_QUERY_INTERVAL
value|125
end_define

begin_comment
comment|/* in seconds */
end_comment

begin_define
define|#
directive|define
name|MLD6_QUERY_RESPONSE_INTERVAL
value|10000
end_define

begin_comment
comment|/* in milliseconds */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_TIMER_SCALE
end_ifndef

begin_define
define|#
directive|define
name|MLD6_TIMER_SCALE
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MLD6_LISTENER_INTERVAL
value|(MLD6_ROBUSTNESS_VARIABLE * \ 				MLD6_QUERY_INTERVAL + \ 				MLD6_QUERY_RESPONSE_INTERVAL / MLD6_TIMER_SCALE)
end_define

begin_define
define|#
directive|define
name|MLD6_LAST_LISTENER_QUERY_INTERVAL
value|1000
end_define

begin_comment
comment|/* in milliseconds */
end_comment

begin_define
define|#
directive|define
name|MLD6_LAST_LISTENER_QUERY_COUNT
value|MLD6_ROBUSTNESS_VARIABLE
end_define

begin_define
define|#
directive|define
name|MLD6_OTHER_QUERIER_PRESENT_INTERVAL
value|(MLD6_ROBUSTNESS_VARIABLE * \ 		MLD6_QUERY_INTERVAL + \ 		MLD6_QUERY_RESPONSE_INTERVAL / (2 * MLD6_TIMER_SCALE))
end_define

end_unit

