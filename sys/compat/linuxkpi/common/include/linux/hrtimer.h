begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Mark Johnston<markj@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_HRTIMER_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_HRTIMER_H_
end_define

begin_include
include|#
directive|include
file|<sys/_callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<linux/ktime.h>
end_include

begin_include
include|#
directive|include
file|<linux/timer.h>
end_include

begin_enum
enum|enum
name|hrtimer_mode
block|{
name|HRTIMER_MODE_REL
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|hrtimer_restart
block|{
name|HRTIMER_RESTART
block|,
name|HRTIMER_NORESTART
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|hrtimer
block|{
name|enum
name|hrtimer_restart
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|struct
name|hrtimer
modifier|*
parameter_list|)
function_decl|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|callout
name|callout
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|hrtimer_active
parameter_list|(
name|hrtimer
parameter_list|)
value|linux_hrtimer_active(hrtimer)
end_define

begin_define
define|#
directive|define
name|hrtimer_cancel
parameter_list|(
name|hrtimer
parameter_list|)
value|linux_hrtimer_cancel(hrtimer)
end_define

begin_define
define|#
directive|define
name|hrtimer_init
parameter_list|(
name|hrtimer
parameter_list|,
name|clock
parameter_list|,
name|mode
parameter_list|)
value|do {			\ 	CTASSERT((clock) == CLOCK_MONOTONIC);			\ 	CTASSERT((mode) == HRTIMER_MODE_REL);			\ 	linux_hrtimer_init(hrtimer);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|hrtimer_set_expires
parameter_list|(
name|hrtimer
parameter_list|,
name|time
parameter_list|)
define|\
value|linux_hrtimer_set_expires(hrtimer, time)
end_define

begin_define
define|#
directive|define
name|hrtimer_start
parameter_list|(
name|hrtimer
parameter_list|,
name|time
parameter_list|,
name|mode
parameter_list|)
value|do {			\ 	CTASSERT((mode) == HRTIMER_MODE_REL);			\ 	linux_hrtimer_start(hrtimer, time);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|hrtimer_start_range_ns
parameter_list|(
name|hrtimer
parameter_list|,
name|time
parameter_list|,
name|prec
parameter_list|,
name|mode
parameter_list|)
value|do {	\ 	CTASSERT((mode) == HRTIMER_MODE_REL);			\ 	linux_hrtimer_start_range_ns(hrtimer, time, prec);	\ } while (0)
end_define

begin_function_decl
name|bool
name|linux_hrtimer_active
parameter_list|(
name|struct
name|hrtimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_hrtimer_cancel
parameter_list|(
name|struct
name|hrtimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_hrtimer_init
parameter_list|(
name|struct
name|hrtimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_hrtimer_set_expires
parameter_list|(
name|struct
name|hrtimer
modifier|*
parameter_list|,
name|ktime_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_hrtimer_start
parameter_list|(
name|struct
name|hrtimer
modifier|*
parameter_list|,
name|ktime_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_hrtimer_start_range_ns
parameter_list|(
name|struct
name|hrtimer
modifier|*
parameter_list|,
name|ktime_t
parameter_list|,
name|int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_HRTIMER_H_ */
end_comment

end_unit

