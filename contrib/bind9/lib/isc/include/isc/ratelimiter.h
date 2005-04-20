begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ratelimiter.h,v 1.13.14.3 2004/03/08 09:04:53 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_RATELIMITER_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_RATELIMITER_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * A rate limiter is a mechanism for dispatching events at a limited  * rate.  This is intended to be used when sending zone maintenance  * SOA queries, NOTIFY messages, etc.  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/*****  ***** Functions.  *****/
name|isc_result_t
name|isc_ratelimiter_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_ratelimiter_t
modifier|*
modifier|*
name|ratelimiterp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a rate limiter.  The execution interval is initially undefined.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_ratelimiter_setinterval
parameter_list|(
name|isc_ratelimiter_t
modifier|*
name|rl
parameter_list|,
name|isc_interval_t
modifier|*
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the mininum interval between event executions.  * The interval value is copied, so the caller need not preserve it.  *  * Requires:  *	'*interval' is a nonzero interval.  */
end_comment

begin_function_decl
name|void
name|isc_ratelimiter_setpertic
parameter_list|(
name|isc_ratelimiter_t
modifier|*
name|rl
parameter_list|,
name|isc_uint32_t
name|perint
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the number of events processed per interval timer tick.  * If 'perint' is zero it is treated as 1.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_ratelimiter_enqueue
parameter_list|(
name|isc_ratelimiter_t
modifier|*
name|rl
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|eventp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Queue an event for rate-limited execution.  This is similar  * to doing an isc_task_send() to the 'task', except that the  * execution may be delayed to achieve the desired rate of  * execution.  *  * '(*eventp)->ev_sender' is used to hold the task.  The caller  * must ensure that the task exists until the event is delivered.  *  * Requires:  *	An interval has been set by calling  *	isc_ratelimiter_setinterval().  *  *	'task' to be non NULL.  *	'(*eventp)->ev_sender' to be NULL.  */
end_comment

begin_function_decl
name|void
name|isc_ratelimiter_shutdown
parameter_list|(
name|isc_ratelimiter_t
modifier|*
name|ratelimiter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Shut down a rate limiter.  *  * Ensures:  *	All events that have not yet been  * 	dispatched to the task are dispatched immediately with  *	the ISC_EVENTATTR_CANCELED bit set in ev_attributes.  *  *	Further attempts to enqueue events will fail with  * 	ISC_R_SHUTTINGDOWN.  *  *	The reatelimiter is no longer attached to its task.  */
end_comment

begin_function_decl
name|void
name|isc_ratelimiter_attach
parameter_list|(
name|isc_ratelimiter_t
modifier|*
name|source
parameter_list|,
name|isc_ratelimiter_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach to a rate limiter.  */
end_comment

begin_function_decl
name|void
name|isc_ratelimiter_detach
parameter_list|(
name|isc_ratelimiter_t
modifier|*
modifier|*
name|ratelimiterp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach from a rate limiter.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_ratelimiter_stall
parameter_list|(
name|isc_ratelimiter_t
modifier|*
name|rl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Stall event processing.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_ratelimiter_release
parameter_list|(
name|isc_ratelimiter_t
modifier|*
name|rl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Release a stalled rate limiter.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_RATELIMITER_H */
end_comment

end_unit

