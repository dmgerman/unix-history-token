begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_COUNTER_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_COUNTER_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file isc/counter.h  *  * \brief The isc_counter_t object is a simplified version of the  * isc_quota_t object; it tracks the consumption of limited  * resources, returning an error condition when the quota is  * exceeded.  However, unlike isc_quota_t, attaching and detaching  * from a counter object does not increment or decrement the counter.  */
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
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/*****  ***** Types.  *****/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_counter_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|int
name|limit
parameter_list|,
name|isc_counter_t
modifier|*
modifier|*
name|counterp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Allocate and initialize a counter object.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_counter_increment
parameter_list|(
name|isc_counter_t
modifier|*
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Increment the counter.  *  * If the counter limit is nonzero and has been reached, then  * return ISC_R_QUOTA, otherwise ISC_R_SUCCESS. (The counter is  * incremented regardless of return value.)  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_counter_used
parameter_list|(
name|isc_counter_t
modifier|*
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the current counter value.  */
end_comment

begin_function_decl
name|void
name|isc_counter_setlimit
parameter_list|(
name|isc_counter_t
modifier|*
name|counter
parameter_list|,
name|int
name|limit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the counter limit.  */
end_comment

begin_function_decl
name|void
name|isc_counter_attach
parameter_list|(
name|isc_counter_t
modifier|*
name|source
parameter_list|,
name|isc_counter_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach to a counter object, increasing its reference counter.  */
end_comment

begin_function_decl
name|void
name|isc_counter_detach
parameter_list|(
name|isc_counter_t
modifier|*
modifier|*
name|counterp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detach (and destroy if reference counter has dropped to zero)  * a counter object.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_COUNTER_H */
end_comment

end_unit

