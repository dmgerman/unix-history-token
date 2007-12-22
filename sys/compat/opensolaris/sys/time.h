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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|lbolt
value|((gethrtime() * hz) / NANOSEC)
end_define

begin_define
define|#
directive|define
name|lbolt64
value|(int64_t)(lbolt)
end_define

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
if|#
directive|if
literal|1
name|getnanouptime
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
else|#
directive|else
name|nanouptime
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
endif|#
directive|endif
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

