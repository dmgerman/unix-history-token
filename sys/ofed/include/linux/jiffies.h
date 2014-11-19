begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_JIFFIES_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_JIFFIES_H_
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_function
specifier|static
specifier|inline
name|int
name|msecs_to_jiffies
parameter_list|(
name|int
name|msec
parameter_list|)
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|tv
operator|.
name|tv_sec
operator|=
name|msec
operator|/
literal|1000
expr_stmt|;
name|tv
operator|.
name|tv_usec
operator|=
operator|(
name|msec
operator|%
literal|1000
operator|)
operator|*
literal|1000
expr_stmt|;
return|return
operator|(
name|tvtohz
argument_list|(
operator|&
name|tv
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|jiffies
value|ticks
end_define

begin_define
define|#
directive|define
name|jiffies_to_msecs
parameter_list|(
name|x
parameter_list|)
value|(((int64_t)(x)) * 1000 / hz)
end_define

begin_define
define|#
directive|define
name|time_after
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(b) - (long)(a)< 0)
end_define

begin_define
define|#
directive|define
name|time_before
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|time_after(b,a)
end_define

begin_define
define|#
directive|define
name|time_after_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(a) - (long)(b)>= 0)
end_define

begin_define
define|#
directive|define
name|time_before_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|time_after_eq(b, a)
end_define

begin_define
define|#
directive|define
name|HZ
value|hz
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_JIFFIES_H_ */
end_comment

end_unit

