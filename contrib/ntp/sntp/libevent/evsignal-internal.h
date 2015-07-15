begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVSIGNAL_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVSIGNAL_INTERNAL_H_INCLUDED_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|evutil_socket_t
end_ifndef

begin_include
include|#
directive|include
file|"event2/util.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ev_sighandler_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Data structure for the default signal-handling implementation in signal.c  */
end_comment

begin_struct
struct|struct
name|evsig_info
block|{
comment|/* Event watching ev_signal_pair[1] */
name|struct
name|event
name|ev_signal
decl_stmt|;
comment|/* Socketpair used to send notifications from the signal handler */
name|evutil_socket_t
name|ev_signal_pair
index|[
literal|2
index|]
decl_stmt|;
comment|/* True iff we've added the ev_signal event yet. */
name|int
name|ev_signal_added
decl_stmt|;
comment|/* Count of the number of signals we're currently watching. */
name|int
name|ev_n_signals_added
decl_stmt|;
comment|/* Array of previous signal handler objects before Libevent started 	 * messing with them.  Used to restore old signal handlers. */
ifdef|#
directive|ifdef
name|EVENT__HAVE_SIGACTION
name|struct
name|sigaction
modifier|*
modifier|*
name|sh_old
decl_stmt|;
else|#
directive|else
name|ev_sighandler_t
modifier|*
modifier|*
name|sh_old
decl_stmt|;
endif|#
directive|endif
comment|/* Size of sh_old. */
name|int
name|sh_old_max
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|evsig_init_
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evsig_dealloc_
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evsig_set_base_
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evsig_free_globals_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVSIGNAL_INTERNAL_H_INCLUDED_ */
end_comment

end_unit

