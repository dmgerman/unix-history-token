begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFER_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|DEFER_INTERNAL_H_INCLUDED_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|"event2/event-config.h"
include|#
directive|include
file|"evconfig-private.h"
include|#
directive|include
file|<sys/queue.h>
struct_decl|struct
name|event_callback
struct_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|deferred_cb_fn
function_decl|)
parameter_list|(
name|struct
name|event_callback
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    Initialize an empty, non-pending event_callback.     @param deferred The struct event_callback structure to initialize.    @param priority The priority that the callback should run at.    @param cb The function to run when the struct event_callback executes.    @param arg The function's second argument.  */
name|void
name|event_deferred_cb_init_
parameter_list|(
name|struct
name|event_callback
modifier|*
parameter_list|,
name|ev_uint8_t
parameter_list|,
name|deferred_cb_fn
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    Change the priority of a non-pending event_callback.  */
name|void
name|event_deferred_cb_set_priority_
parameter_list|(
name|struct
name|event_callback
modifier|*
parameter_list|,
name|ev_uint8_t
parameter_list|)
function_decl|;
comment|/**    Cancel a struct event_callback if it is currently scheduled in an event_base.  */
name|void
name|event_deferred_cb_cancel_
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|,
name|struct
name|event_callback
modifier|*
parameter_list|)
function_decl|;
comment|/**    Activate a struct event_callback if it is not currently scheduled in an event_base.     Return true iff it was not previously scheduled.  */
name|int
name|event_deferred_cb_schedule_
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|,
name|struct
name|event_callback
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT_INTERNAL_H_INCLUDED_ */
end_comment

end_unit

