begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999 LSIIT Laboratory.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to  *  Mickael Hoerdt (hoerdt@clarinet.u-strasbg.fr) LSIIT Strasbourg.  *  */
end_comment

begin_comment
comment|/*  * This program has been derived from pim6dd.          * The pim6dd program is covered by the license in the accompanying file  * named "LICENSE.pim6dd".  */
end_comment

begin_comment
comment|/*  * This program has been derived from pimd.          * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIMER_H
end_ifndef

begin_define
define|#
directive|define
name|TIMER_H
end_define

begin_comment
comment|/* the default granularity if not specified in the config file */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TIMER_INTERVAL
value|5
end_define

begin_comment
comment|/* For timeout. The timers count down */
end_comment

begin_define
define|#
directive|define
name|SET_TIMER
parameter_list|(
name|timer
parameter_list|,
name|value
parameter_list|)
value|(timer) = (value)
end_define

begin_define
define|#
directive|define
name|RESET_TIMER
parameter_list|(
name|timer
parameter_list|)
value|(timer) = 0
end_define

begin_define
define|#
directive|define
name|COPY_TIMER
parameter_list|(
name|timer_1
parameter_list|,
name|timer_2
parameter_list|)
value|(timer_2) = (timer_1)
end_define

begin_define
define|#
directive|define
name|IF_TIMER_SET
parameter_list|(
name|timer
parameter_list|)
value|if ((timer)> 0)
end_define

begin_define
define|#
directive|define
name|IF_TIMER_NOT_SET
parameter_list|(
name|timer
parameter_list|)
value|if ((timer)<= 0)
end_define

begin_define
define|#
directive|define
name|FIRE_TIMER
parameter_list|(
name|timer
parameter_list|)
value|(timer) = 0
end_define

begin_define
define|#
directive|define
name|IF_TIMER_NOT_SET
parameter_list|(
name|timer
parameter_list|)
value|if ((timer)<= 0)
end_define

begin_define
define|#
directive|define
name|IF_TIMEOUT
parameter_list|(
name|timer
parameter_list|)
define|\
value|if (!((timer) -= (MIN(timer, timer_interval))))
end_define

begin_define
define|#
directive|define
name|IF_NOT_TIMEOUT
parameter_list|(
name|timer
parameter_list|)
define|\
value|if ((timer) -= (MIN(timer, timer_interval)))
end_define

begin_define
define|#
directive|define
name|TIMEOUT
parameter_list|(
name|timer
parameter_list|)
define|\
value|(!((timer) -= (MIN(timer, timer_interval))))
end_define

begin_define
define|#
directive|define
name|NOT_TIMEOUT
parameter_list|(
name|timer
parameter_list|)
define|\
value|((timer) -= (MIN(timer, timer_interval)))
end_define

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_reg_rate_bytes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_reg_rate_check_interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_data_rate_bytes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_data_rate_check_interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_hello_period
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_hello_holdtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|timer_interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_join_prune_period
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_join_prune_holdtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_data_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_register_suppression_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_register_probe_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|pim_assert_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_timers
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_timers
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_vifs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_routes
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_misc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

