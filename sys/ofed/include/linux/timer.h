begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_TIMER_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_TIMER_H_
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_struct
struct|struct
name|timer_list
block|{
name|struct
name|callout
name|timer_callout
decl_stmt|;
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
name|unsigned
name|long
name|data
decl_stmt|;
name|unsigned
name|long
name|expires
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|_timer_fn
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
block|{
name|struct
name|timer_list
modifier|*
name|timer
decl_stmt|;
name|timer
operator|=
name|context
expr_stmt|;
name|timer
operator|->
name|function
argument_list|(
name|timer
operator|->
name|data
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|setup_timer
parameter_list|(
name|timer
parameter_list|,
name|func
parameter_list|,
name|dat
parameter_list|)
define|\
value|do {									\ 	(timer)->function = (func);					\ 	(timer)->data = (dat);						\ 	callout_init(&(timer)->timer_callout, CALLOUT_MPSAFE);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|init_timer
parameter_list|(
name|timer
parameter_list|)
define|\
value|do {									\ 	(timer)->function = NULL;					\ 	(timer)->data = 0;						\ 	callout_init(&(timer)->timer_callout, CALLOUT_MPSAFE);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|mod_timer
parameter_list|(
name|timer
parameter_list|,
name|exp
parameter_list|)
define|\
value|do {									\ 	(timer)->expires = (exp);					\ 	callout_reset(&(timer)->timer_callout, (exp) - jiffies,		\ 	    _timer_fn, (timer));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|add_timer
parameter_list|(
name|timer
parameter_list|)
define|\
value|callout_reset(&(timer)->timer_callout,				\ 	    (timer)->expires - jiffies, _timer_fn, (timer))
end_define

begin_define
define|#
directive|define
name|del_timer
parameter_list|(
name|timer
parameter_list|)
value|callout_stop(&(timer)->timer_callout)
end_define

begin_define
define|#
directive|define
name|del_timer_sync
parameter_list|(
name|timer
parameter_list|)
value|callout_drain(&(timer)->timer_callout)
end_define

begin_define
define|#
directive|define
name|timer_pending
parameter_list|(
name|timer
parameter_list|)
value|callout_pending(&(timer)->timer_callout)
end_define

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|round_jiffies
parameter_list|(
name|unsigned
name|long
name|j
parameter_list|)
block|{
return|return
name|roundup
argument_list|(
name|j
argument_list|,
name|hz
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|round_jiffies_relative
parameter_list|(
name|j
parameter_list|)
value|round_jiffies(j)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_TIMER_H_ */
end_comment

end_unit

