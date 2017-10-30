begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_TIME_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_TIME_H_
end_define

begin_empty
empty|#include_next<sys/time.h>
end_empty

begin_define
define|#
directive|define
name|SEC
value|1
end_define

begin_define
define|#
directive|define
name|MILLISEC
value|1000
end_define

begin_define
define|#
directive|define
name|MICROSEC
value|1000000
end_define

begin_define
define|#
directive|define
name|NANOSEC
value|1000000000
end_define

begin_define
define|#
directive|define
name|TIME_MAX
value|LLONG_MAX
end_define

begin_define
define|#
directive|define
name|MSEC2NSEC
parameter_list|(
name|m
parameter_list|)
value|((hrtime_t)(m) * (NANOSEC / MILLISEC))
end_define

begin_define
define|#
directive|define
name|NSEC2MSEC
parameter_list|(
name|n
parameter_list|)
value|((n) / (NANOSEC / MILLISEC))
end_define

begin_define
define|#
directive|define
name|USEC2NSEC
parameter_list|(
name|m
parameter_list|)
value|((hrtime_t)(m) * (NANOSEC / MICROSEC))
end_define

begin_define
define|#
directive|define
name|NSEC2USEC
parameter_list|(
name|n
parameter_list|)
value|((n) / (NANOSEC / MICROSEC))
end_define

begin_define
define|#
directive|define
name|NSEC2SEC
parameter_list|(
name|n
parameter_list|)
value|((n) / (NANOSEC / SEC))
end_define

begin_define
define|#
directive|define
name|SEC2NSEC
parameter_list|(
name|m
parameter_list|)
value|((hrtime_t)(m) * (NANOSEC / SEC))
end_define

begin_typedef
typedef|typedef
name|longlong_t
name|hrtime_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TIMESPEC_OVERFLOW
parameter_list|(
name|ts
parameter_list|)
define|\
value|((ts)->tv_sec< INT32_MIN || (ts)->tv_sec> INT32_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TIMESPEC_OVERFLOW
parameter_list|(
name|ts
parameter_list|)
define|\
value|((ts)->tv_sec< INT64_MIN || (ts)->tv_sec> INT64_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SEC_TO_TICK
parameter_list|(
name|sec
parameter_list|)
value|((sec) * hz)
end_define

begin_define
define|#
directive|define
name|NSEC_TO_TICK
parameter_list|(
name|nsec
parameter_list|)
value|((nsec) / (NANOSEC / hz))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function
specifier|static
name|__inline
name|hrtime_t
name|gethrtime
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|timespec
name|ts
decl_stmt|;
name|hrtime_t
name|nsec
decl_stmt|;
name|getnanouptime
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
name|nsec
operator|=
operator|(
name|hrtime_t
operator|)
name|ts
operator|.
name|tv_sec
operator|*
name|NANOSEC
operator|+
name|ts
operator|.
name|tv_nsec
expr_stmt|;
return|return
operator|(
name|nsec
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|gethrestime_sec
parameter_list|()
value|(time_second)
end_define

begin_define
define|#
directive|define
name|gethrestime
parameter_list|(
name|ts
parameter_list|)
value|getnanotime(ts)
end_define

begin_define
define|#
directive|define
name|gethrtime_waitfree
parameter_list|()
value|gethrtime()
end_define

begin_decl_stmt
specifier|extern
name|int
name|nsec_per_tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nanoseconds per clock tick */
end_comment

begin_define
define|#
directive|define
name|ddi_get_lbolt64
parameter_list|()
define|\
value|(int64_t)(((getsbinuptime()>> 16) * hz)>> 16)
end_define

begin_define
define|#
directive|define
name|ddi_get_lbolt
parameter_list|()
value|(clock_t)ddi_get_lbolt64()
end_define

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|hrtime_t
name|gethrtime
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|timespec
name|ts
decl_stmt|;
name|clock_gettime
argument_list|(
name|CLOCK_UPTIME
argument_list|,
operator|&
name|ts
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
operator|(
name|u_int64_t
operator|)
name|ts
operator|.
name|tv_sec
operator|)
operator|*
name|NANOSEC
operator|+
name|ts
operator|.
name|tv_nsec
operator|)
return|;
block|}
end_function

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
comment|/* !_OPENSOLARIS_SYS_TIME_H_ */
end_comment

end_unit

